#include <iostream>
#include <fstream>
using namespace std;

int days[13] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

struct Date {
  int m;
  int d;
  int y;
};

bool de (Date a, Date b) {
  if(a.m != b.m) return false;
  if(a.d != b.d) return false;
  if(a.y != b.y) return false;
  return true;
}

bool leap (int year) {
  if(year % 4 != 0) return false;
  if(year % 100 == 0) return false;
  if(year % 400 != 0) return false;
  return true;
}

Date tmrw (Date a) {
  Date ret; // return this date
  if(a.m == 12 && a.d == 31) {
    ret.m = 1;
    ret.d = 1;
    ret.y = a.y + 1;
  }

  else if(a.d == ((a.m == 2 && leap(a.y)) ? days[a.m] + 1 : days[a.m])) {
    ret.m = a.m + 1;
    ret.d = 1;
    ret.y = a.y;
  }

  else {
    ret.m = a.m;
    ret.d = a.d + 1;
    ret.y = a.y;
  }

  return ret;
}

string dateToString (Date a) {
  string month = "";
  string day = "";
  string year = to_string(a.y);
  if(a.m < 10) month += '0';
  if(a.d < 10) day += '0';
  month += to_string(a.m);
  day += to_string(a.d);
  return month + '/' + day + '/' + year;
}

int main (int argc, char** argv) {
  ofstream apts;
  apts.open("/home/daniel/.local/share/calcurse/apts");
  string date[2] = {argv[1], argv[2]};
  int month[2] = {stoi(date[0].substr(0, 2)), stoi(date[1].substr(0, 2))};
  int day[2] = {stoi(date[0].substr(3, 2)), stoi(date[1].substr(3, 2))};
  int year[2] = {stoi(date[0].substr(6, 4)), stoi(date[1].substr(6, 4))};
  string task = argv[3];
  Date cur = {month[0], day[0], year[0]};
  Date end = {month[1], day[1], year[1]};
  while(!de(cur, end)) {
    apts << dateToString(cur) << " [1] " << task << '\n';
    cur = tmrw(cur);
  }
  apts << dateToString(end) << " [1] " << task << '\n';
  apts.close();
  return 0;
}

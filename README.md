# uc
CLI for calcurse updates.

# Usage
`uc "mm/dd/yyyy" "mm/dd/yyyy" "Wash the dishes at 3:00 PM."
This will add washing the dishes to the Appointments category of `calcurse` for every date in between (inclusive) the first two dates you provide as arguments.

# Prerequisites
`gcc`
`git`

# Installation
1. `git clone https://github.com/physics/uc.git"`
2. `cd uc`
3. `g++ uc.cpp -o uc`
4. `sudo cp uc /usr/bin/`

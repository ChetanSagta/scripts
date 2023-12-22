#/bin/bash

cd ~/scripts/iotd
python3 main.py
feh --bg-scale $(ls -Art | tail -n 1)

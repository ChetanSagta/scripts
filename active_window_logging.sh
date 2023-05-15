#!/bin/bash

while true
do
current_window=$(xdotool getactivewindow getwindowname)
focused_window=$(xdotool getwindowfocus getwindowname)
echo "Current Window: $current_window and focused Window: $focused_window"
sleep 1
done


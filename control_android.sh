#!/bin/bash
while true 
do
 adb shell input mouse swipe 0 0 1920 1600
 sleep 1
 adb shell input mouse swipe 1920 1600 0 0
done


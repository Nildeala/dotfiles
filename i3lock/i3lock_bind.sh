#!/bin/bash
# Script to trigger a really nice looking lockscreen
# 	Depends on: scrot, i3lock, imagemagick
# 	Details & screenshot @ http://www.reddit.com/r/unixporn/comments/3358vu/i3lock_unixpornworthy_lock_screen/

scrot /tmp/screen.png
convert /tmp/screen.png -scale 10% -scale 1000% /tmp/screen.png
[[ -f $HOME/Images/icons/lock.png ]] && convert /tmp/screen.png $HOME/Images/icons/lock.png -gravity center -composite -matte /tmp/screen.png
i3lock -u -i /tmp/screen.png

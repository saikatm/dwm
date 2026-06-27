#!/bin/bash

# Polkit agent (needed for GUI password prompts)
/usr/lib/policykit-1-gnome/polkit-gnome-authentication-agent-1 &

# Network manager applet
nm-applet &

# MegaSync
megasync &

# Screenshot tool (flameshot sits in systray, ready for PrtSc)
flameshot &

# Notification daemon
dunst &

# Clipboard Manager
parcellite &

# Solid color wallpaper 
xsetroot -solid "#1A1823"

# Status bar (slstatus — no flickering, direct X11, no shell loop)
slstatus &

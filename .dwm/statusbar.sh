#!/bin/bash
# ~/.dwm/statusbar.sh
# Called by autostart.sh — runs as its own process, no subshell issues

prev_status=""

while true; do
    # First CPU sample
    cpu_line=$(grep '^cpu ' /proc/stat)
    user=$(echo $cpu_line | awk '{print $2}')
    nice=$(echo $cpu_line | awk '{print $3}')
    system=$(echo $cpu_line | awk '{print $4}')
    idle=$(echo $cpu_line | awk '{print $5}')

    sleep 5

    # Second CPU sample
    cpu_line2=$(grep '^cpu ' /proc/stat)
    user2=$(echo $cpu_line2 | awk '{print $2}')
    nice2=$(echo $cpu_line2 | awk '{print $3}')
    system2=$(echo $cpu_line2 | awk '{print $4}')
    idle2=$(echo $cpu_line2 | awk '{print $5}')

    total1=$((user + nice + system + idle))
    total2=$((user2 + nice2 + system2 + idle2))
    used1=$((user + nice + system))
    used2=$((user2 + nice2 + system2))
    diff_total=$((total2 - total1))

    if [ "$diff_total" -gt 0 ]; then
        cpu=$(( (used2 - used1) * 100 / diff_total ))
    else
        cpu=0
    fi

    # RAM in GB with 1 decimal
    mem_total=$(awk '/MemTotal/ {print $2}' /proc/meminfo)
    mem_avail=$(awk '/MemAvailable/ {print $2}' /proc/meminfo)
    mem_used_kb=$(( mem_total - mem_avail ))
    gb_x10=$(( mem_used_kb * 10 / 1048576 ))
    gb_int=$(( gb_x10 / 10 ))
    gb_dec=$(( gb_x10 % 10 ))

    status="CPU: ${cpu}%  |  RAM: ${gb_int}.${gb_dec}GB  |  $(date '+%I:%M%p %A %d %B %Y')"

    if [ "$status" != "$prev_status" ]; then
        xsetroot -name "$status"
        prev_status="$status"
    fi
done

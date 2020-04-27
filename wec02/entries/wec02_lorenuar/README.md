# color
A program to colorize text using ANSI escape codes.<br>
Your terminal emulator must support "truecolor" or "24bit" color mode for optimal display.
# Usage
```
Usage :
./color [R(0-255)] [G(0-255] [B(0-255)]                                      - Set foreground color only
./color -b [R(0-255)] [G(0-255] [B(0-255)]                                   - Set background color only
./color -b [R(0-255)] [G(0-255] [B(0-255)] [R(0-255)] [G(0-255] [B(0-255)]   - Set background and foreground color
./color -r                                                                   - Special rainbow mode
./color -rfreq [frequency factor]                                            - Rainbow mode with frequency factor
./color -rfreq [frequency factor] -rphase [phase offset (360 degrees)]       - Rainbow mode with frequency factor and phase offset
```
# Notes
You can use `make run` for a quick showcase (uses python3 script)

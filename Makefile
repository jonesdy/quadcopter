# Arduino Make file. Refer to https://github.com/sudar/Arduino-Makefile

# --- mega2560 ide 1.6
BOARD_TAG    = mega
BOARD_SUB    = atmega2560
MONITOR_PORT = /dev/ttyACM0
ARDUINO_LIBS = NewliquidCrystal Wire SoftI2CMaster
include /usr/share/arduino/Arduino.mk

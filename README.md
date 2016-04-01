# quadcopter
The flight and control software for the quadcopter I'm building

Note that this uses fmalpartida's LCD library instead of the default (found here: https://bitbucket.org/fmalpartida/new-liquidcrystal/wiki/Home). Note that I edited 2 files from the library because they were including Wire.h weirdly (I2CIO.cpp and LiquidCrystal_I2C_ByVac.h). This library also requires SoftI2CMaster (found here: https://github.com/felias-fogg/SoftI2CMaster).
I'm also using the Arduino-Makefile package to build my Makefile (found here: https://github.com/sudar/Arduino-Makefile).

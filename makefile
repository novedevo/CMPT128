CC=g++
CFLAGS = -lm -std=gnu++11

program: src/activity04.cpp src/nibbler.cpp
	$(CC) -o src/activity04.cpp src/nibbler.cpp

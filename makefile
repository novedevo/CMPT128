CPP = g++
C = gcc

.PHONY: default clean all

default:
	@echo no options given, exiting...

clean:
	@echo "removing exe files..."
	rm -f debug/*.exe

all: activity04 activity05 nibbler circlemath codewrite factorial review-session1 system-of-particles review-session-2 smoothness-calculator
	@echo all targets compiled

#BEGIN LIST OF TARGETS

activity04: src/activity04.cpp
	$(CPP) src/activity04.cpp -o debug/activity04 -std=gnu++11

activity05: src/activity05.cpp
	$(CPP) src/activity05.cpp -o debug/activity05 -std=gnu++14

nibbler: src/nibbler.cpp
	$(CPP) src/nibbler.cpp -o debug/nibbler 

circlemath: src/circlemath.cpp
	$(CPP) src/circlemath.cpp -o debug/circlemath -std=gnu++11

codewrite: src/codewrite.cpp
	$(CPP) src/codewrite.cpp -o debug/codewrite -std=gnu++11

recursing-main: src/recursing-main.cpp
	$(CPP) src/recursing-main.cpp -o debug/recursing-main

factorial: src/factorial.cpp
	$(CPP) src/factorial.cpp -o debug/factorial
	
review-session1: src/review-session1.cpp
	$(CPP) src/review-session1.cpp -o debug/review-session1 -std=gnu++11

system-of-particles: src/system-of-particles.cpp
	$(CPP) src/system-of-particles.cpp -o debug/system-of-particles -std=gnu++11

review-session-2: src/review-session-2.c
	$(C) src/review-session-2.c -lm -o debug/review-session-2

smoothness-calculator: src/smoothness-calculator.cpp
	$(CPP) src/smoothness-calculator.cpp -o debug/smoothness-calculator -std=gnu++11

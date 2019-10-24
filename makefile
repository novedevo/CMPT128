CXX = g++

activity04: src/activity04.cpp
	$(CXX) src/activity04.cpp -o activity04 -std=gnu++11

activity05: src/activity05.cpp
	$(CXX) src/activity05.cpp -o activity05 -std=gnu++14

nibbler: src/nibbler.cpp
	$(CXX) src/nibbler.cpp -o nibbler 

circlemath: src/circlemath.cpp
	$(CXX) src/circlemath.cpp -o circlemath -std=gnu++11

codewrite4: src/codewrite4.cpp
	$(CXX) src/codewrite4.cpp -o codewrite4 -std=gnu++11

recursing-main: src/recursingmain.cpp
	$(CXX) src/recursing-main.cpp -o recursing-main

factorial: src/factorial.cpp
	$(CXX) src/factorial.cpp -o factorial
	
review-session1: src/review-session1.cpp
	$(CXX) src/review-session1.cpp -o review-session1 -std=gnu++11

system-of-particles: src/system-of-particles.cpp
	$(CXX) src/system-of-particles.cpp -o system-of-particles -std=gnu++11

review-session-2: src/review-session-2.c
	gcc src/review-session-2.c -o review-session-2
	
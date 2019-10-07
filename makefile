CXX = g++

activity04: src/activity04.cpp
	$(CXX) src/activity04.cpp -o activity04 -std=gnu++11
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
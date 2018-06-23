FLAGS := -std=c++17 `pkg-config --cflags --libs opencv`

a.out: arcv.cpp
	g++ $(FLAGS) arcv.cpp -o a.out

PHONY: run
run: a.out
	./a.out

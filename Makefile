all: compile run


run:
	./a.out

compile:
	g++ src/Graph.cpp src/DynamicGraph.cpp main.cpp src/IntermediatePaths.cpp
all: compile run


run:
	./a.out

compile:
	g++ src/Graph.cpp src/DynamicGraph.cpp  src/IntermediatePaths.cpp src/Dijikstra.cpp main.cpp
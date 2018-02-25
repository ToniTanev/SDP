#include <iostream>
#include <cassert>
#include "graphs.cpp"



void testNumbOfWays() //raboti
{
	
	std::vector<char> row1 = {'a','b','c'};
	std::vector<char> row2 = {'a','d','c'};
	WeightedGraph G = {row1, row1, row2};

	std::cout << isThereAWayFromVertex(G, "bbbbaaaadabbbbbaabbc", 0) << std::endl << numbOfWays(G, "daabbbabaaa") << std::endl;

}

void testBuildTree() //ne raboti suvsem
{
	std::vector<bool> row1 = {1,0,1,0,1};
	std::vector<bool> row2 = {1,0,1,0,1};
	std::vector<bool> row3 = {1,0,0,1,1};
	std::vector<bool> row4 = {0,0,1,1,1};
	std::vector<bool> row5 = {1,0,0,0,1};
	Graph g = {row1, row2, row3, row4, row5};
	Tree t;
	buildTree(t, g, 0, 4);

	ofstream f("DOT.txt");
	printTreeDotty(t, f);
	f.close();
}

void testTopologicalSort() //raboti
{
	std::vector<bool> row1 = {0,1,1,1,0};
	std::vector<bool> row2 = {0,0,0,0,1};
	std::vector<bool> row3 = {0,1,0,0,0};
	std::vector<bool> row4 = {0,0,1,0,1};
	std::vector<bool> row5 = {0,0,0,0,0};

	Graph g = {row1, row2, row3, row4, row5};
	std::vector<int> res = topologicalSort(g);
	
	for(int i = 0; i < res.size(); i++)
		std::cout << res[i] << ' ';
	std::cout << std::endl;

}

void testMakeAdjacencyMatrix()
{
	std::vector<bool> row1 = {1,1,1,1,1};
	std::vector<bool> row2 = {0,0,0,1,1};
	std::vector<bool> row3 = {0,0,0,1,1};
	std::vector<bool> row4 = {0,0,0,0,1};
	std::vector<bool> row5 = {1,1,0,0,1};
	Labyrinth L = {row1, row2, row3, row4, row5};

	Graph G = makeAdjacencyMatrix(L);

	ofstream f("GraphDOT.txt");
	printGraphDotty(G, f);
	f.close();
}

int main()
{
	//testNumbOfWays();
	testBuildTree();
	//testTopologicalSort();
	//testMakeAdjacencyMatrix();

	return 0;
}
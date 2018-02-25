#include <iostream>
#include <vector>
#include <stack>

using Graph = std::vector<std::vector<int>>;

bool isCyclicFrom(Graph G, int startVertex, int cnt)
{
	if(cnt > G.size())
		return true;

	for(int i = 0; i < G[startVertex].size(); i++)
	{
		if(G[startVertex][i])
			if(isCyclicFrom(G, i, cnt + 1))
				return true;
	}

	return false;

}

bool isCyclic(Graph G)
{

	for(int i = 0; i < G.size(); i++)
	{
		if(isCyclicFrom(G, i, 0))
			return true;
	}

	return false;
}


//tests
void testIsCyclic()
{
	std::vector<int> row1 = {0, 0, 0, 0, 0};
	std::vector<int> row2 = {0, 0, 1, 0, 0};
	std::vector<int> row3 = {0, 1, 0, 0, 0};
	std::vector<int> row4 = {0, 1, 0, 0, 0};
	std::vector<int> row5 = {0, 0, 0, 0, 0};
	Graph G = {row1, row2, row3, row4, row5};

	std::cout << isCyclic(G) << std::endl;
}

int main()
{

	testIsCyclic();

	return 0;
}
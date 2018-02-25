#include <vector>
#include <iostream>

using std::ostream;

#define GSIZE 5

bool G[GSIZE][GSIZE] = {0, 0, 1, 0, 0,
						0, 0, 0, 0, 0,
						0, 0, 0, 1, 0,
						0, 1, 0, 1, 0,
						0, 0, 1, 0, 0};


std::ostream& operator << (std::ostream& out, const std::vector<std::vector<int>>& paths)
{

	for(int path = 0; path < paths.size(); path++)
	{
		for(int vertex = 0; vertex < paths[path].size(); vertex++)
		{
			out << paths[path][vertex] << " ";
		}
		out << std::endl;
	}
	return out;
}

void extend(int v, std::vector<std::vector<int>>& paths)
{
	for(int i = 0; i < paths.size(); i++)
	{
		std::vector<int>::iterator it = paths[i].begin();
		paths[i].insert(it, v);
	}
}

void concat(std::vector<std::vector<int>>& result, std::vector<std::vector<int>> newPaths)
{
	for(int i = 0; i < newPaths.size(); i++)
		result.push_back(newPaths[i]);
}

std::vector<std::vector<int>> allPathsStartingWith(int v, int k)
{
	std::vector<std::vector<int>> result;
	if(k == 0)
		return result;

	std::vector<int> path;
	path.push_back(v);
	result.push_back(path);

	for(int i = 0; i < GSIZE; i++)
	{
		if(G[v][i])
		{
			std::vector<std::vector<int>> newPaths = allPathsStartingWith(i, k - 1);
			extend(v, newPaths);
			concat(result, newPaths);
		}

	}

}

void printAllDifferentPaths(int k)
{

	for(int v = 0; v < GSIZE; v++)
	{
		std::vector<std::vector<int>> paths = allPathsStartingWith(v, k);
		std::cout << paths;
	}
}


void testPrintAllDifferentPaths()
{

	printAllDifferentPaths(3);
}

int main()
{

	testPrintAllDifferentPaths();
	return 0;
}
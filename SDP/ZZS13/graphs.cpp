#ifndef __GRAPHS_
#define __GRAPHS_

#include <iostream>
#include <vector>
#include <fstream>
#include <cassert>
#include <map>

using std::ostream;
using std::ofstream;
using std::istream;
using std::ifstream;
using std::vector;
using WeightedGraph = std::vector<std::vector<char>>;
using Graph = std::vector<std::vector<bool>>;
using Tree = std::vector<std::vector<std::pair<int,int>>>;
using Labyrinth = std::vector<std::vector<bool>>;

//zad1
bool isThereAWayFromVertex(WeightedGraph G, const char* w, int currentVertex)
{
	if(*w == 0)
		return true;

	for(int j = 0; j < G[currentVertex].size(); j++)
	{
		if(G[currentVertex][j] == *w)
			return isThereAWayFromVertex(G, w + 1, j);
	}

	return false;
}

int numbOfWays(WeightedGraph G, const char* w)
{
	int br = 0;

	for(int i = 0; i < G.size(); i++)
	{
		if(isThereAWayFromVertex(G, w, i))
			br++;
	}
	
	return br;
}

//zad2 
//nqma izomorfizum mejdu vurhovete na durvoto i grafa
bool isMember(std::vector<int> vec, int el)
{
	if(vec.empty())
		return false;

	for(int i = 0; i < vec.size(); i++)
	{
		if(el == vec[i]) 
			return true;
	}
	return false;
}

/*void buildTreeRec(Tree& t, Graph& G, std::vector<int> currentVertices, int currentLevel, int maxDepth)
{	
	if(currentLevel == maxDepth || currentVertices.empty())
		return;

	std::vector<int> nextVertices(5); //za da ne core dumpva

	for(int i = 0; i < currentVertices.size(); i++)
	{
		for(int j = 0; j < G[currentVertices[i]].size(); j++) 
		{
			if(G[currentVertices[i]][j] && i != j)
			{
				for(int k = 0; k < G.size(); k++)
				{
					G[k][j] = 0;
				}
				G[j][currentVertices[i]] = 0; // za da nqma cikli (durvoto e svurzan graf bez cikli)
				t[currentLevel].push_back(std::pair<int, int>(i, j));
				if(!isMember(nextVertices, j))
					nextVertices.push_back(j);
			}
		}
	}

	buildTreeRec(t, G, nextVertices, currentLevel + 1, maxDepth);
}
*/
void buildTreeRec(Tree& t, Graph& G, std::vector<int> currentVertices, int currentLevel, int maxDepth, std::map<int, int>& map, int& currentVertex)
{
	if(currentLevel == maxDepth || currentVertices.empty())
		return;

	std::vector<int> nextVertices; // za da ne core dumpva

	for(int i = 0; i < currentVertices.size(); i++)
	{
		for(int j = 0; j < G[map[currentVertices[i]]].size(); j++)
		{
			
			if(G[map[currentVertices[i]]][j]) // ako ima put
			{
				nextVertices.push_back(currentVertex);
				t[currentLevel].push_back(std::pair<int, int>(currentVertices[i], currentVertex));
				map[currentVertex] = j;
				currentVertex++;
			}
		}
	}

	buildTreeRec(t, G, nextVertices, currentLevel + 1, maxDepth, map, currentVertex);
}

void buildTree(Tree& t, Graph& G, int root, int maxDepth)
{
	t.resize(5); //za da ne core dumpva
	int currentVertex = 0;
	std::map<int, int> map;
	map[currentVertex] = root;
	std::vector<int> rootVector = {currentVertex};
	currentVertex++;
	buildTreeRec(t, G, rootVector, 1, maxDepth, map, currentVertex);

}

void printTreeDotty(Tree t, ostream& os)
{

	os << "digraph T{\nnode[shape = circle]\n";

	for(int i = 0; i < t.size(); i++)
	{
		for(int j = 0; j < t[i].size(); j++)
		{
			os << t[i][j].first << " -> " << t[i][j].second << "\n";
		}

	}

	os << "}\n";

}


//zad3
bool doesntHaveInEdges(Graph G, int vertex)
{
	for(int i = 0; i < G.size(); i++)
		if(G[i][vertex])
			return false;
	return true;
}

std::vector<int> topologicalSort(Graph G)
{
	std::vector<int> res;
	std::vector<int> temp;

	for(int i = 0; i < G.size(); i++)
	{
		if(doesntHaveInEdges(G, i))
			temp.push_back(i);
	}
	while(!temp.empty())
	{
		res.push_back(temp.back());
		temp.pop_back();
		for(int i = 0; i < G.size(); i++)
		{
			if(G[res.back()][i])
			{
				G[res.back()][i] = 0;
				if(doesntHaveInEdges(G, i))
					temp.push_back(i);
			}
		}
	}

	return res;
}

//zad4
bool areAdjacent(int i1, int j1, int i2, int j2)
{
	if(i2 - i1 == 1 && j1 == j2)
		return true;
	if(i1 - i2 == 1 && j1 == j2)
		return true;
	if(j2 - j1 == 1 && i1 == i2)
		return true;
	if(j1 - j2 == 1 && i1 == i2)
		return true;

	return false;
}

Graph makeAdjacencyMatrix(Labyrinth L)
{
	std::map<int, std::pair<int, int>> f;
	int idx = 0; 
	for(int i = 0; i < L.size(); i++)
	{
		for(int j = 0; j < L[i].size(); j++)
		{
			if(L[i][j])
				f[idx++] = std::pair<int, int>(i, j);
			
		}
	}
	const int len = idx;

	Graph res;
	res.resize(len);
	for(int i = 0; i < res.size(); i++)
	{
		res[i].resize(len);
	}
	for(int i = 0; i < res.size(); i++)
	{
		for(int j = 0; j < res[i].size(); j++)
		{
			if(areAdjacent(f[i].first, f[i].second, f[j].first, f[j].second))
				res[i][j] = 1;
		}
		
	}

	return res;
}

void printGraphDotty(Graph G, ostream& os)
{
	os << "graph G{\nnode[shape = circle]\n";

	for(int i = 0; i < G.size(); i++)
	{
		for(int j = 0; j < G[i].size(); j++)
		{
			if(G[i][j])
			{
				G[j][i] = 0;
				os << i << " -- " << j << "\n";
			}
		}
	}

	os << "}\n";

}

#endif

#ifndef __LIST_
#define __LIST_

#include <list>
#include <map>
#include <vector>
#include <cassert>
#include <iostream>
#include <fstream>

using std::ostream;
using std::ofstream;
template <class T>
using Map = std::map<T, std::list<T>>;

template <class T>
class Graph
{
private:
	Map<T> m;

public:
	Graph() : m() {}
	Graph(Map<T> _m) {m = _m;}

	std::vector<T> vertices() 
	{
		std::vector<T> res;
		for(typename Map<T>::iterator iter = m.begin(); iter != m.end(); ++iter)
			res.push_back(iter->first);

		return res;
	}

	bool member(T v)  
	{
		for(typename Map<T>::iterator iter = m.begin(); iter != m.end(); ++iter)
			if(iter->first == v)
				return true;

		return false;
	}

	std::list<T> successors(T v) 
	{
		if(!member(v))
			return std::list<T>();
		return m[v];
	}

	bool isEdge(T v, T u) 
	{
		if(!member(v))
			return false;

		std::list<T> l = m[v];
		for(typename std::list<T>::iterator iter = l.begin(); iter != l.end(); ++iter)
			if(*iter == u)
				return true;

		return false;
	}

	void addVertex(T v)
	{
		m[v] = std::list<T>();
	}

	void addEdge(T v, T u)
	{
		if(isEdge(v, u))
			return;

		if(!member(v))
			addVertex(v);

		m[v].push_back(u);
	}

	void printDOT(ostream& os) //не може да е const, не знам защо
	{

		os << "digraph G{\n";

		for(typename Map<T>::iterator mapIter = m.begin(); mapIter != m.end(); ++mapIter)
		{
			os << mapIter->first << ";\n";
			for(typename std::list<T>::iterator listIter = (mapIter->second).begin(); listIter != (mapIter->second).end(); ++listIter)
			{
				os << mapIter->first << " -> " << *listIter << ";\n";
			}
		}

		os << "}\n";
	}

};

template <class T>
bool hasPath(Graph<T> g, T u, T v)
{
	std::map<T, bool> visited;
	return hasPathRec(g, u, v, visited);
}

template <class T>
bool hasPathRec(Graph<T> g, T u, T v, std::map<T, bool>& visited)
{
	if(u == v)
		return true;

	visited[u] = true;

	std::list<T> succ = g.successors(u);
	for(typename std::list<T>::iterator iter = succ.begin(); iter != succ.end(); ++iter)
	{	
		if(!visited[*iter])
			if(hasPathRec(g, *iter, v, visited))
				return true;
	}

	return false;
}

template <class T>
bool isFull(Graph<T> g)
{
	std::vector<T> vert = g.vertices();
	for(int i = 0; i < vert.size(); i++)
	{
		for(int j = 0; j < vert.size(); j++)
		{
			if( i != j && !(g.isEdge(i, j)) )
				return false;
		}
	}

	return true;
}

template <class T>
bool isUndirected(Graph<T> g)
{

	std::vector<T> vert = g.vertices();
	for(int i = 0; i < vert.size(); i++)
	{
		for(int j = 0; j < vert.size(); j++)
		{
			if(g.isEdge(i, j) && !g.isEdge(j, i))
				return false;

			if(g.isEdge(j, i) && !g.isEdge(i, j))
				return false;
		}
	}

	return true;

}

#endif 
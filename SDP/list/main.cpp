#include "list.cpp"


void testPrintDOT()
{

	std::list<int> l0;
	l0.push_back(1);
	l0.push_back(2);
	std::list<int> l1;
	l1.push_back(0);
	l1.push_back(4);	
	std::list<int> l2;
	l2.push_back(3);
	std::list<int> l3;
	l3.push_back(0);
	std::list<int> l4;

	Map<int> _map;
	_map[0] = l0;
	_map[1] = l1;
	_map[2] = l2;
	_map[3] = l3;
	_map[4] = l4;

	Graph<int> g(_map);

	ofstream f("graphDOT.txt");
	g.printDOT(f);
	f.close();

}

void testHasPath()
{
	std::list<int> l0;
	l0.push_back(1);
	l0.push_back(2);
	std::list<int> l1;
	l1.push_back(0);
	l1.push_back(4);	
	std::list<int> l2;
	l2.push_back(3);
	std::list<int> l3;
	l3.push_back(0);
	std::list<int> l4;

	Map<int> _map;
	_map[0] = l0;
	_map[1] = l1;
	_map[2] = l2;
	_map[3] = l3;
	_map[4] = l4;

	Graph<int> g(_map);

	std::cout << hasPath<int>(g, 4, 3) << std::endl;
}

void testIsFull()
{
	std::list<int> l0;
	l0.push_back(0);
	l0.push_back(1);
	l0.push_back(2);
	l0.push_back(3);
	l0.push_back(4);
	std::list<int> l1;
	l1.push_back(0);
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);	
	std::list<int> l2;
	l2.push_back(0);
	l2.push_back(1);
	l2.push_back(2);
	l2.push_back(3);
	l2.push_back(4);
	std::list<int> l3;
	l3.push_back(0);
	l3.push_back(1);
	l3.push_back(2);
	l3.push_back(3);
	l3.push_back(4);
	std::list<int> l4;
	l4.push_back(0);
	l4.push_back(1);
	l4.push_back(2);
	l4.push_back(3);
	l4.push_back(4);

	Map<int> _map;
	_map[0] = l0;
	_map[1] = l1;
	_map[2] = l2;
	_map[3] = l3;
	_map[4] = l4;

	Graph<int> fullGraph(_map);

	std::cout << isFull<int>(fullGraph) << std::endl;
}

void testIsUndirected()
{
	std::list<int> l0;
	l0.push_back(0);
	l0.push_back(1);
	l0.push_back(2);
	l0.push_back(3);
	l0.push_back(4);
	std::list<int> l1;
	l1.push_back(0);
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);	
	std::list<int> l2;
	l2.push_back(0);
	l2.push_back(1);
	l2.push_back(2);
	l2.push_back(3);
	l2.push_back(4);
	std::list<int> l3;
	l3.push_back(0);
	l3.push_back(1);
	l3.push_back(2);
	l3.push_back(3);
	l3.push_back(4);
	std::list<int> l4;
	l4.push_back(0);
	l4.push_back(1);
	l4.push_back(2);
	l4.push_back(3);
	l4.push_back(4);

	Map<int> _map;
	_map[0] = l0;
	_map[1] = l1;
	_map[2] = l2;
	_map[3] = l3;
	_map[4] = l4;

	Graph<int> fullGraph(_map);

	Graph<int> g(_map);

	std::cout << isUndirected<int>(g) << std::endl;
}

int main()
{
	//testPrintDOT();
	//testHasPath();
	//testIsFull();
	testIsUndirected();

	return 0;
}
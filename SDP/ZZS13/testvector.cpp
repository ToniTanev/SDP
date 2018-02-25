#include <iostream>
#include <vector>

void testVector()
{

	std::vector<int> vec(5);
	vec.push_back(5);
	vec.pop_back();
	std::cout << vec.capacity() << std::endl;
}

int main()
{
	testVector();
	return 0;
}
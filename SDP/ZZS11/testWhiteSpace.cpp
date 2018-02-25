#include <iostream>
#include <fstream>

using std::ostream;
using std::ofstream;
using std::istream;
using std::ifstream;

void testNewLine()
{

	ifstream is("MyFile.txt");
	char currLet;
	// is>>currLet;
	// is>>currLet;
	// is>>currLet;
	// is>>currLet;

	currLet = is.get();
	currLet = is.get();
	currLet = is.get();
	currLet = is.get();
	currLet = is.get();
	currLet = is.get();
	currLet = is.get();
	currLet = is.get();
	currLet = is.get();

	std::cout << (int)currLet << std::endl;

	is.close();
}

int main()
{
	testNewLine();
	return 0;
}
#include "list.cpp"
#include "listiterator.cpp"

void testList()
{
	Box* l = new Box(69, nullptr);

	listAdd(l, 5);
	listAdd(l, 321);
	listAdd(l, 4451);
	listAdd(l, -14);
	listAdd(l, 20);

	listPrint(l);
}

void testCount()
{
	
	Box* l = new Box(69, nullptr);

	listAdd(l, 5);
	listAdd(l, 321);
	listAdd(l, 4451);
	listAdd(l, -14);
	listAdd(l, 69);

	std::cout << count(l, -13) << std::endl;
}

void testRange()
{
	Box* list = range(1, 10);
	listPrint(list);
}

void testRemoveAll()
{
	
	Box* l = new Box(69, nullptr);

	listAdd(l, 5);
	listAdd(l, 321);
	listAdd(l, 4451);
	listAdd(l, -14);
	listAdd(l, 69);
	listAdd(l, 45);
	listAdd(l, 32);

	removeAll(l, 69);
	listPrint(l);
}

void testAppend()
{

	Box* l1 = new Box(69, nullptr);

	listAdd(l1, 5);
	listAdd(l1, 321);
	listAdd(l1, 4451);
	listAdd(l1, -14);
	listAdd(l1, 69);
	listAdd(l1, 45);
	listAdd(l1, 32);

	Box* l2 = new Box(420, nullptr);
	listAdd(l2, 324);
	listAdd(l2, 512);
	listAdd(l2, 420);

	append(l1, l2);
	listPrint(l1);

}

void testConcat()
{
	Box* l1 = new Box(69, nullptr);

	listAdd(l1, 5);
	listAdd(l1, 321);
	listAdd(l1, 4451);
	listAdd(l1, -14);
	listAdd(l1, 69);
	listAdd(l1, 45);
	listAdd(l1, 32);

	Box* l2 = new Box(420, nullptr);
	listAdd(l2, 324);
	listAdd(l2, 512);
	listAdd(l2, 420);

	Box* l3 = concat(l1, l2);
	listPrint(l3);

}

void testMap()
{
	Box* l = new Box(69, nullptr);

	listAdd(l, 5);
	listAdd(l, 321);
	listAdd(l, 4451);
	listAdd(l, -14);
	listAdd(l, 69);
	listAdd(l, 45);
	listAdd(l, 32);

	map(l, square);
	listPrint(l);

}

void testReverse()
{
	Box* l = new Box(69, nullptr);

	listAdd(l, 5);
	listAdd(l, 321);
	listAdd(l, 4451);
	listAdd(l, -14);
	listAdd(l, 69);
	listAdd(l, 45);
	listAdd(l, 32);

	reverse(l);
	listPrint(l);
}

void testDuplicates()
{
	Box* l = new Box(69, nullptr);

	listAdd(l, 5);
	listAdd(l, 321);
	listAdd(l, 4451);
	listAdd(l, -14);
	listAdd(l, 68);
	listAdd(l, 45);
	listAdd(l, 32);

	std::cout << duplicates(l) << std::endl;

}

void testRemoveDuplicates()
{
	Box* l = new Box(69, nullptr);

	listAdd(l, 5);
	listAdd(l, 321);
	listAdd(l, 4451);
	listAdd(l, -14);
	listAdd(l, 69);
	listAdd(l, 45);
	listAdd(l, 32);

	removeDuplicates(l);
	listPrint(l);

}

void testIsRising()
{
	Box* l = new Box(69, nullptr);
	listAdd(l, 68);
	listAdd(l, 321);
	listAdd(l, 4451);
	std::cout << isRising(l) << std::endl;

}

void testIsDecreasing()
{
	Box* l = new Box(69, nullptr);
	listAdd(l, 68);
	listAdd(l, 67);
	listAdd(l, 66);
	std::cout << isDecreasing(l) << std::endl;

}

void testIsSorted()
{
	Box* l = new Box(69, nullptr);
	listAdd(l, 69);
	listAdd(l, 321);
	listAdd(l, 4451);
	std::cout << isSorted(l) << std::endl;
}

void testIsPalindrom()
{
	Box* l = new Box(69, nullptr);

	listAdd(l, 5);
	listAdd(l, 321);
	listAdd(l, 4451);
	listAdd(l, 32);
	listAdd(l, 5);
	listAdd(l, 69);

	std::cout << isPalindrom(l) << std::endl;

}

void testCount2()
{
	Box* l = new Box(69, nullptr);

	listAdd(l, 5);
	listAdd(l, 321);
	listAdd(l, 4451);
	listAdd(l, -14);
	listAdd(l, 69);

	std::cout << count2(l, -13) << std::endl;
}

void testMap2()
{
	Box* l = new Box(69, nullptr);

	listAdd(l, 5);
	listAdd(l, 321);
	listAdd(l, 4451);
	listAdd(l, -14);
	listAdd(l, 69);
	listAdd(l, 45);
	listAdd(l, 32);

	map2(l, square);
	listPrint(l);
}

int main()
{

	//testList();
	//testCount();
	//testRange();
	//testRemoveAll();
	//testAppend();
	//testConcat();
	//testMap();
	//testReverse(); 
	//testDuplicates();
	//testRemoveDuplicates();
	//testIsRising();
	//testIsDecreasing();
	//testIsSorted();
	//testIsPalindrom();
	//testCount2();
	testMap2();
	return 0;
}
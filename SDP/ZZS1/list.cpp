#ifndef __LIST_H
#define __LIST_H

#include <iostream>
#include <vector>

struct Box
{
	int data;
	Box* next;
	Box() 
	{
		data = 0;
		next = nullptr;
	}
	Box(int _data, Box* _next) : data(_data), next(_next) {}
};

void listAdd(Box* l, int x) //няма нужда да е псевдоним, тъй като l->next се променя директно
{
	while(l->next != nullptr)
		l = l->next;

	Box* newEl = new Box(x, nullptr);
	l->next = newEl; 
}

void listPrint(Box* l)
{
	while(l != nullptr)
	{
		std::cout << l->data << ' ';
		l = l->next;
	}
	std::cout << std::endl;
}

int count(Box* l, int x)
{
	int br = 0;
	while(l != nullptr)
	{
		if(l->data == x)
			br++;
		l = l->next;
	}
	return br;
}

Box* range(int x, int y)
{
	Box* pStart = new Box(x, nullptr);
 	x++;
	while(x <= y)
	{
		listAdd(pStart, x);
		x++;
	}

	return pStart;
}

void removeAll(Box*& l, int x)
{
	if(l->data == x) //ако още първият елемент е за изтриване
	{
		Box* tmp = l;
		l = l->next;
		delete tmp;
		if(l == nullptr)
			return;
	}
	
	Box* curr = l;
	while(curr->next != nullptr)
	{
		if(curr->next->data == x )
		{
			Box* tmp = curr->next;
			curr->next = curr->next->next;
			delete tmp;
		}
		else
			curr = curr->next;
	}
}

void append(Box*& l1, Box* l2)
{
	Box* curr = l1;
	while(curr->next != nullptr)
		curr = curr->next;
	curr->next = l2;
}

Box* concat(Box* l1, Box* l2)
{
	append(l1, l2); //няма проблем да подадем оригинала на append, тъй като така или иначе l1 е копие в случая, тоест подаваме оригинално копие и l1 и l2 не са се променили след concat
	return l1;
}

int square(int x)
{
	return x*x;
}

void map(Box*& l, int (*f)(int))
{
	Box* curr = l;
	while(curr != nullptr)
	{
		curr->data = f(curr->data);
		curr = curr->next;
	}
}

/*Box* concat1(Box* l1, Box* l2)
{
	append(l1, l2); 
	return l1;
}

Box* reverseRec(Box* l)
{
	if(l == nullptr)
		return nullptr;
	Box* first = new Box(l->data, nullptr);
	return concat1(reverseRec(l->next), first);
}

void reverse(Box* l)
{
	reverseRec(l);

}*/

//също не работи
/*
Box* reverseHelper(Box* l)
{
	if(l == nullptr)
		return nullptr;

	Box* first = new Box(l->data, nullptr);
	return concat(reverseHelper(l->next), first);

}

void reverse(Box*& l)
{
	l = reverseHelper(l);
}
*/

void reverse(Box*& l) //тъпо решение, но като не може с другите методи...
{
	std::vector<int> vec;
	Box* curr = l;
	while(curr != nullptr)
	{
		vec.push_back(curr->data);
		curr = curr->next;
	}
	Box* newList = new Box(vec[vec.size() - 1], nullptr);
	for(int i = vec.size() - 2; i >= 0; i--)
	{
		listAdd(newList, vec[i]);
	}
	l = newList;

}

int duplicatesHelper(Box* l, int x)
{
	int br = 0;
	while(l != nullptr)
	{
		if(l->data == x)
			br++;
		l = l->next;
	}
	return br;
}

bool duplicates(Box* l)
{
	while(l != nullptr)
	{
		if(duplicatesHelper(l, l->data) >= 2)
			return true;
		l = l->next;
	}
	return false;
}

void removeDuplicates(Box*& l)
{
	//случаят за първия елемент пак трябва да е отделно 
	if(duplicatesHelper(l, l->data) >= 2) //ако още първият елемент е за изтриване
	{
		removeAll(l, l->data);
		if(l == nullptr)
			return;
	}

	Box* curr = l;
	while(curr != nullptr)
	{
		if(duplicatesHelper(curr, curr->data) >= 2)
			removeAll(curr, curr->data);
		if(curr != nullptr)
			curr = curr->next;
	}
}

bool isRising(Box* l)
{
	if(l == nullptr)
		return false;
	if(l->next == nullptr)
		return true;

	return (l->data <= l->next->data) && isRising(l->next);
}

bool isDecreasing(Box* l)
{
	if(l == nullptr)
		return false;
	if(l->next == nullptr)
		return true;

	return (l->data >= l->next->data) && isDecreasing(l->next);
}

bool isSorted(Box* l)
{
	return isRising(l) || isDecreasing(l);
}

bool isPalindrom(Box* l)
{
	Box* originalList = l;
	Box* reversedList = l;
	reverse(reversedList);
	while(originalList != nullptr && reversedList != nullptr)
	{
		if(originalList->data != reversedList->data)
			return false;
		originalList = originalList->next;
		reversedList = reversedList->next;
	}
	return true;
}

#endif
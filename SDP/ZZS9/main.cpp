#include <cassert>
#include <string>
#include <iostream>
#include "hashmap.cpp"

unsigned int h (const std::string &s, unsigned int n)
{
  unsigned int sum = 0;
  for (int i = 0; i < s.length(); i++)
  {
    //h("abc") == h("acb");
    sum += s[i];
  }
  return sum % n;
}

void testBasicOp ()
{
  HashMap<std::string,int> map (255,h);

  map["John Smith"] = 10;
  map["John Smith"] = 12;
  map["John Simth"] = 15;

  map["Lisa Smith"] = 20;

  assert (map["John Smith"] == 12);
  assert (map["John Simth"] == 15);
  assert (h("John Smith",255) == h("John Simth",255));

  assert (map["Lisa Smith"] == 20);

}


void testCompare ()
{
  HashMap<std::string,int> map1 (255,h);
  HashMap<std::string,int> map2 (1,h);

  map1["John Smith"] = 10;
  map1["Lisa Smith"] = 20;

  map2["John Smith"] = 10;
  map2["Lisa Smith"] = 20;

  assert (map1 == map2);

  map2["Sam Doe"] = 20;

  assert (map1 != map2);

}


void testEfficiency()
{

  HashMap<std::string,int> map (255,h);

  map["John Smith"] = 10;
  map["John Smith"] = 12;
  map["John Simth"] = 15;

  map["Lisa Smith"] = 20;

  std::cout << map.efficiency() << std::endl;
  //std::cout << map << std::endl;
  //std::cout << map;
}


void testCountRepeats()
{

  ifstream f1("text1.txt"), f2("text2.txt");
  HashMap<std::string, int> map(255, h);
  map.countRepeats(f1, f2);

  f1.close();
  f2.close();

}

void testMostFrequentWord()
{
  HashMap<std::string, int> map(255, h);
  ifstream f("text3.txt");
  std::string word = map.mostFrequentWord(f);
  std::cout << word << std::endl;

  f.close();

}

void testIntersection()
{
  HashMap<std::string,int> map1(255,h);

  map1["torta"] = 69;
  map1["kufteta"] = 10;
  map1["pizza"] = 21;
  map1["tikvenik"] = 20;
  map1["negurche"] = 100;

  HashMap<std::string, int> map2(255, h);

  map2["torta"] = 420;
  map2["negurche"] = 101;
  map2["baklava"] = 19;
  map2["pileshkapane"] = 50;

  //HashMap<std::string, std::pair<int, int>> res(255, h);

  //res = map1*map2;

  std::cout << (map1*map2)["torta"].first << " "<< (map1*map2)["torta"].second << std::endl;
  std::cout << (map1*map2)["negurche"].first << " "<< (map1*map2)["negurche"].second << std::endl;
  std::cout << (map1*map2)["pizza"].first << " "<< (map1*map2)["pizza"].second << std::endl;
}

void testSymmetricDifference()
{
  HashMap<std::string,int> map1(255,h);

  map1["torta"] = 69;
  map1["kufteta"] = 10;
  map1["pizza"] = 21;
  map1["tikvenik"] = 20;
  map1["negurche"] = 100;

  HashMap<std::string, int> map2(255, h);

  map2["torta"] = 420;
  map2["negurche"] = 101;
  map2["baklava"] = 19;
  map2["pileshkapane"] = 50;

  std::cout << (map1 + map2)["torta"] << std::endl;
  std::cout << (map1 + map2)["negurche"] << std::endl;
  std::cout << (map1 + map2)["pizza"] << std::endl;
  std::cout << (map2 + map1)["baklava"] << std::endl;
}

void square(int& x)
{
  x = x*x;
}
void testMap()
{
  HashMap<std::string,int> map1(255,h);

  map1["torta"] = 69;
  map1["kufteta"] = 10;
  map1["pizza"] = 21;
  map1["tikvenik"] = 20;
  map1["negurche"] = 100;
  map1.map(square);

  std::cout << map1["kufteta"] << " " << map1["pizza"] << " " << map1["tikvenik"] << std::endl; 
}

std::string f(std::string& str)
{
  if(str.length() > 3)
  {
    str.erase(0, 3);
  }
  return str;
}

void testMapKeys()
{
  HashMap<std::string,int> map1(255,h);

  map1["torta"] = 69;
  map1["kufteta"] = 10;
  map1["pizza"] = 21;
  map1["tikvenik"] = 20;
  map1["negurche"] = 100;
  map1["tor"] = 0;
  map1["ti"] = 1000;
  map1["sad"] = -100;
  map1.mapKeys(f);

  std::cout << map1["kufteta"] <<" " << map1["teta"] << " " << map1["ta"] << " " << map1["sad"] << " " << map1["pizza"] << std::endl;

}

int main ()
{
  //testBasicOp ();
  //testCompare ();
  //std::cout << "Passed!\n";

  //testEfficiency();
  //testCountRepeats();
  //testMostFrequentWord();
  //testIntersection();
  //testSymmetricDifference();
  //testMap();
  testMapKeys();

  return 0;
}
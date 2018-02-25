#ifndef __HASHMAP__
#define __HASHMAP__

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
//#include <pair>
using std::ostream;
using std::ofstream;
using std::istream;
using std::ifstream;

template <class KeyType>
using HashFunction = unsigned int (*)(const KeyType&, unsigned int);

template <class KeyType, class ValueType>
class HashMap
{
public:
  HashMap (unsigned _n, HashFunction<KeyType> _h);
  ~HashMap ();
  HashMap (const HashMap<KeyType,ValueType>&);
  HashMap<KeyType,ValueType>& operator = (const HashMap<KeyType,ValueType> &);

  ValueType& operator [] (const KeyType&);
  const ValueType& operator [] (const KeyType&) const;

  bool hasKey (const KeyType &) const;

  bool operator == (const HashMap<KeyType,ValueType>&) const;
  bool operator != (const HashMap<KeyType,ValueType>&) const;

  void resize (unsigned int);

  //ZZS
  double efficiency() const;
  //friend ostream& operator << (ostream& os, const HashMap<KeyType, ValueType>& map);
  void countRepeats(istream& , istream& ); 
  std::string mostFrequentWord(istream&);
  HashMap<KeyType, std::pair<ValueType, ValueType>> operator*(HashMap<KeyType, ValueType>& );
  HashMap<KeyType, ValueType> operator+(HashMap<KeyType, ValueType>& );
  void map(void (*) (ValueType&));
  void mapKeys(KeyType (*) (KeyType&));

private:

  struct kvpair
  {
    kvpair (KeyType _k, ValueType _v):key(_k), value (_v){}
    KeyType key;
    ValueType value;
  };

  int locate (const KeyType&, unsigned int) const;

  unsigned int size, count;
  HashFunction<KeyType> h;
  std::vector<std::vector<kvpair>> *buckets;
};


template <class KeyType, class ValueType>
HashMap<KeyType,ValueType>
::HashMap (unsigned _n,
 HashFunction<KeyType> _h):size(_n), h(_h)
{
  count = 0;
  buckets = new std::vector<std::vector<kvpair>>;
  std::vector<kvpair> emptyBucket;
  buckets->assign (size,emptyBucket);
}

template <class KeyType, class ValueType>
HashMap<KeyType,ValueType>::~HashMap ()
{
  delete buckets;
}
template <class KeyType, class ValueType>
HashMap<KeyType,ValueType>::HashMap (const HashMap<KeyType,ValueType> &other)
{
  size = other.size;
  count = other.count;
  buckets = new std::vector<std::vector<kvpair>>;
  *buckets = *other.buckets;
}

template <class KeyType, class ValueType>
HashMap<KeyType,ValueType>&
HashMap<KeyType,ValueType>::operator =
(const HashMap<KeyType,ValueType> &other)
{
  if (this != &other)
  {
    delete buckets;
    buckets = new std::vector<std::vector<kvpair>>;
    *buckets = other.buckets;
    size = other.size;
    count = other.count;
  }
  return *this;
}

template <class KeyType, class ValueType>
int HashMap<KeyType,ValueType>::locate (const KeyType& key, unsigned int ix) const
{
  for (int i = 0; i < (*buckets)[ix].size(); i++)
  {
    if ((*buckets)[ix][i].key == key)
    {
      return i;
    }
  }
  return -1;
}


template <class KeyType, class ValueType>
ValueType& HashMap<KeyType,ValueType>::operator [] (const KeyType &key)
{
  unsigned int ix = h (key, size);// % size;
  assert (ix < size);

  unsigned int n = locate (key,ix);

  if (n == -1)
  {
    (*buckets)[ix].push_back (kvpair(key,ValueType()));
    n = (*buckets)[ix].size()-1;
    count++;
  }

  return (*buckets)[ix][n].value;

}

template <class KeyType, class ValueType>
const ValueType& HashMap<KeyType,ValueType>::operator [] (const KeyType &key) const
{
  unsigned int ix = h (key, size);// % size;
  assert (ix < size);

  unsigned int n = locate (key,ix);
  assert (n >= 0);

  return (*buckets)[ix][n].value;

}

template <class KeyType, class ValueType>
bool HashMap<KeyType,ValueType>::operator == (const HashMap<KeyType,ValueType> &other) const
{

  for (int ibucket = 0; ibucket < buckets->size(); ibucket++)
  {
    const std::vector<kvpair> &bucket = (*buckets)[ibucket];
    for (int el = 0; el < bucket.size(); el++)
    {
      const KeyType &key = bucket[el].key;
      const ValueType & value = bucket[el].value;
      if (other.hasKey (key) && other[key] != value)
      {
        return false;
      }
    }
  }

  return count == other.count;
}

template <class KeyType, class ValueType>
bool HashMap<KeyType,ValueType>::hasKey (const KeyType &key) const
{
  unsigned ix = h (key,size);
  return locate (key,ix) >= 0;
}

template <class KeyType, class ValueType>
bool HashMap<KeyType,ValueType>::operator != (const HashMap<KeyType,ValueType> &other) const
{
  return !(*this == other);
}

template <class KeyType, class ValueType>
void HashMap<KeyType,ValueType>::resize (unsigned int newSize)
{
  HashMap<KeyType,ValueType> newMap (size,h);

  for (int ibucket = 0; ibucket < buckets->size(); ibucket++)
  {
    const std::vector<kvpair> &bucket = *buckets[ibucket];
    for (int el = 0; el < bucket.size(); el++)
    {
      const KeyType &key = bucket[el].key;
      const ValueType & value = bucket[el].value;
      newMap[key] = value;
    }
  }

  size = newSize;

  std::vector<std::vector<kvpair>> *save = buckets;
  buckets = newMap.buckets;
  newMap.buckets = save;

}
////////////



//ZZS
template <class KeyType, class ValueType>
double HashMap<KeyType, ValueType>::efficiency() const
{
  double colliding = 0;
  for(int i = 0; i < buckets->size(); i++)
  {
    if((*buckets)[i].size() > 1)
    {
      colliding += (*buckets)[i].size();
    }
  }
  std::cout << colliding << ' ' << count << std::endl;

  return (count - colliding)/count;
}


// template <class KeyType, class ValueType>
// std::ostream& operator << (ostream& os, const HashMap<KeyType, ValueType>& map)
// {

//   for(int i = 0; i < (map.buckets)->size(); i++)
//   {
//     for(int j = 0; j < (*map.buckets)[i].size(); j++)
//     {
//       os << j + 1 << (*map.buckets)[i][j].key << ' ' << (*map.buckets)[i][j].value << "  ";
//     }
//     os << std::endl;
//   }

//   return os;
// }

template <>
void HashMap<std::string, int>::countRepeats(istream& t1, istream& t2) 
{


  std::string word;
  

  while(!t1.eof())
  {
    t1 >> word;
    //std::cout << word << std::endl;
    if(word.back() < 'a' || word.back() > 'z')
      word.pop_back();
    if(word.front() < 'a' || word.front() > 'z')
    {
      if(word.front() >= 'A' && word.front() <= 'Z' )
        word[0] = word[0] - 'A' + 'a';
      else
        word.erase(0, 1);
    }
    (*this)[word] = 1;
  }

  while(!t2.eof())
  {
    t2 >> word;
    if(word.back() < 'a' || word.back() > 'z')
      word.pop_back();

    if(word.front() < 'a' || word.front() > 'z')
    {
      if(word.front() >= 'A' && word.front() <= 'Z' )
        word[0] = word[0] - 'A' + 'a';
      else
        word.erase(0, 1);
    }
    if((*this)[word] >= 1)
      (*this)[word]++;
  }


  for(int i = 0; i < buckets->size(); i++)
  {
    if(!(*buckets)[i].empty())
    {
      for(int j = 0; j < (*buckets)[i].size(); j++)
        if((*buckets)[i][j].value > 1)
          std::cout << (*buckets)[i][j].key << " " << (*buckets)[i][j].value - 1 << std::endl;
    }
  }

}

template <>
std::string HashMap<std::string, int>::mostFrequentWord(istream& t)
{

  std::string word;
  while(!t.eof())
  {
    t >> word;
    //std::cout << word << std::endl;
    if(word.back() < 'a' || word.back() > 'z')
      word.pop_back();
    if(word.front() < 'a' || word.front() > 'z')
    {
      if(word.front() >= 'A' && word.front() <= 'Z' )
        word[0] = word[0] - 'A' + 'a';
      else
        word.erase(0, 1);
    }
    (*this)[word]++;
  }
  int maxFrequency = 0;
  std::string maxWord = "";
  for(int i = 0; i < (*buckets).size(); i++)
  {
    for(int j = 0; j < (*buckets)[i].size(); j++)
    {
      if((*buckets)[i][j].value > maxFrequency && (*buckets)[i][j].key.length() > 3)
      {
        maxFrequency = (*buckets)[i][j].value;
        maxWord = (*buckets)[i][j].key;
      }
    }
  }

  return maxWord;
}

template <class KeyType, class ValueType>
HashMap<KeyType, std::pair<ValueType, ValueType>> HashMap<KeyType, ValueType>::operator*(HashMap<KeyType, ValueType>& other)
{
  HashMap<KeyType, std::pair<ValueType, ValueType>> res(other.size, other.h); //vzema harakteristikite na vtoriq HashMap

  int ix;
  for(int i = 0; i < (*buckets).size(); i++)
  {
    for(int j = 0; j < (*buckets)[i].size(); j++)
    {
      ix = other.h((*buckets)[i][j].key, other.size);
      ix = other.locate((*buckets)[i][j].key, ix);
      if(ix != -1)
        res[(*buckets)[i][j].key] = std::pair<ValueType, ValueType>((*this)[(*buckets)[i][j].key], other[(*buckets)[i][j].key]);
    }
  }

  return res;
}

template <class KeyType, class ValueType>
HashMap<KeyType, ValueType> HashMap<KeyType, ValueType>::operator+(HashMap<KeyType, ValueType>& other)
{
  HashMap<KeyType, ValueType> res(other.size, other.h);

  int ix;
  for(int i = 0; i < (*buckets).size(); i++)
  {
    for(int j = 0; j < (*buckets)[i].size(); j++)
    {
      ix = other.h((*buckets)[i][j].key, other.size);
      ix = other.locate((*buckets)[i][j].key, ix);
      if(ix == -1)
        res[(*buckets)[i][j].key] = (*buckets)[i][j].value;
    }
  }
  for(int i = 0; i < (*other.buckets).size(); i++)
  {
    for(int j = 0; j < (*other.buckets)[i].size(); j++)
    {
      ix = h((*other.buckets)[i][j].key, size);
      ix = locate((*other.buckets)[i][j].key, ix);
      if(ix == -1)
        res[(*other.buckets)[i][j].key] = (*other.buckets)[i][j].value;
    }
  }

  return res;
}

template <class KeyType, class ValueType>
void HashMap<KeyType, ValueType>::map(void (*f) (ValueType& ))
{
  for(int i = 0; i < (*buckets).size(); i++)
  {
    for(int j = 0; j < (*buckets)[i].size(); j++)
    {
      f ((*buckets)[i][j].value);
    }
  }
}

template <class KeyType, class ValueType>
void HashMap<KeyType, ValueType>::mapKeys(KeyType (*f) (KeyType&))
{

  for(int i = 0; i < (*buckets).size(); i++)
  {
    if(!(*buckets)[i].empty())
    {
      std::vector<kvpair> emptyVector;
      std::vector<kvpair> temp = (*buckets)[i];
      // while(!(*buckets)[i].empty())
      // {
      //   (*buckets)[i].pop_back();
      // }
      (*buckets)[i].clear();
      for(int j = 0; j < temp.size(); j++)
      {
        (*this)[f(temp[j].key)] = temp[j].value;
      }
    }
  }
}

#endif
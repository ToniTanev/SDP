#include <cassert>
#include "dfa.cpp"


/*void testSimple ()
{
  DFSA a;

  a.setFinalState (0);
  a.setFinalState (1000);
  a.setFinalState (500);

  a[0]['a'] = 1000;
  a[0]['b'] = 500;
  a[0]['c'] = 5000;

  assert (a[0]['a'] == 1000);
  assert (a[0]['b'] == 500);
  assert (a[0]['c'] == 5000);

  assert (a.hasSymbol (0,'a'));
  assert (!a.hasSymbol (0,'z'));

  std::vector<char> symbols = a.getSymbolsFrom(0);

  assert (std::find(symbols.begin(),symbols.end(),'a') != symbols.end());
  assert (std::find(symbols.begin(),symbols.end(),'z') == symbols.end());

  std::cout << "Symbols from 0:";
  for (char c : a.getSymbolsFrom(0))
  {
    std::cout << c;
  }
  std::cout << std::endl;

}*/


void testPrintDotty()
{
  DFSA dfsa(69);
  dfsa[69]['a'] = 999;
  dfsa[69]['b'] = 420;
  dfsa[999]['a'] = 999;
  dfsa[999]['b'] = 300;
  dfsa[420]['a'] = 999;
  dfsa[300]['b'] = 69;
  dfsa.setFinalState(69);
  dfsa.setFinalState(999);

  ofstream f("dfsa.txt");
  dfsa.printDotty(f);
  f.close();

}

void testReadFromFile()
{

  ifstream is("Automaton.txt");
  ofstream os("DOT.txt");
  DFSA dfsa((int)'A');
  dfsa.readFromFile(is);

  dfsa.printDotty(os);

  is.close();
  os.close();
}

void testIsWord()
{
  DFSA dfsa;
  dfsa[0]['b'] = 23;
  dfsa[23]['c'] = 46;
  dfsa[46]['d'] = 92;
  dfsa[92]['e'] = 184;
  dfsa[184]['f'] = 368;
  dfsa.setFinalState(368);
  dfsa.setFinalState(46);
  dfsa.setFinalState(92);

  std::cout << dfsa.isWord("b") << std::endl;

}

int main ()
{
  //testSimple();
  //testPrintDotty();
  //testReadFromFile();
  testIsWord();
  return 0;
}
#include <iostream>
#include <string>

using namespace std;

int findFoo(int password, int guess) {
  string s1 = to_string(password);
  string s2 = to_string(guess);

  int counter = 0;
  for (int i = 0; i < 4; i++) {
    if (s1[i] == s2[i])
      counter++;
  }
  return counter;
}

int findBar(int password, int guess) {
  string s1 = to_string(password);
  string s2 = to_string(guess);

  int counter = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (i == j)
	continue;
    }
  }

  return counter;
}

bool test(int password, int guess, int foo, int bar) {
  return findFoo(password, guess) == foo &&
         findBar(password, guess) == bar;
}

int main()
{
  int testCount;
  cin >> testCount;

  int guesses[testCount];
  int foo[testCount];
  int bar[testCount];

  for (int i = 0; i < testCount; i++) {
    cin >> guesses[i]
	>> foo[i]
	>> bar[i];
  }

  bool found = false;
  bool pass;
  for (int i = 1000; i <= 9999; i++) {
    pass = true;
    for (int j = 0; j < testCount; j++) {
      if (!test(i, guesses[i], foo[i], bar[i])) {
	pass = false;
	break;
      }
    }
    
    if (pass) {
      found = true;
      cout << i << "\n";
      break;
    }
  }

  if (!found)
    cout << "NONE\n";
}

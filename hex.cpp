#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int foo(char bar) {
  switch (bar) {
    case '0': return 0;
    case '1': return 1;
    case '2': return 2;
    case '3': return 3;
    case '4': return 4;
    case '5': return 5;
    case '6': return 6;
    case '7': return 7;
    case '8': return 8;
    case '9': return 9;
    case 'A': return 10;
    case 'B': return 11;
    case 'C': return 12;
    case 'D': return 13;
    case 'E': return 14;
    case 'F': return 15;
  }
}

int hexToDec(string hex) {
  int res = 0;
  for (int i = hex.length() - 1; i >= 0; i--) {
    res += pow(16, (hex.length() - 1) - i) * foo(hex[i]);
  }
  return res;
}

int printDecToOct(int dec) {
  vector<int> res = vector<int>();
  int length = 0;
  int div = dec;
  
  while (div > 0) {
    res.push_back(div % 8);
    div = (int) (div / 8);
    length++;
  }

  for (int i = length - 1; i >= 0; i--)
    cout << res[i];
  cout << endl;
}

int main() {
  string hex;
  cin >> hex;
  
  printDecToOct(hexToDec(hex));

  return 0;
}

#include <iostream>

using namespace std;

string first(int end, string text) {
  string result = "";
  for (int i = 0; i < end; i++) {
    result += text[i];
  }
  return result;
}

string last(int beginning, string text) {
  string result = "";
  for (int i = text.length() - beginning; i < text.length(); i++) {
    result += text[i];
  }
  return result;
}

int main()
{
  string string1, string2;
  cin >> string1 >> string2;

  int length1 = 0;
  int length2 = 0;
  for (int i = 0; i < string1.length(); i++) {
    if (first(i, string1) == last(i, string2)) {
      length1 = i;
    }
    
    if (last(i, string1) == first(i, string2)) {
      length2 = i;
    }
  }

  if (length1 > length2) {
    cout << length1 << "\n";
  } else if (length2 > length1) {
    cout << length2 << "\n";
  } else {
    cout << length1 << "\n";
  }
}

#include <iostream>

using namespace std;

string foobar(string foo, int bar) {
  string result = "";
  for (int i = bar; i < foo.length(); i++)
    result += foo[i];
  return result + foo;
}

int main()
{
  int cowCount;
  cin >> cowCount;

  int iterations[cowCount];
  int starts[cowCount];
  string foos[cowCount];
  
  for (int i = 0; i < cowCount; i++) {
    cin >> starts[i]
	>> iterations[i]
	>> foos[i];
  }

  for (int i = 0; i < cowCount; i++) {
    string result = foos[i];
    for (int j = 0; j < iterations[i]; j++) {
      result = foobar(result, starts[i]);
    }
    cout << result << "\n";
  }
}

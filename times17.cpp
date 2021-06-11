#include <iostream>

using namespace std;

int baz(char carry) {
  return (carry == '1') ? 1 : 0;
}

int main() {
  string original;
  cin >> original;

  string foo = original + "0000";
  string bar = "0000" + original;
  
  //cout << foo << " " << bar << endl;
  
  string result = "";
  
  char carry = '0';
  for (int i = foo.length() - 1; i >= 0; i--) {
    int sum = baz(foo[i]) + baz(bar[i]) + baz(carry);

    /*
    cout << baz(foo[i]) << " "
	 << baz(bar[i]) << " "
	 << baz(carry) << endl;
    */
    
    if (sum == 0) {
      carry = '0';
      result = '0' + result;
    } else if (sum == 1) {
      carry = '0';
      result = '1' + result;
    } else if (sum == 2) {
      carry = '1';
      result = '0' + result;
    } else if (sum == 3) {
      carry = '1';
      result = '1' + result;
    }
  }

  if (carry == '1')
    result = '1' + result;

  cout << result << endl;
}

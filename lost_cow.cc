#include <iostream>

using namespace std;

bool goingRight = true;
int distance;
int steps = 1;
int res = 0;

int farmerStartPos;
int farmerPos;
int cowPos;

int main()
{
  cout << "Enter farmer's position: ";
  cin >> farmerStartPos;
  
  cout << "Enter cow's position: ";
  cin >> cowPos;

  farmerPos = farmerStartPos;

  while (farmerPos != cowPos) {
    res += 1;
    distance = farmerStartPos - farmerPos;
    if (distance >= steps || distance <= steps * -1) {
      if (direction == '>') {
        direction = '<';
      } else {
        direction = '>';
      }
      steps *= 2;
    }
    if (direction == '>') {
      farmerPos += 1;
    } else {
      farmerPos -= 1;
    }
    // cout << farmerPos << "\n";
  }
  
  cout << "Distance: " << res << "\n";
  
  return 0;
}

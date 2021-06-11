#include <iostream>

using namespace std;

int main() {
  int cowCount;
  cin >> cowCount;

  int before[cowCount];
  int after[cowCount];
  int indices[cowCount];

  for (int i = 0; i < cowCount; i++) {
    cin >> before[i];
  }

  for (int i = 0; i < cowCount; i++) {
    cin >> after[i];
    indices[after[i] - 1] = i;
  }
  
  int cyclicShifts = 0;
  int longestShift = 0;
  for (int i = 0; i < cowCount; i++) {
    if (before[i] == after[i])
      continue;
    
    int out = 0;
    int shiftLength = 0;
    while (true) {
      int replaceIndex = (out == 0) ? i : indices[out - 1];
      int temp = before[replaceIndex];
      before[replaceIndex] = out;
      
      if (temp == 0) break;
      out = temp;

      shiftLength++;
    }

    cyclicShifts++;
    if (shiftLength > longestShift)
      longestShift = shiftLength;
  }

  cout << cyclicShifts << " " << longestShift << endl;
}

#include <iostream>

using std::cout;
using std::cin;

void printArray(int array[]) {
  for (int i = 0; i < 5; i++) {
    if (i < 4) {
      cout << array[i] << ", ";
    } else {
      cout << array[i];
    }
  }
  cout << "\n";
}

int getSmallest(int array[]) {
  int res = 0;
  int num = 0;
  for (int i = 0; i < 5; i++) {
    if ((array[i] < num || num == 0) && array[i] != 0) {
      res = i;
      num = array[i];
    }
  }
  return res;
}

int main()
{
  // Get unsorted array
  int array[5] = {0, 0, 0, 0, 0};
  int inp = 0;
  int i = 0;
  while (i < 5) {
    cout << "Enter a number larger than zero: ";
    cin >> inp;
    if (inp <= 0) {
      cout << "Positive numbers above zero only.\n\n";
    } else {
      array[i] = inp;
      i++;
    }
  }

  int smallest = 0;

  // Create replica of unsorted array for sorting
  int unsorted[5] = {0, 0, 0, 0, 0};
  for (int i = 0; i < 5; i++) {
    unsorted[i] = array[i];
  }

  // Sort array
  int sortedArray[5] = {0, 0, 0, 0, 0};
  for (int i = 0; i < 5; i++) {
    smallest = getSmallest(unsorted);
    sortedArray[i] = unsorted[smallest];
    unsorted[smallest] = 0;
  }

  // Give user feedback
  cout << "\nNon-sorted version of array:\n";
  printArray(array);
  cout << "\nSorted version:\n";
  printArray(sortedArray);

  return 0;
}

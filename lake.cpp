#include <iostream>

using namespace std;

int grid[100][100];
int width, height;
int lakeCount;

void floodfill(int i, int j, int color)
{
  grid[i][j] = color;
  if (i - 1 >= 0 && grid[i - 1][j] == 1)
    floodfill(i - 1, j, color);
  if (i + 1 < height && grid[i + 1][j] == 1)
    floodfill(i + 1, j, color);
  if (j - 1 >= 0 && grid[i][j - 1] == 1)
    floodfill(i, j - 1, color);
  if (j + 1 < width && grid[i][j + 1] == 1)
    floodfill(i, j + 1, color);
}

void markLakes()
{
  lakeCount = 0;

  int color = 2;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if (grid[i][j] == 1) {
	floodfill(i, j, color);
	lakeCount++;
	color++;
      }
    }
  }
}

int findLargestLake()
{
  int size = 0;

  int newSize;
  for (int x = 0; x < lakeCount; x++) {
    newSize = 0;
    for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
	if (grid[i][j] == x + 2)
	  newSize++;
      }
    }

    if (newSize > size)
      size = newSize;
  }

  return size;
}

int main()
{
  cin >> height >> width;
  
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      grid[i][j] = 0;
    }
  }

  int spotCount;
  cin >> spotCount;

  int row, col;
  for (int i = 0; i < spotCount; i++) {
    cin >> row >> col;
    grid[row - 1][col - 1] = 1;
  }
  
  markLakes();

  /*
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      cout << grid[i][j];
    }
    cout << endl;
  }
  */
  
  cout << findLargestLake() << endl;
}

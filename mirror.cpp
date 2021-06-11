#include <iostream>
#include <vector>

using namespace std;

vector<vector<char> > grid;
int width, height;

int simulateBeam(char dir, int c, int r) {
  int length = 0;
  char direction = dir;
  int row = r;
  int col = c;
  while (true) {
    length++;
    char current = grid[row][col];
    
    if (direction == '>' && current == '/')
      direction = '^';
    else if (direction == '>' && current == '\\')
      direction = 'v';
    else if (direction == '<' && current == '/')
      direction = 'v';
    else if (direction == '<' && current == '\\')
      direction = '^';
    else if (direction == '^' && current == '/')
      direction = '>';
    else if (direction == '^' && current == '\\')
      direction = '<';
    else if (direction == 'v' && current == '/')
      direction = '<';
    else if (direction == 'v' && current == '\\')
      direction = '>';

    int newRow = row;
    int newCol = col;
    if (direction == '^')
      newRow--;
    else if (direction == 'v')
      newRow++;
    else if (direction == '>')
      newCol++;
    else if (direction == '<')
      newCol--;

    if (newRow < 0 || newRow >= height || newCol < 0 || newCol >= width)
      break;

    row = newRow;
    col = newCol;
  }
  return length;
}

int main() {
  cin >> width >> height;

  for (int i = 0; i < height; i++) {
    string row;
    cin >> row;

    grid.push_back(vector<char>());
    for (int j = 0; j < width; j++) {
      grid[i].push_back(row[j]);
    }
  }

  int longest = 0;
  
  for (int i = 0; i < height; i++) {
    int foo = simulateBeam('>', 0, i);
    int bar = simulateBeam('<', width - 1, i);
    if (foo > longest) longest = foo;
    if (bar > longest) longest = bar;
  }

  for (int i = 0; i < width; i++) {
    int foo = simulateBeam('v', i, 0);
    int bar = simulateBeam('^', i, height - 1);
    if (foo > longest) longest = foo;
    if (bar > longest) longest = bar;
  }

  cout << longest << endl;
}

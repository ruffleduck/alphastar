#include <iostream>

using namespace std;

const int COW_AMOUNT = 3;
const int GENOMES = 6;

const char SPOTS[COW_AMOUNT][GENOMES] = {
  {'A', 'B', 'G', 'F', 'F', 'B'},
  {'B', 'G', 'F', 'F', 'B', 'A'},
  {'B', 'G', 'B', 'A', 'A', 'F'}
};

const char SPOTLESS[COW_AMOUNT][GENOMES] = {
  {'A', 'F', 'D', 'F', 'F', 'B'},
  {'B', 'F', 'D', 'D', 'B', 'D'},
  {'C', 'F', 'E', 'A', 'A', 'F'}
};


char spotsCol[COW_AMOUNT];
char spotlessCol[COW_AMOUNT];
bool explainSpottiness;
int res = 0;


void printArray(char array[COW_AMOUNT]) {
  for (int i = 0; i < COW_AMOUNT; i++) {
    cout << array[i] << " ";
  }
  cout << "\n";
}


int main()
{ 
  for (int col = 0; col < GENOMES; col++) {
    for (int row = 0; row < GENOMES; row++) {
      spotsCol[row] = SPOTS[row][col];
      spotlessCol[row] = SPOTLESS[row][col];
    }
    
    // printArray(spotsCol);
    // printArray(spotlessCol);
    
    explainSpottiness = true;
    for (int i = 0; i < COW_AMOUNT; i++) {
      for (int j = 0; j < COW_AMOUNT; j++) {
        if (spotsCol[i] == spotlessCol[j]) {
          explainSpottiness = false;
	  break;
        }
      }
    }

    if (explainSpottiness) { res++; }
  }

  cout << res << "\n";
  
  return 0;
}


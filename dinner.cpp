#include <iostream>

using namespace std;

struct Point {
  int x, y;
};

int main() {
  int cowCount, seatCount;
  cin >> cowCount >> seatCount;

  Point cows[cowCount];
  Point seats[seatCount];

  for (int i = 0; i < cowCount; i++) {
    cin >> cows[i].x >> cows[i].y;
  }

  for (int i = 0; i < seatCount; i++) {
    cin >> seats[i].x >> seats[i].y;
  }
  
  for (int i = 0; i < seatCount; i++) {

    // Get best
    int bestDistance = NULL;
    int closestCow = 0;
    for (int j = 0; j < cowCount; j++) {
      int dist = distance(seats[i], cows[j]);
      if (bestDistance == NULL || dist < bestDistance) {
	bestDistance = dist;
	closestCow = j + 1;
      }
    }

    hungr
    
  }
}

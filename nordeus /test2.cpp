/*
cudovista - pozicija, brzina (input, p, v)
oruzije puca 1/jedinici vremena
max cudovista koje mogu eliminisati?

udaljenost - brzina
(9, 5), (5, 2), (10, 1) <- sortirano
  9/5 = 1.8    5/2 = 2.5     10/1 = 10
 vreme = 3
 brojac = 3
 vreme++

-> ()

*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// (9, 5, 2), (5, 2, 1), (10, 1, 9) <- sortirano
//   9/5 = 1.8 - 2 + 1 = 0.8  1   5/2 = 2.5 - 1+1 = 2.5  2  10/1 = 10 - 9 +1 = 2
//   <- times 3
// 0.8 2 2.5

// 3hp vreme: 4 <- mogu da eliminisem
// 3hp vreme: 2 <- ne mogu da elimisem

int game(vector<int> &speeds, vector<int> &distances,
         vector<int> &monster_health, float reload_time) {
  int n = speeds.size();
  vector<float> times(n);
  for (int i = 0; i < n; i++)
    times[i] = distances[i] / (float)speeds[i] - monster_health[i] + 1;
  sort(times.begin(), times.end()); // O(nlogn)
  int counter = 0;
  float passed_time = 0;
  for (int i = 0; i < n; i++) {
    if (passed_time < times[i])
      counter++;
    else
      break;
    passed_time += reload_time;
  }
  return counter;
}

int main() {

  cout << game() << endl;
  return 0;
}
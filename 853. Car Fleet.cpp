#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
  int carFleet(int target, vector<int> &position, vector<int> &speed) {
    int n = position.size();
    vector<pair<int, int>> cars(n);
    for (int i = 0; i < n; i++)
      cars[i] = make_pair(position[i], speed[i]);

    sort(cars.begin(), cars.end());

    stack<float> st;
    for (pair<int, int> car : cars) {
      float time = (target - car.first) / (float)car.second;
      while (!st.empty() && time >= st.top())
        st.pop();
      st.push(time);
    }

    return st.size();
  }
};
#include <array>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<string, vector<string>> map;

    for (string &s : strs) {
      array<int, 26> count = {0};

      for (char c : s)
        count[c - 'a']++;

      string key;
      for (int num : count)
        key += to_string(num) + '#';

      map[key].push_back(s);
    }

    vector<vector<string>> res;
    for (const auto &entr : map)
      res.push_back(move(entr.second));

    return res;
  }
};
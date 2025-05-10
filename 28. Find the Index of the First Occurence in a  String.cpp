#include <string>
using namespace std;

class Solution { // Ako cemo bez varanja treba KMP
public:
  int strStr(string &haystack, string &needle) {
    int found = haystack.find(needle);
    return found != string::npos ? found : -1;
  }
};
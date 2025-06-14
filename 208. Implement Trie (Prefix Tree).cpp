#include <string>
#include <unordered_map>
using namespace std;

class Trie {
private:
  struct Node {
    bool end = false;
    Node *children[26] = {nullptr};
  };
  Node *tree;

public:
  Trie() { tree = new Node(); }

  void insert(const string &word) {
    Node *tmp = tree;
    for (char c : word) {
      int idx = c - 'a';
      if (!tmp->children[idx])
        tmp->children[idx] = new Node();
      tmp = tmp->children[idx];
    }
    tmp->end = true;
  }

  bool search(const string &word) {
    Node *tmp = tree;
    for (char c : word) {
      int idx = c - 'a';
      if (!tmp->children[idx])
        return false;
      tmp = tmp->children[idx];
    }
    return tmp->end;
  }

  bool startsWith(const string &prefix) {
    Node *tmp = tree;
    for (char c : prefix) {
      int idx = c - 'a';
      if (!tmp->children[idx])
        return false;
      tmp = tmp->children[idx];
    }
    return true;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
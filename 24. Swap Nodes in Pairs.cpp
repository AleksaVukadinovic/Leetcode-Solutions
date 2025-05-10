struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *swapPairs(ListNode *head) {
    if (!head || !head->next)
      return head;
    ListNode *res = new ListNode(-1);
    res->next = head;
    ListNode *prev = res;
    while (head && head->next) {
      ListNode *node1 = head;
      ListNode *node2 = head->next;
      prev->next = node2;
      node1->next = node2->next;
      node2->next = node1;
      prev = node1;
      head = node1->next;
    }
    return res->next;
  }
};
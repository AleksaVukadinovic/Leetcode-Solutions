
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *head = new ListNode(0);
    ListNode *mov = head;
    int a, b, sum, carryOver = 0;
    while (l1 || l2 || carryOver != 0) {
      a = l1 ? l1->val : 0;
      b = l2 ? l2->val : 0;

      sum = (a + b + carryOver) % 10;
      carryOver = (a + b + carryOver) / 10;

      mov->next = new ListNode(sum);
      mov = mov->next;

      l1 = l1 ? l1->next : l1;
      l2 = l2 ? l2->next : l2;
    }
    return head->next;
  }
};
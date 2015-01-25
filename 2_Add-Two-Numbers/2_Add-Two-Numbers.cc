// 61 ms
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        uint64_t v1 = 0;
        uint64_t p1 = 1;
        uint64_t v2 = 0;
        uint64_t p2 = 1;
        while(l1) {
            v1 += p1 * l1->val;
            p1 *= 10;
            l1 = l1->next;
        }
        while(l2) {
            v2 += p2 * l2->val;
            p2 *= 10;
            l2 = l2->next;
        }
        uint64_t sum = v1 + v2;
        ListNode* root = new ListNode(0);
        ListNode* now = root;
        while(true) {
            now->val = sum % 10;
            sum /= 10;
            if (sum == 0) {
                return root;
            }
            ListNode* temp = new ListNode(0);
            now->next = temp;
            now = temp;
        }
    }
};
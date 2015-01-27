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


// 57ms
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode* root = new ListNode(0);
        ListNode* now = root;
        bool carry_flag = false;
        bool l1_end = false;
        bool l2_end = false;
        int temp = 0;
        
        while(true) {
            temp = (carry_flag ? 1 : 0) + (l1_end ? 0 : l1->val) + (l2_end ? 0 : l2->val);
            carry_flag = (temp >= 10);
            now->val = temp % 10;
            if (!l1_end) {
                l1 = l1->next;    
                l1_end = (l1 == NULL);
            }
            if (!l2_end) {
                l2 = l2->next;
                l2_end = (l2 == NULL);    
            }
            if (l1_end && l2_end) {
                if (carry_flag) {
                    ListNode* last_node = new ListNode(1);
                    now->next = last_node;
                }
                return root;
            }
            ListNode* new_node = new ListNode(0);
            now->next = new_node;
            now = new_node;
        }
        return root;
    }
};

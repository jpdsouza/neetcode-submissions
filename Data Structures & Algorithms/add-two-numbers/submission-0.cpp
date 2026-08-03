/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int n1 = 0;
        int n2 = 0;
        int count = 1;
        
        while(l1)
        {
            n1 += count * l1->val;
            count *= 10;
            l1 = l1->next;
        }
        count = 1;
        while(l2)
        {
            n2 += count * l2->val;
            count *= 10;
            l2 = l2->next;
        }
        int sum = n1 + n2;
        ListNode result;
        ListNode* node = &result;
        if (sum == 0)
            return new ListNode(0);
        while(sum > 0)
        {
            node->next = new ListNode(sum%10);
            sum = sum/10;
            node = node->next;
        }
        node->next = nullptr;
        return result.next;
    }
};

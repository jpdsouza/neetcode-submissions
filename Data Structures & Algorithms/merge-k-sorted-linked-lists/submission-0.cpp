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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode result;
        ListNode* node = &result;
        int minIndex;

        while(true)
        {
            minIndex = -1;
            for(int i=0; i<lists.size(); i++)
            {
                if(!lists[i])
                    continue;
                if(minIndex == -1 || min(lists[minIndex]->val, lists[i]->val) != lists[minIndex]->val)
                    minIndex = i;
            }
            if(minIndex == -1)
                break;
            node -> next = lists[minIndex];
            lists[minIndex] = lists[minIndex] -> next;
            node = node ->next;
        }
        return result.next;
    }
};

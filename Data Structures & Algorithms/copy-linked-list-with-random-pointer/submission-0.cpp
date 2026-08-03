class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        unordered_map<Node*, Node*> map;
        Node* cur = head;

        // First pass: copy all nodes and store them in the map
        while (cur) {
            map[cur] = new Node(cur->val);
            cur = cur->next;
        }

        // Second pass: set next and random pointers
        cur = head;
        while (cur) {
            map[cur]->next = map[cur->next];
            map[cur]->random = map[cur->random];
            cur = cur->next;
        }

        return map[head];
    }
};

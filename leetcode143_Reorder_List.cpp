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
    void reorderList(ListNode* head) {
        /*
        TC : O(N)
        SC : O(n)
        */
        ListNode* pre = new ListNode(0);
        vector<ListNode*> nodes;
        
        while(head){
            nodes.push_back(head);
            head = head->next;
        }
        
        for(int i = 0;i < (nodes.size() + 1) / 2;i++){
            pre->next = nodes[i];
            nodes[i]->next = nodes[nodes.size() - i - 1];
            pre = nodes[nodes.size() - i - 1];
        }
        pre->next = nullptr;
    }
};
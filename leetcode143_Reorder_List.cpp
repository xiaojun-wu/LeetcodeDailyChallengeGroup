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
        SC : O(1)
        reverse the last half part and merge with the first half.
        */
        if(head->next == nullptr)
            return;
        int len = 0;
        ListNode* cur = head, *pre = new ListNode(0), *temp = nullptr;
        ListNode* first = head, *second = nullptr;
        // count length of nodes.
        while(cur){
            len++;
            cur = cur->next;
        }
        // find the first node of last half.
        cur = head;
        for(int i = 0;i < (len + 1) / 2;i++)
            cur = cur->next;
        pre->next = cur;
        // reverse the last half part.
        while(cur->next){
            temp = cur->next;
            cur->next = temp->next;
            temp->next = pre->next;
            pre->next = temp;
        }
        second = pre->next;
        // merge the first half and last half part.
        while(first && second){
            ListNode* first_next = first->next, *second_next = second->next;
            first->next = second;
            second->next = first_next;
            first = first_next;
            second = second_next;
        }
        if(first != nullptr)
            first->next = nullptr;
    }
};
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        /*
        get length of linklist, and reverse each k nodes.
        TC : O(N)
        SC : O(1)
        */
        ListNode* prehead = new ListNode(0), *cur = head, *pre = prehead, *temp = nullptr;
        int len = 0;
        while(cur){
            len++;
            cur = cur->next;
        }
        
        cur = head;
        prehead->next = head;
        
        while(len >= k){
            for(int i = 0;i < k - 1;i++){
                temp = cur->next;
                cur->next = temp->next;
                temp->next = pre->next;
                pre->next = temp;
            }
            pre = cur;
            cur = cur->next;
            len-= k;
        }
        
        return prehead->next;
    }
};
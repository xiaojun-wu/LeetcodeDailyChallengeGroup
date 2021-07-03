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
        /*
        priority_queue
        TC : O(N logN)
        SC : O(N)
        */
        const int SIZE = lists.size();
        ListNode* pre = new ListNode(0), *cur = pre;
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> pq;
        
        for(int i = 0;i < SIZE;i++)
            if(lists[i] != nullptr)
                pq.emplace(lists[i]->val,lists[i]);
        
        while(!pq.empty()){
            auto[val,node] = pq.top();
            pq.pop();
            cur->next = node;
            if(node->next)
                pq.emplace(node->next->val,node->next);
            cur = cur->next;
        }
        
        return pre->next;
    }
};
// https://tinyurl.com/3p8kvnjt
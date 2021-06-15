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
    vector<int> nextLargerNodes(ListNode* head) {
        /*
        decreasing monotonic stack.
        TC:O(N), SC:O(N)
        */
        vector<int> res;
        vector<pair<int,int>> stack;
        int idx = 0;
        
        while(head){
            res.push_back(0);
            while(!stack.empty() && head->val > stack.back().second){
                res[stack.back().first] = head->val;
                stack.pop_back();
            }
            stack.emplace_back(idx++,head->val);
            head = head->next;
        }
        
        return res;
    }
};
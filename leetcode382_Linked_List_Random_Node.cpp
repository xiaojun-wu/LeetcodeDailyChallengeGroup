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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this->head = head;
        srand(time(NULL));
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        /*
        each 100 nodes belong to a interval, and we choose one from each intervals to represent the interval.
        Since the last interval maynot enough 100 nodes, we have to choose interval by (rand() % len) / 100 to make sure the interval with less nodes has less possible be chosen than interval with more nodes.
        */
        ListNode *cur = head;
        int len = 0;
        while(cur){
            int idx = 0;
            for(;cur && idx < 100;idx++){
                temp[idx] = cur->val;
                cur = cur->next;
                len++;
            }
            int pick = rand() % idx;
            candidates[(len - 1) / 100] = temp[pick];
        }
        int pick = (rand() % len) / 100;
        return candidates[pick];
    }
private:
    ListNode *head;
    int candidates[100] = {0}, temp[100] = {0};
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
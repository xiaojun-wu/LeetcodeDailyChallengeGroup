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
        merge with recursion
        merge half of lists in given range [left,right]
        if left == right, return lists[left].
        if left + 1 == right, merge lists[left] and lists[right] and return.
        otherwise, keep splite lists.
        
        TC : O(K * N * logK)
        SC : O(log K)
        */
        const int SIZE = lists.size();
        if(SIZE == 0)
            return nullptr;

        function<ListNode*(int,int)> spliteLists = [&](int left,int right) ->ListNode*{
            if(left == right)
                return lists[left];
            int mid = left + (right - left) / 2;
            ListNode *l1 = nullptr, *l2 = nullptr;
            if(mid - left <= 1){
                if(mid - left == 0) l1 = lists[left];
                else l1 = mergetTwoLists(lists[left],lists[left + 1]);
            }
            else
                l1 = spliteLists(left,mid);
            if(right - mid - 1 <= 1){
                if(right - mid - 1 == 0) l2 = lists[right];
                else l2 = mergetTwoLists(lists[mid + 1],lists[right]);
            }
            else
                l2 = spliteLists(mid + 1,right);
            return mergetTwoLists(l1,l2);
        };

        return spliteLists(0,SIZE - 1);
    }
    ListNode* mergetTwoLists(ListNode* l1,ListNode* l2){
        if(l1 == nullptr || l2 == nullptr){
            return l1 == nullptr?l2:l1;
        }
        ListNode* pre = new ListNode(0), *cur = pre;
        while(l1 && l2){
            if(l1->val > l2->val)
                swap(l1,l2);
            cur->next = l1;
            cur = cur->next;
            l1 = l1->next;
        }
        cur->next = l2;
        return pre->next;
    }
};

// https://tinyurl.com/3p8kvnjt
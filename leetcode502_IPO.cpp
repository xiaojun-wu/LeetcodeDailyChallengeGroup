class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        // heap + sort, TC: O(N log N), SC : O(N)
        const int SIZE = profits.size();
        vector<pair<int,int>> arrs;
        priority_queue<int> pq;
        int res = 0, idx = 0;
        
        for(int i = 0;i < SIZE;i++)
            arrs.emplace_back(capital[i],profits[i]);
        
        sort(arrs.begin(),arrs.end());
        
        while(k > 0){
            while(idx < SIZE && arrs[idx].first <= w)
                pq.emplace(arrs[idx++].second);
            if(!pq.empty()){
                w+= pq.top();
                pq.pop();
                k--;
            }
            if(pq.empty() && (idx == SIZE || arrs[idx].first > w))
                break;
        }
        
        return w;
    }
};
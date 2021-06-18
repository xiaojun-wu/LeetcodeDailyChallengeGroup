class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        const int SIZE = restaurants.size();
        vector<int> res;
        priority_queue<pair<int,int>> pq;
        
        for(vector<int>& r : restaurants){
            if(veganFriendly && r[2] == 0) continue;
            if(r[3] > maxPrice || r[4] > maxDistance) continue;
            pq.push(make_pair(r[1],r[0]));
        }
        
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        return res;
    }
};
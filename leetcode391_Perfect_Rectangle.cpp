class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        set<pair<int,int>> heap;
        long long area = 0;
        
        for(vector<int>& r : rectangles){
            vector<pair<int,int>> ps;
            ps.emplace_back(r[0],r[1]);// bottom-left
            ps.emplace_back(r[0],r[3]);// top-left
            ps.emplace_back(r[2],r[1]);// bottom-right
            ps.emplace_back(r[2],r[3]);// top-right
            for(auto &p : ps){
                auto it = heap.insert(p);
                if(!it.second)
                    heap.erase(it.first);
            }
            area+= (ps[3].first - ps[0].first) * (ps[3].second - ps[0].second);
        }
        if(heap.size() != 4)
            return false;
        auto p1 = *(heap.begin());
        auto p2 = *(heap.rbegin());
        return area == (p2.first - p1.first) * (p2.second - p1.second);
    }
};
// https://tinyurl.com/uhd6da95
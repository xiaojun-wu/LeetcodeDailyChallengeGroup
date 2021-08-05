class Solution {
public:
    Solution(vector<vector<int>>& rects) {
        totalWeights = 0;
        this->itr = rects.begin();
        for(vector<int>& rect : rects){
            int area = (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1);
            totalWeights+= area;
            weights.push_back(totalWeights);
        }
    }
    
    vector<int> pick() {
        int weight = rand() % totalWeights + 1;
        int idx = lower_bound(weights.begin(),weights.end(),weight) - weights.begin();
        auto nitr = itr + idx;
        int width = (*nitr)[2] - (*nitr)[0], length = (*nitr)[3] - (*nitr)[1];
        int w = rand() % (width + 1), l = rand() % (length + 1);
        return {(*nitr)[0] + w,(*nitr)[1] + l};
    }
private:
    int totalWeights;
    vector<int> weights;
    vector<vector<int>>::iterator itr;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */

 // https://tinyurl.com/ah6aee44
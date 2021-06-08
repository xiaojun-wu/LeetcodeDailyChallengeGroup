class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        /*
        greedy + heap.
        TC: O(M * N * K), SC: (K)
        */
        const int ROW = mat.size(), COL = mat[0].size();
        multiset<int> heap;
        
        for(int i = 0;i < COL && heap.size() < k;i++)
            heap.insert(mat[0][i]);
        
        for(int r = 1;r < ROW;r++){
            multiset<int> next;
            for(int c = 0;c < COL;c++)
                for(auto it = heap.begin();it != heap.end();it++){
                    next.insert(mat[r][c] + *it);
                    if(next.size() > k)
                        next.erase(prev(next.end()));
                }
            swap(next,heap);
        }
        
        return *prev(heap.end());
    }
};

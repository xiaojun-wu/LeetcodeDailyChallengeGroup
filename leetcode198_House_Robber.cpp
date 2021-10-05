class Solution {
public:
    int rob(vector<int>& nums) {
        const int SIZE = nums.size();
        int a = 0, b = 0;
        
        for(int n : nums){
            b = max(a,b);
            a+= n;
            swap(a,b);
        }
        
        return max(a,b);
    }
};
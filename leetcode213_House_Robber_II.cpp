class Solution {
public:
    int rob(vector<int>& nums) {
        const int SIZE = nums.size();
        if(SIZE == 1)
            return nums[0];
        function<int(int,int)> helper = [&](int start,int end) ->int {
            int a = 0,b = 0;
            while(start < end){
                b = max(a,b);
                a+= nums[start++];
                swap(a,b);
            }
            return max(a,b);
        };
        
        return max(helper(0,SIZE - 1),helper(1,SIZE));
    }
};
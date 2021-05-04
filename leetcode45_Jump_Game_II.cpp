class Solution {
public:
    int jump(vector<int>& nums) {
        const int SIZE = nums.size();
        if(SIZE == 1)
            return 0;
        int start = 0, end = 0, step = 0;
        while(true){
            int nextEnd = end;
            for(int i = start;i <= end;i++){
                if(nums[i] + i >= SIZE- 1)
                    return step + 1;
                nextEnd = max(nextEnd,nums[i] + i);
            }
            start = end + 1;
            end = nextEnd;
            step++;
        }
        
        return -1;
    }
};
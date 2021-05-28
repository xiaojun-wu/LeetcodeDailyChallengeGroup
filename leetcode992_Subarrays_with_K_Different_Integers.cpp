class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        const int SIZE = nums.size();
        
        function<int(int)> getLessEquals = [&](int n) ->int {
            vector<int> freq(SIZE + 1,0);
            int res = 0, count = 0;
            for(int l = 0,r = 0;r < SIZE;r++){
                if(freq[nums[r]] == 0)
                    count++;
                freq[nums[r]]++;
                while(count > n){
                    freq[nums[l]]--;
                    if(freq[nums[l++]] == 0)
                        count--;
                }
                res+= r - l + 1;
            }
            return res;
        };
        
        return getLessEquals(k) - getLessEquals(k - 1);
    }
};
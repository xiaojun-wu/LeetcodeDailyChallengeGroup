class Solution {
public:
    bool judgeSquareSum(int c) {
        unordered_set<int> nums;
        for(int i = 0;i <= 46340 && i * i <= c;i++){
            nums.insert(i * i);
        }
        for(auto it = nums.begin();it != nums.end();it++){
            if(nums.count(c - *it)) return true;
        }

        return false;
    }
};
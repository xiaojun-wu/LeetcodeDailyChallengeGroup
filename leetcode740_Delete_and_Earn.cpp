class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        const int SIZE = nums.size();
        vector<pair<int,int>> arr;
        sort(nums.begin(),nums.end());
        int res = 0;
        
        for(int i = 0;i < SIZE;i++){
            int val = nums[i], idx = i;
            while(i < SIZE && nums[i] == val) i++;
            arr.emplace_back(val,i - idx);
            i--;
        }
        
        int pre = arr[0].first * arr[0].second, prepre = 0;
        
        for(int i = 1;i < arr.size();i++){
            int val = arr[i].first * arr[i].second;
            if(arr[i - 1].first == arr[i].first - 1)
                val+= prepre;
            else
                val+= pre;
            prepre = pre;
            pre = max(val,pre);
        }
        
        return pre;
    }
};
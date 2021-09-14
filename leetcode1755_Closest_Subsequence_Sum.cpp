class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        const int SIZE = nums.size(), HALF = SIZE / 2, FIRSTTOTAL = 1 << HALF;
        const int SECONDTOTAL = 1 << (SIZE - HALF);
        vector<int> values1(FIRSTTOTAL), values2(SECONDTOTAL);
        int res = INT_MAX;
        
        function<void(vector<int>&,int,int)> getSums = [&](vector<int>& arr,int offset,int size) {
            for(int i = 0; i < size; ++i)
                for(int j = 0; j < (1 << i); ++j)
                    arr[j + (1 << i)] = arr[j] + nums[i + offset];
        };
        
        getSums(values1,0,HALF);
        getSums(values2,HALF,SIZE - HALF);
        
        sort(values1.begin(),values1.end());
        sort(values2.rbegin(),values2.rend());
        
        int i = 0,j = 0;
        while(i < values1.size() && j < values2.size()){
            int temp = values1[i] + values2[j];
            res = min(res,abs(goal - temp));
            if(temp > goal) j++;
            else if(temp < goal) i++;
            else return 0;
        }
        
        return res;
    }
};

// https://tinyurl.com/8vpcxxhc
class NumArray {
public:
    NumArray(vector<int>& nums) {
        presum = vector<int>(1,0);
        
        for(int n : nums)
            presum.push_back(presum.back() + n);
    }
    
    int sumRange(int left, int right) {
        return presum[right + 1] - presum[left];
    }
private:
    vector<int> presum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
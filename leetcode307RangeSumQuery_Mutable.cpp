class NumArray {
public:
    NumArray(vector<int>& nums) {
        arr = vector<int>(nums.size() + 1,0);
        ptr = nums.data();
        for(int i = 0;i < nums.size();i++)
            for(int idx = i + 1;idx < arr.size();idx+= lowbit(idx))
                arr[idx]+= nums[i];
    }
    
    void update(int index, int val) {
        int diff = val - ptr[index];
        ptr[index]+= diff;
        for(int idx = index + 1;idx < arr.size();idx+= lowbit(idx))
            arr[idx]+= diff;
    }
    
    int sumRange(int left, int right) {
        return presum(right + 1) - presum(left);
    }
private:
    vector<int> arr;
    int *ptr;
    int lowbit(int n){
        return n & -n;
    }
    int presum(int idx){
        int sum = 0;
        while(idx > 0){
            sum+= arr[idx];
            idx-= lowbit(idx);
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
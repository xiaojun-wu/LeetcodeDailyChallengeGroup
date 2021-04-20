class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res(nums.size(),0);
        
        for(int i = nums.size() - 1;i >= 0;i--){
            res[i] = query(nums[i] - 1);
            update(nums[i]);
        }
        
        return res;
    }
private:
    static const int SIZE = 20002;
    int arr[SIZE] = {0};
    int lowbit(int n){
        return n & -n;
    }
    void update(int idx){
        for(int i = idx + 10001;i < SIZE;i+= lowbit(i))
            arr[i]++;
    }
    int query(int idx){
        int sum = 0;
        for(int i = idx + 10001;i > 0;i-= lowbit(i))
            sum+= arr[i];
        return sum;
    }
};
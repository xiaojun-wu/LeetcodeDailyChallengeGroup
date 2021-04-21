class Solution {
public:
    int createSortedArray(vector<int>& instructions) {
        const int SIZE = instructions.size(), MOD = 1e9 + 7;
        int maxVal = *max_element(instructions.begin(),instructions.end());
        arr = vector<int>(maxVal + 1,0);
        int res = 0,count = 0;
        unordered_map<int,int> mp;
        
        for(int n : instructions){
            int amount = query(n);
            res = (res + min(amount - mp[n],count - amount)) % MOD;
            mp[n]++;
            count++;
            update(n);
        }
        
        return res;
    }
private:
    vector<int> arr;
    int lowbit(int n){
        return n & -n;
    }
    void update(int n){
        while(n < arr.size()){
            arr[n]++;
            n+= lowbit(n);
        }
    }
    int query(int n){
        int sum = 0;
        while(n > 0){
            sum+= arr[n];
            n-= lowbit(n);
        }
        return sum;
    }
};
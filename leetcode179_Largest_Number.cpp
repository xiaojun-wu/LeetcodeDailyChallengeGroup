class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // sort
        vector<string> arr;
        for(int n : nums)
            arr.push_back(to_string(n));
        sort(arr.begin(),arr.end(),[](auto& lhs,auto& rhs){
            string s1 = lhs + rhs, s2 = rhs + lhs;
            return s1 > s2;
        });
        
        string res;
        for(string& n : arr)
            res+=n;
        
        return res[0]=='0'?"0":res;
    }
};
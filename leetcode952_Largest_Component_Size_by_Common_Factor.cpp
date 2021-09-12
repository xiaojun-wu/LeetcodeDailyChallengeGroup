class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        const int SIZE = nums.size();
        unordered_set<int> factors;
        DSU dsu = DSU(*max_element(nums.begin(),nums.end()));
        int res = 1;
        
        for(int n : nums)
            dsu.add(n);
        
        for(int n : nums){
            int rest = n;
            
            if(rest % 2 == 0){
                dsu.unionNodes(2,n);
                factors.insert(2);
                while(rest % 2 == 0)
                    rest/= 2;
            }
            
            for(int i = 3;i <= sqrt(rest);i+= 2){
                if(rest % i == 0){
                    dsu.unionNodes(i,n);
                    factors.insert(i);
                    while(rest % i == 0)
                        rest/= i;
                }
            }
            
            if(rest > 2){
                factors.insert(rest);
                dsu.unionNodes(rest,n);
            }
        }
        
        for(int factor : factors)
            res = max(res,dsu.getSize(factor));
        
        return res;
    }
private:
    class DSU{
        public:
        DSU(int n){
            parents = vector<int>(n + 1,0);
            for(int i = 0;i <= n;i++)
                parents[i] = i;
            size = vector<int>(n + 1,0);
        }
        int find(int n){
            while(n != parents[n]){
                parents[n] = parents[parents[n]];
                n = parents[n];
            }
            return n;
        }
        void add(int n){
            size[n]++;
        }
        int getSize(int n){
            return size[n];
        }
        void unionNodes(int a,int b){
            int rootA = find(a), rootB = find(b);
            if(rootA == rootB)
                return;
            parents[rootB] = rootA;
            size[rootA]+= size[rootB];
            return;
        }
        private:
        vector<int> parents;
        vector<int> size;
    };
};

// https://tinyurl.com/25z2epw5
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(),deadends.end());
        unordered_set<string> visited;
        vector<char> pre = {'9','0','1','2','3','4','5','6','7','8'};
        vector<char> next = {'1','2','3','4','5','6','7','8','9','0'};
        int res = 0;
        string s = "0000";
        if(dead.count(s))
            return -1;
        if(s == target)
            return 0;
        deque<string> q;
        visited.insert(s);
        q.push_back(s);
        
        while(!q.empty()){
            for(int i = q.size();i > 0;i--){
                string state = q.front();
                q.pop_front();
                for(int j = 0;j < 4;j++){
                    state[j] = pre[state[j] - '0'];
                    if(state == target)
                        return res + 1;
                    if(!dead.count(state) && visited.insert(state).second)
                        q.push_back(state);
                    state[j] = next[next[state[j] - '0'] - '0'];
                    if(state == target)
                        return res + 1;
                    if(!dead.count(state) && visited.insert(state).second)
                        q.push_back(state);
                    state[j] = pre[state[j] - '0'];
                }
            }
            res++;
        }
        
        return -1;
    }
};

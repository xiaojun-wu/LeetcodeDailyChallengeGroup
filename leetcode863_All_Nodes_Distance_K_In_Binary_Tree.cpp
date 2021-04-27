/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        //graph + bfs
        vector<vector<int>> adjacents(501,vector<int>());
        deque<pair<int,int>> q;
        vector<int> res;
        // build adjacent list.
        function<void(TreeNode*,int)> dfs = [&](TreeNode* node,int parent) {
            if(node == nullptr)
                return;
            if(node->val != parent)
                adjacents[node->val].push_back(parent);
            if(node->left)
                adjacents[node->val].push_back(node->left->val);
            if(node->right)
                adjacents[node->val].push_back(node->right->val);
            dfs(node->left,node->val);
            dfs(node->right,node->val);
        };
        
        dfs(root,root->val);
        q.emplace_back(target->val,target->val);
        
        //bfs
        for(int i = 0;i < K && !q.empty();i++){
            for(int j = q.size();j > 0;j--){
                auto[cur,parent] = q.front();
                q.pop_front();
                for(int nei : adjacents[cur]){
                    if(nei == parent) continue;
                    q.emplace_back(nei,cur);
                }
            }
        }
        
        while(!q.empty()){
            res.push_back(q.front().first);
            q.pop_front();
        }
        
        return res;
    }
};
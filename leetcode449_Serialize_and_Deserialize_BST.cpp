/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr)
            return "";
        string code = "";
        function<void(TreeNode*)> dfs = [&](TreeNode* node) {
            if(node == nullptr)
                return;
            code+= to_string(node->val) + ',';
            dfs(node->left);
            dfs(node->right);
        };
        
        dfs(root);
        
        return code;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty())
            return nullptr;
        vector<int> vals;
        int idx = 0;
        
        for(int i = 0;i < data.length();i++){
            int common = data.find(',',i);
            if(common == string::npos)
                common = data.length();
            vals.push_back(stoi(data.substr(i,common - i)));
            i = common;
        }
        
        function<TreeNode*(int,int)> dfs = [&](int left,int right) ->TreeNode* {
            if(idx == vals.size() || vals[idx] < left || vals[idx] > right)
                return nullptr;
            TreeNode* node = new TreeNode(vals[idx++]);
            node->left = dfs(left,node->val);
            node->right = dfs(node->val,right);
            return node;
        };
        
        return dfs(0,1e4);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;

// https://tinyurl.com/hzc767d8
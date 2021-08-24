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
        deque<TreeNode*> q;
        q.push_back(root);
        
        while(!q.empty()){
            for(int i = q.size();i > 0;i--){
                auto node = q.front();
                q.pop_front();
                if(node == nullptr)
                    code+= "null,";
                else{
                    code+= to_string(node->val) + ',';
                    q.push_back(node->left);
                    q.push_back(node->right);
                }
            }
        }
        
        return code;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty())
            return nullptr;
        vector<string> nodevals;
        deque<TreeNode*> q;
        int idx = 0;
        
        for(int i = 0;i < data.length();i++){
            int common = data.find(',',i);
            if(common == string::npos)
                common = data.length();
            nodevals.push_back(data.substr(i,common - i));
            i = common;
        }
        
        TreeNode* root = new TreeNode(stoi(nodevals[idx++]));
        q.push_back(root);
        
        while(!q.empty()){
            for(int i = q.size();i > 0;i--){
                auto node = q.front();
                q.pop_front();
                if(nodevals[idx] != "null"){
                    node->left = new TreeNode(stoi(nodevals[idx]));
                    q.push_back(node->left);
                }
                idx++;
                if(nodevals[idx] != "null"){
                    node->right = new TreeNode(stoi(nodevals[idx]));
                    q.push_back(node->right);
                }
                idx++;
            }
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
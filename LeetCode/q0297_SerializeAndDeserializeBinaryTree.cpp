#define ll long long
#define INF 20000
#define DIV 256

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
        vector<short> v;
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* cur = q.front(); q.pop();
            if(cur == NULL) {
                v.push_back(INF);
                continue;
            }
            v.push_back(cur->val);
            q.push(cur->left);
            q.push(cur->right);
        }
        
        
        string s(v.size() * 2, '0');
        
        short * ptr = (short *) &s[0];
        for(ll i = 0; i < v.size(); i++) {
            *ptr = v[i];
            ptr++;
        }
        
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string _data) {
        queue<TreeNode*> q;
        ll N = _data.size() / 2;
        short * data = (short *) &_data[0];
        ll didx = 0;
        TreeNode* root = NULL;
        if(data[didx] != INF) {
            root =  new TreeNode(data[didx]);
            q.push(root);
            didx++;
        }
        
        while(!q.empty()) {
            TreeNode* cur = q.front(); q.pop();
            short lval = data[didx++];
            short rval = data[didx++];
            if(lval != INF) {
                cur->left = new TreeNode(lval);
                q.push(cur->left);
            }
            if(rval != INF) {
                cur->right = new TreeNode(rval);
                q.push(cur->right);
            }
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
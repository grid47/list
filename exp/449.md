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
        string str;
        serial(str, root);
        return str;
    }
    
    void serial(string& ss, TreeNode* root) {
        if (!root) return;
        char c[4];
        memcpy(c, &(root->val), sizeof(int));
        for (int i = 0; i < 4; i++) ss.push_back(c[i]);
        serial(ss, root->left );
        serial(ss, root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int pos = 0;
        return deserial(data, pos, INT_MIN, INT_MAX);
    }
    
    TreeNode* deserial(string& data, int& pos, int left, int right) {
        if (pos >= data.size()) return NULL;

        int val;
        memcpy(&val, &(data[pos]), sizeof(int));
        if (val < left || val > right) return NULL;

        TreeNode* root = new TreeNode(val);
        pos += sizeof(int);
        root->left  = deserial ( data, pos, left,   val );
        root->right = deserial ( data, pos,  val, right );
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
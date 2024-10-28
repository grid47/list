/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    vector<int> arr;
public:
    TreeNode* balanceBST(TreeNode* root) {
        inorder (root);
        return reform(0, arr.size()-1);
    }
    
    void inorder (TreeNode* root) {
        if(root == NULL ) return;
        inorder (root->left);
        arr.push_back(root->val);
        inorder (root->right);
    }
    
 TreeNode* reform(int l, int r) {
        if (l > r) return NULL;
     int mid = (l + r)/2;
     TreeNode* node = new TreeNode(arr[mid]);
     node->left = reform (l, mid -1);
     node->right= reform (mid +1, r);
     return node;
    }
};
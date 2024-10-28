
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 95: Unique Binary Search Trees II"
date = "2024-07-26"
description = "Solution to Leetcode 95"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/unique-binary-search-trees-ii/description/)

---

**Code:**

{{< highlight cpp >}}
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
public:
    vector<TreeNode*> run(int l, int r) {
        vector<TreeNode*> ans, left, right;
        if(l >= r) {
            if(l == r) ans.push_back(new TreeNode(l));
            else ans.push_back(NULL);
            return ans;
        }
        for(int i = l; i <= r; i++) {
            left = run(l, i - 1);
            right= run(i + 1, r);
            
            for(int j = 0; j < left.size(); j++) {
                for(int k = 0; k < right.size(); k++) {
                    TreeNode* node = new TreeNode(i);
                    node->left = left[j];
                    node->right = right[k];
                    ans.push_back(node);
                }
            }
        }
        return ans;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        /*
        
        This is a small light weight problem
        my mind is not ready to think about this problem
        
        bst is sorted array
        we can fix a root and get a 
        array of left trees
        and array of right trees
        integrate them then add to result
        
        */        
        vector<TreeNode*> ans, left, right;
        
        for(int i = 1; i <= n; i++) {
            left = run(1, i - 1);
            right= run(i + 1, n);
            
            for(int j = 0; j < left.size(); j++) {
                for(int k = 0; k < right.size(); k++) {
                    TreeNode* node = new TreeNode(i);
                    node->left = left[j];
                    node->right = right[k];
                    ans.push_back(node);
                }
            }
        }
        return ans;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


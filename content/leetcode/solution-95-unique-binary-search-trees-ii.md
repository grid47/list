
+++
authors = ["grid47"]
title = "Leetcode 95: Unique Binary Search Trees II"
date = "2024-10-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 95: Unique Binary Search Trees II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Dynamic Programming","Backtracking","Tree","Binary Search Tree","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/unique-binary-search-trees-ii/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/95.webp" 
    alt="A sequence of elegant trees gently forming in various, unique shapes."
    caption="Solution to LeetCode 95: Unique Binary Search Trees II Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/95.md" >}}
---
{{< youtube m907FlQa2Yc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #97: Interleaving String](https://grid47.xyz/leetcode/solution-97-interleaving-string/) |
| --- |

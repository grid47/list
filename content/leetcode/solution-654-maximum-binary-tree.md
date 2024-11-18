
+++
authors = ["grid47"]
title = "Leetcode 654: Maximum Binary Tree"
date = "2024-09-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 654: Maximum Binary Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Divide and Conquer","Stack","Tree","Monotonic Stack","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-binary-tree/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/654.webp" 
    alt="A binary tree where the maximum value node is highlighted, glowing softly as it’s determined."
    caption="Solution to LeetCode 654: Maximum Binary Tree Problem"
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        vector<TreeNode*> stk;
        
        for(int num : nums) {
            
            TreeNode* cur = new TreeNode(num);
            
            while(!stk.empty() && stk.back()->val < num) {
                cur->left = stk.back();
                stk.pop_back();
            }
            
            if(!stk.empty()) stk.back()->right = cur;
            
            stk.push_back(cur);
            
        }
        
        return stk.front();
        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/654.md" >}}
---
{{< youtube zvBxnudTZmw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #655: Print Binary Tree](https://grid47.xyz/leetcode/solution-655-print-binary-tree/) |
| --- |

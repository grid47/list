
+++
authors = ["grid47"]
title = "Leetcode 111: Minimum Depth of Binary Tree"
date = "2024-10-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 111: Minimum Depth of Binary Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Breadth-First Search","Binary Tree"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-depth-of-binary-tree/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/111.webp" 
    alt="A deep tree with soft, glowing light reaching the minimal depth, highlighting the shortest path."
    caption="Solution to LeetCode 111: Minimum Depth of Binary Tree Problem"
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
    int minDepth(TreeNode* root) {
        
        if(root == NULL) return 0;
        
        int l = minDepth(root->left);
        int r = minDepth(root->right);
        
        if(root->left && root->right) {
            return 1 + ((l < r)? l: r);            
        }
        
        if(root->left) {
            return 1 + l;                        
        }

        return 1 + r;                        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/111.md" >}}
---
{{< youtube Ukbbnzxmd8o >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #113: Path Sum II](https://grid47.xyz/posts/leetcode-113-path-sum-ii-solution/) |
| --- |


+++
authors = ["grid47"]
title = "Leetcode 114: Flatten Binary Tree to Linked List"
date = "2024-10-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 114: Flatten Binary Tree to Linked List in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Linked List","Stack","Tree","Depth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/114.webp"
youtube = "rKnD7rLT0lI"
youtube_upload_date="2021-09-16"
youtube_thumbnail="https://i.ytimg.com/vi/rKnD7rLT0lI/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/114.webp" 
    alt="A soft tree smoothly transforming into a linear, glowing list of nodes, symbolizing a flattened structure."
    caption="Solution to LeetCode 114: Flatten Binary Tree to Linked List Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    void flatten(TreeNode* root) {

        if( root == NULL) return;

        TreeNode* tmp = root->right;
        root->right = root->left;
        root->left = nullptr;

        TreeNode* node = root;
        while(node->right) node = node->right;

        node->right = tmp;
        flatten(root->right); 

    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/114.md" >}}
---
{{< youtube rKnD7rLT0lI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #116: Populating Next Right Pointers in Each Node](https://grid47.xyz/leetcode/solution-116-populating-next-right-pointers-in-each-node/) |
| --- |
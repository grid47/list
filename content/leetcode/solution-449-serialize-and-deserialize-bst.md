
+++
authors = ["grid47"]
title = "Leetcode 449: Serialize and Deserialize BST"
date = "2024-09-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 449: Serialize and Deserialize BST in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Tree","Depth-First Search","Breadth-First Search","Design","Binary Search Tree","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = ""
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/449.webp"
+++



[`Problem Link`](https://leetcode.com/problems/serialize-and-deserialize-bst/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/449.webp" 
    alt="A binary search tree being serialized and deserialized, with each node softly glowing during the transformation."
    caption="Solution to LeetCode 449: Serialize and Deserialize BST Problem"
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
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/449.md" >}}
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #451: Sort Characters By Frequency](https://grid47.xyz/leetcode/solution-451-sort-characters-by-frequency/) |
| --- |

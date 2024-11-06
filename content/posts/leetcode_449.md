
+++
authors = ["Crafted by Me"]
title = "Leetcode 449: Serialize and Deserialize BST"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 449: Serialize and Deserialize BST in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Tree","Depth-First Search","Breadth-First Search","Design","Binary Search Tree","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/serialize-and-deserialize-bst/description/)

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

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #450: Delete Node in a BST](https://grid47.xyz/posts/leetcode_450) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}
Coupen: {{< clip "coupen" >}}

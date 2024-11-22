
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
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/449.webp"
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
+++


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
---

### Problem Statement

In this problem, you are tasked with implementing a codec for a binary search tree (BST). Specifically, you need to:

1. **Serialize a binary search tree** into a string, such that the tree structure and its values are preserved in a way that can be stored or transmitted.
2. **Deserialize the string back into a binary search tree** so that the original structure and values are reconstructed correctly.

A **binary search tree (BST)** is a binary tree where for every node, all the values in the left subtree are smaller, and all the values in the right subtree are larger. This property makes it easier to perform certain operations like searching and inserting nodes.

The goal of this problem is to create efficient methods to:
- Convert a tree to a string format (`serialize` method).
- Convert the string back to the original tree structure (`deserialize` method).

### Approach

To solve this problem, we need to take two major steps:
1. **Serialization (Tree to String)**:
   - We will traverse the tree using **pre-order traversal** (root, left, right) and store the node values in a string. The idea is to serialize the tree structure into a flat string that retains the values and their relationships.
   - During serialization, we need to ensure that we capture the values in a fixed format. The values are stored using their raw byte representation (as integers).
   
2. **Deserialization (String to Tree)**:
   - The serialized string contains the values of the tree nodes in a sequence, so we need to process this string in a way that re-constructs the tree. 
   - As we deserialize, we need to maintain the correct bounds for each node’s value. This can be done by passing the `left` and `right` bounds for each node during the recursive calls. The bounds will ensure that the left child is smaller than the node value, and the right child is larger.
   - The recursive function will build the tree by checking if the current value falls within the valid bounds.

### Code Breakdown (Step by Step)

#### 1. **Serialize Method**

```cpp
string serialize(TreeNode* root) {
    string str;
    serial(str, root);
    return str;
}
```

- The `serialize` method initializes an empty string `str` and calls the helper function `serial` to populate the string with the tree’s node values.
- The function `serial` is a **recursive function** that traverses the tree and appends the values of nodes in a pre-order fashion. It ensures that the tree is properly serialized in the string.

#### 2. **Helper Method for Serialization: `serial`**

```cpp
void serial(string& ss, TreeNode* root) {
    if (!root) return;
    char c[4];
    memcpy(c, &(root->val), sizeof(int));
    for (int i = 0; i < 4; i++) ss.push_back(c[i]);
    serial(ss, root->left );
    serial(ss, root->right);
}
```

- The `serial` method handles the actual tree traversal and string construction.
- If the `root` is `NULL`, it returns immediately (base case).
- For non-null nodes, the function serializes the node’s value into a byte array (`c[4]`) using `memcpy`. It then appends these bytes to the `ss` string. Each node's value is stored as 4 bytes (since an integer is typically 4 bytes).
- After appending the node's value, the function recursively calls itself to serialize the left and right children of the current node.

#### 3. **Deserialize Method**

```cpp
TreeNode* deserialize(string data) {
    int pos = 0;
    return deserial(data, pos, INT_MIN, INT_MAX);
}
```

- The `deserialize` method initializes a position `pos` and calls the recursive helper method `deserial` to reconstruct the tree. The bounds (`INT_MIN` and `INT_MAX`) are initially passed to ensure that the root value is within the valid range.
  
#### 4. **Helper Method for Deserialization: `deserial`**

```cpp
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
```

- The `deserial` method processes the string `data` to reconstruct the tree recursively.
- We start by checking if we have reached the end of the string (`pos >= data.size()`). If so, it means there are no more nodes to process.
- Using `memcpy`, we extract a 4-byte integer value (`val`) from the string starting at the current position (`pos`).
- If the value of the node is outside the allowed bounds (`left` and `right`), we return `NULL` (invalid subtree).
- A new `TreeNode` is created with the extracted value.
- We increment the position pointer `pos` and recursively call the `deserial` method to reconstruct the left and right subtrees. The bounds for the left and right children are updated based on the node value (`left, val` for the left subtree and `val, right` for the right subtree).
- Finally, the root of the current subtree is returned.

### Complexity

#### Time Complexity:
- **Serialization**: The `serialize` function performs a pre-order traversal of the tree. In the worst case, every node in the tree is visited once. Therefore, the time complexity of serialization is **O(n)**, where `n` is the number of nodes in the tree.
- **Deserialization**: The `deserialize` function processes the entire string once, with each recursive call corresponding to a node in the tree. The time complexity of deserialization is also **O(n)**, where `n` is the number of nodes.

#### Space Complexity:
- **Serialization**: The space complexity is **O(n)** due to the string used to store the serialized data.
- **Deserialization**: The space complexity is **O(n)** for the recursion stack during the tree reconstruction process.

### Conclusion

The **Codec** class efficiently handles the serialization and deserialization of a binary search tree (BST). The key idea behind the implementation is to use **pre-order traversal** to serialize the tree, storing node values as byte arrays, and to recursively reconstruct the tree by maintaining the correct bounds for each node during deserialization.

This solution leverages efficient memory management with `memcpy` to store and extract integer values, ensuring that the tree can be serialized and deserialized in linear time with respect to the number of nodes. The space complexity is kept minimal, and the approach ensures that both operations (serialization and deserialization) are performed efficiently, making it suitable for use in practical scenarios where BSTs need to be stored or transmitted.

[`Link to LeetCode Lab`](https://leetcode.com/problems/serialize-and-deserialize-bst/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

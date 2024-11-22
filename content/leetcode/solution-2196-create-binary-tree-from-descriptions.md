
+++
authors = ["grid47"]
title = "Leetcode 2196: Create Binary Tree From Descriptions"
date = "2024-04-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2196: Create Binary Tree From Descriptions in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Tree","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "yWkrFfqO7NA"
youtube_upload_date="2024-07-15"
youtube_thumbnail="https://i.ytimg.com/vi/yWkrFfqO7NA/maxresdefault.jpg"
+++



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
    TreeNode* createBinaryTree(vector<vector<int>>& desc) {
        set<int> s;
        for(vector<int> v: desc) {
            s.insert(v[0]);
            s.insert(v[1]);
        }

        for(auto v: desc) {
            if(s.find(v[1]) != s.end()) {
                s.erase(v[1]);
            }
        }

        int root = *s.begin();

        // found root
        // next create map for nodes
        // connect them as given in desc

        map<int, TreeNode*> mp;
        for(auto v: desc) {
            if(mp.find(v[0]) == mp.end()) {
                mp[v[0]] = new TreeNode(v[0]);
            }
            if(mp.find(v[1]) == mp.end()) {
                mp[v[1]] = new TreeNode(v[1]);
            }
        }

        for(auto v: desc) {
            int paret = v[0];
            int child = v[1];
            int left  = v[2];

            if(left) mp[paret]->left  = mp[child];
            else     mp[paret]->right = mp[child];
        }

        return mp[root];
    }
};
{{< /highlight >}}
---

### Problem Statement
The problem requires constructing a binary tree based on a set of relationships provided in a 2D vector `desc`. Each element of the vector `desc` represents a relationship between a parent and a child node. The task is to reconstruct the binary tree from these relationships and return the root node of the tree.

Each vector in `desc` contains three integers:
1. The first integer represents the parent node.
2. The second integer represents the child node.
3. The third integer indicates whether the child node is the left or right child of the parent. If the third integer is 1, the child is the left child; otherwise, it is the right child.

### Approach
To construct the binary tree from the given descriptions in `desc`, the following approach is used:

1. **Identify the Root**:
   - The first step is to identify the root node of the tree. The root is the only node that does not appear as a child in any of the relationships. Thus, by iterating over the `desc` list and keeping track of which nodes are children, we can find the root.

2. **Create Nodes**:
   - After identifying the root, we need to create all the nodes of the binary tree. We use a `map` to store the nodes by their values, allowing us to easily access or create a node whenever required.

3. **Build Relationships**:
   - Once all the nodes are created, we can proceed to build the relationships between the nodes as described in `desc`. For each parent-child pair, we assign the left or right child based on the third value in the vector.

4. **Return the Root**:
   - After constructing the binary tree, the root node is returned.

### Code Breakdown (Step by Step)

#### Step 1: Identify the Root Node
```cpp
set<int> s;
for (vector<int> v : desc) {
    s.insert(v[0]);  // Insert parent node
    s.insert(v[1]);  // Insert child node
}
```
- A set `s` is used to keep track of all nodes that are either parents or children. This set will help us identify the root node later, as the root is the only node that does not appear as a child.

```cpp
for (auto v : desc) {
    if (s.find(v[1]) != s.end()) {
        s.erase(v[1]);  // Remove child nodes from the set
    }
}
```
- We iterate over each entry in `desc`. If the child node is already in the set `s`, we remove it, because a node that is a child cannot be the root.

```cpp
int root = *s.begin();  // The remaining element in the set is the root
```
- The remaining element in the set `s` is the root node, as it has never been marked as a child.

#### Step 2: Create the Binary Tree Nodes
```cpp
map<int, TreeNode*> mp;
for (auto v : desc) {
    if (mp.find(v[0]) == mp.end()) {
        mp[v[0]] = new TreeNode(v[0]);  // Create the parent node if not already created
    }
    if (mp.find(v[1]) == mp.end()) {
        mp[v[1]] = new TreeNode(v[1]);  // Create the child node if not already created
    }
}
```
- A `map<int, TreeNode*>` called `mp` is used to store nodes. For each pair of parent-child nodes in `desc`, we check if the parent and child nodes have already been created. If not, we create new nodes for them.

#### Step 3: Build the Parent-Child Relationships
```cpp
for (auto v : desc) {
    int parent = v[0];
    int child = v[1];
    int left = v[2];
    
    if (left) {
        mp[parent]->left = mp[child];  // Set the left child
    } else {
        mp[parent]->right = mp[child];  // Set the right child
    }
}
```
- For each parent-child relationship, we use the `left` value to determine whether to set the child as the left or right child of the parent. This is done by checking if `left` is `1` or `0`. If `left` is `1`, the child is set as the left child; otherwise, the child is set as the right child.

#### Step 4: Return the Root Node
```cpp
return mp[root];
```
- Finally, the function returns the root node from the `map`. Since we already identified the root earlier, it is now available in `mp[root]`.

### Complexity

#### Time Complexity:
- **O(n)**, where `n` is the number of nodes in the tree (i.e., the number of elements in `desc`). This is because:
  - We iterate through `desc` three times:
    - First to identify the root node.
    - Second to create nodes.
    - Third to build the parent-child relationships.
  - Each of these operations is linear with respect to the number of nodes.

#### Space Complexity:
- **O(n)**, where `n` is the number of nodes in the tree. This space is used to store:
  - The set `s`, which contains at most `n` nodes.
  - The map `mp`, which also stores `n` nodes.

### Conclusion
This solution constructs a binary tree based on a list of parent-child relationships described by the `desc` array. By efficiently identifying the root node, creating nodes, and building relationships, the solution provides a clean and optimized approach for tree reconstruction.

The algorithm uses a `set` to identify the root and a `map` to manage the nodes and their relationships, ensuring that the tree is reconstructed in linear time. This makes the solution efficient and scalable for large inputs, with a time complexity of O(n) and space complexity of O(n).

This code provides a well-structured and easy-to-understand approach for solving the problem of building a binary tree from a set of node relationships. It can be easily extended or modified to accommodate other variations of tree construction problems.

[`Link to LeetCode Lab`](https://leetcode.com/problems/create-binary-tree-from-descriptions/description/)

---
{{< youtube yWkrFfqO7NA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

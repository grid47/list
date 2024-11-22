
+++
authors = ["grid47"]
title = "Leetcode 1110: Delete Nodes And Return Forest"
date = "2024-07-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1110: Delete Nodes And Return Forest in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Tree","Depth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "UhKu0q1yXHY"
youtube_upload_date="2024-07-17"
youtube_thumbnail="https://i.ytimg.com/vi_webp/UhKu0q1yXHY/maxresdefault.webp"
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
    vector<TreeNode*> ans;
    set<int> to_del;
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(int i: to_delete) to_del.insert(i);
        helper(root, true);
        return ans;
    }

    TreeNode* helper(TreeNode* root, bool is_root) {
        if(root == NULL) return NULL;
        bool del = to_del.find(root->val) != to_del.end();
        if(is_root && !del) ans.push_back(root);
        root->left = helper(root->left, del);
        root->right = helper(root->right, del);
        return del? NULL : root;
    }

};
{{< /highlight >}}
---


### Problem Statement
The task is to delete specific nodes from a binary tree and return all the remaining trees as a list of root nodes. Given a binary tree and an array of values representing the nodes to be deleted, your goal is to:
- Remove the specified nodes from the tree.
- If a node is deleted, its children should be treated as new root nodes in the resulting forest.

**Input:**
- A pointer to the root of the binary tree.
- A list of integers representing the values of nodes to delete.

**Output:**
- A vector containing pointers to the root nodes of the remaining trees.

### Approach
To solve this problem, we will use a recursive approach:
1. Create a set to efficiently check which nodes need to be deleted.
2. Traverse the tree recursively. For each node:
   - If it is marked for deletion, recursively call the function on its children.
   - If it is not marked for deletion and is considered a root node (i.e., its parent is deleted), add it to the result list.
3. Return `nullptr` for deleted nodes, and the original node for non-deleted nodes.
4. Utilize a helper function to facilitate the recursion and maintain clarity.

### Code Breakdown (Step by Step)

1. **Class and Struct Definition**: The `TreeNode` structure defines the structure of each node in the binary tree.

   ```cpp
   struct TreeNode {
       int val;
       TreeNode *left;
       TreeNode *right;
       TreeNode() : val(0), left(nullptr), right(nullptr) {}
       TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
       TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
   };
   ```

2. **Solution Class**: The `Solution` class contains the method to perform the node deletions.

   ```cpp
   class Solution {
       vector<TreeNode*> ans;
       set<int> to_del;  // Set to store values of nodes to delete
   ```

3. **Main Method**: The `delNodes` method initializes the deletion process.

   ```cpp
       public:
       vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
           for(int i: to_delete) to_del.insert(i);  // Insert to_delete values into the set
           helper(root, true);  // Start the recursive helper function
           return ans;  // Return the list of remaining trees
       }
   ```

4. **Helper Function**: The `helper` method performs the recursive traversal of the tree.

   ```cpp
       TreeNode* helper(TreeNode* root, bool is_root) {
           if(root == NULL) return NULL;  // Base case: if the node is null, return null
           bool del = to_del.find(root->val) != to_del.end();  // Check if current node should be deleted
   ```

5. **Checking for Root Nodes**: If the node is not marked for deletion and is a root node (i.e., `is_root` is true), it is added to the result.

   ```cpp
           if(is_root && !del) ans.push_back(root);  // Add to result if it's a root and not deleted
   ```

6. **Recursive Calls**: The function calls itself for the left and right children of the current node, updating the `is_root` flag based on whether the current node is deleted.

   ```cpp
           root->left = helper(root->left, del);  // Recursively process left child
           root->right = helper(root->right, del);  // Recursively process right child
           return del ? NULL : root;  // Return null if deleted, otherwise return the current node
       }
   };
   ```

### Complexity Analysis
- **Time Complexity**: The time complexity of the algorithm is \(O(n)\), where \(n\) is the number of nodes in the tree. Each node is visited once to check for deletion and to build the list of remaining trees.
- **Space Complexity**: The space complexity is \(O(h)\), where \(h\) is the height of the tree. This space is used by the recursion stack. The set `to_del` requires \(O(k)\) space, where \(k\) is the number of nodes to delete.

### Conclusion
The provided C++ code effectively deletes specified nodes from a binary tree and constructs a forest of remaining trees using a recursive approach. By leveraging a set for fast lookups and a helper function to manage the traversal, the algorithm maintains clarity and efficiency.

This solution exemplifies a common pattern in tree-related problems, showcasing how to manipulate trees through recursion. The use of a set enhances performance, allowing for quick checks on whether nodes should be deleted.

Overall, this implementation serves as a valuable reference for those looking to understand tree manipulations and recursive algorithms in competitive programming or software development.


[`Link to LeetCode Lab`](https://leetcode.com/problems/delete-nodes-and-return-forest/description/)

---
{{< youtube UhKu0q1yXHY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

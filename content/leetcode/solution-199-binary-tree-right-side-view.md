
+++
authors = ["grid47"]
title = "Leetcode 199: Binary Tree Right Side View"
date = "2024-10-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 199: Binary Tree Right Side View in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Breadth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/199.webp"
youtube = "d4zLyf32e3I"
youtube_upload_date="2021-01-31"
youtube_thumbnail="https://i.ytimg.com/vi_webp/d4zLyf32e3I/maxresdefault.webp"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/199.webp" 
    alt="A glowing tree viewed from the right side, with the rightmost nodes gently illuminating."
    caption="Solution to LeetCode 199: Binary Tree Right Side View Problem"
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        list<TreeNode*> q;
        q.push_back(root);
        while(!q.empty()) {
            vector<int> res;
            int sz = q.size();
            while(sz--) {
                auto tmp = q.front();
                q.pop_front();
                res.push_back(tmp->val);
                if(tmp->left) q.push_back(tmp->left);
                if(tmp->right) q.push_back(tmp->right);
            }
            ans.push_back(res.back());
        }
        return ans;
    }
};
{{< /highlight >}}
---

### 🌟 Right Side View of a Binary Tree (BFS Approach)

In this problem, we are tasked with returning the "right side view" of a binary tree. The right side view consists of the nodes that are visible when the tree is viewed from the right side. Specifically, we need to return the rightmost node at each level of the binary tree.

#### Example:
- **Input:**  
  ```cpp
  root = [1, 2, 3, 4, null, 5, 6]
  ```
  The tree looks like:
  ```
          1
         / \
        2   3
       /     / \
      4     5   6
  ```
- **Output:** `[1, 3, 6]`  
  **Explanation:** The visible nodes from the right side are:
  - 1 from the first level,
  - 3 from the second level, and
  - 6 from the third level.

### 💡 Approach

We can solve this problem using **Breadth-First Search (BFS)**. BFS allows us to explore the tree level by level, and the rightmost node at each level can be found by processing the nodes from left to right. The last node processed at each level will be the rightmost node for that level.

#### Steps:
1. **Initialize a Queue:** We will use a queue for BFS traversal. The queue will help us store nodes level by level.
2. **Process Each Level:** For each level, we enqueue the left and right children of the current node, and at the end of the level, we record the last node (rightmost node).
3. **Return the Result:** After processing all levels, we will return the list of rightmost nodes.

### 🛠 Code Breakdown

#### Step 1: Initial Setup
```cpp
vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    if(!root) return ans;
```
- The `rightSideView` function is defined, which takes the root of a binary tree as input.
- If the tree is empty (`root == nullptr`), we return an empty vector as there are no visible nodes.

#### Step 2: Initialize the Queue for BFS
```cpp
    list<TreeNode*> q;
    q.push_back(root);
```
- We use a `std::list` as the queue to facilitate BFS traversal. The queue starts with the root node.

#### Step 3: Process Each Level
```cpp
    while(!q.empty()) {
        vector<int> res;
        int sz = q.size();
```
- The `while` loop processes each level until the queue is empty.
- We initialize a vector `res` to store the values of nodes at the current level.
- `sz` is the number of nodes at the current level, which is simply the size of the queue.

#### Step 4: Process All Nodes at the Current Level
```cpp
        while(sz--) {
            auto tmp = q.front();
            q.pop_front();
            res.push_back(tmp->val);
            if(tmp->left) q.push_back(tmp->left);
            if(tmp->right) q.push_back(tmp->right);
        }
```
- The inner `while` loop processes each node at the current level:
  - We dequeue the front node.
  - We add the node’s value to the `res` vector.
  - If the node has left or right children, we enqueue them to the queue.

#### Step 5: Add the Rightmost Node of the Current Level
```cpp
        ans.push_back(res.back());
    }
```
- After processing all nodes at the current level, the last node in the `res` vector is the rightmost node of that level. We add it to the `ans` vector.

#### Step 6: Return the Final Result
```cpp
    return ans;
}
```
- After processing all levels, we return the `ans` vector, which contains the rightmost nodes from all levels.

### 📊 Complexity Analysis

#### Time Complexity:
- **O(n):** In the worst case, we visit every node exactly once during the BFS traversal. For each node, we perform constant-time operations (enqueuing and dequeuing). Therefore, the time complexity is linear in the number of nodes, i.e., **O(n)**, where `n` is the number of nodes in the binary tree.

#### Space Complexity:
- **O(n):** The space complexity is dominated by the size of the queue. In the worst case, the queue can hold all the nodes at the last level, which can be up to `n/2` nodes. Thus, the space complexity is **O(n)**.

### 🚀 Conclusion

This solution uses **Breadth-First Search (BFS)** to traverse the binary tree level by level, capturing the rightmost node at each level. Here’s a summary:

- **Time Complexity:** **O(n)**, where `n` is the number of nodes in the binary tree.
- **Space Complexity:** **O(n)**, due to the queue storing nodes at each level.

This approach is both efficient and straightforward, providing an optimal solution to the problem of determining the right side view of a binary tree.

[`Link to LeetCode Lab`](https://leetcode.com/problems/binary-tree-right-side-view/description/)

---
{{< youtube d4zLyf32e3I >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

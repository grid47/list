
+++
authors = ["grid47"]
title = "Leetcode 662: Maximum Width of Binary Tree"
date = "2024-09-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 662: Maximum Width of Binary Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Breadth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/662.webp"
youtube = "zHz0Ut1r-_8"
youtube_upload_date="2023-04-20"
youtube_thumbnail="https://i.ytimg.com/vi/zHz0Ut1r-_8/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/662.webp" 
    alt="A binary tree where the maximum width is highlighted, with the width softly glowing as it’s measured."
    caption="Solution to LeetCode 662: Maximum Width of Binary Tree Problem"
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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        queue<pair<TreeNode*, int>> q;
        int width = 0;
        q.push({root, 0});
        while(!q.empty()) {
            int f = q.front().second;
            int b = q.back().second;
            int cnt = q.size();
            for(int i = 0; i < cnt; i++) {
                TreeNode* elem = q.front().first;
                int idx = q.front().second - b;
                q.pop();
                if(elem->left  != NULL) q.push({elem->left,  2 * idx + 1});
                if(elem->right != NULL) q.push({elem->right, 2 * idx + 2});                
            }
            width = max(width, b - f + 1);
        }
        return width;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem at hand requires determining the **maximum width of a binary tree**. The width of a binary tree is defined as the number of nodes on the **longest level** of the tree. To calculate this width efficiently, we need to consider both the **level structure** and the **position of nodes** at each level.

- The binary tree nodes are given by the `TreeNode` struct, which contains three fields: `val` (the value of the node), `left` (pointer to the left child), and `right` (pointer to the right child).
- The goal is to return the maximum width of the binary tree, which is the maximum number of nodes present at any level of the tree.

### Approach

To calculate the maximum width of a binary tree, we can take advantage of **level-order traversal** (also known as **breadth-first traversal**). The general approach is as follows:

1. Use a **queue** to implement the level-order traversal of the binary tree.
2. At each level, record the **position of the nodes**. The position can be calculated by assigning each node an index that reflects its relative position within the level.
3. For each level, calculate the difference between the first and last node positions and update the width accordingly.
4. Track the maximum width observed during the traversal.

### Code Breakdown (Step by Step)

The algorithm is implemented in the `Solution` class with the `widthOfBinaryTree` function. Let's break down the code step by step.

#### 1. **Edge Case Handling (Empty Tree)**
```cpp
if(root == NULL) return 0;
```
- Before starting the main logic, we handle the edge case where the root is `NULL`. In this case, the width is obviously `0`, and we return `0`.

#### 2. **Queue Initialization**
```cpp
queue<pair<TreeNode*, int>> q;
int width = 0;
q.push({root, 0});
```
- We declare a queue of pairs: each pair consists of a `TreeNode*` (the node) and an integer (its index at that level).
- We initialize the queue by pushing the root node with an index of `0`. This index will represent the position of the root in the tree.

#### 3. **Level-Order Traversal**
```cpp
while(!q.empty()) {
    int f = q.front().second;
    int b = q.back().second;
    int cnt = q.size();
    for(int i = 0; i < cnt; i++) {
        TreeNode* elem = q.front().first;
        int idx = q.front().second - b;
        q.pop();
        if(elem->left != NULL) q.push({elem->left, 2 * idx + 1});
        if(elem->right != NULL) q.push({elem->right, 2 * idx + 2});
    }
    width = max(width, b - f + 1);
}
```
- **While loop**: We perform a level-order traversal using a `queue` that stores the nodes along with their respective indices. The traversal continues as long as the queue is not empty.
- **f (front) and b (back)**: We extract the `front` and `back` elements of the queue to calculate the width at the current level. The index difference between the front and back elements represents the width at that level.
- **cnt (count)**: The number of elements at the current level. This is equal to the size of the queue at the start of the loop.
- **For loop**: For each element in the current level:
  - We compute the relative index (`idx`) of the current node by subtracting the back element's index (`b`) from the current node's index (`q.front().second`).
  - After processing the current node, we remove it from the queue (`q.pop()`).
  - If the node has a left child, we add it to the queue with the calculated index `2 * idx + 1`.
  - Similarly, if the node has a right child, we add it to the queue with the calculated index `2 * idx + 2`.
  
- **Width Update**: After processing all nodes at the current level, we calculate the width as `b - f + 1` (difference between the indices of the back and front nodes plus one), and update the `width` variable to store the maximum width encountered so far.

#### 4. **Return the Result**
```cpp
return width;
```
- Once the level-order traversal is complete, we return the maximum width observed during the process.

### Complexity

#### Time Complexity:
- **O(n)**: Each node is processed once in the `while` loop and within the inner `for` loop. Since each node is added and removed from the queue exactly once, the overall time complexity is linear with respect to the number of nodes, i.e., `O(n)`, where `n` is the number of nodes in the binary tree.

#### Space Complexity:
- **O(n)**: The queue can store up to `n` nodes in the worst case (if the tree is skewed, such as in a degenerate tree). Therefore, the space complexity is proportional to the number of nodes in the tree.

### Conclusion

This algorithm efficiently calculates the maximum width of a binary tree using a level-order traversal (breadth-first search). By using the indices of the nodes, it effectively computes the width at each level without the need to explicitly store the positions of all nodes at each level. The algorithm handles all edge cases, such as trees with fewer nodes or skewed trees, and provides an optimal solution with a time complexity of `O(n)` and a space complexity of `O(n)`. This approach is well-suited for solving problems involving tree traversal and calculating properties related to the width or levels of binary trees.

[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-width-of-binary-tree/description/)

---
{{< youtube zHz0Ut1r-_8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

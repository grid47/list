
+++
authors = ["grid47"]
title = "Leetcode 98: Validate Binary Search Tree"
date = "2024-10-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 98: Validate Binary Search Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Binary Search Tree","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/98.webp"
youtube = "s6ATEkipzow"
youtube_upload_date="2021-01-08"
youtube_thumbnail="https://i.ytimg.com/vi/s6ATEkipzow/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/98.webp" 
    alt="A glowing tree with balanced nodes, radiating a sense of order and validation."
    caption="Solution to LeetCode 98: Validate Binary Search Tree Problem"
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
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode* node = root, *prv = NULL;
        // stk.push(root);
        while(!stk.empty() || node) {
            if(node) {
                stk.push(node);
                node = node->left;
            } else {
                node = stk.top();
                stk.pop();
                if(prv != NULL && prv -> val >= node->val)
                    return false;
                prv = node;
                node = node->right;
            }
        }
        return true;
    }
};
{{< /highlight >}}
---


### 🌳 **Valid Binary Search Tree (BST) Problem**

The problem asks whether a given binary tree is a **valid binary search tree (BST)**. A **binary search tree** is a type of binary tree where:
- The value of every node in the left subtree is less than the node’s value.
- The value of every node in the right subtree is greater than the node’s value.
- Both left and right subtrees must also be valid BSTs.

Our task is to verify if a given binary tree satisfies these conditions.

#### **Example:**

- **Input:**  
  `root = [2,1,3]`  
  **Output:** `true`  
  **Explanation:** The binary tree is a valid BST because:
  - `2` is greater than `1` (left subtree) and less than `3` (right subtree).

- **Input:**  
  `root = [5,1,4,null,null,3,6]`  
  **Output:** `false`  
  **Explanation:** The binary tree is **not** a valid BST because:
  - `4` is on the right of `5` but `3` (on the left of `4`) is less than `5`, violating the BST properties.

---

### 🔑 **Approach:**

To solve this, we can utilize **in-order traversal** of the tree. During an **in-order traversal**, the nodes are visited in the following order:
1. Traverse the left subtree.
2. Visit the current node.
3. Traverse the right subtree.

For a valid BST:
- During the in-order traversal, the nodes must be visited in **strictly increasing order** (i.e., each node’s value must be greater than the previous node's value).

#### **Steps:**
1. Traverse the tree using in-order traversal, starting from the root node.
2. Keep track of the previously visited node. If the current node’s value is **not greater** than the previous node’s value, return `false`.
3. Use a **stack** to simulate the recursive in-order traversal iteratively, making the algorithm more space-efficient by avoiding recursion.

---

### 💻 **Code Breakdown:**

#### **1. Class Definition and Initial Setup**

```cpp
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode* node = root, *prv = NULL;
```

- We initialize a `stack` (`stk`) to simulate the in-order traversal iteratively.
- The `node` pointer starts at the root and is used to traverse the tree.
- `prv` stores the previously visited node’s value (initialized to `NULL`) for comparison.

#### **2. Iterative In-Order Traversal**

```cpp
        while(!stk.empty() || node) {
            if(node) {
                stk.push(node);
                node = node->left;
            } else {
                node = stk.top();
                stk.pop();
```

- The while loop runs as long as there are nodes to process (`stk` is not empty) or the current node is not `NULL`.
- If the `node` is not `NULL`, push it onto the stack and move to its left child (`node = node->left`).
- If the `node` is `NULL`, pop the top node from the stack, which represents the next node to visit in the in-order traversal.

#### **3. Validity Check and Node Traversal**

```cpp
                if(prv != NULL && prv -> val >= node->val)
                    return false;
                prv = node;
                node = node->right;
            }
        }
```

- After visiting a node, if `prv` (the previous node) is not `NULL`, compare the value of `prv` with the current `node`. If `prv->val >= node->val`, the tree is not a valid BST, so return `false`.
- If the values are in the correct order, update `prv` to the current node and move to the right child (`node = node->right`).

#### **4. Conclusion**

```cpp
        return true;
    }
};
```

- If no violations are found, the tree is a valid BST, and we return `true`.

---

### 🧠 **Time and Space Complexity:**

#### **Time Complexity:**

The time complexity of the algorithm is **O(n)**, where `n` is the number of nodes in the tree. This is because, in the worst case, each node is visited once during the in-order traversal.

#### **Space Complexity:**

The space complexity is **O(h)**, where `h` is the height of the tree. The space is used by the stack to store nodes during the traversal. In the worst case (for an unbalanced tree), the height `h` could be equal to `n`, resulting in a space complexity of **O(n)**. For a balanced tree, the space complexity would be **O(log n)**.

---

### 🎯 **Conclusion:**

This solution efficiently checks whether a given binary tree is a valid BST by performing an **iterative in-order traversal**. By maintaining a reference to the previous node and using a stack to simulate recursion, we ensure the values are visited in the correct order, verifying the BST property in **O(n)** time.

The space complexity is optimized to **O(h)**, where `h` is the height of the tree, ensuring a space-efficient solution. This approach avoids the overhead of recursion and offers an optimal solution for validating a binary search tree.

---

**Happy coding!** 🌱✨

[`Link to LeetCode Lab`](https://leetcode.com/problems/validate-binary-search-tree/description/)

---
{{< youtube s6ATEkipzow >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |


+++
authors = ["grid47"]
title = "Leetcode 95: Unique Binary Search Trees II"
date = "2024-10-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 95: Unique Binary Search Trees II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Dynamic Programming","Backtracking","Tree","Binary Search Tree","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/95.webp"
youtube = "m907FlQa2Yc"
youtube_upload_date="2023-08-05"
youtube_thumbnail="https://i.ytimg.com/vi/m907FlQa2Yc/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/95.webp" 
    alt="A sequence of elegant trees gently forming in various, unique shapes."
    caption="Solution to LeetCode 95: Unique Binary Search Trees II Problem"
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
    vector<TreeNode*> run(int l, int r) {
        vector<TreeNode*> ans, left, right;
        if(l >= r) {
            if(l == r) ans.push_back(new TreeNode(l));
            else ans.push_back(NULL);
            return ans;
        }
        for(int i = l; i <= r; i++) {
            left = run(l, i - 1);
            right= run(i + 1, r);
            
            for(int j = 0; j < left.size(); j++) {
                for(int k = 0; k < right.size(); k++) {
                    TreeNode* node = new TreeNode(i);
                    node->left = left[j];
                    node->right = right[k];
                    ans.push_back(node);
                }
            }
        }
        return ans;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        /*
        
        This is a small light weight problem
        my mind is not ready to think about this problem
        
        bst is sorted array
        we can fix a root and get a 
        array of left trees
        and array of right trees
        integrate them then add to result
        
        */        
        vector<TreeNode*> ans, left, right;
        
        for(int i = 1; i <= n; i++) {
            left = run(1, i - 1);
            right= run(i + 1, n);
            
            for(int j = 0; j < left.size(); j++) {
                for(int k = 0; k < right.size(); k++) {
                    TreeNode* node = new TreeNode(i);
                    node->left = left[j];
                    node->right = right[k];
                    ans.push_back(node);
                }
            }
        }
        return ans;
    }
};
{{< /highlight >}}
---

### 🌳 **Problem Overview: Generate Unique Binary Search Trees (BSTs)**

You are asked to generate all unique binary search trees (BSTs) that can be constructed using integers from `1` to `n`. A binary search tree is structured such that:
- Each node has at most two children.
- The left child’s value is smaller than the parent node.
- The right child’s value is greater than the parent node.

Given an integer `n`, your goal is to return all structurally unique BSTs using the numbers `1` to `n`.

---

### 🧑‍💻 **Step 1: TreeNode Structure**

First, define the `TreeNode` structure to represent each node in the tree. Each node contains a value (`val`), a pointer to its left child, and a pointer to its right child.

```cpp
struct TreeNode {
    int val;           // Value of the node
    TreeNode *left;    // Pointer to the left child node
    TreeNode *right;   // Pointer to the right child node

    // Constructor with no arguments initializes to 0, nullptr for children
    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    // Constructor with the node's value
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    // Constructor with value, left child, and right child
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
```

---

### 🔄 **Step 2: Recursive Helper Function (`run`)**

The `run` function is responsible for generating all possible binary search trees for a given range of values `[l, r]`. It is a recursive function that splits the range into smaller subranges, choosing each number as the root and recursively generating the left and right subtrees.

```cpp
vector<TreeNode*> run(int l, int r) {
    vector<TreeNode*> ans, left, right;

    // Base case: If no numbers in the range, return NULL
    if (l >= r) {
        if (l == r) ans.push_back(new TreeNode(l));  // Single node tree
        else ans.push_back(NULL);  // No tree possible (empty range)
        return ans;
    }

    // Try each number i as the root of the tree
    for (int i = l; i <= r; i++) {
        // Recursively generate all left subtrees for the range [l, i-1]
        left = run(l, i - 1);
        
        // Recursively generate all right subtrees for the range [i+1, r]
        right = run(i + 1, r);

        // Combine each left and right subtree with the root i
        for (int j = 0; j < left.size(); j++) {
            for (int k = 0; k < right.size(); k++) {
                TreeNode* node = new TreeNode(i);   // Create a new node with value i
                node->left = left[j];                // Attach the left subtree
                node->right = right[k];              // Attach the right subtree
                ans.push_back(node);                 // Add the tree to the result
            }
        }
    }
    return ans;  // Return all unique trees for the range [l, r]
}
```

---

### 🧑‍💻 **Step 3: Main Function (`generateTrees`)**

Now, we will define the main function `generateTrees` that will call the `run` function to generate all unique BSTs for the numbers from `1` to `n`.

```cpp
vector<TreeNode*> generateTrees(int n) {
    vector<TreeNode*> ans;

    // Iterate over each number from 1 to n as the root
    for (int i = 1; i <= n; i++) {
        // Generate all left subtrees for the range [1, i-1]
        vector<TreeNode*> left = run(1, i - 1);
        
        // Generate all right subtrees for the range [i+1, n]
        vector<TreeNode*> right = run(i + 1, n);

        // Combine each left and right subtree with root i
        for (int j = 0; j < left.size(); j++) {
            for (int k = 0; k < right.size(); k++) {
                TreeNode* node = new TreeNode(i);  // Root node with value i
                node->left = left[j];               // Attach the left subtree
                node->right = right[k];             // Attach the right subtree
                ans.push_back(node);                // Add the tree to the result
            }
        }
    }
    return ans;  // Return all unique BSTs for the numbers 1 to n
}
```

---

### 💡 **Explanation of the Approach**

1. **Base Case for Recursion:**
   - If the range `[l, r]` has no numbers (i.e., `l >= r`), we return a list containing `NULL` (no tree possible). If there is exactly one number, we create a single node tree.

2. **Recursive Exploration:**
   - For each number `i` from `l` to `r`, treat `i` as the root of the tree.
   - The left subtree is generated recursively from the range `[l, i-1]`, and the right subtree is generated recursively from the range `[i+1, r]`.
   - Each combination of left and right subtrees is attached to the root `i`, and the resulting tree is added to the answer.

3. **Main Function:**
   - The main function loops through each number `i` from `1` to `n` and generates all possible left and right subtrees using the `run` function. For each combination of left and right subtrees, a new tree is formed with `i` as the root.

---

### ⏱️ **Time and Space Complexity**

#### Time Complexity:
The time complexity is approximately **O(4^n / √n)** due to the recursive structure and the number of possible unique BSTs, which is related to the **Catalan number**. The complexity arises from the fact that there are **O(C_n)** unique BSTs for `n` nodes, where `C_n` is the nth Catalan number.

#### Space Complexity:
The space complexity is also **O(4^n / √n)**, which accounts for:
- The storage of the generated trees.
- The recursive call stack due to the function calls.

---

### 🏁 **Conclusion**

This problem is a great exercise in recursive tree construction and combinatorics. By recursively splitting the range of numbers into smaller subranges and using **Catalan numbers** to guide tree generation, we can efficiently compute all unique BSTs for any given `n`. Although the complexity grows exponentially, this approach is optimal for small to moderate values of `n`.

---

[`Link to LeetCode Lab`](https://leetcode.com/problems/unique-binary-search-trees-ii/description/)

---
{{< youtube m907FlQa2Yc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

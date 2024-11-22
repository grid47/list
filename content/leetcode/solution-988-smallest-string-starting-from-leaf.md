
+++
authors = ["grid47"]
title = "Leetcode 988: Smallest String Starting From Leaf"
date = "2024-07-31"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 988: Smallest String Starting From Leaf in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Backtracking","Tree","Depth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "UvdWfxQ_ZDs"
youtube_upload_date="2024-04-17"
youtube_thumbnail="https://i.ytimg.com/vi/UvdWfxQ_ZDs/maxresdefault.jpg"
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
    string ans = "~";
    string smallestFromLeaf(TreeNode* root) {
        recur(root, "");
        return ans;
    }
    void recur(TreeNode* node, string s) {
        if(!node) return;
        if(!node->left && !node->right) {
            ans = min(ans, char(node->val + 'a') + s);
        }
        cout << node->val<<'\n';
        recur(node->left,  char(node->val + 'a') + s);
        recur(node->right, char(node->val + 'a') + s);  
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks to find the lexicographically smallest string that starts from any leaf of a binary tree and moves upwards to the root. Each node in the tree contains a value between 0 and 25, representing a letter in the English alphabet (where 0 maps to 'a', 1 maps to 'b', and so on). The goal is to find the smallest string from any leaf node to the root, considering that the string is formed by concatenating the node values.

### Approach

This problem can be solved using a **depth-first search (DFS)** approach. The idea is to traverse the binary tree, starting from the root, and recursively explore the left and right subtrees. For each leaf node encountered, we form a string by concatenating the corresponding letter (based on the node’s value) and compare it with the previously smallest string found.

Key observations:
1. **Leaf Nodes**: A leaf node is defined as a node that does not have any children (both left and right children are null). We need to consider all possible paths that end at the leaf nodes.
2. **Lexicographical Order**: The smallest string from the leaf to the root is determined by lexicographically comparing strings. The idea is to construct the string in reverse order (from leaf to root) and compare it to keep track of the lexicographically smallest one.

### Code Breakdown (Step by Step)

#### 1. **Helper Function (`smallestFromLeaf`)**:
```cpp
string ans = "~";
string smallestFromLeaf(TreeNode* root) {
    recur(root, "");
    return ans;
}
```
- The function `smallestFromLeaf` initializes a variable `ans` to `"~"` (a string greater than any possible string formed by node values). It then calls the recursive helper function `recur` starting with the root of the binary tree.
- The result of the smallest string is stored in `ans` and returned after the DFS traversal.

#### 2. **Recursive Function (`recur`)**:
```cpp
void recur(TreeNode* node, string s) {
    if(!node) return;
    if(!node->left && !node->right) {
        ans = min(ans, char(node->val + 'a') + s);
    }
    cout << node->val << '\n';
    recur(node->left,  char(node->val + 'a') + s);
    recur(node->right, char(node->val + 'a') + s);  
}
```
- The function `recur` performs a DFS traversal of the binary tree. It takes two parameters:
  - `node`: the current node being processed.
  - `s`: the string constructed so far from the leaf node to the current node.
  
  **Base Case**:
  - If the current node is null (`if(!node)`), we return immediately as there is nothing to process.

  **Leaf Node Check**:
  - If the current node is a leaf node (both left and right children are null), the string formed by traversing from this leaf to the root is complete. At this point, we compute the string by adding the current node’s corresponding character (`char(node->val + 'a')`) to the string `s`, which holds the characters from the leaf to the root. This string is compared with the current `ans` to track the lexicographically smallest string.

  **Recursive Calls**:
  - The function recursively calls itself for the left and right children of the current node, appending the character corresponding to the current node’s value (`char(node->val + 'a')`) to the string `s` being passed down. This continues until all leaf nodes have been processed.
  - A debug print statement (`cout << node->val << '\n';`) is added to print the value of the current node for debugging purposes.

#### 3. **String Construction**:
- The string `s` is built from the leaf to the root, as we append the character for each node while traversing down. By the time we reach a leaf, the string `s` will have the characters corresponding to that leaf’s path to the root.
- We use `char(node->val + 'a')` to convert a node’s integer value to a corresponding letter, ensuring that the node’s value `0` maps to `'a'`, `1` maps to `'b'`, and so on.

### Complexity

#### Time Complexity:
- **DFS Traversal**: We are performing a depth-first search on the binary tree, visiting each node exactly once. The time complexity of the DFS traversal is **O(n)**, where `n` is the number of nodes in the tree.
- **String Comparison**: At each leaf, we compare the current string with the smallest string found so far. Since the maximum length of a string is equal to the height of the tree (which is **O(n)** in the worst case), the string comparison operation takes **O(h)** time, where `h` is the height of the tree. In the worst case, `h = O(n)`, so the time complexity of comparing the strings is **O(n)**.

Thus, the overall time complexity is **O(n * h)**, where `n` is the number of nodes and `h` is the height of the tree.

#### Space Complexity:
- **Recursive Stack**: The space complexity of the DFS traversal is determined by the depth of the recursion stack, which is **O(h)**, where `h` is the height of the tree.
- **String Storage**: The string `s` can have at most `h` characters, so the space used by the string is also **O(h)**.

Thus, the overall space complexity is **O(h)**.

### Conclusion

This solution efficiently computes the lexicographically smallest string from a leaf to the root of a binary tree. By using a depth-first search approach and maintaining a running string that is constructed from leaf to root, we ensure that the solution is both time-efficient and easy to implement. The time complexity is **O(n * h)**, where `n` is the number of nodes in the tree and `h` is the height of the tree, making the approach scalable for larger trees. The space complexity is **O(h)**, as it only requires space proportional to the height of the tree for the recursive stack and the string being built.

[`Link to LeetCode Lab`](https://leetcode.com/problems/smallest-string-starting-from-leaf/description/)

---
{{< youtube UvdWfxQ_ZDs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

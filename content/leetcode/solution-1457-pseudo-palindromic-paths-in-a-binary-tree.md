
+++
authors = ["grid47"]
title = "Leetcode 1457: Pseudo-Palindromic Paths in a Binary Tree"
date = "2024-06-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1457: Pseudo-Palindromic Paths in a Binary Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Bit Manipulation","Tree","Depth-First Search","Breadth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "MBsSpQnaFzg"
youtube_upload_date="2024-01-24"
youtube_thumbnail="https://i.ytimg.com/vi/MBsSpQnaFzg/maxresdefault.jpg"
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
    int pseudoPalindromicPaths (TreeNode* root) {
        return dfs(root, 0);
    }

    int dfs(TreeNode* root, int cnt){
        if(!root) return 0;
        cnt ^= (1 << (root->val - 1));
        int res = dfs(root->left, cnt) + dfs(root->right, cnt);
        if(root->left == NULL && root->right == NULL && (cnt &(cnt -1)) == 0)
            res++;
        return res;
    }

};
{{< /highlight >}}
---

### Problem Statement

The problem involves finding the number of pseudo-palindromic paths in a binary tree. A path is considered pseudo-palindromic if the values along the path can be rearranged to form a palindrome. In terms of character counts, a path can be rearranged into a palindrome if at most one character has an odd count. The task is to count how many such paths exist from the root of the tree to the leaves.

### Approach

To solve this problem, we can utilize a Depth-First Search (DFS) traversal of the binary tree. The main idea is to keep track of the counts of each digit (representing the values of the nodes) as we traverse down the tree. We can use a bit manipulation technique to efficiently track which digits have odd counts.

1. **Bitmasking for Count Tracking**: We can use an integer as a bitmask to represent the count of values from 1 to 9 (assuming node values are in this range). Each bit in this integer represents whether a particular number appears an odd number of times along the current path.
2. **Recursive DFS Traversal**: As we traverse the tree recursively, we update our bitmask when we encounter a node. We toggle the corresponding bit for the node’s value.
3. **Leaf Node Check**: Upon reaching a leaf node, we check if the path can form a pseudo-palindrome by ensuring that the bitmask has at most one bit set (indicating that at most one value appears an odd number of times).
4. **Count Pseudo-Palindromic Paths**: If the conditions for a pseudo-palindrome are satisfied at a leaf node, we increase our count.

### Code Breakdown (Step by Step)

Here’s a detailed breakdown of the code:

1. **Class Declaration**:
   ```cpp
   class Solution {
   ```

   - The solution is encapsulated in a class named `Solution`, which is a common structure in competitive programming and coding interviews.

2. **Function to Count Pseudo-Palindromic Paths**:
   ```cpp
   int pseudoPalindromicPaths(TreeNode* root) {
       return dfs(root, 0);
   }
   ```

   - The function `pseudoPalindromicPaths` takes the root of the binary tree as an argument and initializes the DFS traversal by calling the `dfs` helper function with an initial bitmask of `0`.

3. **DFS Helper Function**:
   ```cpp
   int dfs(TreeNode* root, int cnt){
       if(!root) return 0;
   ```

   - The `dfs` function is defined to traverse the tree. It takes a `TreeNode* root` and an integer `cnt` (the current bitmask) as arguments.
   - If the current node is `nullptr`, it means we've reached a null child and we return `0` as there are no paths through this node.

4. **Update the Bitmask**:
   ```cpp
       cnt ^= (1 << (root->val - 1));
   ```

   - For each node, the value of `root->val` is used to update the bitmask. The expression `1 << (root->val - 1)` shifts the bit corresponding to the node's value to the left. The XOR operation (`^=`) toggles the bit—if it was `0`, it becomes `1`, and if it was `1`, it becomes `0`.

5. **Recursive Calls**:
   ```cpp
       int res = dfs(root->left, cnt) + dfs(root->right, cnt);
   ```

   - The function recursively calls itself for the left and right children of the current node, passing the updated bitmask `cnt`.
   - The results of these recursive calls are summed to get the total number of pseudo-palindromic paths from this node.

6. **Check for Leaf Node and Pseudo-Palindrome Condition**:
   ```cpp
       if(root->left == NULL && root->right == NULL && (cnt &(cnt -1)) == 0)
           res++;
   ```

   - A check is performed to see if the current node is a leaf node (both left and right children are `NULL`).
   - The condition `(cnt & (cnt - 1)) == 0` checks if at most one bit is set in the bitmask, which indicates that the path can be rearranged into a pseudo-palindrome. If this condition is satisfied, we increment the result counter `res`.

7. **Return the Result**:
   ```cpp
       return res;
   }
   ```

   - Finally, the function returns the total count of pseudo-palindromic paths found from this subtree.

### Complexity

- **Time Complexity**: The time complexity of the algorithm is \( O(N) \), where \( N \) is the number of nodes in the binary tree. This is because we traverse each node exactly once during the DFS.
  
- **Space Complexity**: The space complexity is \( O(H) \), where \( H \) is the height of the tree. This is due to the space used by the recursion stack during the DFS traversal.

### Conclusion

This solution effectively counts the number of pseudo-palindromic paths in a binary tree using a depth-first search approach combined with bit manipulation for efficient counting of node values.

#### Key Takeaways:

1. **DFS Traversal**: The depth-first search is a natural choice for tree problems, allowing us to explore all paths systematically.

2. **Bit Manipulation**: Utilizing bitmasking for counting occurrences of node values is an efficient strategy that reduces the complexity of tracking odd/even counts.

3. **Leaf Node Detection**: The condition to check if we are at a leaf node is crucial for counting valid paths.

4. **Efficiency**: The solution is both time-efficient and space-efficient, making it suitable for large binary trees.

In summary, this code serves as an excellent demonstration of how to approach tree traversal problems efficiently while leveraging bit manipulation techniques to solve complex counting problems. The structure and clarity of the implementation also make it easily understandable and maintainable.

[`Link to LeetCode Lab`](https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/description/)

---
{{< youtube MBsSpQnaFzg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |


+++
authors = ["grid47"]
title = "Leetcode 508: Most Frequent Subtree Sum"
date = "2024-09-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 508: Most Frequent Subtree Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Tree","Depth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/508.webp"
youtube = "CvmRmzBQhu8"
youtube_upload_date="2023-01-14"
youtube_thumbnail="https://i.ytimg.com/vi/CvmRmzBQhu8/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/508.webp" 
    alt="A tree with sums at each subtree, and the most frequent subtree sum glowing brightly as it is discovered."
    caption="Solution to LeetCode 508: Most Frequent Subtree Sum Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
    int mx;
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans;
        map<int, int> mp;

        mx = 0;
        dfs(root, mp, ans);

        return ans;
    }
    
    int dfs(TreeNode* root, map<int, int>& mp, vector<int>& ans) {
        
        if (root == NULL) return 0;
        int res;
            
        if (root->left  == NULL && 
            root->right == NULL)
             { res = root->val; }
        else {
            int l = dfs(root->left , mp, ans);
            int r = dfs(root->right, mp, ans);
            res = l + r + root->val;
        }
        
        mp[res] += 1;
        
        if(mx < mp[res]) {
            ans.clear();
            ans.push_back(res);
            mx = mp[res];
        } else if(mx == mp[res]) {
            ans.push_back(res);
        }
        return res;
    }
};
{{< /highlight >}}
---

### Problem Statement

In this problem, you are given the root of a binary tree. Each node in the tree has an integer value. The task is to find the most frequent subtree sums in the binary tree, where a subtree sum is the sum of all node values in a particular subtree (including the root node of that subtree). If multiple subtree sums have the same frequency, return all of them. 

Your task is to return a list of the most frequent subtree sums in the binary tree.

### Approach

To solve this problem efficiently, we use a **Depth First Search (DFS)** to traverse the binary tree. For each node, we calculate the sum of its subtree, which includes the node itself and the sums of its left and right children. We can store these sums in a **map** (or dictionary) to track their frequencies.

The steps in the solution are as follows:

1. **DFS Traversal**: Starting from the root, recursively calculate the sum of the subtree for each node.
   - The sum of a leaf node is just the node's value.
   - For non-leaf nodes, the sum is the node's value plus the sums of its left and right subtrees.
   
2. **Tracking Frequencies**: We store the calculated sums in a `map` where the key is the sum, and the value is its frequency (i.e., how many times the sum has occurred).
   - After calculating the sum for each node's subtree, we update the frequency of that sum in the map.
   
3. **Finding Maximum Frequency**: As we update the map, we also keep track of the maximum frequency encountered so far. This allows us to identify the most frequent subtree sums.

4. **Handling Multiple Results**: If multiple sums have the same frequency, we need to return all such sums. To do this, we maintain a list (`ans`) to store all the sums with the highest frequency.

5. **Return Result**: Finally, the result is the list of the most frequent subtree sums.

### Code Breakdown (Step by Step)

Let's break down the provided code and understand each part of it:

#### 1. Initialization and Setup

```cpp
int mx;
public:
vector<int> findFrequentTreeSum(TreeNode* root) {
    vector<int> ans;
    map<int, int> mp;
    mx = 0;
    dfs(root, mp, ans);
    return ans;
}
```

- `mx`: This is an integer variable that stores the maximum frequency of any subtree sum.
- `findFrequentTreeSum`: This is the main function that initializes a `map<int, int>` to store the frequency of subtree sums and a `vector<int>` to store the most frequent subtree sums.
- Inside `findFrequentTreeSum`, we call the `dfs` function to traverse the tree and calculate the subtree sums. After the DFS traversal, we return the `ans` vector, which contains the most frequent subtree sums.

#### 2. Depth First Search (DFS)

```cpp
int dfs(TreeNode* root, map<int, int>& mp, vector<int>& ans) {
    if (root == NULL) return 0;
    int res;
    
    if (root->left == NULL && root->right == NULL) {
        res = root->val;
    } else {
        int l = dfs(root->left, mp, ans);
        int r = dfs(root->right, mp, ans);
        res = l + r + root->val;
    }
    
    mp[res] += 1;
    
    if (mx < mp[res]) {
        ans.clear();
        ans.push_back(res);
        mx = mp[res];
    } else if (mx == mp[res]) {
        ans.push_back(res);
    }
    
    return res;
}
```

- **Base Case**: The DFS function starts by checking if the current node (`root`) is `NULL`. If it is `NULL`, it returns `0`, indicating that an empty node contributes no value to the sum.
  
- **Leaf Node Case**: If the node is a leaf (both left and right children are `NULL`), the sum for this node is just its value (`res = root->val`).

- **Non-Leaf Node Case**: For non-leaf nodes, the function recursively calculates the sum of the left subtree (`l`) and the sum of the right subtree (`r`). The sum for the current node's subtree is the sum of these left and right sums plus the current node's value (`res = l + r + root->val`).

- **Updating Frequency**: The subtree sum (`res`) is added to the map (`mp`), and its frequency is incremented by 1 (`mp[res] += 1`).

- **Tracking Maximum Frequency**:
    - If the current frequency of `res` is greater than the current maximum frequency (`mx`), we clear the `ans` vector and add the current sum `res` to `ans`. We also update `mx` to the new maximum frequency.
    - If the current frequency of `res` is equal to `mx`, we simply add the current sum `res` to `ans`.

- **Returning Subtree Sum**: Finally, the function returns the sum of the current node's subtree (`res`).

#### 3. TreeNode Definition

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

This is the definition of a binary tree node. Each `TreeNode` contains:
- `val`: The value of the node.
- `left`: A pointer to the left child node.
- `right`: A pointer to the right child node.

### Complexity

#### Time Complexity:
- **DFS Traversal**: The DFS function visits each node once, so the time complexity of the traversal is `O(n)`, where `n` is the number of nodes in the tree.
- **Map Operations**: For each node, we perform an insert and lookup operation in the map, which takes `O(log k)`, where `k` is the number of unique subtree sums. However, since the number of unique subtree sums is at most `n`, we can treat this as `O(log n)` for each node.

Thus, the overall time complexity is `O(n log n)`.

#### Space Complexity:
- The space complexity is determined by the storage of the map `mp` and the recursive call stack.
- The map `mp` stores at most `n` subtree sums, so it requires `O(n)` space.
- The recursive call stack for DFS also requires `O(n)` space in the worst case (i.e., if the tree is a straight line).

Thus, the overall space complexity is `O(n)`.

### Conclusion

This solution efficiently solves the problem by leveraging a DFS traversal to calculate subtree sums and using a map to track the frequency of each sum. By maintaining the maximum frequency during the traversal, we can easily identify the most frequent subtree sums. The solution has optimal time and space complexity for the given problem, making it suitable for large binary trees.

[`Link to LeetCode Lab`](https://leetcode.com/problems/most-frequent-subtree-sum/description/)

---
{{< youtube CvmRmzBQhu8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

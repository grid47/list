
+++
authors = ["grid47"]
title = "Leetcode 2583: Kth Largest Sum in a Binary Tree"
date = "2024-02-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2583: Kth Largest Sum in a Binary Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Breadth-First Search","Sorting","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "Sh-IqBIg9dU"
youtube_upload_date="2024-10-22"
youtube_thumbnail="https://i.ytimg.com/vi/Sh-IqBIg9dU/maxresdefault.jpg"
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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int sz = q.size();
            long long sum = 0;
            while(sz--) {
                auto it = q.front();
                sum += it->val;
                q.pop();
                if(it->left) q.push(it->left);
                if(it->right) q.push(it->right);
            }
            pq.push(sum);
            if(pq.size() > k) pq.pop();
        }
        if(pq.size() < k) return -1;
        return pq.top();
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem requires finding the `k`-th largest sum of node values at any level in a binary tree. The levels of the tree are defined by the depth of the nodes, where the root is at level 0, its children are at level 1, and so on. The goal is to calculate the sum of node values at each level and return the `k`-th largest sum. If there are fewer than `k` levels, the function should return `-1`.

### Approach

To solve this problem efficiently, we need to perform a level-order traversal of the tree to calculate the sum of nodes at each level. For this, we can use a **breadth-first search (BFS)** algorithm, which is well-suited for exploring a tree level by level.

Once we have the sum for each level, we need to track the largest sums in order to find the `k`-th largest. A **priority queue (min-heap)** is a good choice for this task because it allows us to efficiently keep track of the largest sums by maintaining a heap of size `k`. The smallest element in the heap will always be the `k`-th largest sum, as the heap is structured in a way that the smallest element is at the top. We will push each level's sum into the heap and, if the heap exceeds size `k`, remove the smallest element.

#### Key Steps:
1. **Level-order Traversal**: Using BFS, we will traverse the binary tree level by level, calculating the sum of nodes at each level.
2. **Maintain Top k Sums**: Use a priority queue to track the top `k` sums.
3. **Return the k-th Largest Sum**: After traversing all levels, if we have fewer than `k` sums, return `-1`. Otherwise, return the smallest element in the heap, which represents the `k`-th largest sum.

### Code Breakdown (Step by Step)

#### 1. **Priority Queue Setup**:
```cpp
priority_queue<long long, vector<long long>, greater<long long>> pq;
```
Here, we create a min-heap (`priority_queue`) to store the sums of node values at each level. The `greater<long long>` comparator ensures that the smallest sum is at the top of the heap, which allows us to efficiently track the `k`-th largest sum by maintaining a heap of size `k`.

#### 2. **Initial Check for Empty Tree**:
```cpp
if(!root) return 0;
```
If the tree is empty (i.e., `root` is `nullptr`), we immediately return `0` since there are no levels to calculate sums for.

#### 3. **Queue Initialization for Level-order Traversal**:
```cpp
queue<TreeNode*> q;
q.push(root);
```
We initialize a queue (`q`) to store the nodes of the tree as we traverse it level by level. We begin by pushing the root node into the queue.

#### 4. **BFS Traversal**:
```cpp
while(!q.empty()) {
    int sz = q.size();
    long long sum = 0;
    while(sz--) {
        auto it = q.front();
        sum += it->val;
        q.pop();
        if(it->left) q.push(it->left);
        if(it->right) q.push(it->right);
    }
    pq.push(sum);
    if(pq.size() > k) pq.pop();
}
```
This loop represents the BFS traversal:
- We first get the size of the current level (`sz = q.size()`), which tells us how many nodes are at this level.
- For each node at the current level, we:
  - Add its value to `sum`.
  - Remove the node from the queue and add its left and right children (if any) to the queue for the next level.
- After calculating the sum for the current level, we push it into the priority queue (`pq.push(sum)`).
- If the size of the priority queue exceeds `k`, we remove the smallest element (`pq.pop()`). This ensures that the heap always contains the `k` largest sums.

#### 5. **Final Check**:
```cpp
if(pq.size() < k) return -1;
return pq.top();
```
After all levels have been processed:
- If the priority queue contains fewer than `k` sums (meaning there are fewer than `k` levels), we return `-1`.
- Otherwise, the smallest element in the heap (`pq.top()`) represents the `k`-th largest sum, which we return.

### Complexity Analysis

- **Time Complexity**:
  - The time complexity is dominated by the level-order traversal of the tree. Each node is processed once, so the traversal takes \(O(n)\), where `n` is the number of nodes in the tree.
  - For each level, we insert the sum into the priority queue. Inserting an element into a priority queue takes \(O(\log k)\) time. Since there are at most `n` levels, the total time complexity for heap operations is \(O(n \log k)\).
  - Overall, the time complexity is \(O(n \log k)\).

- **Space Complexity**:
  - The space complexity is \(O(n)\) for the queue used in the level-order traversal, as in the worst case (a fully balanced tree), the queue can hold up to `n/2` nodes at the last level.
  - Additionally, the priority queue can hold up to `k` sums, so the space complexity for the heap is \(O(k)\).
  - Therefore, the total space complexity is \(O(n + k)\).

### Conclusion

This solution efficiently calculates the `k`-th largest sum of nodes at any level in a binary tree. By utilizing BFS for level-order traversal and a priority queue to maintain the top `k` largest sums, we achieve a time complexity of \(O(n \log k)\), which is optimal for this problem. The algorithm handles both balanced and unbalanced trees efficiently and ensures that we correctly return the `k`-th largest sum or `-1` if there are fewer than `k` levels.

[`Link to LeetCode Lab`](https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/description/)

---
{{< youtube Sh-IqBIg9dU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

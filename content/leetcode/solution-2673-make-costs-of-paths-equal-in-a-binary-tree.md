
+++
authors = ["grid47"]
title = "Leetcode 2673: Make Costs of Paths Equal in a Binary Tree"
date = "2024-02-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2673: Make Costs of Paths Equal in a Binary Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Greedy","Tree","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "W62wT5Lem6E"
youtube_upload_date="2023-05-07"
youtube_thumbnail="https://i.ytimg.com/vi_webp/W62wT5Lem6E/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minIncrements(int n, vector<int>& A) {
        int res = 0;
        for (int i = n / 2 - 1; i >= 0; --i) {
            int l = i * 2 + 1, r = i * 2 + 2;
            res += abs(A[l] - A[r]);
            A[i] += max(A[l], A[r]);
        }
        return res;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem requires us to modify an array `A` of length `n` (where `n` is always a power of 2) so that the array is transformed into a binary heap. The goal is to perform the minimum number of increment operations on the elements to make the array a binary heap. Specifically, we need to make sure that for each node `i` in the array, the values of its left child and right child are greater than or equal to the value at index `i`.

### Approach

To solve this problem, the idea is to process the array in a bottom-up manner, starting from the leaf nodes and moving towards the root. The binary heap property requires that the value at each parent node must be greater than or equal to the values at the child nodes. If the value at a parent node is less than the value at one of its children, we will need to increment the value of that parent node so that it satisfies the heap condition.

We also need to ensure that the total number of increments is minimized. This is achieved by adjusting the value at the parent node to be the maximum of its children if the heap property is violated, and incrementing it by the difference between the two values.

The algorithm follows a simple greedy approach:
1. Start from the bottom-most level of the binary heap (leaf nodes) and move towards the root.
2. For each parent node, compare the values of its left and right children.
3. If the parent value is smaller than either of its children, increment it to make sure the heap property is satisfied.
4. Keep track of the total number of increments performed.
5. Return the total increments needed after processing all nodes.

### Code Breakdown (Step by Step)

#### Step 1: Initialize Result Variable

```cpp
int res = 0;
```

- **Line 1**: We initialize the variable `res` to store the total number of increments required to satisfy the binary heap condition. This variable will be updated as we process each parent node in the heap.

#### Step 2: Loop Through Each Parent Node in Bottom-Up Manner

```cpp
for (int i = n / 2 - 1; i >= 0; --i) {
```

- **Line 2**: The loop starts from the last internal node (which is the parent of the last leaf node) and moves towards the root of the binary heap. The index of the last internal node is `n / 2 - 1`, and the loop processes nodes from this index down to `0` (the root).

#### Step 3: Identify Left and Right Child Nodes

```cpp
int l = i * 2 + 1, r = i * 2 + 2;
```

- **Line 3**: We calculate the indices of the left and right children of the current parent node `i`. In a complete binary tree represented as an array:
  - The left child of a node at index `i` is located at index `2i + 1`.
  - The right child of a node at index `i` is located at index `2i + 2`.

#### Step 4: Calculate the Difference in Values

```cpp
res += abs(A[l] - A[r]);
```

- **Line 4**: If the parent node does not satisfy the binary heap condition, we calculate the difference between the values of the left and right children. We add this difference to the result variable `res`, as this represents the number of increments required to bring the parent node’s value to a valid value. Specifically, if one of the child nodes has a higher value, the parent will need to be incremented.

#### Step 5: Update Parent Node Value

```cpp
A[i] += max(A[l], A[r]);
```

- **Line 5**: After calculating the necessary increments for the parent node, we adjust the value of the parent node `i` to be the maximum of its two children (`A[l]` and `A[r]`). This ensures that the parent node satisfies the binary heap property for both children. By incrementing the parent node to the maximum value, we effectively ensure the heap condition holds.

#### Step 6: Return Total Increments

```cpp
return res;
```

- **Line 6**: After processing all nodes, we return the total number of increments required to convert the array into a valid binary heap.

### Complexity

#### Time Complexity:
- **O(n)**: The algorithm processes each parent node exactly once. Since the array has `n` elements, the total number of nodes processed is approximately `n/2`. Each operation on a node (finding the left and right children, updating the parent) is done in constant time. Thus, the overall time complexity is **O(n)**.

#### Space Complexity:
- **O(1)**: The algorithm uses a constant amount of space for the `res` variable, and no additional data structures are used apart from the input array `A`. Therefore, the space complexity is **O(1)**.

### Conclusion

This solution efficiently solves the problem of transforming an array into a binary heap with the minimum number of increments. By processing the nodes in a bottom-up manner, the algorithm ensures that each parent node satisfies the binary heap condition with minimal changes. The approach is optimal in terms of both time and space complexity, making it suitable for large inputs. With a time complexity of **O(n)** and space complexity of **O(1)**, this solution is efficient and scalable.

[`Link to LeetCode Lab`](https://leetcode.com/problems/make-costs-of-paths-equal-in-a-binary-tree/description/)

---
{{< youtube W62wT5Lem6E >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

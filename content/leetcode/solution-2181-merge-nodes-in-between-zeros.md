
+++
authors = ["grid47"]
title = "Leetcode 2181: Merge Nodes in Between Zeros"
date = "2024-04-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2181: Merge Nodes in Between Zeros in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Linked List","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "jrSav7fulJY"
youtube_upload_date="2024-07-04"
youtube_thumbnail="https://i.ytimg.com/vi/jrSav7fulJY/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        if(!head->next) return nullptr;

        ListNode* ptr = head->next;
        int sum = 0;
        while(ptr->val!=0) sum += ptr->val, ptr = ptr->next;
        head->next->val = sum;
        head->next->next= mergeNodes(ptr);
        return head->next;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks to merge consecutive nodes in a singly linked list that are separated by a node with value `0`. Specifically, given a singly linked list where:
- Each node contains an integer value.
- The values in the list are separated by `0`, which signifies the end of a block of nodes that need to be summed together.

The task is to remove the zeros and merge consecutive nodes by calculating their sum. After summing, the result should be stored in the node immediately following the `0` node.

### Approach

To solve this problem, we need to:
1. Traverse the list while looking for blocks of nodes that are between two consecutive `0` nodes.
2. Sum the values of nodes in each block and replace the node with the first value of the block with the calculated sum.
3. Once we reach a node with a value of `0`, we recursively repeat the process for the remaining nodes in the list, removing the `0` separator in the process.

By using recursion, we can simplify the merging of nodes in each block and handle the traversal through the linked list efficiently. This method allows for a clean solution without requiring multiple loops or complex logic.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        // Base case: If there is no node after the head (empty or only one element in the list)
        if (!head->next) return nullptr;
```
- We start by checking if the `head->next` is `nullptr`, indicating that there are no further nodes after the `head`. In this case, we return `nullptr`, signaling the end of the list. This check acts as a base case for the recursion.

```cpp
        ListNode* ptr = head->next;
        int sum = 0;
```
- We initialize a pointer `ptr` to `head->next`, which represents the first node after the initial zero node. We also initialize `sum` to 0, which will hold the sum of the values between consecutive zeros.

```cpp
        while(ptr->val != 0) sum += ptr->val, ptr = ptr->next;
```
- Here, we use a `while` loop to traverse the list starting from `ptr`. The loop continues until we encounter a node with a value of `0`. During the traversal, we keep adding the values of the nodes to `sum`. This accumulates the values between the zeros, essentially summing the block of numbers.

```cpp
        head->next->val = sum;
```
- Once we've summed all the values between the zeros, we assign the accumulated `sum` to `head->next->val`. This replaces the first node of the block with the calculated sum.

```cpp
        head->next->next = mergeNodes(ptr);
```
- Now that we've merged the first block of nodes, we recursively call `mergeNodes(ptr)`, passing the pointer `ptr` (which now points to the node with value `0` after the sum block). This recursive call will handle the next block of nodes that appear after the first zero.

```cpp
        return head->next;
    }
};
```
- Finally, we return `head->next` which now points to the newly modified list with merged sums. This will be the new head of the list.

### Example Walkthrough

Let’s walk through an example to better understand how the solution works.

#### Example 1: 
Input: `head = [0, 1, 2, 3, 0, 4, 5, 6, 0]`

**Step-by-Step Execution:**
- Initially, `head = [0, 1, 2, 3, 0, 4, 5, 6, 0]`.
- First block (between `0` and `0`):
  - Sum: `1 + 2 + 3 = 6`.
  - Replace the first node with value `6`.
  - New list: `head = [0, 6, 0, 4, 5, 6, 0]`.
- Second block (between `0` and `0`):
  - Sum: `4 + 5 + 6 = 15`.
  - Replace the first node with value `15`.
  - New list: `head = [0, 6, 15, 0]`.

At the end, the resulting list will be `head = [6, 15]`, with all zeros removed and blocks summed.

#### Example 2:
Input: `head = [0, 3, 5, 0]`

**Step-by-Step Execution:**
- First block (between `0` and `0`):
  - Sum: `3 + 5 = 8`.
  - Replace the first node with value `8`.
  - New list: `head = [0, 8, 0]`.

The final result will be `head = [8]`.

### Time Complexity

- **Time Complexity**: The time complexity is **O(n)**, where `n` is the number of nodes in the linked list. In the worst case, the algorithm must traverse all the nodes of the linked list once, visiting each node to accumulate the sum and merge the blocks.

- **Space Complexity**: The space complexity is **O(n)** due to the recursive calls, where each recursive call adds a new frame to the call stack. In the worst case, if the list contains no zeros and we have to process the entire list recursively, this could lead to a recursion depth equal to the number of nodes in the list.

### Conclusion

The solution uses recursion to merge blocks of nodes in the singly linked list that are separated by zeros. By traversing the list and summing the values between consecutive zeros, we replace the first zero node in each block with the calculated sum, effectively reducing the problem size at each step. The solution is efficient, with a time complexity of **O(n)**, and handles various edge cases, such as empty lists or lists with no zeros, seamlessly. This recursive approach makes the problem both intuitive and elegant to solve, ensuring that the list is merged correctly as specified in the problem.

[`Link to LeetCode Lab`](https://leetcode.com/problems/merge-nodes-in-between-zeros/description/)

---
{{< youtube jrSav7fulJY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

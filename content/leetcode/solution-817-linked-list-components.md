
+++
authors = ["grid47"]
title = "Leetcode 817: Linked List Components"
date = "2024-08-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 817: Linked List Components in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Linked List"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/817.webp"
youtube = "Vxbd1u86p9c"
youtube_upload_date="2019-09-16"
youtube_thumbnail="https://i.ytimg.com/vi_webp/Vxbd1u86p9c/maxresdefault.webp"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/817.webp" 
    alt="A linked list where the components are highlighted, each component softly glowing as it is connected."
    caption="Solution to LeetCode 817: Linked List Components Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> setG(nums.begin(), nums.end());
        int res =0;
        while(head != NULL) {
            if(setG.count(head->val) && 
            (head->next == NULL || !setG.count(head->next->val)))
            res++;
            head = head->next;
        }
        return res;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem is to determine the number of connected components in a linked list given a subset of its nodes. A connected component in this context is a sequence of nodes that are part of both the linked list and the subset, `nums`. Nodes in a connected component must be consecutive in the linked list. The task is to count the number of these components.

### Approach

To solve this problem efficiently, we need to identify contiguous segments in the linked list where each node’s value is present in the subset `nums`. This is achieved using an unordered set and a simple traversal of the linked list.

The main steps in the approach are as follows:

1. **Convert `nums` to an Unordered Set**:
   - Storing the elements of `nums` in an unordered set, `setG`, allows for O(1) average time complexity when checking whether a node's value is part of `nums`.
   - This setup is crucial for efficient lookup and helps determine whether each node in the list belongs to the target subset.

2. **Traverse the Linked List**:
   - We iterate through each node in the linked list to identify contiguous segments where each node's value belongs to `setG`.
   - For each node, we check if:
     - The node’s value is in `setG`.
     - Either the next node is `NULL` (end of the list) or the next node's value is not in `setG`.
   - If these conditions are met, it signifies the end of a connected component.

3. **Count Connected Components**:
   - Each time the above conditions are satisfied, we increment the count of connected components (`res`).
   - This way, we only count distinct segments as components, avoiding double-counting nodes that appear in `nums` but are part of the same contiguous sequence.

### Code Breakdown (Step by Step)

The code implementation follows the approach described:

1. **Convert `nums` to an Unordered Set**:
   ```cpp
   unordered_set<int> setG(nums.begin(), nums.end());
   ```
   - This line initializes `setG` with the elements of `nums` for quick lookups, allowing us to check whether each node’s value is in the subset efficiently.

2. **Initialize Component Counter**:
   ```cpp
   int res = 0;
   ```
   - We set up a counter `res` to store the count of connected components we encounter in the linked list.

3. **Traverse the Linked List and Count Components**:
   ```cpp
   while(head != NULL) {
       if(setG.count(head->val) && 
       (head->next == NULL || !setG.count(head->next->val)))
           res++;
       head = head->next;
   }
   ```
   - We iterate through the linked list using a `while` loop.
   - For each node, we check if its value is in `setG` and if either:
     - The next node is `NULL`, marking the end of the list, or
     - The next node’s value is not in `setG`, indicating the end of a contiguous segment.
   - If both conditions are met, we increment `res`, signaling the detection of a new connected component.
   - The `head` pointer is then moved to the next node, and the loop continues until we reach the end of the list.

4. **Return the Result**:
   ```cpp
   return res;
   ```
   - Finally, we return the value of `res`, which represents the total number of connected components found in the linked list.

### Complexity

- **Time Complexity**: O(n), where `n` is the number of nodes in the linked list. Each node is visited once, and lookups in the unordered set are on average O(1). This makes the traversal efficient.
- **Space Complexity**: O(m), where `m` is the size of `nums`. The unordered set `setG` stores each element of `nums`, ensuring constant-time lookups.

### Conclusion

This solution effectively identifies contiguous segments in a linked list that match a given subset of values, `nums`. By leveraging an unordered set, the algorithm achieves optimal time complexity for lookup operations, making it suitable for handling larger lists and subsets efficiently. This approach demonstrates a practical application of hash sets and pointer manipulation in linked lists, resulting in an intuitive yet efficient solution for finding connected components in linked data structures.

[`Link to LeetCode Lab`](https://leetcode.com/problems/linked-list-components/description/)

---
{{< youtube Vxbd1u86p9c >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

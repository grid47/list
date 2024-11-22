
+++
authors = ["grid47"]
title = "Leetcode 92: Reverse Linked List II"
date = "2024-10-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 92: Reverse Linked List II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Linked List"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/92.webp"
youtube = "RF_M9tX4Eag"
youtube_upload_date="2021-10-01"
youtube_thumbnail="https://i.ytimg.com/vi/RF_M9tX4Eag/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/92.webp" 
    alt="A linked list gently reversing, glowing softly with each node that changes position."
    caption="Solution to LeetCode 92: Reverse Linked List II Problem"
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == NULL) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next     = head;
        ListNode* pre   = dummy;
        for(int i = 1; i < left; i++)
            pre = pre->next;

        ListNode* start =   pre->next;
        ListNode* then  = start->next;

        for(int i = 0; i < right - left; i++) {
            start->next =  then->next;
             then->next =   pre->next;
              pre->next = then;
            then        = start->next;
        }
        return dummy->next;        
    }
};
{{< /highlight >}}
---

### 🔄 **Reverse Linked List Between Positions**

The problem asks us to reverse a portion of a singly linked list between two given positions `left` and `right`. Specifically, the nodes from position `left` to `right` (both inclusive) should be reversed while the rest of the list remains unchanged.

#### Example Walkthrough:
- **Input**: `head = [1, 2, 3, 4, 5], left = 2, right = 4`
- **Output**: `[1, 4, 3, 2, 5]`

In this example, the sublist from position 2 to 4 is reversed, resulting in `[4, 3, 2]` while the rest of the list remains `[1, 5]`.

### Approach

To solve this problem efficiently, we use **pointer manipulation** to reverse the sublist in-place. This approach leverages the flexibility of pointers to manipulate the list directly, reversing only the desired portion while keeping the rest of the list intact.

#### Key Steps:
1. **Dummy Node**: Introduce a dummy node to simplify boundary cases, particularly when the reversal includes the first node of the list.
2. **Pointer Traversal**: Traverse the list to reach the node just before the `left` position and the node at the `left` position (where the reversal begins).
3. **Sublist Reversal**: Reverse the portion of the list by adjusting the `next` pointers in the sublist.
4. **Return the Modified List**: After performing the reversal, return the head of the modified list, which might have changed due to the manipulation.

### Code Breakdown (Step by Step)

#### Step 1: Create a Dummy Node

```cpp
ListNode* dummy = new ListNode(0);
dummy->next = head;
```

- A **dummy node** with value `0` is introduced. This node points to the head of the list. The dummy node simplifies boundary cases, particularly when the reversal involves the first node of the list.

#### Step 2: Move `pre` to the Node Before `left`

```cpp
ListNode* pre = dummy;
for (int i = 1; i < left; i++) {
    pre = pre->next;
}
```

- We initialize `pre` at the dummy node and move it to the node just before the `left` position by iterating `left-1` times.

#### Step 3: Identify `start` and `then`

```cpp
ListNode* start = pre->next;
ListNode* then = start->next;
```

- The node at `pre->next` is the first node of the sublist to reverse, called `start`.
- The node at `start->next` is referred to as `then`. This node will be moved during each iteration of the reversal.

#### Step 4: Reversing the Sublist

```cpp
for (int i = 0; i < right - left; i++) {
    start->next = then->next;
    then->next = pre->next;
    pre->next = then;
    then = start->next;
}
```

- We iterate `right - left` times, reversing the sublist in-place. In each iteration:
  - **Remove `then` from its current position** by updating `start->next = then->next`.
  - **Insert `then` after `pre`** by setting `then->next = pre->next`.
  - Move `pre->next` to point to `then`, effectively placing it in the reversed portion.
  - Finally, update `then` to the next node to continue the reversal.

#### Step 5: Return the New Head

```cpp
return dummy->next;
```

- After completing the reversal, the head of the list is now `dummy->next`, as the dummy node's next pointer points to the new head of the list.

### Complexity Analysis

#### Time Complexity:
- **O(n)**, where `n` is the number of nodes in the list. We traverse the list once to move the `pre` pointer and perform a constant amount of work for each of the `right - left` iterations to reverse the sublist. Thus, the overall time complexity is linear in the size of the list.

#### Space Complexity:
- **O(1)**. We only use a constant amount of extra space: the dummy node and a few pointers (`pre`, `start`, and `then`). No additional space is required for storing or creating new nodes.

### Conclusion

This solution efficiently reverses a portion of a singly linked list in **O(n)** time with **O(1)** space complexity. By using a dummy node and manipulating pointers, we reverse the desired sublist without creating new nodes or altering the structure of the rest of the list. The algorithm is optimal and handles all edge cases, including when the `left` position is the head of the list or when the sublist to reverse is at the start or end of the list.

This method showcases the power of pointer manipulation to modify linked lists in-place and is a great technique for problems involving sublist manipulations.

Happy coding! 🚀

---

[`Link to LeetCode Lab`](https://leetcode.com/problems/reverse-linked-list-ii/description/)

---
{{< youtube RF_M9tX4Eag >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

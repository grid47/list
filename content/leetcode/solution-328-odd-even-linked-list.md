
+++
authors = ["grid47"]
title = "Leetcode 328: Odd Even Linked List"
date = "2024-10-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 328: Odd Even Linked List in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Linked List"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/328.webp"
youtube = "HaoudL9xEHA"
youtube_upload_date="2020-05-16"
youtube_thumbnail="https://i.ytimg.com/vi/HaoudL9xEHA/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/328.webp" 
    alt="A linked list where odd and even numbered nodes alternate, glowing softly as they form the correct pattern."
    caption="Solution to LeetCode 328: Odd Even Linked List Problem"
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
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return NULL;
        ListNode *odd = head, *ehead = head->next, *even = head->next;

        while(even && even->next) {
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        odd->next = ehead;
        return head;
    }
};
{{< /highlight >}}
---

### 🚀 Problem Statement

In this problem, we are tasked with rearranging the nodes of a singly linked list such that all the nodes at **odd positions** (1st, 3rd, 5th, etc.) come first, followed by the nodes at **even positions** (2nd, 4th, 6th, etc.). The relative order of nodes within both the odd and even groups should remain unchanged.

For example:
- **Input**: `1 -> 2 -> 3 -> 4 -> 5`
- **Output**: `1 -> 3 -> 5 -> 2 -> 4`

We are aiming to solve this in **O(n)** time complexity, where `n` is the number of nodes, and **O(1)** space complexity, meaning we shouldn't use extra space beyond a constant amount.

---

### 🧠 Approach

To tackle this efficiently, we’ll use two pointers:
- One pointer will handle the **odd indexed nodes**.
- The other pointer will manage the **even indexed nodes**.

Here’s a step-by-step breakdown of the approach:

1. **Odd and Even List Segregation**: We maintain two separate lists:
   - One for the odd indexed nodes.
   - Another for the even indexed nodes.
   
2. **Pointer Movement**: As we traverse through the list, we update the pointers alternately:
   - Odd indexed nodes will link to the next odd indexed node.
   - Even indexed nodes will link to the next even indexed node.
   
3. **Termination**: The loop ends once we reach the end of the list. Afterward, we connect the last node of the odd list to the head of the even list.

4. **Return the New List**: Finally, the rearranged list is returned starting from the head of the odd list.

---

### 🔨 Step-by-Step Code Breakdown

Let’s walk through the code implementation:

```cpp
if (!head) return NULL;
```
- **Edge Case**: If the list is empty (`head == NULL`), we return `NULL`. This handles cases where there are no nodes.

```cpp
ListNode *odd = head, *ehead = head->next, *even = head->next;
```
- **Pointer Initialization**:
  - `odd`: Points to the first node (odd index).
  - `ehead`: Points to the second node (even index).
  - `even`: Tracks the current even indexed node during iteration.

```cpp
while (even && even->next) {
    odd->next = odd->next->next;
    even->next = even->next->next;
    odd = odd->next;
    even = even->next;
}
```
- **Main Loop**:
  - This loop runs while there are still even indexed nodes to process.
  - The `odd->next` pointer is updated to point to the next odd indexed node.
  - The `even->next` pointer is updated to point to the next even indexed node.
  - Both `odd` and `even` pointers then move forward.

```cpp
odd->next = ehead;
```
- **Connecting Odd and Even Lists**: After the loop ends, all odd nodes are linked together and all even nodes are linked together. Now, we connect the last odd node to the head of the even list.

```cpp
return head;
```
- **Return the Rearranged List**: Finally, we return the head of the rearranged list, which starts with the odd indexed nodes followed by the even indexed ones.

---

### 📈 Complexity Analysis

#### ⏱️ Time Complexity:
- **O(n)**: We only traverse the linked list once, with each node being processed exactly once. Therefore, the time complexity is **O(n)**, where `n` is the number of nodes in the linked list.

#### 💾 Space Complexity:
- **O(1)**: We only use a constant amount of extra space for the `odd`, `even`, and `ehead` pointers, and do not create any additional data structures. Thus, the space complexity is **O(1)**.

---

### 🏁 Conclusion

This approach solves the problem of rearranging a singly linked list in a very efficient manner. The key idea is to use two pointers — one for odd indexed nodes and one for even indexed nodes — and traverse the list only once. By doing this in-place, we achieve **O(n)** time complexity and **O(1)** space complexity, making it both time-efficient and space-efficient.

---

### 🔥 Key Takeaways
- **Time complexity**: O(n)
- **Space complexity**: O(1)
- The solution is efficient and suitable for large linked lists.

Great job reaching the end! 🎉 Keep practicing and refining your problem-solving skills. You'll master these concepts in no time! 😄

[`Link to LeetCode Lab`](https://leetcode.com/problems/odd-even-linked-list/description/)

---
{{< youtube HaoudL9xEHA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

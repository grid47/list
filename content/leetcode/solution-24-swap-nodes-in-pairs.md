
+++
authors = ["grid47"]
title = "Leetcode 24: Swap Nodes in Pairs"
date = "2024-11-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 24: Swap Nodes in Pairs in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Linked List","Recursion"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/24.webp"
youtube = "o811TZLAWOo"
youtube_upload_date="2020-12-31"
youtube_thumbnail="https://i.ytimg.com/vi/o811TZLAWOo/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/24.webp" 
    alt="Two floating nodes gently exchanging places, glowing with subtle motion."
    caption="Solution to LeetCode 24: Swap Nodes in Pairs Problem"
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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        
        
        ListNode* cur = head, *nxt = head->next, *ret = nxt, *prv = NULL;
        
        while(cur != NULL && nxt != NULL) {
            if(prv != NULL) prv->next = nxt;
            prv = cur;            
            cur->next = nxt->next;
            nxt->next = cur;
            cur = cur->next;
            if(cur != NULL) nxt = cur->next;
        }
        return ret;
    }
};
{{< /highlight >}}
---

### 🌟 **Swapping Every Two Adjacent Nodes in a Linked List**

This problem is a fun and practical exercise to manipulate linked lists. The goal is to swap every two adjacent nodes in a singly linked list. If the list contains an odd number of nodes, the last node stays as it is.

---

#### 🧠 **The Simple Idea**

Imagine you’re working with a chain of nodes, and you want to swap every two neighboring links. The challenge is to do this efficiently, without losing track of any part of the list.

#### 👇 **Steps to Solve the Problem:**

1. **Check Base Cases**  
   If the list is empty or contains only one node, there’s no need for any swaps. Just return the list as it is. ✋

2. **Set up the Pointers**  
   We’ll need a few pointers to help with the swaps:  
   - `cur`: Points to the current node.
   - `nxt`: Points to the next node.
   - `prv`: Keeps track of the previous node (to link the swapped nodes).

3. **Iterate Through the List**  
   Start at the beginning, and swap every two adjacent nodes:  
   - Link the previous node (`prv`) to the new first node of the swapped pair.
   - Make sure to update the `next` pointers after each swap so we don’t lose any nodes. 🔄

4. **Handle Edge Cases**  
   When you reach the last pair (if there’s an odd number of nodes), leave it as it is and return the modified list.

---

#### 🛠 **Breaking Down the Code:**

1. **Handle Edge Cases Early**  
   ```cpp
   if (head == NULL || head->next == NULL) return head;
   ```
   If the list is empty or has only one node, no swaps are needed. This is a simple check to save unnecessary work. 👍

2. **Initialize the Pointers**  
   ```cpp
   ListNode* cur = head, *nxt = head->next, *ret = nxt, *prv = NULL;
   ```
   - `cur` starts at the first node.
   - `nxt` starts at the second node (we’ll swap these first!).
   - `prv` is `NULL` at first, as there’s no previous node yet. But we'll use it to maintain the link after the swap.

3. **Iterate and Swap**  
   ```cpp
   while(cur != NULL && nxt != NULL) {
       if(prv != NULL) prv->next = nxt;
       prv = cur;
       cur->next = nxt->next;
       nxt->next = cur;
       cur = cur->next;
       if(cur != NULL) nxt = cur->next;
   }
   ```
   - First, check if both `cur` and `nxt` are valid. If not, we're done with the list.
   - Swap the nodes by adjusting the `next` pointers:
     - `cur->next = nxt->next`: Make `cur` point to the node after `nxt`.
     - `nxt->next = cur`: Point `nxt` to `cur`, completing the swap.
   - Move `cur` and `nxt` forward to the next pair, and repeat until done.

4. **Return the Modified List**  
   ```cpp
   return ret;
   ```
   The new head of the list is now stored in `ret`, which points to the second node from the original list (after the first swap).

---

#### ⏳ **Complexity Breakdown**

- **Time Complexity: O(n)**  
  We traverse the list once, and each swap operation takes constant time. Hence, the overall time complexity is linear, **O(n)**, where `n` is the number of nodes in the list. 🏃‍♀️

- **Space Complexity: O(1)**  
  We use a fixed amount of extra space to keep track of the pointers. No extra data structures are used, so the space complexity is constant. 🎯

---

#### 💡 **Why This Approach Works**

- **One Pass, Efficient**: By modifying the `next` pointers in a single traversal, we achieve the desired swaps without needing to traverse the list multiple times.
- **Simplicity in Design**: The use of a few simple pointers (`cur`, `nxt`, `prv`) allows us to swap nodes effectively without complicated logic. Practice makes perfect, and this approach keeps it simple and clean.

---

#### 🚀 **Conclusion**

Swapping adjacent nodes in a linked list may seem tricky at first, but with the right approach and a bit of pointer manipulation, it becomes a straightforward task! 🎉

- **Key Takeaways**:
  - Efficiently swapping nodes in one pass is the key to keeping this problem in **O(n)** time.
  - Always remember to handle edge cases like empty lists or single-node lists right away.
  - This approach is space-efficient (**O(1)**), so it works well even for large lists!

By mastering this technique, you’ll be able to solve similar linked list problems with ease. Happy coding! 💻

[`Link to LeetCode Lab`](https://leetcode.com/problems/swap-nodes-in-pairs/description/)

---
{{< youtube o811TZLAWOo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

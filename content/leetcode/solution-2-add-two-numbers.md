
+++
authors = ["grid47"]
title = "Leetcode 2: Add Two Numbers"
date = "2024-11-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2: Add Two Numbers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Linked List","Math","Recursion"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/2.webp"
youtube = "wgFPrzTjm7s"
youtube_upload_date="2020-08-18"
youtube_thumbnail="https://i.ytimg.com/vi/wgFPrzTjm7s/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/2.webp" 
    alt="Two radiant number paths merging into one continuous light beam, symbolizing addition."
    caption="Solution to LeetCode 2: Add Two Numbers Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* tail = head;
        int rm = 0;

        while (l1 != NULL || l2 != NULL || rm != 0) {
            int no1 = (l1 != NULL) ? l1->val : 0;
            int no2 = (l2 != NULL) ? l2->val : 0;

            int sum = no1 + no2 + rm;
            int digit = sum % 10;
            rm = sum / 10;

            ListNode* nxt = new ListNode(digit);
            tail->next = nxt;
            tail = tail->next;

            l1 = (l1 != NULL) ? l1->next : NULL;
            l2 = (l2 != NULL) ? l2->next : NULL;
        }

        ListNode* res = head->next;
        delete head;
        return res;
    }
};
{{< /highlight >}}
---

### 💡 **Add Two Numbers Problem** – Let's Solve It Together!

The **Add Two Numbers** problem is a classic linked list challenge that is both intuitive and powerful. In this problem, **two numbers are represented by linked lists** in reverse order, and the task is to **add these numbers** and return the sum as a linked list in the same reverse order. Let’s dive into how to tackle this step by step!

### 📝 **Problem Statement**

You are given:
- **Two linked lists, `l1` and `l2`**, where each node contains a single digit of a non-negative integer, stored in reverse order. This means the **least significant digit** is at the head of the list.
- The goal is to **add these two numbers** and return the result as a linked list, also in reverse order.

### 🔍 **Plan and Approach: Adding Digit by Digit with Carry**

We’ll use a method that mirrors manual addition:
1. **Traverse both linked lists**: We’ll add corresponding digits from `l1` and `l2`, handling any remaining digits if the lists are of different lengths.
2. **Carry management**: Keep track of any carry-over from each addition, carrying it to the next higher digit.
3. **Build the result list**: As we sum digits, we’ll build the result list node-by-node in reverse order, just like the input format.

### Step-by-Step Solution

#### Step 1: Initialize Variables

```cpp
ListNode* head = new ListNode(0);  // Dummy node to start the result list
ListNode* tail = head;
int carry = 0;
```

- `head` acts as a dummy node to simplify list operations.
- `tail` will point to the last node in our result list, making it easy to append new nodes.
- `carry` will store any overflow value from each digit addition.

#### Step 2: Traverse and Add Corresponding Digits

```cpp
while (l1 != NULL || l2 != NULL || carry != 0) {
    int no1 = (l1 != NULL) ? l1->val : 0;
    int no2 = (l2 != NULL) ? l2->val : 0;

    int sum = no1 + no2 + carry;
    int digit = sum % 10;
    carry = sum / 10;

    ListNode* nxt = new ListNode(digit);
    tail->next = nxt;
    tail = tail->next;

    l1 = (l1 != NULL) ? l1->next : NULL;
    l2 = (l2 != NULL) ? l2->next : NULL;
}
```

- We loop while there are remaining digits in `l1` or `l2`, or there’s a carry left.
- For each iteration:
  - Get the value of each list’s current node (`0` if the list has ended).
  - Compute `sum` as the total of these values plus the carry.
  - Extract the resulting `digit` (sum modulo 10) and update `carry` (sum divided by 10).
  - Append `digit` to our result list and advance pointers.

#### Step 3: Return the Result List

```cpp
ListNode* res = head->next;
delete head;
return res;
```

- After the loop, `head->next` points to the result list, skipping the dummy node.
- We delete the dummy node to prevent memory leaks.
- The resulting list represents the sum, stored in reverse order.

### 🌟 **Handling Edge Cases**

- **Different Lengths**: If one list is shorter, its remaining nodes are considered `0`.
- **Final Carry**: If there’s still a carry after processing both lists, a new node with this carry value is appended.

### ⏱️ **Understanding Time and Space Complexity**

- **Time Complexity**: **O(max(m, n))**, where `m` and `n` are the lengths of `l1` and `l2`. We iterate through each node once, resulting in linear time complexity.
- **Space Complexity**: **O(max(m, n))** for storing the result list, with an additional node if there’s a carry at the end.

### 💡 **Why This Approach Works Well**

This solution mimics manual addition closely and is both efficient and intuitive. The dummy node simplifies list construction, avoiding special cases for the head of the list. By following a structured approach, we maintain clean and readable code.

### 🏁 **You Got This!**

With each problem, you’re building your coding expertise and strengthening your problem-solving skills. Linked list problems may seem tricky, but practice makes perfect. Keep going, coder, and remember that every challenge is a step closer to mastery! 🚀

---

#### 🌟 **Final Thoughts**: Keep Coding, Keep Growing!

Solving coding problems like these adds new skills to your coding toolkit. Stay focused, keep learning, and celebrate every bit of progress. Happy coding, and remember: each problem solved is a step forward! 🌱💪✨

[`Link to LeetCode Lab`](https://leetcode.com/problems/add-two-numbers/description/)

---
{{< youtube wgFPrzTjm7s >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

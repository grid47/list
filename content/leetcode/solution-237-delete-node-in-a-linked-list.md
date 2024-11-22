
+++
authors = ["grid47"]
title = "Leetcode 237: Delete Node in a Linked List"
date = "2024-10-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 237: Delete Node in a Linked List in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Linked List"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/237.webp"
youtube = "sW8ZaOTtvgI"
youtube_upload_date="2020-02-01"
youtube_thumbnail="https://i.ytimg.com/vi_webp/sW8ZaOTtvgI/maxresdefault.webp"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/237.webp" 
    alt="A linked list where a node gently fades away, leaving a cleaner structure behind."
    caption="Solution to LeetCode 237: Delete Node in a Linked List Problem"
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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        
        auto nxt = node->next;
        *node = *nxt;
        delete nxt;
    }
};
{{< /highlight >}}
---

### 🚀 Problem Statement

In this problem, you're given a **singly linked list**, and your task is to delete a specific node, but there’s a twist: you're only given access to the node to be deleted. Normally, to delete a node, you'd need access to the previous node to adjust its `next` pointer. But here, you're restricted to working with just the node you're given, and you need to figure out how to delete it.

Each node in the list is represented by the following structure:

```cpp
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};
```

Your goal is to delete the node without having access to the previous node. Let’s dive into the approach to tackle this!

---

### 🧠 Approach

So, how can we delete a node if we don’t have the luxury of modifying the previous node's `next` pointer? 🤔 Here’s a clever solution:

1. **Node Copying**:
    - Instead of trying to remove the node directly, we can *copy the value* from the next node into the current node. This effectively "overwrites" the current node, making it the next node, so it’s as if the current node has been deleted.
    
2. **Update the Next Pointer**:
    - After copying the value, we need to make sure the `next` pointer of the current node skips the next node.
    - So, we update the `next` pointer to point to the node after the next one, effectively removing the next node from the list.

3. **Delete the Next Node**:
    - Once the current node has taken the place of the next node, we delete the next node. The job is done, and the node has been removed!

---

### 🔨 Step-by-Step Code Breakdown

Let’s look at how this approach works in code!

```cpp
class Solution {
public:
    void deleteNode(ListNode* node) {
```
- Here we define the function `deleteNode` in the `Solution` class, taking a pointer to the node that needs to be deleted.

```cpp
        auto nxt = node->next;
```
- First, we store the pointer to the next node (`nxt`). This helps us manipulate the next node while working on the current one.

```cpp
        *node = *nxt;
```
- We copy the entire contents (value and `next` pointer) of the next node into the current node. This effectively "moves" the next node into the current position, as if the current node has been deleted.

```cpp
        delete nxt;
```
- Finally, we delete the next node (which is now redundant because its value has already been copied into the current node). This cleans up the memory.

```cpp
    }
};
```
- The function ends here, and the node has been deleted successfully!

---

### 📈 Complexity Analysis

#### Time Complexity:
- **O(1)** — The solution works in constant time! We’re only copying values and deleting a node, no matter how large the list is. These operations don’t depend on the size of the list, so we get a **constant time** complexity.

#### Space Complexity:
- **O(1)** — We’re using a fixed amount of extra space, which doesn’t grow with the size of the input. Just a couple of pointers are used, so the space complexity is constant.

---

### 🏁 Conclusion

This solution is efficient and clever! 🎉 By copying the value from the next node and adjusting the `next` pointer, we can "delete" a node without needing access to the previous one. Here’s a quick recap:

1. **Node Copying**: Copy the value from the next node into the current node.
2. **Next Pointer Update**: Adjust the `next` pointer to skip the next node.
3. **Delete the Next Node**: Delete the next node since its value is now in the current node.

It’s an elegant solution that works in **constant time** and **constant space**, making it a fantastic approach for this problem. 🚀

#### Key Takeaways:
- This approach works even when you don’t have access to the previous node, which is a tricky situation in a singly linked list.
- The solution is efficient with **O(1)** time and **O(1)** space complexity, making it optimal for this problem.

Now you’re all set to tackle similar problems with confidence! Keep coding and keep learning! ✨

[`Link to LeetCode Lab`](https://leetcode.com/problems/delete-node-in-a-linked-list/description/)

---
{{< youtube sW8ZaOTtvgI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

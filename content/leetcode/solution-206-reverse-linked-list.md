
+++
authors = ["grid47"]
title = "Leetcode 206: Reverse Linked List"
date = "2024-10-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 206: Reverse Linked List in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Linked List","Recursion"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/206.webp"
youtube = "W-EfGB0E_ao"
youtube_upload_date="2020-02-08"
youtube_thumbnail="https://i.ytimg.com/vi/W-EfGB0E_ao/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/206.webp" 
    alt="A linked list where nodes glow and reverse in position, flowing smoothly backward."
    caption="Solution to LeetCode 206: Reverse Linked List Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given the head of a singly linked list, reverse the list and return the new head of the reversed list. You need to reverse the order of the nodes in the list such that the first node becomes the last, the second becomes the second to last, and so on.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is the head node of a singly linked list where each node contains an integer value and a reference to the next node.
- **Example:** `head = [10, 20, 30, 40]`
- **Constraints:**
	- 0 <= The number of nodes in the list <= 5000
	- -5000 <= Node.val <= 5000

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the head of the new reversed list.
- **Example:** `Output: [40, 30, 20, 10]`
- **Constraints:**
	- The returned list must reflect the reversed order of the nodes.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to reverse the linked list and return the head of the newly reversed list.

- Initialize two pointers, one for the current node and one for the previous node (which starts as NULL).
- Iterate through the list while the current node is not NULL.
- For each node, change its next pointer to point to the previous node.
- Move both pointers forward to the next node in the original list.
{{< dots >}}
### Problem Assumptions ✅
- The linked list is well-formed and the input is always valid.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: head = [1, 2, 3, 4, 5]`  \
  **Explanation:** In this example, the original list is [1, 2, 3, 4, 5]. After reversing, the new list becomes [5, 4, 3, 2, 1].

- **Input:** `Input: head = [10, 20, 30]`  \
  **Explanation:** Here, the input list is [10, 20, 30]. After reversing, the result is [30, 20, 10].

- **Input:** `Input: head = []`  \
  **Explanation:** In this case, the input is an empty list, so the output will also be an empty list.

{{< dots >}}
## Approach 🚀
The problem can be solved by reversing the pointers in the list either iteratively or recursively.

### Initial Thoughts 💭
- This is a straightforward problem of manipulating pointers in a singly linked list.
- The iterative approach is generally easier to implement and more space-efficient, as it avoids recursion stack overhead.
{{< dots >}}
### Edge Cases 🌐
- If the list is empty (head is NULL), the reversed list is also NULL.
- For large lists, ensure the algorithm handles the maximum input size (5000 nodes) efficiently.
- If the list contains a single node, it is its own reversal.
- The solution must work within the time limits for both small and large input sizes.
{{< dots >}}
## Code 💻
```cpp
ListNode* reverseList(ListNode* head) {
    ListNode* nxt, *prv = NULL;
    while(head) {
        nxt = head->next;
        head->next = prv;
        prv = head;
        head = nxt;
    }
    return prv;
}
```

This function reverses a singly linked list. It iterates through the list, reassigning each node's `next` pointer to the previous node, effectively reversing the direction of the list until the entire list is reversed.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	ListNode* reverseList(ListNode* head) {
	```
	Define the function `reverseList` that takes a pointer to the head of a singly linked list and returns the reversed list.

2. **Variable Initialization**
	```cpp
	    ListNode* nxt, *prv = NULL;
	```
	Initialize two pointers: `nxt` for storing the next node and `prv` for keeping track of the previous node in the reversed list.

3. **While Loop**
	```cpp
	    while(head) {
	```
	Start a `while` loop to iterate through the linked list as long as the current node `head` is not null.

4. **Next Node Assignment**
	```cpp
	        nxt = head->next;
	```
	Store the next node (`head->next`) in the `nxt` pointer, so it can be used after modifying `head->next`.

5. **Reverse Pointer Assignment**
	```cpp
	        head->next = prv;
	```
	Reverse the direction of the list by pointing the current node’s `next` to the previous node (`prv`).

6. **Move Previous Pointer**
	```cpp
	        prv = head;
	```
	Move the `prv` pointer to the current node, as it will become the previous node in the next iteration.

7. **Move Head Pointer**
	```cpp
	        head = nxt;
	```
	Move the `head` pointer to the next node in the original list (`nxt`) to continue the iteration.

8. **Return Reversed List**
	```cpp
	    return prv;
	```
	Return the `prv` pointer, which now points to the head of the reversed list.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) for all cases, as we need to visit each node once to reverse the list.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) for the iterative approach, as no extra space is needed except for a few pointers.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/reverse-linked-list/description/)

---
{{< youtube W-EfGB0E_ao >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

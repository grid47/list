
+++
authors = ["grid47"]
title = "Leetcode 86: Partition List"
date = "2024-10-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 86: Partition List in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Linked List","Two Pointers"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/86.webp"
youtube = "KT1iUciJr4g"
youtube_upload_date="2021-02-03"
youtube_thumbnail="https://i.ytimg.com/vi_webp/KT1iUciJr4g/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/86.webp" 
    alt="A glowing line dividing a list into two perfect sections."
    caption="Solution to LeetCode 86: Partition List Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given the head of a linked list and a value x, partition the list such that all nodes with values less than x appear before nodes with values greater than or equal to x. The relative order of the nodes in each partition should be preserved.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of the head of a singly linked list and an integer x. The linked list contains nodes with integer values.
- **Example:** `Input: head = [6,2,5,3,8,1], x = 5`
- **Constraints:**
	- The number of nodes in the list is between 0 and 200.
	- -100 <= Node.val <= 100
	- -200 <= x <= 200

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should return the head of the partitioned linked list, where nodes less than x appear first, followed by nodes greater than or equal to x. The relative order of nodes in each partition should be preserved.
- **Example:** `Output: [2,3,1,6,5,8]`
- **Constraints:**
	- The list should maintain the relative order of elements within each partition.

{{< dots >}}
### Core Logic 🔍
**Goal:** To partition the linked list around the given value x such that all nodes with values less than x come before those with values greater than or equal to x, preserving the original order of the nodes.

- Create two separate lists: one for values less than x, and one for values greater than or equal to x.
- Traverse the original list, and for each node, append it to the appropriate list based on its value.
- Once the traversal is complete, merge the two lists by connecting the last node of the first list to the head of the second list.
{{< dots >}}
### Problem Assumptions ✅
- The input list will always be a valid linked list with the specified range of values.
- The partitioning will maintain the relative order of nodes within each partition.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: head = [6,2,5,3,8,1], x = 5`  \
  **Explanation:** The list is partitioned into nodes less than 5 (2, 3, 1) and nodes greater than or equal to 5 (6, 5, 8), maintaining their relative order.

- **Input:** `Input: head = [4, 2, 7, 3], x = 5`  \
  **Explanation:** Nodes less than 5 (4, 2, 3) appear first, followed by nodes greater than or equal to 5 (7). The relative order of each partition is preserved.

{{< dots >}}
## Approach 🚀
To solve the problem, we create two separate linked lists: one for nodes with values less than x, and one for nodes with values greater than or equal to x. After traversing the input list, we merge these two lists together to form the final partitioned list.

### Initial Thoughts 💭
- We can easily partition the list by separating the nodes into two lists based on their value relative to x.
- The challenge is to ensure that the relative order of nodes in each partition is maintained.
- By iterating through the original list and adding nodes to two new lists, we can preserve the order and later merge the lists together.
{{< dots >}}
### Edge Cases 🌐
- If the input linked list is empty (head is null), the output should also be null.
- Ensure the solution can handle up to 200 nodes efficiently.
- If all nodes have values less than x or greater than or equal to x, the list should still maintain its relative order.
- The solution must not modify the relative order of nodes within each partition.
{{< dots >}}
## Code 💻
```cpp
ListNode* partition(ListNode* head, int x) {
    ListNode *dummy1 = new ListNode(0), *dummy2 = new ListNode(0);
    ListNode *p1 = dummy1, *p2 = dummy2;

    while (head) {
        if (head->val < x) {
            p1->next = head;
            p1 = p1->next;
        } else {
            p2->next = head;
            p2 = p2->next;
        }
        head = head->next;
    }

    p2->next = nullptr;
    p1->next = dummy2->next;
    return dummy1->next;
}
```

This code partitions a linked list around a given value `x`. Nodes with values less than `x` come before nodes with values greater than or equal to `x`.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	ListNode* partition(ListNode* head, int x) {
	```
	Declares a function `partition` that takes a linked list `head` and a pivot value `x` as input and returns the head of the partitioned list.

2. **Variable Initialization**
	```cpp
	    ListNode *dummy1 = new ListNode(0), *dummy2 = new ListNode(0);
	```
	Creates two dummy nodes `dummy1` and `dummy2` to act as the heads of two new lists: one for nodes less than `x` and one for nodes greater than or equal to `x`.

3. **Variable Initialization**
	```cpp
	    ListNode *p1 = dummy1, *p2 = dummy2;
	```
	Initializes pointers `p1` and `p2` to point to the dummy nodes.

4. **Loop Iteration**
	```cpp
	    while (head) {
	```
	Iterates through the original linked list.

5. **Conditional**
	```cpp
	        if (head->val < x) {
	```
	Checks if the current node's value is less than `x`.

6. **Node Manipulation**
	```cpp
	            p1->next = head;
	```
	Appends the current node to the first list.

7. **Pointer Update**
	```cpp
	            p1 = p1->next;
	```
	Moves the `p1` pointer to the next node in the first list.

8. **Conditional**
	```cpp
	        } else {
	```
	If the current node's value is greater than or equal to `x`.

9. **Node Manipulation**
	```cpp
	            p2->next = head;
	```
	Appends the current node to the second list.

10. **Pointer Update**
	```cpp
	            p2 = p2->next;
	```
	Moves the `p2` pointer to the next node in the second list.

11. **Pointer Update**
	```cpp
	        head = head->next;
	```
	Moves to the next node in the original linked list.

12. **Node Manipulation**
	```cpp
	    p2->next = nullptr;
	```
	Sets the `next` pointer of the last node in the second list to `null`.

13. **Node Manipulation**
	```cpp
	    p1->next = dummy2->next;
	```
	Connects the two lists by setting the `next` pointer of the last node in the first list to the head of the second list.

14. **Return**
	```cpp
	    return dummy1->next;
	```
	Returns the head of the partitioned list, which is the `next` node of `dummy1`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the number of nodes in the list. We perform a single pass through the list.
- **Average Case:** O(n)
- **Worst Case:** O(n), since we traverse the list once and then merge the partitions.

The time complexity is linear because we iterate through the list once to partition the nodes.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n), where n is the number of nodes in the list, as we create two new lists to hold the partitions.

The space complexity is linear due to the need to store the two partitioned lists.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/partition-list/description/)

---
{{< youtube KT1iUciJr4g >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

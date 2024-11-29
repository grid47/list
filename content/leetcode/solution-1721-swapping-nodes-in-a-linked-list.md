
+++
authors = ["grid47"]
title = "Leetcode 1721: Swapping Nodes in a Linked List"
date = "2024-05-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1721: Swapping Nodes in a Linked List in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Linked List","Two Pointers"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "KUTRaNOzmoo"
youtube_upload_date="2023-05-15"
youtube_thumbnail="https://i.ytimg.com/vi/KUTRaNOzmoo/maxresdefault.jpg"
comments = true
+++



---
You are given a singly linked list and an integer k. The task is to swap the values of the kth node from the beginning of the list with the kth node from the end of the list. The list is 1-indexed.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given the head of a singly linked list and an integer k.
- **Example:** `Input: head = [1,2,3,4,5], k = 2`
- **Constraints:**
	- 1 <= k <= n <= 10^5
	- 0 <= Node.val <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the modified linked list after swapping the kth node from the beginning with the kth node from the end.
- **Example:** `Output: [1,4,3,2,5]`
- **Constraints:**
	- The list will contain at least k nodes.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to swap the values of the kth node from the beginning and the kth node from the end using two pointers.

- 1. Initialize two pointers: one starting from the head of the list and the other starting from the end of the list.
- 2. Traverse the list to locate the kth node from the beginning and the kth node from the end.
- 3. Swap the values of these two nodes.
- 4. Return the head of the modified list.
{{< dots >}}
### Problem Assumptions ✅
- The input list is non-empty and contains at least `k` nodes.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: head = [1, 2, 3, 4, 5], k = 2`  \
  **Explanation:** The kth node from the beginning is 2 and the kth node from the end is 4. Swapping their values results in the list [1, 4, 3, 2, 5].

- **Input:** `Input: head = [7, 9, 6, 6, 7, 8, 3, 0, 9, 5], k = 5`  \
  **Explanation:** The kth node from the beginning is 7 and the kth node from the end is also 7. Swapping their values does not change the list, so the output is [7, 9, 6, 6, 8, 7, 3, 0, 9, 5].

{{< dots >}}
## Approach 🚀
The approach involves using two pointers to locate the kth node from both the start and the end of the list. After locating both nodes, their values are swapped.

### Initial Thoughts 💭
- This problem can be solved by finding the kth node from the start and the kth node from the end in a single traversal of the list.
- To find the kth node from the end, we need to traverse the list from the beginning and find the kth node from the start, then use the length of the list to locate the kth node from the end.
{{< dots >}}
### Edge Cases 🌐
- An empty linked list is not a valid input for this problem as it will not contain any nodes.
- The solution should be efficient enough to handle lists with up to 10^5 nodes.
- If `k` is equal to the length of the list, the kth node from the beginning is the last node in the list, and the kth node from the end is the first node.
- The linked list will always contain at least `k` nodes.
{{< dots >}}
## Code 💻
```cpp
ListNode* swapNodes(ListNode* head, int k) {
    ListNode* n1 = nullptr, *n2 = nullptr;
    for(ListNode *p = head; p != nullptr; p = p->next) {
        n2 = n2 == nullptr? nullptr: n2->next;
        if(--k == 0) {
            n1 = p;
            n2 = head;
        }
    }
    swap(n2->val, n1->val);
    return head;
}
```

This function `swapNodes` swaps the values of the k-th node from the beginning and the k-th node from the end of a singly linked list. It uses two pointers to find the nodes and then swaps their values.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	ListNode* swapNodes(ListNode* head, int k) {
	```
	The function `swapNodes` is declared, which takes a pointer to the head of the linked list (`head`) and an integer `k` representing the position of the node to swap.

2. **Pointer Initialization**
	```cpp
	    ListNode* n1 = nullptr, *n2 = nullptr;
	```
	Two pointers `n1` and `n2` are initialized to `nullptr`. `n1` will point to the k-th node from the beginning, and `n2` will eventually point to the k-th node from the end.

3. **Traversal Loop**
	```cpp
	    for(ListNode *p = head; p != nullptr; p = p->next) {
	```
	A loop is started to traverse the entire linked list using the pointer `p`, starting from the head.

4. **Move `n2` Pointer**
	```cpp
	        n2 = n2 == nullptr? nullptr: n2->next;
	```
	If `n2` is not yet initialized (i.e., `n2` is `nullptr`), it remains `nullptr`. Once `n2` is initialized, it moves one node forward in each iteration.

5. **Condition Check**
	```cpp
	        if(--k == 0) {
	```
	The integer `k` is decremented, and when it becomes zero, the pointer `n1` points to the k-th node from the beginning of the list. The pointer `n2` is also set to the head of the list to start its traversal.

6. **Assign `n1` Node**
	```cpp
	            n1 = p;
	```
	Once `k` reaches zero, the pointer `n1` is assigned to the current node `p`, which is the k-th node from the beginning.

7. **Initialize `n2` to Head**
	```cpp
	            n2 = head;
	```
	The pointer `n2` is reset to point to the head of the linked list to start searching for the k-th node from the end.

8. **Swap Node Values**
	```cpp
	    swap(n2->val, n1->val);
	```
	The values of the nodes pointed to by `n2` and `n1` are swapped using the `swap` function.

9. **Return Statement**
	```cpp
	    return head;
	```
	The function returns the head of the modified linked list, with the values of the k-th nodes swapped.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the number of nodes in the list.
- **Average Case:** O(n), as we traverse the list once to determine the length and perform the swap.
- **Worst Case:** O(n), as the solution requires a single traversal of the list.

The time complexity is linear in the size of the linked list.

### Space Complexity 💾
- **Best Case:** O(1), as the space usage does not depend on the size of the list.
- **Worst Case:** O(1), as no additional space is required other than for the pointers and swapping the values.

The space complexity is constant, as the solution only uses a fixed amount of space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/swapping-nodes-in-a-linked-list/description/)

---
{{< youtube KUTRaNOzmoo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

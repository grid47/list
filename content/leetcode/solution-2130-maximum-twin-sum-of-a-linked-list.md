
+++
authors = ["grid47"]
title = "Leetcode 2130: Maximum Twin Sum of a Linked List"
date = "2024-04-08"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2130: Maximum Twin Sum of a Linked List in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Linked List","Two Pointers","Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "FnKG0uH2PVc"
youtube_upload_date="2023-05-18"
youtube_thumbnail="https://i.ytimg.com/vi/FnKG0uH2PVc/maxresdefault.jpg"
comments = true
+++



---
You are given a linked list with an even number of nodes. Each node in the list has a twin located symmetrically from the center of the list. Specifically, the ith node is the twin of the (n-1-i)th node, where n is the total number of nodes in the list. For example, the first node is the twin of the last node, the second node is the twin of the second last node, and so on. The twin sum is defined as the sum of a node and its twin. Your task is to return the maximum twin sum of the linked list.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given the head of a singly linked list with an even number of nodes.
- **Example:** `head = [3, 1, 4, 2]`
- **Constraints:**
	- The number of nodes in the list is even.
	- 1 <= Node.val <= 10^5.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum twin sum, which is the largest sum of a node and its twin in the linked list.
- **Example:** `Input: head = [3, 1, 4, 2] Output: 6`
- **Constraints:**
	- The solution should return a single integer representing the maximum twin sum.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to calculate the twin sum for all possible pairs of nodes and return the maximum sum.

- 1. Use two pointers, slow and fast, to find the middle of the linked list.
- 2. Reverse the second half of the list starting from the slow pointer.
- 3. Calculate the twin sum by adding the corresponding nodes from the first and second halves.
- 4. Keep track of the maximum twin sum while traversing the two halves.
{{< dots >}}
### Problem Assumptions ✅
- The list has at least two nodes.
- There is no need to handle odd-length lists.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: head = [3, 1, 4, 2]`  \
  **Explanation:** In this case, the first node (3) and the last node (2) form a twin pair with a sum of 5. Similarly, the second node (1) and the third node (4) form another twin pair with a sum of 5. The maximum twin sum is 6.

- **Input:** `Input: head = [5, 3, 7, 4]`  \
  **Explanation:** The first node (5) and the last node (4) form a twin pair with a sum of 9. The second node (3) and the third node (7) form a twin pair with a sum of 10. Therefore, the maximum twin sum is 10.

{{< dots >}}
## Approach 🚀
The approach to solving this problem involves finding the middle of the linked list, reversing the second half, and then calculating the twin sums.

### Initial Thoughts 💭
- We need to reverse the second half of the linked list and calculate the twin sums with the first half.
- By using a slow and fast pointer approach, we can efficiently find the middle of the list, then reverse the second half and calculate the twin sums in a single pass.
{{< dots >}}
### Edge Cases 🌐
- This problem does not require handling for empty lists as it is guaranteed that the number of nodes is even and at least 2.
- Ensure that the solution can handle linked lists with a large number of nodes, up to the limit of 10^5 nodes.
- The value of each node can range from 1 to 10^5, so ensure that the sums are calculated correctly for large numbers.
- The solution must be efficient enough to handle large inputs within the time limits.
{{< dots >}}
## Code 💻
```cpp
int pairSum(ListNode* head) {
    
    ListNode* slow = head, *fast = head;
    while(slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    /*
    
    if its a even chain fast pointer will go out of index
    slow will reach at second of middle elements or first of second half of the chain
    
    */
    
    ListNode *cur = slow, *prv = NULL, *nxt;
    
    while(cur) {
        nxt = cur->next;
        cur->next = prv;
        prv = cur;
        cur = nxt;
    }
    
    int res = 0;
    while(prv) {
        res = max(res, head->val + prv->val);
        head = head->next;
        prv = prv->next;
    }
    return res;
}
```

This function calculates the maximum pair sum of a singly linked list by splitting it into two halves and then finding the maximum sum of corresponding elements from each half.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Declaration**
	```cpp
	int pairSum(ListNode* head) {
	```
	Function declaration for pairSum, which takes the head of a linked list and returns an integer.

2. **Pointer Setup**
	```cpp
	    ListNode* slow = head, *fast = head;
	```
	Two pointers (slow and fast) are initialized to the head of the linked list to find the middle.

3. **Loop Setup**
	```cpp
	    while(slow && fast && fast->next) {
	```
	A while loop to move the slow pointer one step and the fast pointer two steps to find the middle of the list.

4. **Pointer Movement**
	```cpp
	        slow = slow->next;
	```
	Move the slow pointer one step forward.

5. **Pointer Movement**
	```cpp
	        fast = fast->next->next;
	```
	Move the fast pointer two steps forward.

6. **Reversal Initialization**
	```cpp
	    ListNode *cur = slow, *prv = NULL, *nxt;
	```
	Initialize three pointers: cur to slow (start of second half), prv as NULL, and nxt to help in reversing the list.

7. **Loop Setup**
	```cpp
	    while(cur) {
	```
	Start of a loop to reverse the second half of the linked list.

8. **Pointer Movement**
	```cpp
	        nxt = cur->next;
	```
	Store the next node of cur to help in the reversal process.

9. **Pointer Update**
	```cpp
	        cur->next = prv;
	```
	Reverse the pointer of the current node to point to the previous node.

10. **Pointer Movement**
	```cpp
	        prv = cur;
	```
	Move the previous pointer to the current node.

11. **Pointer Movement**
	```cpp
	        cur = nxt;
	```
	Move the current pointer to the next node.

12. **Result Initialization**
	```cpp
	    int res = 0;
	```
	Initialize the result variable to 0, which will store the maximum pair sum.

13. **Loop Setup**
	```cpp
	    while(prv) {
	```
	Start of a while loop to find the maximum pair sum.

14. **Max Calculation**
	```cpp
	        res = max(res, head->val + prv->val);
	```
	Calculate the sum of the current nodes from both halves and update the result with the maximum value.

15. **Pointer Movement**
	```cpp
	        head = head->next;
	```
	Move the head pointer to the next node in the first half of the list.

16. **Pointer Movement**
	```cpp
	        prv = prv->next;
	```
	Move the prv pointer to the next node in the second half of the list.

17. **Return**
	```cpp
	    return res;
	```
	Return the computed result, which is the maximum pair sum.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because we traverse the list at most twice, where n is the number of nodes in the linked list.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) because we are only using a constant amount of extra space, aside from the input list itself.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/description/)

---
{{< youtube FnKG0uH2PVc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

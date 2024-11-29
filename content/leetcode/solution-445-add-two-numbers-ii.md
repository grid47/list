
+++
authors = ["grid47"]
title = "Leetcode 445: Add Two Numbers II"
date = "2024-09-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 445: Add Two Numbers II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Linked List","Math","Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/445.webp"
youtube = "ovGnWmf2sew"
youtube_upload_date="2021-04-14"
youtube_thumbnail="https://i.ytimg.com/vi/ovGnWmf2sew/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/445.webp" 
    alt="Two linked lists gently adding their digits, with each addition softly illuminated as it occurs."
    caption="Solution to LeetCode 445: Add Two Numbers II Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given two non-empty linked lists where each node contains a single digit representing a non-negative integer. Add the two numbers and return the sum as a linked list, ensuring the most significant digit is at the head of the list.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** Each linked list represents a number where each node contains a single digit. The lists do not have leading zeros, except for the number 0 itself.
- **Example:** `[3,4,2], [6,5,7]`
- **Constraints:**
	- 1 <= Number of nodes in each linked list <= 100
	- Node.val >= 0 and Node.val <= 9
	- No leading zeros in the numbers except for 0 itself

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a linked list representing the sum of the two numbers with the most significant digit at the head.
- **Example:** `[9,0,0,9]`
- **Constraints:**
	- The result linked list must be formatted in the same way as the input.

{{< dots >}}
### Core Logic 🔍
**Goal:** Add two numbers represented by two linked lists and return the sum as a linked list.

- 1. Use two stacks to store the digits of the linked lists as we traverse them.
- 2. Pop the digits from the stacks, add them with the carry, and create new nodes to store the result.
- 3. If a carry exists after processing both lists, create a new node for the carry.
- 4. Ensure that the final linked list is built without reversing the input lists.
{{< dots >}}
### Problem Assumptions ✅
- The linked lists are not empty and contain valid digits.
{{< dots >}}
## Examples 🧩
- **Input:** `[3,4,2], [6,5,7]`  \
  **Explanation:** The two numbers are 342 and 657. Their sum is 999, which is represented as [9, 0, 0, 9].

- **Input:** `[1,2], [3,4,5]`  \
  **Explanation:** The two numbers are 12 and 345. Their sum is 357, represented as [3, 5, 7].

{{< dots >}}
## Approach 🚀
This problem can be solved by simulating the addition process using stacks to reverse the linked lists and adding corresponding digits along with a carry.

### Initial Thoughts 💭
- The problem asks to avoid reversing the linked lists, which suggests using a stack to reverse the order temporarily.
- We can use two stacks to simulate the addition process from the most significant digit to the least significant digit.
{{< dots >}}
### Edge Cases 🌐
- If any linked list is empty, it should be treated as 0.
- For larger inputs (up to 100 nodes), ensure that the solution handles the carry correctly and efficiently.
- Consider cases where the numbers involve carry overs, such as adding [9,9] and [1].
- Ensure that the algorithm runs in O(n) time and uses O(n) space for stack operations.
{{< dots >}}
## Code 💻
```cpp
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    stack<int> s1, s2;
    
    while(l1) {
        s1.push(l1->val);
        l1 = l1->next;
    }
    
    while(l2) {
        s2.push(l2->val);
        l2 = l2->next;
    }
    
    int cry = 0;
    
    ListNode* node = NULL, *prv = NULL;
    
    while(!s1.empty() || !s2.empty()) {
        
        if(!s1.empty()) {
            cry += s1.top();
            s1.pop();
        }

        if(!s2.empty()) {
            cry += s2.top();
            s2.pop();
        }
        
        node = new ListNode(cry % 10);
        node->next = prv;
        
        prv = node;
        cry /= 10;
        
    }
    
    if(cry != 0) {
        node = new ListNode(cry %10);
        node->next = prv;
        
    }
    
    return node;
}
```

This function adds two numbers represented by two linked lists in reverse order. It utilizes stacks to reverse the linked lists and performs the addition step by step while carrying over the value. Finally, it returns the sum as a new linked list.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	```
	This is the function definition where two linked lists (l1 and l2) are passed as arguments.

2. **Stack Initialization**
	```cpp
	    stack<int> s1, s2;
	```
	Two stacks are created to hold the digits of the two linked lists.

3. **Stack Population (L1)**
	```cpp
	    while(l1) {
	```
	Traverse the first linked list and push each node's value onto stack s1.

4. **Push Operation**
	```cpp
	        s1.push(l1->val);
	```
	Push the current value of the node in l1 onto stack s1.

5. **Linked List Traversal**
	```cpp
	        l1 = l1->next;
	```
	Move to the next node in the first linked list.

6. **Stack Population (L2)**
	```cpp
	    while(l2) {
	```
	Traverse the second linked list and push each node's value onto stack s2.

7. **Push Operation**
	```cpp
	        s2.push(l2->val);
	```
	Push the current value of the node in l2 onto stack s2.

8. **Linked List Traversal**
	```cpp
	        l2 = l2->next;
	```
	Move to the next node in the second linked list.

9. **Carry Initialization**
	```cpp
	    int cry = 0;
	```
	Initialize a variable to store the carry during addition.

10. **Node Initialization**
	```cpp
	    ListNode* node = NULL, *prv = NULL;
	```
	Initialize pointers for the result linked list: node for the current node and prv for the previous node.

11. **Addition Loop**
	```cpp
	    while(!s1.empty() || !s2.empty()) {
	```
	Start the loop to add corresponding digits from the two stacks while there are still elements in either stack.

12. **Addition from S1**
	```cpp
	        if(!s1.empty()) {
	```
	Check if stack s1 is not empty and add its top element to the carry.

13. **Update Carry**
	```cpp
	            cry += s1.top();
	```
	Add the top element of stack s1 to the carry.

14. **Pop Operation**
	```cpp
	            s1.pop();
	```
	Pop the top element of stack s1.

15. **Addition from S2**
	```cpp
	        if(!s2.empty()) {
	```
	Check if stack s2 is not empty and add its top element to the carry.

16. **Update Carry**
	```cpp
	            cry += s2.top();
	```
	Add the top element of stack s2 to the carry.

17. **Pop Operation**
	```cpp
	            s2.pop();
	```
	Pop the top element of stack s2.

18. **Create Node**
	```cpp
	        node = new ListNode(cry % 10);
	```
	Create a new node with the value of the current digit (cry % 10).

19. **Update Node Links**
	```cpp
	        node->next = prv;
	```
	Link the newly created node to the previous node.

20. **Update Previous Node**
	```cpp
	        prv = node;
	```
	Update the previous node pointer to the current node.

21. **Update Carry**
	```cpp
	        cry /= 10;
	```
	Update the carry by dividing it by 10.

22. **Create Final Node**
	```cpp
	    if(cry != 0) {
	```
	Check if there is a remaining carry to create a final node.

23. **Final Carry Node**
	```cpp
	        node = new ListNode(cry %10);
	```
	Create a final node with the carry value.

24. **Update Node Links**
	```cpp
	        node->next = prv;
	```
	Link the final node to the result list.

25. **Return Final Node**
	```cpp
	    return node;
	```
	Return the head of the newly created linked list that represents the sum.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the length of the longer linked list.
- **Average Case:** O(n), as each node is processed once.
- **Worst Case:** O(n), as we process both lists in full.

The time complexity is linear because we traverse each list once.

### Space Complexity 💾
- **Best Case:** O(n), since we still need stacks for the input digits.
- **Worst Case:** O(n), due to the use of two stacks for storing the digits of both lists.

The space complexity is linear because we use stacks to hold the digits before performing the addition.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/add-two-numbers-ii/description/)

---
{{< youtube ovGnWmf2sew >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

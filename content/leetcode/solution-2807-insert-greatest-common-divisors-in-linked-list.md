
+++
authors = ["grid47"]
title = "Leetcode 2807: Insert Greatest Common Divisors in Linked List"
date = "2024-01-31"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2807: Insert Greatest Common Divisors in Linked List in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Linked List","Math","Number Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "SVnSiD95r-0"
youtube_upload_date="2024-04-18"
youtube_thumbnail="https://i.ytimg.com/vi_webp/SVnSiD95r-0/maxresdefault.webp"
comments = true
+++



---
You are given the head of a linked list, where each node contains an integer. For each pair of adjacent nodes, insert a new node with a value equal to the greatest common divisor (GCD) of the two nodes. Return the modified linked list after performing this operation.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a linked list where each node has an integer value. The linked list is represented as a sequence of integers.
- **Example:** `Input: head = [12, 8, 24, 36]`
- **Constraints:**
	- 1 <= Node.val <= 1000
	- The number of nodes in the list is between 1 and 5000.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the linked list after inserting new nodes with the GCD between adjacent nodes.
- **Example:** `Output: [12, 4, 8, 4, 24, 12, 36]`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to iterate through the linked list, compute the GCD of every pair of adjacent nodes, and insert a new node with the GCD value in between them.

- 1. Iterate through the linked list.
- 2. For each pair of adjacent nodes, compute the GCD of their values.
- 3. Create a new node with the GCD value and insert it between the two adjacent nodes.
- 4. Continue this process until the end of the list.
{{< dots >}}
### Problem Assumptions ✅
- The linked list contains at least one node.
- Adjacent nodes will always be present unless the list has only one node.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: head = [12, 8, 24, 36]`  \
  **Explanation:** Between 12 and 8, the GCD is 4. Between 8 and 24, the GCD is 8. Between 24 and 36, the GCD is 12. So, the final linked list is [12, 4, 8, 4, 24, 12, 36].

- **Input:** `Input: head = [5]`  \
  **Explanation:** Since there is only one node in the list, no insertions are made, and the original list remains unchanged.

{{< dots >}}
## Approach 🚀
We will iterate through the list, compute the GCD for each pair of adjacent nodes, and insert the new node with the GCD value between them.

### Initial Thoughts 💭
- The problem is straightforward, involving GCD calculations and linked list manipulation.
- The main challenge lies in correctly inserting the new nodes between existing nodes while maintaining the integrity of the linked list.
{{< dots >}}
### Edge Cases 🌐
- There are no empty inputs, as the list will always have at least one node.
- The function needs to handle up to 5000 nodes, but the logic remains efficient with a linear time complexity.
- If the list contains only one node, no new nodes will be inserted.
- Ensure that all GCD calculations are performed correctly and efficiently for each pair of nodes.
{{< dots >}}
## Code 💻
```cpp
ListNode* insertGreatestCommonDivisors(ListNode* head) {
    
    ListNode* res = head;
    
    while(head && head->next) {
        ListNode* node = new ListNode(__gcd(head->val, head->next->val));
        ListNode* tmp = head->next;
        head->next = node;
        node->next = tmp;
        head = tmp;
    }
    return res;
}
```

This function inserts greatest common divisors (GCDs) between each adjacent pair of nodes in the linked list.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	ListNode* insertGreatestCommonDivisors(ListNode* head) {
	```
	Function definition: Starts the function to insert GCDs into a linked list.

2. **Initialization**
	```cpp
	    ListNode* res = head;
	```
	Initializes a pointer 'res' to keep track of the head of the linked list.

3. **Loop**
	```cpp
	    while(head && head->next) {
	```
	Starts a while loop that continues as long as there are at least two nodes.

4. **GCD Calculation**
	```cpp
	        ListNode* node = new ListNode(__gcd(head->val, head->next->val));
	```
	Creates a new node containing the GCD of the current node and the next node.

5. **Node Manipulation**
	```cpp
	        ListNode* tmp = head->next;
	```
	Stores a temporary reference to the next node in the list.

6. **Node Manipulation**
	```cpp
	        head->next = node;
	```
	Updates the current node to point to the new GCD node.

7. **Node Manipulation**
	```cpp
	        node->next = tmp;
	```
	Sets the next pointer of the GCD node to the original next node.

8. **Pointer Update**
	```cpp
	        head = tmp;
	```
	Moves the 'head' pointer to the next original node for the next iteration.

9. **Return**
	```cpp
	    return res;
	```
	Returns the head of the modified linked list with the inserted GCDs.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) where n is the number of nodes, as we iterate through the list once and perform constant-time GCD calculations for each adjacent pair.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n) due to the extra nodes being inserted into the list.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/description/)

---
{{< youtube SVnSiD95r-0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

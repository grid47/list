
+++
authors = ["grid47"]
title = "Leetcode 2816: Double a Number Represented as a Linked List"
date = "2024-01-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2816: Double a Number Represented as a Linked List in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Linked List","Math","Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "UmqNCKUeIy4"
youtube_upload_date="2023-08-13"
youtube_thumbnail="https://i.ytimg.com/vi/UmqNCKUeIy4/maxresdefault.jpg"
comments = true
+++



---
You are given the head of a non-empty linked list representing a non-negative integer, where each node contains a single digit of the number. Your task is to double the integer represented by the linked list and return the resulting number as a new linked list.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of the head of a non-empty linked list where each node contains a single digit of a number.
- **Example:** `head = [1, 8, 9]`
- **Constraints:**
	- 1 <= number of nodes <= 10^4
	- 0 <= Node.val <= 9
	- The input is generated such that the list represents a number that does not have leading zeros, except the number 0 itself.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the head of the linked list representing the number after doubling it.
- **Example:** `head = [3, 7, 8]`
- **Constraints:**
	- The returned list must correctly represent the doubled number.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to double the number represented by the linked list and return the result as a new linked list.

- 1. Traverse the linked list to calculate the number it represents.
- 2. Double the number.
- 3. Convert the doubled number back into a linked list and return it.
{{< dots >}}
### Problem Assumptions ✅
- The linked list represents a valid number without leading zeros.
{{< dots >}}
## Examples 🧩
- **Input:** `head = [1, 8, 9]`  \
  **Explanation:** The number represented by the linked list is 189. Doubling 189 gives 378, which is returned as the new linked list [3, 7, 8].

{{< dots >}}
## Approach 🚀
We can traverse the linked list to convert it into a number, double it, and then convert the result back into a new linked list.

### Initial Thoughts 💭
- The number can be represented as a sum of digits multiplied by powers of 10.
- It may be beneficial to use a recursive approach to handle the carry during the doubling process.
{{< dots >}}
### Edge Cases 🌐
- The input will never be an empty list as per the constraints.
- For large lists, we must ensure efficient traversal and handling of the doubled number.
- The number 0 should return 0 when doubled.
- The algorithm must handle lists with up to 10^4 nodes efficiently.
{{< dots >}}
## Code 💻
```cpp
int pin(ListNode* head) {
    if(head == NULL) return 0;
    int val = pin(head->next);
    int num = head->val;
    num = num * 2 + val;
    head->val = num % 10;
    return num/10;
}

ListNode* doubleIt(ListNode* head) {
    int num = pin(head);
    while(num > 0) {
        int c = num % 10;
        num /= 10;
        ListNode* node = new ListNode(c);
        node->next = head;
        head = node;
    }
    return head;
}
```

This code defines two functions: `pin`, which recursively processes a linked list to handle digits, and `doubleIt`, which doubles the number represented by a linked list. `pin` carries out the digit manipulation, and `doubleIt` handles list creation with the doubled value.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int pin(ListNode* head) {
	```
	Define the function `pin` which is responsible for traversing the linked list recursively and calculating the carry for doubling the number.

2. **Condition Check**
	```cpp
	    if(head == NULL) return 0;
	```
	Base case of recursion: If the node is NULL, return 0 (no carry).

3. **Recursive Call**
	```cpp
	    int val = pin(head->next);
	```
	Recursively call `pin` to process the next node in the linked list and obtain the carry from the next digit.

4. **Node Processing**
	```cpp
	    int num = head->val;
	```
	Extract the value of the current node.

5. **Computation**
	```cpp
	    num = num * 2 + val;
	```
	Double the current node's value and add the carry from the recursive call.

6. **Update Node**
	```cpp
	    head->val = num % 10;
	```
	Update the current node's value to the unit digit of the doubled number.

7. **Return Carry**
	```cpp
	    return num / 10;
	```
	Return the carry (higher digit) to the previous recursion level.

8. **Function Definition**
	```cpp
	ListNode* doubleIt(ListNode* head) {
	```
	Define the function `doubleIt` which handles doubling the number represented by the linked list.

9. **Call pin**
	```cpp
	    int num = pin(head);
	```
	Call `pin` to get the carry and process the digits of the linked list.

10. **While Loop**
	```cpp
	    while(num > 0) {
	```
	Loop to handle the remaining carry and create new nodes for the doubled number.

11. **Extract Digit**
	```cpp
	        int c = num % 10;
	```
	Extract the unit digit of the carry.

12. **Update Carry**
	```cpp
	        num /= 10;
	```
	Update the carry by removing the processed unit digit.

13. **Create Node**
	```cpp
	        ListNode* node = new ListNode(c);
	```
	Create a new node with the extracted digit.

14. **Insert Node**
	```cpp
	        node->next = head;
	```
	Insert the new node at the beginning of the list (to maintain the correct order of digits).

15. **Update Head**
	```cpp
	        head = node;
	```
	Update the head of the linked list to point to the newly created node.

16. **Return Head**
	```cpp
	    return head;
	```
	Return the head of the updated linked list representing the doubled number.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The solution involves traversing the entire linked list once, making the time complexity O(n), where n is the number of nodes.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) because we need to store the linked list of size n.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/description/)

---
{{< youtube UmqNCKUeIy4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

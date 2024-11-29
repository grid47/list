
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
comments = true
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
You are given two linked lists representing two non-negative integers, where each node contains a single digit, and the digits are stored in reverse order. Your task is to add these two numbers and return the result as a linked list. You can assume that the input does not contain leading zeros except for the number 0 itself.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two linked lists representing integers in reverse order.
- **Example:** `l1 = [1, 2, 3], l2 = [4, 5, 6]`
- **Constraints:**
	- 1 <= number of nodes in each linked list <= 100
	- 0 <= Node.val <= 9
	- The lists represent valid non-negative integers without leading zeros, except for 0 itself.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is a linked list representing the sum of the two input integers in reverse order.
- **Example:** `[5, 7, 9]`
- **Constraints:**
	- The resulting linked list must maintain reverse order.
	- Each node in the linked list must have a value between 0 and 9.

{{< dots >}}
### Core Logic 🔍
**Goal:** To compute the sum of two integers represented as linked lists in reverse order and return the result as a linked list.

- Initialize a dummy node to start the result linked list.
- Iterate through the two input linked lists while maintaining a carry for digit sums exceeding 9.
- Add corresponding digits from both lists along with the carry to calculate the sum.
- Create a new node for the result of each addition and append it to the result linked list.
- Continue until both lists are traversed and there is no carry left.
- Return the result linked list starting from the node next to the dummy.
{{< dots >}}
### Problem Assumptions ✅
- The input is always valid.
- Both linked lists represent non-negative integers.
{{< dots >}}
## Examples 🧩
- **Input:** `l1 = [3, 4, 2], l2 = [4, 6, 5]`  \
  **Explanation:** The numbers represented are 243 and 564. Their sum is 807, so the output is [7, 0, 8].

- **Input:** `l1 = [0], l2 = [0]`  \
  **Explanation:** The numbers represented are 0 and 0. Their sum is 0, so the output is [0].

- **Input:** `l1 = [9, 9, 9], l2 = [1]`  \
  **Explanation:** The numbers represented are 999 and 1. Their sum is 1000, so the output is [0, 0, 0, 1].

{{< dots >}}
## Approach 🚀
We iterate through the linked lists while maintaining a carry to handle sums that exceed a single digit.

### Initial Thoughts 💭
- The reverse order of digits simplifies addition as we can process from least significant to most significant digit.
- A carry must be handled to account for sums greater than 9.
- Iterating through both linked lists while summing corresponding nodes and keeping track of the carry will give the desired result.
{{< dots >}}
### Edge Cases 🌐
- The input will always have at least one node per list.
- Handles linked lists with up to 100 nodes efficiently.
- Handles cases with all zeroes or where the carry extends the list.
- Handles sums resulting in longer linked lists than either input.
{{< dots >}}
## Code 💻
```cpp
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
```

This code adds two numbers represented as linked lists, where each node contains a single digit. It iteratively adds digits from corresponding nodes, handling carry-over digits, and constructs a new linked list representing the sum.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	```
	Declares a function `addTwoNumbers` that takes two linked lists `l1` and `l2` as input and returns a new linked list representing their sum.

2. **Dummy Node Initialization**
	```cpp
	    ListNode* head = new ListNode(0);
	```
	Creates a dummy node `head` to simplify handling the head of the result list.

3. **Tail Pointer Initialization**
	```cpp
	    ListNode* tail = head;
	```
	Initializes a tail pointer `tail` to point to the dummy node, which will be used to append new nodes to the result list.

4. **Carry-over Initialization**
	```cpp
	    int rm = 0;
	```
	Initializes a variable `rm` to store the carry-over digit from the previous addition.

5. **Main Loop**
	```cpp
	    while (l1 != NULL || l2 != NULL || rm != 0) {
	```
	Starts a loop that continues as long as there are digits in either `l1` or `l2` or there's a carry-over.

6. **Digit Extraction**
	```cpp
	        int no1 = (l1 != NULL) ? l1->val : 0;
	        int no2 = (l2 != NULL) ? l2->val : 0;
	```
	Extracts the digits from the current nodes of `l1` and `l2`, handling cases where one or both lists have ended.

7. **Digit Sum and Carry-over Calculation**
	```cpp
	        int sum = no1 + no2 + rm;
	        int digit = sum % 10;
	        rm = sum / 10;
	```
	Calculates the sum of the current digits and the carry-over, extracts the current digit, and updates the carry-over for the next iteration.

8. **Create New Node**
	```cpp
	        ListNode* nxt = new ListNode(digit);
	```
	Creates a new node `nxt` to store the current digit.

9. **Append Node to Result List**
	```cpp
	        tail->next = nxt;
	        tail = tail->next;
	```
	Appends the new node `nxt` to the end of the result list and updates the `tail` pointer.

10. **Advance Pointers**
	```cpp
	        l1 = (l1 != NULL) ? l1->next : NULL;
	        l2 = (l2 != NULL) ? l2->next : NULL;
	```
	Moves the `l1` and `l2` pointers to the next nodes if they exist.

11. **Return Result List**
	```cpp
	    ListNode* res = head->next;
	```
	Sets the `res` pointer to the second node of the result list, skipping the dummy head node.

12. **Delete Dummy Node**
	```cpp
	    delete head;
	```
	Deletes the dummy head node to avoid memory leaks.

13. **Return Result**
	```cpp
	    return res;
	```
	Returns the head of the resulting linked list.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

We iterate through the length of the longer linked list, where n is the maximum number of nodes.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

We allocate a new node for each digit in the result, resulting in linear space usage.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/add-two-numbers/description/)

---
{{< youtube wgFPrzTjm7s >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

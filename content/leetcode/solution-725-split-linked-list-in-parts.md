
+++
authors = ["grid47"]
title = "Leetcode 725: Split Linked List in Parts"
date = "2024-08-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 725: Split Linked List in Parts in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Linked List"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/725.webp"
youtube = "ZITsHLE5mbE"
youtube_upload_date="2023-09-06"
youtube_thumbnail="https://i.ytimg.com/vi_webp/ZITsHLE5mbE/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/725.webp" 
    alt="A linked list being split into parts, with each split segment softly glowing as it’s separated."
    caption="Solution to LeetCode 725: Split Linked List in Parts Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given the head of a singly linked list and an integer k, split the linked list into k consecutive parts. The parts should have as equal size as possible, with no two parts differing by more than one element. Some parts may be null.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a singly linked list and an integer k.
- **Example:** `Input: head = [1, 2, 3], k = 5`
- **Constraints:**
	- The number of nodes in the list is between 0 and 1000.
	- 0 <= Node.val <= 1000
	- 1 <= k <= 50

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is an array of k parts, where each part is a singly linked list. Some parts may be null if there aren't enough nodes to split the list into k parts.
- **Example:** `Output: [[1], [2], [3], [], []]`
- **Constraints:**
	- The parts should appear in the order of the original linked list.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to split the given linked list into k consecutive parts of as equal size as possible.

- 1. Calculate the total number of nodes in the linked list.
- 2. Determine the base size of each part and the extra nodes that should be distributed.
- 3. Iterate through the linked list, splitting it into parts and linking each part accordingly.
- 4. If there are more parts than nodes, append null parts.
{{< dots >}}
### Problem Assumptions ✅
- The linked list is non-empty, unless specified.
- The value of k is always valid.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: [1, 2, 3], k = 5`  \
  **Explanation:** The linked list [1, 2, 3] is split into 5 parts, with the first three parts containing the elements 1, 2, and 3, respectively, and the last two parts being null.

{{< dots >}}
## Approach 🚀
The approach involves calculating the total number of nodes and then distributing them across k parts in such a way that the parts are as evenly sized as possible.

### Initial Thoughts 💭
- We need to distribute the nodes across the parts while maintaining the relative order.
- If there are more parts than nodes, we need to append null parts.
{{< dots >}}
### Edge Cases 🌐
- If the linked list is empty, the output will be k null parts.
- Ensure the solution handles large lists with up to 1000 nodes efficiently.
- Consider cases where k is larger than the number of nodes in the list.
- Ensure the solution works within the given constraints of up to 1000 nodes and 50 parts.
{{< dots >}}
## Code 💻
```cpp
vector<ListNode*> splitListToParts(ListNode* head, int k) {
    int len = 0;
    ListNode* temp = head;
    while(temp) {
        len++;
        temp = temp->next;
    }

    int numNodes = len/k;
    int ext = len % k;
    int i = 0;
    vector<ListNode*> res;
    temp = head;
    while(temp) {
        res.push_back(temp);
        int curLen = 1;
        while(curLen < numNodes) {
            temp =  temp->next;
            curLen++;
        }
        if(ext > 0 && len > k) {
            temp = temp->next;
            ext--;
        }
        ListNode* x = temp->next;
        temp->next = NULL;
        temp = x;
    }

    while(len < k) {
        res.push_back(NULL);
        len++;
    }
    return res;
}
```

This function splits a linked list into k parts as evenly as possible.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<ListNode*> splitListToParts(ListNode* head, int k) {
	```
	Defines a function that splits a linked list into k parts.

2. **Variable Initialization**
	```cpp
	    int len = 0;
	```
	Initializes the length of the linked list to zero.

3. **Pointer Initialization**
	```cpp
	    ListNode* temp = head;
	```
	Initializes a temporary pointer 'temp' to the head of the linked list.

4. **Loop**
	```cpp
	    while(temp) {
	```
	Starts a while loop to traverse the linked list and calculate its length.

5. **Operation**
	```cpp
	        len++;
	```
	Increments the length of the linked list for each node encountered.

6. **Pointer Update**
	```cpp
	        temp = temp->next;
	```
	Moves the temporary pointer to the next node in the linked list.

7. **Calculation**
	```cpp
	    int numNodes = len/k;
	```
	Calculates the number of nodes in each part, ignoring any remainder.

8. **Calculation**
	```cpp
	    int ext = len % k;
	```
	Calculates the number of extra nodes to distribute across the parts.

9. **Variable Initialization**
	```cpp
	    int i = 0;
	```
	Initializes a counter variable 'i'.

10. **Container Initialization**
	```cpp
	    vector<ListNode*> res;
	```
	Initializes a vector to store the resulting k parts of the linked list.

11. **Pointer Update**
	```cpp
	    temp = head;
	```
	Resets the temporary pointer to the head of the linked list.

12. **Loop**
	```cpp
	    while(temp) {
	```
	Starts a while loop to process the nodes of the linked list and split them into k parts.

13. **Operation**
	```cpp
	        res.push_back(temp);
	```
	Adds the current node to the result vector.

14. **Variable Initialization**
	```cpp
	        int curLen = 1;
	```
	Initializes a variable to track the length of the current part.

15. **Loop**
	```cpp
	        while(curLen < numNodes) {
	```
	Starts a loop to traverse the nodes in the current part.

16. **Pointer Update**
	```cpp
	            temp =  temp->next;
	```
	Moves the temporary pointer to the next node in the current part.

17. **Variable Update**
	```cpp
	            curLen++;
	```
	Increments the length of the current part.

18. **Condition**
	```cpp
	        if(ext > 0 && len > k) {
	```
	Checks if there are remaining extra nodes to be distributed.

19. **Pointer Update**
	```cpp
	            temp = temp->next;
	```
	Moves the temporary pointer to the next node to account for the extra nodes.

20. **Variable Update**
	```cpp
	            ext--;
	```
	Decrements the count of remaining extra nodes.

21. **Pointer Update**
	```cpp
	        ListNode* x = temp->next;
	```
	Stores the next node after the current node in the variable 'x'.

22. **Pointer Update**
	```cpp
	        temp->next = NULL;
	```
	Sets the next pointer of the current node to NULL to end the current part.

23. **Pointer Update**
	```cpp
	        temp = x;
	```
	Moves the temporary pointer to the next node, which is stored in 'x'.

24. **Condition**
	```cpp
	    while(len < k) {
	```
	Starts a loop to handle the case where there are fewer nodes than k.

25. **Operation**
	```cpp
	        res.push_back(NULL);
	```
	Adds NULL to the result vector to represent an empty part.

26. **Variable Update**
	```cpp
	        len++;
	```
	Increments the length to match the number of k parts.

27. **Return**
	```cpp
	    return res;
	```
	Returns the resulting vector containing k parts of the linked list.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) where n is the number of nodes in the linked list, as we traverse the list twice.

### Space Complexity 💾
- **Best Case:** O(k)
- **Worst Case:** O(k)

The space complexity is O(k), as we store the k parts in an array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/split-linked-list-in-parts/description/)

---
{{< youtube ZITsHLE5mbE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

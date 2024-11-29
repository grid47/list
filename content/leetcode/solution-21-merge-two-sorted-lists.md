
+++
authors = ["grid47"]
title = "Leetcode 21: Merge Two Sorted Lists"
date = "2024-11-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 21: Merge Two Sorted Lists in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Linked List","Recursion"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/21.webp"
youtube = "XIdigk956u0"
youtube_upload_date="2020-08-19"
youtube_thumbnail="https://i.ytimg.com/vi/XIdigk956u0/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/21.webp" 
    alt="Two glowing lists merging, with soft energy flowing together in sync."
    caption="Solution to LeetCode 21: Merge Two Sorted Lists Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given two sorted linked lists, merge them into one sorted linked list by splicing together the nodes from both lists. Return the head of the merged linked list.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given two sorted linked lists, list1 and list2. Each list is sorted in non-decreasing order and contains a series of nodes.
- **Example:** `list1 = [5,10,15], list2 = [1,7,12]`
- **Constraints:**
	- The number of nodes in each list is between 0 and 50.
	- -100 <= Node.val <= 100
	- Both lists are sorted in non-decreasing order.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the head of the new sorted linked list formed by merging the two input lists.
- **Example:** `Output: [1,5,7,10,12,15]`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Merge two sorted linked lists into a single sorted list.

- Initialize a dummy node to help with list manipulation.
- Use two pointers to traverse through both linked lists, comparing nodes at each step.
- Append the smaller node to the result list and move the corresponding pointer.
- After one of the lists is exhausted, append the remaining nodes from the other list.
{{< dots >}}
### Problem Assumptions ✅
- The input lists are sorted in non-decreasing order.
- There are no cycles in the linked lists.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1`  \
  **Explanation:** In this example, the lists [5,10,15] and [1,7,12] are merged to form the sorted list [1,5,7,10,12,15].

- **Input:** `Example 2`  \
  **Explanation:** When one of the lists is empty, as in the case of list1 = [] and list2 = [3,8], the result is just the other list: [3,8].

{{< dots >}}
## Approach 🚀
The approach to solving this problem is based on merging two sorted linked lists efficiently using a two-pointer technique.

### Initial Thoughts 💭
- Both input lists are sorted, which makes it easy to merge them in a single pass using two pointers.
- We can iterate through both lists, comparing the current nodes and appending the smaller one to the result list.
{{< dots >}}
### Edge Cases 🌐
- If one or both lists are empty, return the non-empty list or an empty list if both are empty.
- Handle cases where both lists are relatively large (up to 50 nodes).
- Consider negative values and repeated elements in the lists.
- The algorithm must handle the merging process efficiently for the given constraints.
{{< dots >}}
## Code 💻
```cpp
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;
    
    if(l1->val < l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
    l2->next = mergeTwoLists(l1, l2->next);
    return l2;            
}
```

This code implements a recursive function to merge two sorted linked lists into one sorted linked list.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	```
	This line declares a function named 'mergeTwoLists' that takes two pointers to the heads of two sorted linked lists, 'l1' and 'l2', as input and returns a pointer to the head of the merged linked list.

2. **Base Case**
	```cpp
	    if(l1 == NULL) return l2;
	```
	This line checks if the first list 'l1' is empty. If it is, the second list 'l2' is returned directly, as it is already sorted.

3. **Base Case**
	```cpp
	    if(l2 == NULL) return l1;
	```
	This line checks if the second list 'l2' is empty. If it is, the first list 'l1' is returned directly, as it is already sorted.

4. **Condition Check**
	```cpp
	    if(l1->val < l2->val) {
	```
	This line checks if the value of the current node in 'l1' is smaller than the value of the current node in 'l2'.

5. **Recursive Call**
	```cpp
	        l1->next = mergeTwoLists(l1->next, l2);
	```
	If the value of the current node in 'l1' is smaller, the 'next' pointer of 'l1' is set to the result of merging the rest of 'l1' with 'l2'. This recursively merges the remaining nodes.

6. **Return**
	```cpp
	        return l1;
	```
	The head of the merged list is returned, which is the original head of 'l1'.

7. **Recursive Call**
	```cpp
	    l2->next = mergeTwoLists(l1, l2->next);
	```
	If the value of the current node in 'l2' is smaller or equal, the 'next' pointer of 'l2' is set to the result of merging 'l1' with the rest of 'l2'. This recursively merges the remaining nodes.

8. **Return**
	```cpp
	    return l2;            
	```
	The head of the merged list is returned, which is the original head of 'l2'.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m + n)
- **Average Case:** O(m + n)
- **Worst Case:** O(m + n)

The time complexity is linear in terms of the total number of nodes in both lists (m + n), as we process each node once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(m + n)

The space complexity is O(m + n) if we count the space for the merged list, otherwise it is O(1) for the in-place merging algorithm.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/merge-two-sorted-lists/description/)

---
{{< youtube XIdigk956u0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

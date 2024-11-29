
+++
authors = ["grid47"]
title = "Leetcode 817: Linked List Components"
date = "2024-08-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 817: Linked List Components in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Linked List"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/817.webp"
youtube = "Vxbd1u86p9c"
youtube_upload_date="2019-09-16"
youtube_thumbnail="https://i.ytimg.com/vi_webp/Vxbd1u86p9c/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/817.webp" 
    alt="A linked list where the components are highlighted, each component softly glowing as it is connected."
    caption="Solution to LeetCode 817: Linked List Components Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given the head of a linked list containing unique integer values, and an array nums which is a subset of the linked list values. A connected component is defined as a sequence of consecutive values in the linked list that all appear in nums. Your task is to return the number of such connected components.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two parts: a linked list and an array nums. The linked list contains unique integer values, and nums contains integers that are a subset of the linked list's values.
- **Example:** `Input: head = [4,5,6,7,8], nums = [4,5,7]`
- **Constraints:**
	- 1 <= n <= 10^4
	- 0 <= Node.val < n
	- All the values in Node.val are unique.
	- 1 <= nums.length <= n
	- 0 <= nums[i] < n
	- All the values of nums are unique.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of connected components, where two values are connected if they appear consecutively in the linked list.
- **Example:** `Output: 2`
- **Constraints:**
	- The number of connected components should be an integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to traverse the linked list and count the number of connected components where consecutive numbers in nums appear in the linked list.

- Create a set from nums to facilitate fast lookups.
- Traverse the linked list while checking for consecutive values that appear in nums.
- Each time a transition from a number in nums to a non-consecutive value occurs, count a new connected component.
{{< dots >}}
### Problem Assumptions ✅
- The input linked list contains unique integer values.
- The nums array contains integers that are a subset of the linked list's values.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: head = [0,1,2,3], nums = [0,1,3]`  \
  **Explanation:** In this case, the linked list is [0,1,2,3] and nums is [0,1,3]. The first connected component is [0, 1], and the second one is [3], so the output is 2.

- **Input:** `Input: head = [4,5,6,7,8], nums = [4,5,7]`  \
  **Explanation:** Here, the linked list is [4,5,6,7,8] and nums is [4,5,7]. The connected components are [4, 5] and [7], so the output is 2.

{{< dots >}}
## Approach 🚀
We can solve this problem by traversing the linked list and checking whether the consecutive nodes in the linked list are part of nums. We will count each group of consecutive nodes that are in nums as a connected component.

### Initial Thoughts 💭
- We need to check consecutive nodes that belong to nums, so we can leverage a set for quick lookups.
- Whenever a node in nums is followed by a non-nums value, we count that as a new component.
- The problem involves identifying consecutive connected nodes in a linked list that belong to the nums array.
{{< dots >}}
### Edge Cases 🌐
- If the input linked list is empty, return 0 as there are no connected components.
- For large linked lists (up to 10,000 nodes), ensure that the solution runs efficiently within time limits.
- Handle cases where nums has only one element or contains all elements from the linked list.
- Ensure the solution efficiently handles up to 10,000 nodes in the linked list.
{{< dots >}}
## Code 💻
```cpp
int numComponents(ListNode* head, vector<int>& nums) {
    unordered_set<int> setG(nums.begin(), nums.end());
    int res =0;
    while(head != NULL) {
        if(setG.count(head->val) && 
        (head->next == NULL || !setG.count(head->next->val)))
        res++;
        head = head->next;
    }
    return res;
}
```

This function counts the number of connected components in the linked list, where the nodes' values are part of the given set of integers.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int numComponents(ListNode* head, vector<int>& nums) {
	```
	This line defines the function `numComponents` which takes a linked list `head` and a vector of integers `nums` as inputs.

2. **Data Structure Initialization**
	```cpp
	    unordered_set<int> setG(nums.begin(), nums.end());
	```
	An unordered set `setG` is created from the vector `nums`, which will be used to quickly check if a node's value is part of the set.

3. **Variable Initialization**
	```cpp
	    int res =0;
	```
	The variable `res` is initialized to 0, which will be used to count the number of connected components.

4. **Loop Start**
	```cpp
	    while(head != NULL) {
	```
	The loop starts and will iterate through each node of the linked list as long as `head` is not NULL.

5. **Condition Check**
	```cpp
	        if(setG.count(head->val) && 
	```
	This condition checks if the current node's value is in the set `setG`.

6. **Condition Check**
	```cpp
	        (head->next == NULL || !setG.count(head->next->val)))
	```
	This condition checks if the next node is either NULL (end of the list) or its value is not in the set `setG`.

7. **Increment Count**
	```cpp
	        res++;
	```
	If the conditions are met, it indicates the end of a connected component, and `res` is incremented.

8. **Advance to Next Node**
	```cpp
	        head = head->next;
	```
	The `head` pointer is advanced to the next node in the linked list.

9. **Return Result**
	```cpp
	    return res;
	```
	The function returns the value of `res`, which represents the number of connected components.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the length of the linked list.
- **Average Case:** O(n), as each node is processed once.
- **Worst Case:** O(n), since we only traverse the list once and check membership in a set.

The time complexity is linear in terms of the size of the linked list.

### Space Complexity 💾
- **Best Case:** O(m), where m is the size of nums.
- **Worst Case:** O(m), where m is the size of nums, as we store nums in a set for efficient lookups.

The space complexity is linear in terms of the size of nums due to the set used for fast lookups.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/linked-list-components/description/)

---
{{< youtube Vxbd1u86p9c >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

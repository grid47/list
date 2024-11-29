
+++
authors = ["grid47"]
title = "Leetcode 328: Odd Even Linked List"
date = "2024-10-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 328: Odd Even Linked List in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Linked List"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/328.webp"
youtube = "HaoudL9xEHA"
youtube_upload_date="2020-05-16"
youtube_thumbnail="https://i.ytimg.com/vi/HaoudL9xEHA/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/328.webp" 
    alt="A linked list where odd and even numbered nodes alternate, glowing softly as they form the correct pattern."
    caption="Solution to LeetCode 328: Odd Even Linked List Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given the head of a singly linked list. Your task is to reorder the list such that all nodes at odd indices are grouped together followed by all nodes at even indices. The first node is considered to have an odd index, the second node is considered to have an even index, and so on. The relative order inside the odd and even groups should remain unchanged.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given the head of a singly linked list.
- **Example:** `head = [1, 2, 3, 4, 5]`
- **Constraints:**
	- The number of nodes in the linked list is between 0 and 10^4.
	- Each node's value is between -10^6 and 10^6.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the reordered linked list where all odd-indexed nodes appear first, followed by the even-indexed nodes, while maintaining the relative order within each group.
- **Example:** `[1, 3, 5, 2, 4]`
- **Constraints:**
	- The solution must operate in O(n) time complexity and use O(1) extra space.

{{< dots >}}
### Core Logic 🔍
**Goal:** To reorder the linked list such that all odd-indexed nodes come first, followed by the even-indexed nodes, while maintaining the relative order within both groups.

- Initialize two pointers, one for odd-indexed nodes and one for even-indexed nodes.
- Traverse the list, separating the nodes into two lists: one for odd indices and one for even indices.
- Connect the last node of the odd list to the head of the even list.
{{< dots >}}
### Problem Assumptions ✅
- The input linked list always has a valid solution.
{{< dots >}}
## Examples 🧩
- **Input:** `head = [1, 2, 3, 4, 5]`  \
  **Explanation:** The list groups nodes with odd indices first (1, 3, 5), followed by the nodes with even indices (2, 4).

- **Input:** `head = [5, 10, 15, 20, 25, 30]`  \
  **Explanation:** The list groups nodes with odd indices first (5, 15, 25), followed by the nodes with even indices (10, 20, 30).

{{< dots >}}
## Approach 🚀
To solve this problem, we can use a two-pointer technique to separate the odd and even indexed nodes while preserving their relative order.

### Initial Thoughts 💭
- We need to maintain the relative order of both odd and even indexed nodes.
- By splitting the list into two parts (odd and even indexed nodes), we can efficiently reorder them and connect them in the correct order.
{{< dots >}}
### Edge Cases 🌐
- If the list is empty, return NULL.
- For very large lists (up to 10^4 nodes), ensure that the solution runs efficiently in O(n) time.
- Consider cases where all nodes have the same value.
- The solution must handle edge cases like empty lists and lists with a single node.
{{< dots >}}
## Code 💻
```cpp
ListNode* oddEvenList(ListNode* head) {
    if(!head) return NULL;
    ListNode *odd = head, *ehead = head->next, *even = head->next;

    while(even && even->next) {
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }
    odd->next = ehead;
    return head;
}
```

This function reorders the nodes of a singly linked list by separating the odd-indexed nodes and even-indexed nodes. The odd nodes will be placed first, followed by the even nodes. The linked list is rearranged in-place without using extra space.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	ListNode* oddEvenList(ListNode* head) {
	```
	This is the declaration of the `oddEvenList` function, which takes a pointer to the head of a singly linked list and returns a pointer to the reordered list.

2. **Base Case**
	```cpp
	    if(!head) return NULL;
	```
	If the head is NULL, it means the list is empty, so we return NULL immediately.

3. **Variable Initialization**
	```cpp
	    ListNode *odd = head, *ehead = head->next, *even = head->next;
	```
	Here, three pointers are initialized: `odd` points to the first node (head), `ehead` points to the first even node (head->next), and `even` also points to the first even node.

4. **Loop Condition**
	```cpp
	    while(even && even->next) {
	```
	This while loop continues as long as there are more even nodes to process (i.e., as long as `even` and `even->next` are not NULL).

5. **Odd Node Re-linking**
	```cpp
	        odd->next = odd->next->next;
	```
	The next pointer of the odd node is updated to point to the next odd node, skipping over the even node.

6. **Even Node Re-linking**
	```cpp
	        even->next = even->next->next;
	```
	Similarly, the next pointer of the even node is updated to point to the next even node.

7. **Pointer Advancing**
	```cpp
	        odd = odd->next;
	```
	The `odd` pointer is advanced to the next odd node.

8. **Pointer Advancing**
	```cpp
	        even = even->next;
	```
	The `even` pointer is advanced to the next even node.

9. **Reconnecting Odd and Even Lists**
	```cpp
	    odd->next = ehead;
	```
	After processing all odd and even nodes, the last odd node's `next` pointer is set to the head of the even nodes (`ehead`), effectively linking the two sub-lists.

10. **Return Statement**
	```cpp
	    return head;
	```
	Finally, the head of the modified list is returned, which now starts with all odd nodes followed by all even nodes.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear, as we only need to traverse the list once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant, as we are not using any additional data structures that grow with the input size.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/odd-even-linked-list/description/)

---
{{< youtube HaoudL9xEHA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

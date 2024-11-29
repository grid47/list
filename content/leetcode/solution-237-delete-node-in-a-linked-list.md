
+++
authors = ["grid47"]
title = "Leetcode 237: Delete Node in a Linked List"
date = "2024-10-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 237: Delete Node in a Linked List in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Linked List"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/237.webp"
youtube = "sW8ZaOTtvgI"
youtube_upload_date="2020-02-01"
youtube_thumbnail="https://i.ytimg.com/vi_webp/sW8ZaOTtvgI/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/237.webp" 
    alt="A linked list where a node gently fades away, leaving a cleaner structure behind."
    caption="Solution to LeetCode 237: Delete Node in a Linked List Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given a node in a singly linked list, and you are asked to delete this node from the list. The node is guaranteed to be not the last node in the list. After the deletion, the values before the node should remain in the same order, and the values after the node should also remain in the same order.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are provided with the head of the linked list and a specific node to delete. The node will not be the last node in the list.
- **Example:** `Input: head = [1,2,3,4,5], node = 3`
- **Constraints:**
	- The linked list will have at least two nodes.
	- The value of each node is unique.
	- The node to be deleted is guaranteed to not be the tail node.

{{< dots >}}
### Output Specifications 📤
- **Output:** After deleting the given node, return the modified linked list with the node removed.
- **Example:** `Output: [1,2,4,5]`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** To delete the given node, we will copy the value of the next node into the current node and then delete the next node.

- Copy the value of the next node into the current node.
- Point the current node's next to the node after the next node.
- Delete the next node.
{{< dots >}}
### Problem Assumptions ✅
- The list is not empty.
- The node to be deleted is not the last node.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: head = [1,2,3,4,5], node = 3`  \
  **Explanation:** The node to be deleted is 3. After deleting 3, the list becomes [1,2,4,5].

- **Input:** `Input: head = [10,20,30,40], node = 20`  \
  **Explanation:** The node to be deleted is 20. After deleting 20, the list becomes [10,30,40].

{{< dots >}}
## Approach 🚀
We can delete the given node by copying the value of the next node into the current node and adjusting the next pointer. This avoids the need for traversing the list from the start.

### Initial Thoughts 💭
- Since we are not given access to the head of the list, we cannot traverse the list from the start.
- The next node must exist, so we can safely copy its value into the current node.
- By copying the next node's value into the current node and removing the next node, the list remains in the correct order.
{{< dots >}}
### Edge Cases 🌐
- The list will always have at least two nodes, so there are no empty list cases.
- The solution should work efficiently even for lists with up to 1000 nodes.
- The node to be deleted is guaranteed not to be the last node in the list.
- The problem guarantees that the node is not the last node, so no need to check for that.
{{< dots >}}
## Code 💻
```cpp
void deleteNode(ListNode* node) {
    
    auto nxt = node->next;
    *node = *nxt;
    delete nxt;
}
```

This function deletes the node from a singly linked list. It performs the deletion by copying the data from the next node into the current node and then deleting the next node.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	void deleteNode(ListNode* node) {
	```
	Defines the `deleteNode` function which takes a pointer to a node (`node`) in a singly linked list as input and deletes it.

2. **Next Node Assignment**
	```cpp
	    auto nxt = node->next;
	```
	Assigns the next node (`node->next`) to a temporary variable `nxt`.

3. **Copy Data from Next Node**
	```cpp
	    *node = *nxt;
	```
	Copies the data and the next pointer of the next node (`nxt`) into the current node (`node`). This effectively overwrites the current node with the next node's data.

4. **Delete Next Node**
	```cpp
	    delete nxt;
	```
	Deletes the next node (`nxt`). Since its data has already been copied to the current node, the node is effectively removed from the list.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(1)
- **Worst Case:** O(1)

Since we are only modifying the node and its next pointer, the time complexity is constant.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

We are only modifying the linked list in place, so the space complexity is constant.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/delete-node-in-a-linked-list/description/)

---
{{< youtube sW8ZaOTtvgI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

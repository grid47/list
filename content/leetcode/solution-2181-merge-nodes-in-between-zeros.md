
+++
authors = ["grid47"]
title = "Leetcode 2181: Merge Nodes in Between Zeros"
date = "2024-04-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2181: Merge Nodes in Between Zeros in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Linked List","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "jrSav7fulJY"
youtube_upload_date="2024-07-04"
youtube_thumbnail="https://i.ytimg.com/vi/jrSav7fulJY/maxresdefault.jpg"
comments = true
+++



---
You are given the head of a linked list where each segment of the list is separated by nodes with the value `0`. Merge the nodes between two consecutive `0` nodes and replace them with a single node whose value is the sum of the nodes in between. The list should not contain any `0` nodes.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a linked list where each segment is separated by `0` nodes.
- **Example:** `[0, 5, 2, 0, 3, 4, 1, 0]`
- **Constraints:**
	- The number of nodes in the list is in the range [3, 2 * 10^5].
	- 0 <= Node.val <= 1000
	- There are no two consecutive nodes with Node.val == 0.
	- The beginning and end of the linked list have Node.val == 0.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is the modified linked list where each group of nodes between consecutive `0` nodes is replaced with a single node containing the sum of those nodes.
- **Example:** `[7, 8]`
- **Constraints:**
	- The modified list contains no `0` nodes.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to merge the nodes between consecutive `0` nodes by summing their values and removing the `0` nodes.

- Start from the head of the linked list.
- For each segment of nodes between two `0` nodes, sum their values.
- Replace the first `0` node with the sum and remove the rest of the `0` nodes.
{{< dots >}}
### Problem Assumptions ✅
- The input list is valid and adheres to the specified constraints.
- The list will not have consecutive `0` nodes except for the first and last.
{{< dots >}}
## Examples 🧩
- **Input:** `[0, 5, 2, 0, 3, 4, 1, 0]`  \
  **Explanation:** In this example, the nodes between the first `0` and the next `0` are summed to form the node with value 7, and the nodes between the second and third `0` are summed to form the node with value 8.

{{< dots >}}
## Approach 🚀
The approach involves iterating through the linked list and summing the nodes between each pair of consecutive `0` nodes, replacing the first `0` node with the sum.

### Initial Thoughts 💭
- The problem is mainly about traversing the linked list and calculating sums for segments between `0` nodes.
- A recursive or iterative approach can be used to traverse the list, accumulating sums between `0` nodes.
{{< dots >}}
### Edge Cases 🌐
- The input list will never be empty or contain fewer than 3 nodes.
- For larger inputs (up to 200,000 nodes), ensure the solution is efficient.
- Handle cases where the segments between `0` nodes have only one node.
- The solution should run efficiently within the input constraints.
{{< dots >}}
## Code 💻
```cpp
ListNode* mergeNodes(ListNode* head) {
    if(!head->next) return nullptr;

    ListNode* ptr = head->next;
    int sum = 0;
    while(ptr->val!=0) sum += ptr->val, ptr = ptr->next;
    head->next->val = sum;
    head->next->next= mergeNodes(ptr);
    return head->next;
}
```

This function, `mergeNodes`, takes a linked list starting at `head` and sums the values of nodes between the zero-valued nodes. It recursively merges the nodes by accumulating the sums, adjusting the values, and returning the modified list.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	ListNode* mergeNodes(ListNode* head) {
	```
	Define the function `mergeNodes` that processes a linked list to merge nodes by summing values between zero-valued nodes.

2. **Base Case Check**
	```cpp
	    if(!head->next) return nullptr;
	```
	Check if the next node of `head` is null (base case). If so, return `nullptr` to end the recursion.

3. **Pointer Initialization**
	```cpp
	    ListNode* ptr = head->next;
	```
	Initialize a pointer `ptr` to point to the node following `head`.

4. **Variable Initialization**
	```cpp
	    int sum = 0;
	```
	Initialize a variable `sum` to accumulate the sum of node values between zero-valued nodes.

5. **Sum Calculation Loop**
	```cpp
	    while(ptr->val!=0) sum += ptr->val, ptr = ptr->next;
	```
	Iterate through the list, summing node values (`ptr->val`) until a zero-valued node is encountered. Move the pointer `ptr` to the next node after each iteration.

6. **Assign Sum to Node**
	```cpp
	    head->next->val = sum;
	```
	Assign the calculated sum to the `val` of the node immediately following `head`.

7. **Recursive Call**
	```cpp
	    head->next->next= mergeNodes(ptr);
	```
	Recursively call `mergeNodes` with the next node (`ptr`) and update the `next` pointer of the node following `head` with the result of this recursive call.

8. **Return Statement**
	```cpp
	    return head->next;
	```
	Return the modified list starting from the node following `head`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear, as we traverse the list once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant, as we only need a few pointers for traversal.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/merge-nodes-in-between-zeros/description/)

---
{{< youtube jrSav7fulJY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

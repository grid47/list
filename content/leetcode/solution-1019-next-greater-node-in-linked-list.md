
+++
authors = ["grid47"]
title = "Leetcode 1019: Next Greater Node In Linked List"
date = "2024-07-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1019: Next Greater Node In Linked List in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Linked List","Stack","Monotonic Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++



---
You are given the head of a singly linked list. For each node in the list, find the value of the next node that has a strictly larger value than the current node. If no such node exists, return 0 for that node. Return the result as an array where the value at index i represents the next greater node for the i-th node.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a singly linked list where each node contains a value.
- **Example:** `head = [1, 3, 2, 4]`
- **Constraints:**
	- The number of nodes in the list is n.
	- 1 <= n <= 10^4
	- 1 <= Node.val <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an integer array answer, where answer[i] is the value of the next greater node for the i-th node (1-indexed). If no such node exists, set answer[i] = 0.
- **Example:** `Output: [3, 4, 4, 0]`
- **Constraints:**
	- The array returned should have the same length as the number of nodes in the linked list.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the next greater node for each node in the linked list. This involves tracking the nodes where a larger value appears next and updating the corresponding result.

- 1. Traverse the linked list while maintaining a stack to store the indices of nodes.
- 2. For each node, compare its value with the value at the index stored at the top of the stack.
- 3. If the current node has a larger value, pop the index from the stack and update the result for that index.
- 4. Push the current node index onto the stack for future comparisons.
- 5. After processing all nodes, the remaining indices in the stack will correspond to nodes that do not have a larger next node, so set their results to 0.
{{< dots >}}
### Problem Assumptions ✅
- The input linked list is valid, and the list is not empty.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: head = [1, 3, 2, 4]`  \
  **Explanation:** In this list, the next greater node for 1 is 3, for 3 is 4, for 2 is 4, and for 4, there is no greater node, so it returns 0. Therefore, the output is [3, 4, 4, 0].

- **Input:** `Input: head = [2, 1, 5]`  \
  **Explanation:** Here, the next greater node for 2 is 5, for 1 is 5, and for 5, there is no next greater node, so it returns 0. The output is [5, 5, 0].

{{< dots >}}
## Approach 🚀
The solution uses a stack to keep track of the nodes while iterating through the list. This helps efficiently find the next greater node for each element.

### Initial Thoughts 💭
- A stack is useful to store indices of nodes while checking for the next greater node.
- The stack ensures that we only look at each node once, making the algorithm more efficient.
{{< dots >}}
### Edge Cases 🌐
- If the input linked list is empty, the output should be an empty array.
- For large lists (e.g., when n is close to 10^4), the solution should still run efficiently within time limits.
- Handle cases where all nodes have the same value, in which case the output should be an array of zeros.
- Ensure that the solution works for cases with values at the boundary of constraints (e.g., very large node values).
{{< dots >}}
## Code 💻
```cpp
vector<int> nextLargerNodes(ListNode* head) {
    vector<int> stk, res;
    
    for(ListNode* node = head; node != NULL; node = node->next) {
        
        while(!stk.empty() && res[stk.back()] < node->val) {
            res[stk.back()] = node->val;
            stk.pop_back();
        }

        
        stk.push_back(res.size());
        res.push_back(node->val);
    }
    
    for(int i : stk) res[i] = 0;
    
    return res;
}
```

The function `nextLargerNodes` takes a linked list and returns an array of integers representing the next larger node's value for each node in the list. If no larger value exists, it returns 0 for that node.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<int> nextLargerNodes(ListNode* head) {
	```
	Defines the function `nextLargerNodes`, which accepts a pointer to the head of a linked list and returns a vector of integers.

2. **Variable Initialization**
	```cpp
	    vector<int> stk, res;
	```
	Initializes two vectors: `stk` to hold indices of elements and `res` to store the final result.

3. **For Loop Setup**
	```cpp
	    for(ListNode* node = head; node != NULL; node = node->next) {
	```
	Begins a loop that iterates over each node in the linked list from `head` to the end.

4. **While Loop Start**
	```cpp
	        while(!stk.empty() && res[stk.back()] < node->val) {
	```
	Enters a while loop to check if there is a larger node value for the indices stored in `stk`. If the current node's value is greater, it updates the corresponding position in `res`.

5. **Update Result**
	```cpp
	            res[stk.back()] = node->val;
	```
	Updates the result array `res` at the index stored in `stk` with the current node's value.

6. **Pop from Stack**
	```cpp
	            stk.pop_back();
	```
	Removes the top index from the stack `stk` since its next larger value has been found.

7. **Push Index to Stack**
	```cpp
	        stk.push_back(res.size());
	```
	Pushes the index of the current node into the stack `stk` to track the position of the node for future comparisons.

8. **Store Node Value**
	```cpp
	        res.push_back(node->val);
	```
	Adds the current node's value to the `res` vector.

9. **For Loop for Remaining Indices**
	```cpp
	    for(int i : stk) res[i] = 0;
	```
	Iterates through the remaining indices in `stk`, setting their corresponding values in `res` to 0, as no larger value was found for those nodes.

10. **Return Result**
	```cpp
	    return res;
	```
	Returns the final result vector `res`, which contains the next larger value for each node in the linked list.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) since we iterate through each node exactly once.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the stack and result array storing information for each node in the list.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/next-greater-node-in-linked-list/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |


+++
authors = ["grid47"]
title = "Leetcode 654: Maximum Binary Tree"
date = "2024-09-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 654: Maximum Binary Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Divide and Conquer","Stack","Tree","Monotonic Stack","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/654.webp"
youtube = "zvBxnudTZmw"
youtube_upload_date="2024-01-21"
youtube_thumbnail="https://i.ytimg.com/vi_webp/zvBxnudTZmw/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/654.webp" 
    alt="A binary tree where the maximum value node is highlighted, glowing softly as it’s determined."
    caption="Solution to LeetCode 654: Maximum Binary Tree Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given an integer array nums with no duplicates, construct a maximum binary tree by recursively selecting the largest number as the root, and building the left and right subtrees from the elements before and after the largest number.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is an integer array with unique values.
- **Example:** `nums = [6, 3, 8, 2, 5, 7, 4]`
- **Constraints:**
	- 1 <= nums.length <= 1000
	- 0 <= nums[i] <= 1000
	- All integers in nums are unique

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the root of the maximum binary tree, where each subtree is constructed according to the specified rules.
- **Example:** `[8,3,7,2,5,null,4]`
- **Constraints:**
	- The output will be a binary tree structure representing the maximum binary tree.

{{< dots >}}
### Core Logic 🔍
**Goal:** Build a binary tree where each node is the largest value in a subarray.

- 1. Find the largest element in the array.
- 2. Make that element the root of the tree.
- 3. Recursively build the left subtree using the elements before the largest element.
- 4. Recursively build the right subtree using the elements after the largest element.
{{< dots >}}
### Problem Assumptions ✅
- The input array will always contain at least one element.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [6, 3, 8, 2, 5, 7, 4]`  \
  **Explanation:** The largest number, 8, becomes the root. The subarrays to the left and right are [6, 3] and [2, 5, 7, 4], respectively. These subarrays are processed recursively, with 6 as the left child and 7 as the right child of the root.

{{< dots >}}
## Approach 🚀
To construct the maximum binary tree, we find the largest value in the current subarray, make it the root, and then recursively build the left and right subtrees from the remaining elements.

### Initial Thoughts 💭
- The maximum binary tree can be built by using a divide-and-conquer approach.
- This problem requires finding the maximum value efficiently in the array and handling the recursion correctly for left and right subtrees.
{{< dots >}}
### Edge Cases 🌐
- The input array will not be empty as it contains at least one element.
- For large inputs, ensure that the solution handles up to 1000 elements efficiently.
- Handle cases where the array is in strictly increasing or strictly decreasing order.
- Ensure that the solution is optimized for time complexity, especially for larger arrays.
{{< dots >}}
## Code 💻
```cpp
TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    
    vector<TreeNode*> stk;
    
    for(int num : nums) {
        
        TreeNode* cur = new TreeNode(num);
        
        while(!stk.empty() && stk.back()->val < num) {
            cur->left = stk.back();
            stk.pop_back();
        }
        
        if(!stk.empty()) stk.back()->right = cur;
        
        stk.push_back(cur);
        
    }
    
    return stk.front();
    
}
```

This function constructs a maximum binary tree from a given vector of integers. It uses a stack to maintain nodes in the tree, ensuring that the largest values appear as parents.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
	```
	This is the function header for `constructMaximumBinaryTree`. It takes a vector of integers `nums` and returns a pointer to the root of the constructed binary tree.

2. **Stack Initialization**
	```cpp
	    vector<TreeNode*> stk;
	```
	A stack `stk` is initialized to help in constructing the binary tree. The stack will hold nodes as we build the tree.

3. **Loop Through Input**
	```cpp
	    for(int num : nums) {
	```
	The function iterates over each integer in the `nums` vector to construct the binary tree.

4. **Node Creation**
	```cpp
	        TreeNode* cur = new TreeNode(num);
	```
	A new `TreeNode` is created for each value in the `nums` vector. This node will eventually be part of the binary tree.

5. **While Loop for Left Children**
	```cpp
	        while(!stk.empty() && stk.back()->val < num) {
	```
	The `while` loop checks if the last node in the stack has a smaller value than the current number. If true, this means the current node will be a parent of the nodes in the stack.

6. **Link Left Child**
	```cpp
	            cur->left = stk.back();
	```
	The node at the top of the stack becomes the left child of the current node, as the current node has a larger value.

7. **Pop Stack**
	```cpp
	            stk.pop_back();
	```
	The node is removed from the stack after being linked as the left child of the current node.

8. **Link Right Child**
	```cpp
	        if(!stk.empty()) stk.back()->right = cur;
	```
	If the stack is not empty, the current node is set as the right child of the node at the top of the stack.

9. **Push Current Node to Stack**
	```cpp
	        stk.push_back(cur);
	```
	The current node is added to the stack to be used as a potential parent for the next node.

10. **Return Root**
	```cpp
	    return stk.front();
	```
	The root of the tree, which is at the front of the stack after the loop completes, is returned.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear, O(n), because each element is processed once.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the recursion stack and the tree nodes.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-binary-tree/description/)

---
{{< youtube zvBxnudTZmw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

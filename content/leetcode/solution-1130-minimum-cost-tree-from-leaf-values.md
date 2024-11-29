
+++
authors = ["grid47"]
title = "Leetcode 1130: Minimum Cost Tree From Leaf Values"
date = "2024-07-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1130: Minimum Cost Tree From Leaf Values in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Stack","Greedy","Monotonic Stack"]
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
You are given an array arr of positive integers. Consider all binary trees such that each node has either 0 or 2 children, the values of arr correspond to the values of each leaf in an in-order traversal of the tree, and the value of each non-leaf node is equal to the product of the largest leaf values in its left and right subtrees. Return the smallest possible sum of the values of the non-leaf nodes among all possible binary trees.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an array arr of integers where each integer represents a leaf node value in a binary tree.
- **Example:** `Input: arr = [5,3,8]`
- **Constraints:**
	- 2 <= arr.length <= 40
	- 1 <= arr[i] <= 15
	- The answer fits into a 32-bit signed integer.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the smallest possible sum of the values of each non-leaf node in the tree.
- **Example:** `Output: 75`
- **Constraints:**
	- The sum of non-leaf node values should fit in a 32-bit signed integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the binary tree that minimizes the sum of non-leaf node values, considering all possible binary trees that can be formed from the given leaf values.

- Initialize a stack with a value greater than any leaf node.
- Iterate through the array of leaf values, and for each value, check if it can form a valid tree node by combining with the previous elements in the stack.
- For each valid combination, compute the product of the current non-leaf node values and accumulate the result.
{{< dots >}}
### Problem Assumptions ✅
- The tree will be a full binary tree with 0 or 2 children per node.
- It is assumed that the values in the array will always be valid positive integers within the specified range.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: arr = [5,3,8]`  \
  **Explanation:** The goal is to arrange the leaf nodes in such a way that the sum of non-leaf nodes is minimized. The smallest possible non-leaf node sum is 75, as calculated by the optimal tree structure.

- **Input:** `Input: arr = [10,15,12]`  \
  **Explanation:** The optimal binary tree for this set of leaf nodes produces the minimum sum of non-leaf node values, which is 330.

{{< dots >}}
## Approach 🚀
The solution involves using a stack to help compute the smallest sum by simulating the process of building a binary tree and evaluating the cost for each non-leaf node.

### Initial Thoughts 💭
- We need to optimize the tree structure such that the non-leaf node values are minimized.
- Using a stack allows us to easily manage and combine leaf nodes while maintaining an efficient calculation of the product of the largest values from each subtree.
{{< dots >}}
### Edge Cases 🌐
- The problem guarantees that the input will have at least 2 elements, so no need to handle empty arrays.
- The algorithm should handle inputs with up to 40 leaf nodes efficiently.
- Consider cases where all elements in the array are equal, as this might affect the structure of the binary tree.
- Ensure that the solution runs within the time limits for the largest input sizes.
{{< dots >}}
## Code 💻
```cpp
int mctFromLeafValues(vector<int>& arr) {
    
    int res = 0;
    
    vector<int> stk = { INT_MAX };
    for(int a : arr) {
        while(stk.back() <= a) {
            int mid = stk.back();
            stk.pop_back();
            res += mid * min(stk.back(), a);
        }
        stk.push_back(a);
    }
    
    for(int i = 2; i < stk.size(); i++) {
        res += stk[i] * stk[i - 1];
    }
    
    return res;
}
```

This function calculates the minimum cost tree from leaf values by simulating a greedy approach using a stack to maintain the current minimum values while traversing the input array.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int mctFromLeafValues(vector<int>& arr) {
	```
	This function definition begins the implementation of the `mctFromLeafValues` function, which takes a vector of integers `arr` and returns an integer.

2. **Variable Initialization**
	```cpp
	    int res = 0;
	```
	This line initializes the result variable `res`, which will store the total cost of the minimum cost tree.

3. **Stack Initialization**
	```cpp
	    vector<int> stk = { INT_MAX };
	```
	A stack `stk` is initialized with the maximum possible integer (`INT_MAX`) as a sentinel value to handle edge cases when processing the tree structure.

4. **Loop Setup**
	```cpp
	    for(int a : arr) {
	```
	This `for` loop iterates through the elements in the input vector `arr`.

5. **Loop Condition**
	```cpp
	        while(stk.back() <= a) {
	```
	This `while` loop checks if the current stack's top value is less than or equal to the current element `a`. If true, it processes the current stack element.

6. **Stack Manipulation**
	```cpp
	            int mid = stk.back();
	```
	The top value of the stack is stored in `mid` for further calculations.

7. **Stack Pop**
	```cpp
	            stk.pop_back();
	```
	This line removes the top element from the stack after processing it.

8. **Cost Calculation**
	```cpp
	            res += mid * min(stk.back(), a);
	```
	The result variable `res` is updated by adding the product of the `mid` value and the minimum of the stack's new top value and the current element `a`.

9. **Stack Push**
	```cpp
	        stk.push_back(a);
	```
	After the inner `while` loop, the current element `a` is pushed onto the stack.

10. **Additional Processing**
	```cpp
	    for(int i = 2; i < stk.size(); i++) {
	```
	A second `for` loop starts at index 2 to process the remaining stack elements after the main loop finishes.

11. **Cost Calculation**
	```cpp
	        res += stk[i] * stk[i - 1];
	```
	This line adds the product of each adjacent pair of stack elements to the result `res`.

12. **Return Statement**
	```cpp
	    return res;
	```
	The final result `res` is returned, which contains the minimum cost of the tree.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear in terms of the number of leaf nodes due to the stack-based approach.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the space required for the stack.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

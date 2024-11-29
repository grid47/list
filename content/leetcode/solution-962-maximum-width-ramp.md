
+++
authors = ["grid47"]
title = "Leetcode 962: Maximum Width Ramp"
date = "2024-08-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 962: Maximum Width Ramp in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Stack","Monotonic Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "3pTEJ1vzgSI"
youtube_upload_date="2024-10-10"
youtube_thumbnail="https://i.ytimg.com/vi/3pTEJ1vzgSI/maxresdefault.jpg"
comments = true
+++



---
You are given an integer array nums. A ramp in the array is a pair of indices (i, j) where i < j and nums[i] <= nums[j]. The width of the ramp is calculated as the difference between j and i (i.e., j - i). Your task is to find the maximum width of a ramp in the given array. If no such ramp exists, return 0.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a single integer array nums of size n (2 <= n <= 50,000), where each element nums[i] (0 <= nums[i] <= 50,000) represents an integer value in the array.
- **Example:** `Input: nums = [3, 5, 7, 1, 4, 2, 6]`
- **Constraints:**
	- 2 <= nums.length <= 50,000
	- 0 <= nums[i] <= 50,000

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is an integer representing the maximum width of a ramp in the array. If no ramp exists, return 0.
- **Example:** `Output: 4`
- **Constraints:**
	- The result must be a non-negative integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the maximum width of a ramp by iterating over the array, checking pairs (i, j) where nums[i] <= nums[j], and computing the width (j - i) for each valid pair.

- 1. Traverse the array while maintaining a stack to store the indices of elements in a way that ensures nums[i] <= nums[j] for valid pairs.
- 2. For each element in the array, try to find a corresponding j index that results in a larger width.
- 3. Track the maximum width encountered during the traversal.
{{< dots >}}
### Problem Assumptions ✅
- The array nums will always have at least two elements, and all elements will be integers within the given range.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [3, 5, 7, 1, 4, 2, 6]`  \
  **Explanation:** In this case, the maximum width ramp is found between indices (1, 5) where nums[1] = 5 and nums[5] = 2. The width is 5 - 1 = 4.

- **Input:** `Input: nums = [9, 8, 7, 6, 5]`  \
  **Explanation:** Here, no valid ramp can be formed because every pair of elements nums[i] and nums[j] with i < j violates the condition nums[i] <= nums[j]. Thus, the result is 0.

- **Input:** `Input: nums = [1, 2, 3, 4, 5]`  \
  **Explanation:** In this case, the ramp can be formed between the first and the last index, with a width of 4 - 0 = 4.

{{< dots >}}
## Approach 🚀
To solve the problem efficiently, we can use a stack to help keep track of indices that could form valid ramps. The stack will ensure that we can find a pair of indices i and j such that nums[i] <= nums[j], and we can calculate the width j - i.

### Initial Thoughts 💭
- The problem can be reduced to finding a pair of indices i and j such that nums[i] <= nums[j], and maximizing j - i.
- A brute force solution would require checking all pairs, which could be inefficient for large arrays.
- Using a stack to store indices and then traversing the array backwards allows us to efficiently find the maximum width without explicitly checking every pair.
{{< dots >}}
### Edge Cases 🌐
- The input will always have at least two elements, so this case is not possible.
- For large arrays with 50,000 elements, the solution must be efficient enough to handle the constraints.
- When the array elements are all the same, any pair of indices (i, j) will form a valid ramp with the maximum width being j - i.
- The input array will always have at least two elements, and each element will be within the range 0 <= nums[i] <= 50,000.
{{< dots >}}
## Code 💻
```cpp
int maxWidthRamp(vector<int>& nums) {
    stack<int> s;
    for(int i = 0; i < nums.size(); i++)
        if(s.empty() || nums[s.top()] > nums[i])
            s.push(i);
    
    int res = 0;
    for(int i = nums.size() - 1; i >= 0; i--)
        while(!s.empty() && nums[s.top()] <= nums[i])
            res = max(res, i - s.top()), s.pop();
    
    return res;
}
```

This function finds the maximum width ramp in an array. A ramp is a pair (i, j) such that i < j and nums[i] <= nums[j]. The function uses a stack to track potential starting indices and iterates from the end to compute the widest ramp.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int maxWidthRamp(vector<int>& nums) {
	```
	Declares the function to compute the maximum width ramp in an array.

2. **Stack Initialization**
	```cpp
	    stack<int> s;
	```
	Initializes an empty stack to store indices of potential starting points for the ramp.

3. **Outer Loop**
	```cpp
	    for(int i = 0; i < nums.size(); i++)
	```
	Iterates through the array to populate the stack with indices of decreasing elements.

4. **Stack Condition**
	```cpp
	        if(s.empty() || nums[s.top()] > nums[i])
	```
	Checks if the stack is empty or if the current element is smaller than the element at the top of the stack.

5. **Push Index**
	```cpp
	            s.push(i);
	```
	Pushes the current index onto the stack as a potential starting point for a ramp.

6. **Result Initialization**
	```cpp
	    int res = 0;
	```
	Initializes the variable `res` to store the maximum width of the ramp.

7. **Reverse Loop**
	```cpp
	    for(int i = nums.size() - 1; i >= 0; i--)
	```
	Iterates through the array in reverse to calculate the widest ramp.

8. **While Loop Condition**
	```cpp
	        while(!s.empty() && nums[s.top()] <= nums[i])
	```
	Checks if the current element can form a ramp with the index at the top of the stack.

9. **Calculate Ramp**
	```cpp
	            res = max(res, i - s.top()), s.pop();
	```
	Calculates the width of the ramp, updates the result, and pops the stack.

10. **Return Statement**
	```cpp
	    return res;
	```
	Returns the maximum width of the ramp found in the array.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because we traverse the array twice: once to fill the stack and once to calculate the maximum width.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n) due to the stack used to store indices.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-width-ramp/description/)

---
{{< youtube 3pTEJ1vzgSI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

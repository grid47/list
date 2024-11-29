
+++
authors = ["grid47"]
title = "Leetcode 1911: Maximum Alternating Subsequence Sum"
date = "2024-04-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1911: Maximum Alternating Subsequence Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "4v42XOuU1XA"
youtube_upload_date="2021-06-26"
youtube_thumbnail="https://i.ytimg.com/vi/4v42XOuU1XA/maxresdefault.jpg"
comments = true
+++



---
You are given an array nums. The alternating sum of a sequence is calculated as the sum of elements at even indices minus the sum of elements at odd indices. Your task is to find the maximum alternating sum of any subsequence formed by deleting some elements from the array without changing the relative order of the remaining elements.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array nums, where each element is a positive integer.
- **Example:** `nums = [4,2,5,3]`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- 1 <= nums[i] <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum alternating sum that can be achieved from any subsequence of nums.
- **Example:** `7`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** To calculate the maximum alternating sum of any subsequence of nums.

- Use dynamic programming to track the maximum alternating sum at each index, considering both including and excluding the current element.
{{< dots >}}
### Problem Assumptions ✅
- The elements of the array are positive integers.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [4,2,5,3]`  \
  **Explanation:** The optimal subsequence to pick is [4, 2, 5], resulting in an alternating sum of (4 + 5) - 2 = 7.

{{< dots >}}
## Approach 🚀
The problem can be approached using dynamic programming where we maintain two variables: one for the maximum sum when considering the current element and another for the sum when excluding it.

### Initial Thoughts 💭
- The alternating sum involves switching between adding and subtracting elements.
- We can use a greedy dynamic approach to decide at each step whether to include or exclude the current element.
{{< dots >}}
### Edge Cases 🌐
- If nums is empty, handle gracefully by returning 0.
- Ensure the solution works efficiently with arrays of size up to 10^5.
- Handle cases where all elements are the same, as well as where all elements are very large or small.
- Ensure the solution handles the constraints efficiently.
{{< dots >}}
## Code 💻
```cpp
long long maxAlternatingSum(vector<int>& nums) {

    long long odd = 0, even = 0;

    for(int num : nums) {
        even = max(even, odd + num);
        odd = even - num;
    }

    return even;
}
```

This function calculates the maximum alternating sum of a list of numbers using dynamic programming, where we keep track of the sums when including or excluding the current element.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	long long maxAlternatingSum(vector<int>& nums) {
	```
	Define the function 'maxAlternatingSum' which takes a reference to a vector of integers 'nums'. The function will return a long long value representing the maximum alternating sum.

2. **Variable Initialization**
	```cpp
	    long long odd = 0, even = 0;
	```
	Initialize two variables 'odd' and 'even' to store the maximum alternating sums for odd and even indices in the sequence, respectively.

3. **For Loop Setup**
	```cpp
	    for(int num : nums) {
	```
	Start a loop to iterate through each element 'num' in the vector 'nums'.

4. **Dynamic Programming Update**
	```cpp
	        even = max(even, odd + num);
	```
	Update the 'even' sum by considering the maximum of the previous 'even' value and the sum of 'odd' plus the current 'num'. This ensures we alternate between adding and subtracting the elements.

5. **Odd Sum Update**
	```cpp
	        odd = even - num;
	```
	Update the 'odd' sum by subtracting the current 'num' from 'even', following the alternating sum pattern.

6. **Return Statement**
	```cpp
	    return even;
	```
	Return the 'even' value as the result, representing the maximum alternating sum after considering all numbers.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear because we are iterating through the array once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant as we are only using a few extra variables for tracking the sums.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-alternating-subsequence-sum/description/)

---
{{< youtube 4v42XOuU1XA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

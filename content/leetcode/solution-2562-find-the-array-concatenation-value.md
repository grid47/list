
+++
authors = ["grid47"]
title = "Leetcode 2562: Find the Array Concatenation Value"
date = "2024-02-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2562: Find the Array Concatenation Value in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "OgX8lEhgW9g"
youtube_upload_date="2023-02-12"
youtube_thumbnail="https://i.ytimg.com/vi_webp/OgX8lEhgW9g/maxresdefault.webp"
comments = true
+++



---
You are given an array of integers, `nums`, and you need to calculate the total concatenation value. To calculate this, you repeatedly perform the following operations until the array is empty:

1. If the array has more than one element, take the first and last elements, concatenate them, and add the result to the total concatenation value. Then remove the first and last elements from the array.
2. If the array has only one element, add it to the total concatenation value and remove the element.

The goal is to return the total concatenation value after performing all the operations.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a single integer array `nums` of length `n` (1 <= n <= 1000), where each element of the array is a positive integer (1 <= nums[i] <= 104).
- **Example:** `Input: nums = [8, 32, 5, 1]`
- **Constraints:**
	- 1 <= nums.length <= 1000
	- 1 <= nums[i] <= 104

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the total concatenation value after performing the above operations on the array.
- **Example:** `Output: 398`
- **Constraints:**
	- The concatenation value is guaranteed to fit within the range of a 32-bit integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to repeatedly concatenate the first and last elements of the array until it becomes empty and calculate the total concatenation value.

- Initialize a variable to store the concatenation value.
- Repeat the operation of concatenating the first and last elements, removing them from the array, and adding the concatenated result to the value.
- If only one element is left, simply add it to the value.
{{< dots >}}
### Problem Assumptions ✅
- The array will always have at least one element.
- The array elements are positive integers.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: Input: nums = [8, 32, 5, 1], Output: 398`  \
  **Explanation:** In this example, the array starts as [8, 32, 5, 1]. The first operation concatenates 8 and 1 to form 81. Then the array becomes [32, 5]. The second operation concatenates 32 and 5 to form 325. Finally, the total value is 398.

- **Input:** `Example 2: Input: nums = [1, 12, 8, 7, 2], Output: 160`  \
  **Explanation:** In this example, the first concatenation adds 12, then 127, and finally adds 8, resulting in a total value of 160.

{{< dots >}}
## Approach 🚀
The approach to solving this problem is to simulate the process of repeatedly concatenating the first and last elements, updating the total concatenation value at each step.

### Initial Thoughts 💭
- The problem is straightforward and involves array manipulation.
- The challenge is ensuring the proper concatenation of the first and last elements at each step.
- We can perform this task in a loop, ensuring we handle the case of one remaining element properly.
{{< dots >}}
### Edge Cases 🌐
- If the array is empty (though not applicable in this case due to constraints), the result would be 0.
- Ensure the solution handles arrays up to the size limit of 1000 elements.
- If the array contains only one element, return the value of that element.
- The solution must ensure that all concatenations fit within the 32-bit integer limit.
{{< dots >}}
## Code 💻
```cpp
  long long findTheArrayConcVal(vector<int>& nums) {
  long long res = 0, sz = nums.size();
  for (int i = 0, j = sz - 1; i <= j; ++i, --j)
      if (i < j)
          res += nums[i] * pow(10, (int)log10(nums[j]) + 1) + nums[j];
      else
          res += nums[i];
  return res;
  }
```

This function calculates the concatenation value of an array by pairing the first and last elements, then the second and second-to-last, and so on. For each pair, the values are concatenated together by multiplying the first element by a power of 10 based on the number of digits in the second element.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	  long long findTheArrayConcVal(vector<int>& nums) {
	```
	This is the function definition where `findTheArrayConcVal` accepts a vector of integers and returns a long long integer representing the concatenation value.

2. **Variable Initialization**
	```cpp
	  long long res = 0, sz = nums.size();
	```
	The variables `res` and `sz` are initialized. `res` will hold the final result, and `sz` stores the size of the input array `nums`.

3. **Loop Initialization**
	```cpp
	  for (int i = 0, j = sz - 1; i <= j; ++i, --j)
	```
	A loop is set up where two pointers, `i` and `j`, start from the beginning and end of the array, respectively, and move towards the center. The loop runs as long as `i <= j`.

4. **Conditional Branch**
	```cpp
	      if (i < j)
	```
	Inside the loop, there is a condition checking if `i` is less than `j`, which means there are still two elements to pair.

5. **Concatenation Logic**
	```cpp
	          res += nums[i] * pow(10, (int)log10(nums[j]) + 1) + nums[j];
	```
	If `i < j`, the elements `nums[i]` and `nums[j]` are concatenated by multiplying `nums[i]` by 10 raised to the power of the number of digits in `nums[j]`, then adding `nums[j]`.

6. **Else Condition**
	```cpp
	      else
	```
	If `i` is equal to `j`, there is only one element left, and no concatenation is needed.

7. **Single Element Addition**
	```cpp
	          res += nums[i];
	```
	In this case, simply add the element `nums[i]` to the result as no concatenation is required.

8. **Return Statement**
	```cpp
	  return res;
	```
	After the loop completes, return the accumulated value `res` which represents the concatenated result of the array.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

Since we are processing each pair of elements in the array once, the time complexity is linear, O(n).

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant, O(1), as we are not using any additional space beyond a few variables.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-the-array-concatenation-value/description/)

---
{{< youtube OgX8lEhgW9g >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

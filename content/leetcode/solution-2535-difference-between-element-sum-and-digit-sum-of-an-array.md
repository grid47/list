
+++
authors = ["grid47"]
title = "Leetcode 2535: Difference Between Element Sum and Digit Sum of an Array"
date = "2024-02-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2535: Difference Between Element Sum and Digit Sum of an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "wg-szN5zvr4"
youtube_upload_date="2023-01-15"
youtube_thumbnail="https://i.ytimg.com/vi_webp/wg-szN5zvr4/maxresdefault.webp"
comments = true
+++



---
Given a positive integer array `nums`, compute the absolute difference between the element sum and the digit sum of the elements in the array.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array `nums` containing positive integers.
- **Example:** `[2, 28, 5, 7]`
- **Constraints:**
	- 1 <= nums.length <= 2000
	- 1 <= nums[i] <= 2000

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be the absolute difference between the element sum and the digit sum.
- **Example:** `6`
- **Constraints:**
	- The output will be a non-negative integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to compute the absolute difference between the element sum and digit sum efficiently.

- Calculate the element sum by adding all integers in the `nums` array.
- Calculate the digit sum by summing up each digit of all the integers in the `nums` array.
- Return the absolute difference between the element sum and digit sum.
{{< dots >}}
### Problem Assumptions ✅
- The input array will only contain positive integers.
- The array can be of varying lengths within the specified constraints.
{{< dots >}}
## Examples 🧩
- **Input:** `[2, 28, 5, 7]`  \
  **Explanation:** The element sum is 42, and the digit sum is 24. The absolute difference between them is 6.

- **Input:** `[10, 20, 30]`  \
  **Explanation:** The element sum is 60, and the digit sum is 6. The absolute difference between them is 10.

{{< dots >}}
## Approach 🚀
The approach involves calculating both the element sum and the digit sum, then finding their absolute difference.

### Initial Thoughts 💭
- We need to calculate the sum of integers and the sum of individual digits of each integer.
- We can iterate through the array once to compute both sums efficiently.
{{< dots >}}
### Edge Cases 🌐
- The array will never be empty as `nums.length >= 1`.
- Ensure the solution handles arrays with the maximum length of 2000 efficiently.
- Handle edge cases like single-element arrays, where the element sum and digit sum may be the same.
- Ensure that the solution works for all values within the range of 1 to 2000 for each element.
{{< dots >}}
## Code 💻
```cpp
int dsum(int v) {
return v == 0 ? 0 : v % 10 + dsum(v / 10);
}
int differenceOfSum(vector<int>& n) {
return abs(accumulate(begin(n), end(n), 0) - 
    accumulate(begin(n), end(n), 0, [&](int s, int v){ return s + dsum(v); }));
}
```

The function 'dsum' computes the sum of digits of a number recursively, while 'differenceOfSum' calculates the absolute difference between the sum of the elements and the sum of their digits using accumulators.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int dsum(int v) {
	```
	The function 'dsum' is defined, accepting an integer 'v' as input. This function calculates the sum of the digits of the integer recursively.

2. **Recursive Logic**
	```cpp
	return v == 0 ? 0 : v % 10 + dsum(v / 10);
	```
	The function uses recursion: if 'v' is 0, the base case returns 0. Otherwise, it adds the last digit of 'v' (v % 10) to the result of the recursive call with 'v' divided by 10 (removing the last digit).

3. **Function Definition**
	```cpp
	int differenceOfSum(vector<int>& n) {
	```
	The function 'differenceOfSum' is defined, accepting a vector of integers 'n'. It calculates the absolute difference between the sum of the elements of 'n' and the sum of the digits of each element.

4. **Accumulate**
	```cpp
	return abs(accumulate(begin(n), end(n), 0) - 
	```
	The 'accumulate' function computes the sum of the elements in the vector 'n'. The result is subtracted from the sum of the digits of each element in 'n'. The 'abs' function is used to return the absolute value of the result.

5. **Accumulate with Lambda**
	```cpp
	    accumulate(begin(n), end(n), 0, [&](int s, int v){ return s + dsum(v); }));
	```
	This part uses another 'accumulate' to sum the results of applying 'dsum' to each element in 'n'. The lambda function takes the sum accumulator 's' and each element 'v', and adds the result of 'dsum(v)' to 's'.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the length of the `nums` array, since we perform a linear scan to compute both sums.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) since we only need a few variables to hold the sums, irrespective of the size of the input.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/difference-between-element-sum-and-digit-sum-of-an-array/description/)

---
{{< youtube wg-szN5zvr4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

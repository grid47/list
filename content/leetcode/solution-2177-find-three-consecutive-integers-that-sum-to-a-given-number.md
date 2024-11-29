
+++
authors = ["grid47"]
title = "Leetcode 2177: Find Three Consecutive Integers That Sum to a Given Number"
date = "2024-04-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2177: Find Three Consecutive Integers That Sum to a Given Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "DMBWjfh33wY"
youtube_upload_date="2022-02-20"
youtube_thumbnail="https://i.ytimg.com/vi_webp/DMBWjfh33wY/maxresdefault.webp"
comments = true
+++



---
Given an integer `num`, your task is to determine if it can be expressed as the sum of three consecutive integers. If it can, return these integers as a sorted array. If not, return an empty array.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a single integer `num`.
- **Example:** `27`
- **Constraints:**
	- 0 <= num <= 10^15

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is either an array containing the three consecutive integers that sum to `num` or an empty array if no such triplet exists.
- **Example:** `[8, 9, 10]`
- **Constraints:**
	- The output must be a sorted array of three consecutive integers or an empty array.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find if `num` can be written as the sum of three consecutive integers.

- Check if `num` is divisible by 3.
- If `num` is divisible by 3, calculate the three consecutive integers using `num / 3 - 1`, `num / 3`, and `num / 3 + 1`.
- If not, return an empty array.
{{< dots >}}
### Problem Assumptions ✅
- The integer `num` is non-negative.
{{< dots >}}
## Examples 🧩
- **Input:** `27`  \
  **Explanation:** The number 27 can be expressed as 8 + 9 + 10. These are three consecutive integers that sum to 27.

{{< dots >}}
## Approach 🚀
The approach involves checking if the given number is divisible by 3, then finding the three consecutive integers that sum to the number.

### Initial Thoughts 💭
- The sum of three consecutive integers is always divisible by 3.
- Check if `num` is divisible by 3, then simply return the three integers. If not, return an empty array.
{{< dots >}}
### Edge Cases 🌐
- The input `num` is always non-negative and within the specified range.
- The solution should handle very large numbers, as `num` can be as large as 10^15.
- Consider the case when `num` is 0, as the sum of three consecutive integers can't result in 0.
- Ensure that the solution works within the input constraints.
{{< dots >}}
## Code 💻
```cpp
vector<long long> sumOfThree(long long num) {
    vector<long long> ans;
    if(num %3 != 0) return ans;
    return {num / 3 - 1, num/ 3, num/3 + 1};
}
```

This function, `sumOfThree`, takes an integer `num` and returns a vector of three integers if `num` is divisible by 3. If `num` is not divisible by 3, it returns an empty vector. The returned values are three consecutive integers centered around `num/3`.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<long long> sumOfThree(long long num) {
	```
	Define the function `sumOfThree` that takes a single long long integer `num` and returns a vector of long long integers.

2. **Variable Initialization**
	```cpp
	    vector<long long> ans;
	```
	Initialize an empty vector `ans` to store the result if `num` is divisible by 3.

3. **Condition Check**
	```cpp
	    if(num %3 != 0) return ans;
	```
	Check if `num` is divisible by 3. If not, return the empty vector `ans`.

4. **Return Result**
	```cpp
	    return {num / 3 - 1, num/ 3, num/3 + 1};
	```
	If `num` is divisible by 3, return a vector containing three integers: `num/3 - 1`, `num/3`, and `num/3 + 1`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(1)
- **Worst Case:** O(1)

The time complexity is constant because the solution only requires a simple modulo check and arithmetic operations.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant because we are only storing a fixed number of integers.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-three-consecutive-integers-that-sum-to-a-given-number/description/)

---
{{< youtube DMBWjfh33wY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

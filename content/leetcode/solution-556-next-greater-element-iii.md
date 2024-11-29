
+++
authors = ["grid47"]
title = "Leetcode 556: Next Greater Element III"
date = "2024-09-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 556: Next Greater Element III in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Two Pointers","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/556.webp"
youtube = "-Ehc8QF1eac"
youtube_upload_date="2021-03-04"
youtube_thumbnail="https://i.ytimg.com/vi/-Ehc8QF1eac/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/556.webp" 
    alt="A sequence of numbers where each next greater element softly illuminates as it’s found for the next number."
    caption="Solution to LeetCode 556: Next Greater Element III Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given a positive integer n, find the smallest integer which can be formed by rearranging the digits of n and is greater than n. If no such integer exists, return -1.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a positive integer n, which can be up to 2^31-1.
- **Example:** `Input: n = 123`
- **Constraints:**
	- 1 <= n <= 2^31 - 1

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be the smallest integer greater than n formed by rearranging its digits, or -1 if no such integer exists.
- **Example:** `Output: 132`
- **Constraints:**
	- The returned value should be within the 32-bit signed integer range.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the smallest integer greater than n that can be formed using the digits of n.

- Convert n to a string of digits.
- Find the next permutation of the digits that is greater than n.
- If such a permutation exists and it fits within the 32-bit integer range, return it.
- If no permutation is possible or the resulting number exceeds the 32-bit limit, return -1.
{{< dots >}}
### Problem Assumptions ✅
- The input will always be a valid positive integer within the specified range.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: n = 123`  \
  **Explanation:** The next permutation of the digits of 123 is 132, which is the smallest number greater than 123 that can be formed.

- **Input:** `Input: n = 321`  \
  **Explanation:** Since no larger number can be formed with the digits of 321, the answer is -1.

{{< dots >}}
## Approach 🚀
The approach involves finding the next permutation of the digits of n that is greater than n. If no such permutation exists, return -1.

### Initial Thoughts 💭
- Finding the next permutation is a well-known algorithmic problem. It requires rearranging digits to find the smallest number greater than the current number.
- The algorithm can be implemented using a series of steps that involve finding a digit that can be swapped to form the next greater number.
{{< dots >}}
### Edge Cases 🌐
- There are no empty inputs as n is always a valid positive integer.
- The solution should handle the maximum value of n (2^31-1) without exceeding the 32-bit integer limit.
- For values like 999, no next permutation is possible, and the result should be -1.
- The algorithm must be efficient to handle large inputs within the problem constraints.
{{< dots >}}
## Code 💻
```cpp
int nextGreaterElement(int n) {
    auto digits = to_string(n);
    next_permutation(begin(digits), end(digits));
    auto res = stoll(digits);
    return (res > INT_MAX || res <= n)? -1: res;
}
```

This function finds the next greater number that can be formed by rearranging the digits of the input integer `n`. If no such number exists, it returns -1. It uses string manipulation and the next permutation algorithm to generate the next arrangement of digits.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int nextGreaterElement(int n) {
	```
	Defines the function `nextGreaterElement`, which takes an integer `n` and returns the next greater integer that can be formed by rearranging its digits.

2. **String Conversion**
	```cpp
	    auto digits = to_string(n);
	```
	Converts the integer `n` into a string representation to easily manipulate its digits.

3. **Next Permutation**
	```cpp
	    next_permutation(begin(digits), end(digits));
	```
	Uses the `next_permutation` function to rearrange the digits of the string into the next lexicographically greater permutation.

4. **String to Integer Conversion**
	```cpp
	    auto res = stoll(digits);
	```
	Converts the string `digits` back into an integer using `stoll` (string to long long). This represents the next greater permutation of digits.

5. **Edge Case Handling, Return Statement**
	```cpp
	    return (res > INT_MAX || res <= n)? -1: res;
	```
	Checks if the resulting number exceeds the maximum allowable integer value (`INT_MAX`) or if it's not greater than the original number. If either condition is true, it returns -1, otherwise it returns the next greater number.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(d)
- **Average Case:** O(d)
- **Worst Case:** O(d)

The time complexity is linear in terms of the number of digits, which is at most 10 for a 32-bit integer.

### Space Complexity 💾
- **Best Case:** O(d)
- **Worst Case:** O(d)

The space complexity is O(d) due to the storage of the digits of the integer.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/next-greater-element-iii/description/)

---
{{< youtube -Ehc8QF1eac >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

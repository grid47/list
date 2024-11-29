
+++
authors = ["grid47"]
title = "Leetcode 1238: Circular Permutation in Binary Representation"
date = "2024-07-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1238: Circular Permutation in Binary Representation in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Backtracking","Bit Manipulation"]
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
Given two integers n and start, return a permutation of the integers from 0 to 2^n - 1 such that: p[0] = start, each pair of adjacent elements differ by exactly one bit in their binary representation, and p[0] and p[2^n - 1] also differ by exactly one bit.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given two integers n and start.
- **Example:** `n = 2, start = 3`
- **Constraints:**
	- 1 <= n <= 16
	- 0 <= start < 2^n

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a permutation p of integers from 0 to 2^n - 1 such that the required conditions are satisfied.
- **Example:** `[3, 2, 0, 1]`
- **Constraints:**
	- The output should be a permutation of length 2^n.

{{< dots >}}
### Core Logic 🔍
**Goal:** Generate a valid permutation where adjacent numbers differ by one bit.

- Loop through all possible numbers from 0 to 2^n - 1.
- For each number, calculate the corresponding Gray code using the formula.
- Generate the permutation based on the Gray code while ensuring that adjacent numbers differ by exactly one bit.
{{< dots >}}
### Problem Assumptions ✅
- It is assumed that the generated permutation will be in the correct format, starting at the given 'start' value.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: n = 3, start = 2`  \
  **Explanation:** The binary representations of the permutation are (010, 110, 111, 101, 100, 000, 001, 011).

{{< dots >}}
## Approach 🚀
We can generate a circular permutation using Gray code, which ensures that adjacent elements differ by only one bit.

### Initial Thoughts 💭
- Gray code is a binary numeral system where two successive values differ in only one bit.
- This problem can be efficiently solved by generating the Gray code sequence for the range 0 to 2^n - 1.
{{< dots >}}
### Edge Cases 🌐
- Not applicable since n and start are always defined.
- The largest possible value for n is 16, resulting in a permutation of length 65536.
- When start is 0 or 2^n - 1, ensure that the permutation starts and ends with valid elements differing by one bit.
- Time and space complexities must be optimized for the upper bound of n.
{{< dots >}}
## Code 💻
```cpp
vector<int> circularPermutation(int n, int start) {
    vector<int> res;
    for(int i = 0; i < 1 << n; i++)
        res.push_back(start ^ i ^ i >> 1);
    return res;
}
```

This function generates a circular permutation of `n` elements, starting at a given number `start`. The function uses the Gray code algorithm to produce the required permutation.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<int> circularPermutation(int n, int start) {
	```
	The function `circularPermutation` is defined to generate a circular permutation of `n` elements starting from the number `start`.

2. **Result Initialization**
	```cpp
	    vector<int> res;
	```
	A vector `res` is initialized to store the resulting circular permutation.

3. **Loop Setup**
	```cpp
	    for(int i = 0; i < 1 << n; i++)
	```
	A loop is set up to iterate over all possible values for the permutation. The loop runs from `0` to `2^n - 1` (i.e., `1 << n`).

4. **Gray Code Calculation**
	```cpp
	        res.push_back(start ^ i ^ i >> 1);
	```
	The Gray code formula `start ^ i ^ (i >> 1)` is used to generate the next number in the circular permutation, and it is added to the result vector `res`.

5. **Return Result**
	```cpp
	    return res;
	```
	The function returns the vector `res`, which contains the generated circular permutation.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(2^n)
- **Average Case:** O(2^n)
- **Worst Case:** O(2^n)

The solution requires generating all 2^n elements in the permutation, each of which is processed once.

### Space Complexity 💾
- **Best Case:** O(2^n)
- **Worst Case:** O(2^n)

Space is required to store the output permutation of length 2^n.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/circular-permutation-in-binary-representation/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

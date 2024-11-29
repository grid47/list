
+++
authors = ["grid47"]
title = "Leetcode 1017: Convert to Base -2"
date = "2024-07-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1017: Convert to Base -2 in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math"]
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
Given a non-negative integer n, return its binary representation in base -2. The binary string should not have leading zeros unless the result is zero.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a non-negative integer n.
- **Example:** `n = 5`
- **Constraints:**
	- 0 <= n <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the binary representation of n in base -2 as a string.
- **Example:** `Output: '1101'`
- **Constraints:**
	- The output should be a binary string with no leading zeros unless the result is '0'.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to convert the integer n into a binary representation in base -2.

- While n is non-zero, repeatedly divide n by -2 and record the remainders.
- At each step, append the remainder (0 or 1) to the result string.
- For negative n, adjust the division to ensure the remainder is correctly calculated.
{{< dots >}}
### Problem Assumptions ✅
- The input value n is guaranteed to be a valid non-negative integer.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: n = 2`  \
  **Explanation:** In base -2, 2 is represented as '110', since (-2)^2 + (-2)^1 = 2.

- **Input:** `Input: n = 3`  \
  **Explanation:** In base -2, 3 is represented as '111', since (-2)^2 + (-2)^1 + (-2)^0 = 3.

- **Input:** `Input: n = 4`  \
  **Explanation:** In base -2, 4 is represented as '100', since (-2)^2 = 4.

{{< dots >}}
## Approach 🚀
The solution uses repeated division by -2, adjusting for negative remainders, and constructs the binary representation step by step.

### Initial Thoughts 💭
- We need to handle negative bases while ensuring that the binary representation is valid.
- The key challenge is ensuring that the remainder during division is correctly computed for base -2, especially for negative n.
{{< dots >}}
### Edge Cases 🌐
- When n is 0, the output should be '0'.
- When n is very large (e.g., 10^9), the solution should still work efficiently without exceeding time or space limits.
- Ensure that the result does not contain leading zeros unless the value of n is 0.
- The solution must handle n up to 10^9 without performance issues.
{{< dots >}}
## Code 💻
```cpp
string baseNeg2(int n) {
    string res = "";

    while(n) {
        res = to_string(n&1) + res;
        n = -(n >> 1);
    }

    return res == ""? "0":res;
}
```

The function `baseNeg2` converts a given integer `n` into its base -2 representation. The function iteratively calculates the binary digits of `n` in base -2 and constructs the result string. If the input number is zero, the function returns "0".

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	string baseNeg2(int n) {
	```
	Declares the function `baseNeg2` that takes an integer `n` as input and returns a string representing the base -2 representation of `n`.

2. **Variable Initialization**
	```cpp
	    string res = "";
	```
	Initializes an empty string `res` to store the result of the base -2 conversion.

3. **While Loop Start**
	```cpp
	    while(n) {
	```
	Starts a while loop that continues until `n` becomes 0. The loop will calculate the binary digits of `n` in base -2.

4. **Binary Calculation**
	```cpp
	        res = to_string(n&1) + res;
	```
	Calculates the least significant bit (LSB) of `n` by performing a bitwise AND with 1 (`n & 1`), converts it to a string, and appends it to the front of `res`.

5. **Shift and Negate**
	```cpp
	        n = -(n >> 1);
	```
	Performs a right shift on `n` by 1 bit (`n >> 1`) to prepare for the next iteration. The result is negated (`-`) because the number is in base -2.

6. **Return Statement**
	```cpp
	    return res == ""? "0":res;
	```
	Checks if the result string `res` is empty (which means the input was 0) and returns "0". Otherwise, it returns the constructed base -2 representation stored in `res`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(log n)
- **Average Case:** O(log n)
- **Worst Case:** O(log n)

The time complexity is O(log n) since the number of divisions required is proportional to the logarithm of n.

### Space Complexity 💾
- **Best Case:** O(log n)
- **Worst Case:** O(log n)

The space complexity is O(log n) due to the space needed for storing the binary representation of n.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/convert-to-base-2/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

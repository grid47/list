
+++
authors = ["grid47"]
title = "Leetcode 342: Power of Four"
date = "2024-10-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 342: Power of Four in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Bit Manipulation","Recursion"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/342.webp"
youtube = "qEYZPwnlM0U"
youtube_upload_date="2023-10-23"
youtube_thumbnail="https://i.ytimg.com/vi/qEYZPwnlM0U/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/342.webp" 
    alt="A glowing series of numbers where each number doubles and highlights the powers of four along the way."
    caption="Solution to LeetCode 342: Power of Four Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given an integer n, return true if it is a power of four. Otherwise, return false. An integer n is a power of four if there exists an integer x such that n == 4^x.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is an integer n.
- **Example:** `n = 64`
- **Constraints:**
	- -2^31 <= n <= 2^31 - 1

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is a boolean value indicating whether n is a power of four.
- **Example:** `true`
- **Constraints:**
	- The result is true if n is a power of four, otherwise false.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to determine if n is a power of four using efficient conditions.

- Check if the number is greater than 0.
- Ensure that the number is a power of 2 by using the bitwise AND operation.
- Ensure that the number minus one is divisible by 3.
{{< dots >}}
### Problem Assumptions ✅
- The input integer n is within the valid range of 32-bit signed integers.
{{< dots >}}
## Examples 🧩
- **Input:** `n = 64`  \
  **Explanation:** 64 is a power of four, as 64 = 4^3.

- **Input:** `n = 12`  \
  **Explanation:** 12 is not a power of four, so the result is false.

- **Input:** `n = 1`  \
  **Explanation:** 1 is a power of four, as 4^0 = 1.

{{< dots >}}
## Approach 🚀
The approach to solving this problem involves using bitwise operations to check if the number is a power of four.

### Initial Thoughts 💭
- A number is a power of four if it is greater than 0 and if only one bit is set to 1 in its binary representation.
- We can use bitwise AND to check if a number is a power of two and verify divisibility by 3 for powers of four.
{{< dots >}}
### Edge Cases 🌐
- If n is less than or equal to zero, it cannot be a power of four.
- Large inputs within the valid range should be handled without overflow or errors.
- The edge case where n = 1 should return true as 4^0 = 1.
- The solution must run in constant time, O(1).
{{< dots >}}
## Code 💻
```cpp
bool isPowerOfFour(int num) {
    return num > 0 && (num & (num - 1)) == 0 && (num - 1) % 3 == 0;
}
```

This function checks if a given integer `num` is a power of four. It first ensures the number is positive, then it checks if it is a power of two (using a bitwise AND), and finally verifies if it is a power of four by checking if `num - 1` is divisible by 3.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	bool isPowerOfFour(int num) {
	```
	This is the function declaration. It takes an integer `num` and returns a boolean value indicating whether `num` is a power of four.

2. **Return Statement**
	```cpp
	    return num > 0 && (num & (num - 1)) == 0 && (num - 1) % 3 == 0;
	```
	The return statement checks three conditions: first, that `num` is positive, second, that `num` is a power of two (by using the bitwise AND operation), and third, that `num - 1` is divisible by 3, ensuring that it is a power of four.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(1)
- **Worst Case:** O(1)

The time complexity is constant because the solution involves only bitwise operations.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant because only a few variables are used.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/power-of-four/description/)

---
{{< youtube qEYZPwnlM0U >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

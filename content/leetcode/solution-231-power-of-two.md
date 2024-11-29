
+++
authors = ["grid47"]
title = "Leetcode 231: Power of Two"
date = "2024-10-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 231: Power of Two in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Bit Manipulation","Recursion"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/231.webp"
youtube = "lGxiqzurnNU"
youtube_upload_date="2020-06-08"
youtube_thumbnail="https://i.ytimg.com/vi/lGxiqzurnNU/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/231.webp" 
    alt="A series of glowing numbers doubling, each number expanding into the next power of two."
    caption="Solution to LeetCode 231: Power of Two Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given an integer n, determine if it is a power of two. An integer n is considered a power of two if there exists an integer x such that n == 2^x.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a single integer n (−2^31 <= n <= 2^31 − 1).
- **Example:** `Input: n = 8`
- **Constraints:**
	- -2^31 <= n <= 2^31 - 1

{{< dots >}}
### Output Specifications 📤
- **Output:** Return true if n is a power of two, otherwise return false.
- **Example:** `Output: true`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to verify whether the number n is a power of two using bit manipulation.

- Check if n is less than or equal to zero, in which case it is not a power of two.
- Perform a bitwise AND operation between n and (n - 1). If the result is zero, then n is a power of two.
{{< dots >}}
### Problem Assumptions ✅
- The input will be a valid integer within the specified range.
- n may be negative or zero, but only positive values can be a power of two.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: n = 8`  \
  **Explanation:** Since 8 can be written as 2^3, it is a power of two. Thus, the output is true.

- **Input:** `Input: n = 5`  \
  **Explanation:** 5 cannot be written as 2^x for any integer x, so the output is false.

{{< dots >}}
## Approach 🚀
We can solve this problem using bit manipulation to determine if n is a power of two.

### Initial Thoughts 💭
- A number n is a power of two if it has exactly one bit set in its binary representation.
- Using the bitwise AND operation (n & (n - 1)), we can quickly check if a number is a power of two. This operation will return zero only for numbers that are powers of two.
{{< dots >}}
### Edge Cases 🌐
- No empty inputs are possible since the input is an integer.
- For large values of n, ensure the solution works within the given integer range.
- If n is 0 or negative, it cannot be a power of two.
- Ensure that the solution works efficiently within the given constraints.
{{< dots >}}
## Code 💻
```cpp
bool isPowerOfTwo(int n) {
    if(n <= 0) return false;
    return !(n & (n - 1));
}
```

This function checks if a number is a power of two using a bitwise operation.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool isPowerOfTwo(int n) {
	```
	Defines the function `isPowerOfTwo` that takes an integer `n` as input and returns a boolean value indicating whether `n` is a power of two.

2. **Condition Check**
	```cpp
	    if(n <= 0) return false;
	```
	Checks if `n` is less than or equal to 0, in which case it cannot be a power of two. If true, returns `false`.

3. **Bitwise Operation**
	```cpp
	    return !(n & (n - 1));
	```
	Uses a bitwise AND operation between `n` and `n-1` to check if only one bit is set in `n`. If true, the number is a power of two, and it returns `true`; otherwise, it returns `false`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(1)
- **Worst Case:** O(1)

The time complexity is constant, O(1), because we are performing only one bitwise operation to check if the number is a power of two.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant, O(1), because we are using only a few variables and no additional data structures.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/power-of-two/description/)

---
{{< youtube lGxiqzurnNU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

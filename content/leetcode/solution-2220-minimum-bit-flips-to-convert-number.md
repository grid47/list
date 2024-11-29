
+++
authors = ["grid47"]
title = "Leetcode 2220: Minimum Bit Flips to Convert Number"
date = "2024-03-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2220: Minimum Bit Flips to Convert Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Bit Manipulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "yz48myznqQY"
youtube_upload_date="2024-09-11"
youtube_thumbnail="https://i.ytimg.com/vi/yz48myznqQY/maxresdefault.jpg"
comments = true
+++



---
You are given two integers, `start` and `goal`. The task is to determine the minimum number of bit flips required to convert `start` into `goal`. A bit flip consists of choosing a bit in the binary representation of a number and flipping it from 0 to 1 or from 1 to 0.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given two integers, `start` and `goal`, representing the two numbers to be compared.
- **Example:** `start = 5, goal = 10`
- **Constraints:**
	- 0 <= start, goal <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of bit flips required to convert `start` into `goal`.
- **Example:** `Output: 3`
- **Constraints:**
	- Both `start` and `goal` are non-negative integers.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to compute how many bits differ between `start` and `goal`.

- XOR the two numbers `start` and `goal` to get the positions where the bits differ.
- Count the number of 1s in the result of the XOR operation, which represents the bits that differ.
{{< dots >}}
### Problem Assumptions ✅
- The inputs are non-negative integers.
- The problem requires calculating the number of bit flips, which is based on bitwise operations.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: start = 5, goal = 10`  \
  **Explanation:** The binary representation of 5 is 101, and the binary representation of 10 is 1010. To convert 5 to 10, flip the first, second, and fourth bits to get the number 1010, so the minimum number of bit flips is 3.

{{< dots >}}
## Approach 🚀
The approach involves using the XOR operation to identify which bits differ between `start` and `goal`, and then counting the number of differing bits.

### Initial Thoughts 💭
- The XOR operation will set a bit to 1 wherever the bits in `start` and `goal` differ.
- Counting the number of 1s in the result of XOR will give us the number of bit flips required.
- We need to perform the XOR operation between `start` and `goal` and count the number of bits set to 1 in the result.
{{< dots >}}
### Edge Cases 🌐
- The case where both `start` and `goal` are zero should return 0, as no bit flips are needed.
- The solution must handle large values for `start` and `goal`, up to 10^9.
- If `start` and `goal` are the same, the result should be 0, as no bit flips are needed.
- The solution must efficiently handle large input sizes.
{{< dots >}}
## Code 💻
```cpp
int minBitFlips(int start, int goal) {
    return __builtin_popcount(start^goal);
}
```

The function `minBitFlips` computes the minimum number of bit flips required to convert the integer `start` to `goal`. It uses the built-in `__builtin_popcount` function to count the number of bits that differ between `start` and `goal` after performing a bitwise XOR operation.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int minBitFlips(int start, int goal) {
	```
	This is the function declaration for `minBitFlips`, which takes two integers, `start` and `goal`, and returns the minimum number of bit flips required to convert `start` into `goal`.

2. **Bitwise Operation and Count**
	```cpp
	    return __builtin_popcount(start^goal);
	```
	The bitwise XOR operation `start^goal` is performed to identify the differing bits between the two integers. The function `__builtin_popcount` is then used to count how many bits are set to 1, which represents the number of bit flips needed.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1), when `start` and `goal` are the same.
- **Average Case:** O(1), as bitwise operations and popcount are constant-time operations for fixed-size integers.
- **Worst Case:** O(1), as the XOR operation and bit count are independent of the size of the integers within the 32-bit or 64-bit limit.

The time complexity is constant for each operation.

### Space Complexity 💾
- **Best Case:** O(1), as no additional space is required.
- **Worst Case:** O(1), as the solution uses constant space regardless of input size.

The space complexity is constant, as no extra storage is needed beyond the input and output.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-bit-flips-to-convert-number/description/)

---
{{< youtube yz48myznqQY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

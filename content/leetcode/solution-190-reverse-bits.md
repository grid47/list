
+++
authors = ["grid47"]
title = "Leetcode 190: Reverse Bits"
date = "2024-10-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 190: Reverse Bits in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Divide and Conquer","Bit Manipulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/190.webp"
youtube = "epFf0wlbng0"
youtube_upload_date="2020-07-13"
youtube_thumbnail="https://i.ytimg.com/vi/epFf0wlbng0/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/190.webp" 
    alt="A series of bits glowing as they reverse, shifting smoothly from 1 to 0 and back."
    caption="Solution to LeetCode 190: Reverse Bits Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given a 32-bit unsigned integer, reverse its bits and return the result as an unsigned integer.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a 32-bit unsigned integer.
- **Example:** `n = 00000000000000000000000010011010`
- **Constraints:**
	- The input is a 32-bit unsigned integer.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is the 32-bit unsigned integer obtained by reversing the bits of the input integer.
- **Example:** `n = 11259375`
- **Constraints:**
	- The result should be returned as an unsigned integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to reverse the bits of the given 32-bit unsigned integer and return the result.

- Step 1: Perform bitwise manipulations to reverse the bits of the integer.
- Step 2: Apply bit shifting and masking to reverse pairs, nibbles, bytes, etc.
- Step 3: Return the result after all bitwise reversals.
{{< dots >}}
### Problem Assumptions ✅
- The input is a valid 32-bit unsigned integer.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: n = 00000000000000000000000010011010`  \
  **Explanation:** The binary string represents the integer 250. Reversing the bits results in the output integer 11259375, whose binary representation is 0000000000000000101011001010000.

{{< dots >}}
## Approach 🚀
To solve this problem, we use bitwise operations to reverse the bits of the integer efficiently.

### Initial Thoughts 💭
- We can use a series of bitwise operations like shifting and masking to reverse the bits.
- Reversing bits requires operations that progressively swap and shift bits to their correct positions.
{{< dots >}}
### Edge Cases 🌐
- The input is always a 32-bit unsigned integer, so no empty inputs are possible.
- The input is a fixed 32-bit integer, so no large inputs are required.
- Ensure the input is a valid unsigned 32-bit integer (i.e., values between 0 and 4294967295).
- Input is always a 32-bit unsigned integer.
{{< dots >}}
## Code 💻
```cpp
uint32_t reverseBits(uint32_t n) {
    n = (n & 0xffffffff) << 16 | (n & 0xffffffff) >> 16;
    n = (n & 0x00ff00ff) << 8  | (n & 0xff00ff00) >> 8;
    n = (n & 0x0f0f0f0f) << 4  | (n & 0xf0f0f0f0) >> 4;
    n = (n & 0x33333333) << 2  | (n & 0xcccccccc) >> 2;
    n = (n & 0x55555555) << 1  | (n & 0xaaaaaaaa) >> 1;        
    return n;
}
```

This function reverses the bits of a 32-bit unsigned integer 'n'. It uses bitwise operations and shifting to swap corresponding bit positions from the left and right, progressively working towards the center.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	uint32_t reverseBits(uint32_t n) {
	```
	Define the function 'reverseBits' which takes a 32-bit unsigned integer 'n' and returns its bit-reversed value.

2. **Bitwise Operation**
	```cpp
	    n = (n & 0xffffffff) << 16 | (n & 0xffffffff) >> 16;
	```
	Perform a bitwise AND operation with '0xffffffff' to isolate all bits, then shift the left and right halves of 'n' to reverse their positions.

3. **Bitwise Operation**
	```cpp
	    n = (n & 0x00ff00ff) << 8  | (n & 0xff00ff00) >> 8;
	```
	Shift the nibbles (4-bit sections) of 'n' by 8 positions, swapping each pair of adjacent nibbles.

4. **Bitwise Operation**
	```cpp
	    n = (n & 0x0f0f0f0f) << 4  | (n & 0xf0f0f0f0) >> 4;
	```
	Shift the 4-bit blocks of 'n' by 4 positions, swapping adjacent blocks.

5. **Bitwise Operation**
	```cpp
	    n = (n & 0x33333333) << 2  | (n & 0xcccccccc) >> 2;
	```
	Shift the 2-bit pairs of 'n' by 2 positions, swapping each pair of bits.

6. **Bitwise Operation**
	```cpp
	    n = (n & 0x55555555) << 1  | (n & 0xaaaaaaaa) >> 1;        
	```
	Shift individual bits of 'n' by 1 position, swapping bits in each pair.

7. **Return Statement**
	```cpp
	    return n;
	```
	Return the bit-reversed value of 'n'.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(1)
- **Worst Case:** O(1)

The time complexity is O(1), as the number of operations is constant due to the fixed size of the input (32 bits).

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1), as we only need a fixed amount of space to store the result.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/reverse-bits/description/)

---
{{< youtube epFf0wlbng0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |


+++
authors = ["grid47"]
title = "Leetcode 191: Number of 1 Bits"
date = "2024-10-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 191: Number of 1 Bits in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Divide and Conquer","Bit Manipulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/191.webp"
youtube = "1JfdvPk-iHg"
youtube_upload_date="2024-08-22"
youtube_thumbnail="https://i.ytimg.com/vi_webp/1JfdvPk-iHg/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/191.webp" 
    alt="A glowing sequence of bits, with 1's gently illuminating and highlighting their presence."
    caption="Solution to LeetCode 191: Number of 1 Bits Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given a positive integer n, return the number of set bits (1s) in its binary representation, also known as the Hamming weight.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a positive integer n.
- **Example:** `n = 9`
- **Constraints:**
	- The integer n is between 1 and 2^31 - 1.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is the number of set bits (1s) in the binary representation of the integer n.
- **Example:** `Output = 2`
- **Constraints:**
	- The output is a single integer representing the number of set bits.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to count the number of set bits in the binary representation of the integer n.

- Step 1: Use bitwise operations to efficiently count the number of set bits.
- Step 2: Continuously remove the lowest set bit from n and increment the count until n becomes zero.
- Step 3: Return the count of set bits.
{{< dots >}}
### Problem Assumptions ✅
- The input integer is always a positive number within the specified range.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: n = 9`  \
  **Explanation:** The binary representation of 9 is 1001, which has two set bits, so the output is 2.

{{< dots >}}
## Approach 🚀
We can solve this problem using bitwise operations to count the number of set bits in the integer's binary representation.

### Initial Thoughts 💭
- We can use a bitwise trick to remove the lowest set bit of the number and count how many times this operation can be performed.
- By using n = n & (n - 1), we can eliminate the rightmost set bit in each iteration until all bits are processed.
{{< dots >}}
### Edge Cases 🌐
- The input is always a valid positive integer, so there are no empty inputs.
- Since n is constrained between 1 and 2^31 - 1, large inputs are not an issue.
- If n is a power of 2 (e.g., 1, 2, 4, 8, 16, ...), the binary representation will have only one set bit.
- The input is always a positive integer.
{{< dots >}}
## Code 💻
```cpp
int hammingWeight(uint32_t n) {
    int key = 0;
    while(n) {
        n = n & (n - 1);
        key++;
    }
    return key;
}
```

This function calculates the Hamming Weight (the number of 1 bits) in the binary representation of an unsigned integer 'n'. The approach uses a bit manipulation technique where the least significant 1 bit is cleared in each iteration until 'n' becomes zero.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int hammingWeight(uint32_t n) {
	```
	Define the function 'hammingWeight' that takes a 32-bit unsigned integer 'n' and returns the count of 1 bits in its binary representation.

2. **Variable Initialization**
	```cpp
	    int key = 0;
	```
	Initialize a variable 'key' to zero, which will be used to count the number of 1 bits in the binary representation of 'n'.

3. **Loop Iteration**
	```cpp
	    while(n) {
	```
	Start a while loop that continues until 'n' becomes zero. The loop iterates through each 1 bit in 'n'.

4. **Bitwise Operation**
	```cpp
	        n = n & (n - 1);
	```
	Apply the bitwise AND operation between 'n' and 'n-1'. This operation clears the least significant 1 bit in 'n'.

5. **Count Increment**
	```cpp
	        key++;
	```
	Increment the 'key' variable to count the number of 1 bits encountered so far.

6. **Return Statement**
	```cpp
	    return key;
	```
	Return the final count of 1 bits stored in 'key'.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(k), where k is the number of set bits in n.
- **Worst Case:** O(32), in the worst case when all bits are set to 1.

The time complexity is O(k), where k is the number of set bits, because we process each set bit individually. In the worst case, k is at most 32.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1), as we only need a constant amount of space for the count variable.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-1-bits/description/)

---
{{< youtube 1JfdvPk-iHg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

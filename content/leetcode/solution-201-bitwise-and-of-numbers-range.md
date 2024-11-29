
+++
authors = ["grid47"]
title = "Leetcode 201: Bitwise AND of Numbers Range"
date = "2024-10-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 201: Bitwise AND of Numbers Range in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/201.webp"
youtube = "vZkutwUrPgE"
youtube_upload_date="2020-04-23"
youtube_thumbnail="https://i.ytimg.com/vi_webp/vZkutwUrPgE/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/201.webp" 
    alt="A series of overlapping circles, each representing a number, with a soft intersection of glowing bits in the middle."
    caption="Solution to LeetCode 201: Bitwise AND of Numbers Range Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given two integers, left and right, representing a range [left, right], you need to calculate the bitwise AND of all numbers within that range, inclusive. The bitwise AND operation takes two numbers and returns a number where each bit is set to 1 if the corresponding bits of both numbers are also 1.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two integers: left and right, representing the range [left, right].
- **Example:** `left = 10, right = 12`
- **Constraints:**
	- 0 <= left <= right <= 231 - 1

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the result of the bitwise AND operation of all numbers between left and right, inclusive.
- **Example:** `Output: 8`
- **Constraints:**
	- The output should be a single integer representing the result of the bitwise AND.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to efficiently calculate the bitwise AND of all numbers in the range [left, right].

- Shift the left and right integers to the right until they become equal. Each time they are not equal, shift both numbers to the right by 1 bit.
- Count how many shifts were needed. The final result will be the right-shifted value of either left or right shifted back by the counted number of shifts.
{{< dots >}}
### Problem Assumptions ✅
- Both left and right are within the given constraints.
{{< dots >}}
## Examples 🧩
- **Input:** `left = 10, right = 12`  \
  **Explanation:** In this example, the numbers between 10 and 12 are 10, 11, and 12. The bitwise AND of these numbers is 8, because 10 (1010 in binary), 11 (1011 in binary), and 12 (1100 in binary) all share the prefix 1000.

- **Input:** `left = 0, right = 0`  \
  **Explanation:** If left and right are both 0, the bitwise AND of the range [0, 0] is 0.

- **Input:** `left = 1, right = 2147483647`  \
  **Explanation:** In this case, the bitwise AND of all numbers from 1 to 2147483647 will result in 0, because at least one bit in every position will be different across such a large range.

{{< dots >}}
## Approach 🚀
To solve the problem efficiently, we can use bitwise operations. The key observation is that as we move from left to right in the range, the bits of the numbers are guaranteed to become different at some point. The bitwise AND operation for such a range will result in a number that preserves only the common prefix of the numbers.

### Initial Thoughts 💭
- The range can be large, so a brute force approach of calculating the AND for every number is inefficient.
- Shifting the numbers to the right and comparing them allows us to determine the common prefix.
- By shifting the numbers to the right, we ensure that we are comparing the most significant bits, where the AND result will change the least. Once the numbers are equal, we can shift them back and return the result.
{{< dots >}}
### Edge Cases 🌐
- The range [0, 0] should return 0.
- For very large ranges, the solution should be efficient enough to handle up to 231 - 1.
- If left equals right, the result is simply left (or right), since the AND of a single number is the number itself.
- Ensure the solution handles large inputs efficiently within the constraints.
{{< dots >}}
## Code 💻
```cpp
int rangeBitwiseAnd(int left, int right) {
int shift = 0;

while(right != left)
{
    right >>= 1 ;
    left  >>= 1;
    shift++;
}

return right << shift;
}
```

This code solves the bitwise AND operation for a range of integers from 'left' to 'right'. It uses bit manipulation by shifting the 'left' and 'right' values until they are equal, and then shifts the result back to restore the original magnitude.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int rangeBitwiseAnd(int left, int right) {
	```
	Define the function 'rangeBitwiseAnd' which takes two integers, 'left' and 'right', and returns the result of the bitwise AND operation for all integers in the range [left, right].

2. **Variable Initialization**
	```cpp
	int shift = 0;
	```
	Initialize a variable 'shift' to track the number of right shifts performed to align 'left' and 'right'.

3. **Loop Condition**
	```cpp
	while(right != left)
	```
	Check if 'right' and 'left' are not equal. If they are different, continue shifting them to the right until they become the same.

4. **Right Shift**
	```cpp
	    right >>= 1 ;
	```
	Perform a right shift on 'right' by 1 bit, effectively halving the value and moving the binary representation to the right.

5. **Left Shift**
	```cpp
	    left  >>= 1;
	```
	Perform a right shift on 'left' by 1 bit, similar to the operation on 'right'. This ensures both numbers are compared at the same binary position.

6. **Shift Counter Increment**
	```cpp
	    shift++;
	```
	Increment the shift counter to keep track of the number of right shifts performed.

7. **Return Shifted Result**
	```cpp
	return right << shift;
	```
	Once 'left' and 'right' are equal, shift the 'right' value back to the left by the number of times we shifted in the loop, effectively returning the bitwise AND result for the entire range.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(log(max(left, right)))
- **Worst Case:** O(log(max(left, right)))

In the worst case, the algorithm performs a logarithmic number of shifts, which corresponds to the number of bits in the largest number.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant because only a few integer variables are used, regardless of the size of the input.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/bitwise-and-of-numbers-range/description/)

---
{{< youtube vZkutwUrPgE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

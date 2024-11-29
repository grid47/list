
+++
authors = ["grid47"]
title = "Leetcode 371: Sum of Two Integers"
date = "2024-09-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 371: Sum of Two Integers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/371.webp"
youtube = "gVUrDV4tZfY"
youtube_upload_date="2021-10-20"
youtube_thumbnail="https://i.ytimg.com/vi/gVUrDV4tZfY/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/371.webp" 
    alt="A set of two glowing numbers adding up to a sum, with each number and their sum softly illuminated."
    caption="Solution to LeetCode 371: Sum of Two Integers Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given two integers `a` and `b`. Return their sum without using the `+` or `-` operators. You must implement the solution using bitwise operations.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two integers `a` and `b`.
- **Example:** `Input: a = 5, b = 7`
- **Constraints:**
	- -1000 <= a, b <= 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the sum of `a` and `b` using bitwise operations without using the `+` or `-` operators.
- **Example:** `Output: 12`
- **Constraints:**
	- The output should be the sum of the two integers using bitwise operations.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to compute the sum of two integers without using the arithmetic operators `+` or `-`.

- 1. Use the bitwise XOR operation (`^`) to add the numbers without carrying over.
- 2. Use the bitwise AND operation (`&`) and shift the result left by one bit to handle the carry.
- 3. Recursively repeat the process until there is no carry left.
{{< dots >}}
### Problem Assumptions ✅
- The integers `a` and `b` are within the specified range of -1000 to 1000.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: a = 5, b = 7
Output: 12`  \
  **Explanation:** The sum of 5 and 7 is computed using bitwise operations. The final result is 12.

{{< dots >}}
## Approach 🚀
The approach uses bitwise operations to add two integers without using `+` or `-`.

### Initial Thoughts 💭
- Bitwise XOR can add numbers without considering carry.
- Bitwise AND followed by a left shift can handle the carry during addition.
- We can recursively apply the bitwise operations until there is no carry left, which ensures the correct sum.
{{< dots >}}
### Edge Cases 🌐
- An input where both `a` and `b` are 0 should return 0.
- Ensure the solution handles the largest and smallest inputs within the given constraints.
- Consider the behavior when one of the numbers is negative or zero.
- The solution should work efficiently within the constraints, handling up to the maximum and minimum values for `a` and `b`.
{{< dots >}}
## Code 💻
```cpp
int getSum(int a, int b) {
    return b == 0? a: getSum(a^b, (a&b)<<1);
}
```

The `getSum` method calculates the sum of two integers `a` and `b` without using the `+` operator. It uses bitwise operations: XOR (`^`) for addition without carry and AND (`&`) for calculating the carry, followed by a left shift to add the carry to the result.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Method Declaration**
	```cpp
	int getSum(int a, int b) {
	```
	This line declares the method `getSum`, which takes two integers `a` and `b`, and returns their sum using bitwise operations.

2. **Recursive Call**
	```cpp
	    return b == 0? a: getSum(a^b, (a&b)<<1);
	```
	The function uses recursion to compute the sum. If `b` is zero, it returns `a` as the result. Otherwise, it recursively calls `getSum`, using the XOR of `a` and `b` for the sum and the left-shifted AND of `a` and `b` for the carry.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1) if the sum is obtained in the first iteration.
- **Average Case:** O(k), where k is the number of bits in the input values (bounded by the size of the integers).
- **Worst Case:** O(k) as each recursive step involves bitwise operations on the integers.

The time complexity is determined by the number of bits in the input integers, as the process continues until there is no carry.

### Space Complexity 💾
- **Best Case:** O(1) as the solution requires a fixed amount of space for the operations.
- **Worst Case:** O(1) because the space used is constant, regardless of the input size.

The space complexity is constant as the solution does not use additional space proportional to the input size.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/sum-of-two-integers/description/)

---
{{< youtube gVUrDV4tZfY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

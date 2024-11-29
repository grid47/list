
+++
authors = ["grid47"]
title = "Leetcode 89: Gray Code"
date = "2024-10-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 89: Gray Code in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Backtracking","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/89.webp"
youtube = "k5UYQtKXJGo"
youtube_upload_date="2022-02-06"
youtube_thumbnail="https://i.ytimg.com/vi/k5UYQtKXJGo/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/89.webp" 
    alt="A peaceful, spiraling Gray code sequence glowing softly as it shifts from one value to the next."
    caption="Solution to LeetCode 89: Gray Code Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given an integer n, generate an n-bit Gray code sequence. A Gray code sequence is a sequence of integers where each integer's binary representation differs from the next one by exactly one bit. The first integer in the sequence is always 0, and every integer appears only once in the sequence. The binary representation of the first and last integers should also differ by exactly one bit.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer n, representing the number of bits in the Gray code sequence.
- **Example:** `Input: n = 3`
- **Constraints:**
	- 1 <= n <= 16

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a list of integers that represent a valid n-bit Gray code sequence.
- **Example:** `Output: [0, 1, 3, 2, 6, 7, 5, 4]`
- **Constraints:**
	- Each integer in the sequence must be a valid n-bit number.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to generate a sequence of integers such that every adjacent pair of integers differs by exactly one bit in their binary representation, and the first and last integers differ by exactly one bit.

- Start with the sequence containing only the integer 0.
- Iteratively generate the next integer by flipping a bit in the binary representation of the integers already in the sequence, ensuring that each new integer differs by exactly one bit from the previous one.
{{< dots >}}
### Problem Assumptions ✅
- The input value n is always within the specified range (1 <= n <= 16).
- The Gray code sequence will be valid for any input within this range.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: n = 2`  \
  **Explanation:** For n = 2, a valid Gray code sequence is [0, 1, 3, 2]. The binary representations are: 00, 01, 11, 10. Each adjacent pair of numbers differs by exactly one bit.

- **Input:** `Input: n = 3`  \
  **Explanation:** For n = 3, a valid Gray code sequence is [0, 1, 3, 2, 6, 7, 5, 4]. The binary representations are: 000, 001, 011, 010, 110, 111, 101, 100. Each adjacent pair of numbers differs by exactly one bit.

{{< dots >}}
## Approach 🚀
To generate the Gray code sequence, we can use an iterative method. Start with a list containing only 0, then iteratively construct the sequence by reflecting the current list and flipping the appropriate bits to generate the new sequence.

### Initial Thoughts 💭
- The Gray code sequence for any given n can be generated from the sequence of n-1 bits by reflecting it and flipping the appropriate bits.
- By iteratively constructing the sequence for smaller bit sizes, we can use previously computed results to generate the Gray code sequence for larger sizes.
{{< dots >}}
### Edge Cases 🌐
- The input will always have a valid value for n (1 <= n <= 16).
- For n = 16, the sequence will contain 65536 integers, so ensure that the algorithm can handle large sequences efficiently.
- For n = 1, the sequence will be [0, 1].
- The Gray code sequence must be valid for any n between 1 and 16.
{{< dots >}}
## Code 💻
```cpp
vector<int> grayCode(int n) {
    vector<int> res = {0};
    for (int i = 0; i < n; i++) {
        int size = res.size();
        for (int j = size - 1; j >= 0; j--) {
            res.push_back(res[j] | (1 << i));
        }
    }
    return res;
}
```

This code generates the Gray code of a given number of bits `n` using a recursive approach.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<int> grayCode(int n) {
	```
	Declares a function `grayCode` that takes an integer `n` representing the number of bits and returns a vector of integers representing the Gray code.

2. **Array Initialization**
	```cpp
	    vector<int> res = {0};
	```
	Initializes a vector `res` to store the Gray code, starting with the initial value 0.

3. **Loop Iteration**
	```cpp
	    for (int i = 0; i < n; i++) {
	```
	Iterates `n` times, where `n` is the number of bits.

4. **Size Calculation**
	```cpp
	        int size = res.size();
	```
	Stores the current size of the `res` vector.

5. **Reverse Loop Iteration**
	```cpp
	        for (int j = size - 1; j >= 0; j--) {
	```
	Iterates over the current `res` vector in reverse order.

6. **Bitwise Operations, Array Manipulation**
	```cpp
	            res.push_back(res[j] | (1 << i));
	```
	Calculates the next Gray code value by taking the current value `res[j]` and OR-ing it with `1 << i`. This effectively adds the `i`-th bit to the current value. The new value is then added to the end of the `res` vector.

7. **Return**
	```cpp
	    return res;
	```
	Returns the final `res` vector containing the generated Gray code.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(2^n), where n is the number of bits. We need to generate 2^n numbers.
- **Average Case:** O(2^n)
- **Worst Case:** O(2^n), since the sequence contains 2^n integers.

The time complexity is linear with respect to the size of the sequence.

### Space Complexity 💾
- **Best Case:** O(2^n)
- **Worst Case:** O(2^n), since we store the entire Gray code sequence.

The space complexity is linear in the number of integers in the Gray code sequence.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/gray-code/description/)

---
{{< youtube k5UYQtKXJGo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

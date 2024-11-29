
+++
authors = ["grid47"]
title = "Leetcode 338: Counting Bits"
date = "2024-10-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 338: Counting Bits in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Dynamic Programming","Bit Manipulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/338.webp"
youtube = "RyBM56RIWrM"
youtube_upload_date="2021-06-07"
youtube_thumbnail="https://i.ytimg.com/vi/RyBM56RIWrM/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/338.webp" 
    alt="A glowing sequence of numbers where each bit is counted and highlighted as part of the total."
    caption="Solution to LeetCode 338: Counting Bits Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an integer n.
- **Example:** `n = 3`
- **Constraints:**
	- 0 <= n <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an array ans such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.
- **Example:** `[0, 1, 1, 2]`
- **Constraints:**
	- The solution must run in linear time O(n).

{{< dots >}}
### Core Logic 🔍
**Goal:** Calculate the number of 1's in the binary representation for each number from 0 to n.

- Initialize an array res of size n + 1 with 0s.
- For each number i from 0 to n, set res[i] = res[i >> 1] + (i & 1).
- Return the array res.
{{< dots >}}
### Problem Assumptions ✅
- The value of n is within the given constraints.
{{< dots >}}
## Examples 🧩
- **Input:** `n = 3`  \
  **Explanation:** For the input n = 3, the binary representations of 0, 1, 2, and 3 are '0', '1', '10', '11'. The number of 1's in these binary numbers are 0, 1, 1, and 2 respectively.

- **Input:** `n = 6`  \
  **Explanation:** For the input n = 6, the binary representations of 0, 1, 2, 3, 4, 5, and 6 are '0', '1', '10', '11', '100', '101', '110'. The number of 1's in these binary numbers are 0, 1, 1, 2, 1, 2, and 2 respectively.

{{< dots >}}
## Approach 🚀
To solve this problem, we can calculate the number of 1's in the binary representation of each integer from 0 to n using an efficient approach.

### Initial Thoughts 💭
- We need to avoid using built-in functions like popcount to solve the problem.
- We can use bitwise operations to compute the number of 1's in a number's binary representation.
{{< dots >}}
### Edge Cases 🌐
- If n = 0, the output should be [0].
- For large values of n (up to 10^5), ensure the solution runs in linear time.
- Consider cases where all the numbers in the range have the same number of 1's in their binary representation, such as n = 0.
- The solution should not exceed O(n) time complexity.
{{< dots >}}
## Code 💻
```cpp
vector<int> countBits(int n) {
    vector<int> res(n + 1, 0);
    for(int i = 0; i <= n; i++) {
        res[i] = res[i >> 1] + (i & 1);
    }
    return res;
}
```

This function calculates the number of 1's (set bits) in the binary representation of all integers from 0 to `n`. The result is stored in a vector, where each index `i` contains the number of set bits in `i`.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<int> countBits(int n) {
	```
	This is the declaration of the `countBits` function, which takes an integer `n` and returns a vector of integers representing the number of set bits (1's) in the binary representation of each integer from 0 to `n`.

2. **Vector Initialization**
	```cpp
	    vector<int> res(n + 1, 0);
	```
	A vector `res` is initialized with `n + 1` elements, all set to 0. This will store the number of set bits for each integer from 0 to `n`.

3. **For Loop Setup**
	```cpp
	    for(int i = 0; i <= n; i++) {
	```
	A `for` loop is used to iterate over all integers from 0 to `n`. In each iteration, the number of set bits in `i` will be calculated.

4. **Bit Calculation**
	```cpp
	        res[i] = res[i >> 1] + (i & 1);
	```
	For each integer `i`, the number of set bits is calculated by shifting `i` right by 1 (`i >> 1`) and adding the least significant bit (`i & 1`). This approach uses dynamic programming to build the solution efficiently.

5. **Return Statement**
	```cpp
	    return res;
	```
	After the loop completes, the vector `res` containing the count of set bits for all integers from 0 to `n` is returned.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear because we only iterate over the numbers from 0 to n once.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) because we store the result in an array of size n + 1.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/counting-bits/description/)

---
{{< youtube RyBM56RIWrM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

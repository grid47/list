
+++
authors = ["grid47"]
title = "Leetcode 1680: Concatenation of Consecutive Binary Numbers"
date = "2024-05-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1680: Concatenation of Consecutive Binary Numbers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Bit Manipulation","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "1ZtYzuWUFwA"
youtube_upload_date="2020-12-06"
youtube_thumbnail="https://i.ytimg.com/vi/1ZtYzuWUFwA/maxresdefault.jpg"
comments = true
+++



---
Given an integer `n`, form a binary string by concatenating the binary representations of all integers from 1 to `n`. Convert this concatenated binary string to its decimal equivalent and return the result modulo 10^9 + 7.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a single integer `n`.
- **Example:** `n = 3`
- **Constraints:**
	- 1 <= n <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the decimal value of the concatenated binary string modulo (10^9 + 7).
- **Example:** `Output: 27`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to compute the decimal value of the concatenated binary representations of integers from 1 to `n` and return the result modulo (10^9 + 7).

- Initialize a variable to store the result.
- Iterate from 1 to `n`, converting each number to its binary form.
- Concatenate the binary representations.
- Convert the concatenated binary string into its decimal form.
- Return the result modulo (10^9 + 7).
{{< dots >}}
### Problem Assumptions ✅
- The input integer `n` is valid and within the specified range.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: n = 3`  \
  **Explanation:** The binary representations of integers 1, 2, and 3 are concatenated as '11011', which corresponds to the decimal value 27.

{{< dots >}}
## Approach 🚀
To solve this problem, we need to calculate the concatenated binary string from integers 1 to `n`, convert it to a decimal number, and return the result modulo (10^9 + 7).

### Initial Thoughts 💭
- We can compute the binary representation of each number and accumulate the result.
- We need to keep track of the length of the binary strings as they are concatenated.
{{< dots >}}
### Edge Cases 🌐
- The input will always have at least one value (1 <= n).
- For large values of `n` (up to (10^5)), the solution must efficiently handle the calculations and prevent overflow.
- There are no special values other than the concatenated binary strings.
- The input size can be large, so the solution must be efficient with respect to time and space.
{{< dots >}}
## Code 💻
```cpp
int concatenatedBinary(int n) {
    
    int mod = (int) 1e9 + 7;
    
    long ans = 0;
    int len = 0;
    for(int i = 1; i <= n; i++) {
        if(__builtin_popcount(i) == 1) len++;
        
        ans = ((ans << len) % mod + i % mod) % mod;
    }
    return ans;
}
```

This function calculates the concatenated binary number of integers from 1 to 'n', applying modulo (1e9 + 7) at each step to prevent overflow.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int concatenatedBinary(int n) {
	```
	Define the function 'concatenatedBinary' that takes an integer 'n' as input and returns a long integer result.

2. **Constant Declaration**
	```cpp
	    int mod = (int) 1e9 + 7;
	```
	Declare and initialize a constant 'mod' with the value 1e9 + 7, which will be used for modulo operations to prevent overflow.

3. **Variable Initialization**
	```cpp
	    long ans = 0;
	```
	Initialize a variable 'ans' of type long to store the final result of the concatenated binary numbers.

4. **Variable Initialization**
	```cpp
	    int len = 0;
	```
	Initialize a variable 'len' to store the length of the binary representation of numbers with exactly one bit set.

5. **Loop Setup**
	```cpp
	    for(int i = 1; i <= n; i++) {
	```
	Start a loop from 1 to 'n' to process each integer 'i'.

6. **Condition Check**
	```cpp
	        if(__builtin_popcount(i) == 1) len++;
	```
	Check if the number 'i' has exactly one bit set in its binary representation using the built-in function '__builtin_popcount'. If true, increment 'len'.

7. **String Manipulation**
	```cpp
	        ans = ((ans << len) % mod + i % mod) % mod;
	```
	Perform a bit-shifting operation on 'ans' to concatenate the binary of 'i' and add it to 'ans'. Apply modulo 'mod' at each step to avoid overflow.

8. **Return Statement**
	```cpp
	    return ans;
	```
	Return the final value of 'ans', which represents the concatenated binary number modulo (1e9 + 7).

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The algorithm iterates over all numbers from 1 to `n`, and for each number, it performs a constant-time operation.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) as we only need a few variables to store intermediate results.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/description/)

---
{{< youtube 1ZtYzuWUFwA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

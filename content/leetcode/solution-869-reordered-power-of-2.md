
+++
authors = ["grid47"]
title = "Leetcode 869: Reordered Power of 2"
date = "2024-08-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 869: Reordered Power of 2 in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Math","Sorting","Counting","Enumeration"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "rJu123dgDy8"
youtube_upload_date="2019-08-29"
youtube_thumbnail="https://i.ytimg.com/vi_webp/rJu123dgDy8/maxresdefault.webp"
comments = true
+++



---
Given an integer `n`, check if it is possible to reorder its digits (in any order, including the original order) to form a number that is a power of two. Leading digits cannot be zero in the reordered number.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** A single positive integer `n`.
- **Example:** `Input: n = 32`
- **Constraints:**
	- 1 <= n <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return `true` if it is possible to reorder the digits of `n` to form a power of two, otherwise return `false`.
- **Example:** `Output: true`
- **Constraints:**
	- The output is a boolean value.

{{< dots >}}
### Core Logic 🔍
**Goal:** Determine if a permutation of the digits of `n` can result in a power of two.

- Count the frequency of each digit in `n`.
- Iterate through all powers of two up to the maximum possible value within the constraints.
- Check if the frequency of digits in any power of two matches the frequency of digits in `n`.
- If a match is found, return `true`; otherwise, return `false`.
{{< dots >}}
### Problem Assumptions ✅
- The input `n` is always a valid positive integer within the specified range.
- The number can be represented in base 10 without truncation.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: n = 46`  \
  **Explanation:** The number 46 can be reordered to form 64, which is 2^6. Therefore, the output is `true`.

- **Input:** `Input: n = 123`  \
  **Explanation:** The number 123 cannot be reordered to form any power of two. Therefore, the output is `false`.

- **Input:** `Input: n = 8`  \
  **Explanation:** The number 8 is already a power of two (2^3). Therefore, the output is `true`.

{{< dots >}}
## Approach 🚀
Use a frequency-based approach to compare the digit counts of `n` with the digit counts of all powers of two within the constraints.

### Initial Thoughts 💭
- A number can only be a power of two if its digits can be reordered to match the digits of an actual power of two.
- There are only 31 powers of two to consider since 2^30 is slightly over 10^9.
- Compare the digit frequencies of `n` with precomputed digit frequencies of all powers of two.
{{< dots >}}
### Edge Cases 🌐
- Not applicable as `n` is always provided.
- Inputs near the upper limit of 10^9 should be handled efficiently.
- Inputs like `n = 1` should return `true` since 1 is 2^0.
- Inputs like `n = 0` (if allowed) should return `false` since 0 cannot be a power of two.
- Ensure that leading zeros in permutations are not allowed.
{{< dots >}}
## Code 💻
```cpp
bool reorderedPowerOf2(int n) {
    int c = counter(n);
    for(int i = 0; i < 32; i++)
        if(counter(1<<i) == c) return true;
    return false;
}

int counter(int N) {
    int res = 0;
    for(;N; N/=10) res += pow(10, N%10);
    return res;
}
```

This code defines a function `reorderedPowerOf2` to check if a number can be rearranged into a power of 2 by comparing the digit counts of the number and powers of 2.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool reorderedPowerOf2(int n) {
	```
	Defines the `reorderedPowerOf2` function, which checks if the number `n` can be rearranged into a power of 2.

2. **Counter Function Call**
	```cpp
	    int c = counter(n);
	```
	Calls the helper function `counter` to calculate the digit count signature of `n`.

3. **Loop Setup**
	```cpp
	    for(int i = 0; i < 32; i++)
	```
	Starts a loop to check the 32 possible powers of 2 (from 2^0 to 2^31).

4. **Condition Check**
	```cpp
	        if(counter(1<<i) == c) return true;
	```
	Compares the digit count of `n` with the digit count of each power of 2 (calculated as `1 << i`). If they match, returns `true`.

5. **Return False**
	```cpp
	    return false;
	```
	If no power of 2 matches the digit count of `n`, returns `false`.

6. **Helper Function Definition**
	```cpp
	int counter(int N) {
	```
	Defines the helper function `counter`, which calculates the 'digit count signature' of a number `N`.

7. **Variable Initialization**
	```cpp
	    int res = 0;
	```
	Initializes the result variable `res` to store the computed signature of the digits of `N`.

8. **Loop For Digit Counting**
	```cpp
	    for(;N; N/=10) res += pow(10, N%10);
	```
	Uses a loop to process each digit of `N`. For each digit, it adds `10^digit` to the result `res`.

9. **Return Signature**
	```cpp
	    return res;
	```
	Returns the computed digit signature `res`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(log n)
- **Average Case:** O(log n * k), where k is the number of powers of two to check
- **Worst Case:** O(log n * k)

The complexity is determined by the number of digits in `n` (log n) and the number of powers of two to compare (k).

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(k)

Space is used for storing the precomputed digit frequencies of powers of two.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/reordered-power-of-2/description/)

---
{{< youtube rJu123dgDy8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

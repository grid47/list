
+++
authors = ["grid47"]
title = "Leetcode 1016: Binary String With Substrings Representing 1 To N"
date = "2024-07-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1016: Binary String With Substrings Representing 1 To N in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "EAHOzX67VB8"
youtube_upload_date="2024-03-27"
youtube_thumbnail="https://i.ytimg.com/vi/EAHOzX67VB8/maxresdefault.jpg"
comments = true
+++



---
Given a binary string s and a positive integer n, determine if the binary representation of all integers from 1 to n (inclusive) are substrings of s. A substring is defined as a contiguous sequence of characters within a string. Return true if all the binary representations of the integers in the range [1, n] are present as substrings of s, otherwise return false.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a binary string s and a positive integer n.
- **Example:** `s = '110101', n = 4`
- **Constraints:**
	- 1 <= s.length <= 1000
	- s[i] is either '0' or '1'.
	- 1 <= n <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return true if the binary representation of all integers from 1 to n are substrings of s, otherwise return false.
- **Example:** `Output: true`
- **Constraints:**
	- The output is a boolean value.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to check if the binary representation of all integers from 1 to n are substrings of s.

- For each number i from 1 to n, convert the number to its binary representation.
- Check if the binary representation of i is a substring of s.
- If any number’s binary representation is not a substring of s, return false.
- If all numbers’ binary representations are substrings of s, return true.
{{< dots >}}
### Problem Assumptions ✅
- The input string s is guaranteed to be valid and consist only of '0's and '1's.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: s = '0110', n = 3`  \
  **Explanation:** The binary representations of 1, 2, and 3 are '1', '10', and '11', respectively. All these are substrings of '0110', so the output is true.

- **Input:** `Input: s = '0110', n = 4`  \
  **Explanation:** The binary representation of 4 is '100', which is not a substring of '0110', so the output is false.

{{< dots >}}
## Approach 🚀
The solution involves converting numbers from 1 to n into their binary representations and checking if each of these representations exists as a substring within s.

### Initial Thoughts 💭
- This problem requires checking the presence of binary representations as substrings, which can be done efficiently using string operations.
- We need to consider how to handle the large range of n values efficiently.
{{< dots >}}
### Edge Cases 🌐
- There are no empty inputs in this case, as s is a non-empty binary string and n is a positive integer.
- If n is very large (e.g., 10^9), it is impractical to check all numbers, and the solution should use an optimized approach to avoid performance issues.
- When n is 1, the only number to check is 1, which is always a substring of any valid binary string s.
- For large values of n, an optimized solution that reduces unnecessary checks should be used.
{{< dots >}}
## Code 💻
```cpp
bool queryString(string s, int n) {
    for(int i = n; i > n / 2; i--) {
        string b = bitset<32>(i).to_string();
        if(s.find(b.substr(b.find('1'))) == string::npos)
            return false;
    }
    return true;
}
```

The function `queryString` checks whether all binary representations of numbers from `n` to `n/2` are substrings of the given string `s`. It iterates through these numbers in descending order, converts them to binary, and checks if each binary string is found within `s`.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	bool queryString(string s, int n) {
	```
	Declares the function `queryString` which takes a string `s` and an integer `n`, and returns a boolean value indicating whether all binary representations of numbers from `n` to `n/2` are substrings of `s`.

2. **For Loop Initialization**
	```cpp
	    for(int i = n; i > n / 2; i--) {
	```
	Initializes a for loop to iterate through all numbers from `n` down to `n/2`.

3. **Binary Conversion**
	```cpp
	        string b = bitset<32>(i).to_string();
	```
	Converts the current integer `i` into its 32-bit binary string representation using `bitset<32>`, ensuring the binary string is of fixed length.

4. **Substring Check**
	```cpp
	        if(s.find(b.substr(b.find('1'))) == string::npos)
	```
	Checks if the binary string `b` (after removing leading zeros) is found as a substring in the given string `s`. If it is not found, the function returns `false`.

5. **Return False**
	```cpp
	            return false;
	```
	Returns `false` if any binary representation from `n` to `n/2` is not found as a substring in `s`.

6. **Return True**
	```cpp
	    return true;
	```
	Returns `true` if all binary representations from `n` to `n/2` are found as substrings in `s`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The time complexity is O(n log n) because for each number up to n, its binary representation takes O(log n) time to compute and check as a substring.

### Space Complexity 💾
- **Best Case:** O(log n)
- **Worst Case:** O(log n)

The space complexity is O(log n) due to the space needed for storing the binary representation of each number.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/binary-string-with-substrings-representing-1-to-n/description/)

---
{{< youtube EAHOzX67VB8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

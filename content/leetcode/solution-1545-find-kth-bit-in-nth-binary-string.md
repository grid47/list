
+++
authors = ["grid47"]
title = "Leetcode 1545: Find Kth Bit in Nth Binary String"
date = "2024-06-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1545: Find Kth Bit in Nth Binary String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Recursion","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "34QYE5HAFy4"
youtube_upload_date="2020-10-12"
youtube_thumbnail="https://i.ytimg.com/vi/34QYE5HAFy4/maxresdefault.jpg"
comments = true
+++



---
Given two positive integers n and k, the binary string Sn is formed recursively. The task is to return the kth bit in the string Sn.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two integers n and k. The integer n represents the index of the string Sn and k represents the position of the bit we need to return.
- **Example:** `n = 3, k = 2`
- **Constraints:**
	- 1 <= n <= 20
	- 1 <= k <= 2^n - 1

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the kth bit of the string Sn.
- **Example:** `Output: 1`
- **Constraints:**
	- The string Sn is formed recursively, and the kth bit must be accessed in constant time.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find an efficient way to compute the kth bit of the string Sn without constructing the entire string.

- 1. The recursive construction of the string leads to exponential growth in length. Instead of constructing the full string, we need to deduce the position of the kth bit.
- 2. Utilize the recursive structure of the string to find a method that tracks the bit without constructing the entire string.
{{< dots >}}
### Problem Assumptions ✅
- The problem guarantees that k will be a valid index for the given n.
{{< dots >}}
## Examples 🧩
- **Input:** `n = 3, k = 2`  \
  **Explanation:** For n = 3, we know S3 = '0111001'. The 2nd bit is '1'.

- **Input:** `n = 4, k = 7`  \
  **Explanation:** For n = 4, we know S4 = '011100110110001'. The 7th bit is '0'.

{{< dots >}}
## Approach 🚀
We need to leverage the recursive nature of the sequence to compute the kth bit without constructing the full sequence.

### Initial Thoughts 💭
- The length of Sn grows exponentially with n. Thus, constructing the entire string is inefficient.
- We can trace the position of k within the recursive structure of Sn.
- We will work backwards to deduce the bit's value using the recursive properties of the sequence.
{{< dots >}}
### Edge Cases 🌐
- The string Sn is never empty, as n >= 1.
- For large values of n (close to 20), ensure the solution efficiently handles the exponential growth of the string.
- When k equals the maximum possible value (2^n - 1), ensure the solution handles boundary conditions correctly.
- Ensure the solution runs within time limits for all values of n and k.
{{< dots >}}
## Code 💻
```cpp
char findKthBit(int n, int k) {

    string s = "0";
    
    for(int i = 2; i <= n; i++) {
        string tmp = s;
        s += '1';
        for(int j = tmp.size() - 1; j >= 0; j--) {
            
            s += (tmp[j] == '0') ? '1':'0';
            
        }
    }

    return s[k-1];
}
```

This code generates a string based on the pattern and returns the k-th bit of the string for a given n. The string is built iteratively by flipping bits and appending a '1'.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	char findKthBit(int n, int k) {
	```
	This line declares the function `findKthBit`, which takes two integers `n` and `k` as input and returns a character (either '0' or '1') representing the k-th bit of the binary string for the given value of n.

2. **String Initialization**
	```cpp
	    string s = "0";
	```
	The string `s` is initialized to "0". This will be used to store the binary sequence that will be modified iteratively.

3. **Loop**
	```cpp
	    for(int i = 2; i <= n; i++) {
	```
	A for loop starts from i = 2 and runs until i = n, progressively building the binary string `s` by following the given pattern.

4. **String Copy**
	```cpp
	        string tmp = s;
	```
	Create a copy of the current string `s` into the variable `tmp`, which will be used for further manipulation.

5. **String Update**
	```cpp
	        s += '1';
	```
	Add a '1' to the string `s`. This is part of the pattern where each iteration appends a '1' to the string.

6. **Inner Loop**
	```cpp
	        for(int j = tmp.size() - 1; j >= 0; j--) {
	```
	A for loop starts from the last character of `tmp` and iterates backward, flipping the bits of the string to form the new pattern.

7. **Bit Flipping**
	```cpp
	            s += (tmp[j] == '0') ? '1' : '0';
	```
	For each character in `tmp`, append the flipped bit to `s`. If the character is '0', append '1', otherwise append '0'.

8. **Return Statement**
	```cpp
	    return s[k-1];
	```
	Return the k-th character from the string `s`. Since indexing starts at 0, we subtract 1 from `k` to get the correct index.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

Since we work recursively with the structure of Sn, the time complexity depends on the recursion depth, which is O(n).

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

We only store a few variables to track the recursive steps, so the space complexity is O(1).

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/description/)

---
{{< youtube 34QYE5HAFy4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

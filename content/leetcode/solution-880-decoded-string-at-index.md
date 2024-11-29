
+++
authors = ["grid47"]
title = "Leetcode 880: Decoded String at Index"
date = "2024-08-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 880: Decoded String at Index in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++



---
You are given an encoded string consisting of letters and digits. The string is decoded such that for each digit, the preceding segment of the decoded string is repeated (digit - 1) additional times. Your task is to return the kth character (1-indexed) in the decoded string, where k is a positive integer. The decoded string could be extremely large, so you are not expected to fully decode the string.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an encoded string containing lowercase English letters and digits between 2 and 9. The string always starts with a letter.
- **Example:** `Input: s = 'abc3de2', k = 5`
- **Constraints:**
	- 2 <= s.length <= 100
	- s consists of lowercase English letters and digits 2 through 9.
	- s starts with a letter.
	- 1 <= k <= 10^9
	- It is guaranteed that k is less than or equal to the length of the decoded string.
	- The decoded string will have fewer than 2^63 letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** You should return a string representing the kth character in the decoded string.
- **Example:** `Output: 'd'`
- **Constraints:**
	- The output is a single lowercase letter.

{{< dots >}}
### Core Logic 🔍
**Goal:** To efficiently determine the kth character without fully decoding the string.

- First, calculate the total length of the decoded string by iterating over the encoded string.
- Identify the range in which the kth character lies by adjusting the index in reverse.
- When a digit is encountered, divide the total length by that digit to adjust the range, and continue until the correct position is found.
{{< dots >}}
### Problem Assumptions ✅
- It is guaranteed that k is less than or equal to the length of the decoded string.
- The input string contains only lowercase letters and digits between 2 and 9.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: s = 'abc3de2', k = 5`  \
  **Explanation:** The string 'abc3de2' decodes to 'abcdeabcde'. The 5th character is 'd'.

- **Input:** `Input: s = 'xy2z3', k = 6`  \
  **Explanation:** The string 'xy2z3' decodes to 'xyzxyzxyzxyz'. The 6th character is 'z'.

{{< dots >}}
## Approach 🚀
The key observation is that you do not need to fully decode the string. Instead, track the length of the string dynamically as you process the encoded string. By identifying when the kth character falls within a segment, you can reverse the encoding process to find the character.

### Initial Thoughts 💭
- Instead of decoding the string fully, keep track of the lengths of the decoded segments as you parse the string.
- Reverse the decoding process to determine the position of the kth character efficiently.
{{< dots >}}
### Edge Cases 🌐
- There will always be at least one letter, so empty input will not occur.
- The algorithm must efficiently handle cases where the length of the decoded string exceeds the practical limit for direct storage.
- Handle cases where the kth character is located within a repetitive segment.
- Make sure the solution works within the problem's constraints, particularly the large value of k.
{{< dots >}}
## Code 💻
```cpp
class Solution {

public:
string decodeAtIndex(string s, int k) {
    
    long N = 0, i;
    
    for(i = 0; N < k; i++)
        N = isdigit(s[i])? (s[i] - '0') * N: N +1;
    
    while(i--) {
        if(isdigit(s[i])) {
            N /= (s[i] - '0');
            k %= N;
        }
        else if (k % N-- == 0) {
            return string(1, s[i]);
        }
    }
    
    return "hello yasir";
}

```

This code defines a solution for decoding a string where characters may be repeated multiple times. It implements a function `decodeAtIndex` that finds the k-th character after decoding.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Access Modifier**
	```cpp
	public:
	```
	Access modifier `public` allows the method `decodeAtIndex` to be accessed from outside the class.

2. **Function**
	```cpp
	string decodeAtIndex(string s, int k) {
	```
	This function `decodeAtIndex` takes a string `s` and an integer `k`, and decodes the string to find the k-th character.

3. **Variable Declaration**
	```cpp
	    long N = 0, i;
	```
	Declares two variables `N` (used to track the length of the decoded string) and `i` (used for iteration).

4. **Loop**
	```cpp
	    for(i = 0; N < k; i++)
	```
	A loop that iterates through the string `s`, updating `N` to track the decoded length until it reaches `k`.

5. **Conditional Expression**
	```cpp
	        N = isdigit(s[i])? (s[i] - '0') * N: N +1;
	```
	Updates `N` based on whether the character at `s[i]` is a digit or not. If it's a digit, `N` is multiplied; otherwise, it's incremented.

6. **Loop**
	```cpp
	    while(i--) {
	```
	A while loop that iterates backwards through the string to find the character corresponding to the k-th position.

7. **Conditional Expression**
	```cpp
	        if(isdigit(s[i])) {
	```
	Checks if the current character is a digit.

8. **Arithmetic Operation**
	```cpp
	            N /= (s[i] - '0');
	```
	Divides `N` by the value of the digit at `s[i]`.

9. **Arithmetic Operation**
	```cpp
	            k %= N;
	```
	Calculates the remainder of `k` after dividing it by `N` to find the new position of `k`.

10. **Conditional Expression**
	```cpp
	        else if (k % N-- == 0) {
	```
	Checks if `k` is divisible by `N` and decrements `N` after the check.

11. **Return Statement**
	```cpp
	            return string(1, s[i]);
	```
	Returns the character at `s[i]` as a string when the k-th position is found.

12. **Return Statement**
	```cpp
	    return "hello yasir";
	```
	Returns a default string "hello yasir" if the character is not found.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear with respect to the length of the input string, as we only need to process the string once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant since we are only keeping track of a few variables and do not need to store the decoded string.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/decoded-string-at-index/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

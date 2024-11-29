
+++
authors = ["grid47"]
title = "Leetcode 2864: Maximum Odd Binary Number"
date = "2024-01-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2864: Maximum Odd Binary Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","String","Greedy"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "EUKLOAv4-IQ"
youtube_upload_date="2024-03-01"
youtube_thumbnail="https://i.ytimg.com/vi_webp/EUKLOAv4-IQ/maxresdefault.webp"
comments = true
+++



---
You are given a binary string s containing at least one '1'. Your task is to rearrange the bits in such a way that the resulting binary number is the largest possible odd binary number that can be formed from the given bits. A binary number is odd if its least significant bit (last bit) is '1'. The resulting binary number may contain leading zeros.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a binary string s containing only '0' and '1' characters. The string will contain at least one '1'.
- **Example:** `s = "100"`
- **Constraints:**
	- 1 <= s.length <= 100
	- s contains only '0' and '1'.
	- s contains at least one '1'.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a string representing the largest odd binary number that can be created from the given binary string.
- **Example:** `For input s = "100", the output is "010".`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to rearrange the bits in such a way that the resulting binary number is the largest odd binary number possible.

- Identify and place the '1' in the last position to ensure the binary number is odd.
- Sort the remaining bits in descending order to form the largest possible binary number.
{{< dots >}}
### Problem Assumptions ✅
- The binary string contains at least one '1', ensuring that a valid odd binary number can be created.
{{< dots >}}
## Examples 🧩
- **Input:** `For input s = "100", the output is "010".`  \
  **Explanation:** To create the largest odd binary number, the '1' must be placed in the last position. The remaining bits '10' can be rearranged as "01", resulting in the binary number "010".

{{< dots >}}
## Approach 🚀
The approach involves rearranging the bits of the binary string to maximize the resulting odd binary number by ensuring the last bit is '1' and sorting the remaining bits in descending order.

### Initial Thoughts 💭
- The last bit must always be '1' for the binary number to be odd.
- The remaining bits should be sorted to form the largest possible number.
- If the binary string has more than one '1', we need to place one '1' at the end and arrange the rest of the bits in descending order.
{{< dots >}}
### Edge Cases 🌐
- The input string is guaranteed to contain at least one '1', so no need to handle empty inputs.
- The solution must handle input strings of length up to 100 characters efficiently.
- If the string already ends with '1', only sorting the remaining bits is necessary.
- The algorithm must ensure that the result is the largest odd binary number possible.
{{< dots >}}
## Code 💻
```cpp
string maximumOddBinaryNumber(string s) {
int i = 0, sz = s.size();
for(int j = 0;j < sz - 1; ++j) {
    if(s[j] == '1') {
        swap(s[j], s[i]);
        ++i;
    } 
}

if(s.back() != '1') 
    swap(s[sz - 1], s[i - 1]);
return s;
}
```

This function rearranges the binary string to form the largest odd binary number possible by swapping the positions of '1's and '0's.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Start**
	```cpp
	string maximumOddBinaryNumber(string s) {
	```
	Start of the function definition for maximumOddBinaryNumber.

2. **Variable Initialization**
	```cpp
	int i = 0, sz = s.size();
	```
	Initialize index 'i' to 0 and calculate the size of the string 's'.

3. **Loop Start**
	```cpp
	for(int j = 0;j < sz - 1; ++j) {
	```
	Start a loop that iterates over each character of the string, except the last one.

4. **Condition Check**
	```cpp
	    if(s[j] == '1') {
	```
	Check if the current character at position 'j' is '1'.

5. **Swap Operation**
	```cpp
	        swap(s[j], s[i]);
	```
	If the current character is '1', swap it with the character at index 'i'.

6. **Increment Index**
	```cpp
	        ++i;
	```
	Increment the index 'i' after swapping.

7. **Condition Check for Last Character**
	```cpp
	if(s.back() != '1') 
	```
	Check if the last character of the string is not '1'.

8. **Final Swap**
	```cpp
	    swap(s[sz - 1], s[i - 1]);
	```
	If the last character is not '1', swap it with the character at index 'i - 1'.

9. **Return Statement**
	```cpp
	return s;
	```
	Return the modified string which now represents the maximum odd binary number.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

Sorting the bits requires O(n log n) time where n is the length of the string.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n) due to the need for sorting the string.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-odd-binary-number/description/)

---
{{< youtube EUKLOAv4-IQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

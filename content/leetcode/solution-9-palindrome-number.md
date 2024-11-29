
+++
authors = ["grid47"]
title = "Leetcode 9: Palindrome Number"
date = "2024-11-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 9: Palindrome Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/9.webp"
youtube = "yubRKwixN-U"
youtube_upload_date="2021-08-20"
youtube_thumbnail="https://i.ytimg.com/vi/yubRKwixN-U/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/9.webp" 
    alt="A number with mirrored halves, radiating a soothing glow as it reflects symmetrically."
    caption="Solution to LeetCode 9: Palindrome Number Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given an integer, return true if the number is a palindrome. A number is a palindrome if it reads the same forwards and backwards. If the number is negative, it is automatically not a palindrome.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a single integer x. The number can be negative or positive.
- **Example:** `Input: x = 121`
- **Constraints:**
	- -231 <= x <= 231 - 1

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a boolean value indicating whether the input integer is a palindrome or not.
- **Example:** `Output: true`
- **Constraints:**
	- Return true if the number is a palindrome, false otherwise.

{{< dots >}}
### Core Logic 🔍
**Goal:** To check if a given number is a palindrome without converting the integer to a string.

- Check if the number is negative. If it is, return false immediately.
- Reverse the digits of the number.
- Compare the original number with the reversed number. If they are the same, return true; otherwise, return false.
{{< dots >}}
### Problem Assumptions ✅
- We are guaranteed that the input will be within the specified range (-231 <= x <= 231 - 1).
- Negative numbers are not palindromes.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: x = 121`  \
  **Explanation:** The number 121 reads the same from left to right and right to left, so it is a palindrome.

- **Input:** `Input: x = -121`  \
  **Explanation:** The number -121 is not a palindrome because the negative sign appears only on the left, not the right.

- **Input:** `Input: x = 10`  \
  **Explanation:** The number 10 is not a palindrome because it reads '01' from right to left, which is not the same as the original number.

{{< dots >}}
## Approach 🚀
To check if a number is a palindrome, we reverse its digits and compare the reversed number with the original. We will handle negative numbers immediately as they can never be palindromes.

### Initial Thoughts 💭
- A simple approach is to reverse the digits and check if the original and reversed numbers match.
- We need to handle negative numbers early since they can't be palindromes.
- We must reverse the digits without converting the number to a string, which can be done by manipulating the number mathematically.
{{< dots >}}
### Edge Cases 🌐
- The input is always a valid integer within the specified range.
- The solution should handle the largest integer values within the range efficiently.
- If the number is negative, it will not be a palindrome.
- If the number ends with a zero and is greater than zero, it cannot be a palindrome.
- Do not convert the number to a string. Reverse the digits mathematically.
{{< dots >}}
## Code 💻
```cpp
bool isPalindrome(int x) {
    if(x < 0) return false;
    long long int y = x, z = 0;
    while(x) {
        z = z * 10 + x % 10;
        x /= 10;
    }
    return y == z;
}
```

This code implements the `isPalindrome` function, which checks if an integer is a palindrome.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	bool isPalindrome(int x) {
	```
	Declare the `isPalindrome` function, which takes an integer `x` as input and returns a boolean indicating whether it's a palindrome.

2. **Conditional Check**
	```cpp
	    if(x < 0) return false;
	```
	Check if the input number `x` is negative. Negative numbers cannot be palindromes, so return `false` immediately.

3. **Variable Initialization**
	```cpp
	    long long int y = x, z = 0;
	```
	Initialize two variables: `y` to store a copy of the original number `x`, and `z` to store the reversed number.

4. **Loop Iteration**
	```cpp
	    while(x) {
	```
	Start a loop that continues while `x` is not zero.

5. **Mathematical Operations**
	```cpp
	        z = z * 10 + x % 10;
	```
	Extract the last digit of `x` using the modulo operator and append it to the reversed number `z`.

6. **Integer Division**
	```cpp
	        x /= 10;
	```
	Remove the last digit from `x` by integer division.

7. **Return Value**
	```cpp
	    return y == z;
	```
	Compare the original number `y` with the reversed number `z`. If they are equal, the number is a palindrome, so return `true`. Otherwise, return `false`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(log(x)), where x is the integer. This is because we reverse the digits of the number, and the number of digits is proportional to log(x).
- **Average Case:** O(log(x))
- **Worst Case:** O(log(x)), since we are iterating over all digits to reverse the number.

The time complexity is logarithmic relative to the size of the integer.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1), since we only use a constant amount of extra space for the reversal.

The space complexity is constant as we only use a few variables to store intermediate values.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/palindrome-number/description/)

---
{{< youtube yubRKwixN-U >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

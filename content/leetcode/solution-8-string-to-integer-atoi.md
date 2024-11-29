
+++
authors = ["grid47"]
title = "Leetcode 8: String to Integer (atoi)"
date = "2024-11-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 8: String to Integer (atoi) in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/8.webp"
youtube = "YA0LYrKI1CQ"
youtube_upload_date="2022-03-02"
youtube_thumbnail="https://i.ytimg.com/vi/YA0LYrKI1CQ/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/8.webp" 
    alt="A glowing number forming from abstract text, transforming from letters to digits."
    caption="Solution to LeetCode 8: String to Integer (atoi) Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Convert a string to a 32-bit signed integer, handling whitespaces, optional signs, and non-digit characters.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a string s containing English letters, digits, spaces, and optional signs.
- **Example:** `s = ' 42'`
- **Constraints:**
	- 0 <= s.length <= 200
	- s consists of English letters (lowercase and uppercase), digits (0-9), spaces, '+' or '-', and possibly other non-digit characters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the integer value represented by the string after ignoring leading spaces and processing digits, within the 32-bit signed integer range.
- **Example:** `For input s = '42', the output is 42.`
- **Constraints:**
	- The result must be within the range of a 32-bit signed integer: [-231, 231 - 1].

{{< dots >}}
### Core Logic 🔍
**Goal:** Parse the string, handle optional signs, ignore non-digit characters after the first integer, and ensure the result remains within the 32-bit signed integer limits.

- Skip leading spaces.
- Check for a '+' or '-' sign to determine the number's sign.
- Parse the digits until a non-digit character is encountered.
- If no digits are found, return 0.
- Clamp the result to fit within the 32-bit signed integer range.
{{< dots >}}
### Problem Assumptions ✅
- The input string can contain digits, spaces, signs, and other characters.
- If no valid number is found, the result should be 0.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: s = ' 42'`  \
  **Explanation:** The function processes the string '42', ignoring leading spaces, and returns the integer 42.

- **Input:** `Example 2: s = '   - 0345'`  \
  **Explanation:** The function reads the number '-345' after ignoring the spaces and the leading zeros.

- **Input:** `Example 3: s = '56x89'`  \
  **Explanation:** The function reads '56' and stops at the character 'x', returning 56.

- **Input:** `Example 4: s = '0000000000'`  \
  **Explanation:** All zeros are ignored, resulting in 0.

- **Input:** `Example 5: s = 'words 123'`  \
  **Explanation:** Since the string starts with non-numeric characters, the function returns 0.

{{< dots >}}
## Approach 🚀
The approach is to iterate through the string, parsing the number while handling edge cases and ensuring the final result is within the bounds of a 32-bit signed integer.

### Initial Thoughts 💭
- We need to handle whitespace, signs, and non-digit characters properly.
- The result must be clamped to fit within a 32-bit signed integer range.
- The algorithm should stop reading when a non-digit character is encountered after parsing valid digits.
{{< dots >}}
### Edge Cases 🌐
- An empty string should return 0.
- Large inputs may exceed the 32-bit integer range and should be clamped accordingly.
- If the string contains no digits, return 0.
- Handle strings with spaces, signs, and non-digit characters.
{{< dots >}}
## Code 💻
```cpp
int myAtoi(string s) {
    int res = 0;
    int sgn = 1;
    int i = 0;
    while(i < s.size() && s[i] == ' ') i++;
    if(i < s.size() && (s[i] == '+' || s[i] == '-'))
        sgn = (s[i++] == '+')? 1: -1;
    
    while(i < s.size() && s[i] >= '0' && s[i] <= '9') {
        
    if(res > INT_MAX/10 || 
    (res == INT_MAX/10 && ((s[i]-'0')>(INT_MAX %10))))
    return (sgn > 0)? INT_MAX: INT_MIN;
        
        res = res * 10 + (s[i++] - '0');
        // cout << res << " ";
    }
    
    return sgn * res;
}
```

This code implements the `myAtoi` function, which converts a string to an integer.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int myAtoi(string s) {
	```
	Declare the `myAtoi` function, which takes a string `s` as input and returns an integer.

2. **Variable Initialization**
	```cpp
	    int res = 0;
	```
	Initialize a variable `res` to store the result integer.

3. **Variable Initialization**
	```cpp
	    int sgn = 1;
	```
	Initialize a variable `sgn` to store the sign of the integer (1 for positive, -1 for negative).

4. **Variable Initialization**
	```cpp
	    int i = 0;
	```
	Initialize an index `i` to iterate through the string.

5. **Loop Iteration**
	```cpp
	    while(i < s.size() && s[i] == ' ') i++;
	```
	Skip leading whitespace characters.

6. **Conditional Check**
	```cpp
	    if(i < s.size() && (s[i] == '+' || s[i] == '-'))
	```
	Check if the next character is a sign character (`+` or `-`)

7. **Conditional Assignment**
	```cpp
	        sgn = (s[i++] == '+')? 1: -1;
	```
	Set the sign based on the character and increment the index `i`.

8. **Loop Iteration**
	```cpp
	    while(i < s.size() && s[i] >= '0' && s[i] <= '9') {
	```
	Iterate while the current character is a digit.

9. **Conditional Check**
	```cpp
	    if(res > INT_MAX/10 || 
	```
	Check if the current `res` value is greater than the maximum integer divided by 10.

10. **Conditional Check**
	```cpp
	    (res == INT_MAX/10 && ((s[i]-'0')>(INT_MAX %10))))
	```
	Check if `res` is equal to the maximum integer divided by 10 and the next digit is greater than the maximum integer modulo 10.

11. **Return Value**
	```cpp
	    return (sgn > 0)? INT_MAX: INT_MIN;
	```
	If overflow occurs, return `INT_MAX` for positive numbers or `INT_MIN` for negative numbers.

12. **Mathematical Operations**
	```cpp
	        res = res * 10 + (s[i++] - '0');
	```
	Update the `res` value by multiplying it by 10 and adding the current digit.

13. **Comment**
	```cpp
	        // cout << res << " ";
	```
	A commented-out line to print the intermediate `res` value for debugging purposes.

14. **Return Value**
	```cpp
	    return sgn * res;
	```
	Return the final result multiplied by the sign.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the length of the string.
- **Average Case:** O(n), where n is the length of the string.
- **Worst Case:** O(n), where n is the length of the string.

The time complexity depends on the length of the string as we only make a single pass through it.

### Space Complexity 💾
- **Best Case:** O(1), since the space used is constant.
- **Worst Case:** O(1), since we only use a few variables to store the result and current position.

The space complexity is constant, O(1), as we don't use extra space for data structures.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/string-to-integer-atoi/description/)

---
{{< youtube YA0LYrKI1CQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

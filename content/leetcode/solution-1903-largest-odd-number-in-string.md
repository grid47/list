
+++
authors = ["grid47"]
title = "Leetcode 1903: Largest Odd Number in String"
date = "2024-04-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1903: Largest Odd Number in String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","String","Greedy"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "IIt_ARZzclY"
youtube_upload_date="2021-06-27"
youtube_thumbnail="https://i.ytimg.com/vi/IIt_ARZzclY/maxresdefault.jpg"
comments = true
+++



---
You are given a string `num`, which represents a large integer. Your task is to find the largest odd integer that can be formed from any non-empty substring of `num`. If no odd integer exists, return an empty string.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** A string `num` representing a large integer.
- **Example:** `num = "54321"`
- **Constraints:**
	- 1 <= num.length <= 10^5
	- num only consists of digits and does not contain any leading zeros.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the largest odd integer (as a string) formed from any non-empty substring of `num`, or an empty string if no odd integer exists.
- **Example:** `"54321"`
- **Constraints:**
	- The output is a string that represents the largest odd number, or an empty string if no odd integer is found.

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the largest odd integer from any non-empty substring.

- Start by iterating from the end of the string `num`.
- For each digit, check if it is odd.
- If an odd digit is found, return the substring from the beginning of `num` to the current index.
{{< dots >}}
### Problem Assumptions ✅
- The string `num` is valid and follows the constraints provided.
- The string will always contain digits.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: num = "54321"`  \
  **Explanation:** The string '54321' is already an odd number, so it is the largest odd integer possible.

{{< dots >}}
## Approach 🚀
We can find the largest odd integer by starting from the end of the string `num` and checking each character for oddness. As soon as we find an odd digit, we return the substring from the start to that position.

### Initial Thoughts 💭
- The problem requires identifying odd integers in substrings efficiently.
- By iterating backward and checking the digits for oddness, we minimize unnecessary checks and ensure an optimal solution.
{{< dots >}}
### Edge Cases 🌐
- The input string cannot be empty according to the constraints.
- The function should efficiently handle large inputs up to 10^5 digits.
- Handle cases where there are no odd digits in the entire string.
- The string only contains digits, and there are no leading zeros.
{{< dots >}}
## Code 💻
```cpp
string largestOddNumber(string num) {
    string res = "";
    for(int i = num.size(); i >= 0; i--) {
        if((num[i] - '0') % 2)
          return num.substr(0, i + 1);
    }
    return string();
}
```

This function finds and returns the largest odd number that can be formed from a given numeric string.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	string largestOddNumber(string num) {
	```
	The function definition starts here. It takes a string `num` and will return the largest odd number formed from the digits in the string.

2. **Variable Initialization**
	```cpp
	    string res = "";
	```
	A string variable `res` is initialized to store the result, although it is not used in this solution.

3. **For Loop**
	```cpp
	    for(int i = num.size(); i >= 0; i--) {
	```
	This for loop iterates backwards through the digits of the string `num` from the last character to the first.

4. **Condition Check**
	```cpp
	        if((num[i] - '0') % 2)
	```
	This condition checks if the current digit is odd by converting the character to an integer and checking if it is divisible by 2.

5. **Return Substring**
	```cpp
	          return num.substr(0, i + 1);
	```
	If the digit is odd, the function returns the substring from the start of `num` to the current position `i`, which forms the largest odd number.

6. **Return Empty String**
	```cpp
	    return string();
	```
	If no odd digit is found, an empty string is returned.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear since we are checking each digit of the string once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant since we only use a few variables for processing.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/largest-odd-number-in-string/description/)

---
{{< youtube IIt_ARZzclY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

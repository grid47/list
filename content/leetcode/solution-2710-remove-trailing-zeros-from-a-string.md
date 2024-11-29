
+++
authors = ["grid47"]
title = "Leetcode 2710: Remove Trailing Zeros From a String"
date = "2024-02-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2710: Remove Trailing Zeros From a String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "cY-wxEdhSAY"
youtube_upload_date="2023-05-28"
youtube_thumbnail="https://i.ytimg.com/vi/cY-wxEdhSAY/maxresdefault.jpg"
comments = true
+++



---
Given a positive integer represented as a string, your task is to return the same integer but with all trailing zeros removed. The result should also be returned as a string.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string representing a positive integer without leading zeros.
- **Example:** `Input: num = "890000"`
- **Constraints:**
	- 1 <= num.length <= 1000
	- num consists only of digits.
	- The integer represented by the string does not have leading zeros.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the input string after removing any trailing zeros.
- **Example:** `Output: "89"`
- **Constraints:**
	- The output should be the string representing the integer without trailing zeros.

{{< dots >}}
### Core Logic 🔍
**Goal:** Remove all trailing zeros from the string representation of the given integer.

- Step 1: Start from the last character of the string and check if it is a '0'.
- Step 2: Continue checking characters until a non-zero character is found.
- Step 3: Slice the string to exclude all trailing zeros.
{{< dots >}}
### Problem Assumptions ✅
- The input string will always represent a valid positive integer.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: num = "5403000"`  \
  **Explanation:** The integer represented by the string '5403000' has three trailing zeros. After removing them, the resulting string is '5403'.

- **Input:** `Input: num = "1000"`  \
  **Explanation:** The string '1000' has three trailing zeros. After removing them, the output is '1'.

{{< dots >}}
## Approach 🚀
We can solve this problem efficiently by iterating through the string from the end to the beginning and removing all the '0' characters until a non-zero digit is encountered.

### Initial Thoughts 💭
- Trailing zeros can be identified by iterating from the end of the string.
- Removing trailing zeros does not require modifying the middle portion of the string.
- The solution should be efficient enough to handle strings with up to 1000 characters.
{{< dots >}}
### Edge Cases 🌐
- The input will not be empty, as per the constraints.
- Ensure that the solution works for large input sizes up to 1000 characters.
- If the string is composed of only zeros (e.g., '0000'), the result should be an empty string or '0'.
- Ensure that the solution works correctly for inputs with varying numbers of trailing zeros.
{{< dots >}}
## Code 💻
```cpp
string removeTrailingZeros(string num) {
    int n = num.size();
    int cnt = 0;
    int len;
    for( len = 1; len <= n; len++) {
        if(num[n - len] == '0') cnt++;
        else break;
    }
    return num.substr(0, n - cnt);
}
```

This function `removeTrailingZeros` takes a string `num` and removes all trailing zeros from it. It iterates through the string from the end, counting zeros, and then returns the substring excluding those zeros.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	string removeTrailingZeros(string num) {
	```
	The function `removeTrailingZeros` is declared. It takes a string `num` as an input and returns a string with trailing zeros removed.

2. **Variable Initialization**
	```cpp
	    int n = num.size();
	```
	The variable `n` is initialized to the size of the input string `num`, representing the total number of characters in the string.

3. **Variable Initialization**
	```cpp
	    int cnt = 0;
	```
	Initialize `cnt` to zero. This variable will count the number of trailing zeros in the string.

4. **Variable Declaration**
	```cpp
	    int len;
	```
	Declare the variable `len` which will be used to iterate through the string from the end.

5. **Loop Setup**
	```cpp
	    for( len = 1; len <= n; len++) {
	```
	A `for` loop is set up to iterate from the last character of the string towards the beginning, checking for trailing zeros.

6. **Check for Trailing Zero**
	```cpp
	        if(num[n - len] == '0') cnt++;
	```
	If the current character (starting from the end) is a zero, increment the `cnt` variable to track the number of zeros.

7. **Break Condition**
	```cpp
	        else break;
	```
	If a non-zero character is found, break the loop as there are no more trailing zeros.

8. **Return Statement**
	```cpp
	    return num.substr(0, n - cnt);
	```
	Return the substring of `num` from the start to `n - cnt` to remove the trailing zeros.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the length of the string, as we only need to traverse the string once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n) in the worst case when the string has to be modified or a new string is created to hold the result.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/remove-trailing-zeros-from-a-string/description/)

---
{{< youtube cY-wxEdhSAY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

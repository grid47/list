
+++
authors = ["grid47"]
title = "Leetcode 1796: Second Largest Digit in a String"
date = "2024-05-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1796: Second Largest Digit in a String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "hyQUsjKrq1s"
youtube_upload_date="2021-03-20"
youtube_thumbnail="https://i.ytimg.com/vi/hyQUsjKrq1s/maxresdefault.jpg"
comments = true
+++



---
You are given an alphanumeric string 's', which consists of lowercase English letters and digits. Your task is to find the second largest numerical digit in 's'. If there is no second largest digit, return -1.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an alphanumeric string 's'. This string contains only lowercase letters and digits.
- **Example:** `Input: s = 'zab10321xy'`
- **Constraints:**
	- 1 <= s.length <= 500
	- s consists of only lowercase English letters and digits

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the second largest numerical digit in the string 's', or -1 if it does not exist.
- **Example:** `Output: 2`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the second largest numerical digit in the given string 's'. If such a digit does not exist, return -1.

- Initialize an array to store the two largest digits found.
- Loop through the string and extract all digits.
- For each digit, compare it with the two largest digits found so far and update the array accordingly.
- Return the second largest digit if it exists, otherwise return -1.
{{< dots >}}
### Problem Assumptions ✅
- The string 's' is always valid and meets the input constraints.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: 'ab12cd34'`  \
  **Explanation:** The digits in the string are [1, 2, 3, 4]. The second largest digit is 3.

- **Input:** `Input: 'abc1111'`  \
  **Explanation:** The only digit is 1, so there is no second largest digit, and the output is -1.

{{< dots >}}
## Approach 🚀
To solve this problem, we need to iterate through the string to extract all digits, and then determine the second largest digit.

### Initial Thoughts 💭
- We are only interested in the numerical digits, which simplifies the problem to processing a small subset of characters.
- We need to track the two largest digits found while iterating through the string. This will allow us to easily determine the second largest.
{{< dots >}}
### Edge Cases 🌐
- Input string is guaranteed to have at least one character based on the problem constraints.
- The solution must handle up to 500 characters efficiently.
- The string might contain all non-digit characters, which should return -1.
- Ensure the solution works within the time and space constraints.
{{< dots >}}
## Code 💻
```cpp
int secondHighest(string s) {
    // support variables
    int res[2] = {-1, -1};
    // parsing s
    for (char c: s) {
        // considering only numerical characters
        if (c >= '0' && c <= '9') {
            // normalising c
            c -= '0';
            // updating res
            if (c > res[0]) {
                res[1] = res[0];
                res[0] = c;
            } else if (c != res[0] && c > res[1]) res[1] = c;
        }
    }
    return res[1];
}
```

This function finds the second highest digit in a string of characters by iterating through the string, checking if each character is a digit, and comparing it with the two highest digits found so far.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int secondHighest(string s) {
	```
	Define the function `secondHighest` which accepts a string `s` and returns the second highest digit found in the string.

2. **Array Initialization**
	```cpp
	    int res[2] = {-1, -1};
	```
	Initialize an array `res` of size 2 to store the highest (`res[0]`) and second highest (`res[1]`) digits. Both are initially set to -1, which represents no valid digits found yet.

3. **Loop Start**
	```cpp
	    for (char c: s) {
	```
	Start a `for` loop that iterates over each character `c` in the string `s`.

4. **Character Condition**
	```cpp
	        if (c >= '0' && c <= '9') {
	```
	This condition checks if the current character `c` is a digit (between '0' and '9').

5. **Character Conversion**
	```cpp
	            c -= '0';
	```
	Convert the character `c` into its corresponding integer value by subtracting the ASCII value of '0'.

6. **Update Highest and Second Highest**
	```cpp
	            if (c > res[0]) {
	```
	If the current digit `c` is greater than the current highest digit (`res[0]`), update the second highest to the current highest and set the new highest to `c`.

7. **Update Second Highest**
	```cpp
	                res[1] = res[0];
	```
	Set the second highest value to the previous highest value.

8. **Update Highest**
	```cpp
	                res[0] = c;
	```
	Update the highest value in `res` to the current digit `c`.

9. **Update Second Highest (Else)**
	```cpp
	            } else if (c != res[0] && c > res[1]) res[1] = c;
	```
	If the current digit `c` is not equal to the highest digit (`res[0]`) but is greater than the second highest (`res[1]`), update the second highest value.

10. **Return Statement**
	```cpp
	    return res[1];
	```
	Return the second highest digit stored in `res[1]`. If no second highest digit is found, it will return -1.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the length of the string, as we must scan through the string once.
- **Average Case:** O(n), as the complexity is linear in the length of the string.
- **Worst Case:** O(n), as we still need to check each character in the string.

The time complexity is O(n), where n is the length of the string, since we only need to traverse the string once.

### Space Complexity 💾
- **Best Case:** O(1), as we use constant space for storing the two largest digits.
- **Worst Case:** O(1), as we are only storing two variables to track the largest digits.

The space complexity is O(1), as the space used does not depend on the input size.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/second-largest-digit-in-a-string/description/)

---
{{< youtube hyQUsjKrq1s >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

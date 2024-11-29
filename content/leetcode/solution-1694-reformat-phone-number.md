
+++
authors = ["grid47"]
title = "Leetcode 1694: Reformat Phone Number"
date = "2024-05-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1694: Reformat Phone Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "U8EwUjwKYFg"
youtube_upload_date="2020-12-20"
youtube_thumbnail="https://i.ytimg.com/vi_webp/U8EwUjwKYFg/maxresdefault.webp"
comments = true
+++



---
You are given a phone number as a string. The string consists of digits, spaces, and/or dashes. Your task is to reformat the phone number by removing spaces and dashes, then grouping the digits into blocks of length 3 until there are at most 4 digits left. Afterward, follow specific grouping rules for the remaining digits and join the blocks with dashes.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string 'number', which contains digits, spaces, and dashes.
- **Example:** `"9-87-65 4"`
- **Constraints:**
	- 2 <= number.length <= 100
	- number contains digits and the characters '-' and ' '.
	- There are at least two digits in number.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is a string representing the reformatted phone number with digits grouped and separated by dashes as per the specified rules.
- **Example:** `"987-654"`
- **Constraints:**
	- The output string should have no blocks of length 1 and at most two blocks of length 2.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to reformat the phone number optimally by grouping digits as described in the problem statement.

- Remove spaces and dashes from the input string.
- Group the digits into blocks of length 3 while more than 4 digits remain.
- For the remaining digits, apply the appropriate grouping rule.
- Join the blocks using dashes and return the result.
{{< dots >}}
### Problem Assumptions ✅
- The phone number will contain only digits, spaces, and dashes.
- The phone number will contain at least two digits.
{{< dots >}}
## Examples 🧩
- **Input:** `"9-87-65 4"`  \
  **Explanation:** After removing spaces and dashes, the digits are "987654". These are grouped into two blocks: "987" and "654". The final output is "987-654".

- **Input:** `"3 1-2 45"`  \
  **Explanation:** After removing spaces and dashes, the digits are "31245". These are grouped into blocks: "312" and "45". The final output is "312-45".

{{< dots >}}
## Approach 🚀
The approach is to first clean the string by removing spaces and dashes, then group the digits optimally into blocks following the rules.

### Initial Thoughts 💭
- The problem involves string manipulation and grouping logic.
- We need to handle the reformatting and grouping in a way that ensures no block has a length of 1 and at most two blocks of length 2.
{{< dots >}}
### Edge Cases 🌐
- The input will never be empty, as it's guaranteed to contain at least two digits.
- For larger inputs (up to 100 characters), the approach will still work as long as the string is processed efficiently.
- The input will always contain digits and possibly spaces or dashes, which need to be handled by removing them first.
- The length of the phone number string will always be between 2 and 100 characters.
{{< dots >}}
## Code 💻
```cpp
string reformatNumber(string s) {
    int j = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (isdigit(s[i])) s[j++] = s[i];
    }
    s.resize(j);
    string ans;
    for (int i = 0, r = s.size(); i < s.size(); ) {
        for (int d = r == 2 || r == 4 ? 2 : 3; d > 0; --d, --r) {
            ans += s[i++];
        }
        if (r) ans += '-';
    }
    return ans;
}
```

This function reformats a string of digits into a standard phone number format, grouping the digits in parts of 3, and adding a dash between groups of 3 digits. If there are remaining digits in smaller groups (2 or 4), the function adjusts accordingly.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	string reformatNumber(string s) {
	```
	Define the function `reformatNumber`, which takes a string `s` as input and returns the formatted string according to the problem requirements.

2. **Variable Initialization**
	```cpp
	    int j = 0;
	```
	Initialize the variable `j` to 0. This will be used to track the position in the string where the digits will be copied.

3. **Iterate Through Input String**
	```cpp
	    for (int i = 0; i < s.size(); ++i) {
	```
	Start a loop to iterate over each character in the input string `s`.

4. **Digit Extraction**
	```cpp
	        if (isdigit(s[i])) s[j++] = s[i];
	```
	Check if the current character is a digit using `isdigit()`. If it is, copy it to the position `j` in the string and increment `j`.

5. **Resize String**
	```cpp
	    s.resize(j);
	```
	Resize the string `s` to contain only the digits that were copied (those at the positions from 0 to `j - 1`).

6. **String Initialization**
	```cpp
	    string ans;
	```
	Initialize an empty string `ans` which will hold the formatted result.

7. **Main Formatting Loop Start**
	```cpp
	    for (int i = 0, r = s.size(); i < s.size(); ) {
	```
	Start a loop to process the digits in `s` and format them into groups. The variable `r` is the remaining number of digits to process.

8. **Inner Loop for Grouping**
	```cpp
	        for (int d = r == 2 || r == 4 ? 2 : 3; d > 0; --d, --r) {
	```
	Start an inner loop to process 2 or 3 digits at a time. If there are exactly 2 or 4 digits remaining, group them in 2s; otherwise, group in 3s.

9. **Add Digit to Answer**
	```cpp
	            ans += s[i++];
	```
	Add the current digit `s[i]` to the `ans` string, then increment `i` to move to the next digit.

10. **Add Dash If Needed**
	```cpp
	        if (r) ans += '-';
	```
	If there are remaining digits, add a dash `'-'` to separate the groups.

11. **Return Formatted String**
	```cpp
	    return ans;
	```
	Return the formatted string `ans` after processing all digits and grouping them with dashes.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The algorithm processes each character of the string exactly once, resulting in a linear time complexity.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage of the cleaned string and the result string.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/reformat-phone-number/description/)

---
{{< youtube U8EwUjwKYFg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

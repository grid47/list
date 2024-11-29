
+++
authors = ["grid47"]
title = "Leetcode 1736: Latest Time by Replacing Hidden Digits"
date = "2024-05-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1736: Latest Time by Replacing Hidden Digits in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Greedy"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "d1hJCKlEGBM"
youtube_upload_date="2021-01-24"
youtube_thumbnail="https://i.ytimg.com/vi_webp/d1hJCKlEGBM/maxresdefault.webp"
comments = true
+++



---
You are given a time string in the format `hh:mm`, where some digits may be missing and represented by a question mark (`?`). Your task is to replace the `?` with digits to form the latest valid time in the 24-hour format, which is between `00:00` and `23:59`.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a string representing a time in the format `hh:mm`, where some digits may be hidden by `?` characters. The goal is to replace `?` with digits to form the latest valid time.
- **Example:** `Input: time = "1?:?4"`
- **Constraints:**
	- The input time string is guaranteed to be in the format hh:mm.
	- The digits of the input time can be replaced by valid digits to form a valid time.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the latest valid time obtained by replacing the question marks in the input string with valid digits.
- **Example:** `Output: "19:54"`
- **Constraints:**
	- The output is a valid time string in the format hh:mm.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to determine the latest valid time by replacing the `?` characters with the largest possible digits that form a valid time.

- 1. Identify the valid range for the hour based on the first digit, considering if the second digit is `?`.
- 2. If the second digit is `?`, replace it with the largest possible value based on the first digit.
- 3. For the minutes part, replace any `?` with the largest valid digit (`5` for the tens place, `9` for the ones place).
- 4. Return the modified time string.
{{< dots >}}
### Problem Assumptions ✅
- The input time string is guaranteed to be in a valid format and the solution always exists.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: time = "2?:?0"`  \
  **Explanation:** The latest hour starting with '2' is '23', and the latest minute ending with '0' is '50'. Therefore, the result is '23:50'.

- **Input:** `Input: time = "0?:3?"`  \
  **Explanation:** The latest valid hour with '0' in the first digit can be '09'. The latest minute ending with '9' is '39'. Therefore, the result is '09:39'.

{{< dots >}}
## Approach 🚀
We will iterate through the time string and replace the `?` characters with the largest possible digits that result in a valid time.

### Initial Thoughts 💭
- We need to replace each '?' with the largest possible digit that results in a valid time.
- We can handle the hour and minute separately, replacing the question marks with the largest possible values.
{{< dots >}}
### Edge Cases 🌐
- The input string is guaranteed to be in the correct time format and non-empty.
- The time format will always be hh:mm, so no concerns about large inputs.
- Consider edge cases where the hours or minutes have multiple question marks (e.g., `??:??`).
- Ensure that the time is within the valid range of `00:00` to `23:59`.
{{< dots >}}
## Code 💻
```cpp
string maximumTime(string t) {
    if(t[0]=='?' && t[1]=='?')
    {
        t[0]='2';
        t[1]='3';
    }
    if(t[0]=='?')
    {
        if(t[1]<='0')
            t[0]='2';
        else if(t[1]<='1')
            t[0]='2';
        else if(t[1]<='2')
            t[0]='2';
        else if(t[1]<='3')
            t[0]='2';
        else 
            t[0]='1';
    }
    if(t[1]=='?')
    {
        if(t[0]=='2')
            t[1]='3';
        else 
            t[1]='9';
    }
    if(t[3]=='?' && t[4]=='?')
    {
        t[3]='5';
        t[4]='9';
    }
    if(t[3]=='?')
    {
        t[3]='5';
    }
    if(t[4]=='?')
    {
        t[4]='9';
    }
    return t;
}
```

This function takes a string representing a time in the format `hh:mm` with possible '?' placeholders and replaces the '?' with the largest possible valid time.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	string maximumTime(string t) {
	```
	The function `maximumTime` is defined, which takes a string `t` representing a time with potential '?' placeholders and returns a string with the largest possible valid time.

2. **Condition Check**
	```cpp
	    if(t[0]=='?' && t[1]=='?')
	```
	If both the first and second characters of the time string are '?', we replace them with the maximum valid time '23'.

3. **Assignment**
	```cpp
	        t[0]='2';
	```
	The first character `t[0]` is replaced with '2', the largest valid value for the hour.

4. **Assignment**
	```cpp
	        t[1]='3';
	```
	The second character `t[1]` is replaced with '3', forming the largest valid hour '23'.

5. **Block End**
	```cpp
	    }
	```
	Closing the block for replacing '?' when both `t[0]` and `t[1]` are '?'

6. **Condition Check**
	```cpp
	    if(t[0]=='?')
	```
	If the first character `t[0]` is '?', we determine its value based on the second character `t[1]`.

7. **Condition Check**
	```cpp
	        if(t[1]<='0')
	```
	If the second character `t[1]` is less than or equal to '0', we set `t[0]` to '2' to form a valid time.

8. **Assignment**
	```cpp
	            t[0]='2';
	```
	Set `t[0]` to '2' when `t[1]` is less than or equal to '0'.

9. **Condition Check**
	```cpp
	        else if(t[1]<='1')
	```
	If `t[1]` is less than or equal to '1', we can also set `t[0]` to '2' for a valid time.

10. **Assignment**
	```cpp
	            t[0]='2';
	```
	Set `t[0]` to '2' when `t[1]` is less than or equal to '1'.

11. **Condition Check**
	```cpp
	        else if(t[1]<='2')
	```
	If `t[1]` is less than or equal to '2', `t[0]` can still be '2'.

12. **Assignment**
	```cpp
	            t[0]='2';
	```
	Set `t[0]` to '2' when `t[1]` is less than or equal to '2'.

13. **Condition Check**
	```cpp
	        else if(t[1]<='3')
	```
	If `t[1]` is less than or equal to '3', we set `t[0]` to '2'.

14. **Assignment**
	```cpp
	            t[0]='2';
	```
	Set `t[0]` to '2' when `t[1]` is less than or equal to '3'.

15. **Else Block**
	```cpp
	        else 
	```
	If none of the above conditions are met, we set `t[0]` to '1'.

16. **Assignment**
	```cpp
	            t[0]='1';
	```
	Set `t[0]` to '1' when none of the previous conditions are met.

17. **Condition Check**
	```cpp
	    if(t[1]=='?')
	```
	If the second character `t[1]` is '?', we determine its value based on the first character `t[0]`.

18. **Block Start**
	```cpp
	    {
	```
	Opening the block for replacing `t[1]` when it is '?'

19. **Condition Check**
	```cpp
	        if(t[0]=='2')
	```
	If the first character `t[0]` is '2', we set `t[1]` to '3' to form a valid time.

20. **Assignment**
	```cpp
	            t[1]='3';
	```
	Set `t[1]` to '3' when `t[0]` is '2'.

21. **Else Block**
	```cpp
	        else 
	```
	If `t[0]` is not '2', we set `t[1]` to '9'.

22. **Assignment**
	```cpp
	            t[1]='9';
	```
	Set `t[1]` to '9' when `t[0]` is not '2'.

23. **Condition Check**
	```cpp
	    if(t[3]=='?' && t[4]=='?')
	```
	If both the third and fourth characters are '?', we replace them with the maximum valid minute '59'.

24. **Assignment**
	```cpp
	        t[3]='5';
	```
	Set `t[3]` to '5' for the largest valid minute.

25. **Assignment**
	```cpp
	        t[4]='9';
	```
	Set `t[4]` to '9' for the largest valid minute.

26. **Condition Check**
	```cpp
	    if(t[3]=='?')
	```
	If the third character `t[3]` is '?', we set it to '5' for the largest valid minute.

27. **Assignment**
	```cpp
	        t[3]='5';
	```
	Set `t[3]` to '5' when it is '?'.

28. **Condition Check**
	```cpp
	    if(t[4]=='?')
	```
	If the fourth character `t[4]` is '?', we set it to '9' for the largest valid minute.

29. **Assignment**
	```cpp
	        t[4]='9';
	```
	Set `t[4]` to '9' when it is '?'.

30. **Return**
	```cpp
	    return t;
	```
	Return the string `t` after all '?' characters have been replaced with the largest valid values.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1), as the solution only involves checking a fixed number of characters (always 5).
- **Average Case:** O(1), since the input string length is fixed.
- **Worst Case:** O(1), since the time format is always fixed at 5 characters.

The time complexity is constant, O(1), because we only need to iterate over a fixed-size string.

### Space Complexity 💾
- **Best Case:** O(1), since we are not using extra data structures.
- **Worst Case:** O(1), as we only need a constant amount of extra space for storing the result.

The space complexity is constant, O(1), as we only modify the input string in-place.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/latest-time-by-replacing-hidden-digits/description/)

---
{{< youtube d1hJCKlEGBM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

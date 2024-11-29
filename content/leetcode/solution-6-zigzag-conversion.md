
+++
authors = ["grid47"]
title = "Leetcode 6: Zigzag Conversion"
date = "2024-11-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 6: Zigzag Conversion in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/6.webp"
youtube = "2NMMVnxV6lo"
youtube_upload_date="2024-07-30"
youtube_thumbnail="https://i.ytimg.com/vi/2NMMVnxV6lo/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/6.webp" 
    alt="A ribbon of light moving in smooth, calming zigzags across a gentle curve."
    caption="Solution to LeetCode 6: Zigzag Conversion Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given a string, write it in a zigzag pattern on a specified number of rows and then read the rows line by line to create the final string. Return this transformed string.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string and an integer specifying the number of rows for the zigzag pattern.
- **Example:** `Input: s = 'HELLOZIGZAG', numRows = 3`
- **Constraints:**
	- 1 <= s.length <= 1000
	- s consists of English letters (lower-case and upper-case), ',' and '.'.
	- 1 <= numRows <= 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the string after converting it into the zigzag pattern and reading it row by row.
- **Example:** `Output: 'HLZGELOIZALG'`
- **Constraints:**
	- The output must be a single string.

{{< dots >}}
### Core Logic 🔍
**Goal:** Transform the string into the zigzag pattern and read row by row to form the final output.

- Initialize an array of strings to represent each row in the zigzag pattern.
- Iterate through the input string and append characters to appropriate rows in a zigzag manner.
- Switch direction (downwards or upwards) when the top or bottom row is reached.
- Concatenate the strings from all rows to create the final result.
{{< dots >}}
### Problem Assumptions ✅
- The number of rows will always be less than or equal to the length of the string.
- If numRows is 1, the result is the same as the input string.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: s = 'HELLOZIGZAG', numRows = 3`  \
  **Explanation:** The zigzag pattern for 3 rows creates the final string 'HLZGELOIZALG'.

- **Input:** `Input: s = 'DSACODE', numRows = 4`  \
  **Explanation:** The zigzag pattern for 4 rows creates the final string 'DCOESADE'.

{{< dots >}}
## Approach 🚀
The solution uses a simulation approach to mimic the zigzag traversal and builds each row incrementally.

### Initial Thoughts 💭
- The zigzag traversal alternates direction (downwards or upwards) when boundaries are reached.
- Using an array of strings for each row simplifies the logic for appending characters.
- We can iterate through the string once while maintaining a direction flag and row index.
{{< dots >}}
### Edge Cases 🌐
- No empty inputs due to constraints.
- The solution should handle strings of length 1000 and up to 1000 rows efficiently.
- If numRows is 1, the output is the same as the input string.
- Ensure memory and time usage are optimized for large input sizes.
{{< dots >}}
## Code 💻
```cpp
string convert(string str, int n) {

    int len = str.size();
    
    if(n == 1) return str;
    
    vector<string> s(n, "");

    bool down = true; int ridx = 1;
    for (int i = 0; i < len; i++) {

        s[ridx - 1] += str[i];
        if (down) ridx++;
        else      ridx--;

        if ( (ridx == n) || 
             (ridx == 1) ) 
            down = !down;
        
    }
    string res = "";
    for(int i = 0; i < n; i++)
        res += s[i];
    return res;
}
```

This code implements the `convert` function, which takes a string `str` and an integer `n` as input and returns a string formed by zigzagging the input string in a zigzag pattern of `n` rows.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	string convert(string str, int n) {
	```
	Declare the `convert` function, which takes a string `str` and an integer `n` as input and returns a string.

2. **Variable Initialization**
	```cpp
	    int len = str.size();
	```
	Calculate the length of the input string `str` and store it in the `len` variable.

3. **Conditional Return**
	```cpp
	    if(n == 1) return str;
	```
	If `n` is 1, return the input string `str` as it is.

4. **Array Initialization**
	```cpp
	    vector<string> s(n, "");
	```
	Initialize a vector `s` of size `n` to store the characters of each row. Each element is initially an empty string.

5. **Variable Initialization**
	```cpp
	    bool down = true; int ridx = 1;
	```
	Initialize `down` to `true` to indicate the direction of zigzagging, and `ridx` to 1 to track the current row index.

6. **Loop Iteration**
	```cpp
	    for (int i = 0; i < len; i++) {
	```
	Iterate over each character in the input string.

7. **String Manipulation**
	```cpp
	        s[ridx - 1] += str[i];
	```
	Append the current character `str[i]` to the string at index `ridx - 1` in the `s` vector.

8. **Conditional Update**
	```cpp
	        if (down) ridx++;
	```
	If `down` is true, increment `ridx` to move to the next row.

9. **Conditional Update**
	```cpp
	        else      ridx--;
	```
	If `down` is false, decrement `ridx` to move to the previous row.

10. **Conditional Update**
	```cpp
	        if ( (ridx == n) || 
	```
	Check if we've reached the bottom row.

11. **Conditional Update**
	```cpp
	             (ridx == 1) ) 
	```
	Check if we've reached the top row.

12. **Conditional Update**
	```cpp
	            down = !down;
	```
	Toggle the `down` flag to change the direction of zigzagging.

13. **Variable Initialization**
	```cpp
	    string res = "";
	```
	Initialize an empty string `res` to store the final result.

14. **Loop Iteration**
	```cpp
	    for(int i = 0; i < n; i++)
	```
	Iterate over each row in the `s` vector.

15. **String Manipulation**
	```cpp
	        res += s[i];
	```
	Append the current row `s[i]` to the `res` string.

16. **Return Value**
	```cpp
	    return res;
	```
	Return the final zigzagged string `res`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(s.length)
- **Average Case:** O(s.length)
- **Worst Case:** O(s.length)

Each character in the string is processed exactly once.

### Space Complexity 💾
- **Best Case:** O(s.length)
- **Worst Case:** O(s.length)

Space is used for storing the strings for each row.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/zigzag-conversion/description/)

---
{{< youtube 2NMMVnxV6lo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

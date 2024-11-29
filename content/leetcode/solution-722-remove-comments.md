
+++
authors = ["grid47"]
title = "Leetcode 722: Remove Comments"
date = "2024-08-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 722: Remove Comments in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/722.webp"
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/722.webp" 
    alt="A source code where comments are removed, with the comments fading out and the code glowing softly."
    caption="Solution to LeetCode 722: Remove Comments Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given a C++ program represented as an array of strings, where each string corresponds to a line of code. Your task is to remove all comments from the code. The two types of comments in C++ are line comments (//) and block comments (/* ... */). After removing comments, return the modified code as an array of strings, excluding any empty lines.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** An array of strings representing lines of a C++ program.
- **Example:** `["/*This is a test program*/", "int main()", "{", "  // This is a variable declaration", "int a, b, c;"]`
- **Constraints:**
	- 1 <= source.length <= 100
	- 0 <= source[i].length <= 80
	- No single or double quotes in the input
	- Every open block comment will eventually be closed

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the modified program as an array of strings where all comments are removed, and empty lines are excluded.
- **Example:** `["int main()", "{", "  int a, b, c;", "  a = b + c;", "}"]`
- **Constraints:**
	- Each output string will be non-empty.

{{< dots >}}
### Core Logic 🔍
**Goal:** To remove comments from the given C++ program code and return the cleaned code.

- Iterate through each line of the source code.
- Identify and skip characters inside block comments (/*...*/).
- Identify line comments (//) and ignore the remainder of the line.
- Ensure that lines which become empty after removing comments are not included in the result.
{{< dots >}}
### Problem Assumptions ✅
- The input is always valid with properly closed comments.
- There are no macros or defines that affect the comments.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1`  \
  **Explanation:** In this example, the block comment removes multiple lines and part of a line, while the line comment removes everything after the '//' in the line.

- **Input:** `Example 2`  \
  **Explanation:** Here, the block comment starts and ends in the middle of the string, removing implicit newlines between 'a' and 'b'.

{{< dots >}}
## Approach 🚀
The solution uses an iterative approach to process each line of code, removing comments based on whether the code is inside a block comment or a line comment.

### Initial Thoughts 💭
- The code must handle two types of comments: line comments and block comments.
- Block comments can span multiple lines, and a line comment is limited to the current line.
- A simple loop that processes each character in the string will help identify and remove comments.
{{< dots >}}
### Edge Cases 🌐
- Handle empty input arrays gracefully.
- The solution should efficiently handle inputs of maximum length.
- Ensure that multiline block comments and line comments are processed correctly even when nested.
- Ensure that every block comment is closed, as guaranteed by the problem constraints.
{{< dots >}}
## Code 💻
```cpp
vector<string> removeComments(vector<string>& source) {
    vector<string> ans;
    bool is_mul = false;
    string res = "";
    for(int i = 0; i < source.size(); i++) {
        string str = source[i];
        res = is_mul? res:"";
        for(int j = 0; j < str.size() ; j++) {
            if(!is_mul) {
                if (j < str.size() - 1 && str[j] == '/' && str[j + 1] == '/') {
                    break;
                } else if (j < str.size() - 1 && str[j] == '/' && str[j + 1] == '*') {
                    is_mul = true;
                    j++;
                } else {
                    res += str[j];
                }
            } else {
                if(j < str.size() - 1 && str[j] == '*' && str[j + 1] == '/') {
                    is_mul = false;
                    j++;
                }
            }
        }

        if(!is_mul && res != "") ans.push_back(res);
    }
    return ans;
}
};

//
/*
*/
/* */
```

This function removes comments from a vector of strings. It handles both single-line ('//') and multi-line ('/* */') comments, ensuring that no comment remains in the final output.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<string> removeComments(vector<string>& source) {
	```
	Defines the 'removeComments' function that takes a reference to a vector of strings and returns a vector of strings after removing comments.

2. **Variable Initialization**
	```cpp
	    vector<string> ans;
	```
	Declares a vector 'ans' that will store the final result after comments are removed.

3. **Variable Initialization**
	```cpp
	    bool is_mul = false;
	```
	Declares a boolean variable 'is_mul' to track whether multi-line comments are being processed.

4. **Variable Initialization**
	```cpp
	    string res = "";
	```
	Declares a string variable 'res' to accumulate non-comment characters.

5. **Looping Through Source**
	```cpp
	    for(int i = 0; i < source.size(); i++) {
	```
	Starts a loop to iterate over each string in the 'source' vector.

6. **Processing Current String**
	```cpp
	        string str = source[i];
	```
	Assigns the current string in the vector to 'str' for further processing.

7. **Resetting Result**
	```cpp
	        res = is_mul? res:"";
	```
	If currently inside a multi-line comment, keeps 'res' unchanged, otherwise resets it to an empty string.

8. **Inner Loop**
	```cpp
	        for(int j = 0; j < str.size() ; j++) {
	```
	Starts an inner loop to process each character of the current string 'str'.

9. **If Not In Multi-line Comment**
	```cpp
	            if(!is_mul) {
	```
	Checks if the current character is not inside a multi-line comment.

10. **Handling Single-line Comment**
	```cpp
	                if (j < str.size() - 1 && str[j] == '/' && str[j + 1] == '/') {
	```
	Checks for the start of a single-line comment ('//').

11. **Breaking for Single-line Comment**
	```cpp
	                    break;
	```
	If a single-line comment is detected, breaks out of the loop to stop processing further characters in the line.

12. **Handling Multi-line Comment Start**
	```cpp
	                } else if (j < str.size() - 1 && str[j] == '/' && str[j + 1] == '*') {
	```
	Checks for the start of a multi-line comment ('/*').

13. **Entering Multi-line Comment**
	```cpp
	                    is_mul = true;
	```
	Marks the beginning of a multi-line comment.

14. **Skipping Character in Multi-line Comment**
	```cpp
	                    j++;
	```
	Skips the next character in the string as part of multi-line comment handling.

15. **Adding Non-comment Character**
	```cpp
	                } else {
	```
	If the current character is not part of a comment, adds it to the result string 'res'.

16. **Accumulating Result**
	```cpp
	                    res += str[j];
	```
	Adds the current character to the 'res' string.

17. **If In Multi-line Comment**
	```cpp
	            } else {
	```
	Handles the case where the current character is inside a multi-line comment.

18. **Handling Multi-line Comment End**
	```cpp
	                if(j < str.size() - 1 && str[j] == '*' && str[j + 1] == '/') {
	```
	Checks for the end of a multi-line comment ('*/').

19. **Exiting Multi-line Comment**
	```cpp
	                    is_mul = false;
	```
	Marks the end of a multi-line comment.

20. **Skipping Character in Multi-line Comment End**
	```cpp
	                    j++;
	```
	Skips the next character in the string after detecting the end of a multi-line comment.

21. **End of If-Else**
	```cpp
	                }
	```
	Ends the conditional check for the multi-line comment.

22. **Return Result**
	```cpp
	        if(!is_mul && res != "") ans.push_back(res);
	```
	Adds the processed string (without comments) to the result vector if it is not empty.

23. **Final Return**
	```cpp
	    return ans;
	```
	Returns the final result vector with all comments removed.

24. **Function End**
	```cpp
	}
	```
	Ends the function definition.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the total number of characters in the input.
- **Average Case:** O(n), where n is the total number of characters in the input.
- **Worst Case:** O(n), where n is the total number of characters in the input.

The time complexity is linear relative to the size of the input.

### Space Complexity 💾
- **Best Case:** O(n), where n is the total number of characters in the input.
- **Worst Case:** O(n), where n is the total number of characters in the input.

The space complexity is also linear, as we store the cleaned lines in a separate array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/remove-comments/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

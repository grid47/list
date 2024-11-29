
+++
authors = ["grid47"]
title = "Leetcode 1190: Reverse Substrings Between Each Pair of Parentheses"
date = "2024-07-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1190: Reverse Substrings Between Each Pair of Parentheses in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "n_pCJmg-RyU"
youtube_upload_date="2024-07-11"
youtube_thumbnail="https://i.ytimg.com/vi/n_pCJmg-RyU/maxresdefault.jpg"
comments = true
+++



---
Given a string containing lowercase English letters and balanced parentheses, reverse the substrings enclosed within each pair of parentheses, starting from the innermost ones. After processing, return the resulting string without any parentheses.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** A single string `s` containing lowercase English letters and parentheses. Parentheses in the string are guaranteed to be balanced.
- **Example:** `Input: s = "(xy(z))"`
- **Constraints:**
	- 1 <= s.length <= 2000
	- s only contains lowercase English characters and parentheses.
	- All parentheses are guaranteed to be balanced.

{{< dots >}}
### Output Specifications 📤
- **Output:** A string representing the final processed version of `s` after reversing all substrings enclosed in parentheses and removing the parentheses.
- **Example:** `Output: "zyx"`
- **Constraints:**
	- The output string must not contain any parentheses.
	- The order of characters must be correct after processing.

{{< dots >}}
### Core Logic 🔍
**Goal:** To reverse substrings enclosed within matching parentheses from the innermost to the outermost and return the processed string without parentheses.

- Iterate through the string and process characters.
- Push the indices of opening parentheses onto a stack.
- When encountering a closing parenthesis, reverse the substring from the last opening parenthesis to the current position.
- Remove parentheses and construct the final string.
{{< dots >}}
### Problem Assumptions ✅
- The input string always contains balanced parentheses.
- The output string should not contain any parentheses.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: s = "(ab(cd))"`  \
  **Explanation:** Reverse the substring "cd" to get "dc". Then reverse the entire substring "abdc" to get "dcba". Remove the parentheses to produce the result "dcba".

- **Input:** `Input: s = "a(b(cd)e)f"`  \
  **Explanation:** Reverse "cd" to get "dc". Then reverse "b(dce)" to get "ecd". Combine with the rest of the string to get "aecdfe".

- **Input:** `Input: s = "a(b)c"`  \
  **Explanation:** Reverse the substring "b" to get "b". Remove parentheses to produce the result "abc".

{{< dots >}}
## Approach 🚀
Use a stack-based approach to handle parentheses and efficiently reverse substrings enclosed within them.

### Initial Thoughts 💭
- Parentheses define a hierarchy of substrings.
- The innermost substrings should be reversed first.
- The string processing can be done iteratively using a stack.
- A stack can track the start positions of parentheses.
- The reverse operation can be performed in-place.
{{< dots >}}
### Edge Cases 🌐
- Input: s = ""
- Output: ""
- Input: s = "a" + "(" + "b"*999 + ")"
- Output: The reversed result with efficient processing.
- Input: s = "a()b"
- Output: "ab" (Empty parentheses are ignored).
- Ensure processing time is linear relative to the string length.
{{< dots >}}
## Code 💻
```cpp
string reverseParentheses(string s) {
    stack<int> stk;
    string res;
    
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(') 
            stk.push(res.size());
        else if(s[i] == ')') {
            int j = stk.top();
            stk.pop();
            reverse(res.begin() + j, res.end());
        } else res.push_back(s[i]);
    }
    
    return res;
}
```

This function reverses substrings enclosed in parentheses. It uses a stack to track opening parentheses and reverses the string between matching parentheses.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	string reverseParentheses(string s) {
	```
	Defines the function `reverseParentheses` that takes a string `s` as input.

2. **Stack Initialization**
	```cpp
	    stack<int> stk;
	```
	Initializes a stack to store the indices of opening parentheses.

3. **String Initialization**
	```cpp
	    string res;
	```
	Initializes the result string to build the final output.

4. **Loop Declaration**
	```cpp
	    for(int i = 0; i < s.size(); i++) {
	```
	Iterates through each character in the input string `s`.

5. **Opening Parenthesis Check**
	```cpp
	        if(s[i] == '(') 
	```
	Checks if the current character is an opening parenthesis.

6. **Push Index**
	```cpp
	            stk.push(res.size());
	```
	Pushes the current size of the result string to the stack, marking the start of a substring.

7. **Closing Parenthesis Check**
	```cpp
	        else if(s[i] == ')') {
	```
	Checks if the current character is a closing parenthesis.

8. **Top Index Retrieval**
	```cpp
	            int j = stk.top();
	```
	Retrieves the index of the matching opening parenthesis from the stack.

9. **Pop Stack**
	```cpp
	            stk.pop();
	```
	Removes the top element from the stack as it has been processed.

10. **Reverse Substring**
	```cpp
	            reverse(res.begin() + j, res.end());
	```
	Reverses the substring in the result string between the matching parentheses.

11. **Append Character**
	```cpp
	        } else res.push_back(s[i]);
	```
	Appends non-parenthesis characters to the result string.

12. **Return Result**
	```cpp
	    return res;
	```
	Returns the final modified result string after processing.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

Each character in the string is processed at most twice (once during the initial traversal and once during the reverse operation).

### Space Complexity 💾
- **Best Case:** O(1) (excluding input and output storage)
- **Worst Case:** O(n)

The stack can grow up to O(n) in the worst case due to nested parentheses.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/description/)

---
{{< youtube n_pCJmg-RyU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

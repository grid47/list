
+++
authors = ["grid47"]
title = "Leetcode 20: Valid Parentheses"
date = "2024-11-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 20: Valid Parentheses in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Stack"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/20.webp"
youtube = "WTzjTskDFMg"
youtube_upload_date="2021-04-19"
youtube_thumbnail="https://i.ytimg.com/vi/WTzjTskDFMg/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/20.webp" 
    alt="An elegant loop of parentheses, glowing and connected in a balanced, harmonious way."
    caption="Solution to LeetCode 20: Valid Parentheses Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given a string containing characters representing various types of brackets: '(', ')', '{', '}', '[' and ']'. Your task is to determine if the input string is valid. A string is considered valid if: 
1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
3. Every close bracket has a corresponding open bracket of the same type.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string s containing only the characters '(', ')', '{', '}', '[' and ']'.
- **Example:** `s = '({[]})'`
- **Constraints:**
	- 1 <= s.length <= 10^4
	- s consists of parentheses only '()[]{}'.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is a boolean value: true if the string is valid, otherwise false.
- **Example:** `true`
- **Constraints:**
	- The result should be a boolean indicating whether the input string is valid.

{{< dots >}}
### Core Logic 🔍
**Goal:** To check whether the string contains valid parentheses by ensuring each open bracket has a corresponding and correctly ordered closing bracket.

- Initialize an empty stack to keep track of open brackets.
- Iterate through each character in the string.
- If the character is an open bracket ('(', '{', or '['), push it onto the stack.
- If the character is a closing bracket (')', '}', or ']'), check if the stack is not empty and if the top of the stack matches the corresponding open bracket.
- If there's a match, pop the stack, else return false.
- After iterating through the string, if the stack is empty, return true (valid). Otherwise, return false (invalid).
{{< dots >}}
### Problem Assumptions ✅
- The input string is always non-empty.
- The input string contains only valid characters.
{{< dots >}}
## Examples 🧩
- **Input:** `s = '({[]})'`  \
  **Explanation:** This string contains balanced brackets: each opening bracket has a corresponding closing bracket in the correct order. Thus, the output is true.

- **Input:** `s = '({[})'`  \
  **Explanation:** This string contains mismatched brackets. The order is incorrect, and the closing bracket doesn't match the last opening bracket, so the output is false.

- **Input:** `s = '([])'`  \
  **Explanation:** This string contains balanced brackets: each opening bracket has a corresponding closing bracket in the correct order. Thus, the output is true.

{{< dots >}}
## Approach 🚀
The approach to solve this problem is by using a stack to ensure that each open bracket has a corresponding closing bracket in the correct order.

### Initial Thoughts 💭
- Using a stack data structure helps ensure the correct order of opening and closing brackets.
- Each closing bracket should match the most recent open bracket.
- By pushing open brackets onto the stack and popping them when encountering matching closing brackets, we can validate the string efficiently.
{{< dots >}}
### Edge Cases 🌐
- The input string will never be empty. There will always be at least one bracket.
- The solution handles strings of length up to 10^4 efficiently.
- Handles cases with a single pair of brackets as well as very large balanced or unbalanced sequences.
- The solution must work for all strings of valid length and with valid bracket characters.
{{< dots >}}
## Code 💻
```cpp
bool isValid(string s) {
    stack<char> stk;
    for(char x: s) {
        if(x == '(' || x == '{' || x == '[') {
            stk.push(x);
        } else {
                 if(x == ')' && !stk.empty() && stk.top() == '(') stk.pop();
            else if(x == '}' && !stk.empty() && stk.top() == '{') stk.pop();
            else if(x == ']' && !stk.empty() && stk.top() == '[') stk.pop();                
            else return false;
        }
    }
    return stk.empty();
}
```

This code implements a function to check if a given string of parentheses, braces, and brackets is valid. A valid string means that each opening bracket has a corresponding closing bracket in the correct order.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	bool isValid(string s) {
	```
	This line declares a function named 'isValid' that takes a string 's' as input and returns a boolean value indicating whether the string is valid.

2. **Stack Initialization**
	```cpp
	    stack<char> stk;
	```
	This line initializes an empty stack of characters to store opening brackets.

3. **Loop Iteration**
	```cpp
	    for(char x: s) {
	```
	This line starts a loop to iterate over each character 'x' in the input string 's'.

4. **Condition Check**
	```cpp
	        if(x == '(' || x == '{' || x == '[') {
	```
	This line checks if the current character 'x' is an opening bracket ('(', '{', or '[').

5. **Stack Operation**
	```cpp
	            stk.push(x);
	```
	If 'x' is an opening bracket, it is pushed onto the stack.

6. **Conditional Check**
	```cpp
	        } else {
	```
	This line handles the case where 'x' is not an opening bracket.

7. **Stack Operation**
	```cpp
	                 if(x == ')' && !stk.empty() && stk.top() == '(') stk.pop();
	```
	If 'x' is a closing bracket ')' and the stack is not empty and the top element of the stack is an opening bracket '(', then the top element is popped from the stack.

8. **Stack Operation**
	```cpp
	            else if(x == '}' && !stk.empty() && stk.top() == '{') stk.pop();
	```
	If 'x' is a closing bracket '}' and the stack is not empty and the top element of the stack is an opening bracket '{', then the top element is popped from the stack.

9. **Stack Operation**
	```cpp
	            else if(x == ']' && !stk.empty() && stk.top() == '[') stk.pop();                
	```
	If 'x' is a closing bracket ']' and the stack is not empty and the top element of the stack is an opening bracket '[', then the top element is popped from the stack.

10. **Return**
	```cpp
	            else return false;
	```
	If none of the above conditions are met, it means there's an unmatched closing bracket, and the function returns false.

11. **Return**
	```cpp
	    return stk.empty();
	```
	If the loop completes without returning false, it means all brackets are matched. The function returns true if the stack is empty, indicating that all brackets have been paired.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

We iterate through the string once, performing constant time operations for each character.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) in the worst case when all characters are opening brackets.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/valid-parentheses/description/)

---
{{< youtube WTzjTskDFMg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

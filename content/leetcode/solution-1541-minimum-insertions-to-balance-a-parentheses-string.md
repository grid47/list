
+++
authors = ["grid47"]
title = "Leetcode 1541: Minimum Insertions to Balance a Parentheses String"
date = "2024-06-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1541: Minimum Insertions to Balance a Parentheses String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Stack","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "PEKAlnmbBCc"
youtube_upload_date="2020-10-05"
youtube_thumbnail="https://i.ytimg.com/vi/PEKAlnmbBCc/maxresdefault.jpg"
comments = true
+++



---
You are given a string `s` containing only the characters `'('` and `')'`. A string is considered balanced if each `'('` has a matching pair of consecutive `'))'` and if they appear in the correct order. Your task is to return the minimum number of insertions needed to make the string balanced.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string `s` containing only `'('` and `')'.
- **Example:** `s = '(()))'`
- **Constraints:**
	- 1 <= s.length <= 10^5
	- s consists only of the characters '(' and ')'.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of insertions required to make the string balanced.
- **Example:** `Output: 1`
- **Constraints:**
	- The string can be balanced by inserting characters anywhere in the string.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to determine how many insertions are needed to balance the string.

- 1. Traverse through the string and use a stack to keep track of unmatched parentheses.
- 2. For every closing parenthesis, try to match it with an opening parenthesis.
- 3. If there is no match, determine how many insertions are required to balance the string.
{{< dots >}}
### Problem Assumptions ✅
- The string is only composed of characters '(' and ')'.
- The string can be unbalanced and requires insertions to be fixed.
{{< dots >}}
## Examples 🧩
- **Input:** `s = '(()))'`  \
  **Explanation:** The first '(' requires one more ')' to balance the string. We add one more ')' to get '(())))'.

- **Input:** `s = '()))'`  \
  **Explanation:** No insertions are needed because the string is already balanced.

- **Input:** `s = '))())('`  \
  **Explanation:** We need to add one '(' to match the first two closing parentheses and one '))' to match the last '('.

{{< dots >}}
## Approach 🚀
To solve the problem, we will traverse through the string and calculate the insertions needed to balance the parentheses.

### Initial Thoughts 💭
- A stack can help match opening and closing parentheses.
- If there is an unmatched closing parenthesis, we need to add opening or closing parentheses.
- We need to traverse the string and handle unmatched parentheses by tracking them in a stack.
{{< dots >}}
### Edge Cases 🌐
- The string should not be empty, as the length is guaranteed to be at least 1.
- Consider strings with lengths up to 10^5 characters.
- Ensure the string contains only the characters '(' and ')'.
- The string must be within the given length and contain only valid characters.
{{< dots >}}
## Code 💻
```cpp
int minInsertions(string s) {
    int res = 0;
    
    int n = s.size();
    
    stack<char> stk;
    for(int i = 0; i < n; i++) {
        if(s[i] == '(') {
            stk.push('(');
            continue;
        }
        
        if(i + 1 < n && s[i + 1] == ')') {
            if(!stk.empty()) stk.pop();
            else res++;
            i++;
        } else {
            if(!stk.empty()) {stk.pop(); res++;}
            else res += 2;
        }
        
    }
    
    return res + stk.size() * 2;
}
```

This code solves the problem of finding the minimum number of insertions required to make a given string valid in terms of balanced parentheses.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	int minInsertions(string s) {
	```
	This line declares the function `minInsertions` which takes a string `s` as input and returns an integer value representing the minimum insertions required.

2. **Variable Initialization**
	```cpp
	    int res = 0;
	```
	The variable `res` is initialized to 0. This will keep track of the number of insertions needed.

3. **String Length Calculation**
	```cpp
	    int n = s.size();
	```
	Here, the variable `n` is set to the size of the string `s`, which is the total number of characters in the string.

4. **Stack Initialization**
	```cpp
	    stack<char> stk;
	```
	A stack `stk` is created to help keep track of unmatched opening parentheses as we process the string.

5. **Loop**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	A loop begins to iterate through each character of the string `s`.

6. **Conditional Statement**
	```cpp
	        if(s[i] == '(') {
	```
	If the current character is an opening parenthesis, we proceed to push it onto the stack.

7. **Stack Operations**
	```cpp
	            stk.push('(');
	```
	Push the opening parenthesis onto the stack.

8. **Control Flow**
	```cpp
	            continue;
	```
	Skip the rest of the loop and move to the next character if it's an opening parenthesis.

9. **Conditional Statement**
	```cpp
	        if(i + 1 < n && s[i + 1] == ')') {
	```
	Check if the current character is followed by a closing parenthesis.

10. **Stack Operations**
	```cpp
	            if(!stk.empty()) stk.pop();
	```
	If the stack is not empty, pop the top item (the matching opening parenthesis).

11. **Result Calculation**
	```cpp
	            else res++;
	```
	If the stack is empty (no unmatched opening parenthesis), increment `res` by 1 as we need to insert a new opening parenthesis.

12. **Increment**
	```cpp
	            i++;
	```
	Skip the next character (closing parenthesis) since it was already processed.

13. **Else Block**
	```cpp
	        } else {
	```
	If the current character is not followed by a closing parenthesis, handle the unmatched parenthesis.

14. **Stack Operations**
	```cpp
	            if(!stk.empty()) {stk.pop(); res++;}
	```
	If there's an unmatched opening parenthesis in the stack, pop it and increment the `res` counter by 1.

15. **Result Calculation**
	```cpp
	            else res += 2;
	```
	If the stack is empty, two insertions are needed—one opening parenthesis and one closing parenthesis.

16. **Return Statement**
	```cpp
	    return res + stk.size() * 2;
	```
	Return the result, adding any remaining unmatched opening parentheses in the stack, each requiring two insertions.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

We need to traverse the string once, which gives a time complexity of O(n).

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

We use a stack to store the unmatched parentheses, so the space complexity is O(n).

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/description/)

---
{{< youtube PEKAlnmbBCc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

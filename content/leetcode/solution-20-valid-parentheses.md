
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
**Code:**

{{< highlight cpp >}}
class Solution {
public:
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
};
{{< /highlight >}}
---

### 🎯 **Problem Statement: Valid Parentheses**

Given a string `s` consisting only of the characters `'('`, `')'`, `'{'`, `'}'`, `'['`, and `']'`, determine if the string is valid. A string is valid if:
1. The brackets must close in the correct order. For example, `()` and `[]` are valid, but `(]` and `([)]` are not.
2. Each opening bracket must have a corresponding closing bracket of the same type.

#### Input:
- A string `s` of length `n` containing only the characters `'('`, `')'`, `'{'`, `'}'`, `'['`, and `']'`.

#### Output:
- Return `true` if the input string is valid, and `false` if it is not.

---

### 🧑‍💻 **Approach**

To determine if the string is valid, we can use a **stack** data structure. The stack will help us track the most recent opening bracket, ensuring that each closing bracket matches the most recent opening bracket.

#### **Steps to Solve the Problem:**
1. Initialize an empty stack.
2. Traverse through each character of the string:
   - If the character is an opening bracket (`'('`, `'{'`, `'['`), push it onto the stack.
   - If the character is a closing bracket (`')'`, `'}'`, `']'`), check if the stack is not empty and if the top of the stack matches the corresponding opening bracket. If it does, pop the top of the stack. Otherwise, the string is invalid.
3. After traversing the string, if the stack is empty, return `true` (all brackets were properly matched). If the stack is not empty, return `false` (some opening brackets were unmatched).

---

### 🧑‍💻 **Code Breakdown (Step by Step)**

```cpp
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;  // Step 1: Initialize an empty stack.
```
- We create an empty stack `stk` that will store characters. This will help track the most recent opening bracket.
  
```cpp
        for(char x: s) {  // Step 2: Iterate over each character in the string.
            if(x == '(' || x == '{' || x == '[') {  // Step 3: If the character is an opening bracket.
                stk.push(x);  // Step 4: Push the opening bracket onto the stack.
            } else {
```
- We loop through each character `x` in the string `s`. If the character is an opening bracket (`'('`, `'{'`, `'['`), we push it onto the stack.

```cpp
                // Step 5-7: Handle closing brackets and match with the top of the stack.
                if(x == ')' && !stk.empty() && stk.top() == '(') stk.pop();  // ')'
                else if(x == '}' && !stk.empty() && stk.top() == '{') stk.pop();  // '}'
                else if(x == ']' && !stk.empty() && stk.top() == '[') stk.pop();  // ']'
                else return false;  // Step 8: Invalid closing bracket.
            }
        }
```
- If the character is a closing bracket (`')'`, `'}'`, or `']'`), we check if the stack is not empty and if the top of the stack matches the corresponding opening bracket:
  - For `')'`, check if the top of the stack is `'('`.
  - For `'}'`, check if the top of the stack is `'{'`.
  - For `']'`, check if the top of the stack is `'['`.
- If the stack is empty or the top of the stack does not match the closing bracket, return `false`.

```cpp
        return stk.empty();  // Step 9: If the stack is empty, return true; otherwise, false.
    }
};
```
- After processing all characters, we check if the stack is empty:
  - If the stack is empty, it means that all opening brackets have been matched and closed properly, so we return `true`.
  - If the stack is not empty, return `false`, indicating that there are unmatched opening brackets.

---

### ⏱️ **Time and Space Complexity**

#### Time Complexity:
- **O(n)**, where `n` is the length of the string `s`.
- We iterate through the string once, and each stack operation (push or pop) takes constant time, `O(1)`.

#### Space Complexity:
- **O(n)** in the worst case. 
- In the worst case, the string consists entirely of opening brackets (e.g., `"((((("`), and the stack could hold up to `n` elements.

---

### 💡 **Conclusion**

This solution efficiently checks whether a string of parentheses, braces, and brackets is valid by utilizing a stack. It ensures that:
- Each opening bracket has a corresponding closing bracket of the same type.
- The brackets are properly nested and ordered.

**Key points**:
- Using a stack allows us to track the most recent opening bracket, ensuring it matches the appropriate closing bracket.
- The solution runs in **O(n)** time and uses **O(n)** space, where `n` is the length of the string.

This approach is a common and effective solution for problems involving balanced parentheses or similar structure matching problems. Happy coding! 🚀

[`Link to LeetCode Lab`](https://leetcode.com/problems/valid-parentheses/description/)

---
{{< youtube WTzjTskDFMg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |


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
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
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
};
{{< /highlight >}}
---


### Problem Statement
The task is to reverse the substrings that are enclosed within parentheses in a given string `s`. Each pair of parentheses defines a substring that should be reversed, and the challenge lies in handling nested parentheses appropriately. For example, given the input string `"abc(def(ghi)jkl)mno"`, the expected output would be `"abcihgdefjklmno"`. The goal is to efficiently process the string while respecting the structure of parentheses.

### Approach
The solution uses a stack data structure to keep track of the positions of the opening parentheses encountered while traversing the string. This allows the algorithm to know where to reverse the substrings when a closing parenthesis is found. The general approach can be summarized in the following steps:

1. **Traverse the String**: Iterate through each character in the input string.
2. **Use a Stack for Positions**: When an opening parenthesis is encountered, push the current length of the result string onto the stack.
3. **Reverse on Closing Parenthesis**: When a closing parenthesis is found, pop the position from the stack and reverse the substring from that position to the end of the result string.
4. **Construct the Final Result**: Continue appending characters to the result until the entire string is processed.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> stk;
        string res;
```
- **Lines 1-3**: The `Solution` class is defined, and the `reverseParentheses` method is declared. A stack `stk` is initialized to store the positions of opening parentheses, and a string `res` is created to build the result.

```cpp
        for(int i = 0; i < s.size(); i++) {
```
- **Line 4**: A loop starts to iterate over each character in the string `s` using the index `i`.

```cpp
            if(s[i] == '(') 
                stk.push(res.size());
```
- **Lines 5-6**: If the current character is an opening parenthesis `'('`, the current size of the result string `res` is pushed onto the stack. This marks where the substring starts that will need to be reversed later.

```cpp
            else if(s[i] == ')') {
                int j = stk.top();
                stk.pop();
                reverse(res.begin() + j, res.end());
            }
```
- **Lines 7-11**: If the current character is a closing parenthesis `')'`, the algorithm:
  - Retrieves the position `j` from the top of the stack (the last opening parenthesis).
  - Pops the position from the stack.
  - Reverses the substring of `res` starting from index `j` to the end of the result string. This operation effectively reverses the enclosed substring defined by the parentheses.

```cpp
            else res.push_back(s[i]);
        }
```
- **Lines 12-13**: If the current character is neither an opening nor a closing parenthesis, it is appended to the result string `res`.

```cpp
        return res;
    }
};
```
- **Lines 14-16**: After traversing the entire string, the final result string `res` is returned. This string now contains the modified version of the input with all specified substrings reversed.

### Complexity
1. **Time Complexity**: 
   - The overall time complexity of this algorithm is \(O(n)\), where \(n\) is the length of the string `s`. Each character is processed a limited number of times (specifically, each character is pushed or popped from the stack, and substrings are reversed).
  
2. **Space Complexity**: 
   - The space complexity is also \(O(n)\) in the worst case, due to the storage of the result string and the stack. The stack may grow in size proportional to the depth of nested parentheses, and the result string could potentially include all characters of the input.

### Conclusion
The `reverseParentheses` function efficiently handles the task of reversing substrings enclosed in parentheses using a straightforward stack-based approach. By systematically tracking the positions of opening parentheses, the function manages to reverse the required substrings without unnecessary complexity. This solution is both optimal and clear, allowing for easy understanding and maintenance. The use of standard library features, such as the stack and string manipulations, makes this solution a practical choice for similar problems involving nested structures and string transformations.

[`Link to LeetCode Lab`](https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/description/)

---
{{< youtube n_pCJmg-RyU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

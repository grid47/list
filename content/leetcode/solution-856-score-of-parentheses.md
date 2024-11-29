
+++
authors = ["grid47"]
title = "Leetcode 856: Score of Parentheses"
date = "2024-08-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 856: Score of Parentheses in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "iO0zA-N575k"
youtube_upload_date="2019-12-14"
youtube_thumbnail="https://i.ytimg.com/vi_webp/iO0zA-N575k/maxresdefault.webp"
comments = true
+++



---
Given a balanced parentheses string, calculate the score of the string. The score is computed as follows:

1. The score of '()' is 1.
2. For a concatenation of two balanced parentheses strings, AB, the score is the sum of their individual scores (A + B).
3. For a balanced parentheses string wrapped in another pair of parentheses, (A), the score is twice the score of A (2 * A).
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string s, which is a balanced parentheses string composed of only '(' and ')'. The length of the string is between 2 and 50 characters.
- **Example:** `Input: s = "(()())"`
- **Constraints:**
	- 2 <= s.length <= 50
	- s consists of only '(' and ')'.
	- s is guaranteed to be a balanced parentheses string.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the score of the given balanced parentheses string according to the rules defined above.
- **Example:** `Output: 6`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to compute the score of a balanced parentheses string by applying the given rules to the input string.

- Step 1: Initialize a stack to keep track of the scores for different parts of the string.
- Step 2: Iterate over the string. For every opening parenthesis, push the current score onto the stack and reset the score for the new section.
- Step 3: For each closing parenthesis, calculate the score based on the nested structure and update the score by applying the rule: max(2 * score, 1).
- Step 4: Return the final score.
{{< dots >}}
### Problem Assumptions ✅
- The input string is always valid and balanced.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: s = "(()())"`  \
  **Explanation:** In this example, the first pair '()' gives a score of 1. The second pair '()' gives another score of 1. The nested structure '(())' gives a score of 2. Therefore, the total score is 6 (1 + 1 + 2 + 2).

{{< dots >}}
## Approach 🚀
To solve this problem efficiently, we will use a stack to manage the nested structure of parentheses. We will calculate the score for each pair of parentheses and aggregate them based on the rules provided.

### Initial Thoughts 💭
- We can use a stack to handle the nested parentheses structure.
- The algorithm needs to calculate the score dynamically based on nested parentheses and concatenate the results.
{{< dots >}}
### Edge Cases 🌐
- N/A: The input is guaranteed to be a balanced parentheses string.
- For larger inputs, the algorithm should efficiently handle up to 50 characters without performance issues.
- If the string consists of the simplest case '()', the score is 1.
- The input string is guaranteed to be balanced.
{{< dots >}}
## Code 💻
```cpp
int scoreOfParentheses(string s) {
    int scr = 0;
    stack<int> stk;
    for(char &a : s) {
        if(a == '(') {
            stk.push(scr);
            scr = 0;
        }
        else {
            scr = stk.top() + max( 2 * scr, 1);
            stk.pop();
        }
    }
    return scr;
}
```

This function calculates the score of a string of parentheses, where each '(' and ')' contributes to the score based on nested levels.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int scoreOfParentheses(string s) {
	```
	The function `scoreOfParentheses` takes a string of parentheses as input and returns the calculated score.

2. **Variable Initialization**
	```cpp
	    int scr = 0;
	```
	A variable `scr` is initialized to 0 to keep track of the current score.

3. **Variable Declaration**
	```cpp
	    stack<int> stk;
	```
	A stack `stk` is declared to store intermediate score values during parentheses processing.

4. **For Loop**
	```cpp
	    for(char &a : s) {
	```
	A `for` loop is used to iterate through each character of the input string `s`.

5. **If Condition**
	```cpp
	        if(a == '(') {
	```
	This `if` condition checks if the current character is an opening parenthesis '('.

6. **Push Operation**
	```cpp
	            stk.push(scr);
	```
	The current score (`scr`) is pushed onto the stack when an opening parenthesis is encountered.

7. **Reset Score**
	```cpp
	            scr = 0;
	```
	The score `scr` is reset to 0 for the next level of parentheses.

8. **Else Condition**
	```cpp
	        else {
	```
	This `else` condition handles the case when a closing parenthesis ')' is encountered.

9. **Score Calculation**
	```cpp
	            scr = stk.top() + max( 2 * scr, 1);
	```
	The score is updated by taking the top value from the stack and adding the greater of `2 * scr` or 1, to account for nested parentheses.

10. **Pop Operation**
	```cpp
	            stk.pop();
	```
	The top element is popped from the stack after processing the closing parenthesis.

11. **Return Statement**
	```cpp
	    return scr;
	```
	The final score is returned after processing all parentheses.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the length of the input string.
- **Average Case:** O(n), as each character is processed once.
- **Worst Case:** O(n), where n is the length of the input string.



### Space Complexity 💾
- **Best Case:** O(n), where n is the length of the input string.
- **Worst Case:** O(n), where n is the length of the input string (due to the stack usage).



**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/score-of-parentheses/description/)

---
{{< youtube iO0zA-N575k >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

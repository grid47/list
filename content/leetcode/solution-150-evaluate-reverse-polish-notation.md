
+++
authors = ["grid47"]
title = "Leetcode 150: Evaluate Reverse Polish Notation"
date = "2024-10-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 150: Evaluate Reverse Polish Notation in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/150.webp"
youtube = "ffgmKxRqiMc"
youtube_upload_date="2024-02-26"
youtube_thumbnail="https://i.ytimg.com/vi/ffgmKxRqiMc/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/150.webp" 
    alt="A glowing stack of numbers, gently unfolding and calculating the final result step-by-step."
    caption="Solution to LeetCode 150: Evaluate Reverse Polish Notation Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given an array of strings tokens that represents an arithmetic expression in Reverse Polish Notation (RPN). Your task is to evaluate the expression and return the result as an integer.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array of strings, where each string is either an operand (integer) or an operator (+, -, *, /).
- **Example:** `tokens = ["3", "4", "-", "5", "*"]`
- **Constraints:**
	- 1 <= tokens.length <= 10^4
	- tokens[i] is either an operator (+, -, *, /) or an integer between [-200, 200].

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be an integer representing the result of evaluating the RPN expression.
- **Example:** `Result = -35`
- **Constraints:**
	- The answer can be represented as a 32-bit integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** Evaluate the Reverse Polish Notation expression by using a stack to process operands and operators.

- Initialize an empty stack.
- Iterate through the tokens array:
-   - If the token is an integer, push it onto the stack.
-   - If the token is an operator (+, -, *, /), pop the top two elements from the stack, apply the operator, and push the result back onto the stack.
- At the end of the iteration, the stack will contain only one element, which is the result of the expression.
{{< dots >}}
### Problem Assumptions ✅
- The expression will always be valid and contain no division by zero.
{{< dots >}}
## Examples 🧩
- **Input:** `tokens = ["3", "4", "-", "5", "*"]`  \
  **Explanation:** First, 3 - 4 = -1, then -1 * 5 = -35. So the result is -35.

- **Input:** `tokens = ["2", "3", "*", "4", "+"]`  \
  **Explanation:** First, 2 * 3 = 6, then 6 + 4 = 10. So the result is 10.

{{< dots >}}
## Approach 🚀
We can solve this problem using a stack to handle the Reverse Polish Notation (RPN) expression evaluation.

### Initial Thoughts 💭
- Using a stack is ideal for processing Reverse Polish Notation expressions, as operators act on the most recent operands.
- We need to iterate through the tokens, handling both operands and operators, and update the stack as we go.
{{< dots >}}
### Edge Cases 🌐
- There will always be at least one token in the input.
- The solution must handle large inputs efficiently, up to 10^4 tokens.
- Handle negative numbers and division truncation towards zero correctly.
- The solution should be efficient in terms of time and space complexity.
{{< dots >}}
## Code 💻
```cpp
int evalRPN(vector<string>& tokens) {
    stack<int> stk;
    int n = tokens.size();
    for(int i = 0; i < n; i++) {
        if(tokens[i] != "+" &&
           tokens[i] != "-" &&
           tokens[i] != "*" &&
           tokens[i] != "/") {
            stk.push(stoi(tokens[i]));
        } else {
            int x = stk.top(); stk.pop();
            int y = stk.top(); stk.pop();
            
                if(tokens[i] == "*"){ stk.push(y * x); }
                if(tokens[i] == "/"){ stk.push(y / x); }
                if(tokens[i] == "+"){ stk.push(y + x); }
                if(tokens[i] == "-"){ stk.push(y - x); }
            
        }
    }
    return stk.top();
}
```

This code implements the Reverse Polish Notation (RPN) evaluation algorithm. It processes the given tokens using a stack to perform mathematical operations as specified in the RPN expression. The algorithm supports the four basic arithmetic operations: addition, subtraction, multiplication, and division.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int evalRPN(vector<string>& tokens) {
	```
	Defines the function `evalRPN` that takes a vector of strings as input (tokens in Reverse Polish Notation) and returns the result of evaluating the expression.

2. **Variable Declaration**
	```cpp
	    stack<int> stk;
	```
	Declares a stack `stk` to store intermediate values while processing the RPN expression.

3. **Variable Initialization**
	```cpp
	    int n = tokens.size();
	```
	Initializes `n` to the size of the tokens vector, which represents the number of elements in the RPN expression.

4. **Loop Iteration**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Starts a loop to iterate through each token in the RPN expression.

5. **Conditional Check**
	```cpp
	        if(tokens[i] != "+" &&
	```
	Checks if the current token is not an operator (i.e., `+`, `-`, `*`, or `/`). If it is not an operator, the token is assumed to be a number.

6. **Conditional Check**
	```cpp
	           tokens[i] != "-" &&
	```
	Continues the check for other operators to ensure the current token is not one of the arithmetic operators.

7. **Conditional Check**
	```cpp
	           tokens[i] != "*" &&
	```
	Further checks if the current token is not the multiplication operator.

8. **Conditional Check**
	```cpp
	           tokens[i] != "/") {
	```
	Checks if the token is not the division operator.

9. **Stack Operation**
	```cpp
	            stk.push(stoi(tokens[i]));
	```
	If the token is a number (not an operator), it is converted to an integer using `stoi` and pushed onto the stack.

10. **Else Block**
	```cpp
	        } else {
	```
	If the token is an operator, the algorithm proceeds to perform the corresponding arithmetic operation.

11. **Stack Operation**
	```cpp
	            int x = stk.top(); stk.pop();
	```
	Pops the top value from the stack and assigns it to `x`. This represents the second operand for the operation.

12. **Stack Operation**
	```cpp
	            int y = stk.top(); stk.pop();
	```
	Pops the next value from the stack and assigns it to `y`. This represents the first operand for the operation.

13. **Arithmetic Operation**
	```cpp
	                if(tokens[i] == "*"){ stk.push(y * x); }
	```
	Performs multiplication if the current token is the `*` operator. The result is pushed onto the stack.

14. **Arithmetic Operation**
	```cpp
	                if(tokens[i] == "/"){ stk.push(y / x); }
	```
	Performs division if the current token is the `/` operator. The result is pushed onto the stack.

15. **Arithmetic Operation**
	```cpp
	                if(tokens[i] == "+"){ stk.push(y + x); }
	```
	Performs addition if the current token is the `+` operator. The result is pushed onto the stack.

16. **Arithmetic Operation**
	```cpp
	                if(tokens[i] == "-"){ stk.push(y - x); }
	```
	Performs subtraction if the current token is the `-` operator. The result is pushed onto the stack.

17. **Return Value**
	```cpp
	    return stk.top();
	```
	Returns the final result, which is the last remaining value on the stack after processing all the tokens.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

We process each token in the input once, so the time complexity is linear in the number of tokens.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n) in the worst case due to the stack used for processing the tokens.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/evaluate-reverse-polish-notation/description/)

---
{{< youtube ffgmKxRqiMc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

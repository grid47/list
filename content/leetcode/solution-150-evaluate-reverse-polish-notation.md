
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
**Code:**

{{< highlight cpp >}}
class Solution {
public:
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
};
{{< /highlight >}}
---

### 📝 **Problem Understanding: Reverse Polish Notation (RPN) Evaluation**

In **Reverse Polish Notation (RPN)**, every operator follows its operands, and there is no need for parentheses to dictate the order of operations. We are given an expression in RPN, and the task is to evaluate and return the result.

#### **Example**:
- Expression: `["2", "1", "+", "3", "*"]`
- Evaluation: `(2 + 1) * 3 = 9`

#### **Operators**: `+`, `-`, `*`, `/`  
#### **Operands**: Integers

---

### 🔧 **Approach: Using a Stack**

To solve the problem efficiently, we will use a **stack** data structure:
1. **Push numbers** onto the stack.
2. **When encountering an operator** (`+`, `-`, `*`, `/`), pop the top two operands from the stack, apply the operator, and push the result back onto the stack.
3. After processing all tokens, the final result will be the only element left in the stack.

This approach guarantees an efficient evaluation of the expression in **O(n)** time complexity, where `n` is the number of tokens.

---

### 🧑‍💻 **Code Breakdown: Step by Step**

#### **Step 1: Initialize the Stack and Iterate Over Tokens**

```cpp
stack<int> stk;
int n = tokens.size();
for (int i = 0; i < n; i++) {
    ...
}
```
- We initialize an empty stack `stk` to store the operands.
- We iterate through each token in the given `tokens` list.

#### **Step 2: Process Each Token**

```cpp
if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/") {
    stk.push(stoi(tokens[i]));
} else {
    ...
}
```
- If the token is a number (i.e., not an operator), we convert the string to an integer using `stoi(tokens[i])` and push it onto the stack.
- If the token is an operator, we perform the corresponding operation (explained below).

#### **Step 3: Handle Operators**

```cpp
int x = stk.top(); stk.pop();
int y = stk.top(); stk.pop();

if (tokens[i] == "*") { stk.push(y * x); }
if (tokens[i] == "/") { stk.push(y / x); }
if (tokens[i] == "+") { stk.push(y + x); }
if (tokens[i] == "-") { stk.push(y - x); }
```
When an operator is encountered:
- We pop the top two values from the stack. The first popped value `x` corresponds to the second operand, and `y` corresponds to the first operand.
- Depending on the operator:
  - **Multiplication (`*`)**: We calculate `y * x`.
  - **Division (`/`)**: We calculate integer division `y / x` (truncating toward zero).
  - **Addition (`+`)**: We calculate `y + x`.
  - **Subtraction (`-`)**: We calculate `y - x`.
- After each operation, the result is pushed back onto the stack.

#### **Step 4: Return the Final Result**

```cpp
return stk.top();
```
After processing all tokens, the stack will contain one element, which is the final result of the RPN expression. We return this element.

---

### 📊 **Time and Space Complexity**

#### **Time Complexity**:
- **O(n)** where `n` is the number of tokens.
  - We process each token exactly once, either by pushing it onto the stack (if it's a number) or performing an operation (if it's an operator). Each stack operation (push and pop) takes constant time, so the overall time complexity is linear in the number of tokens.

#### **Space Complexity**:
- **O(n)** where `n` is the number of tokens.
  - In the worst case, the stack could hold all the operands before any operators are processed, requiring space proportional to the number of tokens.

---

### 🎯 **Conclusion**

This solution efficiently evaluates an expression in Reverse Polish Notation (RPN) using a stack. By processing the tokens in a single pass, we achieve a time complexity of **O(n)** and a space complexity of **O(n)**. The stack-based approach accurately models the evaluation of postfix expressions, where operands are pushed onto the stack and operators are applied to the most recently encountered operands.

This method is both time and space-efficient, making it suitable for evaluating complex RPN expressions quickly.

### 🔍 **Edge Cases Considered**
- Correct handling of integer division (truncating towards zero).
- Efficient processing of large inputs.

This approach is optimal and robust, providing a clear solution to evaluating Reverse Polish Notation expressions.

[`Link to LeetCode Lab`](https://leetcode.com/problems/evaluate-reverse-polish-notation/description/)

---
{{< youtube ffgmKxRqiMc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

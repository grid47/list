
+++
authors = ["grid47"]
title = "Leetcode 640: Solve the Equation"
date = "2024-09-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 640: Solve the Equation in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","String","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/640.webp"
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/640.webp" 
    alt="An equation being solved step by step, with each step softly glowing as it leads to the solution."
    caption="Solution to LeetCode 640: Solve the Equation Problem"
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
    string solveEquation(string eqn) {
        int i = 0;
        int para = 0, xpara = 0;
        int flag = 1;
        while(i < eqn.size()) {
            int sgn = 1;
            int tmp = 0;
            if(eqn[i] == '=') {
                flag = -1;
                i++;
            } 
            if(eqn[i] == '-') {
                sgn = -1;
                i++;
            }
            if(eqn[i] == '+') {
                sgn = 1;
                i++;
            }
            if(isdigit(eqn[i])) {
                while(i < eqn.size() && isdigit(eqn[i])) {
                    tmp = tmp * 10 + eqn[i] - '0';
                    i++;
                }
                if(i < eqn.size() && eqn[i] == 'x') {
                    xpara += flag * sgn * tmp;
                    i++;
                }
                else para += flag * sgn * tmp;
            } else {
                xpara += flag * sgn;
                i++;
            }
        }

        string res;
        cout << para << '-'<< xpara;
        if(para == 0 && xpara == 0)
            res = "Infinite solutions";
        else if (xpara == 0)
            res = "No solution";
        else res = "x=" + to_string(para/xpara*-1);

        return res;
    }
};
{{< /highlight >}}
---

### Problem Statement

In this problem, we are asked to solve a linear equation of the form `ax + b = cx + d`, where `a`, `b`, `c`, and `d` are integers. The equation might contain one or more `x` terms, and the goal is to solve for `x`. The equation is given as a string, and we need to return the solution in the format `"x=solution"` or indicate that there are "Infinite solutions" or "No solution" based on the values of `a`, `b`, `c`, and `d`.

### Approach

The equation is of the form `ax + b = cx + d`, where the terms may contain variables and constants. Our task is to process the equation, extract the coefficients of `x` and constants, and then solve for `x`. The main steps of the approach are:

1. **Divide the equation**: We can treat the equation as two parts—one before the `=` sign and one after it. The first part represents terms involving `x` and constants on the left-hand side, while the second part represents the right-hand side.

2. **Identify terms**: Each side may have constants and terms involving `x`. The `x` terms will be grouped together on both sides of the equation, and the constants will be added separately.

3. **Simplify the equation**: After identifying the coefficients of `x` and constants on both sides, move all `x` terms to one side and constants to the other side. This results in a simplified equation of the form:
   
   ```
   (a - c) * x = (d - b)
   ```
   We can then solve for `x` using algebraic manipulations.

4. **Handle edge cases**: There are three potential scenarios:
   - If both the coefficients of `x` and constants on both sides are zero, the equation has "Infinite solutions".
   - If the coefficient of `x` is zero but the constant term is not, the equation has "No solution".
   - Otherwise, solve for `x` as `(d - b) / (a - c)`.

### Code Breakdown (Step by Step)

Let’s walk through the code step by step to understand how the solution is implemented.

#### 1. **Initial Setup and Variable Declarations**
```cpp
class Solution {
public:
    string solveEquation(string eqn) {
        int i = 0;
        int para = 0, xpara = 0;
        int flag = 1;
```
- We declare variables `i`, `para`, and `xpara`. `i` is used to iterate through the equation string, `para` stores the sum of constants, and `xpara` stores the sum of coefficients of `x`.
- The variable `flag` is set to `1` initially to indicate the sign of the terms we are currently processing.

#### 2. **Iterating Through the Equation String**
```cpp
        while(i < eqn.size()) {
            int sgn = 1;
            int tmp = 0;
```
- We use a while loop to process each character in the equation string `eqn`.
- `sgn` is used to track the sign of the term (`1` for positive and `-1` for negative).
- `tmp` is used to accumulate the value of numbers before encountering any operator or `x`.

#### 3. **Handling the `=` Symbol**
```cpp
            if(eqn[i] == '=') {
                flag = -1;
                i++;
            } 
```
- If the current character is `=`, it marks the separation between the left-hand side (LHS) and right-hand side (RHS) of the equation. 
- We update `flag` to `-1`, which indicates that we are now processing terms on the RHS.
- We increment `i` to move to the next character.

#### 4. **Processing the Sign of Each Term**
```cpp
            if(eqn[i] == '-') {
                sgn = -1;
                i++;
            }
            if(eqn[i] == '+') {
                sgn = 1;
                i++;
            }
```
- If the current character is `+` or `-`, we update `sgn` to reflect the sign of the current term.
- We increment `i` to process the next character.

#### 5. **Processing Numbers and Terms Involving `x`**
```cpp
            if(isdigit(eqn[i])) {
                while(i < eqn.size() && isdigit(eqn[i])) {
                    tmp = tmp * 10 + eqn[i] - '0';
                    i++;
                }
                if(i < eqn.size() && eqn[i] == 'x') {
                    xpara += flag * sgn * tmp;
                    i++;
                }
                else para += flag * sgn * tmp;
            } else {
                xpara += flag * sgn;
                i++;
            }
```
- If the current character is a digit, we accumulate the value of the number (`tmp`), which could be the coefficient of `x` or a constant.
- If the next character is `x`, we update the coefficient of `x` (`xpara`) accordingly.
- Otherwise, we add the constant term (`para`).
- If the current character is not a digit, it must be `x` with an implicit coefficient of `1`. We directly add the coefficient of `x` to `xpara`.

#### 6. **Solving the Equation**
```cpp
        string res;
        cout << para << '-'<< xpara;
        if(para == 0 && xpara == 0)
            res = "Infinite solutions";
        else if (xpara == 0)
            res = "No solution";
        else res = "x=" + to_string(para/xpara*-1);

        return res;
    }
};
```
- After processing all terms in the equation, we check the values of `para` and `xpara` to determine the type of solution.
  - If both `para` and `xpara` are zero, the equation has "Infinite solutions".
  - If `xpara` is zero but `para` is not, the equation has "No solution".
  - Otherwise, we solve for `x` using the equation `x = -para / xpara`.

### Complexity

#### Time Complexity:
- **O(n)** where `n` is the length of the equation string. The algorithm processes each character in the string once, performing constant-time operations for each character.

#### Space Complexity:
- **O(1)**. The space complexity is constant because we are using a fixed number of variables to store the coefficients and constants, and the space for the result is independent of the input size.

### Conclusion

This solution efficiently solves the equation by breaking it down into terms, processing each term to extract coefficients of `x` and constants, and then solving the simplified equation. It handles edge cases such as missing coefficients for `x` and implicitly considers the sign of each term. By processing the string in a single pass, the solution is both time and space efficient.

[`Link to LeetCode Lab`](https://leetcode.com/problems/solve-the-equation/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

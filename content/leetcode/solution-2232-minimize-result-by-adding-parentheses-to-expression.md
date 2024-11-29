
+++
authors = ["grid47"]
title = "Leetcode 2232: Minimize Result by Adding Parentheses to Expression"
date = "2024-03-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2232: Minimize Result by Adding Parentheses to Expression in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Enumeration"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "8Nt7G6bIkSI"
youtube_upload_date="2022-04-10"
youtube_thumbnail="https://i.ytimg.com/vi_webp/8Nt7G6bIkSI/maxresdefault.webp"
comments = true
+++



---
You are given a string expression in the form '<num1>+<num2>', where <num1> and <num2> represent positive integers. Your task is to add a pair of parentheses to the expression such that the resulting expression evaluates to the smallest possible value. The parentheses must be placed around the '+' operator. If there are multiple valid solutions yielding the same result, any of them can be returned.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string expression containing exactly one '+' symbol, with digits from '1' to '9'.
- **Example:** `expression = '345+56'`
- **Constraints:**
	- 3 <= expression.length <= 10
	- expression consists of digits from '1' to '9' and a single '+'
	- expression starts and ends with digits

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the expression after adding a pair of parentheses such that the result of the expression is minimized.
- **Example:** `Output: '3(45+56)'`
- **Constraints:**
	- The result fits within a signed 32-bit integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to minimize the expression by placing parentheses around the '+' operator. To achieve this, we need to consider the placement of parentheses that minimizes the product after the addition.

- 1. Find the position of the '+' symbol in the expression.
- 2. Try different placements of the parentheses around the '+' and calculate the resulting value.
- 3. Return the expression that yields the smallest result.
{{< dots >}}
### Problem Assumptions ✅
- The expression is always a valid mathematical string with exactly one '+' symbol.
- The length of the expression is guaranteed to be between 3 and 10 characters.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: expression = '345+56'`  \
  **Explanation:** In this case, we can place parentheses around '345' and '56', resulting in '3(45+56)', which evaluates to 3 * (45 + 56) = 3 * 101 = 303, which is the smallest possible value.

- **Input:** `Input: expression = '123+45'`  \
  **Explanation:** Here, placing parentheses around '12' and '45' results in '1(23+45)' which evaluates to 1 * (23 + 45) = 1 * 68 = 68, the smallest value.

- **Input:** `Input: expression = '100+200'`  \
  **Explanation:** For this case, the expression '100+200' becomes '(100+200)', which evaluates to 300, the only possible solution.

{{< dots >}}
## Approach 🚀
The approach is to explore various positions for the parentheses around the '+' symbol and calculate the resulting expressions. We then select the one that produces the smallest value.

### Initial Thoughts 💭
- The parentheses need to be placed around the '+' symbol to affect the addition operation.
- We can use brute force to check all possible valid parentheses placements and calculate the result to find the minimum.
{{< dots >}}
### Edge Cases 🌐
- There are no empty inputs as the problem guarantees valid expressions.
- Since the length of the input is limited to 10 characters, handling large inputs is not an issue.
- The '+' symbol may be at different positions in the expression, but this doesn't affect the approach.
- The expression always contains exactly one '+' symbol.
{{< dots >}}
## Code 💻
```cpp
string minimizeResult(string exp) {
    
    int pos = -1;
    int x = 0, y = 0, p = 0, q = 0;        
    for(int i = 0; i < exp.size(); i++) {
        if(exp[i] == '+') pos = i;
        if(pos == -1) {
            y = y * 10 + exp[i] - '0';
        } else if (exp[i] != '+'){
            q = q * 10 + exp[i] - '0';
        }
    }
    int tmp = q;
    // cout << y << " " << pos << " " << q << "\n";
    
    vector<int> res = {-1, -1}; int ans = INT_MAX;
    

    for(int i = 0; i < pos; i++) {
        
        x = x * 10 + (i > 0? exp[i - 1] - '0': 0);
        y = y % (int)pow(10, pos - i);
        
        for(int j = pos + 1; j < exp.size(); j++) {
            
            p = p * 10 + (exp[j] - '0');
            q= q % (int)pow(10, exp.size() - 1 - j);
            // cout << x << " " << y << " " << p << " " << q << " " << ans << "\n";                  
            if((x==0?1:x) * (y + p) * (q==0?1:q) < ans) {
                ans = (x==0?1:x) * (y + p) * (q==0?1:q);
                // cout << x << " " << y << " " << p << " " << q << " " << ans << "\n";                    
                res = {i, j};
            }
        }
        p = 0;
        q = tmp;
    }
    // cout << res[0] << " " << res[1];
    
    string ret = "";
    
    int i = 0;
    while(i < res[0]) ret += exp[i++];
    ret += '(';
    while(i <= res[1]) ret += exp[i++];
    ret += ')';
    while(i < exp.size()) ret += exp[i++];
    
    return ret;
}
```

This function minimizes the result of a given mathematical expression by strategically placing parentheses. It takes a string representing the expression, identifies the position of the '+' operator, and then computes the minimal result by exploring various ways of grouping terms.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	string minimizeResult(string exp) {
	```
	Defines the function 'minimizeResult', which takes a string representing a mathematical expression and returns the minimized result after placing parentheses optimally.

2. **Variable Initialization**
	```cpp
	    int pos = -1;
	```
	Initializes the variable 'pos' to -1, which will store the index of the '+' operator in the expression.

3. **Variable Initialization**
	```cpp
	    int x = 0, y = 0, p = 0, q = 0;
	```
	Initializes variables 'x', 'y', 'p', and 'q' to 0. These variables will be used to break down and calculate parts of the expression.

4. **Looping Through Expression**
	```cpp
	    for(int i = 0; i < exp.size(); i++) {
	```
	Starts a loop to iterate through each character of the expression string 'exp'.

5. **Condition Check**
	```cpp
	        if(exp[i] == '+') pos = i;
	```
	Checks if the current character is a '+' operator and stores its position in 'pos'.

6. **Condition Check**
	```cpp
	        if(pos == -1) {
	```
	Checks if the '+' operator hasn't been encountered yet.

7. **Mathematical Operations**
	```cpp
	            y = y * 10 + exp[i] - '0';
	```
	If no '+' operator is found, the character is added to the variable 'y' by converting it to an integer.

8. **Condition Check**
	```cpp
	        } else if (exp[i] != '+'){
	```
	If the character is not a '+', it is part of the second number after the '+' operator.

9. **Mathematical Operations**
	```cpp
	            q = q * 10 + exp[i] - '0';
	```
	Adds the current character to the variable 'q', representing the second number in the expression.

10. **Variable Assignment**
	```cpp
	    int tmp = q;
	```
	Stores the value of 'q' into 'tmp' to preserve its original value for later use.

11. **Variable Initialization**
	```cpp
	    vector<int> res = {-1, -1}; int ans = INT_MAX;
	```
	Initializes a vector 'res' to store the optimal indices for placing parentheses, and initializes 'ans' to a large value (INT_MAX) to track the minimum result.

12. **Looping Through Expression**
	```cpp
	    for(int i = 0; i < pos; i++) {
	```
	Starts a loop to iterate through the expression before the '+' operator.

13. **Mathematical Operations**
	```cpp
	        x = x * 10 + (i > 0? exp[i - 1] - '0': 0);
	```
	Calculates the first part of the first number in the expression by adding digits before the '+' operator.

14. **Mathematical Operations**
	```cpp
	        y = y % (int)pow(10, pos - i);
	```
	Calculates the remaining part of the second number after the '+' operator.

15. **Looping Through Expression**
	```cpp
	        for(int j = pos + 1; j < exp.size(); j++) {
	```
	Starts a nested loop to iterate through the expression after the '+' operator.

16. **Mathematical Operations**
	```cpp
	            p = p * 10 + (exp[j] - '0');
	```
	Adds the current character in the second part of the expression (after the '+') to the variable 'p'.

17. **Mathematical Operations**
	```cpp
	            q= q % (int)pow(10, exp.size() - 1 - j);
	```
	Calculates the remaining part of 'q' after the current digit is processed.

18. **Condition Check**
	```cpp
	            if((x==0?1:x) * (y + p) * (q==0?1:q) < ans) {
	```
	Checks if the current combination of 'x', 'y', 'p', and 'q' produces a smaller result.

19. **Variable Assignment**
	```cpp
	                ans = (x==0?1:x) * (y + p) * (q==0?1:q);
	```
	Updates the minimum result 'ans' if the current combination yields a smaller value.

20. **Variable Assignment**
	```cpp
	                res = {i, j};
	```
	Stores the indices of the optimal parentheses placement in 'res'.

21. **Returning Result**
	```cpp
	    string ret = "";
	```
	Initializes an empty string 'ret' to store the result.

22. **Building Result String**
	```cpp
	    int i = 0;
	```
	Initializes an index 'i' to start building the result string.

23. **Building Result String**
	```cpp
	    while(i < res[0]) ret += exp[i++];
	```
	Adds the part before the first parenthesis to 'ret'.

24. **Building Result String**
	```cpp
	    ret += '(';
	```
	Adds the opening parenthesis to 'ret'.

25. **Building Result String**
	```cpp
	    while(i <= res[1]) ret += exp[i++];
	```
	Adds the part inside the parentheses to 'ret'.

26. **Building Result String**
	```cpp
	    ret += ')';
	```
	Adds the closing parenthesis to 'ret'.

27. **Building Result String**
	```cpp
	    while(i < exp.size()) ret += exp[i++];
	```
	Adds the remaining part of the expression to 'ret'.

28. **Returning Result**
	```cpp
	    return ret;
	```
	Returns the final string with the parentheses placed optimally.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The algorithm performs linear passes over the expression to find the optimal placement of parentheses.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is linear due to storing intermediate results of expressions.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimize-result-by-adding-parentheses-to-expression/description/)

---
{{< youtube 8Nt7G6bIkSI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

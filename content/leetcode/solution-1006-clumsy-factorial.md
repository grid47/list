
+++
authors = ["grid47"]
title = "Leetcode 1006: Clumsy Factorial"
date = "2024-07-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1006: Clumsy Factorial in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Stack","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "DxcqMnUON_I"
youtube_upload_date="2019-07-23"
youtube_thumbnail="https://i.ytimg.com/vi_webp/DxcqMnUON_I/maxresdefault.webp"
comments = true
+++



---
Given a positive integer n, compute the 'clumsy factorial' of n. A clumsy factorial is computed using a series of operations (multiplication, division, addition, subtraction) in a fixed order applied to the integers from n down to 1. The operations follow this order: multiplication '*', division '/', addition '+', subtraction '-', and are repeated cyclically. Division is performed as floor division, and multiplication and division are processed left to right before addition and subtraction.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a single integer n (1 <= n <= 10^4).
- **Example:** `n = 6`
- **Constraints:**
	- 1 <= n <= 10^4

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the computed clumsy factorial as an integer.
- **Example:** `Output: 7`
- **Constraints:**
	- The output will be a single integer result of the clumsy factorial.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to compute the clumsy factorial of n by following the predefined rotation of operations and respecting the order of operations.

- Start with the first integer, n.
- Apply the operations (multiplication, division, addition, subtraction) in a cyclic order while considering left-to-right precedence for multiplication and division.
- Use floor division for all division operations.
- Keep track of the intermediate results in a stack to handle the addition and subtraction steps.
- Finally, compute the sum of the results and return the value.
{{< dots >}}
### Problem Assumptions ✅
- The input n is always a positive integer.
- The solution needs to follow the order of operations as described.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: n = 4`  \
  **Explanation:** The clumsy factorial of 4 is computed as follows: 4 * 3 / 2 + 1 = 7.

- **Input:** `Input: n = 6`  \
  **Explanation:** The clumsy factorial of 6 is computed as follows: 6 * 5 / 4 + 3 - 2 * 1 = 7.

{{< dots >}}
## Approach 🚀
To solve the problem, we will simulate the operations as described, using a stack to handle the addition and subtraction operations and performing multiplication and division left-to-right as needed.

### Initial Thoughts 💭
- The problem follows a fixed order of operations and can be approached step by step.
- Since multiplication and division take precedence, we will perform those first and use a stack for the addition and subtraction steps.
{{< dots >}}
### Edge Cases 🌐
- The input will always contain a valid integer n, so there are no empty inputs.
- The solution should efficiently handle the maximum constraint of n = 10,000.
- If n is 1, the clumsy factorial is simply 1.
- The solution must handle values of n efficiently up to the maximum constraint of 10,000.
{{< dots >}}
## Code 💻
```cpp
int clumsy(int n) {
    
    int ans = n;
    int j = n - 1;
    vector<int> stk;
    
    for(int i = 1; i < n; i++) {
        
             if(i % 4 == 1) ans *= j--;
        else if(i % 4 == 2) ans /= j--;
        else {
            
            stk.push_back(ans);
            
            if(i % 4 == 3) ans = j--;
                    else   ans = (-1 * j--);
            
        }
        
    }
    
    int sum = 0;
    for(int i = 0; i < stk.size(); i++)
        sum += stk[i];
    
    return sum + ans;
    
}
```

This function computes the clumsy factorial of a number `n`, following a custom set of multiplication, division, and subtraction steps. It uses a stack to store intermediate results and adjusts the result based on the step's modulo value.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int clumsy(int n) {
	```
	Defines the function `clumsy`, which takes an integer `n` and returns its clumsy factorial based on custom arithmetic operations.

2. **Initialization**
	```cpp
	    int ans = n;
	```
	Initializes `ans` to `n`, which will hold the result of the clumsy factorial calculation.

3. **Pointer Setup**
	```cpp
	    int j = n - 1;
	```
	Initializes `j` as `n - 1` to use as a pointer for the calculation of intermediate values.

4. **Stack Initialization**
	```cpp
	    vector<int> stk;
	```
	Creates a vector `stk` to temporarily store intermediate results for the clumsy factorial.

5. **Loop Start**
	```cpp
	    for(int i = 1; i < n; i++) {
	```
	Starts a loop from 1 to `n - 1` to apply the custom operations based on the current step.

6. **Multiplication Step**
	```cpp
	             if(i % 4 == 1) ans *= j--;
	```
	If `i % 4 == 1`, multiply `ans` by `j` and then decrement `j`.

7. **Division Step**
	```cpp
	        else if(i % 4 == 2) ans /= j--;
	```
	If `i % 4 == 2`, divide `ans` by `j` and then decrement `j`.

8. **Stack Push Operation**
	```cpp
	            stk.push_back(ans);
	```
	Pushes the current value of `ans` to the stack.

9. **Reset/Update Operation**
	```cpp
	            if(i % 4 == 3) ans = j--;
	```
	If `i % 4 == 3`, set `ans` to `j` and then decrement `j`.

10. **Reset/Negative Operation**
	```cpp
	                    else   ans = (-1 * j--);
	```
	For other values of `i % 4`, set `ans` to the negative value of `j` and then decrement `j`.

11. **Sum Initialization**
	```cpp
	    int sum = 0;
	```
	Initializes `sum` to accumulate the values from the stack.

12. **Summing Stack Values**
	```cpp
	    for(int i = 0; i < stk.size(); i++)
	```
	Starts a loop to sum the values in the stack.

13. **Accumulate Stack Values**
	```cpp
	        sum += stk[i];
	```
	Adds each element in the stack to the `sum`.

14. **Return Statement**
	```cpp
	    return sum + ans;
	```
	Returns the final result, which is the sum of the stack values plus the last calculated `ans`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) since we only need to iterate through the numbers and perform constant-time operations for each one.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n) due to the stack used to store intermediate results.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/clumsy-factorial/description/)

---
{{< youtube DxcqMnUON_I >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

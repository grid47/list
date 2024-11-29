
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
comments = true
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
Given an equation with a variable 'x' and basic arithmetic operations ('+', '-'), find the value of 'x'. The equation might have a solution, no solution, or infinite solutions. Your task is to return the correct result in the form of a string.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string representing an equation with the variable 'x', integers, and operations (+, -). The equation contains exactly one '=' symbol, and the equation consists of integer coefficients and variables.
- **Example:** `"x+5-3+x=6+x-2"`
- **Constraints:**
	- 3 <= equation.length <= 1000
	- equation has exactly one '='.
	- equation contains integers with absolute values between 0 and 100, and the variable 'x'.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is a string representing the result of the equation. If there is a solution, the format is 'x=#value'. If there is no solution, return 'No solution'. If the equation has infinite solutions, return 'Infinite solutions'.
- **Example:** `"x=2"`
- **Constraints:**
	- The output is always in the form 'x=#value', 'No solution', or 'Infinite solutions'.

{{< dots >}}
### Core Logic 🔍
**Goal:** To solve the equation for the value of 'x'. If there are multiple solutions or no solutions, return the appropriate message.

- Parse the equation into two parts (before and after the equal sign).
- Group terms with 'x' and constant terms separately.
- Solve for 'x' by isolating it on one side of the equation.
- Handle special cases such as infinite solutions or no solution.
{{< dots >}}
### Problem Assumptions ✅
- The equation will always contain at least one 'x'.
- There will always be exactly one '=' in the equation.
{{< dots >}}
## Examples 🧩
- **Input:** `"x+5-3+x=6+x-2"`  \
  **Explanation:** Simplifying the equation results in '2x+2=6+x-2'. After solving, we get 'x=2'.

- **Input:** `"x=x"`  \
  **Explanation:** This equation simplifies to '0=0', which is true for any value of x. Therefore, the solution is 'Infinite solutions'.

{{< dots >}}
## Approach 🚀
The equation needs to be parsed, and terms involving 'x' should be grouped separately. After simplifying, if there are no 'x' terms, check if the constants are equal, which indicates infinite solutions or no solution. If there are 'x' terms, solve for 'x'.

### Initial Thoughts 💭
- The equation might contain positive and negative terms involving 'x'.
- The variable 'x' can be isolated by grouping terms involving 'x' and constants separately.
- We will need to carefully handle terms on both sides of the equation and consider edge cases like 'x=x'.
{{< dots >}}
### Edge Cases 🌐
- Empty equations are not allowed.
- Equations with large strings can still be handled by parsing and evaluating the terms in a linear manner.
- Special cases like 'x=x' should be handled separately to detect infinite solutions.
- The equation will not contain leading zeros.
{{< dots >}}
## Code 💻
```cpp
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
```

This is a function that solves linear equations involving the variable 'x'. It processes the equation by iterating over its characters, handling signs and coefficients, and returns the result as a string indicating either infinite solutions, no solution, or the value of 'x'.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Helper Function**
	```cpp
	string solveEquation(string eqn) {
	```
	This is the main function which solves the equation represented as a string.

2. **Variable Initialization**
	```cpp
	    int i = 0;
	```
	Initializes the variable 'i' to track the index as we iterate over the equation.

3. **Variable Initialization**
	```cpp
	    int para = 0, xpara = 0;
	```
	Initializes 'para' and 'xpara' to store the constants and coefficients of 'x' respectively.

4. **Variable Initialization**
	```cpp
	    int flag = 1;
	```
	Initializes the 'flag' variable to keep track of the sign for each term.

5. **Loop**
	```cpp
	    while(i < eqn.size()) {
	```
	Begins a loop that will iterate over the entire equation string.

6. **Variable Initialization**
	```cpp
	        int sgn = 1;
	```
	Initializes the 'sgn' variable to 1, representing a positive sign for the current term.

7. **Variable Initialization**
	```cpp
	        int tmp = 0;
	```
	Initializes 'tmp' to accumulate the value of the current number in the equation.

8. **Conditional Check**
	```cpp
	        if(eqn[i] == '=') {
	```
	Checks if the current character is the equal sign, indicating the start of the second half of the equation.

9. **Update Variables**
	```cpp
	            flag = -1;
	```
	Changes the flag to -1, indicating that the terms after the equal sign will have a negative sign.

10. **Increment Index**
	```cpp
	            i++;
	```
	Increments the index to move past the '=' character.

11. **Conditional Check**
	```cpp
	        if(eqn[i] == '-') {
	```
	Checks if the current character is a minus sign, indicating a negative term.

12. **Update Variables**
	```cpp
	            sgn = -1;
	```
	Sets the 'sgn' variable to -1, indicating that the current term will be negative.

13. **Increment Index**
	```cpp
	            i++;
	```
	Increments the index to move past the minus sign.

14. **Conditional Check**
	```cpp
	        if(eqn[i] == '+') {
	```
	Checks if the current character is a plus sign, indicating a positive term.

15. **Update Variables**
	```cpp
	            sgn = 1;
	```
	Sets the 'sgn' variable to 1, indicating that the current term will be positive.

16. **Increment Index**
	```cpp
	            i++;
	```
	Increments the index to move past the plus sign.

17. **Conditional Check**
	```cpp
	        if(isdigit(eqn[i])) {
	```
	Checks if the current character is a digit, indicating the start of a number.

18. **Loop through Digits**
	```cpp
	            while(i < eqn.size() && isdigit(eqn[i])) {
	```
	Begins a loop to accumulate the digits of the current number.

19. **Accumulate Number**
	```cpp
	                tmp = tmp * 10 + eqn[i] - '0';
	```
	Accumulates the current digit into the 'tmp' variable.

20. **Increment Index**
	```cpp
	                i++;
	```
	Increments the index to move to the next character.

21. **Conditional Check**
	```cpp
	            if(i < eqn.size() && eqn[i] == 'x') {
	```
	Checks if the next character is 'x', indicating that the current number is a coefficient of 'x'.

22. **Update Coefficient**
	```cpp
	                xpara += flag * sgn * tmp;
	```
	Updates the coefficient of 'x' based on the current sign and flag.

23. **Increment Index**
	```cpp
	                i++;
	```
	Increments the index to move past the 'x'.

24. **Else Condition**
	```cpp
	            else para += flag * sgn * tmp;
	```
	If the number is not associated with 'x', it is added to the 'para' variable.

25. **Else Condition**
	```cpp
	        } else {
	```
	Handles the case where the character is neither a digit nor 'x'.

26. **Update Coefficient**
	```cpp
	            xpara += flag * sgn;
	```
	If the character is not a digit, it implies that 'x' has a coefficient of 1 (or -1).

27. **Increment Index**
	```cpp
	            i++;
	```
	Increments the index to move past the current character.

28. **Final Calculation**
	```cpp
	    string res;
	```
	Declares a string variable 'res' to store the result.

29. **Print Debug Information**
	```cpp
	    cout << para << '-'<< xpara;
	```
	Prints the values of 'para' and 'xpara' for debugging purposes.

30. **Conditional Check**
	```cpp
	    if(para == 0 && xpara == 0)
	```
	Checks if both 'para' and 'xpara' are zero, which indicates infinite solutions.

31. **Assign Result**
	```cpp
	        res = "Infinite solutions";
	```
	Assigns the string 'Infinite solutions' to 'res'.

32. **Conditional Check**
	```cpp
	    else if (xpara == 0)
	```
	Checks if 'xpara' is zero, which indicates no solution.

33. **Assign Result**
	```cpp
	        res = "No solution";
	```
	Assigns the string 'No solution' to 'res'.

34. **Assign Result**
	```cpp
	    else res = "x=" + to_string(para/xpara*-1);
	```
	If a solution exists, calculates and assigns the value of 'x' to 'res'.

35. **Return Result**
	```cpp
	    return res;
	```
	Returns the final result.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the length of the equation.
- **Average Case:** O(n), as we parse through the equation only once.
- **Worst Case:** O(n), where n is the length of the equation.

The time complexity is linear since we only need to parse the equation once.

### Space Complexity 💾
- **Best Case:** O(1), if the equation is small.
- **Worst Case:** O(1), as we do not need additional data structures to store intermediate results.

The space complexity is constant since we are only using a few variables to store intermediate results.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/solve-the-equation/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

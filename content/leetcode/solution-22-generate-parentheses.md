
+++
authors = ["grid47"]
title = "Leetcode 22: Generate Parentheses"
date = "2024-11-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 22: Generate Parentheses in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Dynamic Programming","Backtracking"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/22.webp"
youtube = "7aSAbqCWhwE"
youtube_upload_date="2024-03-11"
youtube_thumbnail="https://i.ytimg.com/vi/7aSAbqCWhwE/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/22.webp" 
    alt="A swirl of parentheses gently unfolding, forming balanced pairs that radiate a sense of calm."
    caption="Solution to LeetCode 22: Generate Parentheses Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given a number 'n', find all possible combinations of 'n' pairs of parentheses that are balanced and well-formed.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is an integer 'n', representing the number of pairs of parentheses.
- **Example:** `Input: n = 2`
- **Constraints:**
	- 1 <= n <= 8

{{< dots >}}
### Output Specifications 📤
- **Output:** Output a list of strings where each string is a unique combination of 'n' pairs of balanced parentheses.
- **Example:** `Output: ["(())", "()()"]`
- **Constraints:**
	- The output strings must be well-formed parentheses.

{{< dots >}}
### Core Logic 🔍
**Goal:** To generate all valid combinations of balanced parentheses for a given 'n'.

- Use a recursive function to explore all possibilities.
- Track the count of open and closed parentheses to maintain balance.
- Append a combination to the result when it reaches the required length.
{{< dots >}}
### Problem Assumptions ✅
- The input 'n' is always a positive integer within the given constraints.
- Output strings are sorted in the order they are generated.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: n = 3`  \
  **Explanation:** The output will be ["((()))", "(()())", "(())()", "()(())", "()()()"]. These are all the valid combinations for 3 pairs of parentheses.

- **Input:** `Input: n = 1`  \
  **Explanation:** The output will be ["()"]. There is only one valid combination for 1 pair of parentheses.

{{< dots >}}
## Approach 🚀
A recursive backtracking approach is used to generate all valid combinations of parentheses.

### Initial Thoughts 💭
- The problem involves generating all valid combinations, so recursion is suitable.
- The length of the string for a valid combination will always be 2 * n.
- Each step adds either an open or a closed parenthesis.
- The count of open parentheses should not exceed 'n'.
- The count of closed parentheses should not exceed the count of open ones.
{{< dots >}}
### Edge Cases 🌐
- n = 0 (though this is outside constraints).
- n = 8 (the maximum constraint).
- n = 1, where there is only one possible output.
- Ensure parentheses are well-formed even at maximum input size.
{{< dots >}}
## Code 💻
```cpp

void gen(string op, vector<string> &ans, int open, int closed, int n, int i) {
    if(i== 2*n) {
        ans.push_back(op);
        return;
    }
    
    if(open < n) {
        gen(op + "(", ans, open + 1, closed,n, i + 1);
    }
    if(open > closed) {
        gen(op + ")", ans, open, closed + 1,n, i + 1);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> ans;
    gen("", ans, 0, 0, n, 0);
    return ans;
}
```

This code generates all possible valid combinations of n pairs of parentheses using a backtracking approach.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	void gen(string op, vector<string> &ans, int open, int closed, int n, int i) {
	```
	This line declares a recursive helper function 'gen' to generate valid parentheses combinations.

2. **Base Case**
	```cpp
	    if(i== 2*n) {
	```
	This line checks if the current string 'op' has reached the desired length of 2*n. If so, it's a valid combination, so it's added to the 'ans' vector.

3. **Vector Operation**
	```cpp
	        ans.push_back(op);
	```
	Adds the current valid parenthesis combination 'op' to the 'ans' vector.

4. **Return**
	```cpp
	        return;
	```
	Returns from the recursive call.

5. **Conditional Check**
	```cpp
	    if(open < n) {
	```
	Checks if we can add an opening parenthesis. This is possible only if the number of open parentheses is less than 'n'.

6. **Recursive Call**
	```cpp
	        gen(op + "(", ans, open + 1, closed,n, i + 1);
	```
	Recursively calls the 'gen' function with an additional opening parenthesis added to the current string 'op'.

7. **Conditional Check**
	```cpp
	    if(open > closed) {
	```
	Checks if we can add a closing parenthesis. This is possible only if the number of open parentheses is greater than the number of closed parentheses.

8. **Recursive Call**
	```cpp
	        gen(op + ")", ans, open, closed + 1,n, i + 1);
	```
	Recursively calls the 'gen' function with an additional closing parenthesis added to the current string 'op'.

9. **Function End**
	```cpp
	}
	```
	End of the recursive 'gen' function.

10. **Function Declaration**
	```cpp
	vector<string> generateParenthesis(int n) {
	```
	This line declares the main function 'generateParenthesis' that takes the number of pairs 'n' as input and returns a vector of all valid parentheses combinations.

11. **Vector Initialization**
	```cpp
	    vector<string> ans;
	```
	Initializes an empty vector 'ans' to store the generated valid parentheses combinations.

12. **Function Call**
	```cpp
	    gen("", ans, 0, 0, n, 0);
	```
	Calls the recursive 'gen' function with an empty string, initial open and closed parentheses count as 0, and the target number of pairs 'n'.

13. **Return**
	```cpp
	    return ans;
	```
	Returns the 'ans' vector containing all valid parentheses combinations.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(4^n / sqrt(n))
- **Average Case:** O(4^n / sqrt(n))
- **Worst Case:** O(4^n / sqrt(n))

Catalan number Cn gives the count of valid combinations, and generating each combination takes O(n).

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The recursive stack depth is proportional to the length of the combination being generated.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/generate-parentheses/description/)

---
{{< youtube 7aSAbqCWhwE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

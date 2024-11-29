
+++
authors = ["grid47"]
title = "Leetcode 990: Satisfiability of Equality Equations"
date = "2024-07-31"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 990: Satisfiability of Equality Equations in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String","Union Find","Graph"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "d3MkgeCo8l4"
youtube_upload_date="2024-04-06"
youtube_thumbnail="https://i.ytimg.com/vi/d3MkgeCo8l4/maxresdefault.jpg"
comments = true
+++



---
You are given a list of equations where each equation represents a relationship between two variables in the form 'xi==yi' or 'xi!=yi'. Determine if it's possible to assign integer values to variables such that all equations are satisfied.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array of strings, where each string is an equation of the form 'xi==yi' or 'xi!=yi'.
- **Example:** `equations = ["a==b", "b!=a"]`
- **Constraints:**
	- 1 <= equations.length <= 500
	- equations[i].length == 4
	- equations[i][0] is a lowercase letter.
	- equations[i][1] is either '=' or '!'
	- equations[i][2] is '='
	- equations[i][3] is a lowercase letter.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a boolean value: 'true' if the equations can be satisfied by assigning values to the variables, 'false' otherwise.
- **Example:** `Output: true`
- **Constraints:**
	- The output is true if all equations can be satisfied with consistent assignments of values to variables.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to check if it's possible to assign integer values to variables such that all the equations are satisfied. This can be done by using a union-find data structure to group variables that are equal and check if any '!=' equations violate these groups.

- Initialize a union-find data structure to represent groups of variables that are equal.
- Process each equation: if it's an equality ('=='), union the two variables; if it's an inequality ('!='), check if the two variables are in the same group, which would indicate a contradiction.
{{< dots >}}
### Problem Assumptions ✅
- The input list will contain only valid equations in the form of 'xi==yi' or 'xi!=yi'.
- The variables are represented by lowercase letters ('a' to 'z').
{{< dots >}}
## Examples 🧩
- **Input:** `equations = ["a==b", "b!=a"]`  \
  **Explanation:** In this example, we are given the equations 'a==b' and 'b!=a'. If we assume a = 1 and b = 1, the first equation is satisfied, but the second equation is violated because a cannot be equal to b and not equal to b at the same time.

{{< dots >}}
## Approach 🚀
To solve this problem, we can use a union-find (disjoint-set) data structure to manage the groups of variables that must be equal. We process all equality equations first and then check each inequality equation to ensure no contradictions.

### Initial Thoughts 💭
- The problem requires us to check both equality and inequality relationships, which can be efficiently handled using the union-find data structure.
- The union-find approach will allow us to group variables and detect contradictions efficiently. If two variables that must be different are in the same group, it's impossible to satisfy the equations.
{{< dots >}}
### Edge Cases 🌐
- Handle cases where the input array is empty.
- Ensure that the solution efficiently handles the maximum number of equations (500).
- Check for edge cases with only one equation, such as 'a==a' or 'a!=a'.
- The solution must handle up to 500 equations efficiently.
{{< dots >}}
## Code 💻
```cpp
bool equationsPossible(vector<string>& eqn) {
    UF* uf = new UF(26);
    for(int i = 0; i < eqn.size(); i++) {
        int a = eqn[i][0] - 'a';
        int b = eqn[i][3] - 'a';
        if(eqn[i][1] == '=')
            uf->uni(a, b);
    }
    for(int i = 0; i < eqn.size(); i++) {
        int a = eqn[i][0] - 'a';
        int b = eqn[i][3] - 'a';
        if(eqn[i][1] == '!')
            if(uf->find(a) == uf->find(b))
                return false;
    }        
    return true;
}
```

This function checks whether a set of equations is possible, given the constraints. It uses a union-find data structure to process equality constraints and verify that inequality constraints are satisfied.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool equationsPossible(vector<string>& eqn) {
	```
	Defines the `equationsPossible` function that takes a vector of strings, `eqn`, where each string represents an equation (either equality or inequality) between two characters.

2. **Union-Find Initialization**
	```cpp
	    UF* uf = new UF(26);
	```
	Initializes a union-find (disjoint-set) data structure `uf` with 26 elements, one for each letter of the alphabet. The union-find structure will help manage connected components for equality relations.

3. **Equality Processing Loop**
	```cpp
	    for(int i = 0; i < eqn.size(); i++) {
	```
	Starts a loop to process each equation in the input `eqn` vector.

4. **Character Indexing**
	```cpp
	        int a = eqn[i][0] - 'a';
	```
	Converts the first character of the equation (left side) into an integer index between 0 and 25, representing the letter in the alphabet.

5. **Character Indexing**
	```cpp
	        int b = eqn[i][3] - 'a';
	```
	Converts the second character of the equation (right side) into an integer index between 0 and 25.

6. **Equality Check**
	```cpp
	        if(eqn[i][1] == '=')
	```
	Checks if the current equation is an equality (`=`).

7. **Union Operation**
	```cpp
	            uf->uni(a, b);
	```
	If the equation is an equality, it performs a union operation on the two characters (`a` and `b`), indicating that they belong to the same group.

8. **Inequality Processing Loop**
	```cpp
	    for(int i = 0; i < eqn.size(); i++) {
	```
	Starts another loop to process the inequality equations.

9. **Character Indexing**
	```cpp
	        int a = eqn[i][0] - 'a';
	```
	Converts the first character of the inequality equation into an integer index between 0 and 25.

10. **Character Indexing**
	```cpp
	        int b = eqn[i][3] - 'a';
	```
	Converts the second character of the inequality equation into an integer index between 0 and 25.

11. **Inequality Check**
	```cpp
	        if(eqn[i][1] == '!')
	```
	Checks if the current equation is an inequality (`!=`).

12. **Find Operation**
	```cpp
	            if(uf->find(a) == uf->find(b))
	```
	If the equation is an inequality, it checks if the two characters are connected in the union-find structure. If they are connected (i.e., they belong to the same group), the inequality is violated.

13. **Return False**
	```cpp
	                return false;
	```
	If the inequality is violated (the characters are in the same group), the function returns `false` indicating that the equations are not possible.

14. **Return True**
	```cpp
	    return true;
	```
	If all equations have been processed and no contradictions were found, the function returns `true`, indicating that the set of equations is possible.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the number of equations, if all equations are satisfied with no contradictions.
- **Average Case:** O(n), since each equation requires a constant time union/find operation.
- **Worst Case:** O(n), as each union/find operation is nearly constant time with path compression and union by rank.

The time complexity is O(n) due to the use of union-find, where n is the number of equations.

### Space Complexity 💾
- **Best Case:** O(26), regardless of input size, as the space required is constant.
- **Worst Case:** O(26), as we need to store the union-find structure for 26 variables.

The space complexity is O(26), which is constant, since we only need to store the union-find structure for the 26 variables.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/satisfiability-of-equality-equations/description/)

---
{{< youtube d3MkgeCo8l4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

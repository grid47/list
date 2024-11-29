
+++
authors = ["grid47"]
title = "Leetcode 2591: Distribute Money to Maximum Children"
date = "2024-02-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2591: Distribute Money to Maximum Children in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Greedy"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "rCLdAlt05XE"
youtube_upload_date="2023-03-18"
youtube_thumbnail="https://i.ytimg.com/vi_webp/rCLdAlt05XE/maxresdefault.webp"
comments = true
+++



---
You are given an integer `money` and an integer `children`. You need to distribute the money to the children such that everyone gets at least 1 dollar, nobody gets exactly 4 dollars, and you maximize the number of children receiving exactly 8 dollars. Return the maximum number of children who receive 8 dollars, or `-1` if it's not possible.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two integers: `money` (the total amount of money) and `children` (the number of children).
- **Example:** `For example, `money = 18, children = 3`.`
- **Constraints:**
	- 1 <= money <= 200
	- 2 <= children <= 30

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is an integer representing the maximum number of children who can receive exactly 8 dollars, or `-1` if it is not possible to distribute the money accordingly.
- **Example:** `For `money = 18, children = 3`, the output is `1`.`
- **Constraints:**
	- The result will always be a valid integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to distribute the money optimally such that the maximum number of children receive 8 dollars, considering the constraints of the problem.

- 1. Check if it is possible to distribute at least 1 dollar to each child.
- 2. Maximize the number of children who can receive 8 dollars by distributing the remaining money after giving each child 1 dollar.
- 3. Return the number of children who can receive exactly 8 dollars, or return `-1` if it is not possible.
{{< dots >}}
### Problem Assumptions ✅
- The input values are valid, and the money can be divided among children according to the given rules.
{{< dots >}}
## Examples 🧩
- **Input:** `For `money = 18, children = 3``  \
  **Explanation:** In this example, we give 8 dollars to the first child, 6 dollars to the second child, and the remaining 4 dollars to the third child. Only one child can receive exactly 8 dollars.

{{< dots >}}
## Approach 🚀
We start by giving each child at least 1 dollar. Then, we maximize the number of children receiving exactly 8 dollars by distributing the remaining money accordingly.

### Initial Thoughts 💭
- To maximize the number of children receiving 8 dollars, the total money must be sufficiently large to distribute to the children in such a way.
- We need to consider the remainder after distributing the money and check how many children can receive 8 dollars.
{{< dots >}}
### Edge Cases 🌐
- The problem guarantees valid input values and there will be no empty inputs.
- The solution must handle cases where `money` is large (up to 200) and `children` is small (up to 30).
- If `money` is exactly equal to `children`, then every child can receive exactly 1 dollar.
- The problem constraints ensure that the number of children and the amount of money will always fall within the specified ranges.
{{< dots >}}
## Code 💻
```cpp
int distMoney(int num, int kid) {
    if(num < kid) return -1;
    int avg = num / kid;
    if(avg > 8) return kid - 1;
    if(avg == 8) {
        if(num % kid == 0) return kid;
        return kid - 1;
    }
    if(avg > 4) {
        num -= kid;
        int sol = num / 7;
        if(num % 7 == 3 && sol == kid - 1) sol--;
        return sol;
    }
    
    if(avg == 4) {
        num -= kid;
        int sol = num / 7;
        if(num % 7 == 3 && sol == kid - 1) sol--;
        return sol;
    }
    
    if(avg < 4) {
        num -= kid;
        int sol = num / 7;
        if(num % 7 == 3 && sol == kid - 1) sol--;
        return sol;            
    }
    
    return -1;
}
```

This function calculates how money can be distributed between a given number of kids while ensuring some constraints are met. It takes two arguments: the total money available (`num`) and the number of kids (`kid`).

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Initialization**
	```cpp
	int distMoney(int num, int kid) {
	```
	Function definition for `distMoney`, taking `num` (total money) and `kid` (number of kids) as arguments.

2. **Conditional Check**
	```cpp
	    if(num < kid) return -1;
	```
	Checks if there is less money than kids, returns -1 if true.

3. **Average Calculation**
	```cpp
	    int avg = num / kid;
	```
	Calculates the average money each kid would get.

4. **Comparison**
	```cpp
	    if(avg > 8) return kid - 1;
	```
	Checks if the average is greater than 8; if true, returns the number of kids minus one.

5. **Nested Condition**
	```cpp
	    if(avg == 8) {
	```
	Checks if the average is exactly 8.

6. **Division Check**
	```cpp
	        if(num % kid == 0) return kid;
	```
	If the money is exactly divisible by the number of kids, all kids receive 8 units.

7. **Else Case**
	```cpp
	        return kid - 1;
	```
	If the money is not exactly divisible, return one less than the number of kids.

8. **Condition for Larger Averages**
	```cpp
	    if(avg > 4) {
	```
	Checks if the average is greater than 4.

9. **Adjustment**
	```cpp
	        num -= kid;
	```
	Reduces the total money by the number of kids, assuming each kid gets at least 1 unit.

10. **Solution Calculation**
	```cpp
	        int sol = num / 7;
	```
	Calculates the number of 7 units that can be distributed to the remaining money.

11. **Edge Case Handling**
	```cpp
	        if(num % 7 == 3 && sol == kid - 1) sol--;
	```
	Handles a special case when the remaining money modulo 7 equals 3 and the solution is one less than the total kids.

12. **Return Solution**
	```cpp
	        return sol;
	```
	Returns the final calculated solution.

13. **Check for avg == 4**
	```cpp
	    if(avg == 4) {
	```
	Checks if the average is exactly 4.

14. **Adjustment for avg == 4**
	```cpp
	        num -= kid;
	```
	Reduces the total money by the number of kids for the case when the average is 4.

15. **Solution Calculation for avg == 4**
	```cpp
	        int sol = num / 7;
	```
	Calculates the number of 7 units that can be distributed to the remaining money when the average is 4.

16. **Edge Case Handling for avg == 4**
	```cpp
	        if(num % 7 == 3 && sol == kid - 1) sol--;
	```
	Handles the special case when the remaining money modulo 7 equals 3 and the solution is one less than the total kids.

17. **Return Solution for avg == 4**
	```cpp
	        return sol;
	```
	Returns the calculated solution for when the average is 4.

18. **Check for avg < 4**
	```cpp
	    if(avg < 4) {
	```
	Checks if the average is less than 4.

19. **Adjustment for avg < 4**
	```cpp
	        num -= kid;
	```
	Reduces the total money by the number of kids for the case when the average is less than 4.

20. **Solution Calculation for avg < 4**
	```cpp
	        int sol = num / 7;
	```
	Calculates the number of 7 units that can be distributed to the remaining money when the average is less than 4.

21. **Edge Case Handling for avg < 4**
	```cpp
	        if(num % 7 == 3 && sol == kid - 1) sol--;
	```
	Handles the special case when the remaining money modulo 7 equals 3 and the solution is one less than the total kids.

22. **Return Solution for avg < 4**
	```cpp
	        return sol;            
	```
	Returns the calculated solution for when the average is less than 4.

23. **Final Return**
	```cpp
	    return -1;
	```
	Returns -1 if no valid distribution is found.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(1)
- **Worst Case:** O(1)

The solution works in constant time as it only involves basic arithmetic operations.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant as no additional space is used apart from the input and output.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/distribute-money-to-maximum-children/description/)

---
{{< youtube rCLdAlt05XE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

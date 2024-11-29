
+++
authors = ["grid47"]
title = "Leetcode 808: Soup Servings"
date = "2024-08-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 808: Soup Servings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Dynamic Programming","Probability and Statistics"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/808.webp"
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/808.webp" 
    alt="Bowls of soup where servings are poured, glowing softly as each serving is calculated."
    caption="Solution to LeetCode 808: Soup Servings Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You have two types of soup: A and B, with an initial volume of n ml of each. You can serve soup using four possible operations, each with a 25% chance of being chosen randomly. When serving, the amounts of soups A and B used are specified by each operation. If there is insufficient soup for a full operation, serve as much as possible. The process stops when one of the soups runs out. Return the probability that soup A will be exhausted first, plus half the probability that both soups will be exhausted at the same time.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a single integer n, which represents the initial amount (in ml) of both soup A and soup B.
- **Example:** `Input: n = 50`
- **Constraints:**
	- 0 <= n <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the probability that soup A becomes empty first, plus half the probability that both soups become empty simultaneously. The answer must be accurate to 10^-5.
- **Example:** `Output: 0.62500`
- **Constraints:**
	- The answer will be considered correct if the error is within 10^-5 of the actual answer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to calculate the probability of different outcomes where either soup A or both soups become empty based on random choices of operations.

- Represent the problem as a recursive dynamic programming problem, where each state tracks the remaining soup quantities of A and B.
- Use memoization to store the results of already computed states to avoid redundant calculations.
- Each recursive call simulates one of the four operations and computes the resulting probabilities, considering the constraints of the problem.
{{< dots >}}
### Problem Assumptions ✅
- We assume that the operation probabilities are equal (0.25 for each of the four operations).
- The process stops once either soup A or both soups are exhausted.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: n = 50`  \
  **Explanation:** With 50 ml of soup A and B, there are four possible operations to serve the soup. Depending on the operation chosen, either soup A or both soups may be emptied. The probability of each outcome is calculated by simulating the operations and tracking when one or both soups become empty.

{{< dots >}}
## Approach 🚀
The approach leverages dynamic programming with memoization to efficiently calculate the probability of each possible outcome based on the operations performed. This avoids recalculating the same state multiple times.

### Initial Thoughts 💭
- The problem requires recursive thinking due to the multiple choices of operations and the changes in the soup quantities.
- Memoization can help optimize the recursive approach by storing the results of already calculated states and reusing them.
{{< dots >}}
### Edge Cases 🌐
- If n = 0, both soups are already empty, so the result is 0.
- For very large values of n, the memoization approach ensures that we do not recompute the same states repeatedly.
- If n is very small (e.g., n = 1), the result depends on the available operations and how quickly one soup is exhausted.
- Ensure that the solution works efficiently for large values of n.
{{< dots >}}
## Code 💻
```cpp
class Solution {
    vector<vector<double>> mem;
public:
double soupServings(int n) {
    mem.resize(200, vector<double>(200, 0));
    return n > 4800? 1:f((n +24)/25, (n+24)/25);
}

double f(int a, int b) {
    if(a <= 0 && b <= 0) return 0.5;
    if(a <= 0) return 1;
    if(b <= 0) return 0;
    if(mem[a][b] > 0) return mem[a][b];
 mem[a][b] = 0.25 * (f(a-4, b) + f(a-3, b-1) + f(a - 2, b -2) + f(a-1, b-3));
    return mem[a][b];
}
```

This code defines a recursive function with memoization to solve the soup serving problem, where two soups are served in varying amounts, and the goal is to calculate the probability of one soup running out before the other.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Class Definition**
	```cpp
	class Solution {
	```
	This defines a class named 'Solution' where the problem-solving method will be implemented.

2. **Variable Declaration**
	```cpp
	    vector<vector<double>> mem;
	```
	Declares a 2D vector 'mem' to store the computed probabilities of soup servings.

3. **Access Modifier**
	```cpp
	public:
	```
	This is the access modifier, making the following methods accessible from outside the class.

4. **Method Declaration**
	```cpp
	double soupServings(int n) {
	```
	This method calculates the probability of serving the soups until one runs out, given an initial amount 'n'.

5. **Vector Initialization**
	```cpp
	    mem.resize(200, vector<double>(200, 0));
	```
	Resizes the 'mem' vector to store 200 rows and columns, initializing all values to 0.

6. **Conditional Return**
	```cpp
	    return n > 4800? 1:f((n +24)/25, (n+24)/25);
	```
	Checks if 'n' is greater than 4800, returning 1 if true, otherwise calling the function 'f' with adjusted parameters.

7. **Method Declaration**
	```cpp
	double f(int a, int b) {
	```
	This method is a helper recursive function that calculates the probability for each state of the soup servings.

8. **Base Case Check**
	```cpp
	    if(a <= 0 && b <= 0) return 0.5;
	```
	Checks if both soups are empty, returning a probability of 0.5 (equal chances of either soup running out first).

9. **Base Case Check**
	```cpp
	    if(a <= 0) return 1;
	```
	If soup 'a' is empty, return a probability of 1 (soup 'b' runs out first).

10. **Base Case Check**
	```cpp
	    if(b <= 0) return 0;
	```
	If soup 'b' is empty, return a probability of 0 (soup 'a' runs out first).

11. **Memoization Check**
	```cpp
	    if(mem[a][b] > 0) return mem[a][b];
	```
	If the probability for the current state has already been computed, return the stored value from 'mem'.

12. **Memoization Update**
	```cpp
	 mem[a][b] = 0.25 * (f(a-4, b) + f(a-3, b-1) + f(a - 2, b -2) + f(a-1, b-3));
	```
	Recursively computes the probability for the current state by considering all possible moves and updates the 'mem' vector with the result.

13. **Return Statement**
	```cpp
	    return mem[a][b];
	```
	Returns the computed probability stored in 'mem' for the current state (a, b).

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1) for small n values where the result can be computed directly.
- **Average Case:** O(n^2) due to the recursive nature of the solution with memoization for a grid of possible states.
- **Worst Case:** O(n^2), where n is the maximum possible value.

The time complexity depends on the number of unique states and the recursive depth of the function.

### Space Complexity 💾
- **Best Case:** O(1), for very small n values where minimal space is needed.
- **Worst Case:** O(n^2), since the memoization stores results for each pair of soup quantities.

The space complexity is determined by the memoization table, which stores results for each pair of remaining soup quantities.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/soup-servings/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |


+++
authors = ["grid47"]
title = "Leetcode 375: Guess Number Higher or Lower II"
date = "2024-09-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 375: Guess Number Higher or Lower II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Dynamic Programming","Game Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/375.webp"
youtube = "Gi-FQM3Ez84"
youtube_upload_date="2021-03-28"
youtube_thumbnail="https://i.ytimg.com/vi/Gi-FQM3Ez84/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/375.webp" 
    alt="Similar to the previous idea, but with multiple guesses and a progressively smaller range."
    caption="Solution to LeetCode 375: Guess Number Higher or Lower II Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
In this game, you must guess a number between 1 and n. Each wrong guess costs you the amount of the guessed number. Your goal is to minimize the total cost while guaranteeing a win. If you run out of money, you lose the game.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a single integer n, which represents the maximum number in the guessing range.
- **Example:** `Input: n = 8`
- **Constraints:**
	- 1 <= n <= 200

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum amount of money you need to guarantee a win, regardless of what number is picked.
- **Example:** `Output: 12`
- **Constraints:**
	- The solution should minimize the total cost of guesses while guaranteeing a win.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to determine the minimum cost by choosing optimal guesses and minimizing the maximum cost in the worst case.

- 1. Use dynamic programming to calculate the minimum cost for each possible range of numbers.
- 2. For each number, calculate the maximum cost of guessing that number and continue with the next number based on whether the actual number is higher or lower.
- 3. Memoize the results to avoid redundant calculations and improve efficiency.
{{< dots >}}
### Problem Assumptions ✅
- The number picked will always be between 1 and n.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: n = 8
Output: 12`  \
  **Explanation:** The optimal strategy involves guessing numbers in such a way that minimizes the worst-case cost, ensuring that you can win without spending too much.

- **Input:** `Input: n = 3
Output: 2`  \
  **Explanation:** With only three numbers, guessing 2 minimizes the maximum cost, which is 2.

{{< dots >}}
## Approach 🚀
We use dynamic programming to find the minimum cost for each range of numbers from 1 to n. The key is to calculate the cost for each possible number as a guess and then find the optimal strategy.

### Initial Thoughts 💭
- The game is a classic example of decision-making under uncertainty, where we aim to minimize the worst-case outcome.
- Using dynamic programming, we can break the problem into smaller subproblems, ensuring that we compute the optimal cost efficiently.
{{< dots >}}
### Edge Cases 🌐
- n is always between 1 and 200, so there are no cases with empty inputs.
- The algorithm needs to efficiently handle cases where n is large, up to 200.
- If n = 1, the result is 0 because no guessing is needed.
- The solution must work within the constraints of n <= 200.
{{< dots >}}
## Code 💻
```cpp
class Solution {
vector<vector<int>> table;
public:
int getMoneyAmount(int n) {
    table.resize(n + 1, vector<int>(n + 1));
    return dpf(table, 1, n);
}

int dpf(vector<vector<int>> &dp, int s, int e) {
    if(s >= e) return 0;
    if(dp[s][e] > 0) return dp[s][e];
    int res = INT_MAX;
    for(int x = s; x <= e; x++) {
        int tmp = (x + max(dpf(dp, s, x-1), dpf(dp, x + 1, e)));
        res = min(res, tmp);
    }
    return dp[s][e] = res;
}
```

This code defines a solution to the problem of finding the minimum amount of money needed to guarantee a win in a guessing game. It uses dynamic programming to recursively calculate the minimum cost of guessing each number between `s` and `e`.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Class Definition**
	```cpp
	class Solution {
	```
	This line begins the definition of the `Solution` class, which will contain the methods needed to solve the problem.

2. **Variable Declaration**
	```cpp
	vector<vector<int>> table;
	```
	This declares a 2D vector `table` which will be used to store the intermediate results of the dynamic programming computation.

3. **Access Specifier**
	```cpp
	public:
	```
	The `public` access specifier marks the methods and variables that follow as accessible from outside the class.

4. **Function Declaration**
	```cpp
	int getMoneyAmount(int n) {
	```
	This is the function declaration for `getMoneyAmount`, which computes the minimum money required to guarantee a win in a guessing game, taking `n` (the maximum number) as input.

5. **Dynamic Programming Table Initialization**
	```cpp
	    table.resize(n + 1, vector<int>(n + 1));
	```
	The dynamic programming table `table` is resized to store values for all ranges of numbers from 1 to `n`, with each element initialized to 0.

6. **Function Call**
	```cpp
	    return dpf(table, 1, n);
	```
	The function `dpf` is called with the parameters `table`, `1`, and `n` to compute the minimum cost of the game for the range `[1, n]`.

7. **Function Declaration**
	```cpp
	int dpf(vector<vector<int>> &dp, int s, int e) {
	```
	This is the declaration of the `dpf` function, which takes the dynamic programming table and the range `[s, e]` to compute the minimum money needed to guess within that range.

8. **Base Case**
	```cpp
	    if(s >= e) return 0;
	```
	The base case: if the start value `s` is greater than or equal to the end value `e`, no more guesses are needed, so the cost is 0.

9. **Memoization Check**
	```cpp
	    if(dp[s][e] > 0) return dp[s][e];
	```
	If the result for the range `[s, e]` has already been computed and stored in `dp`, it is returned to avoid redundant calculations (memoization).

10. **Variable Initialization**
	```cpp
	    int res = INT_MAX;
	```
	A variable `res` is initialized to the maximum integer value, representing the minimum cost to guess for the range `[s, e]`.

11. **Loop Iteration**
	```cpp
	    for(int x = s; x <= e; x++) {
	```
	This loop iterates over each possible guess `x` within the range `[s, e]`.

12. **Recursive Function Call**
	```cpp
	        int tmp = (x + max(dpf(dp, s, x-1), dpf(dp, x + 1, e)));
	```
	For each guess `x`, the function `dpf` is recursively called to compute the maximum cost for the left and right subranges (`[s, x-1]` and `[x+1, e]`). The result is the sum of `x` and the maximum of the two subranges.

13. **Result Update**
	```cpp
	        res = min(res, tmp);
	```
	The variable `res` is updated to store the minimum result across all possible guesses `x`.

14. **Memoization Update**
	```cpp
	    return dp[s][e] = res;
	```
	The computed minimum result for the range `[s, e]` is stored in the dynamic programming table `dp` for future use.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^3)

In the worst case, we perform calculations for each pair of numbers and then evaluate each guess within the range, leading to a cubic time complexity.

### Space Complexity 💾
- **Best Case:** O(n^2)
- **Worst Case:** O(n^2)

We use a 2D table to store the results for each pair of numbers, resulting in a space complexity of O(n^2).

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/guess-number-higher-or-lower-ii/description/)

---
{{< youtube Gi-FQM3Ez84 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

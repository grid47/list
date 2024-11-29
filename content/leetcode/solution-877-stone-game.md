
+++
authors = ["grid47"]
title = "Leetcode 877: Stone Game"
date = "2024-08-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 877: Stone Game in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Dynamic Programming","Game Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "jGmq8d4cIx0"
youtube_upload_date="2023-09-21"
youtube_thumbnail="https://i.ytimg.com/vi/jGmq8d4cIx0/maxresdefault.jpg"
comments = true
+++



---
Alice and Bob are playing a game with an array of piles of stones. Each pile contains a positive number of stones, and the game proceeds as follows: Alice and Bob take turns, with Alice starting first. On each turn, a player can choose the entire pile of stones either from the beginning or the end of the array. The player who ends up with the most stones wins. Given the piles array, return true if Alice wins the game, or false if Bob wins, assuming both players play optimally.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an array of integers representing piles of stones. The length of the array is even, and the sum of the stones in all piles is odd.
- **Example:** `Input: piles = [4, 6, 2, 8]`
- **Constraints:**
	- 2 <= piles.length <= 500
	- piles.length is even.
	- 1 <= piles[i] <= 500
	- sum(piles[i]) is odd.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return true if Alice wins, meaning she accumulates more stones than Bob. Otherwise, return false.
- **Example:** `Output: true`
- **Constraints:**
	- The output is a boolean indicating if Alice wins the game.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to determine if Alice, starting first, can win the game by optimally picking stones from the piles.

- Use dynamic programming to simulate both players' optimal moves.
- Memoize the results to avoid recalculating the same state.
- For each state, choose the pile from either the start or the end, and subtract the value of the opponent's optimal play.
{{< dots >}}
### Problem Assumptions ✅
- Both Alice and Bob play optimally, meaning they always make the best possible move.
- The game is played to completion with no interruptions.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: piles = [4, 6, 2, 8]`  \
  **Explanation:** In this example, Alice can start by taking the last pile (8), leaving Bob with the choice of taking 4 or 2. No matter what Bob does, Alice will win by selecting optimally.

- **Input:** `Input: piles = [3, 7, 2, 3]`  \
  **Explanation:** Alice can start by taking the first pile (3), and based on Bob's choices, Alice will be able to win by making optimal selections.

{{< dots >}}
## Approach 🚀
We use dynamic programming to solve this problem by simulating both Alice's and Bob's moves, taking into account all possible choices they can make. The solution involves recursion and memoization to optimize the state evaluations.

### Initial Thoughts 💭
- The optimal strategy for both players is to always choose the pile that maximizes their advantage, either from the start or the end.
- Using memoization will help avoid redundant calculations and improve efficiency, especially given the problem constraints.
{{< dots >}}
### Edge Cases 🌐
- An empty input should not occur as the problem guarantees an even number of piles.
- The solution should efficiently handle the upper limit of 500 piles.
- If the piles contain large numbers or small numbers, the solution should still be optimal, considering the memoization approach.
- Ensure that the solution works within the provided constraints, including the odd sum condition.
{{< dots >}}
## Code 💻
```cpp
vector<int> p;
int n;

map<int, map<int,int>> memo;

bool dp(int i, int j) {
    if(i == j) return p[i];
    
    if(memo.count(i) && memo[i].count(j)) return memo[i][j];
    
    return memo[i][j] = max(p[i] - dp(i + 1, j), p[j] - dp(i, j - 1)) ;
    
}

bool stoneGame(vector<int>& piles) {
    this->p = piles;
    n = piles.size();
    return dp(0, n - 1) >= 0;
}
```

This code implements a dynamic programming solution to the Stone Game problem. The goal is to determine if the first player can win by optimally picking stones from a pile, where each player can pick either the first or last stone in each turn. The `dp` function computes the maximum score difference between the two players from any subarray of piles, and `stoneGame` returns whether the first player can win.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	vector<int> p;
	```
	This initializes a vector `p` to store the piles of stones.

2. **Variable Initialization**
	```cpp
	int n;
	```
	This initializes an integer `n` to store the number of piles.

3. **Memoization Map**
	```cpp
	map<int, map<int,int>> memo;
	```
	This initializes a memoization map `memo` to store previously computed results for subproblems in the dynamic programming solution.

4. **Function Definition**
	```cpp
	bool dp(int i, int j) {
	```
	This defines the recursive `dp` function that computes the maximum score difference from the subarray of piles between indices `i` and `j`.

5. **Base Case**
	```cpp
	    if(i == j) return p[i];
	```
	This is the base case of the recursion. If there is only one pile left (i.e., `i == j`), return the value of that pile.

6. **Memoization Check**
	```cpp
	    if(memo.count(i) && memo[i].count(j)) return memo[i][j];
	```
	This checks if the result for the subarray between indices `i` and `j` has already been computed. If so, return the memoized result.

7. **Recursive Calculation**
	```cpp
	    return memo[i][j] = max(p[i] - dp(i + 1, j), p[j] - dp(i, j - 1));
	```
	This calculates the result for the current subarray by recursively calling `dp` for the two possible choices: taking the first pile or taking the last pile, and storing the result in `memo[i][j]`.

8. **Main Function**
	```cpp
	bool stoneGame(vector<int>& piles) {
	```
	This defines the main function `stoneGame` which initializes the vector `p` with the piles and calculates the number of piles `n`. It then calls the `dp` function to determine if the first player can win.

9. **Variable Assignment**
	```cpp
	    this->p = piles;
	```
	This assigns the input vector `piles` to the class member `p`.

10. **Variable Assignment**
	```cpp
	    n = piles.size();
	```
	This assigns the size of the input vector `piles` to the integer `n`.

11. **Return Statement**
	```cpp
	    return dp(0, n - 1) >= 0;
	```
	This calls the `dp` function with the full range of the array (from 0 to `n - 1`) and returns whether the first player can win (i.e., the score difference is greater than or equal to 0).

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2)

The time complexity is O(n^2) due to the memoized recursive calls for each subproblem, where n is the number of piles.

### Space Complexity 💾
- **Best Case:** O(n^2)
- **Worst Case:** O(n^2)

The space complexity is O(n^2) due to the memoization table used to store the results of subproblems.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/stone-game/description/)

---
{{< youtube jGmq8d4cIx0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |


+++
authors = ["grid47"]
title = "Leetcode 1140: Stone Game II"
date = "2024-07-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1140: Stone Game II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Dynamic Programming","Prefix Sum","Game Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "I-z-u0zfQtg"
youtube_upload_date="2023-05-26"
youtube_thumbnail="https://i.ytimg.com/vi/I-z-u0zfQtg/maxresdefault.jpg"
comments = true
+++



---
Alice and Bob are playing a game with piles of stones. Each pile contains a positive integer number of stones. On each player's turn, they can take stones from the first X remaining piles, where 1 <= X <= 2M. The goal is to maximize the number of stones Alice can collect assuming both play optimally.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a list `piles`, where each element `piles[i]` represents the number of stones in the ith pile.
- **Example:** `Input: piles = [3, 5, 8, 7, 6]`
- **Constraints:**
	- 1 <= piles.length <= 100
	- 1 <= piles[i] <= 10^4

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum number of stones Alice can collect if both players play optimally.
- **Example:** `Output: 14`
- **Constraints:**
	- The result will be an integer representing the maximum number of stones Alice can collect.

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the optimal strategy for Alice to collect the maximum number of stones, while simulating the game with Bob's optimal strategy.

- 1. Calculate the cumulative sum of the piles in reverse order (postfix sum).
- 2. Use dynamic programming (DP) to store the optimal results for different states (index and M).
- 3. Recursively calculate the maximum number of stones Alice can collect given the current state and optimal plays of both players.
{{< dots >}}
### Problem Assumptions ✅
- The players take turns and Alice always plays first.
- Both players play optimally, i.e., they maximize their score while minimizing the opponent's score.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: piles = [3, 5, 8, 7, 6]`  \
  **Explanation:** In this example, Alice starts by taking 1 pile. Then Bob takes 2 piles, Alice takes 2 more piles, and Bob takes the remaining piles. Alice's total is 3 + 7 + 6 = 14.

- **Input:** `Input: piles = [1, 2, 3, 4, 6, 80]`  \
  **Explanation:** In this example, Alice can maximize her score by taking the first pile, Bob takes 2 piles, Alice then takes 2 piles, and Bob takes the remaining stones. Alice collects 1 + 4 + 6 + 80 = 84.

{{< dots >}}
## Approach 🚀
The problem can be solved using dynamic programming to simulate the optimal play of both Alice and Bob.

### Initial Thoughts 💭
- Dynamic programming is needed to handle the optimal play decisions and recursive choices for both players.
- I need to consider the remaining stones after each move and calculate the possible outcomes for Alice based on Bob's optimal response.
{{< dots >}}
### Edge Cases 🌐
- An empty input will not occur as per the problem constraints.
- The algorithm should efficiently handle cases where the length of the piles is large (up to 100).
- The case where all piles have the same number of stones or where one player can take all the stones at the beginning should be considered.
- Ensure the algorithm handles the upper constraint where the number of stones in each pile can be as large as 10,000.
{{< dots >}}
## Code 💻
```cpp
/*

Taking postfix sum to count pile is new concept - residual count

Thinking like, I had taken this much and pick what you
require out of remaining, from how much ever you picked
the rest is mine

each call is others turn

*/
vector<int> piles;
vector<vector<int>> memo;
int n;
int dp(int idx, int m) {
    if(idx + 2* m >= piles.size()) return piles[idx];
    if(memo[idx][m] != -1) return memo[idx][m];
    int ans = 0;
    int tmp = 0;
    for(int x = 1; x <= 2 * m; x++) {
        int tmp = piles[idx] - piles[idx + x];
        ans = max(ans, tmp + piles[idx + x] - dp(idx + x, max(m, x)) );
    }
    return memo[idx][m] = ans;
}
int stoneGameII(vector<int>& p) {
    n = p.size();
    piles = p;
    memo.resize(n, vector<int>(n, -1));
    for(int i = p.size() - 2; i >= 0; i--)
        piles[i] += piles[i + 1];
    return dp(0, 1);
}
```

This is the solution for the Stone Game II problem. It uses dynamic programming with memoization to calculate the optimal strategy for the player. The `dp` function calculates the maximum stones that can be taken from any given index, and the final result is computed from the first index.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Declaration**
	```cpp
	vector<int> piles;
	```
	This line declares a vector `piles` to store the number of stones in each pile.

2. **Variable Declaration**
	```cpp
	vector<vector<int>> memo;
	```
	This line declares a 2D vector `memo` to store the results of subproblems, which will be used for memoization to avoid redundant calculations.

3. **Variable Declaration**
	```cpp
	int n;
	```
	This line declares an integer variable `n` to store the number of piles.

4. **Function Definition**
	```cpp
	int dp(int idx, int m) {
	```
	This defines the recursive function `dp`, which calculates the maximum stones that can be taken starting from index `idx` with a maximum number of piles `m` to be taken.

5. **Base Case**
	```cpp
	    if(idx + 2* m >= piles.size()) return piles[idx];
	```
	This is the base case where if the current index `idx` plus `2 * m` exceeds or equals the total number of piles, it returns the remaining stones in the current pile.

6. **Memoization Check**
	```cpp
	    if(memo[idx][m] != -1) return memo[idx][m];
	```
	This checks if the result for the current subproblem has already been computed and stored in `memo`. If so, it returns the cached result.

7. **Initialization**
	```cpp
	    int ans = 0;
	```
	This line initializes the variable `ans` to store the result for the current subproblem.

8. **Initialization**
	```cpp
	    int tmp = 0;
	```
	This line initializes the variable `tmp` to store intermediate results during the calculations.

9. **Loop for Possible Choices**
	```cpp
	    for(int x = 1; x <= 2 * m; x++) {
	```
	This loop iterates over all possible choices of stones that can be picked, from 1 to `2 * m` stones.

10. **Calculate Stones Left**
	```cpp
	        int tmp = piles[idx] - piles[idx + x];
	```
	This line calculates the stones left after picking `x` stones from the current pile.

11. **Recursion for Next Step**
	```cpp
	        ans = max(ans, tmp + piles[idx + x] - dp(idx + x, max(m, x)) );
	```
	This line recursively calculates the maximum stones that can be taken by the current player, updating the result `ans` accordingly.

12. **Memoization Store**
	```cpp
	    return memo[idx][m] = ans;
	```
	This stores the result of the current subproblem in `memo` to avoid redundant calculations in future calls.

13. **Main Function**
	```cpp
	int stoneGameII(vector<int>& p) {
	```
	This defines the main function `stoneGameII`, which initializes the problem and calls the `dp` function.

14. **Initialization in Main**
	```cpp
	    n = p.size();
	```
	This initializes the variable `n` with the size of the input vector `p`, representing the number of piles.

15. **Initialization in Main**
	```cpp
	    piles = p;
	```
	This assigns the input vector `p` to the `piles` vector, which will be used for calculation.

16. **Memoization Initialization**
	```cpp
	    memo.resize(n, vector<int>(n, -1));
	```
	This resizes the `memo` vector to store the results for all subproblems, initializing all values to -1, indicating that they haven't been computed yet.

17. **Prefix Sum Calculation**
	```cpp
	    for(int i = p.size() - 2; i >= 0; i--)
	```
	This loop calculates the prefix sum of the piles in reverse order, storing the cumulative sum in the `piles` vector.

18. **Prefix Sum Calculation**
	```cpp
	        piles[i] += piles[i + 1];
	```
	This adds the stones in the next pile to the current pile to build the prefix sum.

19. **Return Final Result**
	```cpp
	    return dp(0, 1);
	```
	This calls the `dp` function starting from index 0 with a maximum pile count of 1, and returns the result.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2)

The time complexity is O(n^2) because we are using dynamic programming with two nested loops to calculate the optimal solution.

### Space Complexity 💾
- **Best Case:** O(n^2)
- **Worst Case:** O(n^2)

The space complexity is O(n^2) due to the memoization table that stores results for each state (index and max piles Alice can take).

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/stone-game-ii/description/)

---
{{< youtube I-z-u0zfQtg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

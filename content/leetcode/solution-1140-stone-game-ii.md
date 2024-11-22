
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
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
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
};
{{< /highlight >}}
---


### Problem Statement
The Stone Game II is a two-player game where players take turns to pick stones from a pile. The goal is to maximize the number of stones collected. The game starts with a pile of stones, represented as an array, and the players can choose to take a certain number of stones based on a given set of rules.

**Rules:**
1. Players take turns to pick stones.
2. On each turn, a player can take between `1` and `2 * m` stones, where `m` is the maximum number of stones the previous player took.
3. The game ends when there are no stones left to take.

The task is to determine the maximum number of stones that the first player can collect if both players play optimally.

### Approach
The solution employs a dynamic programming approach to analyze the game. It maintains a memoization table to store the results of subproblems, reducing redundant calculations. The key steps of the approach are:

1. **Postfix Sum Calculation**: Compute the cumulative sum of stones from the end of the list to the beginning. This allows efficient calculation of the stones remaining after certain moves.

2. **Dynamic Programming Recursive Function**: The recursive function `dp(idx, m)` is defined to determine the maximum number of stones the first player can collect starting from the index `idx` and with a maximum of `m` stones that can be taken in the next move.

3. **Memoization**: Store the results of previously computed states in a 2D array `memo` to avoid recalculating them.

4. **Optimal Moves Calculation**: For each possible number of stones taken (ranging from `1` to `2 * m`), compute the resultant score and update the maximum possible score.

### Code Breakdown (Step by Step)
Here’s a detailed breakdown of the code:

```cpp
class Solution {
public:
```
- **Line 1-2**: A class named `Solution` is defined, marking the start of the implementation.

```cpp
    vector<int> piles;
    vector<vector<int>> memo;
    int n;
```
- **Line 3-5**: Three member variables are declared:
  - `piles`: A vector to store the initial pile of stones.
  - `memo`: A 2D vector to store previously computed results for the recursive function.
  - `n`: An integer to store the size of the pile.

```cpp
    int dp(int idx, int m) {
```
- **Line 6**: The `dp` function is defined, taking the current index `idx` and the maximum stones `m` as parameters. This function will compute the maximum stones collectible from the current state.

```cpp
        if(idx + 2 * m >= piles.size()) return piles[idx];
```
- **Line 7**: This condition checks if the index plus twice the maximum stones exceeds the size of the pile. If true, it means all remaining stones can be taken, so the function returns the total stones from the current index onward.

```cpp
        if(memo[idx][m] != -1) return memo[idx][m];
```
- **Line 8**: This line checks if the current state has already been computed. If it has (i.e., `memo[idx][m]` is not -1), it returns the stored result.

```cpp
        int ans = 0;
        int tmp = 0;
```
- **Line 9-10**: Initializes variables:
  - `ans`: This will store the maximum stones collectible from the current state.
  - `tmp`: A temporary variable used to store intermediate calculations.

```cpp
        for(int x = 1; x <= 2 * m; x++) {
```
- **Line 11**: A for loop iterates over the possible number of stones `x` that can be taken, which ranges from `1` to `2 * m`.

```cpp
            int tmp = piles[idx] - piles[idx + x];
```
- **Line 12**: This calculates the stones left after taking `x` stones. It uses the cumulative sum to determine how many stones remain in the pile.

```cpp
            ans = max(ans, tmp + piles[idx + x] - dp(idx + x, max(m, x)) );
```
- **Line 13**: The maximum score is updated by comparing the current `ans` with the potential score if `x` stones are taken. It adds the stones left after the current move and subtracts the result of the subsequent player’s optimal move from the new index.

```cpp
        return memo[idx][m] = ans;
```
- **Line 14**: The computed result for the current state is stored in the `memo` table before returning it.

```cpp
    int stoneGameII(vector<int>& p) {
```
- **Line 15**: The main function `stoneGameII` is defined, which takes a vector `p` as input representing the initial pile of stones.

```cpp
        n = p.size();
        piles = p;
```
- **Line 16-17**: The size of the pile is stored in `n`, and the input vector `p` is assigned to the member variable `piles`.

```cpp
        memo.resize(n, vector<int>(n, -1));
```
- **Line 18**: The `memo` table is resized to `n x n` and initialized with `-1` to indicate that no states have been computed yet.

```cpp
        for(int i = p.size() - 2; i >= 0; i--)
            piles[i] += piles[i + 1];
```
- **Line 19-21**: A loop computes the postfix sum, updating `piles[i]` to include the stones from `piles[i + 1]`. This prepares the `piles` vector for efficient score calculations.

```cpp
        return dp(0, 1);
    }
};
```
- **Line 22-23**: The function initiates the recursive DP process starting from index `0` with a maximum of `1` stone that can be taken. The computed maximum stones collectible is returned, and the class definition is closed.

### Complexity
- **Time Complexity**: The time complexity of the algorithm is \( O(n^2) \), where \( n \) is the number of stones in the input vector. This arises from the double recursive nature of the `dp` function, where each state is computed based on possible moves.
- **Space Complexity**: The space complexity is \( O(n) \) due to the memoization table and the `piles` vector. Both require space proportional to the size of the input.

### Conclusion
The provided C++ solution effectively solves the Stone Game II problem using dynamic programming and memoization techniques. By leveraging the concept of cumulative sums, the algorithm efficiently computes the maximum number of stones that the first player can collect, even when faced with optimal plays from the second player. This approach ensures clarity and efficiency, making it suitable for competitive programming and algorithmic challenges.


[`Link to LeetCode Lab`](https://leetcode.com/problems/stone-game-ii/description/)

---
{{< youtube I-z-u0zfQtg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |


+++
authors = ["grid47"]
title = "Leetcode 1690: Stone Game VII"
date = "2024-05-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1690: Stone Game VII in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Dynamic Programming","Game Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "cOGliK5brbQ"
youtube_upload_date="2020-12-16"
youtube_thumbnail="https://i.ytimg.com/vi/cOGliK5brbQ/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int memo[1001][1001] = {};
    int dp(vector<int>& s, int i, int j, int sum) {
        
        if(i == j) {
            return 0;
        }
        
        
        return memo[i][j] ? memo[i][j] : memo[i][j] = max(sum - s[i] - dp(s, i + 1, j, sum - s[i]),
                                            sum - s[j] - dp(s, i, j - 1, sum - s[j]));
    }
    
    int stoneGameVII(vector<int>& s) {
        int n = s.size();
        return dp(s, 0,n-1, accumulate(begin(s), end(s), 0));
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem at hand is from a game theory context where two players, Alice and Bob, play a game with stones arranged in a line. Each player can remove either the leftmost or the rightmost stone in their turn, and their goal is to maximize their total score. The score is calculated based on the values of the stones removed. The objective is to determine the maximum score difference that Alice can achieve over Bob by strategically removing stones.

### Approach

To solve this problem, we can use a dynamic programming approach, specifically memoization to optimize our recursive solution. The key ideas behind our approach are:

1. **Recursive Function**: We define a recursive function `dp(i, j)` that calculates the maximum score difference between Alice and Bob if Alice is playing optimally with the remaining stones from index `i` to index `j`.

2. **Base Case**: When there is only one stone left (i.e., `i == j`), the player cannot make a move, resulting in a score difference of `0`.

3. **State Transition**: For each state defined by the indices `i` and `j`, we calculate the maximum score difference by considering the two options available to Alice:
   - If Alice removes the leftmost stone (s[i]), then Bob will have the remaining stones from `i + 1` to `j`.
   - If Alice removes the rightmost stone (s[j]), then Bob will have the remaining stones from `i` to `j - 1`.

   We calculate the scores accordingly, keeping in mind the total sum of the stones left after each move.

4. **Memoization**: We store the results of subproblems in a 2D array `memo` to avoid redundant calculations.

5. **Final Calculation**: The final score difference is obtained by calling the `dp` function with the initial indices and the total sum of stones.

### Code Breakdown (Step by Step)

Here is the complete breakdown of the code:

```cpp
class Solution {
public:
    int memo[1001][1001] = {};
```
- **Class Definition**: We define a class `Solution` containing a member array `memo` for memoization.

```cpp
    int dp(vector<int>& s, int i, int j, int sum) {
```
- **Recursive Function**: We define the `dp` function that takes a vector of stones `s`, the current indices `i` and `j`, and the `sum` of the values of remaining stones.

```cpp
        if(i == j) {
            return 0;
        }
```
- **Base Case**: If there is only one stone left (when `i` equals `j`), the function returns `0`, as no score can be obtained.

```cpp
        return memo[i][j] ? memo[i][j] : memo[i][j] = max(sum - s[i] - dp(s, i + 1, j, sum - s[i]),
                                            sum - s[j] - dp(s, i, j - 1, sum - s[j]));
```
- **Memoization Check**: We check if the result for this state `memo[i][j]` has already been computed. If it has, we return that value.
- **Score Calculation**:
  - If Alice removes the leftmost stone (`s[i]`), Bob will play optimally with the remaining stones, so we subtract `s[i]` from the total `sum` and call `dp` with the new indices `(i + 1, j)`.
  - If Alice removes the rightmost stone (`s[j]`), we similarly update the sum and call `dp` with `(i, j - 1)`.
- **Maximum Calculation**: We take the maximum of the two scenarios to ensure Alice is playing optimally.

```cpp
    int stoneGameVII(vector<int>& s) {
        int n = s.size();
        return dp(s, 0,n-1, accumulate(begin(s), end(s), 0));
    }
};
```
- **Main Function**: The `stoneGameVII` function initializes the game by calculating the total sum of the stones and calling the `dp` function with the full range of indices (from `0` to `n-1`).

### Complexity

- **Time Complexity**: The time complexity is \(O(n^2)\) due to the nested recursive calls for each state defined by indices `i` and `j`. Each subproblem is computed once thanks to memoization.

- **Space Complexity**: The space complexity is \(O(n^2)\) for the memoization table, in addition to the space used for the input vector.

### Conclusion

The solution effectively utilizes dynamic programming with memoization to solve the stone game problem, allowing Alice to maximize her score against Bob. 

Key insights from the solution include:

1. **Optimal Play Strategy**: The recursive structure captures the optimal choices made by Alice at each step, ensuring that she minimizes Bob's potential score while maximizing her own.

2. **Efficiency Through Memoization**: By storing the results of previously computed states, we significantly reduce the computational overhead, allowing the solution to handle larger input sizes effectively.

3. **Understanding Game Theory**: The problem illustrates fundamental concepts in game theory, including optimal strategies, decision making, and the impact of choices on future outcomes.

In summary, this code serves as a robust example of applying recursive strategies and dynamic programming to solve competitive scenarios, providing valuable insights into optimizing player strategies in game-theoretic contexts.

[`Link to LeetCode Lab`](https://leetcode.com/problems/stone-game-vii/description/)

---
{{< youtube cOGliK5brbQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

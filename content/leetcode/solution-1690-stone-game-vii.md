
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
comments = true
+++



---
Alice and Bob are playing a game with a row of `n` stones. On each player's turn, they can remove the leftmost or the rightmost stone, and their score is the sum of the remaining stones. Alice tries to maximize the score difference, while Bob aims to minimize it. Calculate the score difference between Alice and Bob when both play optimally.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array `stones`, where each element represents the value of a stone.
- **Example:** `Input: stones = [4, 2, 7, 5, 3]`
- **Constraints:**
	- 2 <= n <= 1000
	- 1 <= stones[i] <= 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be an integer, representing the difference in scores between Alice and Bob.
- **Example:** `Output: 8`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to calculate the difference in scores between Alice and Bob when both play optimally.

- Start by calculating the total sum of the stones.
- Use dynamic programming to simulate the optimal plays of both players.
- At each step, choose either the leftmost or rightmost stone to remove and update the score accordingly.
- Track the difference in scores until all stones are removed.
{{< dots >}}
### Problem Assumptions ✅
- Both players always play optimally.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: stones = [4, 2, 7, 5, 3]`  \
  **Explanation:** The game proceeds through multiple turns, with Alice and Bob alternately removing stones. The final score difference is the result of their optimal decisions.

{{< dots >}}
## Approach 🚀
To solve this problem, we will use dynamic programming to simulate the game, where we compute the optimal score difference for each possible subarray of stones.

### Initial Thoughts 💭
- The players make decisions based on the remaining stones in the row.
- We can use a memoization table to store intermediate results and avoid redundant calculations.
{{< dots >}}
### Edge Cases 🌐
- The input will always have at least two stones, so empty inputs are not possible.
- Ensure the algorithm can handle the maximum input size of `n = 1000`.
- When there are only two stones, the game will involve removing both stones in turn.
- The input will always be a valid array of integers as per the given constraints.
{{< dots >}}
## Code 💻
```cpp
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
```

This code defines a dynamic programming solution to the problem of maximizing the score in the Stone Game VII. It uses memoization to optimize overlapping subproblems and calculates the maximum score by making optimal choices to remove either the left or right stone at each step.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Memoization Table Initialization**
	```cpp
	int memo[1001][1001] = {};
	```
	Initialize a memoization table `memo` to store the results of subproblems. This avoids recalculating the same subproblems multiple times and speeds up the solution using dynamic programming.

2. **DP Function Definition**
	```cpp
	int dp(vector<int>& s, int i, int j, int sum) {
	```
	Define the recursive dynamic programming function `dp` that computes the maximum score between the indices `i` and `j` of the array `s`, with the remaining total `sum` of the stones.

3. **Base Case Check**
	```cpp
	    if(i == j) {
	```
	Check if there is only one stone left (i.e., `i == j`). In this case, no more matches can be made, and the score is 0.

4. **Base Case Return**
	```cpp
	        return 0;
	```
	Return 0 as there are no more stones to remove, so no points can be gained.

5. **Memoization Check**
	```cpp
	    return memo[i][j] ? memo[i][j] : memo[i][j] = max(sum - s[i] - dp(s, i + 1, j, sum - s[i]),
	```
	Check if the result for the current subproblem (`i`, `j`) is already computed and stored in `memo`. If not, calculate it by choosing the optimal move: remove the stone at index `i` or `j`.

6. **Recursive Call (Left Stone Removed)**
	```cpp
	                                        sum - s[i] - dp(s, i + 1, j, sum - s[i]),
	```
	Make a recursive call to calculate the score if the leftmost stone (`s[i]`) is removed. The remaining sum of stones is updated accordingly.

7. **Recursive Call (Right Stone Removed)**
	```cpp
	                                        sum - s[j] - dp(s, i, j - 1, sum - s[j]));
	```
	Make a recursive call to calculate the score if the rightmost stone (`s[j]`) is removed. The remaining sum of stones is updated accordingly.

8. **Main Function Definition**
	```cpp
	int stoneGameVII(vector<int>& s) {
	```
	Define the main function `stoneGameVII` that initializes the memoization table and calls the recursive `dp` function to calculate the maximum score.

9. **Size Calculation**
	```cpp
	    int n = s.size();
	```
	Calculate the size `n` of the input array `s`, which represents the number of stones.

10. **Final Calculation and Return**
	```cpp
	    return dp(s, 0, n - 1, accumulate(begin(s), end(s), 0));
	```
	Call the `dp` function with the initial indices `0` and `n - 1` and the total sum of all stones (calculated using `accumulate`). Return the result of the dynamic programming computation.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2)

The time complexity is O(n^2) because we compute the score difference for each subarray using dynamic programming.

### Space Complexity 💾
- **Best Case:** O(n^2)
- **Worst Case:** O(n^2)

The space complexity is O(n^2) due to the memoization table used to store the score differences for subarrays.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/stone-game-vii/description/)

---
{{< youtube cOGliK5brbQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

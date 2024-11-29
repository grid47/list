
+++
authors = ["grid47"]
title = "Leetcode 486: Predict the Winner"
date = "2024-09-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 486: Predict the Winner in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Dynamic Programming","Recursion","Game Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/486.webp"
youtube = "KjlXtj7IwyY"
youtube_upload_date="2022-10-03"
youtube_thumbnail="https://i.ytimg.com/vi/KjlXtj7IwyY/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/486.webp" 
    alt="A glowing sequence where the winner is predicted based on optimal strategies, with each move softly glowing."
    caption="Solution to LeetCode 486: Predict the Winner Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given an integer array nums. Two players, Player 1 and Player 2, take turns to pick numbers from either end of the array. Each player adds the selected number to their score. The goal is to determine if Player 1 can win the game. Player 1 wins if they have a higher score or if the scores are tied.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array `nums`, representing the available numbers that the players can select from.
- **Example:** `nums = [3, 9, 1, 2]`
- **Constraints:**
	- 1 <= nums.length <= 20
	- 0 <= nums[i] <= 10^7

{{< dots >}}
### Output Specifications 📤
- **Output:** Return `true` if Player 1 can win the game, or `false` otherwise.
- **Example:** `Output: true`
- **Constraints:**
	- The result will be a boolean value indicating whether Player 1 can win the game.

{{< dots >}}
### Core Logic 🔍
**Goal:** Implement a strategy to simulate the game and check if Player 1 can win using dynamic programming or recursive techniques.

- 1. Use dynamic programming to calculate the best score each player can achieve based on optimal choices.
- 2. Start with Player 1 making the first move.
- 3. Evaluate both possible moves from either end of the array.
- 4. Use memoization to avoid recalculating the same game states.
{{< dots >}}
### Problem Assumptions ✅
- The array will always have at least one element.
- Both players are playing optimally, making the best choice at each step.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [3, 9, 1, 2]`  \
  **Explanation:** Player 1 picks 3 first, leaving Player 2 with 9 and 1. Player 1 picks 9 next, leaving Player 2 to pick 1. Player 1 ends up with a score of 12, while Player 2 has a score of 3. Therefore, Player 1 wins.

- **Input:** `nums = [5, 3, 4, 5]`  \
  **Explanation:** Player 1 picks 5 first. Player 2 can pick either 5 or 4, but Player 1 will always be able to pick the higher number. In the end, Player 1 wins.

{{< dots >}}
## Approach 🚀
The approach involves simulating the game and using dynamic programming or recursion to calculate the best score each player can achieve based on the current state of the array.

### Initial Thoughts 💭
- Both players can make optimal decisions by looking ahead at the possible outcomes.
- Memoization is essential to avoid recalculating the same game states.
- The problem can be solved using a top-down dynamic programming approach with memoization to optimize the score calculation.
{{< dots >}}
### Edge Cases 🌐
- The input will always contain at least one element, so there is no need to handle empty arrays.
- For larger input sizes, ensure that the solution is optimized with memoization to handle the recursive calls efficiently.
- When the array has only one element, Player 1 will always win by selecting that element.
- Ensure that the algorithm can handle input arrays up to the maximum length of 20 elements.
{{< dots >}}
## Code 💻
```cpp

vector<int> nums;
vector<vector<map<int, int>>> memo;

int dp(int l, int r, int net) {
    
    if(l == r) return nums[l];
    
    if(memo[l][r].count(net)) return memo[l][r][net];
    
    int ans = net - dp(l + 1, r, net - nums[l]);
    ans = max(ans, net - dp(l, r - 1, net - nums[r]));
    
    return memo[l][r][net] = ans;
}

bool predictTheWinner(vector<int>& nums) {

    this->nums = nums;
    int n = nums.size();
    memo.resize(n + 1, vector<map<int,int>>(n + 1));
    
    int net = accumulate(nums.begin(), nums.end(), 0);
    
    int ret = dp(0, n - 1, net);

    return ret >= net - ret;
}
```

This solution uses dynamic programming to determine if a player can win the game by choosing numbers from the ends of a list. The `dp` function calculates the score difference between the two players, and the `predictTheWinner` function evaluates if the player starting first can win.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Declaration**
	```cpp
	vector<int> nums;
	```
	Declares a vector `nums` to store the game values that will be used to compute the scores.

2. **Memoization Structure**
	```cpp
	vector<vector<map<int, int>>> memo;
	```
	Declares a 3D vector of maps `memo` for memoization, storing the results of subproblems to avoid redundant calculations in the dynamic programming solution.

3. **Function Definition**
	```cpp
	int dp(int l, int r, int net) {
	```
	Defines the `dp` function that calculates the maximum score difference for a given range of the game array.

4. **Base Case**
	```cpp
	    if(l == r) return nums[l];
	```
	Base case: when only one element is left, return its value as it represents the score the current player will get.

5. **Memoization Check**
	```cpp
	    if(memo[l][r].count(net)) return memo[l][r][net];
	```
	Checks if the result for the current subproblem has already been computed. If yes, it returns the stored result to avoid redundant calculations.

6. **Recursion**
	```cpp
	    int ans = net - dp(l + 1, r, net - nums[l]);
	```
	Recursively calculates the score difference by choosing the leftmost element and subtracting it from the net score.

7. **Recursion**
	```cpp
	    ans = max(ans, net - dp(l, r - 1, net - nums[r]));
	```
	Compares the result of choosing the leftmost element with the result of choosing the rightmost element. The maximum of these two choices is stored as the final answer.

8. **Memoization**
	```cpp
	    return memo[l][r][net] = ans;
	```
	Stores the computed result in the `memo` structure to avoid redundant calculations in future calls.

9. **Function Definition**
	```cpp
	bool predictTheWinner(vector<int>& nums) {
	```
	Defines the `predictTheWinner` function which determines if the first player can win given the array `nums`.

10. **Input Assignment**
	```cpp
	    this->nums = nums;
	```
	Assigns the input vector `nums` to the class-level `nums` variable for use in the dynamic programming solution.

11. **Size Calculation**
	```cpp
	    int n = nums.size();
	```
	Calculates the size of the input vector `nums` and stores it in the variable `n`.

12. **Memoization Initialization**
	```cpp
	    memo.resize(n + 1, vector<map<int,int>>(n + 1));
	```
	Initializes the memoization structure to handle all subproblems of size up to `n`.

13. **Net Score Calculation**
	```cpp
	    int net = accumulate(nums.begin(), nums.end(), 0);
	```
	Calculates the total score (`net`) by summing all elements in `nums`.

14. **Recursive Call**
	```cpp
	    int ret = dp(0, n - 1, net);
	```
	Calls the `dp` function to calculate the score difference between the two players starting from the first and last elements of the array.

15. **Return Statement**
	```cpp
	    return ret >= net - ret;
	```
	Returns `true` if the first player can win or tie, otherwise returns `false`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2)

The time complexity is O(n^2) because the algorithm involves recursively calculating the best score for each subarray, and memoization ensures that each state is calculated only once.

### Space Complexity 💾
- **Best Case:** O(n^2)
- **Worst Case:** O(n^2)

The space complexity is O(n^2) due to the memoization table storing results for every possible subarray.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/predict-the-winner/description/)

---
{{< youtube KjlXtj7IwyY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

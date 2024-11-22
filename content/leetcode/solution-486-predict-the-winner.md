
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
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
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
};
{{< /highlight >}}
---

### Problem Statement

The problem is to determine if the first player can guarantee a win in a two-player game with an optimal strategy. Given an array of integers `nums`, where each element represents a score value of a card, two players take turns to pick either the leftmost or rightmost card from the array. The player with the highest total score at the end wins. The goal is to determine if the first player can guarantee victory, assuming both players play optimally.

### Approach

The solution leverages dynamic programming with memoization to make this decision efficiently. Here’s a breakdown of the approach:

1. **Dynamic Programming (DP) Strategy**:
   - The key to solving this problem is to understand that each player will pick cards with the intention of maximizing their score while minimizing the opponent’s potential score.
   - We define a recursive `dp` function that calculates the maximum score a player can obtain from a subarray defined by the indices `l` (left) and `r` (right) of `nums`.
   - The function also tracks the `net` score, which represents the sum of the elements in the current subarray.
   
2. **Memoization**:
   - Since calculating scores recursively for overlapping subproblems can be redundant, we use a memoization structure (`memo`) to store previously computed results.
   - The `memo` structure is a 2D vector of maps, where `memo[l][r][net]` stores the result of the `dp` function for subarray `nums[l]` to `nums[r]` with the given `net`.

3. **Recursive Calculation**:
   - For each recursive call, we consider two options:
     - If the player picks the left card, the next recursive call computes the score for the range from `l + 1` to `r`.
     - If the player picks the right card, the range becomes `l` to `r - 1`.
   - The final score is then computed as the maximum score obtainable by either choice.

4. **Game Decision**:
   - After calculating the maximum score for the first player, we compare it to the remainder of the total score. If the first player's score is greater than or equal to half of the total score, they can guarantee a win.

### Code Breakdown (Step by Step)

The solution code consists of two main parts: the `dp` function and the `predictTheWinner` function.

1. **Member Variables**:
   ```cpp
   vector<int> nums;
   vector<vector<map<int, int>>> memo;
   ```
   Here, `nums` stores the input array, and `memo` is a 2D vector of maps to cache results for each subarray and net value combination.

2. **Dynamic Programming Function (`dp`)**:
   ```cpp
   int dp(int l, int r, int net) {
       if(l == r) return nums[l];
       if(memo[l][r].count(net)) return memo[l][r][net];
       
       int ans = net - dp(l + 1, r, net - nums[l]);
       ans = max(ans, net - dp(l, r - 1, net - nums[r]));
       
       return memo[l][r][net] = ans;
   }
   ```
   - **Base Case**: If `l` equals `r`, there’s only one card left, so the result is simply `nums[l]`.
   - **Memoization Check**: If the result for this subarray and net value has already been computed, it is returned from `memo`.
   - **Recursive Calculation**: The player’s score is calculated based on the choices of picking either the left or right card. The player maximizes their score while reducing the opponent’s score in the recursive calls.
   - **Memoization Storage**: The result is stored in `memo` to avoid recomputation in subsequent recursive calls.

3. **Main Function (`predictTheWinner`)**:
   ```cpp
   bool predictTheWinner(vector<int>& nums) {
       this->nums = nums;
       int n = nums.size();
       memo.resize(n + 1, vector<map<int,int>>(n + 1));
       
       int net = accumulate(nums.begin(), nums.end(), 0);
       int ret = dp(0, n - 1, net);

       return ret >= net - ret;
   }
   ```
   - **Initialization**: The input `nums` is assigned to the class variable, and `memo` is resized based on the size of `nums`.
   - **Net Calculation**: `net` represents the total sum of all elements in `nums`.
   - **Recursive Call**: The `dp` function is called for the full array, aiming to maximize the score for the first player.
   - **Decision**: If the first player’s score `ret` is greater than or equal to half of `net`, the function returns `true`, indicating that the first player can guarantee a win.

### Complexity

1. **Time Complexity**:
   - The time complexity is roughly `O(n^2 * S)`, where `n` is the size of `nums` and `S` represents the range of potential values in `net`. However, due to memoization, this complexity is significantly reduced by storing intermediate results.

2. **Space Complexity**:
   - The space complexity is `O(n^2 * S)`, accounting for the 2D `memo` structure.

### Conclusion

This solution demonstrates an effective use of dynamic programming with memoization to solve a problem involving recursive choices. By storing intermediate results and making optimal decisions at each step, we ensure that the solution is both efficient and scalable for larger inputs. This approach is highly effective for problems involving competitive strategy, making it ideal for scenarios where players compete over resource allocation or score maximization.

[`Link to LeetCode Lab`](https://leetcode.com/problems/predict-the-winner/description/)

---
{{< youtube KjlXtj7IwyY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |


+++
authors = ["grid47"]
title = "Leetcode 1824: Minimum Sideway Jumps"
date = "2024-05-08"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1824: Minimum Sideway Jumps in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "IDTzmXD5H58"
youtube_upload_date="2021-04-11"
youtube_thumbnail="https://i.ytimg.com/vi/IDTzmXD5H58/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<int>> memo;
    int dp(int cur, int idx, vector<int> &obs) {

        if(idx == obs.size()) return 0;
        if(memo[cur][idx] != -1) return memo[cur][idx];
        if(obs[idx] == cur) return INT_MAX - 1;
        
        int ans = dp(cur, idx + 1, obs);

        int left  = (cur - 1 + 1) % 3 + 1;
        int right = (cur - 1 + 2) % 3 + 1;
        
        if(obs[idx] != left) {
            ans = min(ans, dp(left, idx + 1, obs) + 1);
        }
        if(obs[idx] != right) {
            ans = min(ans, dp(right, idx + 1, obs) + 1);
        }
        return memo[cur][idx] = ans;
    }
    
    int minSideJumps(vector<int>& obs) {
        
        int n = obs.size();
        int cur = 2, idx = 0;
        
        memo.resize(4, vector<int>(n + 1, -1));
        
        return dp(cur, idx, obs);
        
    }
};
{{< /highlight >}}
---

### Problem Statement

In this problem, we have a road consisting of three lanes, and we need to navigate through obstacles that are represented in a given array. The objective is to determine the minimum number of side jumps required to get from the starting position to the end of the road while avoiding the obstacles. The player starts at lane 2, and they can move to an adjacent lane or stay in the same lane.

Given an array `obs` where `obs[i]` represents the lane that has an obstacle at position `i`, the task is to find the minimum number of side jumps required to reach the end of the road (position `n`), which corresponds to the last index of the `obs` array.

### Approach

The solution employs dynamic programming with memoization to efficiently compute the minimum number of jumps required to navigate through the obstacles. The main ideas of the approach are as follows:

1. **Recursive Function**: A recursive function `dp(cur, idx, obs)` is used to explore the possibilities of jumping to different lanes at the current index `idx` and tracks the current lane `cur`.

2. **Base Cases**:
   - If `idx` equals the size of `obs`, it indicates that we have successfully reached the end of the road, so we return `0`.
   - If the current lane `cur` has an obstacle at `obs[idx]`, we cannot remain in that lane, so we return a large value (to signify an invalid state).

3. **Recursion**: For each position:
   - Calculate the minimum side jumps needed if we either stay in the same lane or jump to an adjacent lane (left or right).
   - If jumping to the left or right lane does not lead to an obstacle, we consider that option and add `1` to the jump count.

4. **Memoization**: We store the results of previously computed states to avoid redundant calculations, which enhances performance significantly.

5. **Initialization**: The algorithm starts from lane `2` at index `0`, and we call the recursive function to compute the result.

### Code Breakdown (Step by Step)

Here’s the complete implementation with detailed explanations:

```cpp
class Solution {
public:
    vector<vector<int>> memo; // Memoization table to store computed values
    
    // The recursive function for DP
    int dp(int cur, int idx, vector<int> &obs) {
```
- The function `dp` takes the current lane `cur`, the current index `idx`, and the obstacle array `obs` as inputs.

```cpp
        if(idx == obs.size()) return 0; // Reached the end of the road
        if(memo[cur][idx] != -1) return memo[cur][idx]; // Return already computed value
        if(obs[idx] == cur) return INT_MAX - 1; // Current lane is blocked
```
- The function checks for base cases:
  - If `idx` equals the length of `obs`, we return `0` as we have successfully traversed the road.
  - If the current lane has an obstacle, we return a large number, indicating that this path is not feasible.

```cpp
        int ans = dp(cur, idx + 1, obs); // Option to stay in the same lane
```
- Calculate the minimum jumps if we stay in the current lane.

```cpp
        int left  = (cur - 1 + 1) % 3 + 1; // Compute the left lane
        int right = (cur - 1 + 2) % 3 + 1; // Compute the right lane
```
- Determine the adjacent lanes: `left` and `right`.

```cpp
        if(obs[idx] != left) {
            ans = min(ans, dp(left, idx + 1, obs) + 1);
        }
        if(obs[idx] != right) {
            ans = min(ans, dp(right, idx + 1, obs) + 1);
        }
```
- If moving to the `left` or `right` lanes is valid (not blocked), calculate the minimum jumps needed considering the jump and update `ans`.

```cpp
        return memo[cur][idx] = ans; // Memoize the computed result
    }
```
- Store the result in the memoization table before returning.

```cpp
    int minSideJumps(vector<int>& obs) {
        int n = obs.size(); // Length of the obstacles array
        int cur = 2, idx = 0; // Start in lane 2 at index 0
        
        memo.resize(4, vector<int>(n + 1, -1)); // Resize memoization table
        
        return dp(cur, idx, obs); // Start the DP recursion
    }
};
```
- In `minSideJumps`, we initialize the parameters, resize the memoization table, and call the `dp` function to get the result.

### Complexity

- **Time Complexity**: The time complexity is \(O(n)\) because each state is computed at most once, where \(n\) is the length of the `obs` array.
  
- **Space Complexity**: The space complexity is \(O(n)\) due to the memoization table, which stores results for each combination of current lane and index.

### Conclusion

The provided solution effectively utilizes dynamic programming with memoization to find the minimum number of side jumps needed to traverse the road with obstacles. The approach is systematic and leverages the recursive nature of the problem to explore different possibilities of movement while efficiently storing intermediate results to optimize performance.

This implementation showcases the power of dynamic programming to break down complex problems into manageable subproblems, thereby achieving an efficient solution. It ensures that the constraints of the problem are respected while providing a clear pathway to the solution, making it a robust approach to solving this particular challenge.

[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-sideway-jumps/description/)

---
{{< youtube IDTzmXD5H58 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

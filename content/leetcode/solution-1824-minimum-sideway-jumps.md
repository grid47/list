
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
comments = true
+++



---
A frog is traveling on a 3-lane road, starting at point 0 on lane 2. The frog wants to reach point n, but there may be obstacles at various points on the road. The frog can either move forward on the same lane or jump to another lane if the current lane is blocked. The goal is to find the minimum number of side jumps the frog needs to take to reach point n while avoiding obstacles.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an array obstacles where obstacles[i] (0 <= i <= n) represents the obstacle at point i in lane obstacles[i]. The value of obstacles[i] can be 0 (no obstacle), 1 (obstacle on lane 1), 2 (obstacle on lane 2), or 3 (obstacle on lane 3).
- **Example:** `For example, obstacles = [0, 1, 2, 3, 0] means that there are obstacles on lane 1 at point 1, lane 2 at point 2, and lane 3 at point 3.`
- **Constraints:**
	- 1 <= n <= 5 * 10^5
	- 0 <= obstacles[i] <= 3
	- obstacles[0] == obstacles[n] == 0

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of side jumps the frog needs to take to reach point n, starting from point 0 on lane 2.
- **Example:** `For obstacles = [0, 1, 2, 3, 0], the frog needs 2 side jumps to avoid obstacles and reach point n, so the output should be 2.`
- **Constraints:**
	- The output should be a non-negative integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The frog needs to avoid obstacles and reach point n with the fewest side jumps.

- 1. Start at point 0, lane 2.
- 2. At each point, check if there is an obstacle in the current lane.
- 3. If there is an obstacle in the current lane, consider jumping to the other two lanes if they are clear of obstacles.
- 4. Continue this process until the frog reaches point n, keeping track of the minimum number of jumps.
{{< dots >}}
### Problem Assumptions ✅
- The frog can always make a side jump if needed, as long as the destination lane is clear of obstacles.
- The frog will only need to jump when its current lane is blocked.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: obstacles = [0, 1, 2, 3, 0]`  \
  **Explanation:** The frog starts on lane 2 at point 0. It faces an obstacle on lane 1 at point 1, so it jumps to lane 3. It then faces an obstacle on lane 3 at point 2, so it jumps to lane 1. After jumping twice, the frog reaches point n, having made 2 side jumps.

- **Input:** `Input: obstacles = [0, 1, 1, 3, 3, 0]`  \
  **Explanation:** The frog starts on lane 2 at point 0. There are no obstacles on lane 2 at point 1, so it continues straight ahead. No side jumps are needed, and the frog reaches point n without any obstacles.

- **Input:** `Input: obstacles = [0, 2, 1, 0, 3, 0]`  \
  **Explanation:** The frog faces an obstacle on lane 2 at point 1, so it jumps to lane 3. It then faces an obstacle on lane 3 at point 3, so it jumps to lane 1. The frog makes 2 side jumps to reach point n.

{{< dots >}}
## Approach 🚀
The frog's movement is optimized by using dynamic programming to minimize the number of side jumps. We track the frog's position and the state of the lanes at each point, recursively determining the minimum jumps required.

### Initial Thoughts 💭
- The frog can either move forward on the same lane or jump to another lane to avoid obstacles.
- We need to calculate the minimum number of jumps for each position and lane combination.
- The problem can be solved with dynamic programming by storing results for each possible state (lane and position) and building upon the previous states.
{{< dots >}}
### Edge Cases 🌐
- The input array has only one point (n=1), which is the simplest case.
- Consider the case where n is at its upper bound (n = 500000). Efficient memoization and recursion are necessary to handle this case.
- The frog does not need to jump if no obstacles are present, making the solution straightforward.
- Ensure that the memoization table handles the maximum input size efficiently.
{{< dots >}}
## Code 💻
```cpp
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
```

This code defines a solution for the problem of minimizing side jumps in a track with obstacles. The function `minSideJumps` uses dynamic programming and memoization to find the optimal path avoiding obstacles.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Memoization Setup**
	```cpp
	vector<vector<int>> memo;
	```
	A 2D vector `memo` is declared to store the results of subproblems. It helps in avoiding redundant calculations during recursion.

2. **Function Definition**
	```cpp
	int dp(int cur, int idx, vector<int> &obs) {
	```
	This defines the recursive helper function `dp` which calculates the minimum side jumps starting from the current track (`cur`) and index (`idx`) while avoiding obstacles.

3. **Base Case 1**
	```cpp
	    if(idx == obs.size()) return 0;
	```
	This base case checks if the end of the track is reached. If so, it returns 0, as no further jumps are needed.

4. **Memoization Check**
	```cpp
	    if(memo[cur][idx] != -1) return memo[cur][idx];
	```
	If the result for the current subproblem has already been calculated, it is retrieved from `memo` to avoid redundant computations.

5. **Obstacle Check**
	```cpp
	    if(obs[idx] == cur) return INT_MAX - 1;
	```
	If there is an obstacle on the current track (`cur`), it returns a large value (`INT_MAX - 1`), indicating an invalid path.

6. **Recursive Call 1**
	```cpp
	    int ans = dp(cur, idx + 1, obs);
	```
	This recursive call computes the minimum side jumps if the current track is not changed.

7. **Left Track Calculation**
	```cpp
	    int left  = (cur - 1 + 1) % 3 + 1;
	```
	This calculates the left track (`left`) that can be considered for the next move.

8. **Right Track Calculation**
	```cpp
	    int right = (cur - 1 + 2) % 3 + 1;
	```
	This calculates the right track (`right`) that can be considered for the next move.

9. **Left Track Side Jump**
	```cpp
	    if(obs[idx] != left) {
	```
	Checks if the left track is not blocked by an obstacle. If not, it recursively calculates the minimum side jumps from the left track.

10. **Left Track Recursive Call**
	```cpp
	        ans = min(ans, dp(left, idx + 1, obs) + 1);
	```
	The minimum side jumps value is updated if jumping to the left track results in a smaller number of jumps.

11. **Right Track Side Jump**
	```cpp
	    if(obs[idx] != right) {
	```
	Checks if the right track is not blocked by an obstacle. If not, it recursively calculates the minimum side jumps from the right track.

12. **Right Track Recursive Call**
	```cpp
	        ans = min(ans, dp(right, idx + 1, obs) + 1);
	```
	The minimum side jumps value is updated if jumping to the right track results in a smaller number of jumps.

13. **Memoization Storage**
	```cpp
	    return memo[cur][idx] = ans;
	```
	The result of the current subproblem is stored in the `memo` array to avoid redundant calculations.

14. **Main Function Definition**
	```cpp
	int minSideJumps(vector<int>& obs) {
	```
	This defines the main function `minSideJumps`, which initializes the memoization table and calls the `dp` function to compute the minimum side jumps.

15. **Track Size**
	```cpp
	    int n = obs.size();
	```
	This line calculates the size of the obstacle array (`obs`) to determine the number of tracks.

16. **Initial Track and Index**
	```cpp
	    int cur = 2, idx = 0;
	```
	Initial values for `cur` (current track) and `idx` (current index) are set.

17. **Memoization Table Setup**
	```cpp
	    memo.resize(4, vector<int>(n + 1, -1));
	```
	The `memo` table is resized to store the results of subproblems for all tracks and indices.

18. **Return Result**
	```cpp
	    return dp(cur, idx, obs);
	```
	Calls the `dp` function to compute and return the minimum number of side jumps.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n) when there are no obstacles and no side jumps are required.
- **Average Case:** O(n) since we compute the minimum jumps for each position and lane.
- **Worst Case:** O(n) with memoization to prevent recomputation of subproblems.

The dynamic programming solution processes each point only once, resulting in linear time complexity.

### Space Complexity 💾
- **Best Case:** O(n) when no side jumps are needed.
- **Worst Case:** O(n) for the memoization table.

The space complexity is linear due to the memoization table storing the minimum jumps for each lane and position.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-sideway-jumps/description/)

---
{{< youtube IDTzmXD5H58 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

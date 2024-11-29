
+++
authors = ["grid47"]
title = "Leetcode 1621: Number of Sets of K Non-Overlapping Line Segments"
date = "2024-05-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1621: Number of Sets of K Non-Overlapping Line Segments in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Dynamic Programming","Combinatorics"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "Zl-atHgL8QY"
youtube_upload_date="2020-10-17"
youtube_thumbnail="https://i.ytimg.com/vi/Zl-atHgL8QY/maxresdefault.jpg"
comments = true
+++



---
You are given n points on a 1-D plane, where each point i is at x = i. Your task is to find the number of ways to draw exactly k non-overlapping line segments that cover two or more points, such that the endpoints are integral. Return the result modulo 10^9 + 7.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given two integers n (2 <= n <= 1000) and k (1 <= k <= n - 1), where n represents the number of points on the 1-D plane and k represents the number of non-overlapping line segments to draw.
- **Example:** `n = 4, k = 2`
- **Constraints:**
	- 2 <= n <= 1000
	- 1 <= k <= n - 1

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of ways to draw k non-overlapping line segments, modulo 10^9 + 7.
- **Example:** `Output: 5`
- **Constraints:**
	- The result should be returned modulo 10^9 + 7.

{{< dots >}}
### Core Logic 🔍
**Goal:** You need to find the number of distinct ways to draw k non-overlapping line segments.

- Use dynamic programming to calculate the number of ways to draw the segments.
- Memoize intermediate results to optimize the calculation.
{{< dots >}}
### Problem Assumptions ✅
- The input will always satisfy the given constraints.
- You can use dynamic programming with memoization to solve the problem efficiently.
{{< dots >}}
## Examples 🧩
- **Input:** `n = 4, k = 2`  \
  **Explanation:** The 5 different ways to draw 2 non-overlapping line segments are: (0, 2) and (2, 3), (0, 1) and (1, 3), (0, 1) and (2, 3), (1, 2) and (2, 3), (0, 1) and (1, 2).

- **Input:** `n = 3, k = 1`  \
  **Explanation:** The 3 ways to draw 1 non-overlapping line segment are: (0, 1), (0, 2), (1, 2).

{{< dots >}}
## Approach 🚀
We use dynamic programming to compute the number of ways to draw k non-overlapping line segments by considering each point and whether we can start or end a line segment at that point.

### Initial Thoughts 💭
- The problem can be solved using dynamic programming to track the number of ways to draw the segments.
- The segments must be non-overlapping, and we have to take care of memoization to avoid recomputation.
- We need a recursive function that calculates the number of ways to draw segments from the current position and memoizes the results for efficiency.
{{< dots >}}
### Edge Cases 🌐
- n cannot be less than 2, so there is no need to handle empty inputs.
- Ensure that the solution handles the upper limit where n is up to 1000.
- The number of ways may become large, so remember to return the result modulo 10^9 + 7.
- The value of k must always be between 1 and n-1, inclusive.
{{< dots >}}
## Code 💻
```cpp
int n;
int mod = (int) 1e9 + 7;
int memo[1001][1001][2];
int dp(int idx, int seg, bool startHere) {
    if(seg == 0) return 1;
    if(idx == n) return 0;

    if(memo[idx][seg][startHere] != -1) return memo[idx][seg][startHere];
    
    int ans = dp(idx + 1, seg, startHere); // will start on next or continue the seg
    if(startHere) {
        ans = (ans + dp(idx + 1, seg, false)) % mod; // stared new line            
    } else {
        ans = (ans + dp(idx, seg - 1, true)) % mod; // end the line here            
    }

    return memo[idx][seg][startHere] = ans;
}

int numberOfSets(int n, int k) {
    this->n = n;
    memset(memo, -1, sizeof(memo));
    return dp(0, k, true);
}
```

This code defines a function `numberOfSets` to calculate the number of ways to divide a sequence into exactly `k` non-empty segments using dynamic programming. The function `dp` recursively explores different ways to split the sequence, caching results in a memoization table to improve efficiency.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	int n;
	```
	Declare a variable `n` to store the length of the sequence to be divided.

2. **Variable Initialization**
	```cpp
	int mod = (int) 1e9 + 7;
	```
	Initialize a variable `mod` with a large prime number, used for modulo operations to prevent overflow in the final result.

3. **Array Initialization**
	```cpp
	int memo[1001][1001][2];
	```
	Declare a 3D array `memo` for memoization, to store results of subproblems and avoid redundant calculations. It stores results for different states of the recursion.

4. **Function Definition**
	```cpp
	int dp(int idx, int seg, bool startHere) {
	```
	Define the recursive function `dp`, which takes the current index `idx`, the number of segments left `seg`, and a boolean `startHere` indicating whether we are starting a new segment.

5. **Base Case**
	```cpp
	    if(seg == 0) return 1;
	```
	Base case: if there are no more segments to divide, return 1, indicating one valid way to split the sequence.

6. **Base Case**
	```cpp
	    if(idx == n) return 0;
	```
	Base case: if the index has reached the end of the sequence (`n`), return 0, as there are no ways to further split the sequence.

7. **Memoization Check**
	```cpp
	    if(memo[idx][seg][startHere] != -1) return memo[idx][seg][startHere];
	```
	Check if the result for the current subproblem is already computed and stored in the `memo` array. If so, return the cached result.

8. **Recursive Call**
	```cpp
	    int ans = dp(idx + 1, seg, startHere); // will start on next or continue the seg
	```
	Recursively call `dp` to explore the option of either starting a new segment or continuing the current one, incrementing the index `idx`.

9. **Conditional Branching**
	```cpp
	    if(startHere) {
	```
	Check if we are starting a new segment. If `startHere` is true, we can split the sequence at the current index and start a new segment.

10. **Recursive Call**
	```cpp
	        ans = (ans + dp(idx + 1, seg, false)) % mod; // started new line
	```
	If we start a new segment, make a recursive call to `dp`, marking `startHere` as false and continue dividing the sequence.

11. **Else Branch**
	```cpp
	    } else {
	```
	If we are not starting a new segment, then we end the current segment and decrease the segment count.

12. **Recursive Call**
	```cpp
	        ans = (ans + dp(idx, seg - 1, true)) % mod; // end the line here
	```
	If not starting a new segment, recursively call `dp` with a reduced segment count `seg - 1` and mark `startHere` as true to start the next segment.

13. **Memoization Update**
	```cpp
	    return memo[idx][seg][startHere] = ans;
	```
	Store the result of the current subproblem in the `memo` array to avoid redundant calculations in future calls.

14. **Function Definition**
	```cpp
	int numberOfSets(int n, int k) {
	```
	Define the main function `numberOfSets`, which initializes the necessary variables and calls the `dp` function to calculate the number of ways to divide the sequence into `k` segments.

15. **Variable Assignment**
	```cpp
	    this->n = n;
	```
	Assign the value of `n` (number of elements in the sequence) to the instance variable `n`.

16. **Array Initialization**
	```cpp
	    memset(memo, -1, sizeof(memo));
	```
	Initialize the `memo` array to -1 to indicate that no subproblem results have been calculated yet.

17. **Return Statement**
	```cpp
	    return dp(0, k, true);
	```
	Call the `dp` function starting from the first index (`0`), with `k` segments to be formed, and return the result.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n * k)
- **Average Case:** O(n * k)
- **Worst Case:** O(n * k)

The dynamic programming solution evaluates each subproblem once, and there are at most n * k subproblems to solve.

### Space Complexity 💾
- **Best Case:** O(n * k)
- **Worst Case:** O(n * k)

The space complexity is O(n * k) due to the memoization table storing results for each subproblem.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-sets-of-k-non-overlapping-line-segments/description/)

---
{{< youtube Zl-atHgL8QY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

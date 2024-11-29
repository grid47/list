
+++
authors = ["grid47"]
title = "Leetcode 2320: Count Number of Ways to Place Houses"
date = "2024-03-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2320: Count Number of Ways to Place Houses in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "9K92zYtgjrk"
youtube_upload_date="2022-06-26"
youtube_thumbnail="https://i.ytimg.com/vi_webp/9K92zYtgjrk/maxresdefault.webp"
comments = true
+++



---
Given a street with two rows of plots, each containing n plots, find the number of ways houses can be placed such that no two houses are adjacent on the same side of the street. Return the result modulo 10^9 + 7.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer n, representing the number of plots on each side of the street.
- **Example:** `n = 1`
- **Constraints:**
	- 1 <= n <= 10^4

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of valid ways to place houses modulo 10^9 + 7.
- **Example:** `For n = 1, the output is 4.`
- **Constraints:**
	- The result should be returned modulo 10^9 + 7.

{{< dots >}}
### Core Logic 🔍
**Goal:** To calculate the number of ways to place houses, we need to ensure that houses are not adjacent on the same side of the street. The result depends on valid placement configurations for both sides.

- 1. Use dynamic programming to calculate the number of valid configurations for each side of the street.
- 2. Multiply the valid configurations for each side and return the result modulo 10^9 + 7.
{{< dots >}}
### Problem Assumptions ✅
- The street has exactly two sides, and both sides have n plots.
{{< dots >}}
## Examples 🧩
- **Input:** `n = 1`  \
  **Explanation:** For n = 1, the possible configurations are: no house, one house on the first side, one house on the second side, and one house on both sides. Hence, the total number of valid configurations is 4.

- **Input:** `n = 2`  \
  **Explanation:** For n = 2, the number of valid configurations is calculated by considering the valid placement of houses on each side and multiplying them together, resulting in 9 possible configurations.

{{< dots >}}
## Approach 🚀
We will use dynamic programming to calculate the number of valid ways to place houses on both sides of the street, ensuring no two houses are adjacent on the same side.

### Initial Thoughts 💭
- The problem can be broken down into calculating the number of valid ways to place houses on each side of the street.
- Dynamic programming is a good fit for this problem, as it allows us to compute the number of valid configurations efficiently.
- The problem can be solved by calculating the valid configurations for one side and then considering the placements on both sides simultaneously.
{{< dots >}}
### Edge Cases 🌐
- There are no empty inputs since n will always be at least 1.
- For large values of n (up to 10^4), the solution should efficiently compute the result without running into performance issues.
- When n is small (e.g., n = 1), the number of valid placements can be easily verified manually.
- The solution should be efficient enough to handle the upper bound of n = 10^4.
{{< dots >}}
## Code 💻
```cpp
class Solution {

long long mod = 1000000007;

public:

typedef long long ll;

vector<vector<int>> dp;
int countHousePlacements(int n) {
    
    dp.resize(n + 1, vector<int> (2, -1));
    
    ll res = ( rec(n, 0) + rec(n, 1) ) % mod;

    return (res * res ) % mod;
}

int rec(int n, bool filled) {
    if(n == 1) return 1;
    
    if(dp[n][filled] != -1)
        return dp[n][filled];

    if(filled)  return dp[n][filled] = rec(n - 1, !filled);
    else        return dp[n][filled] = ( rec(n - 1, filled) + rec(n - 1, !filled) ) % mod;
}

```

This solution calculates the number of ways to place houses in a street with `n` plots, ensuring that no two houses are adjacent. It uses dynamic programming (DP) to efficiently calculate the result.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Class Declaration**
	```cpp
	class Solution {
	```
	Define the `Solution` class which will contain the necessary methods to solve the problem.

2. **Mod Constant**
	```cpp
	long long mod = 1000000007;
	```
	Declare a constant `mod` to store the value 1000000007, which will be used for modular arithmetic to avoid overflow during calculations.

3. **Public Access Specifier**
	```cpp
	public:
	```
	Declare the following methods and variables as public so they can be accessed from outside the class.

4. **Typedef**
	```cpp
	typedef long long ll;
	```
	Create a typedef `ll` for `long long` to simplify the code and improve readability.

5. **DP Vector Declaration**
	```cpp
	vector<vector<int>> dp;
	```
	Declare a 2D vector `dp` to store results of subproblems. The dimensions of `dp` are based on the number of plots `n` and whether the last plot is filled.

6. **Main Function Declaration**
	```cpp
	int countHousePlacements(int n) {
	```
	Declare the `countHousePlacements` method that takes an integer `n` (the number of plots) as input and returns the number of ways to place houses.

7. **DP Resizing**
	```cpp
	    dp.resize(n + 1, vector<int> (2, -1));
	```
	Resize the DP vector `dp` to store results for each plot `n` and each possible state (filled or not filled). Initialize all entries to -1 (indicating that they have not been calculated yet).

8. **Recursive Call**
	```cpp
	    ll res = ( rec(n, 0) + rec(n, 1) ) % mod;
	```
	Make recursive calls to `rec` for both filled and not filled states at plot `n`. The results are summed up and taken modulo `mod`.

9. **Final Result**
	```cpp
	    return (res * res ) % mod;
	```
	Return the final result, which is the square of `res` modulo `mod`, as the number of valid house placements.

10. **Recursive Function Declaration**
	```cpp
	int rec(int n, bool filled) {
	```
	Declare the recursive method `rec`, which computes the number of valid placements for `n` plots with the last plot either filled or not.

11. **Base Case**
	```cpp
	    if(n == 1) return 1;
	```
	If there is only one plot, return 1, as there is exactly one way to place a house (either fill the plot or leave it empty).

12. **Memoization Check**
	```cpp
	    if(dp[n][filled] != -1)
	```
	Check if the result for this subproblem has already been computed (memoization). If so, return the stored result.

13. **Memoized Result**
	```cpp
	        return dp[n][filled];
	```
	Return the memoized result for the current subproblem.

14. **Recursion for Filled Plot**
	```cpp
	    if(filled)  return dp[n][filled] = rec(n - 1, !filled);
	```
	If the last plot is filled, recursively calculate the result for the previous plot with the opposite state (not filled).

15. **Recursion for Unfilled Plot**
	```cpp
	    else        return dp[n][filled] = ( rec(n - 1, filled) + rec(n - 1, !filled) ) % mod;
	```
	If the last plot is not filled, recursively calculate the result for both filled and unfilled states for the previous plot, and sum the results modulo `mod`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) since we calculate the number of valid placements using dynamic programming, iterating through each plot.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage required for the dynamic programming table.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/count-number-of-ways-to-place-houses/description/)

---
{{< youtube 9K92zYtgjrk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |


+++
authors = ["grid47"]
title = "Leetcode 474: Ones and Zeroes"
date = "2024-09-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 474: Ones and Zeroes in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/474.webp"
youtube = "miZ3qV04b1g"
youtube_upload_date="2023-03-02"
youtube_thumbnail="https://i.ytimg.com/vi/miZ3qV04b1g/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/474.webp" 
    alt="A sequence of ones and zeroes gently forming various combinations, with each valid combination glowing softly."
    caption="Solution to LeetCode 474: Ones and Zeroes Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given an array of binary strings `strs` and two integers `m` and `n`, return the size of the largest subset of `strs` such that there are at most `m` zeros and `n` ones in the subset.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array `strs` of binary strings and two integers `m` and `n`.
- **Example:** `strs = ['11', '0001', '101', '1', '0'], m = 4, n = 3`
- **Constraints:**
	- 1 <= strs.length <= 600
	- 1 <= strs[i].length <= 100
	- strs[i] consists only of digits '0' and '1'.
	- 1 <= m, n <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the size of the largest subset of strings where the total number of zeros is at most `m` and the total number of ones is at most `n`.
- **Example:** `Output: 4`
- **Constraints:**
	- The output should be an integer representing the size of the largest valid subset.

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the largest subset of strings that meets the criteria of having at most `m` zeros and `n` ones.

- 1. Initialize a dynamic programming table `dp` to track the largest subset size for each combination of zeros and ones.
- 2. For each string in `strs`, count the number of zeros and ones.
- 3. Update the DP table by considering the current string and checking if adding it to any existing valid subset would exceed the limits of `m` zeros and `n` ones.
- 4. Return the maximum subset size found in the DP table.
{{< dots >}}
### Problem Assumptions ✅
- The strings in `strs` only contain '0' and '1'.
- The constraints on `m` and `n` ensure that brute-force approaches are not feasible.
{{< dots >}}
## Examples 🧩
- **Input:** `strs = ['11', '0001', '101', '1', '0'], m = 4, n = 3`  \
  **Explanation:** The largest valid subset is {'11', '0001', '1', '0'}, which has 4 zeros and 3 ones, satisfying the conditions.

- **Input:** `strs = ['10', '1', '0'], m = 2, n = 2`  \
  **Explanation:** The largest valid subset is {'10', '1', '0'}, which contains 2 zeros and 2 ones.

{{< dots >}}
## Approach 🚀
The approach involves dynamic programming to keep track of the largest subset that satisfies the constraints on zeros and ones.

### Initial Thoughts 💭
- This is a variant of the knapsack problem, where we are bounded by both zeros and ones in the strings.
- We need to use dynamic programming to track the largest valid subset size.
- Using dynamic programming (DP), we can efficiently track the maximum number of strings we can select given the constraints.
{{< dots >}}
### Edge Cases 🌐
- Empty input array should return 0 as no strings can be selected.
- Handle cases where the number of strings is large (up to 600).
- Consider inputs where all strings are '0' or '1', or combinations of strings with very few zeros or ones.
- Ensure that the DP table is efficiently updated to handle all possible combinations of zeros and ones.
{{< dots >}}
## Code 💻
```cpp
int findMaxForm(vector<string>& strs, int zeros, int ones) {
    int i, j, p = strs.size();
    vector<vector<int>> dp(zeros + 1, vector<int>(ones+1));

    for(auto &s : strs) {
        int currOne = count(s.begin(), s.end(), '1');
        int currZero = s.size() - currOne;
        for(int j = ones ; j >= currOne; j--) 
        for(int i = zeros; i >= currZero; i--) {
           dp[i][j] = max(dp[i][j], 1 + dp[i- currZero ][j-currOne]);
        }
    }

    return dp[zeros][ones];
}
```

The `findMaxForm` function uses dynamic programming to find the maximum number of strings that can be formed with a given number of 0's and 1's. The DP table stores the results of subproblems, where `dp[i][j]` represents the maximum number of strings that can be formed with `i` zeros and `j` ones.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int findMaxForm(vector<string>& strs, int zeros, int ones) {
	```
	Defines the function `findMaxForm`, which takes a list of binary strings and two integers `zeros` and `ones` as input and returns the maximum number of strings that can be formed using at most the given number of 0's and 1's.

2. **Variable Initialization**
	```cpp
	    int i, j, p = strs.size();
	```
	Initializes the variables `i` and `j` for the loops, and `p` to store the size of the `strs` vector.

3. **DP Table Initialization**
	```cpp
	    vector<vector<int>> dp(zeros + 1, vector<int>(ones+1));
	```
	Initializes the DP table `dp` with dimensions `(zeros + 1) x (ones + 1)` to store the maximum number of strings that can be formed with a given number of zeros and ones.

4. **Outer Loop Over Strings**
	```cpp
	    for(auto &s : strs) {
	```
	Iterates over each string `s` in the `strs` vector to process it one by one.

5. **Count Ones in Current String**
	```cpp
	        int currOne = count(s.begin(), s.end(), '1');
	```
	Counts the number of 1's in the current string `s` using the `count()` function.

6. **Count Zeros in Current String**
	```cpp
	        int currZero = s.size() - currOne;
	```
	Calculates the number of 0's in the current string `s` by subtracting the number of 1's from the total size of the string.

7. **Inner Loop Over Ones**
	```cpp
	        for(int j = ones ; j >= currOne; j--) 
	```
	Iterates over the number of ones in the DP table in reverse order (from `ones` down to `currOne`) to ensure we don't overwrite previously computed values.

8. **Inner Loop Over Zeros**
	```cpp
	        for(int i = zeros; i >= currZero; i--) {
	```
	Iterates over the number of zeros in the DP table in reverse order (from `zeros` down to `currZero`) to avoid overwriting values during the DP calculation.

9. **DP Table Update**
	```cpp
	           dp[i][j] = max(dp[i][j], 1 + dp[i - currZero][j - currOne]);
	```
	Updates the DP table at position `dp[i][j]` by considering whether to include the current string. If included, the value becomes 1 + the previous value at `dp[i - currZero][j - currOne]`.

10. **Return Result**
	```cpp
	    return dp[zeros][ones];
	```
	Returns the value stored in `dp[zeros][ones]`, which represents the maximum number of strings that can be formed with `zeros` and `ones`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n * strs.length)
- **Average Case:** O(m * n * strs.length)
- **Worst Case:** O(m * n * strs.length)

Time complexity is proportional to the product of `m`, `n`, and the length of the input array `strs`.

### Space Complexity 💾
- **Best Case:** O(m * n)
- **Worst Case:** O(m * n)

Space complexity is proportional to the size of the DP table, which is `O(m * n)`.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/ones-and-zeroes/description/)

---
{{< youtube miZ3qV04b1g >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

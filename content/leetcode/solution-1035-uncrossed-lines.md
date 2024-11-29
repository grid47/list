
+++
authors = ["grid47"]
title = "Leetcode 1035: Uncrossed Lines"
date = "2024-07-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1035: Uncrossed Lines in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "TFBZKlASq3g"
youtube_upload_date="2023-05-11"
youtube_thumbnail="https://i.ytimg.com/vi/TFBZKlASq3g/maxresdefault.jpg"
comments = true
+++



---
Given two integer arrays, `nums1` and `nums2`, we write the integers of both arrays on two separate horizontal lines. We can draw connecting lines between the elements of `nums1` and `nums2` if they are equal and the lines do not intersect. The objective is to return the maximum number of connecting lines that can be drawn between the two arrays without any line intersecting.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are provided with two integer arrays `nums1` and `nums2`. Each array contains integers, and the task is to find the maximum number of connecting lines between them.
- **Example:** `Input: nums1 = [1, 3, 7, 1], nums2 = [1, 9, 2, 5]`
- **Constraints:**
	- 1 <= nums1.length, nums2.length <= 500
	- 1 <= nums1[i], nums2[j] <= 2000

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum number of connecting lines that can be drawn between the two arrays without any intersection.
- **Example:** `Output: 2`
- **Constraints:**
	- The maximum number of connecting lines should be calculated based on the given arrays.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the maximum number of uncrossed lines between the two arrays by using dynamic programming to track the matches.

- 1. Use dynamic programming to calculate the maximum number of uncrossed lines.
- 2. Iterate through both arrays and find matching values. If a match is found, a line can be drawn.
- 3. Keep track of the maximum matches using a memoization approach to avoid redundant calculations.
{{< dots >}}
### Problem Assumptions ✅
- The arrays may contain repeated elements, and matching values can form valid connecting lines.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums1 = [1, 4, 2], nums2 = [1, 2, 4]`  \
  **Explanation:** We can draw two uncrossed lines: one between nums1[0] and nums2[0], and another between nums1[2] and nums2[1]. Therefore, the output is 2.

- **Input:** `Input: nums1 = [2, 5, 1, 2, 5], nums2 = [10, 5, 2, 1, 5, 2]`  \
  **Explanation:** The maximum number of uncrossed lines is 3: one line between nums1[0] and nums2[2], one between nums1[2] and nums2[3], and one between nums1[4] and nums2[5].

{{< dots >}}
## Approach 🚀
The approach uses dynamic programming (DP) to calculate the maximum number of uncrossed lines that can be drawn. We iterate through the arrays and use a memoization table to store the results of subproblems.

### Initial Thoughts 💭
- This problem can be solved by comparing each element of `nums1` with each element of `nums2` and using dynamic programming to avoid redundant computations.
- By using a 2D DP array, we can efficiently calculate the maximum number of uncrossed lines between the two arrays.
{{< dots >}}
### Edge Cases 🌐
- If either of the input arrays is empty, the result is 0 because no lines can be drawn.
- For large inputs (up to 500 elements), the DP solution efficiently handles the problem within the constraints.
- The solution should handle repeated numbers in the arrays correctly.
- Ensure the DP table is initialized correctly and iterated over all possible pairs.
{{< dots >}}
## Code 💻
```cpp
int m, n;
vector<int> nums1, nums2;
vector<vector<int>> memo;

int dp(int i, int j) {
    if(i == m || j == n) return 0;
    
    if(memo[i][j] != -1) return memo[i][j];
    
    int ans = INT_MIN;
    if(nums1[i] == nums2[j]) {
        ans = 1 + dp(i + 1, j + 1);
        return ans;
    }
    ans = max(dp(i + 1, j), dp(i, j + 1));
    return memo[i][j] = ans;
}

int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
    this->nums1 = nums1;
    this->nums2 = nums2;
    m = nums1.size(), n = nums2.size();
    memo.resize(m+1, vector<int>(n+1, -1));
    
    return dp(0, 0);
}
```

This is the complete code for the 'Max Uncrossed Lines' problem, which uses dynamic programming to find the maximum number of uncrossed lines between two sequences.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	int m, n;
	```
	Declare two integer variables 'm' and 'n' to store the lengths of the two input arrays.

2. **Variable Initialization**
	```cpp
	vector<int> nums1, nums2;
	```
	Declare two integer vectors, 'nums1' and 'nums2', to store the input arrays.

3. **Memoization Setup**
	```cpp
	vector<vector<int>> memo;
	```
	Declare a 2D vector 'memo' to store the results of subproblems for dynamic programming.

4. **Function Definition**
	```cpp
	int dp(int i, int j) {
	```
	Define a helper function 'dp' that computes the maximum number of uncrossed lines starting from indices 'i' and 'j' in the two arrays.

5. **Base Case**
	```cpp
	    if(i == m || j == n) return 0;
	```
	If either index 'i' or 'j' exceeds the array bounds, return 0 as no lines can be formed beyond the arrays.

6. **Memoization Check**
	```cpp
	    if(memo[i][j] != -1) return memo[i][j];
	```
	If the subproblem has been solved previously (i.e., 'memo[i][j]' is not -1), return the cached result.

7. **Initializing Answer**
	```cpp
	    int ans = INT_MIN;
	```
	Initialize a variable 'ans' to store the result of the current subproblem. Set it to the smallest possible value initially.

8. **Recursive Case (Matching Elements)**
	```cpp
	    if(nums1[i] == nums2[j]) {
	```
	If the elements at indices 'i' and 'j' in 'nums1' and 'nums2' are equal, this means a line can be drawn.

9. **Recursive Call (Matching Elements)**
	```cpp
	        ans = 1 + dp(i + 1, j + 1);
	```
	If the elements match, the result is 1 (for the current line) plus the result from the next indices 'i+1' and 'j+1'.

10. **Return on Match**
	```cpp
	        return ans;
	```
	Return the computed result for this subproblem if the elements match.

11. **Recursive Call (No Match)**
	```cpp
	    ans = max(dp(i + 1, j), dp(i, j + 1));
	```
	If the elements don't match, calculate the maximum result by either skipping the element from 'nums1' or 'nums2'.

12. **Memoization Assignment**
	```cpp
	    return memo[i][j] = ans;
	```
	Store the result of the current subproblem in the 'memo' table to avoid redundant calculations.

13. **Main Function Definition**
	```cpp
	int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
	```
	Define the main function 'maxUncrossedLines' that sets up the problem by initializing the input arrays and calling the 'dp' function.

14. **Input Assignment**
	```cpp
	    this->nums1 = nums1;
	```
	Assign the input vector 'nums1' to the class member 'nums1'.

15. **Input Assignment**
	```cpp
	    this->nums2 = nums2;
	```
	Assign the input vector 'nums2' to the class member 'nums2'.

16. **Variable Initialization**
	```cpp
	    m = nums1.size(), n = nums2.size();
	```
	Initialize the lengths 'm' and 'n' of the input arrays 'nums1' and 'nums2'.

17. **Memoization Setup**
	```cpp
	    memo.resize(m+1, vector<int>(n+1, -1));
	```
	Resize the 'memo' table to store results for all subproblems. Initialize all values to -1.

18. **Return DP Result**
	```cpp
	    return dp(0, 0);
	```
	Call the 'dp' function with initial indices (0, 0) and return the final result.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n)
- **Average Case:** O(m * n)
- **Worst Case:** O(m * n)

The time complexity is O(m * n), where m and n are the lengths of `nums1` and `nums2`, because we iterate through all pairs of elements in both arrays.

### Space Complexity 💾
- **Best Case:** O(m * n)
- **Worst Case:** O(m * n)

The space complexity is O(m * n) due to the DP table used to store the intermediate results.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/uncrossed-lines/description/)

---
{{< youtube TFBZKlASq3g >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |


+++
authors = ["grid47"]
title = "Leetcode 718: Maximum Length of Repeated Subarray"
date = "2024-08-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 718: Maximum Length of Repeated Subarray in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Dynamic Programming","Sliding Window","Rolling Hash","Hash Function"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/718.webp"
youtube = "MynhR1bMtWY"
youtube_upload_date="2021-07-08"
youtube_thumbnail="https://i.ytimg.com/vi/MynhR1bMtWY/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/718.webp" 
    alt="An array where the longest repeated subarray is highlighted and softly glowing as it's determined."
    caption="Solution to LeetCode 718: Maximum Length of Repeated Subarray Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given two integer arrays `nums1` and `nums2`, your task is to find the maximum length of a contiguous subarray that appears in both arrays.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two arrays `nums1` and `nums2` of integers.
- **Example:** `nums1 = [4, 5, 6, 7, 8], nums2 = [1, 2, 3, 4, 5]`
- **Constraints:**
	- 1 <= nums1.length, nums2.length <= 1000
	- 0 <= nums1[i], nums2[i] <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum length of a contiguous subarray that appears in both `nums1` and `nums2`.
- **Example:** `2`
- **Constraints:**
	- The result should be a non-negative integer representing the length of the longest common subarray.

{{< dots >}}
### Core Logic 🔍
**Goal:** To compute the maximum length of a contiguous subarray that appears in both arrays using dynamic programming.

- Create a 2D array `dp` where `dp[i][j]` represents the length of the longest common subarray ending at `nums1[i-1]` and `nums2[j-1]`.
- If `nums1[i-1] == nums2[j-1]`, then `dp[i][j] = dp[i-1][j-1] + 1`.
- Track the maximum value in the `dp` array during the iteration.
{{< dots >}}
### Problem Assumptions ✅
- The input arrays will contain non-negative integers.
- The length of the arrays is guaranteed to be at least 1.
{{< dots >}}
## Examples 🧩
- **Input:** `nums1 = [4, 5, 6, 7, 8], nums2 = [1, 2, 3, 4, 5]`  \
  **Explanation:** The longest common subarray is [4, 5], which has a length of 2.

- **Input:** `nums1 = [1, 2, 3, 4], nums2 = [2, 3, 4, 5]`  \
  **Explanation:** The longest common subarray is [2, 3, 4], which has a length of 3.

{{< dots >}}
## Approach 🚀
The problem can be solved using dynamic programming to efficiently calculate the longest common subarray.

### Initial Thoughts 💭
- We need to keep track of the common subarrays between `nums1` and `nums2`.
- Dynamic programming will help us store the results of overlapping subproblems and avoid redundant calculations.
{{< dots >}}
### Edge Cases 🌐
- If one of the arrays is empty, the result should be 0.
- Ensure that the solution works efficiently for large arrays with lengths up to 1000.
- Handle cases where all elements in the arrays are the same.
- Handle cases where no common subarray exists, in which case the result will be 0.
{{< dots >}}
## Code 💻
```cpp
int findLength(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size(), n2 = nums2.size();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1));

    for(int i = 0; i < n1 + 1; i++) dp[i][0] = 0;
    for(int i = 0; i < n2 + 1; i++) dp[0][i] = 0;
    // dp[0][0] = 0;

    // subseq - !subarr
    int mx = 0;
    for(int i = 1; i < n1 + 1; i++)
    for(int j = 1; j < n2 + 1; j++) {
        if (nums1[i - 1] == nums2[j - 1]) {
             dp[i][j] = dp[i - 1][j - 1] + 1;
            mx = max(mx, dp[i][j]);
        }
    }
    return mx;
}
```

The function finds the maximum length of a common subarray between two given arrays. It uses dynamic programming to build a table where each entry stores the length of the common subarray ending at that index.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int findLength(vector<int>& nums1, vector<int>& nums2) {
	```
	Define the function 'findLength' that takes two vectors of integers 'nums1' and 'nums2' and returns an integer representing the maximum length of a common subarray.

2. **Variable Initialization**
	```cpp
	    int n1 = nums1.size(), n2 = nums2.size();
	```
	Initialize two variables, 'n1' and 'n2', to store the sizes of 'nums1' and 'nums2', respectively.

3. **Array Initialization**
	```cpp
	    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1));
	```
	Initialize a 2D vector 'dp' with dimensions (n1+1) by (n2+1), where each entry will store the length of the common subarray ending at that position.

4. **Base Case Initialization**
	```cpp
	
	```
	Base cases for dynamic programming are initialized in the following steps. The first row and first column of the DP table will be set to zero.

5. **Filling DP Table - Row Initialization**
	```cpp
	    for(int i = 0; i < n1 + 1; i++) dp[i][0] = 0;
	```
	Set the first column of the DP table to zero since there is no common subarray with an empty second array.

6. **Filling DP Table - Column Initialization**
	```cpp
	    for(int i = 0; i < n2 + 1; i++) dp[0][i] = 0;
	```
	Set the first row of the DP table to zero since there is no common subarray with an empty first array.

7. **Comment**
	```cpp
	    // dp[0][0] = 0;
	```
	This line is a redundant initialization since dp[0][0] is already set to 0 in the previous loops.

8. **Dynamic Programming Loop Start**
	```cpp
	    int mx = 0;
	```
	Initialize 'mx' to store the maximum length of the common subarray found during the iterations.

9. **Outer Loop - Iterating Over nums1**
	```cpp
	    for(int i = 1; i < n1 + 1; i++)
	```
	Start the outer loop to iterate over each element of 'nums1', from index 1 to n1.

10. **Inner Loop - Iterating Over nums2**
	```cpp
	    for(int j = 1; j < n2 + 1; j++) {
	```
	Start the inner loop to iterate over each element of 'nums2', from index 1 to n2.

11. **Condition Check - Matching Elements**
	```cpp
	        if (nums1[i - 1] == nums2[j - 1]) {
	```
	Check if the elements at the current indices of 'nums1' and 'nums2' match. If they do, the common subarray is extended.

12. **DP Update - Matching Elements**
	```cpp
	             dp[i][j] = dp[i - 1][j - 1] + 1;
	```
	If the elements match, update the DP table by adding 1 to the value from the previous diagonal entry, representing the length of the common subarray ending at that point.

13. **Max Length Update**
	```cpp
	            mx = max(mx, dp[i][j]);
	```
	Update 'mx' to store the maximum length of the common subarray found so far.

14. **Return Maximum Length**
	```cpp
	    return mx;
	```
	Return the maximum length of the common subarray found, stored in 'mx'.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n1 * n2)
- **Average Case:** O(n1 * n2)
- **Worst Case:** O(n1 * n2)

The time complexity is quadratic due to the two nested loops iterating over both arrays.

### Space Complexity 💾
- **Best Case:** O(n1 * n2)
- **Worst Case:** O(n1 * n2)

The space complexity is quadratic because we are using a 2D array to store the results.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-length-of-repeated-subarray/description/)

---
{{< youtube MynhR1bMtWY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

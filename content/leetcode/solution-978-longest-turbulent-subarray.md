
+++
authors = ["grid47"]
title = "Leetcode 978: Longest Turbulent Subarray"
date = "2024-08-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 978: Longest Turbulent Subarray in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "V_iHUhR8Dek"
youtube_upload_date="2023-02-25"
youtube_thumbnail="https://i.ytimg.com/vi_webp/V_iHUhR8Dek/maxresdefault.webp"
comments = true
+++



---
Given an integer array arr, return the length of the largest subarray that is turbulent. A subarray is considered turbulent if the comparison sign alternates between each adjacent pair of elements.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** An integer array arr.
- **Example:** `arr = [5, 3, 8, 10, 2, 7, 9]`
- **Constraints:**
	- 1 <= arr.length <= 4 * 10^4
	- 0 <= arr[i] <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** The length of the largest turbulent subarray of arr.
- **Example:** `5`
- **Constraints:**
	- The length of the subarray should be at least 1.

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the longest turbulent subarray by tracking the alternating comparisons between adjacent elements.

- Use a dynamic programming approach with two states to track alternating comparisons.
- Maintain a variable to store the maximum length of the turbulent subarray encountered so far.
- Iterate through the array to detect and extend the turbulent subarrays.
{{< dots >}}
### Problem Assumptions ✅
- The array has at least one element.
{{< dots >}}
## Examples 🧩
- **Input:** `arr = [5, 3, 8, 10, 2, 7, 9]`  \
  **Explanation:** The longest turbulent subarray is [3, 8, 10, 2, 7], where comparisons alternate as expected.

- **Input:** `arr = [1, 2, 3, 4, 5]`  \
  **Explanation:** The longest turbulent subarray is [1, 2], where the comparison alternates once.

{{< dots >}}
## Approach 🚀
Use a dynamic programming approach to keep track of alternating comparison states and find the longest turbulent subarray.

### Initial Thoughts 💭
- The comparison between adjacent elements alternates between greater than and less than.
- A dynamic programming approach with two states will help efficiently solve the problem.
{{< dots >}}
### Edge Cases 🌐
- An empty input array should return 0.
- Large arrays with up to 40,000 elements should be processed efficiently.
- Single-element arrays, which are trivially turbulent with a length of 1.
- The input array must contain at least one element.
{{< dots >}}
## Code 💻
```cpp
int maxTurbulenceSize(vector<int>& arr) {

    vector<int> dp(2, 1);
    
    int res = 1, n = arr.size(), prv = 0;

    for(int i = 1; i < n; i++) {

        if ((prv == 0 || prv == -1) && arr[i - 1] < arr[i] ) {
            dp[0] = dp[1] + 1;
            res = max(res, dp[0]);
            prv = 1;
        } else if ((prv == 0 || prv == 1) && arr[i - 1] > arr[i] ) {
            dp[1] = dp[0] + 1;
            res = max(res, dp[1]);
            prv = -1;
        }
        else if (arr[i - 1] == arr[i] ) {
            dp[0] = 1;
            dp[1] = 1;
            prv = 0;
        } else {
            dp[0] = 2;
            dp[1] = 2;
            prv = (arr[i - 1] < arr[i]) ? 1 : -1;
        }
    }
    
    return res;
}
```

This function finds the maximum size of a turbulent subarray in the given integer array `arr`. A turbulent subarray is a subarray where the elements alternate between being greater and smaller than their neighbors. The function uses dynamic programming to track the lengths of the turbulent subarrays.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int maxTurbulenceSize(vector<int>& arr) {
	```
	Defines the function `maxTurbulenceSize` which takes a reference to a vector of integers `arr` and returns an integer representing the length of the maximum turbulent subarray.

2. **Dynamic Programming Initialization**
	```cpp
	    vector<int> dp(2, 1);
	```
	Initializes a dynamic programming array `dp` of size 2, with both elements set to 1, which will be used to track the length of the turbulent subarrays. The two values represent the lengths of the turbulent subarrays ending in an increasing or decreasing manner.

3. **Variable Initialization**
	```cpp
	    int res = 1, n = arr.size(), prv = 0;
	```
	Initializes the result variable `res` to 1 (the minimum possible length of a turbulent subarray), `n` to the size of the input array `arr`, and `prv` to 0 (representing the previous comparison state).

4. **Loop Initialization**
	```cpp
	    for(int i = 1; i < n; i++) {
	```
	Starts a loop that iterates through the array from the second element (index 1) to the last element. This loop will check each pair of adjacent elements to determine if they form a turbulent subarray.

5. **Increasing Comparison**
	```cpp
	        if ((prv == 0 || prv == -1) && arr[i - 1] < arr[i] ) {
	```
	Checks if the previous state was either 0 (initial state) or -1 (decreasing), and if the current pair is increasing (i.e., `arr[i - 1] < arr[i]`). If true, the current subarray can continue as turbulent in an increasing direction.

6. **Update DP for Increasing**
	```cpp
	            dp[0] = dp[1] + 1;
	```
	Updates the length of the turbulent subarray ending in an increasing direction by incrementing the length of the turbulent subarray that was previously decreasing.

7. **Update Result for Increasing**
	```cpp
	            res = max(res, dp[0]);
	```
	Updates the result `res` to the maximum value between the current result and the newly calculated length of the increasing turbulent subarray.

8. **Set Previous State to Increasing**
	```cpp
	            prv = 1;
	```
	Sets the previous state `prv` to 1, indicating that the last comparison was an increasing one.

9. **Decreasing Comparison**
	```cpp
	        } else if ((prv == 0 || prv == 1) && arr[i - 1] > arr[i] ) {
	```
	Checks if the previous state was either 0 (initial state) or 1 (increasing), and if the current pair is decreasing (i.e., `arr[i - 1] > arr[i]`). If true, the current subarray can continue as turbulent in a decreasing direction.

10. **Update DP for Decreasing**
	```cpp
	            dp[1] = dp[0] + 1;
	```
	Updates the length of the turbulent subarray ending in a decreasing direction by incrementing the length of the turbulent subarray that was previously increasing.

11. **Update Result for Decreasing**
	```cpp
	            res = max(res, dp[1]);
	```
	Updates the result `res` to the maximum value between the current result and the newly calculated length of the decreasing turbulent subarray.

12. **Set Previous State to Decreasing**
	```cpp
	            prv = -1;
	```
	Sets the previous state `prv` to -1, indicating that the last comparison was a decreasing one.

13. **Handle Equal Adjacent Elements**
	```cpp
	        else if (arr[i - 1] == arr[i] ) {
	```
	Checks if the current and previous elements are equal. If true, the turbulent subarray ends, and the dynamic programming states are reset.

14. **Reset DP for Equal Elements**
	```cpp
	            dp[0] = 1;
	```
	Resets both dynamic programming values to 1, as the turbulent subarray must start fresh.

15. **Reset DP for Equal Elements**
	```cpp
	            dp[1] = 1;
	```
	Resets the second dynamic programming value to 1 as well, ensuring the subarray starts over.

16. **Reset Previous State**
	```cpp
	            prv = 0;
	```
	Resets the previous state `prv` to 0, indicating no trend (increasing or decreasing).

17. **Handle New Trend**
	```cpp
	        } else {
	```
	Handles the case where the adjacent elements form a new trend (either increasing or decreasing).

18. **Start New Turbulent Subarray**
	```cpp
	            dp[0] = 2;
	```
	Starts a new turbulent subarray with a length of 2.

19. **Start New Turbulent Subarray**
	```cpp
	            dp[1] = 2;
	```
	Starts a new turbulent subarray with a length of 2 in the decreasing direction.

20. **Update Previous State**
	```cpp
	            prv = (arr[i - 1] < arr[i]) ? 1 : -1;
	```
	Sets the previous state `prv` to 1 (increasing) or -1 (decreasing) depending on the comparison between `arr[i - 1]` and `arr[i]`.

21. **Return Result**
	```cpp
	    return res;
	```
	Returns the length of the longest turbulent subarray found.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The solution iterates through the array once, leading to a time complexity of O(n).

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) as we only store a few variables for tracking the current and maximum subarray lengths.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/longest-turbulent-subarray/description/)

---
{{< youtube V_iHUhR8Dek >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

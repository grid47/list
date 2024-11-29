
+++
authors = ["grid47"]
title = "Leetcode 300: Longest Increasing Subsequence"
date = "2024-10-08"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 300: Longest Increasing Subsequence in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/300.webp"
youtube = "VZc93A5v1JI"
youtube_upload_date="2023-07-01"
youtube_thumbnail="https://i.ytimg.com/vi/VZc93A5v1JI/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/300.webp" 
    alt="A series of numbers gently connecting to form the longest increasing subsequence, glowing brightly along the way."
    caption="Solution to LeetCode 300: Longest Increasing Subsequence Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given an integer array 'nums', find the length of the longest strictly increasing subsequence. A subsequence is a sequence derived by deleting some elements without changing the order of the remaining elements.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is an array of integers, where the length of the array can be between 1 and 2500, and the values range from -10^4 to 10^4.
- **Example:** `nums = [10, 9, 2, 5, 3, 7, 101, 18]`
- **Constraints:**
	- 1 <= nums.length <= 2500
	- -10^4 <= nums[i] <= 10^4

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is the length of the longest strictly increasing subsequence.
- **Example:** `For nums = [10, 9, 2, 5, 3, 7, 101, 18], the output is 4.`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** To find the length of the longest strictly increasing subsequence in the array.

- Initialize a dp array to store the length of the longest subsequence ending at each index.
- Iterate through the array, comparing each element with previous elements to update the dp array.
- Return the maximum value from the dp array as the length of the longest subsequence.
{{< dots >}}
### Problem Assumptions ✅
- The solution should account for the possibility of duplicate values in the array.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [10, 9, 2, 5, 3, 7, 101, 18]`  \
  **Explanation:** The longest increasing subsequence is [2, 3, 7, 101], and its length is 4.

- **Input:** `nums = [0, 1, 0, 3, 2, 3]`  \
  **Explanation:** The longest increasing subsequence is [0, 1, 2, 3], and its length is 4.

- **Input:** `nums = [7, 7, 7, 7, 7, 7, 7]`  \
  **Explanation:** Since all the elements are the same, the longest increasing subsequence has a length of 1.

{{< dots >}}
## Approach 🚀
To solve this problem, we need to find the length of the longest increasing subsequence using dynamic programming (DP). We will use a DP array to store the length of the longest subsequence at each index.

### Initial Thoughts 💭
- A dynamic programming approach is ideal for this problem as we can build the solution incrementally.
- To optimize, we can reduce the time complexity by using a binary search approach, which helps in finding the longest subsequence in O(n log n) time.
{{< dots >}}
### Edge Cases 🌐
- If the array is empty, the result should be 0.
- The algorithm should be optimized to handle arrays up to 2500 elements efficiently.
- If the array contains only one element, the longest increasing subsequence has a length of 1.
- Make sure to implement the solution within the O(n log n) time complexity to handle large inputs.
{{< dots >}}
## Code 💻
```cpp
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size(), mx = 1;
    vector<int> dp(n, 1);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++)
            if(nums[j] < nums[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
                mx = max(mx, dp[i]);
            }
    }
    return mx;
}
```

This function calculates the length of the longest increasing subsequence (LIS) in a given array using dynamic programming.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int lengthOfLIS(vector<int>& nums) {
	```
	Defines the function `lengthOfLIS`, which computes the length of the longest increasing subsequence in the given vector `nums`.

2. **Initialize Variables**
	```cpp
	    int n = nums.size(), mx = 1;
	```
	Initializes the size of the input array `n` and the variable `mx` to track the length of the longest increasing subsequence.

3. **Initialize DP Array**
	```cpp
	    vector<int> dp(n, 1);
	```
	Creates a dynamic programming array `dp` where each element is initialized to 1, representing the length of the longest increasing subsequence ending at that index.

4. **Outer Loop - Iterating Through Array**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Begins the outer loop, which iterates through each element of the array `nums`.

5. **Inner Loop - Comparing Elements**
	```cpp
	        for(int j = 0; j < i; j++)
	```
	Starts the inner loop to compare each element `nums[j]` with `nums[i]` to check if an increasing subsequence can be extended.

6. **Check for Increasing Subsequence**
	```cpp
	            if(nums[j] < nums[i]) {
	```
	Checks if the element at index `j` is smaller than the element at index `i`. If true, this means `nums[i]` can extend the subsequence ending at `nums[j]`.

7. **Update DP Array**
	```cpp
	                dp[i] = max(dp[i], dp[j] + 1);
	```
	Updates the `dp[i]` value, taking the maximum of the current value and the value of `dp[j] + 1`, indicating that `nums[i]` extends the subsequence ending at `nums[j]`.

8. **Track Maximum LIS Length**
	```cpp
	                mx = max(mx, dp[i]);
	```
	Updates the `mx` variable to store the length of the longest subsequence found so far.

9. **End Outer Loop**
	```cpp
	    }
	```
	Ends the outer loop after iterating through all elements in the array `nums`.

10. **Return Result**
	```cpp
	    return mx;
	```
	Returns the value of `mx`, which holds the length of the longest increasing subsequence found.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n^2)

In the best case, the time complexity is O(n log n), achieved using binary search. The worst case is O(n^2) with a dynamic programming approach.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n), where n is the size of the input array, due to the space used for the DP array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/longest-increasing-subsequence/description/)

---
{{< youtube VZc93A5v1JI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

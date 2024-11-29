
+++
authors = ["grid47"]
title = "Leetcode 3101: Count Alternating Subarrays"
date = "2024-01-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3101: Count Alternating Subarrays in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "EZSNwFnWaV8"
youtube_upload_date="2024-03-31"
youtube_thumbnail="https://i.ytimg.com/vi_webp/EZSNwFnWaV8/maxresdefault.webp"
comments = true
+++



---
You are given a binary array nums. A subarray is called alternating if no two adjacent elements in the subarray have the same value. Return the total number of alternating subarrays in the given binary array.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a binary array nums of length n.
- **Example:** `nums = [0, 1, 1, 0]`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- nums[i] is either 0 or 1

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the total number of alternating subarrays in the binary array nums.
- **Example:** `Output: 6`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Count all possible alternating subarrays in the given binary array.

- 1. Initialize a dynamic programming array to store the lengths of alternating subarrays.
- 2. Iterate through the array, and for each element, calculate the length of the alternating subarray ending at that element.
- 3. Add the length of the alternating subarray to the result for each element.
{{< dots >}}
### Problem Assumptions ✅
- The input will always consist of a valid binary array of size between 1 and 100,000.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [0, 1, 1, 0]`  \
  **Explanation:** The alternating subarrays are: [0], [1], [0, 1], [1], [1, 0], and [0], which gives a total of 6.

- **Input:** `nums = [1, 0, 1, 0, 1]`  \
  **Explanation:** All subarrays in this binary array are alternating, resulting in 15 alternating subarrays.

{{< dots >}}
## Approach 🚀
To solve this problem, we can use dynamic programming to keep track of the lengths of alternating subarrays as we iterate through the input array.

### Initial Thoughts 💭
- The problem is related to counting alternating subarrays, which can be efficiently done by storing the length of each alternating subarray.
- We can use dynamic programming to store the lengths of alternating subarrays and calculate the result in linear time.
{{< dots >}}
### Edge Cases 🌐
- The input will always contain at least one element (nums.length >= 1).
- The solution should efficiently handle arrays with up to 100,000 elements.
- When the array contains only one element, the only possible alternating subarray is the element itself.
- The solution must run efficiently within the input constraints (1 <= nums.length <= 10^5).
{{< dots >}}
## Code 💻
```cpp
long long countAlternatingSubarrays(vector<int>& nums) {
    int n = nums.size();
    vector<long long> dp(n, 0);
    dp[0] = 1;
    long long res = 1;
    for(int i = 1; i < n; i++) {
        dp[i] = nums[i] == nums[i - 1]? 1: dp[i - 1] + 1;
        // cout << dp[i];
        res += dp[i];
    }
    return res;
}
```

This function calculates the number of alternating subarrays in a given vector of integers. It uses dynamic programming (dp) to track the length of alternating subarrays and accumulates the results to return the total count.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	long long countAlternatingSubarrays(vector<int>& nums) {
	```
	Defines the function `countAlternatingSubarrays` that takes a vector of integers `nums` and returns the total number of alternating subarrays.

2. **Variable Initialization**
	```cpp
	    int n = nums.size();
	```
	Initializes `n` to the size of the input vector `nums`, representing the number of elements in the array.

3. **Variable Initialization**
	```cpp
	    vector<long long> dp(n, 0);
	```
	Creates a dynamic programming array `dp` of size `n`, initializing all values to 0. This array will store the length of alternating subarrays ending at each position.

4. **Base Case Initialization**
	```cpp
	    dp[0] = 1;
	```
	Sets the first element of the `dp` array to 1, representing the base case where the first element is an alternating subarray of length 1.

5. **Variable Initialization**
	```cpp
	    long long res = 1;
	```
	Initializes `res` to 1, which will accumulate the total number of alternating subarrays.

6. **For Loop Setup**
	```cpp
	    for(int i = 1; i < n; i++) {
	```
	Begins a `for` loop starting from index 1, iterating through the array to calculate the length of alternating subarrays ending at each position.

7. **DP Calculation**
	```cpp
	        dp[i] = nums[i] == nums[i - 1]? 1: dp[i - 1] + 1;
	```
	For each element, checks if it is equal to the previous one. If so, sets `dp[i]` to 1 (indicating the start of a new subarray); otherwise, increments `dp[i]` by 1 to extend the alternating subarray.

8. **Accumulating Results**
	```cpp
	        res += dp[i];
	```
	Adds `dp[i]` to `res`, accumulating the total number of alternating subarrays.

9. **Return Statement**
	```cpp
	    return res;
	```
	Returns the total count of alternating subarrays stored in `res`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the length of the input array. This is because we iterate through the array once, performing constant-time operations.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n) due to the dynamic programming array used to store the lengths of alternating subarrays.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/count-alternating-subarrays/description/)

---
{{< youtube EZSNwFnWaV8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

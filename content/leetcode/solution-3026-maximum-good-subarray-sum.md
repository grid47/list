
+++
authors = ["grid47"]
title = "Leetcode 3026: Maximum Good Subarray Sum"
date = "2024-01-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3026: Maximum Good Subarray Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "v-IFLS8-Haw"
youtube_upload_date="2024-02-03"
youtube_thumbnail="https://i.ytimg.com/vi_webp/v-IFLS8-Haw/maxresdefault.webp"
comments = true
+++



---
You are given an array `nums` of length `n` and a positive integer `k`. A subarray is called good if the absolute difference between its first and last element is exactly `k`. The task is to return the maximum sum of any good subarray of `nums`. If no such subarray exists, return 0.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array `nums` of integers and a positive integer `k`.
- **Example:** `nums = [5, 7, 1, 9, 3], k = 4`
- **Constraints:**
	- 2 <= nums.length <= 10^5
	- -10^9 <= nums[i] <= 10^9
	- 1 <= k <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum sum of any good subarray in `nums` where the absolute difference between the first and last element is exactly `k`. If no good subarray exists, return 0.
- **Example:** `Output: 16`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the maximum sum of a subarray where the absolute difference between the first and last element is exactly `k`.

- Initialize a variable `ans` to store the maximum sum.
- Use a map to store the last occurrence index of each element.
- Use prefix sum to track cumulative sums while checking for good subarrays.
- For each element, check if the absolute difference between the first and last element is equal to `k`, then compute the sum of that subarray and update `ans`.
{{< dots >}}
### Problem Assumptions ✅
- The array will always have at least two elements.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [5, 7, 1, 9, 3], k = 4`  \
  **Explanation:** The good subarrays are: [5, 7, 1], [7, 1, 9], and [1, 9, 3]. The maximum subarray sum is 16 for the subarray [7, 1, 9].

- **Input:** `Input: nums = [-3, -6, -4, -8], k = 2`  \
  **Explanation:** The good subarrays are: [-3, -6, -4], and [-6, -4, -8]. The maximum subarray sum is -13 for the subarray [-3, -6, -4].

{{< dots >}}
## Approach 🚀
We can solve this problem by iterating through the array, tracking the prefix sums, and checking if the difference between the first and last elements of each subarray matches `k`. We use a map to store the last occurrence of elements and compute the sum dynamically.

### Initial Thoughts 💭
- We need to track the prefix sums of subarrays while checking for the difference `k` between the first and last elements.
- A prefix sum approach allows for efficient subarray sum calculations, and a map helps track the last seen element for quick lookups.
{{< dots >}}
### Edge Cases 🌐
- The input array will always have at least two elements, so we don't need to handle empty inputs.
- Ensure the solution works efficiently for large arrays with a size of up to 100,000 elements.
- Consider cases where the array elements are large or negative.
- The constraints ensure that the array will always have a size between 2 and 100,000.
{{< dots >}}
## Code 💻
```cpp
long long maximumSubarraySum(vector<int>& nums, int k) {

    long long ans = LLONG_MIN;

    int n = nums.size();
    map<int, int> mp;
    vector<long long> pre;
    pre.push_back(0);
    for(int i = 0; i < n; i++) {
        pre.push_back(pre.back() + nums[i]);
        if(mp.count(nums[i] - k)) ans = max(ans, pre[i + 1] - pre[mp[nums[i] - k]]);
        if(mp.count(nums[i] + k)) ans = max(ans, pre[i + 1] - pre[mp[nums[i] + k]]);
        auto it = mp.find(nums[i]);
        if(it == mp.end() || pre[i] - pre[it->second] <= 0) mp[nums[i]] = i;
    }
    return ans == LLONG_MIN? 0: ans;
}
```

This function computes the maximum subarray sum for which the difference between two elements is exactly `k`. It uses prefix sums to optimize the search for the desired subarray sums.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	long long maximumSubarraySum(vector<int>& nums, int k) {
	```
	Defines the function `maximumSubarraySum` that takes a vector of integers `nums` and an integer `k` as input. It returns the maximum subarray sum such that the difference between two elements is `k`.

2. **Initialize Answer Variable**
	```cpp
	    long long ans = LLONG_MIN;
	```
	Initializes the variable `ans` to hold the maximum subarray sum found, starting with the smallest possible value (`LLONG_MIN`) to ensure any subarray sum will be larger.

3. **Get Size of Input**
	```cpp
	    int n = nums.size();
	```
	Stores the size of the input array `nums` in the variable `n`.

4. **Initialize Frequency Map**
	```cpp
	    map<int, int> mp;
	```
	Initializes a map `mp` to store the index of previously encountered values in the array `nums`.

5. **Initialize Prefix Sum Array**
	```cpp
	    vector<long long> pre;
	```
	Declares a vector `pre` to store the prefix sum of the elements in `nums`.

6. **Add Initial Prefix Sum**
	```cpp
	    pre.push_back(0);
	```
	Adds the initial value `0` to the `pre` vector to represent the prefix sum before the first element.

7. **Loop Over Array**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Begins a loop that iterates over each element `i` in the array `nums`.

8. **Update Prefix Sum**
	```cpp
	        pre.push_back(pre.back() + nums[i]);
	```
	Calculates the prefix sum by adding the current element `nums[i]` to the previous prefix sum (`pre.back()`), and stores it in the `pre` vector.

9. **Check for Subarray with Difference -k**
	```cpp
	        if(mp.count(nums[i] - k)) ans = max(ans, pre[i + 1] - pre[mp[nums[i] - k]]);
	```
	Checks if a subarray exists with the difference between elements equal to `k` (i.e., `nums[i] - k`). If so, updates `ans` with the maximum subarray sum found.

10. **Check for Subarray with Difference +k**
	```cpp
	        if(mp.count(nums[i] + k)) ans = max(ans, pre[i + 1] - pre[mp[nums[i] + k]]);
	```
	Checks if a subarray exists with the difference between elements equal to `+k` (i.e., `nums[i] + k`). If so, updates `ans` with the maximum subarray sum found.

11. **Find Element in Map**
	```cpp
	        auto it = mp.find(nums[i]);
	```
	Attempts to find the index of the current element `nums[i]` in the map `mp`.

12. **Update Map with New Element**
	```cpp
	        if(it == mp.end() || pre[i] - pre[it->second] <= 0) mp[nums[i]] = i;
	```
	If the element `nums[i]` is not found in the map or if its prefix sum is non-positive, updates the map with the current index `i` of `nums[i]`.

13. **Return Result**
	```cpp
	    return ans == LLONG_MIN? 0: ans;
	```
	Returns the final result: if no valid subarray was found (`ans == LLONG_MIN`), returns 0, otherwise returns the maximum subarray sum found.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), as we only iterate through the array once while performing constant-time operations for each element.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage of the prefix sum array and the map to track the last occurrences of elements.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-good-subarray-sum/description/)

---
{{< youtube v-IFLS8-Haw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

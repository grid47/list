
+++
authors = ["grid47"]
title = "Leetcode 523: Continuous Subarray Sum"
date = "2024-09-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 523: Continuous Subarray Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Math","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/523.webp"
youtube = "OKcrLfR-8mE"
youtube_upload_date="2022-03-06"
youtube_thumbnail="https://i.ytimg.com/vi_webp/OKcrLfR-8mE/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/523.webp" 
    alt="An array where the sum of a continuous subarray is highlighted with glowing elements."
    caption="Solution to LeetCode 523: Continuous Subarray Sum Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given an integer array nums and an integer k, return true if there exists a good subarray, otherwise return false. A good subarray is defined as a subarray whose length is at least 2 and the sum of its elements is a multiple of k.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array of integers nums and an integer k.
- **Example:** `nums = [15, 5, 10, 20], k = 10`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- 0 <= nums[i] <= 10^9
	- 1 <= k <= 2^31 - 1

{{< dots >}}
### Output Specifications 📤
- **Output:** Return true if there exists a good subarray, otherwise return false.
- **Example:** `true, false`
- **Constraints:**
	- The output is a boolean value.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to check if there exists a subarray of length at least 2 whose sum is a multiple of k.

- 1. Use a running sum of elements while iterating through the array.
- 2. Compute the modulo of the sum with k at each step.
- 3. If the same modulo is encountered at a later index, the sum of the subarray between those two indices is a multiple of k.
- 4. Ensure that the length of the subarray is at least 2 before confirming it as a valid subarray.
{{< dots >}}
### Problem Assumptions ✅
- The input will always consist of valid integers and the array length will be within the given bounds.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [15, 5, 10, 20], k = 10`  \
  **Explanation:** The subarray [5, 10] has a sum of 15, which is a multiple of 10.

- **Input:** `nums = [5, 8, 3, 7], k = 7`  \
  **Explanation:** No subarray has a sum that is a multiple of 7.

- **Input:** `nums = [10, 5, 15, 10], k = 10`  \
  **Explanation:** The subarray [10, 5, 15, 10] has a sum of 40, which is a multiple of 10.

{{< dots >}}
## Approach 🚀
The approach uses a running sum with modulo to track possible subarrays. By using a map to store previous sums and their corresponding indices, we can efficiently check if a valid subarray exists.

### Initial Thoughts 💭
- Using the modulo operation allows us to easily check if the sum of elements in a subarray is a multiple of k.
- The solution can be optimized by keeping track of previous sums modulo k to avoid checking every possible subarray.
{{< dots >}}
### Edge Cases 🌐
- If the input array is empty or contains only one element, return false.
- The algorithm should be optimized for large inputs, with a time complexity of O(n).
- The value of k should be handled for large integers, especially when k is 1 or very large.
- The solution should handle up to 10^5 elements in the array efficiently.
{{< dots >}}
## Code 💻
```cpp
bool checkSubarraySum(vector<int>& nums, int k) {
    map<int, int> mp;
    mp[0] = -1;
    int sum = 0;
    for(int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        sum %= k;
        if (mp.count(sum))
        {
            if (i - mp[sum] > 1) 
                return true;
        }
        else mp[sum] = i;
    }
    return false;
}
```

This function checks if there is a contiguous subarray whose sum is divisible by `k`. It uses a map to store the remainder of the cumulative sum and checks if the same remainder is seen again with a sufficient gap between indices.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool checkSubarraySum(vector<int>& nums, int k) {
	```
	Defines the function `checkSubarraySum`, which takes an array `nums` and an integer `k` as inputs and returns a boolean indicating if a subarray sum is divisible by `k`.

2. **Variable Initialization**
	```cpp
	    map<int, int> mp;
	```
	Initializes a map `mp` to store the cumulative sum modulo `k` and the corresponding index.

3. **Edge Case Initialization**
	```cpp
	    mp[0] = -1;
	```
	Adds a base case to the map, setting the value `-1` for the key `0` to handle edge cases where the subarray starts at index 0.

4. **Variable Initialization**
	```cpp
	    int sum = 0;
	```
	Initializes the variable `sum` to 0, which will keep track of the cumulative sum of the elements in `nums`.

5. **Outer Loop**
	```cpp
	    for(int i = 0; i < nums.size(); i++) {
	```
	Starts a loop to iterate through each element of the array `nums`.

6. **Cumulative Sum Calculation**
	```cpp
	        sum += nums[i];
	```
	Adds the current element `nums[i]` to the cumulative sum `sum`.

7. **Modulo Operation**
	```cpp
	        sum %= k;
	```
	Takes the modulo of the cumulative sum with `k`, ensuring the sum remains within the bounds of `k`.

8. **Map Lookup**
	```cpp
	        if (mp.count(sum))
	```
	Checks if the cumulative sum modulo `k` has been seen before by looking it up in the map `mp`.

9. **Subarray Check**
	```cpp
	            if (i - mp[sum] > 1) 
	```
	Checks if the difference between the current index `i` and the index stored in `mp[sum]` is greater than 1, which ensures there is a valid subarray.

10. **Return True**
	```cpp
	                return true;
	```
	If a valid subarray is found, return `true` indicating the presence of a subarray whose sum is divisible by `k`.

11. **Map Insertion**
	```cpp
	        else mp[sum] = i;
	```
	If the cumulative sum modulo `k` is not found in the map, insert it along with the current index `i` into `mp`.

12. **Return False**
	```cpp
	    return false;
	```
	Returns `false` if no subarray whose sum is divisible by `k` is found.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the length of the array.
- **Average Case:** O(n), where n is the length of the array.
- **Worst Case:** O(n), where n is the length of the array.

In the worst case, we check each element once, resulting in linear time complexity.

### Space Complexity 💾
- **Best Case:** O(1), if no valid subarray exists and no map entries are used.
- **Worst Case:** O(n), where n is the number of elements in the array.

The space complexity is linear with respect to the number of elements, due to the map storing intermediate sums.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/continuous-subarray-sum/description/)

---
{{< youtube OKcrLfR-8mE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

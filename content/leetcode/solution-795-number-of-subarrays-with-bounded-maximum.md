
+++
authors = ["grid47"]
title = "Leetcode 795: Number of Subarrays with Bounded Maximum"
date = "2024-08-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 795: Number of Subarrays with Bounded Maximum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/795.webp"
youtube = "V8jAp1Zi1Os"
youtube_upload_date="2021-06-17"
youtube_thumbnail="https://i.ytimg.com/vi/V8jAp1Zi1Os/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/795.webp" 
    alt="A sequence of numbers where subarrays are counted with a bounded maximum, glowing softly as each valid subarray is found."
    caption="Solution to LeetCode 795: Number of Subarrays with Bounded Maximum Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given an integer array `nums` and two integers `left` and `right`, return the number of contiguous non-empty subarrays such that the maximum value in each subarray lies within the inclusive range [left, right].
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an integer array `nums` of size `n`, and two integers `left` and `right` that represent the range of valid maximum values for the subarrays.
- **Example:** `Input: nums = [1, 2, 3], left = 2, right = 3`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- 0 <= nums[i] <= 10^9
	- 0 <= left <= right <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an integer representing the number of valid subarrays where the maximum value lies within the range [left, right].
- **Example:** `Output: 4`
- **Constraints:**
	- The answer will always fit within a 32-bit integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to count all contiguous subarrays such that the maximum element in each subarray falls within the given range [left, right].

- Initialize a variable `ans` to keep track of the number of valid subarrays.
- Iterate through each element of `nums` while maintaining a variable `dp` to count valid subarrays ending at the current index.
- If the current element is less than `left`, add `dp` to `ans` since the subarray formed up to this element is valid.
- If the current element is greater than `right`, reset `dp` as this element and any subarray containing it are no longer valid.
- If the current element is within the range [left, right], calculate `dp` as the number of valid subarrays that can be formed with the current element and add it to `ans`.
{{< dots >}}
### Problem Assumptions ✅
- The array `nums` is non-empty and contains integers.
- The range [left, right] is valid and falls within the specified bounds.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [1, 2, 3], left = 2, right = 3`  \
  **Explanation:** There are four subarrays where the maximum element lies between 2 and 3: [2], [2, 3], [3], and [1, 2, 3].

- **Input:** `Input: nums = [2, 9, 2, 5, 6], left = 2, right = 8`  \
  **Explanation:** The valid subarrays are [2], [2, 9], [9], [2, 9, 2], [2, 9, 2, 5], [9, 2], and [2]. The total count is 7.

{{< dots >}}
## Approach 🚀
We can solve this problem by iterating through the array and using a sliding window approach to count valid subarrays. We keep track of the number of valid subarrays ending at each position using a dynamic programming approach.

### Initial Thoughts 💭
- We need an efficient way to count subarrays. A brute force approach could take too long.
- A sliding window approach combined with dynamic programming should work well here, as it allows us to track subarrays in constant time.
{{< dots >}}
### Edge Cases 🌐
- If `nums` is empty, the result should be 0.
- For large arrays, the solution should still be efficient enough to handle up to 10^5 elements.
- If all elements in the array are larger than `right`, no valid subarrays will exist.
- The array should be non-empty, and `left` and `right` should be valid integer values.
{{< dots >}}
## Code 💻
```cpp
int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
    
    int n = nums.size();
    
    int ans = 0, dp = 0, prv = -1;
    for(int i = 0; i < n; i++) {
        
        if(nums[i] < left)
            ans += dp;
            
        if(nums[i] > right) {
            dp = 0;
            prv = i;
        }
            
        if(nums[i] >= left && nums[i] <= right) {
            dp = i - prv;
            ans += dp;
        }
            
    }
    
    return ans;
}
```

This function calculates the number of subarrays with a bounded maximum in the range [left, right]. It iterates through the array, maintaining a count of subarrays that meet the conditions. The code uses a dynamic programming approach to handle this efficiently.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
	```
	Defines the function that calculates the number of subarrays with a bounded maximum.

2. **Initialize Variables**
	```cpp
	    
	```
	Prepare for the loop and initialize variables used for the calculation.

3. **Get Array Size**
	```cpp
	    int n = nums.size();
	```
	Calculates the size of the input array nums.

4. **Initialize Variables**
	```cpp
	    int ans = 0, dp = 0, prv = -1;
	```
	Initializes variables: ans for the result, dp for counting valid subarrays, and prv for tracking the previous index.

5. **Loop through Array**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Begins the iteration through the input array.

6. **Update Answer if Element is Less than Left**
	```cpp
	        if(nums[i] < left)
	```
	If the current element is less than the left bound, accumulate the result by adding the dynamic programming state.

7. **Add to Answer**
	```cpp
	            ans += dp;
	```
	Adds the value of dp to the answer if the current element is less than the left bound.

8. **Handle Element Greater than Right**
	```cpp
	        if(nums[i] > right) {
	```
	Checks if the current element exceeds the upper bound.

9. **Reset DP and Update Index**
	```cpp
	            dp = 0;
	```
	Resets the dynamic programming state to zero because no valid subarrays can end at this element.

10. **Update Previous Index**
	```cpp
	            prv = i;
	```
	Sets the previous index to the current one, which marks the new boundary for subarray calculations.

11. **Check if Element is in Range**
	```cpp
	        if(nums[i] >= left && nums[i] <= right) {
	```
	Checks if the current element is within the range [left, right].

12. **Update DP for Valid Element**
	```cpp
	            dp = i - prv;
	```
	Updates dp to represent the count of subarrays ending at the current element.

13. **Update Answer for Valid Subarray**
	```cpp
	            ans += dp;
	```
	Adds the number of valid subarrays (dp) to the total answer.

14. **Return Final Answer**
	```cpp
	    return ans;
	```
	Returns the final count of subarrays with bounded maximum values.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), when the array is small or when no valid subarrays exist.
- **Average Case:** O(n), since we are iterating through the array once.
- **Worst Case:** O(n), as we always process each element of the array once.

The time complexity is linear because we process each element of the array exactly once.

### Space Complexity 💾
- **Best Case:** O(1), as the space used is constant regardless of input size.
- **Worst Case:** O(1), since we only use a few variables for tracking counts and the solution does not use extra space proportional to the input size.

The space complexity is constant because we only use a fixed amount of additional memory.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/description/)

---
{{< youtube V8jAp1Zi1Os >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

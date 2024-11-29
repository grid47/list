
+++
authors = ["grid47"]
title = "Leetcode 53: Maximum Subarray"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 53: Maximum Subarray in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Divide and Conquer","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/53.webp"
youtube = "5WZl3MMT0Eg"
youtube_upload_date="2020-06-13"
youtube_thumbnail="https://i.ytimg.com/vi/5WZl3MMT0Eg/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/53.webp" 
    alt="A bright, uplifting wave rising, showing the peak of a series of numbers."
    caption="Solution to LeetCode 53: Maximum Subarray Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given an integer array `nums`, find the contiguous subarray (containing at least one number) that has the largest sum and return its sum.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a single integer array `nums`.
- **Example:** `["nums = [3, -2, 5, -1, 2]"]`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- -10^4 <= nums[i] <= 10^4

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a single integer, which is the largest sum of a contiguous subarray in the input array `nums`.
- **Example:** `["8"]`
- **Constraints:**
	- The sum of the subarray is guaranteed to be a valid integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the subarray with the maximum sum using an optimal solution.

- 1. Initialize two variables: `l` for the current subarray sum and `g` for the maximum sum found so far.
- 2. Iterate through the array and update `l` based on whether adding the current number increases the sum or not.
- 3. Update `g` to track the maximum subarray sum encountered during the iteration.
- 4. Return the value of `g`.
{{< dots >}}
### Problem Assumptions ✅
- The array `nums` will always contain at least one element.
- The solution needs to handle arrays with both positive and negative numbers.
{{< dots >}}
## Examples 🧩
- **Input:** `["nums = [3, -2, 5, -1, 2]"]`  \
  **Explanation:** In this example, the largest sum subarray is `[3, -2, 5, -1, 2]`, which gives a sum of `8`.

- **Input:** `["nums = [-3, 4, -1, 2, 1]"]`  \
  **Explanation:** Here, the largest sum subarray is `[4, -1, 2, 1]`, which gives a sum of `6`.

{{< dots >}}
## Approach 🚀
The approach uses a dynamic programming technique to find the largest sum subarray in linear time.

### Initial Thoughts 💭
- We can compute the maximum subarray sum efficiently by keeping track of the current sum and updating the maximum sum found so far.
- Kadane's Algorithm is the ideal approach to solve this problem in O(n) time.
{{< dots >}}
### Edge Cases 🌐
- The problem guarantees that the array will have at least one element.
- The solution must handle inputs with up to 10^5 elements efficiently.
- When all elements are negative, the solution should return the largest (least negative) number.
- The algorithm needs to work efficiently for both small and large arrays.
{{< dots >}}
## Code 💻
```cpp
int maxSubArray(vector<int>& nums) {
    int l = nums[0], g = nums[0];
    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] > l + nums[i])
            l = nums[i];
        else l += nums[i];
        
        g = max(g, l);
    }
    return g;
}
```

This code finds the contiguous subarray within an array of numbers which has the largest sum.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int maxSubArray(vector<int>& nums) {
	```
	This line declares a function named `maxSubArray` that takes a vector of integers `nums` as input and returns the maximum sum of a contiguous subarray.

2. **Variable Initialization**
	```cpp
	    int l = nums[0], g = nums[0];
	```
	This line initializes two integer variables: `l` to store the sum of the current contiguous subarray and `g` to store the global maximum sum. Both are initialized to the first element of the `nums` array.

3. **Iterate Over Array**
	```cpp
	    for(int i = 1; i < nums.size(); i++) {
	```
	This loop iterates over the elements of the `nums` array, starting from the second element.

4. **Check for New Subarray**
	```cpp
	        if(nums[i] > l + nums[i])
	```
	This condition checks if starting a new subarray at the current element `nums[i]` would yield a larger sum than continuing the previous subarray.

5. **Start New Subarray**
	```cpp
	            l = nums[i];
	```
	If the condition is true, the current element `nums[i]` becomes the new starting point for the subarray, and `l` is updated to its value.

6. **Continue Current Subarray**
	```cpp
	        else l += nums[i];
	```
	If the condition is false, it's more beneficial to continue the current subarray, so the current element `nums[i]` is added to the current sum `l`.

7. **Update Global Maximum**
	```cpp
	        g = max(g, l);
	```
	The global maximum sum `g` is updated to the maximum of its current value and the current subarray sum `l`.

8. **Return Global Maximum**
	```cpp
	    return g;
	```
	After iterating through the entire array, the function returns the final global maximum sum `g`, which represents the maximum sum of any contiguous subarray.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The algorithm iterates through the array exactly once, making the time complexity O(n).

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The solution uses a constant amount of space, so the space complexity is O(1).

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-subarray/description/)

---
{{< youtube 5WZl3MMT0Eg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

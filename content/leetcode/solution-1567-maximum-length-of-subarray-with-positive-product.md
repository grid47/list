
+++
authors = ["grid47"]
title = "Leetcode 1567: Maximum Length of Subarray With Positive Product"
date = "2024-06-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1567: Maximum Length of Subarray With Positive Product in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "bFer5PdsgpY"
youtube_upload_date="2020-09-01"
youtube_thumbnail="https://i.ytimg.com/vi/bFer5PdsgpY/maxresdefault.jpg"
comments = true
+++



---
Given an array of integers, your task is to find the maximum length of a contiguous subarray where the product of all its elements is positive. The product of a subarray is considered positive if the result of multiplying all elements of the subarray results in a positive number.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array of integers where each integer represents a value in the array. The goal is to find the longest subarray that has a positive product.
- **Example:** `Input: nums = [3,-1,-2,4,2]`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- -10^9 <= nums[i] <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the length of the longest subarray where the product of all its elements is positive.
- **Example:** `Output: 4`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to track the lengths of subarrays with positive products, adjusting the lengths based on whether the current element is positive, negative, or zero.

- Initialize variables to track the length of the subarray with positive and negative products.
- Iterate through the array and adjust the lengths of the subarrays based on the current value (positive, negative, or zero).
- Keep track of the maximum length of subarrays with positive products during the iteration.
{{< dots >}}
### Problem Assumptions ✅
- The input array nums is non-empty.
- A subarray can be an empty sequence, but we are interested in subarrays with a positive product.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: nums = [3,-1,-2,4,2]`  \
  **Explanation:** In this case, the longest subarray with a positive product is [3, -1, -2, 4], which has a product of 24. The length of this subarray is 4.

- **Input:** `Example 2: nums = [1,-2,-3,0,1]`  \
  **Explanation:** In this case, the longest subarray with a positive product is [-2, -3], which has a product of 6. The length of this subarray is 2.

- **Input:** `Example 3: nums = [0,1,-2,-3,-4]`  \
  **Explanation:** Here, the longest subarray with a positive product is [1, -2, -3], which has a product of 6. The length of this subarray is 3.

{{< dots >}}
## Approach 🚀
To solve the problem efficiently, the approach tracks the length of the longest subarray with a positive product while iterating over the array. We maintain two variables to track the lengths of subarrays with positive and negative products, adjusting them based on the sign of the current element.

### Initial Thoughts 💭
- The product of a subarray is positive if the number of negative elements in the subarray is even.
- A zero in the array will reset any product, as the product becomes zero.
- Using a dynamic approach to track both the positive and negative subarrays will allow us to efficiently find the longest subarray with a positive product.
{{< dots >}}
### Edge Cases 🌐
- The array will always have at least one element, so no need to handle empty arrays.
- The solution must handle large arrays efficiently, with up to 10^5 elements.
- Zero elements should be handled by resetting the positive and negative subarray lengths.
- Ensure the solution works within the time limits for large inputs.
{{< dots >}}
## Code 💻
```cpp
int getMaxLen(vector<int>& nums) {
    int ans = 0, positive = 0, negative = 0;
    for(int x : nums) {
        if (x == 0) {
            positive = 0;
            negative = 0;
        }
        else if (x > 0) {
            positive++;
            negative = negative == 0 ? 0 : negative + 1;
        }
        else {
            int tmp  = positive;
            positive = negative == 0 ? 0 : negative + 1;
            negative = tmp + 1;
        }
        ans = max(ans, positive);
    }
    return ans;
}
```

This function calculates the maximum length of a contiguous subarray with a positive product in a given array of integers.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int getMaxLen(vector<int>& nums) {
	```
	Defines the function `getMaxLen` which takes a vector `nums` representing a sequence of integers.

2. **Variable Initialization**
	```cpp
	    int ans = 0, positive = 0, negative = 0;
	```
	Initializes the variables `ans`, `positive`, and `negative`. `ans` stores the maximum length of subarray with positive product, while `positive` and `negative` track the length of positive and negative product subarrays, respectively.

3. **Loop Start**
	```cpp
	    for(int x : nums) {
	```
	Starts a loop that iterates through each element `x` in the input array `nums`.

4. **Zero Check**
	```cpp
	        if (x == 0) {
	```
	Checks if the current element is zero. A zero in the array breaks any product subarray, so both `positive` and `negative` are reset.

5. **Reset Variables**
	```cpp
	            positive = 0;
	```
	Resets the `positive` variable to zero, as a zero product subarray is reset.

6. **Reset Variables**
	```cpp
	            negative = 0;
	```
	Resets the `negative` variable to zero, as a zero product subarray is reset.

7. **Positive Number Check**
	```cpp
	        else if (x > 0) {
	```
	Checks if the current element `x` is greater than zero, which will increase the length of positive product subarrays.

8. **Positive Update**
	```cpp
	            positive++;
	```
	Increments the `positive` counter, as a positive number will extend any positive product subarray.

9. **Negative Update**
	```cpp
	            negative = negative == 0 ? 0 : negative + 1;
	```
	If `negative` is non-zero, it is incremented. Otherwise, it is reset to zero because a positive number cannot extend a negative product subarray.

10. **Negative Number Check**
	```cpp
	        else {
	```
	If the current element `x` is negative, it causes the positive and negative product subarrays to swap roles.

11. **Temporary Variable for Positive**
	```cpp
	            int tmp  = positive;
	```
	Stores the current value of `positive` in a temporary variable `tmp` to swap the roles of `positive` and `negative`.

12. **Negative Update**
	```cpp
	            positive = negative == 0 ? 0 : negative + 1;
	```
	Updates `positive` to `negative + 1`, or zero if `negative` is zero, as a negative number will convert a negative product subarray to a positive one.

13. **Positive Update**
	```cpp
	            negative = tmp + 1;
	```
	Updates `negative` to `tmp + 1`, which represents the previous positive subarray length plus one for the new negative number.

14. **Max Length Update**
	```cpp
	        ans = max(ans, positive);
	```
	Updates the maximum length `ans` by comparing it with the current value of `positive` to store the longest subarray with a positive product.

15. **Return**
	```cpp
	    return ans;
	```
	Returns the value of `ans`, which is the length of the longest contiguous subarray with a positive product.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because we iterate over the array exactly once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) since we only need a constant amount of extra space to store the current lengths of the subarrays.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/description/)

---
{{< youtube bFer5PdsgpY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |


+++
authors = ["grid47"]
title = "Leetcode 1749: Maximum Absolute Sum of Any Subarray"
date = "2024-05-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1749: Maximum Absolute Sum of Any Subarray in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "XVVB_ZXsbnI"
youtube_upload_date="2021-02-06"
youtube_thumbnail="https://i.ytimg.com/vi_webp/XVVB_ZXsbnI/maxresdefault.webp"
comments = true
+++



---
Given an array of integers `nums`, your task is to find the maximum absolute sum of any subarray. The absolute sum of a subarray is the absolute value of the sum of its elements.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array `nums` of size `n`.
- **Example:** `Input: nums = [1, -2, 3, 4, -1]`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- -10^4 <= nums[i] <= 10^4

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum absolute sum of any subarray of the given array.
- **Example:** `Output: 8`
- **Constraints:**
	- The answer should be the maximum possible absolute sum, even if the subarray is empty.

{{< dots >}}
### Core Logic 🔍
**Goal:** To find the maximum absolute sum of any subarray of the given array.

- 1. Keep track of the running sum for both positive and negative sums separately.
- 2. Calculate the maximum sum at each step and keep updating the result with the absolute value of the sum.
{{< dots >}}
### Problem Assumptions ✅
- There may be negative numbers in the array, so you need to handle both positive and negative sums.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [1, -3, 2, 3, -4]`  \
  **Explanation:** The subarray [2, 3] has an absolute sum of abs(2+3) = 5. This is the maximum absolute sum in the array.

- **Input:** `Input: nums = [2, -5, 1, -4, 3, -2]`  \
  **Explanation:** The subarray [-5, 1, -4] has an absolute sum of abs(-5+1-4) = abs(-8) = 8. This is the maximum absolute sum.

{{< dots >}}
## Approach 🚀
To solve this problem, we can iterate through the array and maintain the running sum for both positive and negative sums. At each step, we calculate the absolute value of the current sum and update the maximum absolute sum.

### Initial Thoughts 💭
- We need to track both positive and negative sums at each step to account for the maximum possible absolute sum.
- We don't need to keep track of the exact subarray, just the absolute value of the sum at each point.
- The problem can be solved by iterating through the array once, maintaining two variables: one for the maximum positive sum and one for the maximum negative sum.
{{< dots >}}
### Edge Cases 🌐
- If the array is empty, return 0 as no subarray exists.
- For large arrays, ensure the solution is optimized to run within time limits.
- If all elements are negative or all positive, the algorithm should still return the correct maximum absolute sum.
- Ensure that the solution works efficiently with inputs up to 10^5 elements.
{{< dots >}}
## Code 💻
```cpp
int maxAbsoluteSum(vector<int>& nums) {
    
    int global = 0, lx = 0, ln = 0;
    
    int n = nums.size();
    
    for(int i = 0; i < n; i++) {
        if(nums[i] > lx + nums[i])
            lx = nums[i];
        else lx += nums[i];

        if(nums[i] < ln + nums[i])
            ln = nums[i];
        else ln += nums[i];
        
        
        if(abs(lx) > global)
            global = abs(lx);
        if(abs(ln) > global)
            global = abs(ln);            
    }
    return global;
}
```

The `maxAbsoluteSum` function computes the maximum absolute sum of a subarray in the given vector `nums`. It maintains two variables, `lx` and `ln`, to track the maximum subarray sums that end with positive or negative values. It iterates through the array, updating these variables and the result `global` with the largest absolute value found.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int maxAbsoluteSum(vector<int>& nums) {
	```
	This defines the function `maxAbsoluteSum` which takes a reference to a vector of integers `nums` and returns the maximum absolute sum of any subarray.

2. **Variable Initialization**
	```cpp
	    int global = 0, lx = 0, ln = 0;
	```
	This line initializes three integer variables: `global` to store the largest absolute sum, `lx` for the maximum subarray sum with a positive or zero total, and `ln` for the maximum sum with a negative total.

3. **Size Calculation**
	```cpp
	    int n = nums.size();
	```
	This calculates the size of the input vector `nums` and stores it in the variable `n`.

4. **Main Loop**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	This loop iterates over each element in the vector `nums` to compute the maximum absolute sum of any subarray.

5. **Update Positive Subarray Sum**
	```cpp
	        if(nums[i] > lx + nums[i])
	```
	This checks if adding the current element `nums[i]` to `lx` would result in a smaller sum than just starting a new subarray with `nums[i]`. If true, it updates `lx` to the current element.

6. **Set Positive Subarray Sum**
	```cpp
	            lx = nums[i];
	```
	If the above condition is true, `lx` is set to the current element `nums[i]`, effectively starting a new subarray.

7. **Accumulate Positive Subarray Sum**
	```cpp
	        else lx += nums[i];
	```
	If the current element `nums[i]` is added to `lx`, the sum is updated to include it.

8. **Update Negative Subarray Sum**
	```cpp
	        if(nums[i] < ln + nums[i])
	```
	This checks if adding the current element `nums[i]` to `ln` would result in a smaller sum than just starting a new subarray with `nums[i]`. If true, it updates `ln` to the current element.

9. **Set Negative Subarray Sum**
	```cpp
	            ln = nums[i];
	```
	If the above condition is true, `ln` is set to the current element `nums[i]`, effectively starting a new subarray.

10. **Accumulate Negative Subarray Sum**
	```cpp
	        else ln += nums[i];
	```
	If the current element `nums[i]` is added to `ln`, the sum is updated to include it.

11. **Check Maximum Absolute Sum (Positive)**
	```cpp
	        if(abs(lx) > global)
	```
	This checks if the absolute value of the current positive subarray sum `lx` is larger than the current global maximum.

12. **Update Global Maximum (Positive)**
	```cpp
	            global = abs(lx);
	```
	If the condition is true, it updates the global maximum sum to the absolute value of `lx`.

13. **Check Maximum Absolute Sum (Negative)**
	```cpp
	        if(abs(ln) > global)
	```
	This checks if the absolute value of the current negative subarray sum `ln` is larger than the current global maximum.

14. **Update Global Maximum (Negative)**
	```cpp
	            global = abs(ln);            
	```
	If the condition is true, it updates the global maximum sum to the absolute value of `ln`.

15. **Return Maximum Sum**
	```cpp
	    return global;
	```
	The function returns the `global` variable, which holds the maximum absolute sum found.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), as we must iterate through the entire array.
- **Average Case:** O(n), as the running sum is updated in each iteration.
- **Worst Case:** O(n), since every element must be processed to find the maximum absolute sum.

The solution runs in linear time.

### Space Complexity 💾
- **Best Case:** O(1), since no extra space is required.
- **Worst Case:** O(1), since only a few variables are used to track the running sums.

The space complexity is constant, as the algorithm only requires a few variables.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/description/)

---
{{< youtube XVVB_ZXsbnI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

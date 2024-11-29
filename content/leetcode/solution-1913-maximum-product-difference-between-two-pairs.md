
+++
authors = ["grid47"]
title = "Leetcode 1913: Maximum Product Difference Between Two Pairs"
date = "2024-04-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1913: Maximum Product Difference Between Two Pairs in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sorting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "wBPoEm3r3EA"
youtube_upload_date="2023-12-18"
youtube_thumbnail="https://i.ytimg.com/vi_webp/wBPoEm3r3EA/maxresdefault.webp"
comments = true
+++



---
Given an integer array nums, your goal is to select four distinct indices w, x, y, and z such that the product difference between two pairs of numbers, (nums[w], nums[x]) and (nums[y], nums[z]), is maximized. The product difference is defined as (nums[w] * nums[x]) - (nums[y] * nums[z]). Return the maximum product difference between these two pairs.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array nums, where each element is a positive integer.
- **Example:** `nums = [5,6,2,7,4]`
- **Constraints:**
	- 4 <= nums.length <= 10^4
	- 1 <= nums[i] <= 10^4

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum product difference between the two pairs.
- **Example:** `34`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** To calculate the maximum product difference by finding the optimal pairs of elements.

- Identify the two largest elements in the array and the two smallest elements in the array.
- Calculate the product difference using these values: (max1 * max2) - (min1 * min2).
{{< dots >}}
### Problem Assumptions ✅
- The array has at least 4 elements, as the problem requires selecting four distinct indices.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [5,6,2,7,4]`  \
  **Explanation:** The maximum product difference is obtained by selecting indices 1 and 3 for the first pair (6, 7) and indices 2 and 4 for the second pair (2, 4). Thus, the product difference is (6 * 7) - (2 * 4) = 34.

{{< dots >}}
## Approach 🚀
To solve this problem, we need to identify the two largest and two smallest values in the array and then compute their product difference.

### Initial Thoughts 💭
- We need to find the largest and smallest elements efficiently.
- Using a single loop to identify the two largest and two smallest elements in the array would be the most efficient approach.
{{< dots >}}
### Edge Cases 🌐
- Handle cases where the input array has fewer than 4 elements, though this won't occur based on the problem constraints.
- Ensure that the solution works efficiently with arrays of size up to 10^4.
- Handle cases where all elements are the same or all are very large.
- Ensure that the solution handles the constraints efficiently.
{{< dots >}}
## Code 💻
```cpp
int maxProductDifference(vector<int>& nums) {
    //we have to return the result of
    // (firstMax*secondMax) - (firstMin*secondMin)
    int max1=INT_MIN;
    int max2=INT_MIN;
    int min1=INT_MAX;
    int min2=INT_MAX;
    for(int i=0;i<nums.size();i++)
    {
        
        if(nums[i]>max1)
        {
            //assign the second max to max2
            max2=max1;
            max1=nums[i];
        }
        else if(nums[i]>max2)
        {
            //it can become second max
            max2= nums[i];
        }
        
        //check for the minimum
        if(nums[i]<min1)
        {
            //it can become first minimum
            min2=min1;
            min1=nums[i];
        }
        else if(nums[i]<min2)
        {
            //it can become second minimum
            min2=nums[i];
        }
    }
    return (max1*max2)- (min1*min2);
}
```

This function calculates the maximum product difference between two pairs of integers from a list. It finds the two largest and two smallest numbers and returns the result of (firstMax * secondMax) - (firstMin * secondMin).

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Signature**
	```cpp
	int maxProductDifference(vector<int>& nums) {
	```
	This is the function signature, defining a function called 'maxProductDifference' which takes a vector of integers as input.

2. **Variable Initialization**
	```cpp
	    int max1=INT_MIN;
	```
	This initializes 'max1' to the smallest possible integer, which will hold the maximum value from the array.

3. **Variable Initialization**
	```cpp
	    int max2=INT_MIN;
	```
	This initializes 'max2' to the smallest possible integer, which will hold the second maximum value from the array.

4. **Variable Initialization**
	```cpp
	    int min1=INT_MAX;
	```
	This initializes 'min1' to the largest possible integer, which will hold the minimum value from the array.

5. **Variable Initialization**
	```cpp
	    int min2=INT_MAX;
	```
	This initializes 'min2' to the largest possible integer, which will hold the second minimum value from the array.

6. **Loop**
	```cpp
	    for(int i=0;i<nums.size();i++)
	```
	A for-loop iterates through each element of the 'nums' array to evaluate the maximum and minimum values.

7. **Condition**
	```cpp
	        if(nums[i]>max1)
	```
	Checks if the current number is greater than 'max1' (the largest number found so far).

8. **Assignment**
	```cpp
	            max2=max1;
	```
	Assigns the previous 'max1' to 'max2' because a new larger number has been found.

9. **Assignment**
	```cpp
	            max1=nums[i];
	```
	Assigns the current number to 'max1' as it is now the largest number found.

10. **Condition**
	```cpp
	        else if(nums[i]>max2)
	```
	Checks if the current number is greater than 'max2' but less than or equal to 'max1'.

11. **Assignment**
	```cpp
	            max2= nums[i];
	```
	Assigns the current number to 'max2' as it is now the second largest number.

12. **Condition**
	```cpp
	        if(nums[i]<min1)
	```
	Checks if the current number is smaller than 'min1' (the smallest number found so far).

13. **Assignment**
	```cpp
	            min2=min1;
	```
	Assigns the previous 'min1' to 'min2' because a new smaller number has been found.

14. **Assignment**
	```cpp
	            min1=nums[i];
	```
	Assigns the current number to 'min1' as it is now the smallest number found.

15. **Condition**
	```cpp
	        else if(nums[i]<min2)
	```
	Checks if the current number is smaller than 'min2' but greater than or equal to 'min1'.

16. **Assignment**
	```cpp
	            min2=nums[i];
	```
	Assigns the current number to 'min2' as it is now the second smallest number.

17. **Return**
	```cpp
	    return (max1*max2)- (min1*min2);
	```
	Returns the product difference between the largest two numbers and the smallest two numbers.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear because we are iterating through the array once to find the two largest and two smallest values.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant because we are only using a fixed amount of extra space for tracking the four values.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-product-difference-between-two-pairs/description/)

---
{{< youtube wBPoEm3r3EA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

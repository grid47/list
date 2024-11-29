
+++
authors = ["grid47"]
title = "Leetcode 152: Maximum Product Subarray"
date = "2024-10-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 152: Maximum Product Subarray in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/152.webp"
youtube = "lXVy6YWFcRM"
youtube_upload_date="2021-01-03"
youtube_thumbnail="https://i.ytimg.com/vi_webp/lXVy6YWFcRM/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/152.webp" 
    alt="A radiant subarray of numbers, with the product of values glowing brightly as the maximum result."
    caption="Solution to LeetCode 152: Maximum Product Subarray Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given an integer array nums. Find the subarray that has the largest product, and return the product.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is an integer array nums where each element is an integer between -10 and 10.
- **Example:** `nums = [1, 2, -1, 4]`
- **Constraints:**
	- 1 <= nums.length <= 2 * 10^4
	- -10 <= nums[i] <= 10

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be an integer representing the largest product of any subarray.
- **Example:** `8`
- **Constraints:**
	- The product of any subarray will fit within a 32-bit integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** To find the maximum product of a subarray, we can track the maximum and minimum products up to the current index.

- Initialize two variables, mx and mn, to store the maximum and minimum products so far.
- Initialize a result variable to store the maximum product encountered.
- Iterate through the array, updating mx, mn, and result at each step by considering the current number and its product with the previous mx and mn.
{{< dots >}}
### Problem Assumptions ✅
- The input array is not empty.
- The product of any subarray will fit within a 32-bit integer.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [1, 2, -1, 4]`  \
  **Explanation:** The subarray [1, 2, -1, 4] has the largest product, which is 8.

- **Input:** `nums = [-1, 0, -3, 4]`  \
  **Explanation:** The subarray [4] has the largest product, which is 4.

{{< dots >}}
## Approach 🚀
To solve this problem, we will iterate through the array while keeping track of the maximum and minimum products at each step.

### Initial Thoughts 💭
- When we multiply a negative number by a negative number, it could result in a large positive product.
- By keeping track of both the maximum and minimum products at each index, we can handle the case of negative numbers efficiently.
{{< dots >}}
### Edge Cases 🌐
- The input will never be empty.
- The solution must handle large inputs efficiently, up to 2 * 10^4 elements.
- Handle negative numbers and zeros correctly.
- The product of any subarray must fit in a 32-bit integer.
{{< dots >}}
## Code 💻
```cpp
int maxProduct(vector<int>& nums) {
    int mx = 1, mn = 1;

    int res = INT_MIN;
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] < 0) swap(mx, mn);
        mx = max(nums[i], mx * nums[i]);
        mn = min(nums[i], mn * nums[i]);
        
        res = max(res, mx);
    }
    return res;
}
```

This code implements the algorithm to find the maximum product subarray in an array of integers. It uses dynamic tracking of the maximum and minimum products ending at each index, accounting for negative values that could flip the product's sign.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int maxProduct(vector<int>& nums) {
	```
	Defines the function `maxProduct`, which takes a vector of integers and returns the maximum product of any contiguous subarray.

2. **Variable Initialization**
	```cpp
	    int mx = 1, mn = 1;
	```
	Initializes two variables `mx` and `mn` to 1, representing the maximum and minimum products ending at the current index.

3. **Variable Declaration**
	```cpp
	    int res = INT_MIN;
	```
	Declares `res` and initializes it to the minimum integer value (`INT_MIN`) to track the maximum product found during the loop.

4. **Loop Iteration**
	```cpp
	    for(int i = 0; i < nums.size(); i++) {
	```
	Starts a loop to iterate through the elements of the `nums` vector.

5. **Conditional Check**
	```cpp
	        if(nums[i] < 0) swap(mx, mn);
	```
	Checks if the current number is negative. If it is, it swaps `mx` and `mn`, as a negative number could flip the product's sign.

6. **Dynamic Programming**
	```cpp
	        mx = max(nums[i], mx * nums[i]);
	```
	Updates `mx` to the maximum of the current number itself or the product of `mx` and the current number. This keeps track of the largest product of any subarray ending at the current index.

7. **Dynamic Programming**
	```cpp
	        mn = min(nums[i], mn * nums[i]);
	```
	Updates `mn` to the minimum of the current number itself or the product of `mn` and the current number. This helps to track the smallest product, which can be important for handling negative numbers.

8. **Result Update**
	```cpp
	        res = max(res, mx);
	```
	Updates the result `res` by comparing it with the current `mx` to keep track of the maximum product encountered so far.

9. **End of Loop**
	```cpp
	    }
	```
	Marks the end of the loop that processes each number in the input array.

10. **Return Value**
	```cpp
	    return res;
	```
	Returns the final value of `res`, which holds the maximum product of any subarray.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

We iterate through the array once, so the time complexity is linear in the number of elements.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

We use a constant amount of space, so the space complexity is O(1).

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-product-subarray/description/)

---
{{< youtube lXVy6YWFcRM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

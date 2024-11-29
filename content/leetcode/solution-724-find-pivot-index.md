
+++
authors = ["grid47"]
title = "Leetcode 724: Find Pivot Index"
date = "2024-08-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 724: Find Pivot Index in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Prefix Sum"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/724.webp"
youtube = "u89i60lYx8U"
youtube_upload_date="2021-12-29"
youtube_thumbnail="https://i.ytimg.com/vi/u89i60lYx8U/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/724.webp" 
    alt="A number array where the pivot index is found, with the pivot glowing brightly as it’s identified."
    caption="Solution to LeetCode 724: Find Pivot Index Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given an array of integers, find the pivot index where the sum of elements to the left equals the sum of elements to the right.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array of integers nums.
- **Example:** `nums = [5, 6, 4, 2]`
- **Constraints:**
	- 1 <= nums.length <= 10^4
	- -1000 <= nums[i] <= 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is the leftmost pivot index where the sum of elements on the left equals the sum of elements on the right.
- **Example:** `Output: 1`
- **Constraints:**
	- Return -1 if no pivot index exists.

{{< dots >}}
### Core Logic 🔍
**Goal:** Determine the index where the sum of the left side of the array equals the sum of the right side.

- 1. Compute the total sum of the array.
- 2. Traverse the array, updating the left sum and comparing it to the right sum (initially the total sum).
- 3. If the left sum equals the right sum at any index, return that index.
- 4. If no such index exists, return -1.
{{< dots >}}
### Problem Assumptions ✅
- The input array will not be empty.
- The pivot index will be calculated by comparing sums of integers on both sides.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: [2, 4, 1, 3, 5]`  \
  **Explanation:** The sum to the left of index 2 is 6 (2 + 4), and the sum to the right is 8 (3 + 5). Thus, the pivot index is 2.

{{< dots >}}
## Approach 🚀
The approach involves calculating the total sum and iterating through the array while maintaining running sums of the left and right sides.

### Initial Thoughts 💭
- We can use a running left sum and calculate the right sum by subtracting the current element from the total sum.
- If the left sum equals the right sum at any index, return that index. Otherwise, continue the search.
{{< dots >}}
### Edge Cases 🌐
- Handle cases where the input array has only one element.
- Ensure the solution works efficiently for large arrays (up to 10^4 elements).
- Consider arrays with negative numbers or zeros.
- Handle arrays with both positive and negative values.
{{< dots >}}
## Code 💻
```cpp
int pivotIndex(vector<int>& nums) {
    int left = 0;
    int right = accumulate(nums.begin(), nums.end(), 0);
    for(int i = 0; i < nums.size(); i++) {
        right -= nums[i];
        if(right == left) return i;
        left  += nums[i];
    }
    return -1;
}
```

This function finds the pivot index in an array where the sum of the elements to the left equals the sum of the elements to the right.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int pivotIndex(vector<int>& nums) {
	```
	Defines a function called pivotIndex that accepts a reference to a vector of integers.

2. **Variable Initialization**
	```cpp
	    int left = 0;
	```
	Initializes a variable 'left' to 0, representing the sum of elements to the left of the pivot.

3. **Variable Initialization**
	```cpp
	    int right = accumulate(nums.begin(), nums.end(), 0);
	```
	Initializes 'right' to the total sum of all elements in the vector 'nums'.

4. **Loop**
	```cpp
	    for(int i = 0; i < nums.size(); i++) {
	```
	Starts a loop that iterates through each element of the vector 'nums'.

5. **Operation**
	```cpp
	        right -= nums[i];
	```
	Subtracts the current element from the 'right' sum to exclude it from the right side of the pivot.

6. **Condition**
	```cpp
	        if(right == left) return i;
	```
	Checks if the sum of elements to the left is equal to the sum of elements to the right. If so, returns the index.

7. **Operation**
	```cpp
	        left  += nums[i];
	```
	Adds the current element to the 'left' sum to include it in the left side of the pivot.

8. **Return**
	```cpp
	    return -1;
	```
	Returns -1 if no pivot index is found.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear because we need to traverse the array once to compute the total sum and then once more to find the pivot index.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant, as we only use a few extra variables for sum calculations.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-pivot-index/description/)

---
{{< youtube u89i60lYx8U >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

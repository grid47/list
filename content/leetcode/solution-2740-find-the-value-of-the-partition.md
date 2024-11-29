
+++
authors = ["grid47"]
title = "Leetcode 2740: Find the Value of the Partition"
date = "2024-02-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2740: Find the Value of the Partition in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "WeaM8AiavbY"
youtube_upload_date="2023-06-18"
youtube_thumbnail="https://i.ytimg.com/vi_webp/WeaM8AiavbY/maxresdefault.webp"
comments = true
+++



---
You are given a list of positive integers `nums`. Your task is to partition this list into two non-empty arrays, `nums1` and `nums2`, such that the absolute difference between the maximum element of `nums1` and the minimum element of `nums2` is minimized.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a single array of positive integers `nums`.
- **Example:** `nums = [3, 7, 2, 8]`
- **Constraints:**
	- 2 <= nums.length <= 100000
	- 1 <= nums[i] <= 1000000000

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the integer denoting the value of the partition, i.e., the minimum possible absolute difference between the maximum of `nums1` and the minimum of `nums2`.
- **Example:** `Output: 1`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** To minimize the absolute difference between the maximum of `nums1` and the minimum of `nums2`.

- Sort the array `nums` in ascending order.
- Find the smallest difference between two consecutive elements in the sorted array.
- Return this minimum difference as the result.
{{< dots >}}
### Problem Assumptions ✅
- All elements in `nums` are positive integers.
- The array is non-empty and contains at least two elements.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [3, 7, 2, 8]`  \
  **Explanation:** We can partition the array into `nums1 = [2, 7]` and `nums2 = [3, 8]`. The minimum absolute difference is `|7 - 3| = 1`.

- **Input:** `nums = [15, 2, 5]`  \
  **Explanation:** We can partition the array into `nums1 = [5]` and `nums2 = [15, 2]`. The minimum absolute difference is `|5 - 2| = 3`.

{{< dots >}}
## Approach 🚀
The approach involves sorting the array and calculating the smallest difference between two consecutive elements in the sorted array.

### Initial Thoughts 💭
- Sorting the array helps us easily find the smallest possible difference between two elements.
- The problem can be solved by comparing adjacent elements in the sorted array.
{{< dots >}}
### Edge Cases 🌐
- The input will never be empty as per the constraints.
- For large arrays, sorting the array and finding the minimum difference should still be efficient.
- If the array contains two elements, the result is the absolute difference between those two elements.
- The solution needs to handle arrays with up to 100,000 elements efficiently.
{{< dots >}}
## Code 💻
```cpp
int findValueOfPartition(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int res = nums[1] - nums[0];
    for(int i = 1; i < nums.size(); i++) {
        res = min(nums[i] - nums[i - 1], res);
    }
    return res;
}
```

This function calculates the minimum difference between any two adjacent numbers in a sorted array `nums`.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int findValueOfPartition(vector<int>& nums) {
	```
	The function `findValueOfPartition` is defined, which takes a vector of integers `nums` and returns the minimum difference between any two adjacent elements after sorting the array.

2. **Sorting**
	```cpp
	    sort(nums.begin(), nums.end());
	```
	The `nums` array is sorted in non-decreasing order using the `sort` function from the Standard Library.

3. **Variable Initialization**
	```cpp
	    int res = nums[1] - nums[0];
	```
	The variable `res` is initialized to the difference between the first two elements of the sorted array, which will hold the minimum difference found.

4. **Loop - Condition**
	```cpp
	    for(int i = 1; i < nums.size(); i++) {
	```
	A `for` loop is initiated, iterating over the sorted `nums` array starting from index 1.

5. **Min Calculation**
	```cpp
	        res = min(nums[i] - nums[i - 1], res);
	```
	Inside the loop, the difference between the current element `nums[i]` and the previous element `nums[i - 1]` is calculated. The result is compared with the current value of `res`, and the smaller value is assigned back to `res`.

6. **Return Statement**
	```cpp
	    return res;
	```
	The function returns the value of `res`, which contains the minimum difference between adjacent elements in the sorted array.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The time complexity is dominated by the sorting step, which is O(n log n).

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n) for storing the sorted array, assuming the sorting algorithm uses extra space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-the-value-of-the-partition/description/)

---
{{< youtube WeaM8AiavbY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

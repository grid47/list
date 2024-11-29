
+++
authors = ["grid47"]
title = "Leetcode 34: Find First and Last Position of Element in Sorted Array"
date = "2024-11-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 34: Find First and Last Position of Element in Sorted Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/34.webp"
youtube = "4sQL7R5ySUU"
youtube_upload_date="2021-02-05"
youtube_thumbnail="https://i.ytimg.com/vi_webp/4sQL7R5ySUU/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/34.webp" 
    alt="A soft glowing bar where the positions of elements light up in sequence."
    caption="Solution to LeetCode 34: Find First and Last Position of Element in Sorted Array Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given a sorted array 'nums' in non-decreasing order, find the starting and ending index of a target value. If the target is not found, return [-1, -1]. Your solution must run in O(log n) time complexity.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a sorted array 'nums' and a target value that needs to be searched.
- **Example:** `nums = [1, 2, 3, 3, 3, 5, 6, 7], target = 3`
- **Constraints:**
	- 0 <= nums.length <= 10^5
	- -10^9 <= nums[i] <= 10^9
	- nums is sorted in non-decreasing order.
	- -10^9 <= target <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be an array of two integers, representing the starting and ending position of the target value, or [-1, -1] if the target is not found.
- **Example:** `For nums = [1, 2, 3, 3, 3, 5, 6, 7], target = 3, the output is [2, 4].`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** To find the starting and ending positions of the target in a sorted array efficiently.

- Use binary search to find the first occurrence of the target value (lower bound).
- Use binary search to find the position just after the last occurrence of the target value (upper bound).
- Return the index range or [-1, -1] if the target is not found.
{{< dots >}}
### Problem Assumptions ✅
- The array is sorted and can contain duplicate values.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [1, 2, 3, 3, 3, 5, 6, 7], target = 3`  \
  **Explanation:** The target value 3 appears three times in the array. The starting position is 2, and the ending position is 4.

- **Input:** `nums = [1, 2, 3, 3, 3, 5, 6, 7], target = 0`  \
  **Explanation:** The target value 0 is not present in the array, so the output is [-1, -1].

- **Input:** `nums = [], target = 5`  \
  **Explanation:** The array is empty, so the target cannot be found, resulting in [-1, -1].

{{< dots >}}
## Approach 🚀
The approach is to utilize binary search to efficiently find the starting and ending positions of the target in the sorted array.

### Initial Thoughts 💭
- Since the array is sorted, binary search can help find the target in O(log n) time.
- We can use two binary search operations: one for finding the first occurrence and one for finding the last occurrence of the target.
{{< dots >}}
### Edge Cases 🌐
- If the array is empty, the result should be [-1, -1].
- The algorithm must handle arrays of size up to 10^5 efficiently.
- If the target value is not present in the array, return [-1, -1].
- The solution should run in O(log n) time, so avoid linear searches.
{{< dots >}}
## Code 💻
```cpp
vector<int> searchRange(vector<int>& nums, int target) {
    
    auto it1 = lower_bound(nums.begin(), nums.end(), target);
    auto it2 = upper_bound(nums.begin(), nums.end(), target);

    if(it1 == nums.end() || *it1 != target) return {-1, -1};

    return {(int) (it1 - nums.begin()), (int) (it2 - nums.begin() - 1)};
}
```

This code finds the first and last positions of a target element in a sorted array using binary search.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<int> searchRange(vector<int>& nums, int target) {
	```
	This line declares a function named 'searchRange' that takes a sorted array 'nums' and a target integer 'target' as input and returns a vector containing the first and last positions of the target element, or {-1, -1} if the target is not found.

2. **Binary Search**
	```cpp
	    auto it1 = lower_bound(nums.begin(), nums.end(), target);
	```
	This line uses the `lower_bound` function to find the first occurrence of the target element in the array. It returns an iterator pointing to the first element greater than or equal to the target.

3. **Binary Search**
	```cpp
	    auto it2 = upper_bound(nums.begin(), nums.end(), target);
	```
	This line uses the `upper_bound` function to find the first element greater than the target element in the array. It returns an iterator pointing to the first element greater than the target.

4. **Conditional Check**
	```cpp
	    if(it1 == nums.end() || *it1 != target) return {-1, -1};
	```
	This line checks if the `lower_bound` iterator points to the end of the array or if the element at the `it1` position is not equal to the target. If either condition is true, it means the target is not found in the array, so the function returns {-1, -1}.

5. **Result Calculation**
	```cpp
	    return {(int) (it1 - nums.begin()), (int) (it2 - nums.begin() - 1)};
	```
	If the target is found, the function returns a vector containing the first and last positions of the target. The first position is calculated by subtracting the beginning iterator of the array from the `it1` iterator, and the last position is calculated by subtracting the beginning iterator from the `it2` iterator and then decrementing by 1.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(log n)
- **Average Case:** O(log n)
- **Worst Case:** O(log n)

The time complexity is O(log n) because we are performing binary search operations.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) because no additional space is required beyond the input array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/)

---
{{< youtube 4sQL7R5ySUU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

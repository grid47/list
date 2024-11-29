
+++
authors = ["grid47"]
title = "Leetcode 33: Search in Rotated Sorted Array"
date = "2024-11-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 33: Search in Rotated Sorted Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/33.webp"
youtube = "U8XENwh8Oy8"
youtube_upload_date="2020-06-18"
youtube_thumbnail="https://i.ytimg.com/vi/U8XENwh8Oy8/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/33.webp" 
    alt="A rotating spiral of light, revealing new paths and points of connection."
    caption="Solution to LeetCode 33: Search in Rotated Sorted Array Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given a sorted array 'nums' which may have been rotated at an unknown pivot. Your task is to search for a target value in this rotated array. Return the index of the target if found, or -1 if not found. The solution must have a runtime complexity of O(log n).
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a rotated sorted array 'nums' of distinct integers, followed by the target value to search for.
- **Example:** `nums = [4, 5, 6, 7, 0, 1, 2], target = 0`
- **Constraints:**
	- 1 <= nums.length <= 5000
	- -104 <= nums[i] <= 104
	- All values of nums are unique.
	- nums is a rotated sorted array.
	- -104 <= target <= 104

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is the index of the target in the rotated array if it exists, otherwise return -1.
- **Example:** `For nums = [4, 5, 6, 7, 0, 1, 2], target = 0, the output is 4.`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to search for the target value in the rotated array efficiently using binary search.

- Use binary search to find the pivot where the rotation occurs.
- Determine which half of the array is sorted, and narrow down the search to that half.
- Adjust the search range depending on whether the target is within the sorted half.
{{< dots >}}
### Problem Assumptions ✅
- The array has been rotated, and the array is sorted in ascending order before the rotation.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [4, 5, 6, 7, 0, 1, 2], target = 0`  \
  **Explanation:** The array is rotated at index 3, so the target value 0 is found at index 4 in the rotated array.

- **Input:** `nums = [4, 5, 6, 7, 0, 1, 2], target = 3`  \
  **Explanation:** The target value 3 does not exist in the array, so the output is -1.

{{< dots >}}
## Approach 🚀
We will use a modified binary search to efficiently find the target in the rotated array.

### Initial Thoughts 💭
- The array is rotated, so we cannot perform a standard binary search directly.
- We need to identify which half of the array is sorted and determine if the target is within that range.
- The key observation is that the array is always divided into two subarrays, one of which is sorted.
{{< dots >}}
### Edge Cases 🌐
- The array is guaranteed to have at least one element, so no need to handle empty arrays.
- The solution should handle arrays with up to 5000 elements efficiently within O(log n) time.
- If the target is not present in the array, return -1.
- All elements are distinct, so we do not need to worry about duplicate values.
{{< dots >}}
## Code 💻
```cpp
int search(vector<int>& nums, int target) {
    int n = nums.size();
    int s = 0, e = n - 1;
    while(s <= e) {
        int mid = s + (e - s + 1) / 2;
        if(nums[mid] == target) return mid;
        if(nums[s] <= nums[mid]) {// window contain jerk
            if(nums[s] <= target && target < nums[mid])
                e = mid - 1;
            else s = mid + 1;
        } else {// window is linear
            if(nums[mid] < target && target <= nums[e])
                s = mid + 1;
            else e = mid - 1;
        }
    }
    return -1;
}
```

This code implements binary search on a rotated sorted array to find the target element.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int search(vector<int>& nums, int target) {
	```
	This line declares a function named 'search' that takes a vector of integers 'nums' and a target integer 'target' as input and returns the index of the target element if found, otherwise -1.

2. **Variable Initialization**
	```cpp
	    int n = nums.size();
	```
	This line stores the size of the input array 'nums' in the variable 'n'.

3. **Variable Initialization**
	```cpp
	    int s = 0, e = n - 1;
	```
	This line initializes two pointers 's' and 'e' to represent the start and end indices of the search range, respectively.

4. **Loop Iteration**
	```cpp
	    while(s <= e) {
	```
	This line starts a `while` loop that continues as long as the start index 's' is less than or equal to the end index 'e'.

5. **Calculation**
	```cpp
	        int mid = s + (e - s + 1) / 2;
	```
	This line calculates the middle index 'mid' using a formula that avoids integer overflow for large values of 's' and 'e'.

6. **Conditional Check**
	```cpp
	        if(nums[mid] == target) return mid;
	```
	This line checks if the element at the middle index 'mid' is equal to the target. If so, the function returns the index 'mid'.

7. **Conditional Check**
	```cpp
	        if(nums[s] <= nums[mid]) {// window contain jerk
	```
	This line checks if the first half of the array is sorted. If it is, the window contains a 'jerk' (a point where the array is not sorted).

8. **Conditional Check**
	```cpp
	            if(nums[s] <= target && target < nums[mid])
	```
	This line checks if the target lies within the sorted first half of the array.

9. **Index Update**
	```cpp
	                e = mid - 1;
	```
	If the target lies within the sorted first half, the search space is narrowed by updating the end index 'e' to 'mid - 1'.

10. **Index Update**
	```cpp
	            else s = mid + 1;
	```
	If the target doesn't lie within the sorted first half, the search space is narrowed by updating the start index 's' to 'mid + 1'.

11. **Conditional Check**
	```cpp
	        } else {// window is linear
	```
	This line checks if the second half of the array is sorted. If it is, the window is linear.

12. **Conditional Check**
	```cpp
	            if(nums[mid] < target && target <= nums[e])
	```
	This line checks if the target lies within the sorted second half of the array.

13. **Index Update**
	```cpp
	                s = mid + 1;
	```
	If the target lies within the sorted second half, the search space is narrowed by updating the start index 's' to 'mid + 1'.

14. **Index Update**
	```cpp
	            else e = mid - 1;
	```
	If the target doesn't lie within the sorted second half, the search space is narrowed by updating the end index 'e' to 'mid - 1'.

15. **Return**
	```cpp
	    return -1;
	```
	If the target is not found after the loop, the function returns -1 to indicate that the target is not present in the array.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(log n)
- **Average Case:** O(log n)
- **Worst Case:** O(log n)

The time complexity is O(log n) because we are using a modified binary search that halves the search space at each step.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) because the algorithm only uses a constant amount of extra space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/search-in-rotated-sorted-array/description/)

---
{{< youtube U8XENwh8Oy8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |


+++
authors = ["grid47"]
title = "Leetcode 81: Search in Rotated Sorted Array II"
date = "2024-10-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 81: Search in Rotated Sorted Array II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/81.webp"
youtube = "oUnF7o88_Xc"
youtube_upload_date="2023-08-10"
youtube_thumbnail="https://i.ytimg.com/vi/oUnF7o88_Xc/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/81.webp" 
    alt="A rotating array with elements softly shifting in a clockwise direction."
    caption="Solution to LeetCode 81: Search in Rotated Sorted Array II Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given a sorted integer array `nums` that has been rotated at an unknown pivot index `k`. The array may contain duplicates. Your task is to determine whether a given target exists in the array, minimizing the number of operations as much as possible.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a rotated sorted integer array `nums` and an integer target to search for in the array.
- **Example:** `nums = [4,5,6,6,7,0,1,2,4], target = 0`
- **Constraints:**
	- 1 <= nums.length <= 5000
	- -104 <= nums[i] <= 104
	- -104 <= target <= 104

{{< dots >}}
### Output Specifications 📤
- **Output:** Return `true` if the target exists in the array, otherwise return `false`.
- **Example:** `true`
- **Constraints:**
	- The result should be true if the target exists in the array, and false if not.

{{< dots >}}
### Core Logic 🔍
**Goal:** To efficiently search for the target in the rotated sorted array, even when duplicates are present.

- Use a modified binary search to handle both rotated arrays and duplicates.
- At each step, check if the middle element equals the target. If it does, return true.
- If the left, middle, and right elements are the same, increment `l` and decrement `r` to avoid duplicates.
- Use the standard binary search logic to narrow down the search range based on the sorted portion of the array.
{{< dots >}}
### Problem Assumptions ✅
- The array is guaranteed to be rotated, but duplicates may be present.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [4,5,6,6,7,0,1,2,4], target = 0`  \
  **Explanation:** The target `0` is found at index 5, so the output is `true`.

- **Input:** `nums = [1,3,5,7,8,8,10], target = 4`  \
  **Explanation:** The target `4` does not exist in the array, so the output is `false`.

{{< dots >}}
## Approach 🚀
We use a modified binary search approach that accounts for the rotation and potential duplicates in the array.

### Initial Thoughts 💭
- Binary search can be adapted to handle the rotated sorted array, but we need to handle duplicates carefully.
- When elements are equal at the left, middle, and right indices, we need to increment and decrement `l` and `r` respectively to avoid redundant checks.
{{< dots >}}
### Edge Cases 🌐
- If the array is empty, the result should be false.
- Ensure that the solution handles the largest possible input size efficiently.
- Handle cases where all elements are the same and the target is present or absent.
- Ensure that the solution works within the time and space limits for large arrays.
{{< dots >}}
## Code 💻
```cpp
bool search(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return true;
        }

        // If left half is sorted
        if (nums[left] <= nums[mid]) {
            if (target >= nums[left] && target < nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else {
            // Right half is sorted
            if (target > nums[mid] && target <= nums[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }

    return false;
}
```

This code implements a binary search algorithm to find a target value in a rotated sorted array.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	bool search(vector<int>& nums, int target) {
	```
	Declares a function `search` that takes a sorted rotated array `nums` and a target value `target` as input and returns a boolean indicating whether the target is found.

2. **Variable Initialization**
	```cpp
	    int left = 0, right = nums.size() - 1;
	```
	Initializes two pointers, `left` and `right`, to the beginning and end of the array, respectively.

3. **Loop Iteration**
	```cpp
	    while (left <= right) {
	```
	Starts a `while` loop that continues as long as `left` is less than or equal to `right`.

4. **Calculation**
	```cpp
	        int mid = left + (right - left) / 2;
	```
	Calculates the middle index `mid` using a formula that avoids potential integer overflow.

5. **Conditional**
	```cpp
	        if (nums[mid] == target) {
	            return true;
	        }
	```
	Checks if the element at the middle index is the target. If so, returns `true`.

6. **Conditional**
	```cpp
	        if (nums[left] <= nums[mid]) {
	```
	Checks if the left half of the array is sorted.

7. **Conditional**
	```cpp
	            if (target >= nums[left] && target < nums[mid]) {
	                right = mid - 1;
	            } else {
	                left = mid + 1;
	            }
	```
	If the left half is sorted and the target is within its range, adjusts the `right` pointer. Otherwise, adjusts the `left` pointer.

8. **Conditional**
	```cpp
	        } else {
	```
	If the left half is not sorted, the right half must be sorted.

9. **Conditional**
	```cpp
	            if (target > nums[mid] && target <= nums[right]) {
	                left = mid + 1;
	            } else {
	                right = mid - 1;
	            }
	```
	If the right half is sorted and the target is within its range, adjusts the `left` pointer. Otherwise, adjusts the `right` pointer.

10. **Return**
	```cpp
	    return false;
	```
	If the target is not found after the loop, returns `false`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(log n)
- **Average Case:** O(log n)
- **Worst Case:** O(n)

In the worst case, we may need to check every element due to duplicates, leading to linear time complexity.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The solution uses constant space, as we are modifying the search range in-place.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/)

---
{{< youtube oUnF7o88_Xc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |


+++
authors = ["grid47"]
title = "Leetcode 35: Search Insert Position"
date = "2024-11-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 35: Search Insert Position in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/35.webp"
youtube = "K-RYzDZkzCI"
youtube_upload_date="2020-12-11"
youtube_thumbnail="https://i.ytimg.com/vi_webp/K-RYzDZkzCI/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/35.webp" 
    alt="A glowing insertion point in a calm array, gently creating a new position."
    caption="Solution to LeetCode 35: Search Insert Position Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given a sorted array of distinct integers and a target value, return the index of the target if it is present. If the target is not in the array, return the index where it should be inserted to maintain the sorted order.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** A sorted array of distinct integers and a target value.
- **Example:** `Input: nums = [1, 2, 4, 5, 7], target = 4`
- **Constraints:**
	- 1 <= nums.length <= 10^4
	- -10^4 <= nums[i] <= 10^4
	- nums contains distinct values sorted in ascending order.
	- -10^4 <= target <= 10^4

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the index of the target if found, or the index where it should be inserted to keep the array sorted.
- **Example:** `Output: 2`
- **Constraints:**
	- Return an integer indicating the position of the target or where it should be inserted.

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the target's index or the index for insertion using binary search for O(log n) time complexity.

- Initialize two pointers, left and right, at the start and end of the array.
- Perform a binary search: calculate mid and compare the value at mid with the target.
- If the target is equal to the value at mid, return mid.
- If the target is greater than the value at mid, move the left pointer to mid + 1.
- If the target is smaller than the value at mid, move the right pointer to mid - 1.
- If the loop ends without finding the target, return the position of left as the index for insertion.
{{< dots >}}
### Problem Assumptions ✅
- The input array will always be sorted and contain distinct integers.
- The target value is within the bounds of the given constraints.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [1, 2, 4, 5, 7], target = 4`  \
  **Explanation:** The target is present at index 2, so we return 2.

- **Input:** `Input: nums = [1, 2, 4, 5, 7], target = 3`  \
  **Explanation:** The target is not found, but it should be inserted at index 2 to keep the array sorted.

- **Input:** `Input: nums = [1, 2, 4, 5, 7], target = 6`  \
  **Explanation:** The target is not found, but it should be inserted at index 4 to keep the array sorted.

{{< dots >}}
## Approach 🚀
Use binary search to find the target's position or determine where it should be inserted in the sorted array.

### Initial Thoughts 💭
- The problem can be solved efficiently with a binary search approach due to the sorted nature of the array.
- Binary search ensures an O(log n) runtime, which is optimal for this problem.
{{< dots >}}
### Edge Cases 🌐
- The array may not be empty as per constraints.
- Test with large arrays to ensure the O(log n) time complexity holds.
- Test with a target value that is smaller or larger than all elements in the array.
- Handle edge cases where the target is at the start or end of the array.
{{< dots >}}
## Code 💻
```cpp
int searchInsert(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(nums[mid] == target) return mid;
        if(nums[mid] < target) l = mid + 1;
        else r = mid - 1;
    }
    return l;
}
```

This code finds the index where the target element should be inserted in a sorted array to maintain the sorted order.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int searchInsert(vector<int>& nums, int target) {
	```
	This line declares a function named 'searchInsert' that takes a sorted array 'nums' and a target integer 'target' as input and returns the index where the target should be inserted.

2. **Variable Initialization**
	```cpp
	    int l = 0, r = nums.size() - 1;
	```
	This line initializes two pointers, 'l' and 'r', to represent the left and right boundaries of the search range. 'l' is initialized to 0 (the start of the array), and 'r' is initialized to the index of the last element in the array.

3. **Loop Iteration**
	```cpp
	    while(l <= r) {
	```
	This line starts a `while` loop that continues as long as the left pointer 'l' is less than or equal to the right pointer 'r'.

4. **Calculation**
	```cpp
	        int mid = l + (r - l) / 2;
	```
	This line calculates the middle index 'mid' using a formula that avoids integer overflow for large values of 'l' and 'r'.

5. **Conditional Check**
	```cpp
	        if(nums[mid] == target) return mid;
	```
	This line checks if the element at the middle index 'mid' is equal to the target. If so, the function returns the index 'mid' as the target is already present in the array.

6. **Conditional Check and Index Update**
	```cpp
	        if(nums[mid] < target) l = mid + 1;
	```
	This line checks if the element at the middle index 'mid' is less than the target. If so, it means the target should be inserted after the middle element, so the left pointer 'l' is updated to 'mid + 1'.

7. **Conditional Check and Index Update**
	```cpp
	        else r = mid - 1;
	```
	If the element at the middle index 'mid' is greater than the target, it means the target should be inserted before the middle element, so the right pointer 'r' is updated to 'mid - 1'.

8. **Return**
	```cpp
	    return l;
	```
	After the loop terminates, the left pointer 'l' will be pointing to the correct insertion index for the target element. The function returns 'l' as the result.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(log n)
- **Average Case:** O(log n)
- **Worst Case:** O(log n)

The time complexity is O(log n) because binary search is performed on the sorted array.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) as no additional space is used beyond the input array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/search-insert-position/description/)

---
{{< youtube K-RYzDZkzCI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

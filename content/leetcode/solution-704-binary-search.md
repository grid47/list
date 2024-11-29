
+++
authors = ["grid47"]
title = "Leetcode 704: Binary Search"
date = "2024-08-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 704: Binary Search in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/704.webp"
youtube = "PissfOvEH7Q"
youtube_upload_date="2023-04-01"
youtube_thumbnail="https://i.ytimg.com/vi/PissfOvEH7Q/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/704.webp" 
    alt="A sorted array where binary search is applied, each step softly glowing to highlight the search process."
    caption="Solution to LeetCode 704: Binary Search Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given a sorted array of integers and a target value. Your task is to search for the target in the array. If the target exists, return its index. If it does not exist, return -1. You must achieve a time complexity of O(log n).
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a sorted array of integers and a target integer. The array is sorted in ascending order.
- **Example:** `nums = [1, 3, 5, 7, 9, 11], target = 5`
- **Constraints:**
	- 1 <= nums.length <= 10^4
	- -10^4 < nums[i], target < 10^4
	- All integers in nums are unique.
	- nums is sorted in ascending order.

{{< dots >}}
### Output Specifications 📤
- **Output:** The function should return the index of the target if it exists in the array. If the target does not exist, return -1.
- **Example:** `Output: 2`
- **Constraints:**
	- The result should be the index of the target value in the sorted array.

{{< dots >}}
### Core Logic 🔍
**Goal:** Implement an efficient search algorithm to find the target in the sorted array using binary search.

- 1. Initialize two pointers: left and right, pointing to the first and last elements of the array.
- 2. Calculate the middle index as the average of left and right.
- 3. If the middle element is equal to the target, return the middle index.
- 4. If the middle element is less than the target, update the left pointer to mid + 1.
- 5. If the middle element is greater than the target, update the right pointer to mid - 1.
- 6. If the left pointer exceeds the right, return -1 indicating the target is not in the array.
{{< dots >}}
### Problem Assumptions ✅
- The target is a valid integer within the given range.
- The array is sorted and contains unique integers.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [1, 3, 5, 7, 9, 11], target = 5`  \
  **Explanation:** The target 5 exists at index 2 in the sorted array, so the function will return 2.

- **Input:** `Input: nums = [1, 3, 5, 7, 9, 11], target = 8`  \
  **Explanation:** The target 8 does not exist in the array, so the function will return -1.

{{< dots >}}
## Approach 🚀
The optimal solution for this problem is binary search, which allows searching in O(log n) time complexity. We will iteratively narrow down the search range by updating the left and right pointers based on the comparison with the middle element.

### Initial Thoughts 💭
- Since the array is sorted, binary search is ideal for this problem to achieve O(log n) time complexity.
- We can solve this efficiently by halving the search space at each step.
{{< dots >}}
### Edge Cases 🌐
- The array is never empty in this problem, as the constraint guarantees that nums.length >= 1.
- For very large arrays, ensure that the binary search approach handles the input efficiently.
- The target could be the first or last element of the array.
- Ensure that the binary search efficiently narrows down the search space for large arrays.
{{< dots >}}
## Code 💻
```cpp
int search(vector<int>& nums, int target) {
    int l = 0, r = nums.size() -1;
    
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(nums[mid] == target) return mid;
        if(nums[mid] < target) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}
```

This code implements the binary search algorithm to find the index of a target element in a sorted array. The function iteratively narrows down the search range based on comparisons, reducing the search space by half each time.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int search(vector<int>& nums, int target) {
	```
	Define a function 'search' that takes a vector of integers 'nums' and an integer 'target' to return the index of the target element, or -1 if not found.

2. **Variable Initialization**
	```cpp
	    int l = 0, r = nums.size() -1;
	```
	Initialize two variables, 'l' for the left pointer and 'r' for the right pointer, which represent the range of indices to search within the array.

3. **While Loop**
	```cpp
	    while(l <= r) {
	```
	Start a while loop that will execute as long as the left pointer is less than or equal to the right pointer, meaning there is still a search range to explore.

4. **Midpoint Calculation**
	```cpp
	        int mid = l + (r - l) / 2;
	```
	Calculate the midpoint index 'mid' to divide the search space in half. Using 'l + (r - l) / 2' prevents potential overflow that could happen with large values of 'l' and 'r'.

5. **Target Comparison**
	```cpp
	        if(nums[mid] == target) return mid;
	```
	If the element at the midpoint is equal to the target, return the index 'mid' where the target is located.

6. **Left Pointer Update**
	```cpp
	        if(nums[mid] < target) l = mid + 1;
	```
	If the value at the midpoint is less than the target, update the left pointer 'l' to 'mid + 1' to search the right half of the array.

7. **Right Pointer Update**
	```cpp
	        else r = mid - 1;
	```
	If the value at the midpoint is greater than the target, update the right pointer 'r' to 'mid - 1' to search the left half of the array.

8. **Return Not Found**
	```cpp
	    return -1;
	```
	If the target element is not found within the array, return -1 indicating that the search was unsuccessful.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1), if the target is found at the middle of the array.
- **Average Case:** O(log n), for each search operation.
- **Worst Case:** O(log n), in the case where the search space is halved at each step.

The time complexity is logarithmic due to the binary search algorithm.

### Space Complexity 💾
- **Best Case:** O(1), as binary search does not require additional space.
- **Worst Case:** O(1), as the space complexity is constant for binary search.

The space complexity is constant since we only use a few pointers to track the search range.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/binary-search/description/)

---
{{< youtube PissfOvEH7Q >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

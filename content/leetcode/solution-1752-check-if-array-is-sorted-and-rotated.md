
+++
authors = ["grid47"]
title = "Leetcode 1752: Check if Array Is Sorted and Rotated"
date = "2024-05-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1752: Check if Array Is Sorted and Rotated in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "uoEJ3FXr56w"
youtube_upload_date="2021-02-07"
youtube_thumbnail="https://i.ytimg.com/vi_webp/uoEJ3FXr56w/maxresdefault.webp"
comments = true
+++



---
You are given an array `nums`. The array is originally sorted in non-decreasing order and then rotated some number of positions (including zero). Your task is to determine if the array could have been rotated from a sorted array. Return `true` if the array can be rotated to become sorted, and `false` otherwise.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a single array `nums` of length `n`.
- **Example:** `Input: nums = [4,5,6,7,1,2,3]`
- **Constraints:**
	- 1 <= nums.length <= 100
	- 1 <= nums[i] <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** Return `true` if the array can be rotated to become sorted in non-decreasing order. Otherwise, return `false`.
- **Example:** `Output: true`
- **Constraints:**
	- The returned value will be either true or false.

{{< dots >}}
### Core Logic 🔍
**Goal:** Determine if the array can be rotated to match a sorted sequence.

- 1. Traverse the array from the first to the last element.
- 2. Count how many times the array decreases (i.e., when `nums[i] > nums[i+1]`).
- 3. If there is more than one decrease, the array cannot be a rotated sorted array, and return `false`.
- 4. If there is zero or one decrease, return `true`.
{{< dots >}}
### Problem Assumptions ✅
- The array can contain duplicate elements.
- There is no need to handle edge cases for empty arrays as the length of `nums` is always at least 1.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [3,4,5,1,2]`  \
  **Explanation:** This array can be viewed as a rotation of [1,2,3,4,5]. Hence, the array can be rotated back into a sorted array, and the output is `true`.

- **Input:** `Input: nums = [2,1,3,4]`  \
  **Explanation:** This array cannot be rotated into a sorted array because there is a drop between `2` and `1` and it cannot be rotated to become sorted. Hence, the output is `false`.

{{< dots >}}
## Approach 🚀
We can solve this problem by checking how many times the array decreases while traversing it. If there is at most one decrease, the array can be rotated into a sorted order.

### Initial Thoughts 💭
- We can check for decreases in the array and count how many times the order is violated.
- If we encounter more than one decrease, the array cannot be rotated into a sorted form. We need to keep track of the number of decreases.
{{< dots >}}
### Edge Cases 🌐
- The problem guarantees that the array will have at least one element, so there will be no need to handle empty inputs.
- For large inputs, the solution should efficiently handle arrays of up to 100 elements.
- If all elements in the array are identical, the array is trivially sorted, so the result will be `true`.
- Ensure the solution handles arrays where elements are repeated or where there are only small changes between consecutive elements.
{{< dots >}}
## Code 💻
```cpp
bool check(vector<int>& nums) {
    int n = nums.size();
    int cnt = 0;
    for(int i=1;i<n;i++){
        if(nums[i-1]>nums[i]){
            cnt++;
        }
    }
    if(nums[n-1]>nums[0]){
        cnt++;
    }
    return cnt<=1;
}
```

The function checks if the array can be sorted in non-decreasing order by at most one rotation.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	bool check(vector<int>& nums) {
	```
	Declares a function to check if the input array can be sorted by at most one rotation.

2. **Variable Initialization**
	```cpp
	    int n = nums.size();
	```
	Initializes `n` to store the size of the input vector `nums`.

3. **Variable Initialization**
	```cpp
	    int cnt = 0;
	```
	Initializes a counter `cnt` to track the number of discontinuities in the array.

4. **Loop**
	```cpp
	    for(int i=1;i<n;i++){
	```
	Iterates through the array to check for descending pairs of elements.

5. **Conditional Check**
	```cpp
	        if(nums[i-1]>nums[i]){
	```
	Checks if the current pair of elements violates the non-decreasing order.

6. **Increment**
	```cpp
	            cnt++;
	```
	Increments the counter if a discontinuity is found.

7. **Conditional Check**
	```cpp
	    if(nums[n-1]>nums[0]){
	```
	Checks if the last element is greater than the first, indicating a discontinuity across the circular boundary.

8. **Increment**
	```cpp
	        cnt++;
	```
	Increments the counter if a discontinuity is found at the circular boundary.

9. **Return Statement**
	```cpp
	    return cnt<=1;
	```
	Returns true if there is at most one discontinuity in the array.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the length of the array.
- **Average Case:** O(n), as we scan through the array once.
- **Worst Case:** O(n), as we still only need to scan the array once.

The time complexity is linear, as we traverse the array only once.

### Space Complexity 💾
- **Best Case:** O(1), as no extra space is required.
- **Worst Case:** O(1), as the algorithm uses a constant amount of extra space.

The space complexity is constant because we are only using a few variables to track the state of the array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/)

---
{{< youtube uoEJ3FXr56w >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

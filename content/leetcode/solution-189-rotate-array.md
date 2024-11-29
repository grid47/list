
+++
authors = ["grid47"]
title = "Leetcode 189: Rotate Array"
date = "2024-10-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 189: Rotate Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Two Pointers"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/189.webp"
youtube = "lTHTR_jsqAQ"
youtube_upload_date="2020-01-23"
youtube_thumbnail="https://i.ytimg.com/vi_webp/lTHTR_jsqAQ/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/189.webp" 
    alt="An array gently rotating, with the elements shifting in a calming, circular motion."
    caption="Solution to LeetCode 189: Rotate Array Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given an integer array nums. Your task is to rotate the array to the right by k steps, where k is a non-negative integer.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array of integers nums and an integer k.
- **Example:** `nums = [10, 20, 30, 40, 50, 60, 70], k = 2`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- -231 <= nums[i] <= 231 - 1
	- 0 <= k <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is the rotated array after shifting its elements k steps to the right.
- **Example:** `[60, 70, 10, 20, 30, 40, 50]`
- **Constraints:**
	- The output array should be the result of rotating the input array by k steps.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to rotate the array in-place by shifting its elements to the right by k steps.

- Step 1: Calculate k modulo the length of the array to handle cases where k is larger than the array size.
- Step 2: Reverse the entire array.
- Step 3: Reverse the first k elements of the array.
- Step 4: Reverse the remaining elements from k to the end of the array.
{{< dots >}}
### Problem Assumptions ✅
- The input array will always contain at least one element.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [10, 20, 30, 40, 50, 60, 70], k = 2`  \
  **Explanation:** The list is [10, 20, 30, 40, 50, 60, 70]. After rotating 2 steps to the right, the array becomes [60, 70, 10, 20, 30, 40, 50].

{{< dots >}}
## Approach 🚀
The approach involves rotating the array using an in-place algorithm by reversing the array in segments.

### Initial Thoughts 💭
- The key observation is that rotating the array can be efficiently done by reversing sections of the array.
- Reversing the entire array and then reversing parts of it is an effective approach to achieve the desired rotation.
{{< dots >}}
### Edge Cases 🌐
- If the input array is empty, no rotation is needed.
- For large input arrays, ensure that the solution handles up to 10^5 elements efficiently.
- If k is zero, the array remains unchanged.
- The array will always contain at least one element.
{{< dots >}}
## Code 💻
```cpp
void rotate(vector<int>& nums, int k) {
    k = k % nums.size();
    rev(nums, 0, nums.size() - 1);
    rev(nums, 0, k - 1);
    rev(nums, k, nums.size() - 1);
    
}

void rev(vector<int>& nums, int i, int j) {
    while(i <= j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
        i++;
        j--;
    }
}
```

This code defines a solution for rotating an array to the right by 'k' steps using a reversal algorithm. The 'rev' helper function reverses parts of the array to achieve the final rotated order.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	void rotate(vector<int>& nums, int k) {
	```
	Define the function 'rotate' which takes a vector of integers 'nums' and an integer 'k', and rotates the array to the right by 'k' steps.

2. **Modulo Operation**
	```cpp
	    k = k % nums.size();
	```
	Adjust 'k' by taking the modulo with the size of the array. This ensures that if 'k' is larger than the array size, it will rotate the array the correct number of times.

3. **Reverse Array**
	```cpp
	    rev(nums, 0, nums.size() - 1);
	```
	Reverse the entire array to facilitate the rotating process. This step prepares the array for further segment reversals.

4. **Reverse First Segment**
	```cpp
	    rev(nums, 0, k - 1);
	```
	Reverse the first 'k' elements of the array. This step begins the transformation toward the rotated array.

5. **Reverse Second Segment**
	```cpp
	    rev(nums, k, nums.size() - 1);
	```
	Reverse the remaining elements from index 'k' to the end of the array. This completes the rotation process.

6. **Helper Function Definition**
	```cpp
	void rev(vector<int>& nums, int i, int j) {
	```
	Define the helper function 'rev' which reverses a segment of the array between indices 'i' and 'j'.

7. **While Loop**
	```cpp
	    while(i <= j) {
	```
	Start a while loop that runs until the indices 'i' and 'j' meet, which will swap elements in the array.

8. **Swap Elements**
	```cpp
	        int tmp = nums[i];
	```
	Store the element at index 'i' in a temporary variable 'tmp' to prepare for the swap.

9. **Swap Elements**
	```cpp
	        nums[i] = nums[j];
	```
	Replace the element at index 'i' with the element at index 'j'.

10. **Swap Elements**
	```cpp
	        nums[j] = tmp;
	```
	Replace the element at index 'j' with the value stored in 'tmp', completing the swap.

11. **Update Indices**
	```cpp
	        i++;
	```
	Increment the index 'i' to move towards the middle of the segment.

12. **Update Indices**
	```cpp
	        j--;
	```
	Decrement the index 'j' to move towards the middle of the segment.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the length of the array, as each reversal operation involves iterating through the array once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1), as the solution only requires a constant amount of extra space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/rotate-array/description/)

---
{{< youtube lTHTR_jsqAQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

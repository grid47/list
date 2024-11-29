
+++
authors = ["grid47"]
title = "Leetcode 31: Next Permutation"
date = "2024-11-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 31: Next Permutation in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/31.webp"
youtube = "6qXO72FkqwM"
youtube_upload_date="2021-05-04"
youtube_thumbnail="https://i.ytimg.com/vi_webp/6qXO72FkqwM/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/31.webp" 
    alt="A flowing sequence of shapes or words shifting and reshaping into a new, calming formation."
    caption="Solution to LeetCode 31: Next Permutation Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given an array of integers 'nums'. Find the next lexicographically greater permutation of the array. If no such permutation exists, return the smallest possible arrangement (sorted in ascending order). The result must be computed in place with no extra space.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is an array of integers 'nums' where each element is a non-negative integer.
- **Example:** `nums = [1,2,3]`
- **Constraints:**
	- 1 <= nums.length <= 100
	- 0 <= nums[i] <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is the next lexicographically greater permutation of the input array, or the smallest possible permutation if no greater permutation exists.
- **Example:** `For nums = [1,2,3], the output is [1,3,2].`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to determine the next permutation of the input array by modifying the array in place.

- Find the largest index 'i' such that nums[i] < nums[i+1]. If no such index exists, reverse the entire array.
- Find the largest index 'j' such that nums[j] > nums[i]. Swap nums[i] and nums[j].
- Reverse the sub-array from nums[i+1] to the end of the array.
{{< dots >}}
### Problem Assumptions ✅
- The array may contain repeated elements, which should be handled appropriately.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [1,2,3]`  \
  **Explanation:** The next permutation of [1,2,3] is [1,3,2] because 3 is the next greater number after 2 in the lexicographical order.

- **Input:** `nums = [3,2,1]`  \
  **Explanation:** The next permutation of [3,2,1] is [1,2,3] because no greater permutation exists, so the array is sorted in ascending order.

{{< dots >}}
## Approach 🚀
The approach involves modifying the array in place to find the next lexicographically greater permutation.

### Initial Thoughts 💭
- To find the next permutation, we need to identify the correct positions to swap and reverse.
- The process involves finding a 'pivot' point, performing a swap, and reversing the remaining elements.
- The algorithm should operate with a time complexity of O(n) since we only need to scan the array a few times.
{{< dots >}}
### Edge Cases 🌐
- There are no empty arrays; the array will have at least one element.
- Given that the array can contain up to 100 elements, the approach should work efficiently within this limit.
- If the array is already in descending order, the next permutation is the array sorted in ascending order.
- The array will not exceed 100 elements, and each element will not exceed 100.
{{< dots >}}
## Code 💻
```cpp
void nextPermutation(vector<int>& nums) {
    int idx = -1;
    for(int i = nums.size() - 2; i >= 0; i--) {
        if(nums[i] < nums[i+1]) { 
            idx = i;
            break;
        }
    }
    if(idx ==-1) {
        reverse(nums.begin(), nums.end());
        return;
    }
    for(int i = nums.size() - 1; i > idx; i--) {
        if(nums[i] > nums[idx]) {
            swap(nums[idx], nums[i]);
            break;
        }
    }
    reverse(nums.begin() + idx + 1, nums.end());
}
```

This code finds the next lexicographically greater permutation of a given array of integers.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	void nextPermutation(vector<int>& nums) {
	```
	This line declares a function named 'nextPermutation' that takes a vector of integers 'nums' by reference and modifies it to the next lexicographically greater permutation.

2. **Variable Initialization**
	```cpp
	    int idx = -1;
	```
	This line initializes an integer variable 'idx' to -1. This variable will be used to store the index of the pivot element, which is the element that will be swapped.

3. **Loop Iteration**
	```cpp
	    for(int i = nums.size() - 2; i >= 0; i--) {
	```
	This line starts a loop to iterate through the array from the second-to-last element to the beginning.

4. **Conditional Check**
	```cpp
	        if(nums[i] < nums[i+1]) { 
	```
	This line checks if the current element is smaller than the next element. If so, it means we've found the pivot element.

5. **Variable Update**
	```cpp
	            idx = i;
	```
	If the pivot element is found, its index is stored in the 'idx' variable.

6. **Early Termination**
	```cpp
	            break;
	```
	Once the pivot element is found, the loop is broken.

7. **Conditional Check**
	```cpp
	    if(idx ==-1) {
	```
	This line checks if the pivot element was not found. If not, it means the array is already in descending order, and the next permutation is the reverse of the current array.

8. **Array Manipulation**
	```cpp
	        reverse(nums.begin(), nums.end());
	```
	This line reverses the entire array to get the next permutation.

9. **Return**
	```cpp
	        return;
	```
	The function returns after reversing the array.

10. **Loop Iteration**
	```cpp
	    for(int i = nums.size() - 1; i > idx; i--) {
	```
	This line starts another loop to find the smallest element greater than the pivot element.

11. **Conditional Check**
	```cpp
	        if(nums[i] > nums[idx]) {
	```
	This line checks if the current element is greater than the pivot element.

12. **Array Manipulation**
	```cpp
	            swap(nums[idx], nums[i]);
	```
	If a suitable element is found, it's swapped with the pivot element.

13. **Early Termination**
	```cpp
	            break;
	```
	The loop is broken after the swap.

14. **Array Manipulation**
	```cpp
	    reverse(nums.begin() + idx + 1, nums.end());
	```
	This line reverses the subarray from the pivot element to the end to get the next lexicographically greater permutation.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because we scan the array from right to left and perform constant-time operations like swaps and reversals.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) because the solution is implemented in place with no additional space used.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/next-permutation/description/)

---
{{< youtube 6qXO72FkqwM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

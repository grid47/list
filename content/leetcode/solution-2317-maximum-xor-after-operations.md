
+++
authors = ["grid47"]
title = "Leetcode 2317: Maximum XOR After Operations "
date = "2024-03-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2317: Maximum XOR After Operations  in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "aNgStAspl4M"
youtube_upload_date="2022-06-25"
youtube_thumbnail="https://i.ytimg.com/vi_webp/aNgStAspl4M/maxresdefault.webp"
comments = true
+++



---
You are given an integer array nums. In each operation, select a non-negative integer x and an index i, then update nums[i] to be equal to nums[i] AND (nums[i] XOR x). The task is to find the maximum possible bitwise XOR of all elements after applying the operation any number of times.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array nums where 1 <= nums.length <= 10^5 and 0 <= nums[i] <= 10^8.
- **Example:** `nums = [5, 7, 3, 10]`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- 0 <= nums[i] <= 10^8

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum possible bitwise XOR of all elements after applying the operation any number of times.
- **Example:** `For nums = [5, 7, 3, 10], the output is 15.`
- **Constraints:**
	- The result is a non-negative integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to calculate the maximum bitwise XOR achievable after applying the operation on the array any number of times.

- 1. Iterate over the entire array and calculate the OR of all elements.
- 2. Return the OR result, which represents the maximum possible XOR after applying the operations.
{{< dots >}}
### Problem Assumptions ✅
- The array nums is non-empty.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [5, 7, 3, 10]`  \
  **Explanation:** In this example, applying the operation with x = 5 at index 3 gives us nums = [5, 7, 3, 0]. The XOR of these elements is 15, which is the maximum possible XOR.

{{< dots >}}
## Approach 🚀
To achieve the maximum bitwise XOR of all elements, the operation modifies the array in a way that the result is influenced by the bitwise OR of the elements.

### Initial Thoughts 💭
- The operation essentially affects the bits of each element, and we are interested in maximizing the XOR across the entire array.
- The operation will allow us to manipulate the bits of the elements, but the final result can be determined by the OR of all elements.
{{< dots >}}
### Edge Cases 🌐
- If the array is empty, the result should be 0.
- The algorithm should efficiently handle large arrays with up to 10^5 elements.
- If all elements are zero, the result will be 0.
- Ensure that large inputs are processed efficiently within time limits.
{{< dots >}}
## Code 💻
```cpp
int maximumXOR(vector<int>& nums) {
    
    int mask = 0;
    
    for(auto it : nums) {
        mask |= it;
    }
    
    return mask;
}
```

This function calculates the bitwise OR of all numbers in the array `nums` to find the maximum possible XOR that can be achieved using any subset of the numbers. The function iterates over each number, updating the mask with the bitwise OR result.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Method Declaration**
	```cpp
	int maximumXOR(vector<int>& nums) {
	```
	Declare the method `maximumXOR` which takes a vector of integers `nums` as input and returns an integer representing the maximum XOR achievable.

2. **Variable Initialization**
	```cpp
	    int mask = 0;
	```
	Initialize a variable `mask` to store the cumulative result of the bitwise OR operation over all elements of `nums`. Initially set to 0.

3. **Loop Initialization**
	```cpp
	    for(auto it : nums) {
	```
	Start a loop to iterate over each element `it` in the vector `nums`.

4. **Bitwise OR Operation**
	```cpp
	        mask |= it;
	```
	For each number `it` in `nums`, perform a bitwise OR operation with the current `mask` value, updating `mask` to include the bits set by `it`.

5. **Return Statement**
	```cpp
	    return mask;
	```
	Return the final value of `mask`, which holds the result of the bitwise OR of all elements in `nums`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the length of the array, as we iterate over the array once to compute the OR.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1), as we only need a constant amount of extra space to store the mask.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-xor-after-operations/description/)

---
{{< youtube aNgStAspl4M >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |


+++
authors = ["grid47"]
title = "Leetcode 2527: Find Xor-Beauty of Array"
date = "2024-02-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2527: Find Xor-Beauty of Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "V12dkKaSdnw"
youtube_upload_date="2023-01-07"
youtube_thumbnail="https://i.ytimg.com/vi/V12dkKaSdnw/maxresdefault.jpg"
comments = true
+++



---
You are given an integer array nums. The xor-beauty of the array is the XOR of the effective values of all possible triplets of indices (i, j, k) where 0 <= i, j, k < n. The effective value for each triplet is calculated as ((nums[i] | nums[j]) & nums[k]).
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a list of integers nums.
- **Example:** `[3, 7]`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- 1 <= nums[i] <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the xor-beauty of the array, which is the XOR of the effective values for all triplets of indices (i, j, k).
- **Example:** `4`
- **Constraints:**
	- The output will be a single integer representing the xor-beauty of the array.

{{< dots >}}
### Core Logic 🔍
**Goal:** To calculate the xor-beauty by XORing all the effective values of triplets of indices in the array.

- Iterate through all possible triplets (i, j, k).
- For each triplet, compute the effective value ((nums[i] | nums[j]) & nums[k]).
- XOR all the computed effective values to obtain the final result.
{{< dots >}}
### Problem Assumptions ✅
- The length of the array and the size of the numbers will fit within the given constraints.
- The solution should handle large inputs efficiently.
{{< dots >}}
## Examples 🧩
- **Input:** `[3, 7]`  \
  **Explanation:** The xor-beauty is calculated by XORing the effective values of all the triplets of indices in the array, resulting in the final value of 4.

- **Input:** `[15, 22, 11, 8, 40]`  \
  **Explanation:** The xor-beauty of the array is calculated by XORing the effective values of all possible triplets, and the result is 22.

{{< dots >}}
## Approach 🚀
The solution involves iterating over all possible triplets and calculating the effective values by applying bitwise OR and AND operations. The final result is obtained by XORing all the effective values.

### Initial Thoughts 💭
- This problem involves iterating over all triplets and performing bitwise operations, which can be optimized by reducing the number of calculations.
- Given the constraints, a direct approach that computes the XOR for each possible triplet will be inefficient. We need to explore optimizations or mathematical insights for faster computation.
{{< dots >}}
### Edge Cases 🌐
- There are no empty inputs since the length of nums is always at least 1.
- Ensure that the solution can handle large arrays efficiently, especially when nums.length is close to 10^5.
- Handle cases where all numbers in nums are the same.
- Ensure that the time complexity is optimized for large inputs.
{{< dots >}}
## Code 💻
```cpp
int xorBeauty(vector<int>& nums) {
    
    int tmp = 0;
    for(int it: nums)
        tmp ^= it;
    return tmp;
    
}
```

The 'xorBeauty' function calculates the XOR of all the elements in the input vector 'nums' and returns the result.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int xorBeauty(vector<int>& nums) {
	```
	This is the definition of the 'xorBeauty' function which takes a reference to a vector of integers 'nums' and returns an integer result.

2. **Variable Initialization**
	```cpp
	    int tmp = 0;
	```
	Here, a temporary variable 'tmp' is initialized to 0. This variable will store the result of the cumulative XOR operation.

3. **Loop**
	```cpp
	    for(int it: nums)
	```
	This is a range-based for loop that iterates through each element 'it' in the 'nums' vector.

4. **XOR Operation**
	```cpp
	        tmp ^= it;
	```
	In each iteration of the loop, the XOR operation is performed between the current value of 'tmp' and the element 'it'. This accumulates the XOR of all elements in the vector.

5. **Return Statement**
	```cpp
	    return tmp;
	```
	After completing the loop, the function returns the final value of 'tmp', which is the cumulative XOR of all elements in the 'nums' vector.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^3)
- **Average Case:** O(n^3)
- **Worst Case:** O(n^3)

The time complexity is O(n^3) because we need to consider every triplet in the array for calculating the effective values.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) as we only need a constant amount of extra space for the XOR calculation.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-xor-beauty-of-array/description/)

---
{{< youtube V12dkKaSdnw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

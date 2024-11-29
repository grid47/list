
+++
authors = ["grid47"]
title = "Leetcode 2357: Make Array Zero by Subtracting Equal Amounts"
date = "2024-03-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2357: Make Array Zero by Subtracting Equal Amounts in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Greedy","Sorting","Heap (Priority Queue)","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "rtGJycuTSUo"
youtube_upload_date="2022-07-31"
youtube_thumbnail="https://i.ytimg.com/vi_webp/rtGJycuTSUo/maxresdefault.webp"
comments = true
+++



---
You are given a non-negative integer array nums. In each operation, you must:

- Choose a positive integer x that is less than or equal to the smallest non-zero element in nums.
- Subtract x from every positive element in nums.

Return the minimum number of operations to make every element in nums equal to 0.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array nums where each element is a non-negative integer.
- **Example:** `Input: nums = [1, 5, 0, 3, 5]`
- **Constraints:**
	- 1 <= nums.length <= 100
	- 0 <= nums[i] <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an integer representing the minimum number of operations required.
- **Example:** `Output: 3`
- **Constraints:**
	- The output will always be a non-negative integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** Sort the input array and calculate the number of operations based on distinct positive elements.

- Sort the input array.
- Iterate over the array and count how many distinct non-zero elements exist.
- For each distinct positive element, consider an operation to reduce those elements to zero.
{{< dots >}}
### Problem Assumptions ✅
- All elements in nums are non-negative integers.
- At least one element in nums is positive.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: nums = [1, 5, 0, 3, 5]`  \
  **Explanation:** In this case, we perform three operations: subtract 1 from all elements (resulting in [0, 4, 0, 2, 4]), subtract 2 from all elements (resulting in [0, 2, 0, 0, 2]), and finally subtract 2 again (resulting in [0, 0, 0, 0, 0]). Thus, the output is 3.

{{< dots >}}
## Approach 🚀
The approach is to sort the array and calculate the number of operations based on distinct positive elements in the array.

### Initial Thoughts 💭
- We can sort the array to easily track the smallest non-zero element.
- We need to perform operations for each distinct positive element in the array.
{{< dots >}}
### Edge Cases 🌐
- If the array has only zeroes, the output should be 0.
- Even with the largest possible input size (100 elements), sorting and iterating through the array will be efficient enough.
- If all elements are zero, no operation is needed.
- Ensure that only positive elements are considered when counting operations.
{{< dots >}}
## Code 💻
```cpp
int minimumOperations(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int mx = 0, res = 0, diff;
    for(int i = 0; i < nums.size(); i++) {
        if(mx < nums[i]) {
            mx = nums[i];
            res++;
        }
    }
    return res;
}
```

This function calculates the minimum number of operations required to make all elements of the array equal, where an operation consists of picking a larger number and updating it to the current maximum.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int minimumOperations(vector<int>& nums) {
	```
	Defines the function `minimumOperations`, which takes a vector of integers `nums` and returns an integer representing the minimum operations needed.

2. **Sorting**
	```cpp
	    sort(nums.begin(), nums.end());
	```
	Sorts the vector `nums` in ascending order to facilitate comparison between the current element and the maximum element.

3. **Variable Initialization**
	```cpp
	    int mx = 0, res = 0, diff;
	```
	Initializes `mx` to track the maximum number encountered, `res` to count the number of operations, and `diff` which is unused in this case.

4. **Loop**
	```cpp
	    for(int i = 0; i < nums.size(); i++) {
	```
	Loops through each element of the sorted `nums` array.

5. **Condition Check**
	```cpp
	        if(mx < nums[i]) {
	```
	Checks if the current number is greater than the previously encountered maximum `mx`.

6. **Update Maximum**
	```cpp
	            mx = nums[i];
	```
	Updates `mx` to the current number `nums[i]` if it is greater.

7. **Increment Operation Count**
	```cpp
	            res++;
	```
	Increments the operation count `res` each time a new maximum is found, implying a change operation.

8. **Return Result**
	```cpp
	    return res;
	```
	Returns the total number of operations performed.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The worst-case time complexity is O(n log n) due to sorting the array.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the array being stored in memory.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/make-array-zero-by-subtracting-equal-amounts/description/)

---
{{< youtube rtGJycuTSUo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

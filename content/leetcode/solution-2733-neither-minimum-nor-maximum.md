
+++
authors = ["grid47"]
title = "Leetcode 2733: Neither Minimum nor Maximum"
date = "2024-02-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2733: Neither Minimum nor Maximum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sorting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "n6Wg_vntUAA"
youtube_upload_date="2023-06-11"
youtube_thumbnail="https://i.ytimg.com/vi_webp/n6Wg_vntUAA/maxresdefault.webp"
comments = true
+++



---
You are given an array `nums` containing distinct positive integers. Your task is to find and return any number from the array that is neither the smallest nor the largest number, or return -1 if no such number exists.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a single array `nums` of integers.
- **Example:** `nums = [4, 2, 1, 3]`
- **Constraints:**
	- 1 <= nums.length <= 100
	- 1 <= nums[i] <= 100
	- All values in nums are distinct.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return any integer from the array that is neither the minimum nor the maximum value, or return -1 if no such number exists.
- **Example:** `Output: 2`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find an integer from the array that is neither the smallest nor the largest number.

- Check if the array has less than 3 elements. If true, return -1.
- Find the minimum and maximum values in the array.
- Loop through the array and return any number that is not the minimum or maximum.
{{< dots >}}
### Problem Assumptions ✅
- All integers in the array are distinct.
- The array length is at least 2.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [4, 2, 1, 3]`  \
  **Explanation:** In this example, the minimum value is 1 and the maximum value is 4. Therefore, 2 or 3 can be valid answers.

- **Input:** `nums = [1, 2]`  \
  **Explanation:** Since the array has only two elements, no element is both non-minimal and non-maximal. Therefore, the output is -1.

{{< dots >}}
## Approach 🚀
The problem is solved by finding the minimum and maximum values, then checking for any element that lies between them.

### Initial Thoughts 💭
- We can solve the problem by simply finding the min and max values in the array.
- The problem is straightforward with a time complexity of O(n).
- If the array has less than 3 elements, return -1 immediately.
{{< dots >}}
### Edge Cases 🌐
- The array has less than 3 elements.
- Consider testing with arrays of size 100.
- The array has only two distinct values.
- All values are distinct, so the result is deterministic.
{{< dots >}}
## Code 💻
```cpp
int findNonMinOrMax(vector<int>& A) {
    if (A.size() < 3)
        return -1;
    int mx = max(A[0], max(A[1], A[2])), mn = min(A[0], min(A[1], A[2]));
    for (int i = 0; i < 3; ++i)
        if (mn < A[i] && A[i] < mx)
            return A[i];
    return -1;
}
```

This function finds a number in the array `A` that is neither the minimum nor the maximum value in the first three elements. If such a number is found, it is returned. Otherwise, -1 is returned.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int findNonMinOrMax(vector<int>& A) {
	```
	The function `findNonMinOrMax` is defined to take a reference to a vector of integers `A` as input and return an integer.

2. **Condition Check**
	```cpp
	    if (A.size() < 3)
	```
	The function checks if the size of the vector `A` is less than 3. If true, it returns -1 as a result, since it requires at least 3 elements to find a non-minimum and non-maximum value.

3. **Return Statement**
	```cpp
	        return -1;
	```
	If the size of the vector `A` is less than 3, the function immediately returns -1.

4. **Variable Initialization**
	```cpp
	    int mx = max(A[0], max(A[1], A[2])), mn = min(A[0], min(A[1], A[2]));
	```
	The variables `mx` and `mn` are initialized to store the maximum and minimum values among the first three elements of the vector `A`.

5. **Loop Start**
	```cpp
	    for (int i = 0; i < 3; ++i)
	```
	A for-loop is initiated to iterate over the first three elements of the vector `A`.

6. **Conditional Check**
	```cpp
	        if (mn < A[i] && A[i] < mx)
	```
	Inside the loop, the function checks if the current element `A[i]` is greater than the minimum value `mn` and less than the maximum value `mx`. If true, this element is returned as the result.

7. **Return Statement**
	```cpp
	            return A[i];
	```
	If the current element satisfies the condition of being neither the minimum nor the maximum, it is returned as the result.

8. **Return Statement**
	```cpp
	    return -1;
	```
	If no element satisfies the condition within the loop, the function returns -1, indicating no such element exists.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1) when there are only two elements.
- **Average Case:** O(n) where n is the number of elements in the array.
- **Worst Case:** O(n) because we need to find the minimum and maximum of the array.

Finding the minimum and maximum takes linear time.

### Space Complexity 💾
- **Best Case:** O(1) when the array has minimal elements.
- **Worst Case:** O(1) because we only store a few extra variables.

The space complexity is constant as no additional space is required.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/neither-minimum-nor-maximum/description/)

---
{{< youtube n6Wg_vntUAA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

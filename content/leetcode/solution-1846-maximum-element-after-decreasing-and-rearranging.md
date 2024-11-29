
+++
authors = ["grid47"]
title = "Leetcode 1846: Maximum Element After Decreasing and Rearranging"
date = "2024-05-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1846: Maximum Element After Decreasing and Rearranging in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "o_hVl8IXuIE"
youtube_upload_date="2023-11-15"
youtube_thumbnail="https://i.ytimg.com/vi/o_hVl8IXuIE/maxresdefault.jpg"
comments = true
+++



---
You are given an array of positive integers arr. Perform a series of operations (possibly none) on arr to make it satisfy the following conditions: The value of the first element in arr must be 1, and the absolute difference between any two adjacent elements must be less than or equal to 1. You can decrease the value of any element and rearrange the elements in any order. Return the maximum possible value of an element in arr after performing the operations.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an array of positive integers. The operations allowed are to rearrange the array and decrease the value of any element.
- **Example:** `[3, 2, 1, 3, 1]`
- **Constraints:**
	- 1 <= arr.length <= 10^5
	- 1 <= arr[i] <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum value of an element in the array after performing the operations that satisfy the given conditions.
- **Example:** `3`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to rearrange and possibly decrease values in the array to ensure the first element is 1 and the absolute difference between adjacent elements is less than or equal to 1.

- Sort the array to make the smallest elements come first.
- Set the first element to 1 if it's not already.
- For each element after the first, ensure that the difference between the current element and the previous one is no greater than 1. If it is, decrease the current element to be one greater than the previous element.
- The largest element after modifications will be the result.
{{< dots >}}
### Problem Assumptions ✅
- The input array is guaranteed to contain positive integers.
- The array will have at least one element.
{{< dots >}}
## Examples 🧩
- **Input:** `[3, 2, 1, 3, 1]`  \
  **Explanation:** After rearranging and adjusting the values, the largest element in the array is 3.

{{< dots >}}
## Approach 🚀
The solution approach is to first sort the array to make it easier to adjust the elements and then iteratively decrease elements where necessary while ensuring that adjacent elements differ by no more than 1.

### Initial Thoughts 💭
- Sorting the array simplifies the process of making adjustments between adjacent elements.
- By iterating over the sorted array and adjusting elements that violate the absolute difference condition, we can efficiently arrive at the correct answer.
{{< dots >}}
### Edge Cases 🌐
- There are no empty inputs, as the array always has at least one element.
- For large inputs, ensure that the sorting and adjustments are efficient enough to handle up to 100,000 elements.
- Consider arrays where all elements are the same or where they are already in a sequence that satisfies the conditions.
- The operations should be efficient to handle arrays of length up to 100,000.
{{< dots >}}
## Code 💻
```cpp
int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
    
    sort(arr.begin(), arr.end());
    
    if(arr[0] != 1) arr[0] = 1;
    
    int n = arr.size();
    
    for(int i = 1; i < n; i++) {
        if(arr[i] - arr[i - 1] > 1) arr[i] = arr[i - 1] + 1;
    }
    return arr[n - 1];
}
```

This function rearranges and adjusts the given array such that each element is decreased or rearranged to meet a certain condition. It ensures that each element is either equal to or greater than its predecessor, while returning the maximum element after the operation.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
	```
	Defines the function `maximumElementAfterDecrementingAndRearranging`, which accepts a vector `arr` and returns an integer.

2. **Sorting**
	```cpp
	    sort(arr.begin(), arr.end());
	```
	Sorts the array `arr` in ascending order.

3. **Condition Check**
	```cpp
	    if(arr[0] != 1) arr[0] = 1;
	```
	Checks if the first element in the sorted array is not 1, and if so, sets it to 1.

4. **Array Size Calculation**
	```cpp
	    int n = arr.size();
	```
	Calculates the size of the array `arr` and stores it in the variable `n`.

5. **Loop Start**
	```cpp
	    for(int i = 1; i < n; i++) {
	```
	Starts a loop from the second element in the array to the end.

6. **Condition Check Inside Loop**
	```cpp
	        if(arr[i] - arr[i - 1] > 1) arr[i] = arr[i - 1] + 1;
	```
	Checks if the difference between the current element and the previous element is greater than 1. If so, it adjusts the current element to be one greater than the previous element.

7. **Return Statement**
	```cpp
	    return arr[n - 1];
	```
	Returns the last element in the array, which is now the maximum after adjustments.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The time complexity is dominated by the sorting step, which takes O(n log n), where n is the length of the array.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n) due to the space required for sorting the array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/description/)

---
{{< youtube o_hVl8IXuIE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

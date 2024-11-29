
+++
authors = ["grid47"]
title = "Leetcode 2161: Partition Array According to Given Pivot"
date = "2024-04-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2161: Partition Array According to Given Pivot in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "Ie7eN2NAa6w"
youtube_upload_date="2022-02-05"
youtube_thumbnail="https://i.ytimg.com/vi_webp/Ie7eN2NAa6w/maxresdefault.webp"
comments = true
+++



---
You are given an integer array 'nums' and a value 'pivot'. Your task is to rearrange the elements in 'nums' such that all elements less than 'pivot' appear before any element greater than 'pivot', and all elements equal to 'pivot' appear between the elements less than and greater than 'pivot'. The relative order of the elements less than and greater than 'pivot' should be preserved.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array 'nums' and an integer 'pivot'.
- **Example:** `nums = [15, 20, 10, 25, 10, 5], pivot = 10`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- -10^6 <= nums[i] <= 10^6
	- pivot is an element in nums.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be the array 'nums' after rearranging it according to the conditions described in the problem statement.
- **Example:** `[5, 10, 10, 15, 20, 25]`
- **Constraints:**
	- The output must preserve the relative order of elements less than and greater than pivot.

{{< dots >}}
### Core Logic 🔍
**Goal:** Rearrange the elements in nums such that all elements less than pivot come first, followed by elements equal to pivot, and then elements greater than pivot.

- Count the number of elements less than pivot, equal to pivot, and greater than pivot.
- Allocate space for the rearranged array.
- Place elements less than pivot first, then the pivot elements, and finally the elements greater than pivot, maintaining the relative order.
{{< dots >}}
### Problem Assumptions ✅
- The input will always contain a valid pivot, and there will always be at least one element equal to pivot in nums.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: nums = [15, 20, 10, 25, 10, 5], pivot = 10`  \
  **Explanation:** The elements 5 are less than the pivot and appear before the 10's. The pivot 10's are in the middle, and the elements greater than 10 (15, 20, 25) appear last.

- **Input:** `Example 2: nums = [2, 3, 1, 4, 1], pivot = 3`  \
  **Explanation:** The element 2 and 1 are less than the pivot and appear first, followed by 3, and finally 4, maintaining the original order.

{{< dots >}}
## Approach 🚀
The approach is to count the number of elements less than pivot, equal to pivot, and greater than pivot. Then, use these counts to rearrange the elements in the desired order while maintaining relative ordering.

### Initial Thoughts 💭
- Sorting is not required since we only need to rearrange the elements based on their values relative to pivot.
- This is a counting problem where the relative order within groups of less than, equal to, and greater than pivot must be preserved.
{{< dots >}}
### Edge Cases 🌐
- There are no empty inputs because nums has at least one element.
- The solution should efficiently handle arrays with the maximum length of 100,000 elements.
- Special values such as the minimum and maximum values for nums[i] and pivot (-10^6, 10^6) should be handled correctly.
- The solution must handle large inputs efficiently.
{{< dots >}}
## Code 💻
```cpp
vector<int> pivotArray(vector<int>& nums, int pivot) {
    int low = 0, same = 0, high;
    for(auto num: nums) {
        if(num < pivot) low++;
        else if(num == pivot) same++;
    }
    high = low + same;
    same = low;
    low = 0;
    vector<int> res(nums.size(), 0);
    for(auto num: nums) {
        if(num < pivot) res[low++] = num;
        else if(num == pivot) res[same++] = num;
        else res[high++] = num;
    }
    return res;
}
```

This function reorders the array such that elements less than the pivot appear first, followed by elements equal to the pivot, and then elements greater than the pivot.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<int> pivotArray(vector<int>& nums, int pivot) {
	```
	Define a function `pivotArray` that accepts a reference to a vector of integers `nums` and an integer `pivot`.

2. **Variable Initialization**
	```cpp
	    int low = 0, same = 0, high;
	```
	Initialize three variables: `low` for elements less than the pivot, `same` for elements equal to the pivot, and `high` for elements greater than the pivot.

3. **Loop Start**
	```cpp
	    for(auto num: nums) {
	```
	Iterate over each element `num` in the vector `nums`.

4. **Condition Check (Low)**
	```cpp
	        if(num < pivot) low++;
	```
	If the element `num` is less than the pivot, increment the `low` counter.

5. **Condition Check (Same)**
	```cpp
	        else if(num == pivot) same++;
	```
	If the element `num` is equal to the pivot, increment the `same` counter.

6. **High Calculation**
	```cpp
	    high = low + same;
	```
	Set `high` as the sum of `low` and `same`, as `high` starts after the elements equal to the pivot.

7. **Reassign Same**
	```cpp
	    same = low;
	```
	Reassign the `same` variable to the value of `low` since elements equal to the pivot will be placed after the elements less than the pivot.

8. **Reset Low**
	```cpp
	    low = 0;
	```
	Reset the `low` counter to zero for use in the second loop.

9. **Result Vector Initialization**
	```cpp
	    vector<int> res(nums.size(), 0);
	```
	Create a result vector `res` of the same size as `nums`, initialized with zeroes, to store the reordered elements.

10. **Second Loop Start**
	```cpp
	    for(auto num: nums) {
	```
	Iterate over each element `num` in the vector `nums` again to place them in the result vector `res`.

11. **Condition Check (Low) - Second Loop**
	```cpp
	        if(num < pivot) res[low++] = num;
	```
	If `num` is less than the pivot, assign it to the `res` vector at the `low` index and increment `low`.

12. **Condition Check (Same) - Second Loop**
	```cpp
	        else if(num == pivot) res[same++] = num;
	```
	If `num` is equal to the pivot, assign it to the `res` vector at the `same` index and increment `same`.

13. **Condition Check (High) - Second Loop**
	```cpp
	        else res[high++] = num;
	```
	If `num` is greater than the pivot, assign it to the `res` vector at the `high` index and increment `high`.

14. **Return Result**
	```cpp
	    return res;
	```
	Return the reordered result vector `res`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear in the size of the input array.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

We are using additional space for the result array, which is of the same size as the input array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/partition-array-according-to-given-pivot/description/)

---
{{< youtube Ie7eN2NAa6w >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

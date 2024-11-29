
+++
authors = ["grid47"]
title = "Leetcode 2148: Count Elements With Strictly Smaller and Greater Elements "
date = "2024-04-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2148: Count Elements With Strictly Smaller and Greater Elements  in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sorting","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "V3SamYLfPtg"
youtube_upload_date="2022-01-23"
youtube_thumbnail="https://i.ytimg.com/vi_webp/V3SamYLfPtg/maxresdefault.webp"
comments = true
+++



---
You are given an integer array 'nums'. Your task is to return the count of elements in the array that have both a strictly smaller and a strictly greater number in the array. Each element should have at least one number strictly smaller and one number strictly greater.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a single integer array 'nums'.
- **Example:** `nums = [5, 8, 1, 10]`
- **Constraints:**
	- 1 <= nums.length <= 100
	- -105 <= nums[i] <= 105

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is a single integer representing the count of elements in the array that satisfy the given condition.
- **Example:** `Output: 2`
- **Constraints:**
	- The result should be a non-negative integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** We aim to count the number of elements in 'nums' that have both a strictly smaller and a strictly greater element.

- Sort the array to easily compare neighboring elements.
- Identify the range where there are both smaller and larger elements than the current element.
- Count elements that satisfy the condition.
{{< dots >}}
### Problem Assumptions ✅
- The input array contains at least one element.
- The array may contain duplicate elements.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: nums = [5, 8, 1, 10]`  \
  **Explanation:** The element '8' has both a smaller element '1' and a greater element '10'. Similarly, '5' has a smaller element '1' and a greater element '8'. Thus, two elements satisfy the condition.

{{< dots >}}
## Approach 🚀
We can solve this problem by sorting the array and then finding elements that have both smaller and greater elements in the sorted array.

### Initial Thoughts 💭
- Sorting the array helps in easily finding elements that have both smaller and larger neighbors.
- We need to traverse the sorted array and count the elements that meet the criteria.
{{< dots >}}
### Edge Cases 🌐
- An empty array is not valid per the constraints.
- The solution should handle the maximum size of the input array efficiently.
- Arrays with all identical elements should return 0.
- Ensure that the array is sorted before making comparisons.
{{< dots >}}
## Code 💻
```cpp
int countElements(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int res = 0, l = -1, r = -1, n = nums.size();
    for(int i = 1; i < n; i++) {
        if(nums[i] > nums[i - 1]) {
          l = i;
          break;
        }
    }
    for(int i = n - 1; i > 0; i--) {
        if(nums[i] > nums[i - 1]) {
          r = i;
          break;
        }
    }
    if(l < r) return r - l;
    return 0;
}
```

This function sorts the input vector and finds the positions of the first and last elements that are out of order, returning the count of elements between these positions.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Start**
	```cpp
	int countElements(vector<int>& nums) {
	```
	The function begins. The input vector `nums` is passed by reference.

2. **Sort Array**
	```cpp
	    sort(nums.begin(), nums.end());
	```
	Sort the input array to prepare for identifying the unsorted segment.

3. **Variable Initialization**
	```cpp
	    int res = 0, l = -1, r = -1, n = nums.size();
	```
	Initialize variables: `res` (result), `l` (left index), `r` (right index), and `n` (size of the array).

4. **Forward Iteration**
	```cpp
	    for(int i = 1; i < n; i++) {
	```
	Start a loop to iterate from the second element to the end of the sorted array.

5. **Check Left Bound**
	```cpp
	        if(nums[i] > nums[i - 1]) {
	```
	Check if the current element is greater than the previous one, identifying the first unordered pair.

6. **Set Left Index**
	```cpp
	          l = i;
	```
	Set the left index `l` to the current position where the first unordered element is found.

7. **Break Loop**
	```cpp
	          break;
	```
	Break out of the loop once the left boundary is identified.

8. **Backward Iteration**
	```cpp
	    for(int i = n - 1; i > 0; i--) {
	```
	Start a loop to iterate from the last element to the first in reverse order.

9. **Check Right Bound**
	```cpp
	        if(nums[i] > nums[i - 1]) {
	```
	Check if the current element is greater than the previous one, identifying the second unordered pair.

10. **Set Right Index**
	```cpp
	          r = i;
	```
	Set the right index `r` to the current position where the second unordered element is found.

11. **Break Loop**
	```cpp
	          break;
	```
	Break out of the loop once the right boundary is identified.

12. **Check Unsorted Segment**
	```cpp
	    if(l < r) return r - l;
	```
	If the left index `l` is less than the right index `r`, return the difference between them as the length of the unsorted segment.

13. **Return Result**
	```cpp
	    return 0;
	```
	Return 0 if no unsorted segment was found.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The time complexity is determined by the sorting step, which takes O(n log n).

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant since we only use a few variables for counting and comparisons.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/count-elements-with-strictly-smaller-and-greater-elements/description/)

---
{{< youtube V3SamYLfPtg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

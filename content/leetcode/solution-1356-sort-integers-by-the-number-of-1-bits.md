
+++
authors = ["grid47"]
title = "Leetcode 1356: Sort Integers by The Number of 1 Bits"
date = "2024-06-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1356: Sort Integers by The Number of 1 Bits in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Bit Manipulation","Sorting","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++



---
You are given an array of integers. Sort the array based on the number of 1's in the binary representation of each integer. If two integers have the same number of 1's, sort them in ascending order of the integer value.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array of integers.
- **Example:** `For example, [5, 3, 9, 8, 6, 7, 2, 4, 1] where each integer is sorted based on the number of 1's in their binary form.`
- **Constraints:**
	- 1 <= arr.length <= 500
	- 0 <= arr[i] <= 10^4

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is a sorted array of integers based on the number of 1's in their binary representation. If two integers have the same number of 1's, they are sorted in ascending order of value.
- **Example:** `For input [5, 3, 9, 8, 6, 7, 2, 4, 1], the output is [1, 2, 4, 8, 3, 5, 6, 7, 9].`
- **Constraints:**
	- The result should be a non-empty array with integers in the sorted order.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to sort the array of integers first by the number of 1's in their binary representation, and second by their integer value in case of ties.

- 1. For each number in the array, calculate the number of 1's in its binary representation.
- 2. Sort the array using a custom comparator: first by the count of 1's in the binary representation, and then by the integer value for numbers with the same number of 1's.
- 3. Return the sorted array.
{{< dots >}}
### Problem Assumptions ✅
- The array is not empty.
- We assume the input array will always contain integers within the specified constraints.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: [5, 3, 9, 8, 6, 7, 2, 4, 1]`  \
  **Explanation:** We first count the number of 1's in the binary representation of each number. Then we sort by the number of 1's, and for numbers with the same count, we sort them by value.

- **Input:** `Example 2: [1024, 512, 256, 128, 64, 32, 16, 8, 4, 2, 1]`  \
  **Explanation:** All numbers have exactly 1 bit in their binary representation, so we sort them in ascending order.

{{< dots >}}
## Approach 🚀
To solve this problem, we calculate the number of 1's in the binary representation of each number and then sort the array based on this number and the integer value.

### Initial Thoughts 💭
- Sorting by binary 1's is a unique way to order the numbers.
- The number of bits for each integer is easy to calculate using built-in functions.
- The sorting approach should be efficient enough for the problem's constraints.
{{< dots >}}
### Edge Cases 🌐
- The input will always contain at least one element, so we don't need to handle empty arrays.
- For large arrays, the sorting algorithm should efficiently handle up to 500 elements.
- All elements could be the same, or all could have the same number of 1's in their binary representation.
- The solution should sort the array efficiently within the given input size.
{{< dots >}}
## Code 💻
```cpp
vector<int> sortByBits(vector<int>& arr) {
    
    sort(arr.begin(), arr.end(), cmp);

    return arr;
}
```

This function sorts an array of integers based on the number of set bits (1's) in their binary representation, using a custom comparator 'cmp'.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<int> sortByBits(vector<int>& arr) {
	```
	This line declares the 'sortByBits' function, which takes a reference to a vector of integers as input and returns a sorted vector of integers.

2. **Sort Function**
	```cpp
	    sort(arr.begin(), arr.end(), cmp);
	```
	Here, the standard 'sort' function is used to sort the input vector 'arr'. The custom comparator 'cmp' is applied to determine the sorting order, which is based on the number of set bits in the binary representation of each integer.

3. **Return Statement**
	```cpp
	    return arr;
	```
	The sorted array 'arr' is returned after the sorting operation.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n) for sorting the array where n is the length of the array.
- **Average Case:** O(n log n) for sorting with custom comparison.
- **Worst Case:** O(n log n), where n is the number of elements in the array.

The time complexity is dominated by the sorting step.

### Space Complexity 💾
- **Best Case:** O(1) if no additional space is required outside the input.
- **Worst Case:** O(n) for the space used by the input array and sorting process.

The space complexity is mainly determined by the size of the input array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

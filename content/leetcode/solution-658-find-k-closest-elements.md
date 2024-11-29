
+++
authors = ["grid47"]
title = "Leetcode 658: Find K Closest Elements"
date = "2024-09-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 658: Find K Closest Elements in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Binary Search","Sliding Window","Sorting","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/658.webp"
youtube = "o-YDQzHoaKM"
youtube_upload_date="2022-01-31"
youtube_thumbnail="https://i.ytimg.com/vi_webp/o-YDQzHoaKM/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/658.webp" 
    alt="A set of elements with the k closest ones glowing softly as they are identified."
    caption="Solution to LeetCode 658: Find K Closest Elements Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given a sorted integer array and two integers k and x, return the k closest integers to x in the array, sorted in ascending order. If two integers are equally close to x, the smaller integer should be preferred.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a sorted array of integers arr, and two integers k and x.
- **Example:** `arr = [10, 20, 30, 40, 50], k = 3, x = 35`
- **Constraints:**
	- 1 <= k <= arr.length
	- 1 <= arr.length <= 10^4
	- arr is sorted in ascending order.
	- -10^4 <= arr[i], x <= 10^4

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is a sorted array of the k integers closest to x from the input array arr.
- **Example:** `[30, 40, 50]`
- **Constraints:**
	- The output array will contain exactly k integers.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the k closest integers to x by comparing the absolute differences of each integer in the array to x, and selecting the k smallest differences.

- 1. Use a binary search to efficiently locate the closest element to x.
- 2. Expand outward from the closest element to gather k elements (both left and right).
- 3. Sort the selected k elements and return them.
{{< dots >}}
### Problem Assumptions ✅
- The input array is always sorted in ascending order.
- The value of k will always be valid (1 <= k <= arr.length).
{{< dots >}}
## Examples 🧩
- **Input:** `arr = [5, 10, 15, 20, 25, 30], k = 2, x = 12`  \
  **Explanation:** The closest integers to 12 are 10 and 15. Sorted, the result is [10, 15].

{{< dots >}}
## Approach 🚀
This problem can be solved using binary search to quickly find the nearest element to x, followed by expanding to collect the k closest integers.

### Initial Thoughts 💭
- Binary search can help quickly locate the closest integer to x in the sorted array.
- Once the closest element is found, we can expand outward to select the k closest integers.
- Efficiently finding the closest element using binary search can save time in large arrays. Afterward, we just need to compare adjacent elements to gather the k closest integers.
{{< dots >}}
### Edge Cases 🌐
- The input array will never be empty as per the problem constraints.
- For large arrays (up to 10^4 elements), binary search ensures the solution remains efficient.
- The array can contain both negative and positive integers, and edge cases where all elements are either greater or less than x should be considered.
- Ensure that the selected k elements are always the closest ones to x, and handle edge cases where the array contains values that are equally close to x.
{{< dots >}}
## Code 💻
```cpp
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int l = 0, r = arr.size() -k;
    while(l < r) {
        int m = (l + r) / 2;
        if(x - arr[m] > arr[m + k] - x) {
            l = m + 1;
        } else r = m;
    }
    
    return vector<int>(arr.begin() + l, arr.begin() + l + k);
}
```

This function finds the 'k' closest elements to a given value 'x' in a sorted array 'arr' using a binary search approach.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<int> findClosestElements(vector<int>& arr, int k, int x) {
	```
	This is the function definition for `findClosestElements`, which takes an array `arr`, an integer `k`, and a target value `x`. It returns a vector containing the `k` closest elements to `x` from the sorted array.

2. **Variable Initialization**
	```cpp
	    int l = 0, r = arr.size() - k;
	```
	Initialize two pointers: `l` starts at 0 (left boundary), and `r` is set to the index of the last valid element that can form a window of size 'k'.

3. **Binary Search Loop**
	```cpp
	    while(l < r) {
	```
	A binary search loop is started to find the best position for the `k` closest elements. The loop continues until the left pointer is no longer less than the right pointer.

4. **Calculate Midpoint**
	```cpp
	        int m = (l + r) / 2;
	```
	Calculate the middle index `m` as the average of the left (`l`) and right (`r`) pointers.

5. **Compare Differences**
	```cpp
	        if(x - arr[m] > arr[m + k] - x) {
	```
	Compare the distance from `x` to the current element `arr[m]` with the distance from `x` to the element `arr[m + k]`. This is used to decide whether to move the left or right pointer.

6. **Update Left Pointer**
	```cpp
	            l = m + 1;
	```
	If the distance to `arr[m]` is greater, it means the closest `k` elements are to the right, so we move the left pointer `l` to `m + 1`.

7. **Update Right Pointer**
	```cpp
	        } else r = m;
	```
	Otherwise, the closest `k` elements are either at or before the midpoint, so we move the right pointer `r` to `m`.

8. **Return Result**
	```cpp
	    return vector<int>(arr.begin() + l, arr.begin() + l + k);
	```
	The function returns a vector containing the `k` closest elements, starting from index `l` to `l + k` in the original array.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(log(n) + k)
- **Average Case:** O(log(n) + k)
- **Worst Case:** O(log(n) + k)

The time complexity is O(log(n) + k) due to the binary search and the subsequent expansion to gather k elements.

### Space Complexity 💾
- **Best Case:** O(k)
- **Worst Case:** O(k)

The space complexity is O(k) due to the storage required for the k closest integers.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-k-closest-elements/description/)

---
{{< youtube o-YDQzHoaKM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

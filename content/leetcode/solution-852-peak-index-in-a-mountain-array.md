
+++
authors = ["grid47"]
title = "Leetcode 852: Peak Index in a Mountain Array"
date = "2024-08-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 852: Peak Index in a Mountain Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "yeYhFWpIus4"
youtube_upload_date="2022-06-29"
youtube_thumbnail="https://i.ytimg.com/vi/yeYhFWpIus4/maxresdefault.jpg"
comments = true
+++



---
You are given a mountain array `arr` of length `n`, where the values first strictly increase to a peak element and then strictly decrease. Your task is to find the index of the peak element in the array. The peak element is an element that is greater than both its neighbors.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array `arr` that represents the mountain array.
- **Example:** `Input: arr = [1, 3, 2]`
- **Constraints:**
	- 3 <= arr.length <= 10^5
	- 0 <= arr[i] <= 10^6
	- arr is guaranteed to be a mountain array.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the index of the peak element in the array.
- **Example:** `Output: 1`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the index of the peak element in O(log(n)) time complexity using binary search.

- Step 1: Initialize two pointers, `l` and `r`, to represent the left and right bounds of the search range.
- Step 2: Use binary search to find the peak element by comparing the middle element with its neighbors.
- Step 3: If the middle element is greater than both neighbors, return its index.
- Step 4: If the middle element is less than its right neighbor, move the left pointer to `mid + 1`. Otherwise, move the right pointer to `mid - 1`.
{{< dots >}}
### Problem Assumptions ✅
- The array is a valid mountain array, which means there is always exactly one peak.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: arr = [0, 2, 1, 0]`  \
  **Explanation:** In this example, the peak element is 2, which is located at index 1. The values increase from index 0 to 1, and then decrease from index 1 to 3, so the peak is at index 1.

- **Input:** `Input: arr = [0, 10, 5, 2]`  \
  **Explanation:** Here, the peak element is 10, located at index 1. The values increase from index 0 to 1, and then decrease from index 1 to 3, with 10 being the peak.

{{< dots >}}
## Approach 🚀
We can solve this problem efficiently using a binary search approach to find the peak element in O(log n) time.

### Initial Thoughts 💭
- The array is a mountain array, meaning the elements first increase to a peak and then decrease.
- We can take advantage of the binary search technique by checking the middle element and adjusting our search bounds based on whether we are on the increasing or decreasing slope.
{{< dots >}}
### Edge Cases 🌐
- N/A: The array always has at least 3 elements.
- The solution must efficiently handle cases where the array length is close to the upper limit (10^5).
- The array will always contain a valid peak, so there is no need for additional validity checks.
- The binary search approach ensures O(log n) time complexity.
{{< dots >}}
## Code 💻
```cpp
int peakIndexInMountainArray(vector<int>& arr) {
    
    int n = arr.size();

    int l = 1, r = n - 2;

    while(l <= r) {
        int mid = l + (r - l + 1) / 2;
        
        if(arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1]) {
            return mid;
        }
        
        if(arr[mid] > arr[mid + 1]) {
            r = mid - 1;
        } else if(arr[mid] > arr[mid - 1]) {
            l = mid + 1;
        }
        
    }
    return 0;
}
```

This is an implementation of finding the peak index in a mountain array using binary search.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int peakIndexInMountainArray(vector<int>& arr) {
	```
	Defines the function that will return the index of the peak element in the mountain array.

2. **Variable Initialization**
	```cpp
	    int n = arr.size();
	```
	Stores the size of the input array into variable 'n'.

3. **Variable Initialization**
	```cpp
	    int l = 1, r = n - 2;
	```
	Initializes left and right pointers (l and r) to search within the range of valid indices.

4. **Looping**
	```cpp
	    while(l <= r) {
	```
	Starts the binary search loop to find the peak.

5. **Mid Calculation**
	```cpp
	        int mid = l + (r - l + 1) / 2;
	```
	Calculates the middle index (mid) for the binary search range.

6. **Condition Check**
	```cpp
	        if(arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1]) {
	```
	Checks if the current element is greater than its neighbors, indicating it's the peak.

7. **Return**
	```cpp
	            return mid;
	```
	Returns the index of the peak element.

8. **Condition Check**
	```cpp
	        if(arr[mid] > arr[mid + 1]) {
	```
	If the current element is greater than the element on its right, move the right pointer.

9. **Pointer Update**
	```cpp
	            r = mid - 1;
	```
	Updates the right pointer to search the left half of the array.

10. **Condition Check**
	```cpp
	        } else if(arr[mid] > arr[mid - 1]) {
	```
	If the current element is greater than the element on its left, move the left pointer.

11. **Pointer Update**
	```cpp
	            l = mid + 1;
	```
	Updates the left pointer to search the right half of the array.

12. **Return**
	```cpp
	    return 0;
	```
	Returns 0 if no peak is found (default case).

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(log n)
- **Average Case:** O(log n)
- **Worst Case:** O(log n)

The time complexity is O(log n) due to the binary search process, which halves the search space at each step.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) as the solution uses only a constant amount of extra space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/peak-index-in-a-mountain-array/description/)

---
{{< youtube yeYhFWpIus4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

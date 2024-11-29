
+++
authors = ["grid47"]
title = "Leetcode 162: Find Peak Element"
date = "2024-10-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 162: Find Peak Element in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/162.webp"
youtube = "31foR5tJapQ"
youtube_upload_date="2021-02-22"
youtube_thumbnail="https://i.ytimg.com/vi/31foR5tJapQ/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/162.webp" 
    alt="A smooth curve of numbers with the highest point glowing brightly, symbolizing the peak."
    caption="Solution to LeetCode 162: Find Peak Element Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given a list of integers, nums. A peak element is an element that is strictly greater than its neighbors. You need to find and return the index of any peak element in the list. The algorithm should run in O(log n) time.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a list of integers, nums. The list has at least one element.
- **Example:** `[1, 3, 2, 1]`
- **Constraints:**
	- 1 <= nums.length <= 1000
	- -231 <= nums[i] <= 231 - 1
	- nums[i] != nums[i + 1] for all valid i.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be the index of any peak element in the list.
- **Example:** `1`
- **Constraints:**
	- There will always be at least one peak element in the array.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the peak element index in O(log n) time.

- Perform a binary search to find the peak element.
- Check if the middle element is greater than its neighbors.
- If the middle element is a peak, return its index.
- If the left neighbor is greater, search the left half of the array.
- If the right neighbor is greater, search the right half of the array.
{{< dots >}}
### Problem Assumptions ✅
- The array will always contain at least one peak element.
{{< dots >}}
## Examples 🧩
- **Input:** `[1, 3, 2, 1]`  \
  **Explanation:** In this example, the element 3 is the peak element as it is greater than its neighbors 1 and 2. Therefore, the function returns index 1.

{{< dots >}}
## Approach 🚀
We will use binary search to find a peak element in the array. Binary search will allow us to find the peak in O(log n) time.

### Initial Thoughts 💭
- A peak is an element greater than its neighbors.
- Binary search can help us efficiently narrow down the peak element.
- Since we are only asked to find any peak, binary search will efficiently locate one in O(log n) time.
{{< dots >}}
### Edge Cases 🌐
- The input will always have at least one element.
- The solution should work efficiently for arrays of up to 1000 elements.
- Handle arrays where elements are strictly increasing or strictly decreasing.
- Ensure the algorithm runs in O(log n) time.
{{< dots >}}
## Code 💻
```cpp
int findPeakElement(vector<int>& arr) {
    int n = arr.size();
    
    int l = 0, r = n - 1;
    
    while(l <= r) {
        int mid = l + (r - l) / 2;
        
        bool x = mid > 0? arr[mid - 1] < arr[mid] : true;
        bool y = mid < n -1 ? arr[mid + 1] < arr[mid] : true;
        
        if(x && y) return mid;
        if(!x && y) r = mid - 1;
        else if(x && !y) l = mid + 1;
        else r = mid - 1;            
    }
    return l;
}
```

This function finds the peak element in an array, where a peak element is defined as an element that is greater than or equal to its neighbors.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int findPeakElement(vector<int>& arr) {
	```
	Define the function 'findPeakElement' which takes a vector of integers as input and returns the index of a peak element.

2. **Variable Declaration**
	```cpp
	    int n = arr.size();
	```
	Declare and initialize 'n' to store the size of the input array 'arr'.

3. **Variable Initialization**
	```cpp
	    int l = 0, r = n - 1;
	```
	Initialize two variables 'l' and 'r' to represent the left and right boundaries of the search space.

4. **Loop**
	```cpp
	    while(l <= r) {
	```
	Start a while loop to perform binary search, continuing as long as the left boundary is less than or equal to the right boundary.

5. **Variable Calculation**
	```cpp
	        int mid = l + (r - l) / 2;
	```
	Calculate the middle index 'mid' using the formula to avoid overflow.

6. **Boolean Expression**
	```cpp
	        bool x = mid > 0? arr[mid - 1] < arr[mid] : true;
	```
	Check if the current element is greater than its left neighbor, or if it's the first element (in which case it is treated as a peak).

7. **Boolean Expression**
	```cpp
	        bool y = mid < n -1 ? arr[mid + 1] < arr[mid] : true;
	```
	Check if the current element is greater than its right neighbor, or if it's the last element (in which case it is treated as a peak).

8. **Conditional Check**
	```cpp
	        if(x && y) return mid;
	```
	If both 'x' and 'y' are true, the current element is a peak, so return the index 'mid'.

9. **Conditional Check**
	```cpp
	        if(!x && y) r = mid - 1;
	```
	If the current element is smaller than its left neighbor, move the right boundary 'r' to 'mid - 1' to search the left half.

10. **Conditional Check**
	```cpp
	        else if(x && !y) l = mid + 1;
	```
	If the current element is greater than its left neighbor but smaller than its right neighbor, move the left boundary 'l' to 'mid + 1' to search the right half.

11. **Conditional Check**
	```cpp
	        else r = mid - 1;            
	```
	If neither of the above conditions is met, adjust the right boundary 'r' to search the left half.

12. **Return Statement**
	```cpp
	    return l;
	```
	If no peak is found during the binary search, return the left boundary 'l', which will point to the index of the peak element.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(log n)
- **Average Case:** O(log n)
- **Worst Case:** O(log n)

Each binary search step reduces the search space by half, resulting in O(log n) time complexity.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) as we only use a few variables for indexing and comparisons.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-peak-element/description/)

---
{{< youtube 31foR5tJapQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

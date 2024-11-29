
+++
authors = ["grid47"]
title = "Leetcode 153: Find Minimum in Rotated Sorted Array"
date = "2024-10-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 153: Find Minimum in Rotated Sorted Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/153.webp"
youtube = "H2U24n4bcQQ"
youtube_upload_date="2024-03-04"
youtube_thumbnail="https://i.ytimg.com/vi_webp/H2U24n4bcQQ/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/153.webp" 
    alt="A rotating array with a glowing highlight marking the minimum element."
    caption="Solution to LeetCode 153: Find Minimum in Rotated Sorted Array Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given a sorted array of unique elements, rotated between 1 and n times, find the minimum element in this array.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a sorted array of unique integers which is rotated between 1 and n times.
- **Example:** `nums = [6,7,9,10,2,3,4]`
- **Constraints:**
	- 1 <= n <= 5000
	- -5000 <= nums[i] <= 5000
	- All elements in the array are unique.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be the minimum element in the rotated sorted array.
- **Example:** `2`
- **Constraints:**
	- The array will always be rotated between 1 and n times.

{{< dots >}}
### Core Logic 🔍
**Goal:** To find the minimum element, use a binary search approach that reduces the search space in each step.

- Initialize two pointers: start and end of the array.
- Find the middle element and compare it with the rightmost element.
- If the middle element is greater than the rightmost element, the minimum must be in the right half, so move the start pointer to mid + 1.
- Otherwise, move the end pointer to mid.
- Repeat this process until the start pointer equals the end pointer, which will be the minimum element.
{{< dots >}}
### Problem Assumptions ✅
- The array is sorted and rotated.
- The array has at least one element.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [6,7,9,10,2,3,4]`  \
  **Explanation:** The array was originally [2,3,4,6,7,9,10] and was rotated 4 times. The minimum element is 2.

- **Input:** `nums = [10,11,13,15,18,20,1]`  \
  **Explanation:** The array was originally [1,10,11,13,15,18,20] and was rotated 6 times. The minimum element is 1.

{{< dots >}}
## Approach 🚀
We can use binary search to find the minimum element efficiently in O(log n) time.

### Initial Thoughts 💭
- Since the array is sorted and rotated, the minimum element will always be the pivot point where the array shifts from higher to lower values.
- Binary search will be optimal to reduce the time complexity to O(log n).
{{< dots >}}
### Edge Cases 🌐
- The array will always have at least one element.
- The solution must efficiently handle arrays with up to 5000 elements.
- Negative values and large values within the constraints should be handled correctly.
- The array will always contain unique elements.
{{< dots >}}
## Code 💻
```cpp
int findMin(vector<int>& nums) {
    int n = nums.size();
    int s = 0, e = n - 1;
    int ans = -1;

    if(n == 1) return nums[0];

    while(s < e) {
        int mid = s + (e - s) / 2;

        // if(mid - 1 >= 0 && nums[mid] < nums[mid - 1]) return nums[mid];

        if(nums[e] < nums[mid]) {
            s = mid + 1;
        } else{
            e = mid;
        }
    }
    cout << "Hi" << e;
    return nums[e];
}
```

This code is used to find the minimum element in a rotated sorted array. The logic applies binary search, adjusting the search range based on the comparison of the current middle element with the rightmost element of the array.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int findMin(vector<int>& nums) {
	```
	Defines the function `findMin`, which takes a vector of integers and returns the minimum element in a rotated sorted array.

2. **Variable Initialization**
	```cpp
	    int n = nums.size();
	```
	Initializes `n` to the size of the `nums` vector to handle the array's length and ensure valid indexing.

3. **Variable Initialization**
	```cpp
	    int s = 0, e = n - 1;
	```
	Initializes `s` (start) and `e` (end) to the first and last indices of the array, respectively, setting the bounds for the binary search.

4. **Variable Initialization**
	```cpp
	    int ans = -1;
	```
	Initializes `ans` to store the result of the minimum element (though it isn't used in the final implementation here).

5. **Edge Case Handling**
	```cpp
	    if(n == 1) return nums[0];
	```
	Handles the edge case where the array has only one element. If true, returns that single element as the minimum.

6. **Loop Iteration**
	```cpp
	
	```
	This space is reserved for the beginning of the loop that will iterate until the search range is narrowed down to a single element.

7. **Binary Search**
	```cpp
	    while(s < e) {
	```
	Begins the while loop for binary search, which will continue until the search range (`s` to `e`) is reduced to a single element.

8. **Midpoint Calculation**
	```cpp
	        int mid = s + (e - s) / 2;
	```
	Calculates the midpoint `mid` between `s` and `e` to split the array into two halves during each iteration.

9. **Binary Search Logic**
	```cpp
	        if(nums[e] < nums[mid]) {
	```
	Compares the element at the rightmost index (`e`) with the middle element. If the element at `e` is smaller, the minimum must be in the right half of the array.

10. **Binary Search Update**
	```cpp
	            s = mid + 1;
	```
	Adjusts the start index `s` to `mid + 1` to narrow the search to the right half of the array.

11. **Binary Search Logic**
	```cpp
	        } else{
	```
	If the element at `e` is not smaller than the middle element, the minimum must lie in the left half or could be the middle itself.

12. **Binary Search Update**
	```cpp
	            e = mid;
	```
	Adjusts the end index `e` to `mid` to narrow the search to the left half of the array.

13. **Return Value**
	```cpp
	    return nums[e];
	```
	Returns the element at index `e`, which is the minimum element in the rotated sorted array.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(log n)
- **Average Case:** O(log n)
- **Worst Case:** O(log n)

Binary search will run in logarithmic time.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The solution only requires a constant amount of space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/)

---
{{< youtube H2U24n4bcQQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

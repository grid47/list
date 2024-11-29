
+++
authors = ["grid47"]
title = "Leetcode 75: Sort Colors"
date = "2024-10-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 75: Sort Colors in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/75.webp"
youtube = "4xbWSRZHqac"
youtube_upload_date="2021-06-24"
youtube_thumbnail="https://i.ytimg.com/vi/4xbWSRZHqac/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/75.webp" 
    alt="A radiant sequence of colors gently sorting themselves in a peaceful, fluid motion."
    caption="Solution to LeetCode 75: Sort Colors Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given an array of integers where each element represents a color: 0 for red, 1 for white, and 2 for blue. Your task is to sort the array such that all reds (0) appear first, followed by whites (1), and finally blues (2). Solve the problem in one pass with constant extra space, without using any built-in sort functions.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array of integers where each integer is either 0, 1, or 2.
- **Example:** `nums = [1, 0, 2, 1, 0, 2]`
- **Constraints:**
	- 1 <= n <= 300
	- nums[i] is either 0, 1, or 2.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the sorted array where all 0s (red) appear first, followed by 1s (white), and finally 2s (blue).
- **Example:** `[0, 0, 1, 1, 2, 2]`
- **Constraints:**
	- The output should be a single array with the elements sorted according to the color order.

{{< dots >}}
### Core Logic 🔍
**Goal:** Sort the array in-place using a one-pass algorithm with constant space.

- Use a three-pointer approach (Dutch National Flag algorithm):
- Set pointers i and j at the beginning and end of the array, respectively.
- Iterate through the array using a third pointer k to rearrange the elements by swapping them with the correct pointers.
{{< dots >}}
### Problem Assumptions ✅
- The array will only contain the integers 0, 1, and 2.
- The array has at least one element.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [1, 0, 2, 1, 0, 2]`  \
  **Explanation:** By sorting the array, we move the 0s to the front, followed by the 1s and 2s, resulting in [0, 0, 1, 1, 2, 2].

- **Input:** `nums = [2, 1, 0]`  \
  **Explanation:** The array is sorted to [0, 1, 2], with all the 0s first, followed by 1s and 2s.

{{< dots >}}
## Approach 🚀
The goal is to perform an in-place sort with a time complexity of O(n) and constant extra space. We can achieve this using the Dutch National Flag algorithm.

### Initial Thoughts 💭
- The array only contains three distinct values: 0, 1, and 2.
- We need to sort the array in a way that minimizes space and performs in linear time.
- By using three pointers, we can segregate the 0s, 1s, and 2s efficiently.
{{< dots >}}
### Edge Cases 🌐
- If the array is empty, there is nothing to sort.
- Ensure that the algorithm works efficiently with the maximum array size of 300.
- The input array may contain only one type of color (e.g., all 0s, all 1s, or all 2s).
- The function should perform the sorting in one pass with O(1) extra space.
{{< dots >}}
## Code 💻
```cpp
void sortColors(vector<int>& nums) {
    int n = nums.size();
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high) {
        if (nums[mid] == 0) {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        } else if (nums[mid] == 1) {
            mid++;
        } else {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}
```

This code sorts an array of 0s, 1s, and 2s in-place using a three-pointer approach.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	void sortColors(vector<int>& nums) {
	```
	Declares a function `sortColors` that takes a vector of integers `nums` as input and sorts it in-place.

2. **Variable Initialization**
	```cpp
	    int n = nums.size();
	```
	Initializes a variable `n` to store the size of the input array.

3. **Variable Initialization**
	```cpp
	    int low = 0, mid = 0, high = n - 1;
	```
	Initializes three pointers: `low`, `mid`, and `high`. `low` points to the next position for a 0, `mid` is the current element being considered, and `high` points to the next position for a 2.

4. **Loop Iteration**
	```cpp
	    while (mid <= high) {
	```
	Starts a `while` loop that continues as long as `mid` is less than or equal to `high`.

5. **Conditional**
	```cpp
	        if (nums[mid] == 0) {
	```
	Checks if the current element at `mid` is 0.

6. **Swap**
	```cpp
	            swap(nums[low], nums[mid]);
	```
	Swaps the element at `mid` with the element at `low`.

7. **Increment**
	```cpp
	            low++;
	            mid++;
	```
	Increments both `low` and `mid` pointers.

8. **Conditional**
	```cpp
	        } else if (nums[mid] == 1) {
	```
	Checks if the current element at `mid` is 1.

9. **Increment**
	```cpp
	            mid++;
	```
	Increments the `mid` pointer to the next element.

10. **Conditional**
	```cpp
	        } else {
	```
	If the current element at `mid` is 2.

11. **Swap**
	```cpp
	            swap(nums[mid], nums[high]);
	```
	Swaps the element at `mid` with the element at `high`.

12. **Decrement**
	```cpp
	            high--;
	```
	Decrements the `high` pointer.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The algorithm has a linear time complexity of O(n) because we traverse the array once using the three-pointer approach.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The algorithm uses only constant extra space, as the sorting is done in-place.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/sort-colors/description/)

---
{{< youtube 4xbWSRZHqac >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

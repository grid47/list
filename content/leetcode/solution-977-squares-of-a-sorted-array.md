
+++
authors = ["grid47"]
title = "Leetcode 977: Squares of a Sorted Array"
date = "2024-08-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 977: Squares of a Sorted Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Sorting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "z0InhrjK3es"
youtube_upload_date="2024-04-03"
youtube_thumbnail="https://i.ytimg.com/vi_webp/z0InhrjK3es/maxresdefault.webp"
comments = true
+++



---
Given an integer array nums sorted in non-decreasing order, return an array of the squares of each element, sorted in non-decreasing order.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** An integer array nums sorted in non-decreasing order.
- **Example:** `nums = [-6, -3, 0, 2, 8]`
- **Constraints:**
	- 1 <= nums.length <= 10^4
	- -10^4 <= nums[i] <= 10^4
	- nums is sorted in non-decreasing order.

{{< dots >}}
### Output Specifications 📤
- **Output:** An array containing the squares of each number from nums, sorted in non-decreasing order.
- **Example:** `[0, 9, 36, 64, 81]`
- **Constraints:**
	- The output should be sorted in non-decreasing order.

{{< dots >}}
### Core Logic 🔍
**Goal:** Square each element and sort the resulting array.

- Square each element of the array.
- Use a two-pointer approach to combine the negative and positive elements efficiently, leveraging their positions in the sorted array.
{{< dots >}}
### Problem Assumptions ✅
- The array nums is already sorted in non-decreasing order.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [-6, -3, 0, 2, 8]`  \
  **Explanation:** Squaring each element results in [36, 9, 0, 4, 64]. After sorting, we get [0, 9, 36, 64, 81].

- **Input:** `nums = [-10, -5, 1, 4, 7]`  \
  **Explanation:** Squaring each element results in [100, 25, 1, 16, 49]. After sorting, we get [1, 16, 25, 49, 100].

{{< dots >}}
## Approach 🚀
Use a two-pointer technique to process the squares of the sorted array efficiently in O(n) time.

### Initial Thoughts 💭
- The array is already sorted, so we can efficiently merge the positive and negative squares using a two-pointer approach.
- We can avoid sorting by directly placing the largest squares at the correct positions from the end of the result array.
{{< dots >}}
### Edge Cases 🌐
- An empty input array, which should return an empty result.
- A large input array, ensuring that the solution handles up to the maximum input size efficiently.
- All elements being zero.
- The array must be sorted in non-decreasing order.
{{< dots >}}
## Code 💻
```cpp
vector<int> sortedSquares(vector<int>& nums) {
    vector<int> ans(nums.size());
    int l = 0, r = nums.size() - 1;
    int ll, rr;
    for(int i = nums.size() - 1; i >= 0; i--) {
        ll = nums[l] * nums[l];
        rr = nums[r] * nums[r];
        if(ll < rr) ans[i] = rr, r--;
        else ans[i] = ll, l++;
    }
    return ans;
}
```

This function takes a sorted array of integers, squares each element, and returns a new array sorted in non-decreasing order. It uses a two-pointer approach, comparing squares of the largest and smallest elements from both ends.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<int> sortedSquares(vector<int>& nums) {
	```
	Defines the function `sortedSquares`, which takes a reference to a vector of integers `nums` and returns a vector of integers containing the squares of each element in sorted order.

2. **Initialize Answer Vector**
	```cpp
	    vector<int> ans(nums.size());
	```
	Initializes a vector `ans` with the same size as `nums` to store the squared values of the elements in sorted order.

3. **Initialize Pointers**
	```cpp
	    int l = 0, r = nums.size() - 1;
	```
	Initializes two pointers `l` and `r` to point to the beginning and end of the `nums` array, respectively.

4. **Variable Declarations**
	```cpp
	    int ll, rr;
	```
	Declares two integer variables `ll` and `rr` to store the squared values of the elements at the `l` and `r` pointers.

5. **Loop Over Array**
	```cpp
	    for(int i = nums.size() - 1; i >= 0; i--) {
	```
	Starts a loop to iterate from the end of the `ans` array towards the beginning. The loop continues as long as there are elements left to process.

6. **Calculate Square of Left Element**
	```cpp
	        ll = nums[l] * nums[l];
	```
	Calculates the square of the element at the `l` pointer and stores it in `ll`.

7. **Calculate Square of Right Element**
	```cpp
	        rr = nums[r] * nums[r];
	```
	Calculates the square of the element at the `r` pointer and stores it in `rr`.

8. **Choose Larger Square**
	```cpp
	        if(ll < rr) ans[i] = rr, r--;
	```
	Compares the squares `ll` and `rr`. If `ll` is smaller, assigns `rr` to `ans[i]` and moves the `r` pointer one step left.

9. **Choose Smaller Square**
	```cpp
	        else ans[i] = ll, l++;
	```
	If `ll` is greater than or equal to `rr`, assigns `ll` to `ans[i]` and moves the `l` pointer one step right.

10. **Return Statement**
	```cpp
	    return ans;
	```
	Returns the sorted `ans` array, which contains the squares of the elements in `nums` sorted in non-decreasing order.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The two-pointer approach processes each element once, leading to a time complexity of O(n).

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the result array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/squares-of-a-sorted-array/description/)

---
{{< youtube z0InhrjK3es >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

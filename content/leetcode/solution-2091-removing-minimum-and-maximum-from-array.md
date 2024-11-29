
+++
authors = ["grid47"]
title = "Leetcode 2091: Removing Minimum and Maximum From Array"
date = "2024-04-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2091: Removing Minimum and Maximum From Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "OsaRrf_jDn4"
youtube_upload_date="2021-11-28"
youtube_thumbnail="https://i.ytimg.com/vi_webp/OsaRrf_jDn4/maxresdefault.webp"
comments = true
+++



---
You are given an array of distinct integers. Your task is to remove the elements that hold the minimum and maximum values in the array. A deletion can either be from the front or the back of the array. Your objective is to find the minimum number of deletions required to remove both of these elements.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a single list of integers, nums, where each integer is distinct. You are also given the size of the list.
- **Example:** `nums = [3, 7, 8, 5, 2, 10, 1]`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- -10^5 <= nums[i] <= 10^5
	- All integers in nums are distinct.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is a single integer: the minimum number of deletions required to remove both the minimum and maximum elements from the array.
- **Example:** `Output: 4`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to calculate the minimum number of deletions required to remove both the minimum and maximum values from the array.

- Find the indices of the minimum and maximum elements in the array.
- Check three possible ways to remove both elements: delete from the front, delete from the back, or a combination of both.
- Choose the minimum number of deletions from the three options.
{{< dots >}}
### Problem Assumptions ✅
- The array is non-empty.
- The integers in the array are distinct.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: nums = [3, 7, 8, 5, 2, 10, 1]`  \
  **Explanation:** The minimum element is 1, and the maximum element is 10. We can remove both elements by deleting 2 elements from the front and 2 elements from the back. Therefore, the minimum number of deletions is 4.

- **Input:** `Example 2: nums = [10, 15, 12, 9]`  \
  **Explanation:** The minimum element is 9, and the maximum element is 15. We can remove both elements by deleting 1 element from the front and 2 elements from the back. The minimum deletions required is 3.

{{< dots >}}
## Approach 🚀
We need to calculate the minimum deletions needed to remove both the minimum and maximum values from the array by considering three strategies: removing elements from the front, from the back, or both.

### Initial Thoughts 💭
- We can delete from both ends of the array.
- Finding the indices of the minimum and maximum elements in the array is crucial. Once we have those, we can evaluate different deletion strategies.
{{< dots >}}
### Edge Cases 🌐
- If the array is empty, the solution should return 0 deletions.
- Ensure that the solution handles large arrays efficiently.
- If the array has only one element, the deletion count will be 1.
- Arrays with up to 10^5 elements must be processed efficiently.
{{< dots >}}
## Code 💻
```cpp
int minimumDeletions(vector<int>& nums) {
    int xi = 0, ni = 0;
    int n = nums.size();
    for(int i = 0; i < n; i++) {
        if(nums[xi] < nums[i])
            xi = i;
        if(nums[ni] > nums[i])
            ni = i;
    }
    if(xi == ni) return 1;
    int mx = (xi < ni)? ni: xi;
    int mn = (xi < ni)? xi: ni;

    int ans = (mx - 0 + 1);
    
    ans = min(ans, (n - mn));
    
    ans = min(ans, (n - mx) + (mn - 0 + 1));
            
    return ans;
}
```

This is the function `minimumDeletions` which calculates the minimum deletions needed to make a given array `nums` strictly increasing.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	int minimumDeletions(vector<int>& nums) {
	```
	Defines the function `minimumDeletions`, which takes a reference to a vector `nums` as input.

2. **Variable Initialization**
	```cpp
	    int xi = 0, ni = 0;
	```
	Initializes two integer variables `xi` and `ni` to track the indices of the largest and smallest elements encountered so far.

3. **Size Calculation**
	```cpp
	    int n = nums.size();
	```
	Calculates the size of the `nums` array and stores it in variable `n`.

4. **Looping**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Iterates over each element in the array `nums` using the index `i`.

5. **Condition Checking**
	```cpp
	        if(nums[xi] < nums[i])
	```
	Checks if the current element `nums[i]` is greater than the element at index `xi`.

6. **Update Indices**
	```cpp
	            xi = i;
	```
	Updates `xi` to the current index `i` if `nums[i]` is greater than `nums[xi]`.

7. **Condition Checking**
	```cpp
	        if(nums[ni] > nums[i])
	```
	Checks if the current element `nums[i]` is smaller than the element at index `ni`.

8. **Update Indices**
	```cpp
	            ni = i;
	```
	Updates `ni` to the current index `i` if `nums[i]` is smaller than `nums[ni]`.

9. **Condition Checking**
	```cpp
	    if(xi == ni) return 1;
	```
	If `xi` and `ni` are equal, return 1 because the array is already in the desired state.

10. **Max/Min Calculation**
	```cpp
	    int mx = (xi < ni)? ni: xi;
	```
	Calculates the larger of `xi` and `ni` and stores it in `mx`.

11. **Max/Min Calculation**
	```cpp
	    int mn = (xi < ni)? xi: ni;
	```
	Calculates the smaller of `xi` and `ni` and stores it in `mn`.

12. **Return Statement**
	```cpp
	    int ans = (mx - 0 + 1);
	```
	Initializes the variable `ans` to track the minimum deletions required, starting with the largest index calculation.

13. **Calculations**
	```cpp
	    ans = min(ans, (n - mn));
	```
	Compares the current value of `ans` with the number of elements after `mn`, and updates `ans` to the smaller value.

14. **Final Calculation**
	```cpp
	    ans = min(ans, (n - mx) + (mn - 0 + 1));
	```
	Calculates the total deletions required based on `mx` and `mn`, and updates `ans` with the minimum value.

15. **Return Statement**
	```cpp
	    return ans;
	```
	Returns the final result, which is the minimum number of deletions required.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because we need to find the minimum and maximum elements and calculate the deletions for each possible strategy, which all require a single pass through the array.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) because we only use a constant amount of extra space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/removing-minimum-and-maximum-from-array/description/)

---
{{< youtube OsaRrf_jDn4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

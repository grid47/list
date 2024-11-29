
+++
authors = ["grid47"]
title = "Leetcode 1389: Create Target Array in the Given Order"
date = "2024-06-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1389: Create Target Array in the Given Order in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Simulation"]
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
Given two arrays of integers nums and index, the task is to create a target array by inserting elements of nums at the positions specified by index. After processing all elements, return the target array.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given two arrays: nums and index. The length of both arrays is the same, and nums[i] represents the element to be inserted at index[i] position in the target array.
- **Example:** `For nums = [5, 10, 20, 30, 40], index = [0, 1, 2, 2, 1], the target array will be [5, 40, 10, 30, 20].`
- **Constraints:**
	- 1 <= nums.length, index.length <= 100
	- nums.length == index.length
	- 0 <= nums[i] <= 100
	- 0 <= index[i] <= i

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the target array after inserting all elements from nums at the corresponding indices from index.
- **Example:** `For nums = [5, 10, 20, 30, 40] and index = [0, 1, 2, 2, 1], the output will be [5, 40, 10, 30, 20].`
- **Constraints:**
	- The output will always be a valid array.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to insert elements from nums at positions specified by index, maintaining the order of elements in nums.

- 1. Initialize an empty target array.
- 2. Iterate over the nums and index arrays.
- 3. Insert nums[i] at the position index[i] in the target array.
- 4. Return the target array after all insertions.
{{< dots >}}
### Problem Assumptions ✅
- The insertion operations will always be valid.
{{< dots >}}
## Examples 🧩
- **Input:** `For nums = [5, 10, 20, 30, 40] and index = [0, 1, 2, 2, 1], the target array becomes [5, 40, 10, 30, 20].`  \
  **Explanation:** The algorithm inserts elements at positions defined by index, and we keep track of the current state of the target array.

{{< dots >}}
## Approach 🚀
To solve this problem, iterate through the nums and index arrays, inserting each element of nums at the specified position in the target array.

### Initial Thoughts 💭
- The insertion operation involves shifting elements of the target array to make room for the new element.
- We will insert elements in the order specified, which means we need to shift the current elements of the target array each time.
{{< dots >}}
### Edge Cases 🌐
- The input arrays nums and index will never be empty.
- Ensure the solution handles cases with the maximum input size of 100 elements.
- The input values will always be valid and within the specified range.
- The algorithm must handle the maximum constraints efficiently.
{{< dots >}}
## Code 💻
```cpp
static bool cmp(vector<int> &a, vector<int> &b) {
    return a[0] < b[0];
    // return b[2] < a[2];
}

vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
    int n = nums.size();
    vector<int> ans(n, 0);
    for(int i = 0; i < n; i++) {
        int j = index[i];
        for(int k = n - 1; k > j; k--)
            ans[k] = ans[k - 1];
        ans[j] = nums[i];
    }
    return ans;
}
```

This code solves the problem of creating a target array based on given index positions. It uses a helper function `cmp` for sorting (although it's commented out), and the main function `createTargetArray` inserts elements from the `nums` array into a new array at the specified positions in the `index` array.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Helper Function**
	```cpp
	static bool cmp(vector<int> &a, vector<int> &b) {
	```
	Define a helper function `cmp` which compares two vectors based on the first element (used for sorting). The function can be customized to compare other elements.

2. **Comparison**
	```cpp
	    return a[0] < b[0];
	```
	Compare the first element of the two vectors. This is used for sorting purposes (ascending order based on the first element).

3. **Function Definition**
	```cpp
	vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
	```
	Define the function `createTargetArray`, which takes two arrays: `nums` (values to insert) and `index` (positions to insert the corresponding values).

4. **Variable Declaration**
	```cpp
	    int n = nums.size();
	```
	Store the size of the `nums` array in the variable `n` to use as the loop limit.

5. **Data Structures**
	```cpp
	    vector<int> ans(n, 0);
	```
	Initialize a vector `ans` of size `n` with all elements set to 0. This will hold the final target array.

6. **Loop**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Iterate over each element in the `nums` array using a loop.

7. **Index Assignment**
	```cpp
	        int j = index[i];
	```
	Get the index `j` from the `index` array, where the `i`-th number of `nums` should be inserted.

8. **Nested Loop**
	```cpp
	        for(int k = n - 1; k > j; k--)
	```
	Loop backwards from `n-1` to `j+1`, shifting the elements in the target array to the right to make space for the new element.

9. **Array Manipulation**
	```cpp
	            ans[k] = ans[k - 1];
	```
	Shift the element at index `k-1` to index `k`, moving all elements to the right starting from the end of the array.

10. **Array Insertion**
	```cpp
	        ans[j] = nums[i];
	```
	Insert the `i`-th element of `nums` at the position `j` in the target array `ans`.

11. **Return Statement**
	```cpp
	    return ans;
	```
	Return the final target array `ans` after all elements from `nums` have been inserted at the specified positions.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2), where n is the length of nums.
- **Average Case:** O(n^2), due to shifting elements for each insertion.
- **Worst Case:** O(n^2), where n is the length of nums.

The time complexity is dominated by the shifting operations during each insertion.

### Space Complexity 💾
- **Best Case:** O(n), since we store the target array.
- **Worst Case:** O(n), where n is the length of nums, for storing the target array.

The space complexity is O(n) due to the storage of the target array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/create-target-array-in-the-given-order/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

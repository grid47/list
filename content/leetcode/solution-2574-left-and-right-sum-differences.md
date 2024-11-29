
+++
authors = ["grid47"]
title = "Leetcode 2574: Left and Right Sum Differences"
date = "2024-02-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2574: Left and Right Sum Differences in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Prefix Sum"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "O3pCkMbVsFQ"
youtube_upload_date="2023-02-26"
youtube_thumbnail="https://i.ytimg.com/vi_webp/O3pCkMbVsFQ/maxresdefault.webp"
comments = true
+++



---
You are given a 0-indexed integer array nums. Find a 0-indexed integer array answer where: answer[i] = |leftSum[i] - rightSum[i]|, where leftSum[i] is the sum of elements to the left of the index i, and rightSum[i] is the sum of elements to the right of the index i.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a single integer array nums.
- **Example:** `For example, nums = [5, 3, 7, 2].`
- **Constraints:**
	- 1 <= nums.length <= 1000
	- 1 <= nums[i] <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an array answer where answer[i] = |leftSum[i] - rightSum[i]|, with leftSum[i] being the sum of elements to the left of index i and rightSum[i] being the sum of elements to the right of index i.
- **Example:** `For nums = [5, 3, 7, 2], the output is [12, 2, 4, 12].`
- **Constraints:**
	- The output array must have the same length as the input array.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to compute the leftSum and rightSum arrays and use them to calculate the absolute difference at each index.

- 1. Calculate the leftSum array where leftSum[i] is the sum of all elements before index i.
- 2. Calculate the rightSum array where rightSum[i] is the sum of all elements after index i.
- 3. For each index i, compute answer[i] = |leftSum[i] - rightSum[i]|.
{{< dots >}}
### Problem Assumptions ✅
- The input will always have at least one element.
{{< dots >}}
## Examples 🧩
- **Input:** `For nums = [5, 3, 7, 2], the output is [12, 2, 4, 12].`  \
  **Explanation:** We calculate the leftSum and rightSum for each index, and then take the absolute difference of the sums.

{{< dots >}}
## Approach 🚀
The approach involves calculating the cumulative sum to the left and right for each index, and then taking their absolute difference.

### Initial Thoughts 💭
- We need to calculate the sum of the elements on the left and right of each index efficiently.
- By using cumulative sums, we can compute both leftSum and rightSum in linear time.
{{< dots >}}
### Edge Cases 🌐
- nums will always have at least one element.
- Ensure the solution handles large arrays efficiently.
- Handle cases where all elements are the same.
- The output should handle large integers resulting from the sums of large elements.
{{< dots >}}
## Code 💻
```cpp
vector<int> leftRightDifference(vector<int>& nums) {
    int n = nums.size();
    vector<int> sum(n + 1, 0), ans(n, 0);
    for(int i = 0; i < n; i++)
        sum[i + 1] = nums[i] + sum[i];
    
    int net = sum[n];
    for(int i = 0; i < n; i++) {
        ans[i] = abs(net - sum[i + 1] - sum[i]);
    }
    return ans;
}
```

This is the complete code for solving the problem of calculating the left-right difference for each element in the array. The code computes the difference using prefix sums and stores the results in a new array.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<int> leftRightDifference(vector<int>& nums) {
	```
	Define the function 'leftRightDifference' which takes a vector of integers as input and returns a vector of integers containing the left-right differences.

2. **Variable Initialization**
	```cpp
	    int n = nums.size();
	```
	Declare an integer 'n' to store the size of the input vector 'nums'.

3. **Variable Initialization**
	```cpp
	    vector<int> sum(n + 1, 0), ans(n, 0);
	```
	Declare two vectors: 'sum' to store the prefix sums of the input array, and 'ans' to store the resulting differences. Initialize both vectors with zeros.

4. **Loop**
	```cpp
	    for(int i = 0; i < n; i++)
	```
	Start a loop to iterate through the input array and compute the prefix sums.

5. **Prefix Sum Calculation**
	```cpp
	        sum[i + 1] = nums[i] + sum[i];
	```
	Compute the prefix sum for each element by adding the current element of 'nums' to the previous value in the 'sum' array.

6. **Blank Line**
	```cpp
	    
	```
	An empty line used for readability and to separate sections of code.

7. **Variable Initialization**
	```cpp
	    int net = sum[n];
	```
	Store the total sum of the input array in the variable 'net', which is the last element of the 'sum' array.

8. **Loop**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Start a loop to calculate the left-right differences for each element.

9. **Difference Calculation**
	```cpp
	        ans[i] = abs(net - sum[i + 1] - sum[i]);
	```
	For each element, compute the absolute difference between the total sum 'net' and the sum of the elements to the left and right of the current element.

10. **Return Statement**
	```cpp
	    return ans;
	```
	Return the result vector 'ans', which contains the left-right differences for each element in the input array.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear in the size of the input array, as we iterate over the array a few times.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

We use extra space to store the leftSum and rightSum arrays, which are both of size n.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/left-and-right-sum-differences/description/)

---
{{< youtube O3pCkMbVsFQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

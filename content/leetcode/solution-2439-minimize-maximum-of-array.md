
+++
authors = ["grid47"]
title = "Leetcode 2439: Minimize Maximum of Array"
date = "2024-03-08"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2439: Minimize Maximum of Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Dynamic Programming","Greedy","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "AeHMvcKuR0Y"
youtube_upload_date="2023-04-05"
youtube_thumbnail="https://i.ytimg.com/vi/AeHMvcKuR0Y/maxresdefault.jpg"
comments = true
+++



---
You are given a 0-indexed array `nums` of length `n`, where each element represents the number of items in a container. In one operation, you can pick an index `i` such that 1 <= i < n and `nums[i] > 0`, and move one item from `nums[i]` to `nums[i-1]`. Your goal is to minimize the maximum value in the array `nums` after performing any number of operations.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array `nums` where `n` is the length of the array and `nums[i]` is the value at index `i`.
- **Example:** `nums = [5, 10, 3, 8]`
- **Constraints:**
	- 2 <= n <= 10^5
	- 0 <= nums[i] <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum possible value of the maximum integer in `nums` after performing any number of operations.
- **Example:** `Output: 6`
- **Constraints:**
	- The final result must be an integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to minimize the maximum value in the `nums` array after redistributing the elements. This can be done by calculating the sum of the array and spreading the items evenly.

- 1. Calculate the sum of the entire array `nums`.
- 2. For each index `i`, calculate the maximum possible value that can be achieved in the array after redistributing the items.
- 3. Return the minimized maximum value.
{{< dots >}}
### Problem Assumptions ✅
- The input array will always contain at least two elements.
- You are allowed to perform any number of operations to achieve the optimal result.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [3, 7, 1, 6]`  \
  **Explanation:** In this example, we can perform operations to redistribute the values in `nums`. Here’s one set of operations: 1. Move one item from `nums[1]` to `nums[0]`, resulting in [4, 6, 1, 6]; 2. Move one item from `nums[3]` to `nums[2]`, resulting in [4, 6, 2, 5]; 3. Move one item from `nums[1]` to `nums[0]`, resulting in [5, 5, 2, 5]; The maximum value in the array is now 5, and this is the minimal possible maximum value.

- **Input:** `nums = [10, 1]`  \
  **Explanation:** Here, the array is already optimal since 10 is the maximum value, and no operations are needed. The result is 10.

{{< dots >}}
## Approach 🚀
The key idea is to minimize the maximum value by redistributing items from higher-valued elements to lower-valued ones. This can be done by calculating the cumulative sum and determining the point at which the values start to stabilize.

### Initial Thoughts 💭
- To minimize the maximum value, it's helpful to consider redistributing the values across the array rather than focusing on individual operations.
- One approach is to calculate the cumulative sum while iterating through the array, and at each step, track the maximum value that could result from the redistribution of items.
{{< dots >}}
### Edge Cases 🌐
- There will always be at least two elements in `nums`, so empty input is not a concern.
- The solution must be able to handle up to 100,000 elements in the array, so time efficiency is important.
- If the array is already sorted with all values equal, no operations are needed.
- The array can have very large numbers, up to 10^9, so avoid overflow and ensure the solution handles such cases efficiently.
{{< dots >}}
## Code 💻
```cpp
int minimizeArrayValue(vector<int>& nums) {
    long sum = 0, res = 0;
    for(int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        res = max(res, (sum + i) / (i + 1));
    }
    return res;
}
```

This code defines a function `minimizeArrayValue` that minimizes the maximum value of the array after making adjustments to the values. It does so by iterating through the array, maintaining a cumulative sum, and calculating the maximum average for each index.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int minimizeArrayValue(vector<int>& nums) {
	```
	Defining the function `minimizeArrayValue`, which takes a vector `nums` and returns an integer. The function aims to minimize the maximum value in the array after adjusting the values.

2. **Variable Initialization**
	```cpp
	    long sum = 0, res = 0;
	```
	Initializing two variables: `sum`, which stores the cumulative sum of the array, and `res`, which tracks the result—the minimum maximum value of the array.

3. **Loop**
	```cpp
	    for(int i = 0; i < nums.size(); i++) {
	```
	A for loop that iterates over each element in the `nums` array. It updates the sum and checks for the maximum value after adjusting the array.

4. **Mathematical Operation**
	```cpp
	        sum += nums[i];
	```
	Adding the current element of the array `nums[i]` to the `sum` variable.

5. **Mathematical Operation**
	```cpp
	        res = max(res, (sum + i) / (i + 1));
	```
	Calculating the average of the first `i+1` elements (considering the sum up to index `i`) and updating `res` to store the maximum average encountered so far.

6. **Return Statement**
	```cpp
	    return res;
	```
	Returning the result stored in `res`, which is the minimized maximum value of the array after adjustments.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because we only need to iterate over the array once to calculate the sum and the optimal maximum value.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) because we are only using a constant amount of extra space, aside from the input array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimize-maximum-of-array/description/)

---
{{< youtube AeHMvcKuR0Y >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

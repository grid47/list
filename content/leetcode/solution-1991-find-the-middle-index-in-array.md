
+++
authors = ["grid47"]
title = "Leetcode 1991: Find the Middle Index in Array"
date = "2024-04-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1991: Find the Middle Index in Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Prefix Sum"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "C9PhqirC9vs"
youtube_upload_date="2021-09-04"
youtube_thumbnail="https://i.ytimg.com/vi/C9PhqirC9vs/maxresdefault.jpg"
comments = true
+++



---
Given a 0-indexed integer array 'nums', find the leftmost index where the sum of elements to the left of that index is equal to the sum of elements to the right of that index. If such an index exists, return the smallest such index, otherwise return -1. The sum of the elements before the first index is considered 0, and similarly, the sum of elements after the last index is also 0.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array 'nums' where each element represents an integer.
- **Example:** `nums = [1, 2, 3, -1, 2]`
- **Constraints:**
	- 1 <= nums.length <= 100
	- -1000 <= nums[i] <= 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the leftmost index where the sum of elements to the left equals the sum of elements to the right. If no such index exists, return -1.
- **Example:** `Output: 3`
- **Constraints:**
	- The output should be an integer representing the leftmost index or -1 if no such index exists.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the leftmost index where the sum of elements to the left is equal to the sum of elements to the right.

- Calculate the prefix sum for the input array, which is the cumulative sum of elements from the start up to each index.
- Compare the prefix sum at each index with the total sum to find the middle index where the two sides are balanced.
{{< dots >}}
### Problem Assumptions ✅
- The input array is non-empty, and its length will be between 1 and 100.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [1, 2, 3, -1, 2]`  \
  **Explanation:** The sum of elements to the left of index 3 is 1 + 2 + 3 = 6, and the sum of elements to the right is -1 + 2 = 6. Hence, index 3 is the middle index.

- **Input:** `Input: nums = [1, 2, 3]`  \
  **Explanation:** There is no index where the sum of elements to the left equals the sum of elements to the right, so the result is -1.

{{< dots >}}
## Approach 🚀
The approach involves calculating the prefix sums of the array, and then checking if there exists an index where the sum of elements to the left equals the sum to the right. This can be achieved in linear time.

### Initial Thoughts 💭
- The problem requires comparing the sum of elements on both sides of each index in the array.
- A prefix sum approach is optimal for this problem since it allows us to efficiently check each index with a running sum calculation.
{{< dots >}}
### Edge Cases 🌐
- The input will always contain at least one element, so no need to handle an empty array.
- The algorithm is efficient enough for arrays of length up to 100.
- The solution should handle arrays with negative numbers and arrays where all elements are the same.
- Ensure the solution runs efficiently for the maximum input size.
{{< dots >}}
## Code 💻
```cpp
int findMiddleIndex(vector<int>& nums) {
    int n = nums.size();
    vector<int> sum(n + 1, 0);
    for(int i = 0; i < n; i++)
        sum[i + 1] = nums[i] + sum[i];
    
    int net = sum[n];
    
    for(int i = 0; i < n; i++) {
        if(net - sum[i + 1] == sum[i]) return i;
    }
    return -1;
}
```

This solution calculates the middle index in a list of numbers where the sum of elements to the left is equal to the sum of elements to the right. The function uses a cumulative sum array to track the sums efficiently.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int findMiddleIndex(vector<int>& nums) {
	```
	Defines the function `findMiddleIndex`, which calculates the index where the sum of elements to the left equals the sum of elements to the right.

2. **Variable Initialization**
	```cpp
	    int n = nums.size();
	```
	Initializes the variable `n` to store the size of the input vector `nums`.

3. **Array Initialization**
	```cpp
	    vector<int> sum(n + 1, 0);
	```
	Creates a cumulative sum array `sum` initialized to zeros, where `sum[i]` will store the sum of the first `i` elements of `nums`.

4. **Loop Initialization**
	```cpp
	    for(int i = 0; i < n; i++)
	```
	Starts a loop to iterate through the input vector `nums`.

5. **Cumulative Sum Calculation**
	```cpp
	        sum[i + 1] = nums[i] + sum[i];
	```
	Calculates the cumulative sum by adding the current element `nums[i]` to the sum of all previous elements stored in `sum[i]`.

6. **Net Sum Calculation**
	```cpp
	    int net = sum[n];
	```
	Calculates the total sum of all elements in the array `nums` by using `sum[n]`, where `n` is the size of the array.

7. **Loop Through Elements**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Starts a loop to iterate through each index `i` of the input vector `nums`.

8. **Condition Check**
	```cpp
	        if(net - sum[i + 1] == sum[i]) return i;
	```
	Checks if the sum of elements to the left of index `i` equals the sum of elements to the right. If so, returns the index `i`.

9. **Return Statement**
	```cpp
	    return -1;
	```
	If no middle index is found, returns `-1` to indicate that no such index exists.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

We only need to make a single pass through the array to compute the sums and compare each index.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is constant if we calculate the sum in place and only store the running sum.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-the-middle-index-in-array/description/)

---
{{< youtube C9PhqirC9vs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

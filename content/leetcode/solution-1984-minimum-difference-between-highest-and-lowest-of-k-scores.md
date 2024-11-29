
+++
authors = ["grid47"]
title = "Leetcode 1984: Minimum Difference Between Highest and Lowest of K Scores"
date = "2024-04-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1984: Minimum Difference Between Highest and Lowest of K Scores in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sliding Window","Sorting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "JU5XdBZZtlk"
youtube_upload_date="2021-08-29"
youtube_thumbnail="https://i.ytimg.com/vi/JU5XdBZZtlk/maxresdefault.jpg"
comments = true
+++



---
You are given a 0-indexed array nums where each element represents the score of a student. You need to select the scores of exactly k students such that the difference between the highest and the lowest score of the selected students is minimized. Your task is to return the minimum possible difference.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are provided with an integer array nums and an integer k.
- **Example:** `nums = [1, 3, 8, 7, 9], k = 3`
- **Constraints:**
	- 1 <= k <= nums.length <= 1000
	- 0 <= nums[i] <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum possible difference between the highest and the lowest score of the selected k students.
- **Example:** `Output: 2`
- **Constraints:**
	- The returned value must be the smallest possible difference.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to select a subset of k students from the array such that the difference between the highest and the lowest score in that subset is minimized.

- Sort the array to make the differences easier to calculate.
- Iterate through the sorted array and consider every contiguous subsequence of length k.
- For each subsequence, calculate the difference between the first and the last element, then track the minimum difference.
{{< dots >}}
### Problem Assumptions ✅
- The array is not empty, and k is at least 1.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [1, 3, 8, 7, 9], k = 3`  \
  **Explanation:** After sorting the array, we get [1, 3, 7, 8, 9]. Selecting the students with scores 3, 7, and 8 gives a difference of 8 - 3 = 5. The minimum possible difference is 2.

- **Input:** `Input: nums = [5, 2, 9, 4], k = 2`  \
  **Explanation:** The sorted array is [2, 4, 5, 9]. Choosing the students with scores 4 and 5 results in a difference of 5 - 4 = 1. This is the minimum possible difference.

{{< dots >}}
## Approach 🚀
We will sort the array of student scores, and then use a sliding window technique to find the smallest possible difference between the highest and lowest scores in any subsequence of length k.

### Initial Thoughts 💭
- Sorting the array helps because it allows us to consider only consecutive elements for a valid subsequence.
- By sliding a window of size k over the sorted array, we can easily compute the difference between the largest and smallest elements in each subsequence.
{{< dots >}}
### Edge Cases 🌐
- If the array is empty, return 0 since there are no students to choose.
- For large arrays, ensure the algorithm runs in O(n log n) time due to sorting.
- If k equals the length of the array, the only valid choice is the entire array.
- The solution must handle large arrays and ensure that the minimum difference is computed efficiently.
{{< dots >}}
## Code 💻
```cpp
int minimumDifference(vector<int>& nums, int k) {
int res = INT_MAX;
sort(begin(nums), end(nums));
for (int i = k - 1; i < nums.size(); ++i)
    res = min(res, nums[i] - nums[i - k + 1]);
return res;
}
```

This function finds the minimum difference between any two elements in a subarray of size k from the sorted array.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	int minimumDifference(vector<int>& nums, int k) {
	```
	Defines the function `minimumDifference` that takes a vector `nums` and an integer `k`, representing the array and the size of the subarray, respectively.

2. **Variable Initialization**
	```cpp
	int res = INT_MAX;
	```
	Initializes a variable `res` with the maximum possible integer value to keep track of the minimum difference.

3. **Sorting**
	```cpp
	sort(begin(nums), end(nums));
	```
	Sorts the array `nums` in non-decreasing order, which is necessary for efficiently finding the minimum difference in subsequent steps.

4. **Looping**
	```cpp
	for (int i = k - 1; i < nums.size(); ++i)
	```
	Starts a loop from the index `k-1` to iterate through the sorted array `nums` and compare elements that are part of a subarray of size `k`.

5. **Mathematical Operations**
	```cpp
	    res = min(res, nums[i] - nums[i - k + 1]);
	```
	Updates the `res` variable by calculating the minimum difference between the current element `nums[i]` and the element `k` positions before it.

6. **Return Statement**
	```cpp
	return res;
	```
	Returns the minimum difference found between the elements in any subarray of size `k`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

Sorting the array takes O(n log n) time, and iterating through it takes O(n) time.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n) for the sorted array, and O(1) if we are sorting in place.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/description/)

---
{{< youtube JU5XdBZZtlk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

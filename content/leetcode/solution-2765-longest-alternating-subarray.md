
+++
authors = ["grid47"]
title = "Leetcode 2765: Longest Alternating Subarray"
date = "2024-02-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2765: Longest Alternating Subarray in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Enumeration"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "Yg_VhAOIIuk"
youtube_upload_date="2023-07-08"
youtube_thumbnail="https://i.ytimg.com/vi/Yg_VhAOIIuk/maxresdefault.jpg"
comments = true
+++



---
You are given a 0-indexed integer array 'nums'. A subarray 's' is called alternating if it follows a specific pattern of alternating differences between consecutive elements: +1, -1, +1, -1, and so on. Return the maximum length of all alternating subarrays, or -1 if no such subarray exists.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a single integer array 'nums'.
- **Example:** `nums = [1, 2, 3, 2, 3]`
- **Constraints:**
	- 2 <= nums.length <= 100
	- 1 <= nums[i] <= 10^4

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum length of all alternating subarrays, or -1 if no alternating subarray exists.
- **Example:** `For nums = [1, 2, 3, 2, 3], the output is 4.`
- **Constraints:**
	- The output should be a single integer representing the maximum length of alternating subarrays.

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the longest alternating subarray by iterating over the array and checking the alternating pattern condition.

- Initialize variables to store the maximum length and the current subarray's length.
- Iterate through the array to find subarrays that follow the alternating pattern.
- If an alternating subarray is found, update the maximum length.
{{< dots >}}
### Problem Assumptions ✅
- The input array contains at least two elements.
{{< dots >}}
## Examples 🧩
- **Input:** `For nums = [1, 2, 3, 2, 3]`  \
  **Explanation:** The alternating subarrays are [1, 2], [2, 3], [3, 2, 3], and [2, 3, 2, 3]. The longest one is [2, 3, 2, 3], with length 4.

- **Input:** `For nums = [5, 6, 7]`  \
  **Explanation:** The alternating subarrays are [5, 6] and [6, 7], both of length 2.

{{< dots >}}
## Approach 🚀
We use a two-pointer technique to check for alternating subarrays and track the longest one.

### Initial Thoughts 💭
- The array length is relatively small (<= 100), so a brute force approach is feasible.
- By iterating through the array and checking the alternating pattern, we can efficiently find the longest alternating subarray.
{{< dots >}}
### Edge Cases 🌐
- The input will always have at least two elements, so no need to handle empty arrays.
- Handle arrays with 100 elements, ensuring the solution runs efficiently within the time limit.
- If no alternating subarray is found, return -1.
- Ensure that the solution works within the time constraints for arrays of size up to 100.
{{< dots >}}
## Code 💻
```cpp
int alternatingSubarray(vector<int>& A) {
    int n = A.size(), res = 0, j = 0;
    for (int i = 0; i < n; ++i)
        for (j = i + 1; j < n && A[j] == A[i] + (j - i) % 2; ++j)
            res = max(res, j - i + 1);
    return res > 1 ? res : -1;
}
```

This function calculates the length of the longest alternating subarray in a given array `A` where the difference between adjacent elements alternates between increasing and decreasing by 1.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int alternatingSubarray(vector<int>& A) {
	```
	Defines the function `alternatingSubarray`, which takes a vector `A` and returns the length of the longest alternating subarray.

2. **Variable Initialization**
	```cpp
	    int n = A.size(), res = 0, j = 0;
	```
	Initializes variables: `n` as the size of the vector `A`, `res` to store the result (longest alternating subarray length), and `j` as a helper index.

3. **Outer Loop**
	```cpp
	    for (int i = 0; i < n; ++i)
	```
	Starts an outer loop with `i` to iterate through each possible starting index of the subarray.

4. **Inner Loop (Check Alternating Pattern)**
	```cpp
	        for (j = i + 1; j < n && A[j] == A[i] + (j - i) % 2; ++j)
	```
	Starts an inner loop with `j`, checking if the current element alternates with the previous one (difference between elements alternates between 1 and -1).

5. **Update Result**
	```cpp
	            res = max(res, j - i + 1);
	```
	Updates `res` to store the maximum length of the alternating subarray found so far.

6. **Return Result**
	```cpp
	    return res > 1 ? res : -1;
	```
	Returns the length of the longest alternating subarray, or -1 if no such subarray with length greater than 1 exists.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the length of the array. We loop through the array once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) as we use only a few variables to track the lengths.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/longest-alternating-subarray/description/)

---
{{< youtube Yg_VhAOIIuk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

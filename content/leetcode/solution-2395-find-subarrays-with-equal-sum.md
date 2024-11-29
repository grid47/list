
+++
authors = ["grid47"]
title = "Leetcode 2395: Find Subarrays With Equal Sum"
date = "2024-03-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2395: Find Subarrays With Equal Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "1v-XTlRvUvU"
youtube_upload_date="2022-09-03"
youtube_thumbnail="https://i.ytimg.com/vi_webp/1v-XTlRvUvU/maxresdefault.webp"
comments = true
+++



---
You are given a 0-indexed integer array `nums`. Your task is to determine if there are two subarrays of length 2 that have the same sum, but these subarrays must begin at different indices in the array. A subarray is defined as a contiguous sequence of elements within the array.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array `nums` of length n, where 2 <= n <= 1000 and -10^9 <= nums[i] <= 10^9.
- **Example:** `nums = [3,1,2,3,5]`
- **Constraints:**
	- 2 <= nums.length <= 1000
	- -10^9 <= nums[i] <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return `true` if there are two distinct subarrays of length 2 with the same sum, and `false` otherwise.
- **Example:** `Output: true`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find if there are two distinct subarrays of length 2 with the same sum by checking each pair of consecutive elements in the array.

- 1. Traverse the array and for each pair of consecutive elements, calculate their sum.
- 2. Store the sum of each subarray of length 2 in a set.
- 3. If any sum is encountered more than once, return true.
- 4. If no sums are repeated, return false.
{{< dots >}}
### Problem Assumptions ✅
- There will always be at least one pair of subarrays to check.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [4,2,4]`  \
  **Explanation:** The subarrays [4,2] and [2,4] have the same sum of 6. Since they are at different indices, the answer is true.

- **Input:** `nums = [1,2,3,4,5]`  \
  **Explanation:** No two subarrays of length 2 have the same sum. Hence, the answer is false.

{{< dots >}}
## Approach 🚀
The approach involves calculating the sum of all possible subarrays of length 2 and checking for duplicates using a set.

### Initial Thoughts 💭
- The problem requires checking pairs of elements for matching sums.
- We can use a set to track sums and easily check for duplicates.
{{< dots >}}
### Edge Cases 🌐
- If the array contains less than 2 elements, no subarray of length 2 can exist.
- Handle cases where the array contains the maximum allowed number of elements (1000).
- Consider cases where all elements are the same.
- Ensure the solution works within time limits for large inputs and handles extreme values of array elements.
{{< dots >}}
## Code 💻
```cpp
bool findSubarrays(vector<int>& nums) {
unordered_set<int> s;
for (int i = 1; i < nums.size(); ++i)
    if(!s.insert(nums[i - 1] + nums[i]).second)
        return true;
return false;
  }
```

The function `findSubarrays` checks if there are any subarrays of size 2 in the input vector `nums` that have the same sum. It returns `true` if such subarrays exist, and `false` otherwise.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	bool findSubarrays(vector<int>& nums) {
	```
	The function `findSubarrays` is declared, which takes a reference to a vector of integers `nums` as input and returns a boolean value.

2. **Set Initialization**
	```cpp
	unordered_set<int> s;
	```
	An unordered set `s` is initialized to store the sums of consecutive pairs of elements in the `nums` array. This ensures that only unique sums are stored.

3. **Loop Initialization**
	```cpp
	for (int i = 1; i < nums.size(); ++i)
	```
	A loop starts from the second element of the `nums` vector (index 1) and iterates through the rest of the vector.

4. **Checking for Duplicates**
	```cpp
	    if(!s.insert(nums[i - 1] + nums[i]).second)
	```
	For each consecutive pair of elements, their sum is calculated and inserted into the set `s`. If the insertion is unsuccessful (i.e., the sum is already in the set), it indicates that a duplicate sum exists.

5. **Return True**
	```cpp
	        return true;
	```
	If a duplicate sum is found, the function immediately returns `true`, indicating that there are two consecutive subarrays with the same sum.

6. **Return False**
	```cpp
	return false;
	```
	If the loop completes without finding a duplicate sum, the function returns `false`, indicating no such subarrays exist.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the length of the input array.
- **Average Case:** O(n), where n is the length of the input array.
- **Worst Case:** O(n), where n is the length of the input array.

The algorithm processes each pair of consecutive elements once, making the time complexity O(n).

### Space Complexity 💾
- **Best Case:** O(n), where n is the length of the input array.
- **Worst Case:** O(n), where n is the length of the input array, due to the space used by the set to store sums.

The space complexity is O(n) as we need a set to store the subarray sums.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-subarrays-with-equal-sum/description/)

---
{{< youtube 1v-XTlRvUvU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

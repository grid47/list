
+++
authors = ["grid47"]
title = "Leetcode 2824: Count Pairs Whose Sum is Less than Target"
date = "2024-01-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2824: Count Pairs Whose Sum is Less than Target in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Binary Search","Sorting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "Xe1teNERwSY"
youtube_upload_date="2023-08-19"
youtube_thumbnail="https://i.ytimg.com/vi_webp/Xe1teNERwSY/maxresdefault.webp"
comments = true
+++



---
You are given a 0-indexed integer array nums and an integer target. Return the number of distinct pairs (i, j) such that 0 <= i < j < n and nums[i] + nums[j] < target.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array nums and an integer target. The array nums has length n, and the integer target is a threshold value.
- **Example:** `nums = [2, -1, 3, 5, -2], target = 4`
- **Constraints:**
	- 1 <= nums.length == n <= 50
	- -50 <= nums[i], target <= 50

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of distinct pairs (i, j) where 0 <= i < j < n such that nums[i] + nums[j] < target.
- **Example:** `Output: 4`
- **Constraints:**
	- The output should be a single integer representing the number of valid pairs.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to count the number of pairs of indices (i, j) that satisfy the condition nums[i] + nums[j] < target.

- 1. Iterate over all pairs of indices (i, j) where i < j.
- 2. For each pair, check if nums[i] + nums[j] is less than the target.
- 3. Keep a count of the valid pairs.
{{< dots >}}
### Problem Assumptions ✅
- The input array nums is not empty, and there is always at least one valid pair when the input is valid.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [2, -1, 3, 5, -2], target = 4`  \
  **Explanation:** The valid pairs are (0, 1), (0, 2), (0, 4), and (1, 4), all of which have a sum less than the target.

{{< dots >}}
## Approach 🚀
To solve the problem, we can use a brute-force approach by checking all pairs of indices.

### Initial Thoughts 💭
- We are required to check all pairs of indices (i, j) where i < j.
- A brute-force solution works well for the constraints, as n is small (<= 50).
{{< dots >}}
### Edge Cases 🌐
- The input array will never be empty as per the constraints.
- The solution should efficiently handle the maximum array size of 50.
- When all elements in the array are the same, the number of valid pairs depends on the target.
- Since n is small (<= 50), a brute-force solution is acceptable.
{{< dots >}}
## Code 💻
```cpp
  int countPairs(vector<int>& nums, int target) {
  int ans = 0;
  for(int i = 0; i < nums.size(); ++i){
      for(int j = i + 1; j < nums.size(); ++j){
          if(nums[i] + nums[j] < target) ans++;
      }
  }
  return ans;
  }
```

This function counts the number of pairs in the array 'nums' whose sum is less than a given 'target'. It uses two nested loops to check every pair.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	  int countPairs(vector<int>& nums, int target) {
	```
	The function 'countPairs' is defined, accepting a vector of integers 'nums' and an integer 'target' as parameters.

2. **Variable Initialization**
	```cpp
	  int ans = 0;
	```
	A variable 'ans' is initialized to 0, which will be used to keep track of the number of pairs whose sum is less than 'target'.

3. **Outer Loop**
	```cpp
	  for(int i = 0; i < nums.size(); ++i){
	```
	The outer loop begins, iterating over each element of the vector 'nums' from index 0 to the last element.

4. **Inner Loop**
	```cpp
	      for(int j = i + 1; j < nums.size(); ++j){
	```
	The inner loop starts from index 'i + 1' and iterates through the elements after the current element of the outer loop, ensuring all pairs are checked.

5. **Condition Check**
	```cpp
	          if(nums[i] + nums[j] < target) ans++;
	```
	Check if the sum of the pair 'nums[i]' and 'nums[j]' is less than the 'target'. If true, increment the 'ans' counter.

6. **Return Statement**
	```cpp
	  return ans;
	```
	Return the final count of pairs that satisfy the condition.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2)

Since we need to check all pairs of indices (i, j), the time complexity is O(n^2).

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1), as we only need a few variables to track the count.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/count-pairs-whose-sum-is-less-than-target/description/)

---
{{< youtube Xe1teNERwSY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

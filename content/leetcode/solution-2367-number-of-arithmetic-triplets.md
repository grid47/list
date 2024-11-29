
+++
authors = ["grid47"]
title = "Leetcode 2367: Number of Arithmetic Triplets"
date = "2024-03-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2367: Number of Arithmetic Triplets in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Two Pointers","Enumeration"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "WEyiBgwO4ZA"
youtube_upload_date="2022-08-07"
youtube_thumbnail="https://i.ytimg.com/vi/WEyiBgwO4ZA/maxresdefault.jpg"
comments = true
+++



---
You are given a strictly increasing array of integers, nums, and a positive integer diff. A triplet (i, j, k) is an arithmetic triplet if the following conditions hold: i < j < k, nums[j] - nums[i] == diff, and nums[k] - nums[j] == diff. Your task is to return the number of unique arithmetic triplets that can be formed from the given array.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a strictly increasing array nums, and an integer diff which specifies the common difference in the arithmetic triplet.
- **Example:** `nums = [1, 3, 4, 6, 8, 9], diff = 2`
- **Constraints:**
	- 3 <= nums.length <= 200
	- 0 <= nums[i] <= 200
	- 1 <= diff <= 50
	- nums is strictly increasing

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a single integer, representing the number of unique arithmetic triplets that satisfy the conditions described.
- **Example:** `Output: 3`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** We need to count the number of valid triplets where the difference between consecutive numbers is exactly the given diff.

- Initialize an array to keep track of the occurrences of potential triplet values.
- For each number in the input array, check if the previous two numbers that form a valid triplet (with the given diff) have appeared before.
- Accumulate the count of valid triplets and return the final result.
{{< dots >}}
### Problem Assumptions ✅
- The input array is guaranteed to be strictly increasing.
- The number of triplets should be counted based on the difference condition, not the exact indices.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [1, 3, 4, 6, 8, 9], diff = 2`  \
  **Explanation:** In this example, the valid arithmetic triplets are (1, 3, 5), (3, 5, 7), and (4, 6, 8). These triplets are formed by choosing values where the difference between consecutive numbers is exactly 2.

{{< dots >}}
## Approach 🚀
We need to efficiently count the number of valid arithmetic triplets by checking if the conditions for triplet formation are met for each number in the array.

### Initial Thoughts 💭
- We need to check if each number in the array can form an arithmetic triplet with the previous numbers.
- We can use a frequency count to store potential triplet values.
- By iterating over the array, we can efficiently check for the existence of valid pairs and count the triplets.
{{< dots >}}
### Edge Cases 🌐
- The problem guarantees that the input will always contain at least three elements, so empty arrays are not possible.
- The solution should efficiently handle arrays with up to 200 elements.
- If diff is large (close to 50) and nums values are also close to 200, the number of valid triplets might be small.
- Ensure that you handle cases where no valid triplets are found.
{{< dots >}}
## Code 💻
```cpp
int arithmeticTriplets(vector<int>& nums, int diff) {
int cnt[201] = {}, res = 0;
for (auto n : nums) {
    if (n >= 2 * diff)
        res += cnt[n - diff] && cnt[n - 2 * diff];
    cnt[n] = true;
}
return res;
  }
```

This function counts the number of arithmetic triplets in a sequence where the difference between each element is 'diff'. The approach uses an auxiliary array to track previously seen numbers.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int arithmeticTriplets(vector<int>& nums, int diff) {
	```
	The function starts by defining the input parameters, which are a vector of integers 'nums' and an integer 'diff' representing the difference between triplet elements.

2. **Array Initialization**
	```cpp
	int cnt[201] = {}, res = 0;
	```
	An array 'cnt' is initialized to track the presence of numbers in the sequence, with a size of 201, as the problem restricts the numbers to a known range. 'res' is initialized to store the final count of valid triplets.

3. **For Loop**
	```cpp
	for (auto n : nums) {
	```
	A for loop iterates over each element 'n' in the input array 'nums'.

4. **Condition Check**
	```cpp
	    if (n >= 2 * diff)
	```
	Checks if the current number 'n' is large enough to form a triplet. Specifically, it ensures that there is a possibility of forming a triplet with the required difference.

5. **Counting Triplets**
	```cpp
	        res += cnt[n - diff] && cnt[n - 2 * diff];
	```
	If the condition is met, the result counter 'res' is incremented by 1, indicating a valid triplet. This is determined by checking if two previous numbers, 'n - diff' and 'n - 2 * diff', have been seen before.

6. **Marking Presence**
	```cpp
	    cnt[n] = true;
	```
	Marks the current number 'n' as present by setting 'cnt[n]' to true. This helps track which numbers have been seen in the array.

7. **Return Statement**
	```cpp
	return res;
	```
	The function returns the total count of valid arithmetic triplets found.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the length of the array, since we iterate over the array once.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) as we need extra space to store the occurrence count for each number in the array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-arithmetic-triplets/description/)

---
{{< youtube WEyiBgwO4ZA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

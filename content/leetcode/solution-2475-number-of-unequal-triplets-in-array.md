
+++
authors = ["grid47"]
title = "Leetcode 2475: Number of Unequal Triplets in Array"
date = "2024-03-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2475: Number of Unequal Triplets in Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sorting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "AbSMJxiiJpk"
youtube_upload_date="2022-11-20"
youtube_thumbnail="https://i.ytimg.com/vi_webp/AbSMJxiiJpk/maxresdefault.webp"
comments = true
+++



---
You are given a 0-indexed array of positive integers, nums. Find the number of triplets (i, j, k) such that 0 <= i < j < k < nums.length and nums[i], nums[j], nums[k] are distinct.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a 0-indexed array of integers, nums, containing positive integers.
- **Example:** `nums = [5, 5, 3, 5, 2]`
- **Constraints:**
	- 3 <= nums.length <= 100
	- 1 <= nums[i] <= 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of triplets (i, j, k) where nums[i], nums[j], nums[k] are distinct.
- **Example:** `Output: 3`
- **Constraints:**
	- The output should be an integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the number of distinct triplets in nums that satisfy the condition i < j < k and nums[i], nums[j], nums[k] are distinct.

- Count the occurrences of each number in nums.
- Iterate through the array to find the number of valid triplets that meet the conditions.
{{< dots >}}
### Problem Assumptions ✅
- The input array will always contain at least three elements.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [5,5,3,5,2]`  \
  **Explanation:** The valid triplets are (0, 2, 4), (1, 2, 4), and (2, 3, 4), all of which contain distinct values. Therefore, the output is 3.

{{< dots >}}
## Approach 🚀
We need to count how many valid triplets can be formed from the array nums such that they are distinct and the indices satisfy i < j < k.

### Initial Thoughts 💭
- We can efficiently count the number of triplets by utilizing the counts of distinct elements in the array.
- We need to count the frequency of each number in the array, then calculate how many distinct combinations can be made from these frequencies.
{{< dots >}}
### Edge Cases 🌐
- The input will always have at least 3 elements, so there are no empty input cases.
- Ensure the solution handles cases where the array has the maximum size (100 elements).
- When all elements in the array are the same, there will be no valid triplets.
- The solution should run efficiently for arrays up to size 100.
{{< dots >}}
## Code 💻
```cpp
int unequalTriplets(vector<int>& nums) {
unordered_map<int, int> m;
for (int n : nums)
    ++m[n];
int res = 0, left = 0, right = nums.size();
for (auto [n, cnt] : m) {
    right -= cnt;
    res += left * cnt * right;
    left += cnt;
}
return res;
}
```

This function calculates the number of unequal triplets in an array, where a triplet consists of three elements from the array that are not equal to each other. The algorithm uses a frequency count and performs efficient calculations based on the left and right partitions of the array.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int unequalTriplets(vector<int>& nums) {
	```
	This is the function declaration of `unequalTriplets`, which takes a reference to a vector of integers `nums` and returns an integer representing the number of unequal triplets.

2. **Map Initialization**
	```cpp
	unordered_map<int, int> m;
	```
	An unordered map `m` is initialized to store the frequency of each element in the `nums` array.

3. **Frequency Count**
	```cpp
	for (int n : nums)
	```
	This loop iterates through each element `n` in the `nums` array.

4. **Map Update**
	```cpp
	    ++m[n];
	```
	The frequency count of each element `n` is incremented in the map `m`.

5. **Variable Initialization**
	```cpp
	int res = 0, left = 0, right = nums.size();
	```
	Three variables are initialized: `res` to store the result, `left` to track the number of elements before the current element, and `right` to track the number of elements after the current element in the array.

6. **Loop Over Map**
	```cpp
	for (auto [n, cnt] : m) {
	```
	A loop that iterates through each element `n` and its frequency count `cnt` in the map `m`.

7. **Right Partition Update**
	```cpp
	    right -= cnt;
	```
	The `right` variable is decremented by `cnt` (the frequency of the current element `n`), as we are considering this element in the left partition.

8. **Result Calculation**
	```cpp
	    res += left * cnt * right;
	```
	The result `res` is updated by adding the number of triplets formed by the current element `n`, considering its frequency in the left and right partitions.

9. **Left Partition Update**
	```cpp
	    left += cnt;
	```
	The `left` partition is updated by adding the current frequency `cnt`, as the current element `n` moves to the left partition.

10. **Return Statement**
	```cpp
	return res;
	```
	The function returns the final result `res`, which is the total number of unequal triplets.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The worst case involves sorting or counting distinct values, leading to a time complexity of O(n log n).

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the need for a hash map to count element frequencies.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-unequal-triplets-in-array/description/)

---
{{< youtube AbSMJxiiJpk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

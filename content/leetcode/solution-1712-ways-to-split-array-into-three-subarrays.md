
+++
authors = ["grid47"]
title = "Leetcode 1712: Ways to Split Array Into Three Subarrays"
date = "2024-05-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1712: Ways to Split Array Into Three Subarrays in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Binary Search","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "u5GIK6GaNWk"
youtube_upload_date="2021-01-03"
youtube_thumbnail="https://i.ytimg.com/vi/u5GIK6GaNWk/maxresdefault.jpg"
comments = true
+++



---
You are given an array of non-negative integers. Your task is to count the number of ways the array can be split into three contiguous non-empty subarrays: left, mid, and right. The sum of the elements in the left subarray should be less than or equal to the sum in the mid subarray, and the sum of the mid subarray should be less than or equal to the sum of the right subarray. Return the number of such good splits modulo 10^9 + 7.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an integer array 'nums' where each element is a non-negative integer.
- **Example:** `[3, 5, 1, 6, 2]`
- **Constraints:**
	- 3 <= nums.length <= 10^5
	- 0 <= nums[i] <= 10^4

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of valid ways to split the array into three subarrays that satisfy the sum conditions, modulo 10^9 + 7.
- **Example:** `2`
- **Constraints:**
	- The output should be a non-negative integer less than 10^9 + 7.

{{< dots >}}
### Core Logic 🔍
**Goal:** Determine the number of valid splits of the array based on the sum conditions.

- 1. Calculate the cumulative sums of the elements in the array.
- 2. Use two pointers to explore valid subarray splits that satisfy the condition: left_sum <= mid_sum <= right_sum.
- 3. For each potential left and mid subarray split, calculate how many valid right subarrays exist, and count them.
{{< dots >}}
### Problem Assumptions ✅
- The input array is non-empty and has at least 3 elements.
{{< dots >}}
## Examples 🧩
- **Input:** `[1,2,2,2,5,0]`  \
  **Explanation:** There are three good ways to split the array into three subarrays: [1] [2] [2,2,5,0], [1] [2,2] [2,5,0], and [1,2] [2,2] [5,0]. Each split satisfies the condition left_sum <= mid_sum <= right_sum.

- **Input:** `[3,2,1]`  \
  **Explanation:** There is no valid way to split the array because no subarray splits satisfy the condition left_sum <= mid_sum <= right_sum.

{{< dots >}}
## Approach 🚀
To solve this problem efficiently, we need to calculate the number of valid subarray splits that satisfy the sum conditions using two pointers and cumulative sums.

### Initial Thoughts 💭
- We need to track the sums of potential subarrays efficiently.
- Using a cumulative sum array will allow us to calculate the sum of any subarray in constant time.
{{< dots >}}
### Edge Cases 🌐
- The array will always have at least three elements based on the constraints.
- Make sure the algorithm can handle the largest input sizes (up to 10^5 elements).
- Handle cases where all elements are the same value or where some elements are zero.
- The solution must be efficient and handle the upper constraint limits within time limits.
{{< dots >}}
## Code 💻
```cpp
class Solution {
int mod = 1000000007;
public:
int waysToSplit(vector<int>& nums) {
    
    int n = nums.size(), res=0;

    partial_sum(nums.begin(), nums.end(), nums.begin());
    
    for(int i = 0, j = 0, k = 0; i < n - 2; i++) {

        j = max(i + 1, j);
        while(j < n - 1 && 2 * nums[i] > nums[j]) j++;

        k = max(j, k);
        while(k < n - 1 && nums[k] - nums[i] <= nums[n - 1] - nums[k]) k++;

        res = (res + (k - j)) % mod;
    }
    return res;            
}
```

This function calculates the number of ways to split the given array `nums` into three non-empty contiguous subarrays, such that the sum of the first subarray is less than or equal to the sum of the second subarray, and the sum of the second subarray is less than or equal to the sum of the third subarray. The result is computed modulo 1,000,000,007.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Class Definition**
	```cpp
	class Solution {
	```
	Defines the `Solution` class that contains the method to solve the problem.

2. **Variable Initialization**
	```cpp
	int mod = 1000000007;
	```
	Initializes a constant `mod` with a large prime number to compute the result modulo this value.

3. **Access Specifier**
	```cpp
	public:
	```
	Marks the following methods as public, allowing them to be accessed outside of the class.

4. **Function Definition**
	```cpp
	int waysToSplit(vector<int>& nums) {
	```
	Defines the function `waysToSplit` that takes a vector `nums` and returns the number of valid ways to split the array into three subarrays.

5. **Variable Initialization**
	```cpp
	int n = nums.size(), res=0;
	```
	Initializes `n` with the size of the input array `nums` and `res` to store the result of the computation.

6. **Prefix Sum Calculation**
	```cpp
	partial_sum(nums.begin(), nums.end(), nums.begin());
	```
	Calculates the prefix sum of the array `nums` and stores the cumulative sum in the same vector, which allows for efficient range sum calculations.

7. **Outer Loop**
	```cpp
	for(int i = 0, j = 0, k = 0; i < n - 2; i++) {
	```
	Begins a loop through the array to consider each possible starting index for the first subarray.

8. **Update j**
	```cpp
	j = max(i + 1, j);
	```
	Updates the index `j` to ensure it is at least one position ahead of `i`.

9. **Inner Loop**
	```cpp
	while(j < n - 1 && 2 * nums[i] > nums[j]) j++;
	```
	Advances the index `j` while the sum of the first subarray (`nums[i]`) is greater than the sum of the second subarray (`nums[j]`).

10. **Update k**
	```cpp
	k = max(j, k);
	```
	Ensures that `k` is at least as large as `j`, maintaining the correct relationship between the indices.

11. **Second Inner Loop**
	```cpp
	while(k < n - 1 && nums[k] - nums[i] <= nums[n - 1] - nums[k]) k++;
	```
	Advances the index `k` to maintain the condition that the difference between the second and third subarray sums is non-negative.

12. **Result Update**
	```cpp
	res = (res + (k - j)) % mod;
	```
	Updates the result `res` by adding the number of valid splits found in the current iteration, taking the modulo `mod` to prevent overflow.

13. **Return Result**
	```cpp
	return res;
	```
	Returns the final result, which is the total number of valid ways to split the array into three subarrays.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the length of the input array.
- **Average Case:** O(n), as we iterate through the array and calculate valid splits in a linear pass.
- **Worst Case:** O(n), as we perform a linear scan with two pointers over the array.

The solution uses a linear scan to find all valid splits, making the time complexity O(n).

### Space Complexity 💾
- **Best Case:** O(n), if the input array is large.
- **Worst Case:** O(n), due to the space needed for the cumulative sum array.

The space complexity is O(n) because we store the cumulative sums of the array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/ways-to-split-array-into-three-subarrays/description/)

---
{{< youtube u5GIK6GaNWk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

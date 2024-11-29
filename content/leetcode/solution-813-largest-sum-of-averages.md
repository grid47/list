
+++
authors = ["grid47"]
title = "Leetcode 813: Largest Sum of Averages"
date = "2024-08-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 813: Largest Sum of Averages in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/813.webp"
youtube = "3eqwUW6_cx4"
youtube_upload_date="2023-02-01"
youtube_thumbnail="https://i.ytimg.com/vi_webp/3eqwUW6_cx4/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/813.webp" 
    alt="A set of averages where the largest sum is calculated, glowing softly as the sum is found."
    caption="Solution to LeetCode 813: Largest Sum of Averages Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given an integer array 'nums' and an integer 'k'. You can partition the array into at most 'k' non-empty adjacent subarrays. The score of a partition is defined as the sum of the averages of each subarray. Your goal is to return the maximum score that can be achieved by partitioning the array in any possible way, with each partition's score calculated as the sum of averages of its subarrays.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are provided with an array 'nums' of integers and an integer 'k', where 'nums' represents the array to be partitioned and 'k' is the maximum number of partitions allowed.
- **Example:** `Input: nums = [4, 6, 2, 8, 3], k = 2`
- **Constraints:**
	- 1 <= nums.length <= 100
	- 1 <= nums[i] <= 10^4
	- 1 <= k <= nums.length

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a floating-point number representing the maximum score that can be achieved by partitioning the array into at most 'k' subarrays.
- **Example:** `Output: 16.5`
- **Constraints:**
	- The answer should be accurate within a relative or absolute error of 10^-6.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to maximize the sum of averages of all subarrays created by partitioning the given array.

- Precompute the prefix sums of the array to allow quick calculations of subarray sums.
- Use dynamic programming to find the maximum score, where the score is the sum of averages for each subarray formed.
- Implement a memoization technique to avoid redundant calculations of overlapping subproblems.
{{< dots >}}
### Problem Assumptions ✅
- The input array 'nums' and the integer 'k' are valid as per the constraints.
- Each partition must use all elements of the array without any element being left out.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [4, 6, 2, 8, 3], k = 2`  \
  **Explanation:** The best partition for this example is [4, 6], [2, 8, 3]. The average of [4, 6] is (4 + 6)/2 = 5, and the average of [2, 8, 3] is (2 + 8 + 3)/3 = 4.33. The total score is 5 + 4.33 = 9.33.

{{< dots >}}
## Approach 🚀
The approach involves using dynamic programming to solve the problem optimally. We will memoize the results of subproblems to avoid redundant calculations and maximize the partition score.

### Initial Thoughts 💭
- Each partition can be represented by a subarray, and we need to compute the sum of averages for each partition.
- We need to maximize the sum of averages, which means distributing the array elements across subarrays efficiently.
{{< dots >}}
### Edge Cases 🌐
- An empty input array should not be a valid test case based on the problem's constraints.
- The solution should handle the largest inputs efficiently, where the array length is at its maximum and k is large.
- Consider cases where k equals the array length, meaning each element will be its own subarray.
- Ensure the algorithm handles arrays of different sizes and large values of k within the given time limits.
{{< dots >}}
## Code 💻
```cpp
double memo[200][200];
double largestSumOfAverages(vector<int>& nums, int k) {
    memset(memo, 0, sizeof(memo));
    int n = nums.size();
    double cur = 0;
    for(int i = 0; i < n; i++) {
        cur += nums[i];
        memo[i + 1][1] = cur / (i+ 1);
    }
    return search(n, k, nums);
}

double search(int n, int k, vector<int> &nums) {
    if(memo[n][k] > 0) return memo[n][k];
    double cur = 0;
    for(int i = n - 1; i > 0; i--) {
        cur += nums[i];
        memo[n][k] = max(memo[n][k], search(i, k - 1, nums) + cur / (n - i));
    }
    return memo[n][k];
}
```

This code implements a dynamic programming solution to find the largest sum of averages after dividing a list of numbers into k parts. It uses memoization to store intermediate results for efficient computation.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	double memo[200][200];
	```
	Initializes a memoization table `memo` to store the maximum averages for each possible subarray division.

2. **Function Definition**
	```cpp
	double largestSumOfAverages(vector<int>& nums, int k) {
	```
	Defines the main function `largestSumOfAverages`, which takes a list of integers `nums` and the number of divisions `k`.

3. **Initialization**
	```cpp
	    memset(memo, 0, sizeof(memo));
	```
	Initializes the memoization table `memo` with zeros using `memset` to ensure no residual values.

4. **Variable Assignment**
	```cpp
	    int n = nums.size();
	```
	Stores the size of the `nums` array in the variable `n`.

5. **Variable Initialization**
	```cpp
	    double cur = 0;
	```
	Initializes the variable `cur` to accumulate the sum of elements as we process them.

6. **Looping through Array**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Begins a loop to iterate through each element of the `nums` array.

7. **Accumulate Sum**
	```cpp
	        cur += nums[i];
	```
	Adds the current element of `nums` to the `cur` variable, updating the accumulated sum.

8. **Memoization Update**
	```cpp
	        memo[i + 1][1] = cur / (i+ 1);
	```
	Calculates the average of the elements from index 0 to i and stores it in the memoization table `memo`.

9. **Return Statement**
	```cpp
	    return search(n, k, nums);
	```
	Calls the recursive `search` function to calculate the largest sum of averages and returns its result.

10. **Function Definition**
	```cpp
	double search(int n, int k, vector<int> &nums) {
	```
	Defines the recursive helper function `search`, which computes the largest possible sum of averages for given indices.

11. **Memoization Check**
	```cpp
	    if(memo[n][k] > 0) return memo[n][k];
	```
	Checks if the result for the current state (n, k) is already computed and returns it if available.

12. **Variable Initialization**
	```cpp
	    double cur = 0;
	```
	Initializes a variable `cur` to accumulate the sum for the current subarray.

13. **Looping through Array**
	```cpp
	    for(int i = n - 1; i > 0; i--) {
	```
	Starts a loop to iterate through the array elements from index `n - 1` to 1 in reverse order.

14. **Accumulate Sum**
	```cpp
	        cur += nums[i];
	```
	Adds the current element `nums[i]` to `cur` for the current subarray.

15. **Memoization Update**
	```cpp
	        memo[n][k] = max(memo[n][k], search(i, k - 1, nums) + cur / (n - i));
	```
	Updates the memoization table with the maximum average found for the current subarray division.

16. **Return Statement**
	```cpp
	    return memo[n][k];
	```
	Returns the computed result for the current subarray division (n, k) from the memoization table.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n * k) where n is the length of the array and k is the number of partitions.
- **Average Case:** O(n * k) as the solution requires evaluating all subarray partitions.
- **Worst Case:** O(n * k) as the solution depends on iterating over the entire array and considering all possible partitions.

The complexity arises from computing the sum of averages for each subarray and storing the results in a dynamic programming table.

### Space Complexity 💾
- **Best Case:** O(n * k) in the best case scenario where all subproblems are distinct and memoization is used optimally.
- **Worst Case:** O(n * k) where n is the length of the array and k is the number of partitions, due to memoization.

The space complexity comes from storing intermediate results in the memoization table.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/largest-sum-of-averages/description/)

---
{{< youtube 3eqwUW6_cx4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

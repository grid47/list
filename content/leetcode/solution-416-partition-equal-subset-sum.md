
+++
authors = ["grid47"]
title = "Leetcode 416: Partition Equal Subset Sum"
date = "2024-09-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 416: Partition Equal Subset Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/416.webp"
youtube = "ZFuagJEpeEU"
youtube_upload_date="2023-07-02"
youtube_thumbnail="https://i.ytimg.com/vi/ZFuagJEpeEU/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/416.webp" 
    alt="A set of numbers with glowing partitions, showing how they can be divided into equal subsets."
    caption="Solution to LeetCode 416: Partition Equal Subset Sum Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given an integer array, determine if it is possible to partition the array into two subsets with equal sum. Return true if such a partition exists, otherwise return false.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array of integers 'nums'.
- **Example:** `For nums = [2, 6, 7, 4], the output is true.`
- **Constraints:**
	- 1 <= nums.length <= 200
	- 1 <= nums[i] <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** Return true if the array can be partitioned into two subsets with equal sum, otherwise return false.
- **Example:** `For nums = [1, 2, 3, 9], the output is false.`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** To check if an array can be partitioned into two subsets with equal sum.

- 1. Calculate the total sum of the array.
- 2. If the sum is odd, return false (since two equal subsets cannot be formed).
- 3. If the sum is even, check if there exists a subset whose sum is half of the total sum using dynamic programming.
- 4. Use a dynamic programming approach to check if it's possible to form a subset with the target sum.
{{< dots >}}
### Problem Assumptions ✅
- The input array contains only positive integers.
- The array length is within the given constraints.
{{< dots >}}
## Examples 🧩
- **Input:** `For nums = [2, 6, 7, 4], the output is true.`  \
  **Explanation:** The array can be partitioned as [2, 6] and [7, 4], both with a sum of 8, making the partition possible.

- **Input:** `For nums = [1, 2, 3, 9], the output is false.`  \
  **Explanation:** The sum of the elements is 15, which is odd, so it's impossible to partition the array into two subsets with equal sum.

{{< dots >}}
## Approach 🚀
To solve the problem, we need to first check if the sum of the array is even. If it's even, we will use dynamic programming to determine if a subset with half the sum exists.

### Initial Thoughts 💭
- The total sum must be even for the array to be partitioned into two subsets with equal sum.
- A dynamic programming approach can be used to check if a subset sum of half the total sum is achievable.
{{< dots >}}
### Edge Cases 🌐
- For large inputs, ensure the dynamic programming approach runs efficiently by considering the time and space complexity.
- If the array has only one element, it cannot be partitioned into two subsets.
- Handle cases where the sum is odd, or the array has a small number of elements.
{{< dots >}}
## Code 💻
```cpp
vector<int> nums;
int memo[201][10001];

bool dp(int idx, int sum) {
    
    if(idx == nums.size()) return sum == 0;
    
    if(memo[idx][sum] != -1) return memo[idx][sum];
    
    bool res = dp(idx + 1, sum);
    
    if(sum >= nums[idx])
        res |= dp(idx + 1, sum - nums[idx]);
    
    return memo[idx][sum] = res;
    
}

bool canPartition(vector<int>& nums) {
    this->nums = nums;
    int sum = 0;
    for(int x: nums)
        sum += x;
    
    if(sum & 1) return false;
    
    sum = sum / 2;
    
    memset(memo, -1, sizeof(memo));
    
    return dp(0, sum);
}
```

The `canPartition` function checks if an array can be partitioned into two subsets with equal sum using dynamic programming. It uses memoization to avoid redundant calculations and reduces time complexity.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	vector<int> nums;
	```
	Declare a vector `nums` to hold the input array of integers that needs to be partitioned.

2. **Array Initialization**
	```cpp
	int memo[201][10001];
	```
	Initialize a 2D array `memo` with dimensions to store computed results for each index and sum to avoid redundant calculations in the dynamic programming solution.

3. **Base Case, Recursion**
	```cpp
	bool dp(int idx, int sum) {
	```
	Define the function `dp` that takes two parameters: `idx`, the current index of the element being considered, and `sum`, the remaining sum we need to achieve.

4. **Base Case Check**
	```cpp
	    if(idx == nums.size()) return sum == 0;
	```
	If we've reached the end of the array (`idx == nums.size()`), return `true` if the remaining `sum` is 0, meaning we've successfully partitioned the array.

5. **Memoization Check**
	```cpp
	    if(memo[idx][sum] != -1) return memo[idx][sum];
	```
	Check if the current state (`idx`, `sum`) has already been computed by looking up the value in the `memo` table. If it has, return the stored result.

6. **Recursive Call**
	```cpp
	    bool res = dp(idx + 1, sum);
	```
	Make a recursive call to `dp` by moving to the next index (`idx + 1`) without including the current element in the sum.

7. **Conditional Check**
	```cpp
	    if(sum >= nums[idx])
	```
	Check if the current element (`nums[idx]`) can be included in the subset, i.e., if the remaining `sum` is greater than or equal to the current element.

8. **Recursive Call with Element Inclusion**
	```cpp
	        res |= dp(idx + 1, sum - nums[idx]);
	```
	Make a recursive call to `dp` including the current element (`nums[idx]`) by subtracting it from the remaining `sum`.

9. **Return Memoized Result**
	```cpp
	    return memo[idx][sum] = res;
	```
	Store the result of the current state (`idx`, `sum`) in the `memo` table and return it.

10. **Main Function Definition**
	```cpp
	bool canPartition(vector<int>& nums) {
	```
	Define the main function `canPartition` that takes a vector `nums` and determines whether it is possible to partition the array into two subsets with equal sum.

11. **Assign Input Vector**
	```cpp
	    this->nums = nums;
	```
	Assign the input `nums` to the class member variable `nums` for use in the `dp` function.

12. **Sum Calculation**
	```cpp
	    int sum = 0;
	```
	Initialize a variable `sum` to store the total sum of the elements in `nums`.

13. **Loop Iteration**
	```cpp
	    for(int x: nums)
	```
	Iterate through each element `x` in the `nums` array.

14. **Sum Calculation**
	```cpp
	        sum += x;
	```
	Accumulate the value of each element `x` to compute the total sum of the elements in the array.

15. **Odd Sum Check**
	```cpp
	    if(sum & 1) return false;
	```
	Check if the sum is odd (`sum & 1`). If it is, return `false` since an odd sum cannot be partitioned into two equal subsets.

16. **Divide Sum by Two**
	```cpp
	    sum = sum / 2;
	```
	Since the array needs to be split into two equal subsets, divide the total `sum` by 2 to determine the target sum for one subset.

17. **Memoization Initialization**
	```cpp
	    memset(memo, -1, sizeof(memo));
	```
	Initialize the `memo` table by setting all values to `-1`, indicating that no state has been computed yet.

18. **Return DP Function Call**
	```cpp
	    return dp(0, sum);
	```
	Call the `dp` function starting from index 0 with the target sum (`sum`). Return the result of this call.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n * sum)
- **Average Case:** O(n * sum)
- **Worst Case:** O(n * sum)

The time complexity is O(n * sum), where n is the number of elements in the array and sum is the total sum of the array.

### Space Complexity 💾
- **Best Case:** O(sum)
- **Worst Case:** O(sum)

The space complexity is O(sum), where sum is the total sum of the array, due to the dynamic programming array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/partition-equal-subset-sum/description/)

---
{{< youtube ZFuagJEpeEU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

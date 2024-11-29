
+++
authors = ["grid47"]
title = "Leetcode 2597: The Number of Beautiful Subsets"
date = "2024-02-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2597: The Number of Beautiful Subsets in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Math","Dynamic Programming","Backtracking","Sorting","Combinatorics"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "Dle_SpjHTio"
youtube_upload_date="2024-05-23"
youtube_thumbnail="https://i.ytimg.com/vi/Dle_SpjHTio/maxresdefault.jpg"
comments = true
+++



---
You are given an array of positive integers `nums` and a positive integer `k`. A subset of `nums` is considered beautiful if it does not contain any two integers whose absolute difference is equal to `k`. Your task is to return the number of non-empty beautiful subsets of the array `nums`. A subset is formed by deleting some (possibly none) elements from `nums`, and two subsets are different if their selected indices are different.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array `nums` and a positive integer `k`.
- **Example:** `For `nums = [3, 5, 7]` and `k = 2`.`
- **Constraints:**
	- 1 <= nums.length <= 20
	- 1 <= nums[i], k <= 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of non-empty beautiful subsets of the array `nums`.
- **Example:** `For `nums = [3, 5, 7]` and `k = 2`, the output should be `4`.`
- **Constraints:**
	- The output will be a positive integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find all subsets of `nums` and check if they meet the condition that no two elements have an absolute difference of `k`.

- 1. Generate all possible non-empty subsets of the array `nums`.
- 2. For each subset, check if it contains two elements with an absolute difference of `k`.
- 3. Count and return the subsets that do not contain any such pair.
{{< dots >}}
### Problem Assumptions ✅
- The array `nums` will contain only positive integers.
- The value of `k` will be a positive integer.
{{< dots >}}
## Examples 🧩
- **Input:** `For `nums = [3, 5, 7]` and `k = 2``  \
  **Explanation:** The beautiful subsets are `[3]`, `[5]`, `[7]`, and `[3, 7]`, because none of them contains a pair of numbers with an absolute difference of `2`.

- **Input:** `For `nums = [1, 4, 6]` and `k = 3``  \
  **Explanation:** The beautiful subsets are `[1]`, `[4]`, `[6]`, `[1, 4]`, and `[4, 6]` because none contains two elements with an absolute difference of `3`.

{{< dots >}}
## Approach 🚀
The approach involves generating all non-empty subsets of the array `nums` and checking whether any subset contains two elements with an absolute difference of `k`. If a subset does not contain such a pair, it is counted as a beautiful subset.

### Initial Thoughts 💭
- The problem requires finding subsets without two elements having a specific difference.
- Given that the array length is small (up to 20), it is feasible to check all subsets.
- Using a recursive approach or dynamic programming could help generate subsets efficiently.
{{< dots >}}
### Edge Cases 🌐
- There will always be a non-empty input array as per the problem constraints.
- The maximum length of `nums` is 20, so the solution must handle up to 2^20 subsets.
- If `k` is greater than the largest difference between any two elements, all subsets will be beautiful.
- The array length is small enough (maximum 20), so checking all subsets is feasible.
{{< dots >}}
## Code 💻
```cpp
vector<int> cnt, nums;

int dp(int idx, int k) {
    if(idx == nums.size()) return 1;
    int ans = 0;
    if(nums[idx] - k >= 0 && (cnt[nums[idx] - k] > 0)) {
        ans += dp(idx + 1, k);
    } else {
        ans += dp(idx + 1, k);
        cnt[nums[idx]]++;
        ans += dp(idx + 1, k);
        cnt[nums[idx]]--;            
    }
    return ans;
}

int beautifulSubsets(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    cnt.resize(1001, 0);
    this->nums = nums;
    return dp(0, k) - 1; // exluding none selected
}
```

This code defines a dynamic programming approach to finding beautiful subsets in an array `nums`. A subset is considered beautiful if the difference between any two elements is divisible by `k`. The solution uses recursion and memoization to efficiently solve the problem.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	vector<int> cnt, nums;
	```
	Initialize two vectors: `cnt` for counting occurrences of numbers and `nums` for storing the input array.

2. **Function Definition**
	```cpp
	int dp(int idx, int k) {
	```
	Define the recursive function `dp` that takes an index `idx` and a difference `k` to calculate the number of valid subsets.

3. **Base Case**
	```cpp
	    if(idx == nums.size()) return 1;
	```
	The base case of the recursion: if the index reaches the end of the array, return 1, indicating a valid subset.

4. **Variable Declaration**
	```cpp
	    int ans = 0;
	```
	Declare a variable `ans` to store the count of valid subsets.

5. **Subset Validation**
	```cpp
	    if(nums[idx] - k >= 0 && (cnt[nums[idx] - k] > 0)) {
	```
	Check if the current number minus `k` is valid and if the count of that number is greater than 0.

6. **Recursive Call**
	```cpp
	        ans += dp(idx + 1, k);
	```
	If the condition is met, make a recursive call to check the next element and accumulate the result in `ans`.

7. **Else Case**
	```cpp
	    } else {
	```
	If the condition isn't met, proceed with the following alternative logic.

8. **Recursive Call (No Selection)**
	```cpp
	        ans += dp(idx + 1, k);
	```
	First, try the case where the current element is not selected in the subset and make a recursive call.

9. **Increment Count**
	```cpp
	        cnt[nums[idx]]++;
	```
	Increment the count of the current element in the `cnt` vector.

10. **Recursive Call (With Selection)**
	```cpp
	        ans += dp(idx + 1, k);
	```
	Make a recursive call to consider the current element as part of the subset.

11. **Decrement Count**
	```cpp
	        cnt[nums[idx]]--;            
	```
	After considering the element in the subset, decrement its count to backtrack.

12. **Return Statement**
	```cpp
	    return ans;
	```
	Return the result `ans`, which represents the number of valid subsets found.

13. **Function Definition**
	```cpp
	int beautifulSubsets(vector<int>& nums, int k) {
	```
	Define the main function `beautifulSubsets` that sets up the initial values and calls the `dp` function.

14. **Sort Input**
	```cpp
	    sort(nums.begin(), nums.end());
	```
	Sort the input array `nums` to make it easier to handle subsets.

15. **Resize Count Array**
	```cpp
	    cnt.resize(1001, 0);
	```
	Resize the `cnt` array to store counts of numbers in the range 0 to 1000, initializing all counts to 0.

16. **Store Input Array**
	```cpp
	    this->nums = nums;
	```
	Store the input array `nums` as a member variable of the class.

17. **Return Result**
	```cpp
	    return dp(0, k) - 1; // exluding none selected
	```
	Call the `dp` function to compute the number of valid subsets, subtract 1 to exclude the empty subset.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(2^n)
- **Average Case:** O(2^n)
- **Worst Case:** O(2^n)

The time complexity is O(2^n) because we need to check all subsets, where n is the size of the array `nums`.

### Space Complexity 💾
- **Best Case:** O(2^n)
- **Worst Case:** O(2^n)

The space complexity is O(2^n) because we store all possible subsets of the array `nums`.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/the-number-of-beautiful-subsets/description/)

---
{{< youtube Dle_SpjHTio >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

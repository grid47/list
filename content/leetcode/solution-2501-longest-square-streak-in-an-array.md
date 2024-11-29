
+++
authors = ["grid47"]
title = "Leetcode 2501: Longest Square Streak in an Array"
date = "2024-03-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2501: Longest Square Streak in an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Binary Search","Dynamic Programming","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "prcJMNtokGI"
youtube_upload_date="2022-12-11"
youtube_thumbnail="https://i.ytimg.com/vi_webp/prcJMNtokGI/maxresdefault.webp"
comments = true
+++



---
You are given an integer array nums. A subsequence of nums is called a square streak if its length is at least 2, and after sorting the subsequence, each element (except the first one) is the square of the previous number. Return the length of the longest square streak in nums, or -1 if no square streak exists.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an array nums, where each element is a positive integer.
- **Example:** `Input: nums = [9,3,16,2,4,81]`
- **Constraints:**
	- 2 <= nums.length <= 10^5
	- 2 <= nums[i] <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the length of the longest subsequence that forms a square streak. If no such subsequence exists, return -1.
- **Example:** `Output: 3`
- **Constraints:**
	- If no subsequence satisfies the conditions, return -1.

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the longest subsequence where each element (except the first) is the square of the previous one.

- 1. Sort the array to easily check the relationship between elements.
- 2. Use dynamic programming to store the longest square streak for each element.
- 3. Iterate over the array, check for the condition where an element is the square of the previous one.
- 4. Keep track of the maximum length of any such subsequence.
{{< dots >}}
### Problem Assumptions ✅
- There are no duplicate numbers in the array.
- The array contains at least two elements.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [9, 3, 16, 2, 4, 81]`  \
  **Explanation:** In this example, the subsequence [4, 16, 81] is a square streak. After sorting, it becomes [4, 16, 81], where 16 = 4 * 4 and 81 = 16 * 16. Therefore, the longest square streak has a length of 3.

- **Input:** `Input: nums = [5, 2, 3, 7]`  \
  **Explanation:** There is no subsequence that satisfies the square streak condition, so the output is -1.

{{< dots >}}
## Approach 🚀
The approach involves sorting the array and using dynamic programming to find the longest subsequence where each number is the square of the previous one.

### Initial Thoughts 💭
- Sorting the array helps to easily identify potential square relationships between numbers.
- Using dynamic programming ensures that we can efficiently calculate the longest square streak by considering each element as part of a subsequence.
{{< dots >}}
### Edge Cases 🌐
- The array will always have at least two elements, so this case is not applicable.
- Ensure the solution handles large inputs efficiently, given the constraint of up to 10^5 elements.
- Handle arrays where no subsequences form a square streak.
- The solution must work efficiently within the given constraints.
{{< dots >}}
## Code 💻
```cpp
int longestSquareStreak(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<int> dp(n, 1);
    int mx = 1;
    for(int i= 0; i < n; i++) {
        long long tmp = (long long) nums[i] * nums[i];
        if(tmp > INT_MAX) break;
        auto it = lower_bound(nums.begin(), nums.end(), tmp);
        if(it == nums.end()) break;
        int pos = it - nums.begin();
        while(pos < n && nums[i] * nums[i] == nums[pos]) {
                dp[pos] = max(dp[pos], 1 + dp[i]);                
                mx = max(mx, dp[pos]);  
                pos++;
        }
    }
    return mx == 1? -1: mx;
}
```

The function `longestSquareStreak` finds the length of the longest streak of numbers in a sorted list such that the square of any number in the streak is also present in the list. If no streak is found, it returns -1.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int longestSquareStreak(vector<int>& nums) {
	```
	Defines the function `longestSquareStreak` which takes a vector `nums` and returns an integer representing the longest streak of numbers whose squares also exist in the list.

2. **Variable Initialization**
	```cpp
	    int n = nums.size();
	```
	Initializes the variable `n` to the size of the vector `nums`.

3. **Sorting**
	```cpp
	    sort(nums.begin(), nums.end());
	```
	Sorts the vector `nums` in ascending order.

4. **Dynamic Programming Initialization**
	```cpp
	    vector<int> dp(n, 1);
	```
	Creates a vector `dp` initialized to 1, which will store the longest streak of numbers for each element.

5. **Variable Initialization**
	```cpp
	    int mx = 1;
	```
	Initializes the variable `mx` to 1 to store the maximum streak length.

6. **Looping**
	```cpp
	    for(int i= 0; i < n; i++) {
	```
	Starts a loop to iterate over each element `i` in the sorted vector `nums`.

7. **Mathematical Operations**
	```cpp
	        long long tmp = (long long) nums[i] * nums[i];
	```
	Calculates the square of the current element `nums[i]` and stores it in the variable `tmp`.

8. **Conditionals**
	```cpp
	        if(tmp > INT_MAX) break;
	```
	Checks if the square of the number exceeds the maximum possible integer value, in which case the loop breaks.

9. **Binary Search**
	```cpp
	        auto it = lower_bound(nums.begin(), nums.end(), tmp);
	```
	Uses binary search (`lower_bound`) to find the position of `tmp` in the sorted vector `nums`.

10. **Conditionals**
	```cpp
	        if(it == nums.end()) break;
	```
	Checks if the position returned by `lower_bound` is at the end of the vector, meaning `tmp` is not found.

11. **Pointer Operations**
	```cpp
	        int pos = it - nums.begin();
	```
	Calculates the index of the found element `tmp` in the vector `nums`.

12. **Looping**
	```cpp
	        while(pos < n && nums[i] * nums[i] == nums[pos]) {
	```
	Starts a nested loop to check for consecutive elements in `nums` that match the square of the current element.

13. **Dynamic Programming Update**
	```cpp
	            dp[pos] = max(dp[pos], 1 + dp[i]);
	```
	Updates the value of `dp[pos]` to be the maximum of its current value or the streak length of `dp[i]` plus 1.

14. **Result Calculation**
	```cpp
	            mx = max(mx, dp[pos]);
	```
	Updates the maximum streak length `mx` by comparing it with the current streak length `dp[pos]`.

15. **Pointer Operations**
	```cpp
	            pos++;
	```
	Increments the position `pos` to check the next element in the streak.

16. **Return Statement**
	```cpp
	    return mx == 1? -1: mx;
	```
	Returns the result: if no streaks were found (`mx == 1`), returns -1; otherwise, returns the length of the longest streak.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The sorting step takes O(n log n), and the dynamic programming step requires O(n) time, resulting in an overall time complexity of O(n log n).

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the dp array used for storing the longest square streaks for each element.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/longest-square-streak-in-an-array/description/)

---
{{< youtube prcJMNtokGI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

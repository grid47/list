
+++
authors = ["grid47"]
title = "Leetcode 2563: Count the Number of Fair Pairs"
date = "2024-02-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2563: Count the Number of Fair Pairs in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Binary Search","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "Z9hOAQFSQ_I"
youtube_upload_date="2023-02-12"
youtube_thumbnail="https://i.ytimg.com/vi_webp/Z9hOAQFSQ_I/maxresdefault.webp"
comments = true
+++



---
Given an integer array `nums` of size `n` and two integers `lower` and `upper`, find the number of fair pairs. A pair `(i, j)` is considered fair if it satisfies the following conditions:

- `0 <= i < j < n`
- `lower <= nums[i] + nums[j] <= upper`

Return the number of such pairs.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an array of integers `nums` of size `n`, and two integers `lower` and `upper`.
- **Example:** `nums = [0,1,7,4,4,5], lower = 3, upper = 6`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- -10^9 <= nums[i] <= 10^9
	- -10^9 <= lower <= upper <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of fair pairs (i, j) satisfying the given conditions.
- **Example:** `Output: 6`
- **Constraints:**
	- The output should be a single integer representing the number of fair pairs.

{{< dots >}}
### Core Logic 🔍
**Goal:** To count the number of fair pairs (i, j) such that the sum of `nums[i] + nums[j]` lies within the range [lower, upper].

- Sort the array `nums` to efficiently check pairs.
- For each element in the array, calculate the range [lower - nums[i], upper - nums[i]] for the second element of the pair.
- Use binary search to find the bounds for valid second elements in the array.
- Count the number of pairs (i, j) that satisfy the condition `lower <= nums[i] + nums[j] <= upper`.
{{< dots >}}
### Problem Assumptions ✅
- The array nums is 0-indexed.
- The integers lower and upper are inclusive and must satisfy lower <= upper.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1:`  \
  **Explanation:** Given the array nums = [0,1,7,4,4,5], lower = 3, upper = 6, we can form 6 valid pairs. The pairs are: (0,3), (0,4), (0,5), (1,3), (1,4), and (1,5).

- **Input:** `Example 2:`  \
  **Explanation:** Given the array nums = [1,7,9,2,5], lower = 11, upper = 11, there is only one valid pair: (2,3), where the sum of nums[2] + nums[3] equals 11.

{{< dots >}}
## Approach 🚀
The approach to solving this problem involves sorting the array and using binary search to efficiently count valid pairs that satisfy the condition.

### Initial Thoughts 💭
- Sorting the array helps in quickly finding valid pairs using binary search.
- For each element, we need to check a range of possible values for the second element of the pair.
- Sorting the array allows us to efficiently find pairs using binary search, reducing the time complexity.
{{< dots >}}
### Edge Cases 🌐
- An empty input array should return 0, as there are no pairs to check.
- The approach should efficiently handle arrays of size up to 10^5, as specified in the constraints.
- If nums contains very large or very small numbers, the approach must still work within the given bounds of [-10^9, 10^9].
- The solution must handle inputs efficiently to avoid timeouts, particularly when nums is large.
{{< dots >}}
## Code 💻
```cpp
long long countFairPairs(vector<int>& nums, int lower, int upper) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    long long cnt = 0;
    for(int i = 0; i < n; i++) {
        int l = lower - nums[i];
        int r = upper - nums[i];
        int u = upper_bound(nums.begin(), nums.end(), r) - nums.begin();
        int b = max((int)(lower_bound(nums.begin(), nums.end(), l) - nums.begin()), i + 1);
        cnt +=  (u < b)? 0: u - b;
    }
    return cnt;
}
```

This function counts the number of fair pairs in the given vector `nums` such that the sum of any two elements lies between the specified `lower` and `upper` bounds. It uses sorting and binary search to efficiently calculate the number of pairs.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	long long countFairPairs(vector<int>& nums, int lower, int upper) {
	```
	The function `countFairPairs` is defined to take a vector `nums` of integers and two integers `lower` and `upper` that represent the bounds for the sum of pairs.

2. **Variable Initialization**
	```cpp
	    int n = nums.size();
	```
	The variable `n` is initialized to store the size of the input array `nums`.

3. **Sorting**
	```cpp
	    sort(nums.begin(), nums.end());
	```
	The vector `nums` is sorted in ascending order to facilitate efficient searching of pairs later.

4. **Variable Initialization**
	```cpp
	    long long cnt = 0;
	```
	The variable `cnt` is initialized to 0, which will be used to count the number of fair pairs.

5. **Loop Initialization**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	A loop is set up to iterate through each element of the sorted vector `nums`.

6. **Calculating Lower Bound**
	```cpp
	        int l = lower - nums[i];
	```
	For each element `nums[i]`, calculate the value `l`, which is the difference between the `lower` bound and `nums[i]`. This represents the smallest possible value for the second element in the pair.

7. **Calculating Upper Bound**
	```cpp
	        int r = upper - nums[i];
	```
	Similarly, calculate the value `r`, which is the difference between the `upper` bound and `nums[i]`. This represents the largest possible value for the second element in the pair.

8. **Binary Search for Upper Bound**
	```cpp
	        int u = upper_bound(nums.begin(), nums.end(), r) - nums.begin();
	```
	Using binary search, the `upper_bound` function is used to find the position in the sorted array where the value `r` should be inserted. The result is stored in `u`.

9. **Binary Search for Lower Bound**
	```cpp
	        int b = max((int)(lower_bound(nums.begin(), nums.end(), l) - nums.begin()), i + 1);
	```
	Similarly, the `lower_bound` function is used to find the position in the sorted array where the value `l` should be inserted. The result is stored in `b`, but it's adjusted to ensure that the pair starts after the current element `i`.

10. **Counting Valid Pairs**
	```cpp
	        cnt +=  (u < b)? 0: u - b;
	```
	If `u` is less than `b`, there are no valid pairs for the current element `i`, so 0 is added to `cnt`. Otherwise, the number of valid pairs is `u - b`, which is added to `cnt`.

11. **Return Statement**
	```cpp
	    return cnt;
	```
	Return the final count of fair pairs stored in `cnt`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The time complexity is dominated by the sorting step (O(n log n)) and binary search for each element (O(log n)).

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the need to store the sorted array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/count-the-number-of-fair-pairs/description/)

---
{{< youtube Z9hOAQFSQ_I >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |


+++
authors = ["grid47"]
title = "Leetcode 2568: Minimum Impossible OR"
date = "2024-02-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2568: Minimum Impossible OR in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Bit Manipulation","Brainteaser"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "ofCTBFFzB2Q"
youtube_upload_date="2023-02-18"
youtube_thumbnail="https://i.ytimg.com/vi/ofCTBFFzB2Q/maxresdefault.jpg"
comments = true
+++



---
You are given a 0-indexed integer array nums. A number x is expressible from nums if there exists a subsequence of elements in nums whose bitwise OR equals x. Your task is to return the smallest positive integer that cannot be expressed as the bitwise OR of any subsequence from nums.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array nums, where each element represents a number.
- **Example:** `For example, nums = [1, 2, 4].`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- 1 <= nums[i] <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the smallest positive integer that cannot be expressed as the bitwise OR of any subsequence from nums.
- **Example:** `For nums = [1, 2, 4], the output is 8.`
- **Constraints:**
	- The result must be a positive integer that cannot be formed by the OR operation of any subsequence of the input array.

{{< dots >}}
### Core Logic 🔍
**Goal:** To find the smallest positive integer that cannot be expressed as the bitwise OR of any subsequence from nums.

- 1. Initialize a set to store the unique OR values of subsequences.
- 2. Traverse the nums array and compute the bitwise OR for all possible subsequences.
- 3. Check which positive integer is not part of the computed values, starting from 1 upwards.
{{< dots >}}
### Problem Assumptions ✅
- The nums array will always contain at least one element.
- The integers in nums are positive and within the specified range.
{{< dots >}}
## Examples 🧩
- **Input:** `For nums = [1, 2, 4], we can express 1, 2, 3 (from 1 | 2), 4, 5 (from 1 | 4), 6 (from 2 | 4), and 7 (from 1 | 2 | 4).`  \
  **Explanation:** The smallest integer that cannot be expressed is 8.

- **Input:** `For nums = [7, 3, 1], we can express 1, 3, 7, 4 (from 1 | 3), and 6 (from 3 | 7).`  \
  **Explanation:** The smallest integer that cannot be expressed is 8.

{{< dots >}}
## Approach 🚀
The approach is based on finding all possible bitwise OR values from subsequences of the array and identifying the smallest integer that cannot be formed.

### Initial Thoughts 💭
- Bitwise OR is cumulative, so we can track which values can be formed from any subsequence.
- Start with a small integer (1) and check whether it is expressible. If not, that is the smallest non-expressible integer.
{{< dots >}}
### Edge Cases 🌐
- Empty input is not possible since nums contains at least one integer.
- The solution should be efficient enough to handle large inputs, up to 100,000 elements.
- If all elements are powers of two, it is possible to express every positive integer from 1 up to the sum of all the powers of two.
- Ensure the solution can handle arrays with large values efficiently.
{{< dots >}}
## Code 💻
```cpp
int minImpossibleOR(vector<int>& nums) {
    set<int> cnt;
    int n = nums.size();
    for(int i = 0; i < n; i++) {
        cnt.insert(nums[i]);
    }
    int ret = 1;
    while(cnt.count(ret)) {
        ret *= 2;
    }
    // to create all the numbers till a positive integer
    // presents of all the powers of 2s below it are mandatory.
    return ret;
}
```

This code finds the smallest positive integer that is not the bitwise OR of any subset of elements in the given array `nums`.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int minImpossibleOR(vector<int>& nums) {
	```
	Declares the function `minImpossibleOR` which takes a vector `nums` and returns an integer, representing the smallest impossible OR value.

2. **Set Initialization**
	```cpp
	    set<int> cnt;
	```
	Declares a set `cnt` to store unique elements from the array, ensuring no duplicates are included.

3. **Array Size Calculation**
	```cpp
	    int n = nums.size();
	```
	Calculates the size of the input array `nums` and stores it in variable `n`.

4. **Loop**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Begins a loop to iterate through the entire array `nums`.

5. **Set Insertion**
	```cpp
	        cnt.insert(nums[i]);
	```
	Inserts each element of the array `nums` into the set `cnt`. This ensures that only unique elements are considered.

6. **Variable Initialization**
	```cpp
	    int ret = 1;
	```
	Initializes the variable `ret` with a value of `1`, representing the smallest possible result.

7. **Loop**
	```cpp
	    while(cnt.count(ret)) {
	```
	Starts a loop that continues while the set `cnt` contains the current value of `ret`.

8. **Multiplication**
	```cpp
	        ret *= 2;
	```
	Doubles the value of `ret` in each iteration, ensuring that `ret` is a power of 2.

9. **Return Statement**
	```cpp
	    return ret;
	```
	Returns the value of `ret`, which is the smallest positive integer that is not present in the set `cnt`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n), where n is the number of elements in nums.
- **Average Case:** O(n log n), dominated by the sorting step.
- **Worst Case:** O(n log n), as all subsequences need to be considered.

The sorting operation dominates the time complexity.

### Space Complexity 💾
- **Best Case:** O(n), in case we store all possible OR results.
- **Worst Case:** O(n), where n is the number of elements in nums.

Space complexity is driven by the storage required for the nums array and intermediate OR results.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-impossible-or/description/)

---
{{< youtube ofCTBFFzB2Q >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

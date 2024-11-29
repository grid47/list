
+++
authors = ["grid47"]
title = "Leetcode 2784: Check if Array is Good"
date = "2024-02-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2784: Check if Array is Good in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sorting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "le-u0OA8HMM"
youtube_upload_date="2023-07-22"
youtube_thumbnail="https://i.ytimg.com/vi_webp/le-u0OA8HMM/maxresdefault.webp"
comments = true
+++



---
Determine if an integer array nums is a permutation of a special array base[n], defined as [1, 2, ..., n - 1, n, n], where 1 to n-1 appear once and n appears twice.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array nums.
- **Example:** `Input: nums = [4, 2, 1, 4, 3]`
- **Constraints:**
	- 1 <= nums.length <= 100
	- 1 <= nums[i] <= 200

{{< dots >}}
### Output Specifications 📤
- **Output:** Return true if nums can be rearranged to form any base[n] array; otherwise, return false.
- **Example:** `Output: true`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Check if nums matches the structure of a valid base[n] array.

- Identify the maximum value n in nums.
- Verify that nums contains exactly two occurrences of n.
- Verify that nums contains all integers from 1 to n-1 exactly once.
- Ensure the length of nums is n+1.
{{< dots >}}
### Problem Assumptions ✅
- The input array may contain duplicates.
- The maximum value in the array determines the candidate base[n].
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [4, 2, 1, 4, 3]`  \
  **Explanation:** The array matches base[4] = [1, 2, 3, 4, 4], so the output is true.

- **Input:** `Input: nums = [2, 1, 3]`  \
  **Explanation:** The array does not match any valid base[n] structure, so the output is false.

{{< dots >}}
## Approach 🚀
Iterate through the array to validate its structure against a possible base[n].

### Initial Thoughts 💭
- The array must have a specific structure to be valid.
- The maximum value in nums determines the potential base[n].
- We need to check counts of numbers in nums to validate the match.
{{< dots >}}
### Edge Cases 🌐
- Input: nums = []. Output: false.
- Input: nums = [1, 2, ..., 99, 100, 100]. Output: true.
- Input: nums = [1, 1]. Output: true.
- Handling arrays where nums.length != n+1 should return false.
{{< dots >}}
## Code 💻
```cpp
bool isGood(vector<int>& nums) {
    int cnt[201] = {}, n = nums.size() - 1;
    for (auto num : nums)
        ++cnt[num];
    return all_of(begin(cnt) + 1, begin(cnt) + n, [](int c){ return c == 1; }) && cnt[n] == 2;
}
```

The `isGood` function checks if a given vector `nums` contains a specific set of values. It ensures that all elements except the largest one occur exactly once, and the largest element occurs exactly twice.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	bool isGood(vector<int>& nums) {
	```
	This line defines the function `isGood` which takes a vector of integers `nums` and returns a boolean value indicating if the array meets the specified condition.

2. **Variable Initialization**
	```cpp
	    int cnt[201] = {}, n = nums.size() - 1;
	```
	Here, an array `cnt` of size 201 is initialized to track the frequency of each number in the `nums` vector. The variable `n` stores the size of the vector minus one, representing the largest number in the vector.

3. **Looping**
	```cpp
	    for (auto num : nums)
	```
	This for-each loop iterates through each element `num` in the `nums` vector.

4. **Frequency Update**
	```cpp
	        ++cnt[num];
	```
	For each number `num`, its corresponding frequency in the `cnt` array is incremented by one.

5. **Return Statement**
	```cpp
	    return all_of(begin(cnt) + 1, begin(cnt) + n, [](int c){ return c == 1; }) && cnt[n] == 2;
	```
	This return statement checks two conditions: 1) that all elements in the `cnt` array (except the last one) occur exactly once, using `all_of`, and 2) that the largest number occurs exactly twice. If both conditions are true, the function returns true, otherwise, it returns false.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

Iterate through the array and validate counts.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

Use a count array or hashmap to store counts.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/check-if-array-is-good/description/)

---
{{< youtube le-u0OA8HMM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

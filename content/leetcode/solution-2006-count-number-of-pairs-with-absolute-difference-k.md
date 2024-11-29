
+++
authors = ["grid47"]
title = "Leetcode 2006: Count Number of Pairs With Absolute Difference K"
date = "2024-04-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2006: Count Number of Pairs With Absolute Difference K in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "noP_AsQlgQc"
youtube_upload_date="2021-09-18"
youtube_thumbnail="https://i.ytimg.com/vi/noP_AsQlgQc/maxresdefault.jpg"
comments = true
+++



---
Given an integer array nums and an integer k, return the number of pairs (i, j) where i < j such that |nums[i] - nums[j]| == k.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array nums and an integer k.
- **Example:** `nums = [3, 5, 2, 6, 7], k = 3`
- **Constraints:**
	- 1 <= nums.length <= 200
	- 1 <= nums[i] <= 100
	- 1 <= k <= 99

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of pairs (i, j) where i < j such that |nums[i] - nums[j]| == k.
- **Example:** `2`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to count the number of pairs with an absolute difference of k.

- 1. Create a frequency count of the elements in the array.
- 2. For each element x, check if x + k or x - k exists in the array.
- 3. Add the count of valid pairs for each element.
- 4. Return the total count of valid pairs.
{{< dots >}}
### Problem Assumptions ✅
- The solution should be efficient given the constraints.
- Handling of duplicate elements is necessary to avoid over-counting pairs.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [3, 5, 2, 6, 7], k = 3`  \
  **Explanation:** The valid pairs with an absolute difference of 3 are (3, 6) and (5, 2). Thus, the output is 2.

- **Input:** `nums = [1, 1, 3, 5], k = 2`  \
  **Explanation:** The valid pair with an absolute difference of 2 is (3, 5). Hence, the output is 1.

- **Input:** `nums = [8, 2, 5, 6, 9], k = 4`  \
  **Explanation:** The valid pairs with an absolute difference of 4 are (8, 4) and (5, 9). The output is 2.

{{< dots >}}
## Approach 🚀
To solve this problem efficiently, we can use a hash map to count the occurrences of each number in the array and use it to check if the corresponding pairs exist that satisfy the condition.

### Initial Thoughts 💭
- We need to check each element's potential to form a valid pair with another element based on the given difference k.
- Handling multiple occurrences of the same number requires careful counting.
- A hash map will help in efficiently checking if a number exists that satisfies the absolute difference condition.
{{< dots >}}
### Edge Cases 🌐
- If the array is empty, the result should be 0 since there are no elements to form pairs.
- If the array has a large number of elements, ensure the solution handles them efficiently with linear or near-linear time complexity.
- If the array contains duplicate elements, ensure not to double-count pairs that are the same but occur at different indices.
- Make sure the solution handles arrays of size up to 200 elements efficiently.
{{< dots >}}
## Code 💻
```cpp
int countKDifference(vector<int>& nums, int k) {
    int cnt[101] = {}, res = 0;
    for (auto n : nums)
        ++cnt[n];
    for (int i = k + 1; i < 101; ++i)
        res += cnt[i] * cnt[i - k];
    return res;
}
```

The function calculates the number of pairs in the `nums` array where the absolute difference between the elements is equal to a given value `k`. It uses an array `cnt` to store the frequency of each number and then iterates to find the number of valid pairs.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int countKDifference(vector<int>& nums, int k) {
	```
	Defines the function `countKDifference` which takes a vector `nums` and an integer `k` as inputs, and returns the number of pairs with the absolute difference of `k`.

2. **Variable Declaration**
	```cpp
	    int cnt[101] = {}, res = 0;
	```
	Declares an array `cnt` of size 101 to store the frequency count of each element in the range [0, 100] and an integer `res` to store the final result.

3. **Loop Iteration**
	```cpp
	    for (auto n : nums)
	```
	Starts a loop to iterate through each element `n` in the input vector `nums`.

4. **Frequency Counting**
	```cpp
	        ++cnt[n];
	```
	Increments the count of the number `n` in the `cnt` array, effectively counting the frequency of each number in `nums`.

5. **Loop Iteration**
	```cpp
	    for (int i = k + 1; i < 101; ++i)
	```
	Starts another loop that iterates through numbers starting from `k+1` up to 100 to check if there exists a corresponding pair with the difference of `k`.

6. **Result Calculation**
	```cpp
	        res += cnt[i] * cnt[i - k];
	```
	For each `i`, it calculates the number of valid pairs by multiplying the count of `i` and the count of `i-k`, adding this to the result `res`.

7. **Return Statement**
	```cpp
	    return res;
	```
	Returns the final result, which is the number of valid pairs with the absolute difference equal to `k`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because we loop over the array once to count elements and then check for pairs in constant time using a frequency map.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) because we use a frequency map to store counts of each element in the array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/description/)

---
{{< youtube noP_AsQlgQc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |


+++
authors = ["grid47"]
title = "Leetcode 2640: Find the Score of All Prefixes of an Array"
date = "2024-02-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2640: Find the Score of All Prefixes of an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "Xp413jTlTNk"
youtube_upload_date="2023-04-15"
youtube_thumbnail="https://i.ytimg.com/vi_webp/Xp413jTlTNk/maxresdefault.webp"
comments = true
+++



---
You are given a 0-indexed integer array `nums` of length `n`. For each prefix `nums[0..i]`, you are asked to calculate its 'score.' The score is defined as the sum of the conversion array of the prefix. The conversion array of a prefix is formed by the following rule: conver[i] = nums[i] + max(nums[0..i]), where max(nums[0..i]) is the maximum value in the prefix from the start to the current index.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array `nums` of length `n` where 1 <= n <= 10^5 and 1 <= nums[i] <= 10^9.
- **Example:** `nums = [4, 6, 2, 9]`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- 1 <= nums[i] <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an integer array `ans` of length `n`, where each `ans[i]` represents the score of the prefix `nums[0..i]`.
- **Example:** `Output: [8, 18, 26, 44]`
- **Constraints:**
	- The output array will have exactly `n` elements, each corresponding to the score of the prefix.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to compute the score of each prefix of the array. For each index `i`, compute the conversion array element as the sum of `nums[i]` and the maximum value encountered in the array up to that index.

- Step 1: Initialize a variable to keep track of the maximum value encountered so far in the array.
- Step 2: Iterate over the array, and for each element at index `i`, calculate its conversion array value by adding `nums[i]` to the maximum value up to that point.
- Step 3: Maintain a running sum of the conversion array values to store the score of the prefix `nums[0..i]`.
- Step 4: Return the array of scores for all prefixes.
{{< dots >}}
### Problem Assumptions ✅
- The array `nums` is non-empty and contains positive integers within the specified range.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [4, 6, 2, 9]`  \
  **Explanation:** For the prefix [4], the conversion array is [8] with score 8. For the prefix [4, 6], the conversion array is [8, 12] with score 18. For the prefix [4, 6, 2], the conversion array is [8, 12, 14] with score 26. For the prefix [4, 6, 2, 9], the conversion array is [8, 12, 14, 20] with score 44.

- **Input:** `nums = [1, 2, 3]`  \
  **Explanation:** For the prefix [1], the conversion array is [2] with score 2. For the prefix [1, 2], the conversion array is [2, 4] with score 6. For the prefix [1, 2, 3], the conversion array is [2, 4, 6] with score 12.

{{< dots >}}
## Approach 🚀
The problem can be solved by iterating through the array while maintaining the maximum element encountered up to the current index. We can calculate the conversion array value on the fly and maintain a running sum for each prefix score.

### Initial Thoughts 💭
- The problem asks us to compute a running score for each prefix of the array, so a straightforward approach would be to maintain the maximum of the prefix as we iterate through the array.
- By keeping track of the maximum element encountered so far, we can efficiently compute the conversion array for each prefix and accumulate the score in a single pass.
{{< dots >}}
### Edge Cases 🌐
- If the input array is empty, the result should also be an empty array.
- The solution should handle large arrays with up to 100,000 elements efficiently.
- When all elements are the same, the result will follow a predictable pattern where the score increases steadily based on the fixed maximum value.
- The algorithm must be optimized to run in O(n) time to handle large inputs efficiently.
{{< dots >}}
## Code 💻
```cpp
vector<long long> findPrefixScore(vector<int>& nums) {
    int mx = nums[0];
    long long sum = 0;
    int n = nums.size();
    vector<long long> ans(n, 0);
    for(int i = 0; i < n; i++) {
        mx = max(mx, nums[i]);
        int scr = nums[i] + mx;
        ans[i] = i == 0? scr: ans[i - 1] + scr;
    }
    return ans;
}
```

This function computes the prefix scores of an array of integers, where the score for each element is the sum of the element and the maximum element seen so far, with the result being a cumulative sum of these scores.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Header**
	```cpp
	vector<long long> findPrefixScore(vector<int>& nums) {
	```
	This line defines the function `findPrefixScore`, which takes a vector of integers `nums` and returns a vector of long long integers containing the prefix scores.

2. **Variable Initialization**
	```cpp
	    int mx = nums[0];
	```
	Initializes `mx` to the first element of the array `nums`, representing the maximum value encountered so far.

3. **Variable Initialization**
	```cpp
	    long long sum = 0;
	```
	A variable `sum` is initialized to 0, but it's not used further in the current code.

4. **Variable Initialization**
	```cpp
	    int n = nums.size();
	```
	Stores the size of the `nums` array in the variable `n`.

5. **Array Initialization**
	```cpp
	    vector<long long> ans(n, 0);
	```
	Initializes a vector `ans` of size `n` to store the cumulative prefix scores, initially filled with zeros.

6. **Loop Setup**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Starts a loop to iterate through each element of the `nums` array.

7. **Logic**
	```cpp
	        mx = max(mx, nums[i]);
	```
	Updates the `mx` variable to be the maximum of the current `mx` and the current element of `nums[i]`.

8. **Computation**
	```cpp
	        int scr = nums[i] + mx;
	```
	Calculates the score `scr` for the current element as the sum of the element `nums[i]` and the maximum element `mx` seen so far.

9. **Condition**
	```cpp
	        ans[i] = i == 0? scr: ans[i - 1] + scr;
	```
	If it's the first element (`i == 0`), assigns `scr` to `ans[i]`. Otherwise, adds `scr` to the cumulative sum stored in `ans[i-1]`.

10. **Return**
	```cpp
	    return ans;
	```
	Returns the vector `ans` containing the cumulative prefix scores.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because we process each element of the array once and perform constant time operations for each element.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the space required for the result array `ans`, which stores the scores for all prefixes.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-the-score-of-all-prefixes-of-an-array/description/)

---
{{< youtube Xp413jTlTNk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

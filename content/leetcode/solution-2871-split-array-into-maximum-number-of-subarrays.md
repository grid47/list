
+++
authors = ["grid47"]
title = "Leetcode 2871: Split Array Into Maximum Number of Subarrays"
date = "2024-01-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2871: Split Array Into Maximum Number of Subarrays in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "xgzsBxfu8Ew"
youtube_upload_date="2023-09-30"
youtube_thumbnail="https://i.ytimg.com/vi/xgzsBxfu8Ew/maxresdefault.jpg"
comments = true
+++



---
You are given an array nums consisting of non-negative integers. Your task is to divide the array into subarrays such that the sum of the scores of the subarrays is minimized. The score of a subarray nums[l..r] is defined as nums[l] AND nums[l + 1] AND ... AND nums[r], where AND is the bitwise AND operation. Your goal is to return the maximum number of subarrays that you can split the array into while achieving the minimum possible sum of scores.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array of non-negative integers nums. You need to divide the array into subarrays while minimizing the sum of their scores.
- **Example:** `nums = [3, 0, 5, 0, 3, 5]`
- **Constraints:**
	- 1 <= nums.length <= 105
	- 0 <= nums[i] <= 106

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum number of subarrays that you can split the array into while minimizing the sum of the subarray scores.
- **Example:** `For input nums = [3, 0, 5, 0, 3, 5], the output is 3.`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the maximum number of subarrays that can be formed while achieving the minimum score for the entire array.

- Initialize the variable to track the current AND result for the subarray.
- Iterate over the array and continuously apply the AND operation until a subarray with a score of 0 is found.
- Once a subarray with score 0 is found, split the array and reset the AND result for the next subarray.
- Track the number of subarrays formed and ensure that the score sum is minimized.
{{< dots >}}
### Problem Assumptions ✅
- The array will have at least one element.
- Elements are non-negative integers.
{{< dots >}}
## Examples 🧩
- **Input:** `For input nums = [3, 0, 5, 0, 3, 5], the output is 3.`  \
  **Explanation:** We can split the array into three subarrays with scores [0, 0, 1], minimizing the sum of scores.

{{< dots >}}
## Approach 🚀
The problem requires minimizing the sum of scores of subarrays formed by dividing the original array. This can be achieved by leveraging the bitwise AND operation to split the array into the maximum number of subarrays.

### Initial Thoughts 💭
- The AND operation makes the score reduce or stay the same as we include more elements in the subarray.
- By continuously performing the AND operation and resetting when the score reaches 0, we can maximize the number of subarrays.
{{< dots >}}
### Edge Cases 🌐
- The array will always have at least one element.
- The algorithm should efficiently handle arrays up to 100,000 elements.
- An array where all elements are identical may require fewer subarrays.
- The solution must handle large arrays efficiently.
{{< dots >}}
## Code 💻
```cpp
int maxSubarrays(vector<int>& nums) {
    int res = 0, cur = 0;
    for (int n : nums) {
        cur = cur == 0 ? n : cur & n;
        res += cur == 0;
    }
    return max(1, res);
}
```

This function calculates the maximum number of subarrays where the bitwise AND of all elements in the subarray becomes 0.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int maxSubarrays(vector<int>& nums) {
	```
	Function declaration, taking a vector of integers 'nums' as input, and returning the maximum number of subarrays.

2. **Variable Initialization**
	```cpp
	    int res = 0, cur = 0;
	```
	Initialize variables: 'res' for the result and 'cur' for the current bitwise AND value.

3. **Loop Setup**
	```cpp
	    for (int n : nums) {
	```
	Iterate through each element 'n' in the input vector 'nums'.

4. **Bitwise AND Operation**
	```cpp
	        cur = cur == 0 ? n : cur & n;
	```
	If 'cur' is 0, set it to the current element 'n'. Otherwise, perform a bitwise AND operation between 'cur' and 'n'.

5. **Count Subarrays**
	```cpp
	        res += cur == 0;
	```
	If the result of the AND operation is 0, increment the 'res' counter, indicating a valid subarray.

6. **Return Result**
	```cpp
	    return max(1, res);
	```
	Return the maximum value between 1 and the result, ensuring at least 1 subarray is counted.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because we iterate through the array once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) as we use a constant amount of extra space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/split-array-into-maximum-number-of-subarrays/description/)

---
{{< youtube xgzsBxfu8Ew >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

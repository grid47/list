
+++
authors = ["grid47"]
title = "Leetcode 2348: Number of Zero-Filled Subarrays"
date = "2024-03-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2348: Number of Zero-Filled Subarrays in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "1Y_QfTQmfKg"
youtube_upload_date="2023-03-21"
youtube_thumbnail="https://i.ytimg.com/vi/1Y_QfTQmfKg/maxresdefault.jpg"
comments = true
+++



---
You are given an integer array `nums`. Your task is to determine the total number of subarrays that consist entirely of zeroes.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a single array `nums` which contains integers. You need to count the subarrays filled with zeroes.
- **Example:** `nums = [4, 0, 0, 3, 0, 0, 5]`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- -10^9 <= nums[i] <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a single integer representing the total number of subarrays filled with zeroes.
- **Example:** `6`
- **Constraints:**
	- The result should be a non-negative integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** To count the subarrays that consist entirely of zeroes.

- Iterate through the array while keeping track of the count of consecutive zeroes.
- For each group of consecutive zeroes, add the number of possible subarrays that can be formed from those zeroes.
- Return the total count.
{{< dots >}}
### Problem Assumptions ✅
- The input array will contain valid integers.
- There may be multiple subarrays of zeroes in the array.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [4, 0, 0, 3, 0, 0, 5]`  \
  **Explanation:** There are 3 occurrences of `[0]`, 2 occurrences of `[0, 0]`, and 1 occurrence of `[0, 0, 0]`. Thus, the total is 6.

- **Input:** `nums = [0, 0, 0, 5, 0, 0]`  \
  **Explanation:** There are 5 occurrences of `[0]`, 3 occurrences of `[0, 0]`, and 1 occurrence of `[0, 0, 0]`. Thus, the total is 9.

- **Input:** `nums = [1, 2, 3, 4, 5]`  \
  **Explanation:** There are no subarrays of zeroes, so the result is 0.

{{< dots >}}
## Approach 🚀
The problem is solved by iterating through the array and counting consecutive zeroes. The number of subarrays that can be formed from `k` consecutive zeroes is given by `k * (k + 1) / 2`.

### Initial Thoughts 💭
- We need to find contiguous blocks of zeroes.
- Keep a counter for consecutive zeroes, and when a non-zero element is encountered, calculate the subarrays formed by the zeroes seen so far.
{{< dots >}}
### Edge Cases 🌐
- There are no empty inputs as the array will always have at least one element.
- The approach needs to handle arrays of up to 100,000 elements efficiently.
- If all elements are non-zero, the answer should be 0.
- The solution should handle both small and large arrays efficiently.
{{< dots >}}
## Code 💻
```cpp
long long zeroFilledSubarray(vector<int>& nums) {
    long long res = 0;
    for(int i = 0, j = 0; i < nums.size(); i++) {
        if(nums[i] != 0)
        j = i +1;
        res += i + 1 - j;
    }
    return res;
}
```

This function calculates the number of subarrays filled with zeros in the given vector of integers. It uses a sliding window technique to count consecutive zeros.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	long long zeroFilledSubarray(vector<int>& nums) {
	```
	Defines the function `zeroFilledSubarray` which takes a vector of integers `nums` as input and returns a long long integer representing the number of zero-filled subarrays.

2. **Variable Initialization**
	```cpp
	    long long res = 0;
	```
	Initializes a variable `res` to store the result, which will hold the number of zero-filled subarrays.

3. **For Loop**
	```cpp
	    for(int i = 0, j = 0; i < nums.size(); i++) {
	```
	This loop iterates through the vector `nums`. The variable `i` keeps track of the current index, and `j` marks the start of the zero-filled subarray.

4. **Condition Check**
	```cpp
	        if(nums[i] != 0)
	```
	Checks if the current element `nums[i]` is non-zero. If true, it updates the position of `j` to start from the next element after the current non-zero element.

5. **Update `j`**
	```cpp
	        j = i + 1;
	```
	If the current element is non-zero, sets `j` to the next index, which resets the potential subarray of zeros.

6. **Update Result**
	```cpp
	        res += i + 1 - j;
	```
	Updates the result `res` by adding the number of consecutive zeros between indices `j` and `i`.

7. **Return Statement**
	```cpp
	    return res;
	```
	Returns the total count of zero-filled subarrays.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The solution runs in linear time as we traverse the array once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant, as we only use a few variables.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-zero-filled-subarrays/description/)

---
{{< youtube 1Y_QfTQmfKg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

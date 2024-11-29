
+++
authors = ["grid47"]
title = "Leetcode 2962: Count Subarrays Where Max Element Appears at Least K Times"
date = "2024-01-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2962: Count Subarrays Where Max Element Appears at Least K Times in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "CZ-z1ViskzE"
youtube_upload_date="2024-03-29"
youtube_thumbnail="https://i.ytimg.com/vi_webp/CZ-z1ViskzE/maxresdefault.webp"
comments = true
+++



---
Given an integer array `nums` and a positive integer `k`, count how many subarrays contain the maximum element of the array at least `k` times.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an integer array `nums` and a positive integer `k`. The goal is to find subarrays in which the maximum element appears at least `k` times.
- **Example:** `nums = [5, 7, 8, 7, 7], k = 2`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- 1 <= nums[i] <= 10^6
	- 1 <= k <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of subarrays where the maximum element of the array appears at least `k` times.
- **Example:** `8`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** To efficiently count the number of subarrays that meet the criteria where the maximum element appears at least `k` times.

- Find the maximum element in the array.
- Use two pointers to iterate through the array and track the count of the maximum element.
- For each subarray where the count of the maximum element is at least `k`, add it to the result.
{{< dots >}}
### Problem Assumptions ✅
- The input array will always have at least one element.
- The value of `k` will always be less than or equal to the length of the array.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [5, 7, 8, 7, 7], k = 2`  \
  **Explanation:** The maximum element in the array is 7. The subarrays containing 7 at least 2 times are: [5, 7, 8, 7], [5, 7, 8, 7, 7], [7, 8, 7], [7, 8, 7, 7], [8, 7, 7], [7, 7], [7, 7, 8], and [7, 7]. Thus, there are 8 such subarrays.

- **Input:** `Input: nums = [2, 4, 3, 2], k = 3`  \
  **Explanation:** There is no subarray in which the element 4 appears at least 3 times, so the output is 0.

{{< dots >}}
## Approach 🚀
We solve this problem by using a sliding window approach to track subarrays with the required condition.

### Initial Thoughts 💭
- The problem asks us to identify subarrays based on the frequency of the maximum element, making it a sliding window problem.
- We can use a two-pointer technique to keep track of subarrays and efficiently count the ones that satisfy the condition.
{{< dots >}}
### Edge Cases 🌐
- The problem constraints guarantee that the array will not be empty.
- The solution should efficiently handle inputs with the maximum array size (10^5).
- Handle cases where no subarrays meet the condition, in which case the result should be 0.
- Ensure that the solution handles large values for `nums[i]` and `k` efficiently.
{{< dots >}}
## Code 💻
```cpp
long long countSubarrays(vector<int>& A, int k) {
    int a = *max_element(A.begin(), A.end()), n = A.size(), cur = 0, i = 0;
    long long res = 0;
    for (int j = 0; j < n; ++j) {
        cur += A[j] == a;
        while (cur >= k)
            cur -= A[i++] == a;
        res += i;
    }
    return res;
}
```

This code defines the function 'countSubarrays' which calculates the number of subarrays where a specific element, the maximum element in the array, appears at least 'k' times.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	long long countSubarrays(vector<int>& A, int k) {
	```
	Defines the function 'countSubarrays' that takes an integer array 'A' and an integer 'k' as input, and returns the count of subarrays where the maximum element appears at least 'k' times.

2. **Variable Initialization**
	```cpp
	    int a = *max_element(A.begin(), A.end()), n = A.size(), cur = 0, i = 0;
	```
	Initializes variables: 'a' is the maximum element in the array, 'n' is the size of the array, 'cur' tracks the count of the maximum element in the current subarray, and 'i' is the left pointer of the sliding window.

3. **Result Initialization**
	```cpp
	    long long res = 0;
	```
	Initializes the result variable 'res' which will store the number of valid subarrays.

4. **For Loop**
	```cpp
	    for (int j = 0; j < n; ++j) {
	```
	Starts a for loop where 'j' is the right pointer of the sliding window that iterates through the array.

5. **Update Count of Max Element**
	```cpp
	        cur += A[j] == a;
	```
	Increments 'cur' if the current element at index 'j' is equal to the maximum element 'a'. This tracks how many times 'a' appears in the current subarray.

6. **While Loop**
	```cpp
	        while (cur >= k)
	```
	Checks if the count of the maximum element 'cur' in the current subarray is greater than or equal to 'k'. If so, it enters the while loop.

7. **Adjust Left Pointer**
	```cpp
	            cur -= A[i++] == a;
	```
	Decreases 'cur' if the element at index 'i' is equal to the maximum element 'a', and moves the left pointer 'i' to the right. This reduces the window size until 'cur' is less than 'k'.

8. **Update Result**
	```cpp
	        res += i;
	```
	Adds 'i' to the result 'res'. This counts all subarrays ending at index 'j' where the subarray contains at least 'k' occurrences of the maximum element.

9. **Return Result**
	```cpp
	    return res;
	```
	Returns the result 'res', which is the total number of subarrays where the maximum element appears at least 'k' times.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) where `n` is the length of the input array. This is because we are iterating through the array only once with two pointers.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) as we are using a constant amount of extra space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/description/)

---
{{< youtube CZ-z1ViskzE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

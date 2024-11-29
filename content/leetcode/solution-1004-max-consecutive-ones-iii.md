
+++
authors = ["grid47"]
title = "Leetcode 1004: Max Consecutive Ones III"
date = "2024-07-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1004: Max Consecutive Ones III in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Sliding Window","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "HsGKI02yw6M"
youtube_upload_date="2024-04-17"
youtube_thumbnail="https://i.ytimg.com/vi/HsGKI02yw6M/maxresdefault.jpg"
comments = true
+++



---
Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's to 1's.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a binary array nums of length n (1 <= n <= 10^5) and an integer k (0 <= k <= n), where nums[i] is either 0 or 1.
- **Example:** `nums = [1,0,1,0,1,1,0,1,1], k = 2`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- nums[i] is either 0 or 1.
	- 0 <= k <= nums.length

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum length of the subarray of 1's that can be obtained by flipping at most k 0's.
- **Example:** `Output: 6`
- **Constraints:**
	- The output will be an integer representing the maximum consecutive 1's after flipping at most k 0's.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the maximum number of consecutive 1's after flipping at most k 0's.

- Use a sliding window approach to track the range of indices that contains at most k 0's.
- Expand the window by including elements, and whenever the count of 0's exceeds k, shrink the window from the left side.
- Keep track of the maximum window size as you iterate through the array.
{{< dots >}}
### Problem Assumptions ✅
- The input array nums only contains 0's and 1's.
- The integer k is within the valid range (0 <= k <= nums.length).
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [1,1,0,0,1,1,1,0,1,1], k = 2`  \
  **Explanation:** By flipping two 0's to 1's, the longest subarray of consecutive 1's becomes [1,1,1,1,1,1], which has a length of 6.

- **Input:** `Input: nums = [1,0,0,1,1,0,1,0], k = 1`  \
  **Explanation:** By flipping one 0 to 1, the longest subarray of consecutive 1's is [1,1,1], which has a length of 3.

{{< dots >}}
## Approach 🚀
To solve this problem efficiently, we can use the sliding window technique to find the maximum length subarray with at most k flipped 0's.

### Initial Thoughts 💭
- This problem can be solved efficiently using the sliding window technique.
- We need to handle the case where k is 0 or the array consists entirely of 1's.
- The sliding window should expand to include 0's and shrink when the number of 0's exceeds k.
{{< dots >}}
### Edge Cases 🌐
- If the input array is empty, return 0.
- Ensure the solution handles inputs where the array size is at the maximum limit (10^5).
- If k is 0, no 0's can be flipped, so the solution should find the longest subarray of 1's in the input array.
- The solution should handle arrays with a length of up to 100,000 efficiently.
{{< dots >}}
## Code 💻
```cpp
int longestOnes(vector<int>& nums, int k) {
    int cnt[2] = {};
    int res = 0, j = 0;
    for(int i = 0; i < nums.size(); i++) {
        cnt[nums[i]]++;
        while(cnt[0] > k && j <= i) {
            cnt[nums[j]]--;
            j++;
        }
        res = max(res, (i - j + 1));
    }
    return res;
}
```

This function finds the longest subarray with at most `k` zeroes by using a sliding window approach. The window is adjusted by maintaining a count of zeros and ensuring it does not exceed `k`.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int longestOnes(vector<int>& nums, int k) {
	```
	Defines the function `longestOnes`, which takes a vector of integers `nums` and an integer `k` to determine the length of the longest subarray with at most `k` zeroes.

2. **Array Initialization**
	```cpp
	    int cnt[2] = {};
	```
	Initializes an array `cnt` to store the count of zeros and ones within the current sliding window.

3. **Variable Initialization**
	```cpp
	    int res = 0, j = 0;
	```
	Initializes the result variable `res` to store the maximum length of valid subarrays, and `j` as the left pointer of the sliding window.

4. **Sliding Window Loop**
	```cpp
	    for(int i = 0; i < nums.size(); i++) {
	```
	Starts a loop to iterate through the elements of the `nums` array using `i` as the right pointer of the sliding window.

5. **Count Ones and Zeros**
	```cpp
	        cnt[nums[i]]++;
	```
	Increments the count of zeros or ones in the `cnt` array based on the current element `nums[i]`.

6. **Adjust Window**
	```cpp
	        while(cnt[0] > k && j <= i) {
	```
	Checks if the count of zeros exceeds `k`. If so, adjusts the sliding window by incrementing the left pointer `j`.

7. **Decrease Zero Count**
	```cpp
	            cnt[nums[j]]--;
	```
	Decrements the count of the element at `nums[j]` in the `cnt` array as the left pointer `j` moves to the right.

8. **Move Left Pointer**
	```cpp
	            j++;
	```
	Increments the left pointer `j` to shrink the sliding window from the left side until the number of zeros is less than or equal to `k`.

9. **Calculate Result**
	```cpp
	        res = max(res, (i - j + 1));
	```
	Updates the result `res` with the maximum length of valid subarray found so far. The length is calculated as `i - j + 1`.

10. **Return Result**
	```cpp
	    return res;
	```
	Returns the maximum length of subarray with at most `k` zeroes.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) since we iterate through the array once with the sliding window technique.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) since we use only a constant amount of space, aside from the input array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/max-consecutive-ones-iii/description/)

---
{{< youtube HsGKI02yw6M >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

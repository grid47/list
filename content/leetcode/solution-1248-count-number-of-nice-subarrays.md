
+++
authors = ["grid47"]
title = "Leetcode 1248: Count Number of Nice Subarrays"
date = "2024-07-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1248: Count Number of Nice Subarrays in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Math","Sliding Window","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "4zNK0rhFfcA"
youtube_upload_date="2024-06-22"
youtube_thumbnail="https://i.ytimg.com/vi_webp/4zNK0rhFfcA/maxresdefault.webp"
comments = true
+++



---
You are given an array of integers nums and an integer k. A subarray is considered 'nice' if it contains exactly k odd numbers. Your task is to return the number of nice subarrays in the given array.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an array nums of integers and an integer k.
- **Example:** `nums = [1, 1, 2, 1, 1], k = 3`
- **Constraints:**
	- 1 <= nums.length <= 50000
	- 1 <= nums[i] <= 10^5
	- 1 <= k <= nums.length

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of nice subarrays that contain exactly k odd numbers.
- **Example:** `2`
- **Constraints:**
	- Return 0 if no nice subarrays exist.

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the number of subarrays with exactly k odd numbers.

- Use a sliding window technique to count the number of subarrays with at most k odd numbers.
- The result is the difference between the number of subarrays with at most k odd numbers and those with at most k-1 odd numbers.
{{< dots >}}
### Problem Assumptions ✅
- The array has at least 1 element and contains only integers.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [1, 1, 2, 1, 1], k = 3`  \
  **Explanation:** The subarrays with exactly 3 odd numbers are [1, 1, 2, 1] and [1, 2, 1, 1], so the result is 2.

{{< dots >}}
## Approach 🚀
To solve this problem efficiently, we use a sliding window approach to count the number of subarrays with exactly k odd numbers.

### Initial Thoughts 💭
- The problem can be broken down into counting subarrays with at most k odd numbers and using this to calculate the result.
- We can calculate the number of subarrays with at most k odd numbers by maintaining a window and counting the odd numbers in the window.
{{< dots >}}
### Edge Cases 🌐
- If the array is empty, return 0.
- The solution should efficiently handle arrays of size up to 50,000.
- If k is larger than the number of odd numbers in the array, return 0.
- Ensure the solution works for large inputs and edge cases such as all numbers being even or odd.
{{< dots >}}
## Code 💻
```cpp
int numberOfSubarrays(vector<int>& nums, int k) {
    return atmost(nums, k) - atmost(nums, k - 1);
}

int atmost(vector<int> &nums, int k) {
    int cnt[2] = {};
    int res = 0, j = 0;
    for(int i = 0; i < nums.size(); i++) {
        cnt[nums[i]%2]++;
        while(cnt[1] > k) {
            cnt[nums[j]%2]--;
            j++;
        }
        res += (i - j + 1);
    }
    return res;
}
```

The function `numberOfSubarrays` calculates the number of subarrays with at most `k` odd numbers by calling the helper function `atmost` twice and calculating the difference. The helper function `atmost` counts subarrays with at most `k` odd numbers using a sliding window approach.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int numberOfSubarrays(vector<int>& nums, int k) {
	```
	This function is defined to count the number of subarrays with at most `k` odd numbers. It takes a vector `nums` and an integer `k` as inputs.

2. **Return Statement**
	```cpp
	    return atmost(nums, k) - atmost(nums, k - 1);
	```
	The result is calculated by subtracting the result of calling `atmost(nums, k-1)` from `atmost(nums, k)`. This gives the number of subarrays with exactly `k` odd numbers.

3. **Helper Function Definition**
	```cpp
	int atmost(vector<int> &nums, int k) {
	```
	This helper function counts the number of subarrays with at most `k` odd numbers using a sliding window technique.

4. **Variable Initialization**
	```cpp
	    int cnt[2] = {};
	```
	The `cnt` array is initialized to track the counts of even and odd numbers in the current sliding window. `cnt[0]` tracks even numbers and `cnt[1]` tracks odd numbers.

5. **Variable Initialization**
	```cpp
	    int res = 0, j = 0;
	```
	The variable `res` is initialized to count the total number of subarrays, and `j` is the left pointer for the sliding window.

6. **Loop Through Array**
	```cpp
	    for(int i = 0; i < nums.size(); i++) {
	```
	A loop is used to iterate through the elements of `nums` using the index `i` as the right pointer of the sliding window.

7. **Update Count**
	```cpp
	        cnt[nums[i]%2]++;
	```
	The count of either even or odd numbers is updated in the `cnt` array based on the current element in `nums`. If `nums[i]` is odd, `cnt[1]` is incremented.

8. **Adjust Sliding Window**
	```cpp
	        while(cnt[1] > k) {
	```
	If the number of odd numbers in the current window exceeds `k`, the left pointer `j` is moved to the right to shrink the window until there are at most `k` odd numbers.

9. **Adjust Sliding Window**
	```cpp
	            cnt[nums[j]%2]--;
	```
	The count of the element at the left pointer `j` is decremented, and the window is adjusted by moving `j` to the right.

10. **Adjust Sliding Window**
	```cpp
	            j++;
	```
	Increment the left pointer `j` to shrink the window from the left side.

11. **Update Result**
	```cpp
	        res += (i - j + 1);
	```
	Add the number of subarrays with at most `k` odd numbers in the current window to the result. The number of such subarrays is `(i - j + 1)`.

12. **Return Statement**
	```cpp
	    return res;
	```
	Return the total number of subarrays with at most `k` odd numbers.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear, O(n), where n is the length of the array.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant, O(1), as we only use a few extra variables.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/count-number-of-nice-subarrays/description/)

---
{{< youtube 4zNK0rhFfcA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |


+++
authors = ["grid47"]
title = "Leetcode 1493: Longest Subarray of 1's After Deleting One Element"
date = "2024-06-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1493: Longest Subarray of 1's After Deleting One Element in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "PnzvwU4CFg8"
youtube_upload_date="2020-06-27"
youtube_thumbnail="https://i.ytimg.com/vi_webp/PnzvwU4CFg8/maxresdefault.webp"
comments = true
+++



---
Given a binary array nums, you should delete one element from it. After deleting one element, return the size of the longest non-empty subarray containing only 1's in the resulting array. If no such subarray exists, return 0.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a binary array nums where each element is either 0 or 1.
- **Example:** `nums = [1, 0, 1, 1, 0]`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- nums[i] is either 0 or 1.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the size of the longest contiguous subarray containing only 1's after deleting one element. If no such subarray exists, return 0.
- **Example:** `Output: 4`
- **Constraints:**
	- The array will contain at least one element.

{{< dots >}}
### Core Logic 🔍
**Goal:** To maximize the length of contiguous 1's after deleting one element, we will use a sliding window approach to count the maximum subarray of 1's with at most one zero.

- Initialize two pointers, `i` and `j`, for the sliding window.
- Count the zeros in the window and ensure there is at most one zero.
- If there is more than one zero, shrink the window from the left.
- Track the maximum length of the window that contains at most one zero.
{{< dots >}}
### Problem Assumptions ✅
- The array nums contains only 0's and 1's.
- There will be at least one element in the array.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [1,0,1,1,0]`  \
  **Explanation:** After deleting the element at index 1, the array becomes [1, 1, 1, 0]. The longest subarray with only 1's is of length 4.

- **Input:** `nums = [0,1,1,0,1,1,1,0]`  \
  **Explanation:** After deleting the element at index 3, the array becomes [0, 1, 1, 1, 1, 1, 0]. The longest subarray of 1's is of length 5.

- **Input:** `nums = [1, 1, 1]`  \
  **Explanation:** After deleting one element, the remaining array has two 1's, so the longest subarray is of length 2.

{{< dots >}}
## Approach 🚀
The sliding window approach allows us to efficiently find the longest subarray of 1's with one element deleted. By maintaining a window with at most one 0, we can compute the result in linear time.

### Initial Thoughts 💭
- We need to handle cases where the array has no 0's or the array contains only one element.
- By keeping track of the zeros within the window, we can adjust the window size to maximize the length of 1's.
{{< dots >}}
### Edge Cases 🌐
- An empty array is not a valid input as per the constraints.
- For large arrays, the solution must handle up to 10^5 elements efficiently.
- If the array contains only one element, after deleting it, the result will be 0.
- The solution must handle all edge cases efficiently, especially when there is a single zero or when the array contains only 1's.
{{< dots >}}
## Code 💻
```cpp

int longestSubarray(vector<int>& nums) {
    
    int ans = 0;
    
    int n = nums.size();
    
    int k = 1;
    
    int j = 0;
    for(int i = 0; i < n; i++) {
        if(nums[i] == 0) k--;
        
        while(k < 0) {
            if(nums[j] == 0)
                k++;
            j++;
        }
        ans = max(ans, i - j);
    }
    
    /*
    i - j mean one element will be cut from [j, i] closed interval
    what k does is, make that element a zero.
    */

    return ans;
}
```

The `longestSubarray` function finds the length of the longest subarray with at most one zero. It uses a sliding window approach, adjusting the window's size dynamically based on the value of `k`.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int longestSubarray(vector<int>& nums) {
	```
	The function `longestSubarray` takes a vector of integers `nums` as input and returns the length of the longest subarray containing at most one zero.

2. **Variable Initialization**
	```cpp
	    int ans = 0;
	```
	Initialize `ans` to 0. This variable will store the length of the longest subarray with at most one zero.

3. **Variable Initialization**
	```cpp
	    int n = nums.size();
	```
	Get the size of the input vector `nums` and store it in `n`.

4. **Variable Initialization**
	```cpp
	    int k = 1;
	```
	Initialize `k` to 1, representing the maximum allowed number of zeros in the subarray.

5. **Variable Initialization**
	```cpp
	    int j = 0;
	```
	Initialize `j` to 0, which will be the left boundary of the sliding window.

6. **Loop**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Start a loop from `i = 0` to `i = n - 1` to iterate through the elements of the vector `nums`.

7. **Zero Detection**
	```cpp
	        if(nums[i] == 0) k--;
	```
	If the current element `nums[i]` is zero, decrement `k` to track the number of zeros in the current window.

8. **Inner Loop**
	```cpp
	        while(k < 0) {
	```
	If `k` is negative (indicating more than one zero in the window), enter a while loop to shrink the window.

9. **Adjust Left Boundary**
	```cpp
	            if(nums[j] == 0)
	```
	If `nums[j]` is zero, increment `k` because we are removing a zero from the window.

10. **Adjust Left Boundary**
	```cpp
	                k++;
	```
	Increment `k` because a zero is being removed from the left side of the window.

11. **Adjust Left Boundary**
	```cpp
	            j++;
	```
	Move the left boundary `j` to the right, effectively shrinking the window.

12. **Max Length Update**
	```cpp
	        ans = max(ans, i - j);
	```
	Update `ans` with the maximum length of the current valid subarray, which is the difference between the right boundary `i` and the left boundary `j`.

13. **Return Statement**
	```cpp
	    return ans;
	```
	Return the value of `ans`, which represents the length of the longest subarray with at most one zero.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear, O(n), since we only need a single pass through the array with a sliding window approach.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant, O(1), since we only need a few variables for tracking the window and count of zeros.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/description/)

---
{{< youtube PnzvwU4CFg8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

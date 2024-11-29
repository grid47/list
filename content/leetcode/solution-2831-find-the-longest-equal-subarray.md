
+++
authors = ["grid47"]
title = "Leetcode 2831: Find the Longest Equal Subarray"
date = "2024-01-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2831: Find the Longest Equal Subarray in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Binary Search","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "UFCF01O7Yxk"
youtube_upload_date="2023-08-20"
youtube_thumbnail="https://i.ytimg.com/vi/UFCF01O7Yxk/maxresdefault.jpg"
comments = true
+++



---
You are given a list of integers nums and an integer k. Your task is to find the length of the longest subarray where all the elements are equal after you delete at most k elements.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array nums and an integer k.
- **Example:** `nums = [1, 3, 2, 3, 1, 3], k = 3`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- 1 <= nums[i] <= nums.length
	- 0 <= k <= nums.length

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the length of the longest subarray where all the elements are equal after deleting at most k elements.
- **Example:** `3`
- **Constraints:**
	- The output should be a single integer representing the length of the longest possible subarray.

{{< dots >}}
### Core Logic 🔍
**Goal:** To calculate the longest possible subarray of equal elements after deleting at most k elements.

- Group the indices of each element in nums.
- For each element, use a sliding window to count how many elements can be deleted to form a subarray of equal elements.
- Calculate the maximum length of such subarrays.
{{< dots >}}
### Problem Assumptions ✅
- The elements of the nums array are between 1 and the length of the nums array.
- You are allowed to delete at most k elements.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [1, 3, 2, 3, 1, 3], k = 3`  \
  **Explanation:** After deleting two elements at indices 2 and 4, the array becomes [1, 3, 3, 3], and the longest subarray of equal elements is [3, 3, 3] with a length of 3.

- **Input:** `nums = [1, 1, 2, 2, 1, 1], k = 2`  \
  **Explanation:** After deleting two elements at indices 2 and 3, the array becomes [1, 1, 1, 1], which is the longest subarray of equal elements with a length of 4.

{{< dots >}}
## Approach 🚀
The problem can be solved using a sliding window approach, where we track the number of deletions needed to make a subarray of equal elements.

### Initial Thoughts 💭
- We need to find subarrays where all the elements are the same after deleting at most k elements.
- We can group the indices of each element and check which subarray can be made equal with minimal deletions.
- Sliding window technique is ideal for problems involving subarrays where we need to calculate the longest valid segment.
{{< dots >}}
### Edge Cases 🌐
- The array may be empty, in which case the result should be 0.
- For large arrays, efficient handling of the sliding window and grouping is required.
- If k is 0, no deletions are allowed, and the subarray must already be equal.
- Ensure that the time complexity remains efficient, especially for large inputs.
{{< dots >}}
## Code 💻
```cpp
int longestEqualSubarray(vector<int>& nums, int k) {
    
    int n = nums.size();
    vector<vector<int>> grid(n + 1);

    int ans = 0;
    for(int i = 0; i < n; i++) {
        grid[nums[i]].push_back(i);
    }
            
    for(int e = 1; e <= n; e++) {
        
        if(grid[e].size() == 0) continue;
        
        int left = 0, right = 1, rm = 0;
        
        while(left < grid[e].size() && right < grid[e].size()) {
            rm += (grid[e][right] - grid[e][right - 1] - 1);
            if (rm <= k) {
                ans = max(ans, 1 + (right - left));
                right++;
            } else {
                right++;
                left++;
                if(left < grid[e].size())
                rm -= (grid[e][left] - grid[e][left - 1] - 1);
            }
        }
    }
    
    return max(ans, 1);
}
```

This function aims to find the longest subarray of equal elements where the difference between the indices of the elements exceeds a threshold `k`. It uses a sliding window technique with a frequency map for efficient lookup.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int longestEqualSubarray(vector<int>& nums, int k) {
	```
	Define the function `longestEqualSubarray`, which takes a vector `nums` and an integer `k` as input.

2. **Variable Initialization**
	```cpp
	    int n = nums.size();
	```
	Initialize `n` to the size of the `nums` array.

3. **Grid Setup**
	```cpp
	    vector<vector<int>> grid(n + 1);
	```
	Create a 2D grid (vector of vectors) to store the indices of each element in `nums`.

4. **Answer Initialization**
	```cpp
	    int ans = 0;
	```
	Initialize the variable `ans` to store the maximum length of the subarray found.

5. **Iterating Over nums**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Iterate over each element `i` in `nums`.

6. **Populating Grid**
	```cpp
	        grid[nums[i]].push_back(i);
	```
	For each element in `nums`, push its index into the corresponding grid slot based on the element's value.

7. **Iterating Over Grid**
	```cpp
	    for(int e = 1; e <= n; e++) {
	```
	Iterate through the grid from index `1` to `n`.

8. **Skipping Empty Grids**
	```cpp
	        if(grid[e].size() == 0) continue;
	```
	If the grid at index `e` is empty, skip to the next iteration.

9. **Sliding Window Initialization**
	```cpp
	        int left = 0, right = 1, rm = 0;
	```
	Initialize the sliding window pointers `left`, `right`, and the variable `rm` to keep track of the remaining space within the window.

10. **Sliding Window Loop**
	```cpp
	        while(left < grid[e].size() && right < grid[e].size()) {
	```
	Start a `while` loop to manage the sliding window, adjusting the `left` and `right` pointers.

11. **Updating Remaining Space**
	```cpp
	            rm += (grid[e][right] - grid[e][right - 1] - 1);
	```
	Update the remaining space `rm` by calculating the gaps between consecutive indices in the grid.

12. **Checking Window Validity**
	```cpp
	            if (rm <= k) {
	```
	If the remaining space `rm` is within the allowed threshold `k`, update the answer.

13. **Updating Answer**
	```cpp
	                ans = max(ans, 1 + (right - left));
	```
	Update the answer by taking the maximum of the current `ans` and the length of the window (right - left).

14. **Incrementing Right Pointer**
	```cpp
	                right++;
	```
	Increment the `right` pointer to expand the window.

15. **Else Condition**
	```cpp
	            } else {
	```
	If the `rm` exceeds `k`, reduce the window from the left.

16. **Incrementing Right Pointer Again**
	```cpp
	                right++;
	```
	Increment the `right` pointer to expand the window.

17. **Incrementing Left Pointer**
	```cpp
	                left++;
	```
	Increment the `left` pointer to shrink the window.

18. **Updating Remaining Space After Shrinking**
	```cpp
	                if(left < grid[e].size())
	                rm -= (grid[e][left] - grid[e][left - 1] - 1);
	```
	After adjusting the `left` pointer, update the remaining space `rm` by recalculating the gap.

19. **Returning Result**
	```cpp
	    return max(ans, 1);
	```
	Return the maximum of `ans` and `1` as the result, ensuring at least a length of 1.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear, as we iterate through the elements and use a sliding window approach.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is linear due to the storage of index groups for each element.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-the-longest-equal-subarray/description/)

---
{{< youtube UFCF01O7Yxk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

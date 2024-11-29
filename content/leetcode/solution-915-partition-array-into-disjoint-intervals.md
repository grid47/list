
+++
authors = ["grid47"]
title = "Leetcode 915: Partition Array into Disjoint Intervals"
date = "2024-08-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 915: Partition Array into Disjoint Intervals in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++



---
Given an integer array `nums`, partition it into two contiguous subarrays, `left` and `right`, such that all elements in `left` are less than or equal to all elements in `right`. The size of `left` should be as small as possible, and both subarrays must be non-empty. Your task is to return the length of the `left` subarray after performing such a partition.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a list of integers `nums`.
- **Example:** `Input: nums = [2, 5, 3, 7, 6]`
- **Constraints:**
	- 2 <= nums.length <= 10^5
	- 0 <= nums[i] <= 10^6
	- There is at least one valid answer for the given input.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the length of the `left` subarray after partitioning the array as described.
- **Example:** `Output: 3`
- **Constraints:**
	- The output should be an integer representing the length of the `left` subarray.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the smallest size of `left` where all elements in `left` are less than or equal to all elements in `right`.

- Keep track of the maximum value encountered in the `left` subarray as you iterate through the array.
- If an element in the array is less than the maximum value of the `left`, update the partition point to include the previous elements in `left`.
- Once the partitioning is done, the size of `left` gives the required result.
{{< dots >}}
### Problem Assumptions ✅
- The array will always contain a valid partitioning where the condition is satisfied.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [2, 5, 3, 7, 6]`  \
  **Explanation:** For this array, the optimal partition is `left = [2, 5, 3]` and `right = [7, 6]`. The length of `left` is 3, so the answer is 3.

{{< dots >}}
## Approach 🚀
We need to find the smallest `left` subarray such that all elements in `left` are less than or equal to all elements in `right`. This can be done by tracking the maximum value in `left` and ensuring that the next element in the array is greater than or equal to this maximum value.

### Initial Thoughts 💭
- We can iterate through the array while keeping track of the maximum element in the left subarray.
- Once we find an element smaller than the maximum of the left subarray, we need to extend the left subarray to include that element.
- This approach involves linear traversal through the array, making it efficient enough for the input size constraints.
{{< dots >}}
### Edge Cases 🌐
- The input array is guaranteed to have at least two elements, so no need to handle empty arrays.
- For large inputs, the solution must be efficient with a time complexity of O(n).
- If all elements are the same, the entire array could be in the `left` subarray.
- The constraints ensure that there is always a valid partition, so no need to handle invalid cases.
{{< dots >}}
## Code 💻
```cpp
int partitionDisjoint(vector<int>& nums) {
    int n = nums.size();
    int max_i, cur, ans = 1;
    max_i = cur = nums[0];
    
    for(int i = 1; i < n; i++) {
        if(nums[i] < max_i) {
            max_i = cur;
            ans = i + 1;
        } else if (nums[i] > cur)
            cur = nums[i];
    }
    return ans;
}
```

This function partitions the given array such that the left part contains only elements that are less than or equal to the right part.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int partitionDisjoint(vector<int>& nums) {
	```
	This is the declaration of the function 'partitionDisjoint', which takes a vector of integers as input.

2. **Variable Initialization**
	```cpp
	    int n = nums.size();
	```
	Initializes the variable 'n' to store the size of the 'nums' array.

3. **Variable Initialization**
	```cpp
	    int max_i, cur, ans = 1;
	```
	Declares three variables: 'max_i' for tracking the maximum value, 'cur' for the current element, and 'ans' for the partition index, initialized to 1.

4. **Variable Assignment**
	```cpp
	    max_i = cur = nums[0];
	```
	Assigns the first element of the array to both 'max_i' and 'cur' as the initial values.

5. **Loop**
	```cpp
	    for(int i = 1; i < n; i++) {
	```
	Starts a loop iterating through the array from the second element.

6. **Condition Check**
	```cpp
	        if(nums[i] < max_i) {
	```
	Checks if the current element is smaller than the previously tracked maximum value.

7. **Variable Update**
	```cpp
	            max_i = cur;
	```
	Updates the 'max_i' to be the current element 'cur' if a smaller element is found.

8. **Variable Update**
	```cpp
	            ans = i + 1;
	```
	Updates the partition index 'ans' to the current position 'i + 1'.

9. **Condition Check**
	```cpp
	        } else if (nums[i] > cur)
	```
	If the current element is larger than the current element 'cur', we update 'cur'.

10. **Variable Update**
	```cpp
	            cur = nums[i];
	```
	Updates the 'cur' variable to hold the current element if it's greater than the previous 'cur'.

11. **Return Statement**
	```cpp
	    return ans;
	```
	Returns the partition index 'ans'.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n) where n is the length of the array
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear because we traverse the array once while keeping track of the partition.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant since we only need a few extra variables to track the current maximum and partition point.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/partition-array-into-disjoint-intervals/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

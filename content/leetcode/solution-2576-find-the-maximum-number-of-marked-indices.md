
+++
authors = ["grid47"]
title = "Leetcode 2576: Find the Maximum Number of Marked Indices"
date = "2024-02-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2576: Find the Maximum Number of Marked Indices in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Binary Search","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "NlsyXR7GOJE"
youtube_upload_date="2023-02-26"
youtube_thumbnail="https://i.ytimg.com/vi_webp/NlsyXR7GOJE/maxresdefault.webp"
comments = true
+++



---
You are given a 0-indexed integer array nums. Initially, all indices are unmarked. You are allowed to perform the following operation any number of times: Pick two different unmarked indices i and j such that 2 * nums[i] <= nums[j], then mark both indices i and j. Return the maximum possible number of marked indices after performing this operation multiple times.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array nums of size n.
- **Example:** `For example, nums = [4, 6, 2, 5].`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- 1 <= nums[i] <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is an integer, the maximum possible number of marked indices.
- **Example:** `For nums = [10, 2, 3, 6], the output is 4.`
- **Constraints:**
	- The output is an integer representing the maximum number of marked indices.

{{< dots >}}
### Core Logic 🔍
**Goal:** To find the maximum number of indices that can be marked by performing the operation any number of times.

- 1. Sort the array nums.
- 2. Use a greedy approach to find valid pairs: For each unmarked index i, try to find a valid index j such that 2 * nums[i] <= nums[j].
- 3. Mark both indices i and j if the condition is met and repeat the process.
{{< dots >}}
### Problem Assumptions ✅
- The array nums is non-empty and contains only positive integers.
{{< dots >}}
## Examples 🧩
- **Input:** `For nums = [10, 2, 3, 6], the output is 4.`  \
  **Explanation:** First, pair index 3 with 0 (6 and 10), then pair index 1 with 2 (2 and 3), and all indices are marked.

{{< dots >}}
## Approach 🚀
The approach leverages sorting and a greedy matching strategy to find the maximum number of valid index pairs.

### Initial Thoughts 💭
- A greedy approach will be useful to maximize the number of valid pairs.
- We need to first sort the array and then iterate over it to check for valid pairs where 2 * nums[i] <= nums[j].
{{< dots >}}
### Edge Cases 🌐
- The array nums will always have at least one element.
- For large inputs (nums.length up to 10^5), ensure the algorithm runs efficiently with time complexity of O(n log n).
- If all elements in nums are the same, there may be no valid pairs to mark.
- Handle edge cases where no valid pair can be formed.
{{< dots >}}
## Code 💻
```cpp

bool can(int k, vector<int> &nums) {
    int ridx = k - 1;
    int lidx = nums.size() - k;
    
    for(int i = 0; i < k; i++)
        if(nums[i] * 2 > nums[nums.size() - k + i]) return false;
    
    return true;
    
}

int maxNumOfMarkedIndices(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int l = 1, r = n/2, ans = 0;
    while(l <= r) {
        
        int mid = l + (r - l + 1) / 2;
        if(can(mid, nums)) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;

    }
    return ans * 2;
}
```

This code identifies the maximum number of marked indices based on constraints and binary search logic.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool can(int k, vector<int> &nums) {
	```
	Defines a helper function to validate whether a specific number of indices can be marked.

2. **Variable Declaration**
	```cpp
	    int ridx = k - 1;
	```
	Declares the right index variable to track the midpoint of the array.

3. **Variable Declaration**
	```cpp
	    int lidx = nums.size() - k;
	```
	Declares the left index variable based on the array size.

4. **Loop Start**
	```cpp
	    for(int i = 0; i < k; i++)
	```
	Starts a loop to check if the conditions are satisfied for the current subset of indices.

5. **Condition Check**
	```cpp
	        if(nums[i] * 2 > nums[nums.size() - k + i]) return false;
	```
	Validates the condition for marking indices; returns false if it fails.

6. **Return Statement**
	```cpp
	    return true;
	```
	Returns true if all conditions for marking indices are satisfied.

7. **Main Function Definition**
	```cpp
	int maxNumOfMarkedIndices(vector<int>& nums) {
	```
	Defines the main function to find the maximum number of marked indices.

8. **Variable Declaration**
	```cpp
	    int n = nums.size();
	```
	Declares the size of the input array `nums`.

9. **Sorting**
	```cpp
	    sort(nums.begin(), nums.end());
	```
	Sorts the array to facilitate binary search logic.

10. **Binary Search Initialization**
	```cpp
	    int l = 1, r = n/2, ans = 0;
	```
	Initializes variables for binary search.

11. **Binary Search Loop**
	```cpp
	    while(l <= r) {
	```
	Starts the binary search loop to find the maximum valid subset.

12. **Midpoint Calculation**
	```cpp
	        int mid = l + (r - l + 1) / 2;
	```
	Calculates the midpoint of the current binary search range.

13. **Condition Check**
	```cpp
	        if(can(mid, nums)) {
	```
	Checks if the current midpoint is valid using the helper function.

14. **Update Answer**
	```cpp
	            ans = mid;
	```
	Updates the answer if the condition is satisfied.

15. **Adjust Range**
	```cpp
	            l = mid + 1;
	```
	Narrows the binary search range by increasing the lower bound.

16. **Adjust Range**
	```cpp
	        } else r = mid - 1;
	```
	Narrows the binary search range by decreasing the upper bound.

17. **Final Calculation**
	```cpp
	    return ans * 2;
	```
	Calculates the final result by doubling the valid subset size.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The time complexity is dominated by the sorting step, which is O(n log n).

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the space used for the sorted array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-the-maximum-number-of-marked-indices/description/)

---
{{< youtube NlsyXR7GOJE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

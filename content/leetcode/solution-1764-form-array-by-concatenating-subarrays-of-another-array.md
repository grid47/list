
+++
authors = ["grid47"]
title = "Leetcode 1764: Form Array by Concatenating Subarrays of Another Array"
date = "2024-05-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1764: Form Array by Concatenating Subarrays of Another Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Greedy","String Matching"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "GGdu6E9o7D4"
youtube_upload_date="2021-02-23"
youtube_thumbnail="https://i.ytimg.com/vi/GGdu6E9o7D4/maxresdefault.jpg"
comments = true
+++



---
Given an array of subarrays `groups` and a single array `nums`, your task is to determine whether it is possible to extract each subarray from `groups` as a contiguous segment from `nums`. The subarrays must appear in the same order as in `groups`, and they should be disjoint, meaning no element from `nums` can belong to more than one subarray. Return true if this is possible, and false otherwise.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a 2D array `groups` where each subarray is a sequence of integers. Additionally, you are given an integer array `nums`.
- **Example:** `Input: groups = [[2, 3], [1, 2, 3]], nums = [2, 3, 1, 2, 3, 4]`
- **Constraints:**
	- 1 <= groups.length <= 1000
	- 1 <= groups[i].length <= 1000
	- 1 <= sum(groups[i].length) <= 1000
	- 1 <= nums.length <= 1000
	- nums and group elements are between -10^7 and 10^7

{{< dots >}}
### Output Specifications 📤
- **Output:** Return true if you can find each subarray from `groups` as disjoint subarrays within `nums` while maintaining the order, otherwise return false.
- **Example:** `Output: true`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to check whether each subarray from `groups` can be found in `nums` in the given order and that the subarrays are disjoint.

- 1. Start iterating through `nums` while keeping track of the current subarray being matched from `groups`.
- 2. For each subarray, check if it appears in `nums` as a contiguous block.
- 3. Once a match is found, ensure no elements from `nums` are reused for the next subarray by continuing the search beyond the matched segment.
- 4. Return true if all subarrays are found, otherwise return false.
{{< dots >}}
### Problem Assumptions ✅
- The arrays `nums` and `groups` consist of integers only.
- Subarrays in `groups` must appear in the same order in `nums`.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: groups = [[2, 3], [1, 2, 3]], nums = [2, 3, 1, 2, 3, 4]`  \
  **Explanation:** The first subarray [2, 3] can be found at the start of `nums`. The second subarray [1, 2, 3] follows immediately after the first. Thus, the answer is true.

- **Input:** `Input: groups = [[10, -2], [1, 2, 3, 4]], nums = [1, 2, 3, 4, 10, -2]`  \
  **Explanation:** The subarrays are not in the same order in `nums`. The second subarray [1, 2, 3, 4] appears before [10, -2], so the answer is false.

- **Input:** `Input: groups = [[3, 4], [5, 6]], nums = [3, 5, 4, 6]`  \
  **Explanation:** The subarrays are disjoint, but they do not appear in the same order. Therefore, the answer is false.

{{< dots >}}
## Approach 🚀
The solution will iterate through `nums` and try to match each subarray from `groups` in sequence. We will attempt to find each subarray as a contiguous block, ensuring that no element is shared between subarrays.

### Initial Thoughts 💭
- The subarrays must be found in order, and no overlap should occur between the subarrays in `nums`.
- An efficient approach is to use a greedy matching strategy to find each subarray and continue searching from the end of the last match.
{{< dots >}}
### Edge Cases 🌐
- If `nums` is empty or if the total sum of lengths of subarrays in `groups` exceeds the length of `nums`, return false.
- The solution must handle cases where the length of `nums` and the total number of elements in `groups` are close to their upper limits efficiently.
- If any group is empty or a group doesn't have a matching subsequence in `nums`, return false.
- The solution should be optimized to handle up to 1000 subarrays in `groups` and 1000 elements in `nums`.
{{< dots >}}
## Code 💻
```cpp
bool canChoose(vector<vector<int>>& group, vector<int>& nums) {
    
    int numsIdx = 0, grpIdx = 0;
    
    while(numsIdx < nums.size() && grpIdx < group.size()) {
        

        int matchCnt = 0;
        
        while(numsIdx + matchCnt < nums.size() &&
             matchCnt < group[grpIdx].size() &&
             nums[numsIdx + matchCnt] == group[grpIdx][matchCnt])
                matchCnt++;
        
        if(matchCnt == group[grpIdx].size()) {
            grpIdx++;
            numsIdx += matchCnt;
        } else numsIdx++;

    }
            
    return grpIdx == group.size();
    
}
```

This function checks whether the groups of integers in `group` can be sequentially matched in the array `nums`. It uses indices and counts to track matches and ensures all groups are processed in order.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	bool canChoose(vector<vector<int>>& group, vector<int>& nums) {
	```
	Declares the function for determining if groups can be matched in the given array `nums`.

2. **Variable Initialization**
	```cpp
	    int numsIdx = 0, grpIdx = 0;
	```
	Initializes indices for tracking the current position in `nums` and `group`.

3. **While Loop**
	```cpp
	    while(numsIdx < nums.size() && grpIdx < group.size()) {
	```
	Iterates over `nums` and `group` as long as indices are within bounds.

4. **Variable Initialization**
	```cpp
	        int matchCnt = 0;
	```
	Initializes a counter to track the number of matching elements for the current group.

5. **While Loop**
	```cpp
	        while(numsIdx + matchCnt < nums.size() &&
	```
	Checks for matching elements between the current group and the array `nums`.

6. **Condition Check**
	```cpp
	             matchCnt < group[grpIdx].size() &&
	```
	Ensures the match count does not exceed the size of the current group.

7. **Condition Check**
	```cpp
	             nums[numsIdx + matchCnt] == group[grpIdx][matchCnt])
	```
	Checks if the current elements in `nums` and `group` match.

8. **Increment**
	```cpp
	                matchCnt++;
	```
	Increments the match count when elements match.

9. **Block End**
	```cpp
	        
	```
	Empty line for separating blocks for readability.

10. **Condition Check**
	```cpp
	        if(matchCnt == group[grpIdx].size()) {
	```
	Checks if all elements in the current group have been matched.

11. **Index Update**
	```cpp
	            grpIdx++;
	```
	Moves to the next group after successfully matching the current group.

12. **Index Update**
	```cpp
	            numsIdx += matchCnt;
	```
	Skips past the matched elements in `nums`.

13. **Else Block**
	```cpp
	        } else numsIdx++;
	```
	Moves to the next element in `nums` if the current group does not match.

14. **Return Statement**
	```cpp
	    return grpIdx == group.size();
	```
	Returns `true` if all groups were matched successfully; otherwise, `false`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^3)

In the worst case, each subarray needs to be matched against a portion of `nums`, leading to a time complexity of O(n^3) when considering the sum of subarray lengths.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant since we are only using a few integer variables to track indices and matches.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/form-array-by-concatenating-subarrays-of-another-array/description/)

---
{{< youtube GGdu6E9o7D4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

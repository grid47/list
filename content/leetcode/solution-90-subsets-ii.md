
+++
authors = ["grid47"]
title = "Leetcode 90: Subsets II"
date = "2024-10-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 90: Subsets II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Backtracking","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/90.webp"
youtube = "Vn2v6ajA7U0"
youtube_upload_date="2021-12-14"
youtube_thumbnail="https://i.ytimg.com/vi/Vn2v6ajA7U0/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/90.webp" 
    alt="A glowing, branching set of subsets gently forming in a calm, peaceful pattern."
    caption="Solution to LeetCode 90: Subsets II Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given an integer array nums that may contain duplicates, return all possible subsets (the power set) of the array. The solution set should not contain duplicate subsets. The subsets should be returned in any order.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is an integer array nums, which may contain duplicate values.
- **Example:** `Input: nums = [3, 3, 1]`
- **Constraints:**
	- 1 <= nums.length <= 10
	- -10 <= nums[i] <= 10

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a list of lists, where each inner list represents a unique subset of the input array.
- **Example:** `Output: [[], [1], [1, 3], [1, 3, 3], [3], [3, 3]]`
- **Constraints:**
	- The subsets must not contain duplicates.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to generate all possible subsets of the input array while avoiding duplicates. This can be done by iterating through the array, considering each element either as part of a subset or not, and ensuring that subsets with duplicate elements are not included.

- Sort the input array to ensure duplicates are adjacent.
- Use a backtracking approach to generate subsets, ensuring that if an element is included, the next occurrence of the same element is only included if it was included previously in the current subset.
{{< dots >}}
### Problem Assumptions ✅
- The input array is not empty.
- The input array length is at most 10, so it is feasible to generate all subsets.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [1, 2, 2]`  \
  **Explanation:** For input [1, 2, 2], the possible unique subsets are: [], [1], [1, 2], [1, 2, 2], [2], and [2, 2]. The subset [2] appears twice, so only one of them is included in the result.

- **Input:** `Input: nums = [0]`  \
  **Explanation:** For input [0], the only subsets are the empty set [] and the set containing the element itself [0].

{{< dots >}}
## Approach 🚀
We can solve this problem using backtracking to generate all subsets. Sorting the array first helps ensure that duplicate subsets are avoided by making sure the same elements are adjacent.

### Initial Thoughts 💭
- The backtracking approach can help generate subsets by either including or excluding an element.
- The sorted array ensures that duplicate elements are adjacent and can be handled easily during the backtracking process.
- Handling duplicates requires careful management during the backtracking to avoid generating the same subset multiple times.
{{< dots >}}
### Edge Cases 🌐
- An empty input array will result in a single subset: the empty set []
- For large inputs (n = 10), the solution must handle 2^n subsets efficiently.
- If the array contains duplicate values, the solution must ensure only unique subsets are returned.
- The constraints (1 <= nums.length <= 10) allow for generating all subsets directly, as 2^10 subsets is a manageable number.
{{< dots >}}
## Code 💻
```cpp
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res = {{}};
    int startIndex = 0, endIndex = 0;
    for (int i = 0; i < nums.size(); i++) {
        int n = res.size();
        for (int j = 0; j < n; j++) {
            if (i == 0 || nums[i] != nums[i - 1] || j >= startIndex) {
                vector<int> temp = res[j];
                temp.push_back(nums[i]);
                res.push_back(temp);
            }
        }
        startIndex = i + 1;
    }
    return res;
}
```

This code generates all unique subsets of a given array of integers, including duplicates.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
	```
	Declares a function `subsetsWithDup` that takes a vector of integers `nums` as input and returns a vector of vectors representing all unique subsets.

2. **Sorting**
	```cpp
	    sort(nums.begin(), nums.end());
	```
	Sorts the input array `nums` in ascending order to handle duplicates efficiently.

3. **Array Initialization**
	```cpp
	    vector<vector<int>> res = {{}};
	```
	Initializes a vector `res` to store the subsets. The initial empty subset `{}` is added.

4. **Variable Initialization**
	```cpp
	    int startIndex = 0, endIndex = 0;
	```
	Initializes `startIndex` and `endIndex` to keep track of the range of indices to consider for adding elements to subsets.

5. **Loop Iteration**
	```cpp
	    for (int i = 0; i < nums.size(); i++) {
	```
	Iterates through each element `nums[i]` in the sorted array.

6. **Size Calculation**
	```cpp
	        int n = res.size();
	```
	Stores the current size of the `res` vector.

7. **Nested Loop Iteration**
	```cpp
	        for (int j = 0; j < n; j++) {
	```
	Iterates through the existing subsets in `res`.

8. **Conditional, Array Manipulation**
	```cpp
	            if (i == 0 || nums[i] != nums[i - 1] || j >= startIndex) {
	```
	Checks if it's the first iteration, or if the current element is different from the previous one, or if we've reached the `startIndex` for the current element. This ensures we avoid duplicates.

9. **Array Manipulation**
	```cpp
	                vector<int> temp = res[j];
	```
	Creates a copy `temp` of the current subset `res[j]`.

10. **Array Manipulation**
	```cpp
	                temp.push_back(nums[i]);
	```
	Adds the current element `nums[i]` to the `temp` subset.

11. **Array Manipulation**
	```cpp
	                res.push_back(temp);
	```
	Adds the new subset `temp` to the `res` vector.

12. **Index Update**
	```cpp
	        startIndex = i + 1;
	```
	Updates `startIndex` to the next index for the next iteration, skipping duplicate elements.

13. **Return**
	```cpp
	    return res;
	```
	Returns the final `res` vector containing all unique subsets.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(2^n), where n is the number of elements in the input array, since the solution involves generating all possible subsets.
- **Average Case:** O(2^n)
- **Worst Case:** O(2^n), as we must generate and check each subset once.

The time complexity is exponential, as we are generating 2^n subsets.

### Space Complexity 💾
- **Best Case:** O(1), if no subsets are generated.
- **Worst Case:** O(2^n), since we store all subsets.

The space complexity depends on the number of subsets stored.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/subsets-ii/description/)

---
{{< youtube Vn2v6ajA7U0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

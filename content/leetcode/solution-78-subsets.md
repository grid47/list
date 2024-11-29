
+++
authors = ["grid47"]
title = "Leetcode 78: Subsets"
date = "2024-10-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 78: Subsets in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Backtracking","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/78.webp"
youtube = "UP3dOYJa05s"
youtube_upload_date="2024-04-24"
youtube_thumbnail="https://i.ytimg.com/vi/UP3dOYJa05s/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/78.webp" 
    alt="Multiple floating subsets gently coming together, forming a whole."
    caption="Solution to LeetCode 78: Subsets Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given an integer array `nums` containing unique elements. Find all possible subsets (the power set) of the array `nums`. The solution set should not contain duplicate subsets, and the result can be returned in any order.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array `nums` with unique elements.
- **Example:** `nums = [1, 2, 3]`
- **Constraints:**
	- 1 <= nums.length <= 10
	- -10 <= nums[i] <= 10
	- All elements of nums are unique.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return all possible subsets (the power set) of the array `nums`, ensuring no duplicate subsets are included. The order of the subsets does not matter.
- **Example:** `[[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]]`
- **Constraints:**
	- The output should be a list of subsets where each subset is a list of integers.

{{< dots >}}
### Core Logic 🔍
**Goal:** Generate all possible subsets (the power set) of the given array `nums` using a backtracking approach.

- Start with an empty subset and recursively explore both options: including the current element or excluding it.
- For each element in the array, make a choice whether to add it to the current subset or skip it.
- Each time an element is included or excluded, recursively call the function to build all possible subsets.
{{< dots >}}
### Problem Assumptions ✅
- The array `nums` contains unique integers.
- The solution set should include all possible subsets without duplicates.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [1, 2, 3]`  \
  **Explanation:** The output includes all subsets, ranging from the empty subset to the full set itself.

- **Input:** `nums = [4]`  \
  **Explanation:** There are two subsets: the empty subset `[]` and the subset `[4]`.

{{< dots >}}
## Approach 🚀
The approach involves using backtracking to explore both possibilities for each element (include or exclude it) and build all possible subsets.

### Initial Thoughts 💭
- We can generate all subsets by recursively exploring both inclusion and exclusion of elements in the array.
- Backtracking works well for generating subsets, as it allows for efficiently exploring all combinations by making decisions at each step.
{{< dots >}}
### Edge Cases 🌐
- If `nums` is an empty array, the only subset is the empty subset `[]`.
- For larger arrays, ensure the solution handles the exponential number of subsets efficiently.
- If `nums` contains just one element, the output will be two subsets: the empty subset `[]` and the subset with the single element.
- The function should efficiently handle arrays up to the maximum size of 10 elements.
{{< dots >}}
## Code 💻
```cpp
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result = {{}};
    for (int num : nums) {
        int n = result.size();
        for (int i = 0; i < n; ++i) {
            result.push_back(result[i]);
            result.back().push_back(num);
        }
    }
    return result;
}
```

This code generates all possible subsets of a given set of numbers using an iterative approach.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<vector<int>> subsets(vector<int>& nums) {
	```
	Declares a function `subsets` that takes a vector of integers `nums` as input and returns a vector of vectors representing all possible subsets.

2. **Variable Initialization**
	```cpp
	    vector<vector<int>> result = {{}};
	```
	Initializes a vector `result` to store the generated subsets, starting with an empty set.

3. **Loop Iteration**
	```cpp
	    for (int num : nums) {
	```
	Iterates over each number `num` in the input vector `nums`.

4. **Variable Initialization**
	```cpp
	        int n = result.size();
	```
	Stores the current size of the `result` vector in `n`.

5. **Loop Iteration**
	```cpp
	        for (int i = 0; i < n; ++i) {
	```
	Iterates over the existing subsets in the `result` vector.

6. **Vector Operation**
	```cpp
	            result.push_back(result[i]);
	```
	Creates a new subset by copying the current subset `result[i]` and adds it to the `result` vector.

7. **Vector Operation**
	```cpp
	            result.back().push_back(num);
	```
	Adds the current number `num` to the newly created subset.

8. **Return**
	```cpp
	    return result;
	```
	Returns the `result` vector containing all the generated subsets.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(2^n)
- **Average Case:** O(2^n)
- **Worst Case:** O(2^n)

The time complexity is O(2^n) because there are 2^n subsets of a set with n elements.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the recursive call stack and storage for the current subset being built.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/subsets/description/)

---
{{< youtube UP3dOYJa05s >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

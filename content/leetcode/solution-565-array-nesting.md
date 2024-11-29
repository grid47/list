
+++
authors = ["grid47"]
title = "Leetcode 565: Array Nesting"
date = "2024-09-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 565: Array Nesting in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Depth-First Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/565.webp"
youtube = "rl_hXXzvTiM"
youtube_upload_date="2021-09-01"
youtube_thumbnail="https://i.ytimg.com/vi/rl_hXXzvTiM/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/565.webp" 
    alt="An array where elements are nested, each valid nesting glowing softly as it is processed."
    caption="Solution to LeetCode 565: Array Nesting Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given an array nums, a permutation of numbers from [0, n-1], and for each index k, you need to build a set s[k] by repeatedly selecting elements based on the rule nums[k] -> nums[nums[k]] -> nums[nums[nums[k]]], stopping when a duplicate is found. Return the longest length of any such set s[k].
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array nums containing a permutation of numbers from [0, n-1].
- **Example:** `Input: nums = [3, 1, 4, 0, 2]`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- 0 <= nums[i] < nums.length
	- All values of nums are unique.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a single integer representing the longest length of any set s[k].
- **Example:** `Output: 3`
- **Constraints:**
	- The result should be an integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the longest set s[k] for any index k in the array nums.

- Initialize a variable to store the maximum size of the set found.
- Iterate over the array, for each index k, follow the rule of building the set until a duplicate is found.
- Mark the visited elements as processed (e.g., by setting nums[k] to -1).
- Update the maximum set size during the iteration.
{{< dots >}}
### Problem Assumptions ✅
- The input array is non-empty and contains unique values.
- The size of the array is within the given constraints.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [3, 1, 4, 0, 2]`  \
  **Explanation:** Starting from nums[0] = 3, we build the set {3, 0}. The length of the longest set is 3.

- **Input:** `Input: nums = [0, 1, 2]`  \
  **Explanation:** Each element points to itself, so the longest set has a length of 1.

{{< dots >}}
## Approach 🚀
The problem can be solved by iterating through the array and, for each element, following the chain of elements until a repeat is found. The challenge is to avoid revisiting elements unnecessarily.

### Initial Thoughts 💭
- The process of following the chain of elements from any starting point is deterministic and involves tracking visited elements to avoid infinite loops.
- The solution will involve visiting each element once and marking it as visited to ensure no duplicates are counted in the chain.
{{< dots >}}
### Edge Cases 🌐
- The input array will never be empty as per the problem constraints.
- The solution should efficiently handle input sizes up to 100,000 elements.
- If all elements point to themselves (like in a sorted array), the solution should return 1.
- The solution should handle large inputs efficiently and avoid unnecessary recomputations.
{{< dots >}}
## Code 💻
```cpp
int arrayNesting(vector<int>& nums) {
    int mxsize = 0;
    for(int i = 0; i < nums.size(); i++) {
        int size = 0;
        for(int k = i; nums[k] >= 0; size++) {
            int ak = nums[k];
            nums[k] = -1;
            k = ak;
        }
        mxsize = max(size, mxsize);
    }
    return mxsize;
}
```

The function `arrayNesting` calculates the largest set of numbers that form a cycle in the array. It uses a greedy approach and modifies the input array to mark visited elements.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int arrayNesting(vector<int>& nums) {
	```
	Defines the function `arrayNesting` that takes a vector of integers `nums` and returns the size of the largest cycle (set of elements that point to each other).

2. **Variable Initialization**
	```cpp
	    int mxsize = 0;
	```
	Initializes the variable `mxsize` to store the size of the largest set found. This will be updated as the function iterates through the array.

3. **Outer Loop - Iterate Through Array**
	```cpp
	    for(int i = 0; i < nums.size(); i++) {
	```
	Starts an outer loop to iterate through each element in the array `nums`.

4. **Size Initialization**
	```cpp
	        int size = 0;
	```
	Initializes the variable `size` to 0 for each new cycle. This variable will store the number of elements in the current cycle.

5. **Inner Loop - Cycle Traversal**
	```cpp
	        for(int k = i; nums[k] >= 0; size++) {
	```
	Starts an inner loop to traverse the cycle starting from index `i`. It continues as long as the element at index `k` has not been visited (i.e., it's non-negative).

6. **Cycle Element Access**
	```cpp
	            int ak = nums[k];
	```
	Stores the current value of the element at index `k` in `ak`. This is used to track the next element in the cycle.

7. **Mark Element as Visited**
	```cpp
	            nums[k] = -1;
	```
	Marks the element at index `k` as visited by setting it to `-1`. This prevents revisiting the same element in future iterations.

8. **Move to Next Element in Cycle**
	```cpp
	            k = ak;
	```
	Sets `k` to the value stored in `ak`, which represents the index of the next element in the cycle.

9. **Update Maximum Size**
	```cpp
	        mxsize = max(size, mxsize);
	```
	Updates `mxsize` to the larger value between the current cycle size (`size`) and the largest cycle size found so far (`mxsize`).

10. **Return Maximum Size**
	```cpp
	    return mxsize;
	```
	Returns the largest cycle size found during the traversal of the array.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear in the size of the input array.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the need to store the visited elements and the intermediate sets.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/array-nesting/description/)

---
{{< youtube rl_hXXzvTiM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

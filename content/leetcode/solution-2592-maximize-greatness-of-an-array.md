
+++
authors = ["grid47"]
title = "Leetcode 2592: Maximize Greatness of an Array"
date = "2024-02-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2592: Maximize Greatness of an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "p1njSkWtg2U"
youtube_upload_date="2023-03-18"
youtube_thumbnail="https://i.ytimg.com/vi_webp/p1njSkWtg2U/maxresdefault.webp"
comments = true
+++



---
You are given an integer array `nums`. You can permute (rearrange) the elements of `nums` into a new array `perm`. Define the greatness of `nums` as the number of indices `0 <= i < nums.length` where `perm[i] > nums[i]`. Your task is to return the maximum possible greatness you can achieve after permuting `nums`.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a single integer array `nums` representing the array of integers.
- **Example:** `For example, `nums = [3, 1, 4, 2]`.`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- 0 <= nums[i] <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a single integer representing the maximum possible greatness you can achieve after permuting `nums`.
- **Example:** `For `nums = [3, 1, 4, 2]`, the output is `3`.`
- **Constraints:**
	- The output is an integer value representing the maximum greatness.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to permute the array `nums` to maximize the number of indices where `perm[i] > nums[i]`.

- 1. Sort the array `nums` to create a sorted version.
- 2. Use a greedy approach to find the maximum number of indices where `perm[i] > nums[i]` by pairing elements from the sorted array with the original array.
{{< dots >}}
### Problem Assumptions ✅
- The input array will always contain at least one integer, and no element will exceed 10^9 in value.
{{< dots >}}
## Examples 🧩
- **Input:** `For `nums = [3, 1, 4, 2]``  \
  **Explanation:** By rearranging `nums` into `perm = [4, 2, 3, 1]`, the greatness is 3 because at indices `0, 1, 2`, `perm[i] > nums[i]`. This is the optimal rearrangement.

{{< dots >}}
## Approach 🚀
The approach involves sorting the array `nums` and then using a greedy approach to match the elements from the sorted array with the original array to maximize the number of times `perm[i] > nums[i]`.

### Initial Thoughts 💭
- To maximize greatness, we want to pair smaller values in `nums` with larger values from a sorted version of `nums`.
- Sorting the array and then using a greedy approach to match elements can help achieve the maximum greatness.
{{< dots >}}
### Edge Cases 🌐
- The input array is guaranteed to have at least one element, so there will be no empty inputs.
- The solution must handle large inputs efficiently, with the array size up to 10^5.
- If all elements in `nums` are the same, the result will be zero because no element can be greater than another.
- The input constraints ensure that the number of elements will be manageable within the time limits.
{{< dots >}}
## Code 💻
```cpp
int maximizeGreatness(vector<int>& nums) {
    // 1 1 1 2 3 3 5
    sort(nums.begin(), nums.end());
    int n = nums.size();
    map<int, int> pos;
    pos[-1] = -1;
    for(int i = 0; i < n; i++) {
        auto it = upper_bound(nums.begin() + pos[i - 1] + 1, nums.end(), nums[i]);
        if(it == nums.end()) break;
        int idx = it - nums.begin();
        pos[i] = idx;
        if(idx == n - 1) break;
    }
    return pos.size() - 1;
}
```

This function calculates the maximum possible greatness of a sequence by rearranging its elements. The algorithm sorts the input array and uses a map to track the positions of elements that can be added to the result, ensuring that each new element is greater than the previous.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int maximizeGreatness(vector<int>& nums) {
	```
	Defines the `maximizeGreatness` function that takes a vector of integers, `nums`, as an argument.

2. **Sort Array**
	```cpp
	    sort(nums.begin(), nums.end());
	```
	Sorts the input array `nums` in non-decreasing order.

3. **Size Calculation**
	```cpp
	    int n = nums.size();
	```
	Calculates the size of the sorted array and stores it in variable `n`.

4. **Map Initialization**
	```cpp
	    map<int, int> pos;
	```
	Declares a map `pos` to track the positions of elements that are being considered for the result.

5. **Initial Value Assignment**
	```cpp
	    pos[-1] = -1;
	```
	Initializes the map `pos` with a value for `-1` key set to `-1`, which serves as the starting point for comparisons.

6. **Loop**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Starts a loop that iterates over each element in the sorted array `nums`.

7. **Upper Bound Search**
	```cpp
	        auto it = upper_bound(nums.begin() + pos[i - 1] + 1, nums.end(), nums[i]);
	```
	Uses the `upper_bound` function to find the first position in the array where the current element `nums[i]` can be inserted while maintaining sorted order.

8. **Break Condition**
	```cpp
	        if(it == nums.end()) break;
	```
	Breaks the loop if no valid position is found for the current element.

9. **Index Calculation**
	```cpp
	        int idx = it - nums.begin();
	```
	Calculates the index `idx` of the found position where the current element can be inserted.

10. **Map Update**
	```cpp
	        pos[i] = idx;
	```
	Updates the `pos` map with the index `idx` for the current element at position `i`.

11. **End Condition Check**
	```cpp
	        if(idx == n - 1) break;
	```
	Ends the loop early if the last element of the array is reached.

12. **Return Statement**
	```cpp
	    return pos.size() - 1;
	```
	Returns the size of the `pos` map minus one, which represents the maximum greatness of the sequence.

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

The space complexity is O(n) due to the additional space used for sorting the array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximize-greatness-of-an-array/description/)

---
{{< youtube p1njSkWtg2U >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

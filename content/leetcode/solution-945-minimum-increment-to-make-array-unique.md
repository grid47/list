
+++
authors = ["grid47"]
title = "Leetcode 945: Minimum Increment to Make Array Unique"
date = "2024-08-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 945: Minimum Increment to Make Array Unique in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "XPPs2Wj2YSk"
youtube_upload_date="2024-06-14"
youtube_thumbnail="https://i.ytimg.com/vi/XPPs2Wj2YSk/maxresdefault.jpg"
comments = true
+++



---
You are given an integer array `nums`. In one move, you can select any index `i` where `0 <= i < nums.length` and increment `nums[i]` by 1. Your task is to find the minimum number of moves required to make all the values in `nums` unique.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a single integer array `nums` containing n elements.
- **Example:** `Input: nums = [1, 2, 2]`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- 0 <= nums[i] <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of moves required to make all elements of `nums` unique.
- **Example:** `Output: 1`
- **Constraints:**
	- The input is always valid, and the answer fits in a 32-bit integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to calculate the minimum moves to make all elements unique by incrementing them.

- 1. Sort the input array `nums` to group identical elements together.
- 2. Iterate over the sorted array and check if each number can be incremented to a unique value.
- 3. Track the current maximum value and ensure each number is greater than the previous number to make the array unique.
- 4. Accumulate the number of moves needed to achieve the uniqueness.
{{< dots >}}
### Problem Assumptions ✅
- All elements in the array are non-negative integers.
- The array may contain duplicate elements initially.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [1, 2, 2]`  \
  **Explanation:** In this case, the array contains two 2's. By incrementing the second 2 to 3, we make all the elements unique. This requires one move.

- **Input:** `Input: nums = [3, 2, 1, 2, 1, 7]`  \
  **Explanation:** Here, the array contains repeated 2's and 1's. To make all the values unique, we increment the second 2 to 3, the second 1 to 4, and so on. A total of 6 moves are needed to make the values unique.

{{< dots >}}
## Approach 🚀
The approach involves sorting the array and iterating through it to ensure each element is unique by incrementing the elements when necessary.

### Initial Thoughts 💭
- The array may contain duplicates, and the goal is to eliminate those duplicates by incrementing the values.
- Sorting the array helps to deal with duplicates efficiently by ensuring the smallest possible number is always encountered first.
{{< dots >}}
### Edge Cases 🌐
- If the array has only one element, no moves are required.
- For large inputs, ensure the solution runs efficiently by utilizing sorting and a single pass through the array.
- If all elements in the array are already unique, no moves are required.
- Ensure the solution can handle up to 100,000 elements efficiently.
{{< dots >}}
## Code 💻
```cpp
int minIncrementForUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    
    int res = 0, n = nums.size(), need = 0;
    for(int i = 0; i < n; i++) {
        res += max(need - nums[i], 0);
        need = max(nums[i], need) + 1;
    }
    return res;
}
```

This function calculates the minimum number of increments required to make all elements in the `nums` vector unique. It sorts the vector and iterates through it to ensure that no two elements are the same, incrementing where necessary.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int minIncrementForUnique(vector<int>& nums) {
	```
	This line defines the function `minIncrementForUnique`, which takes a vector of integers `nums` and returns the minimum number of increments needed to make the numbers unique.

2. **Sorting**
	```cpp
	    sort(nums.begin(), nums.end());
	```
	Sort the vector `nums` in ascending order to make it easier to ensure uniqueness by comparing consecutive elements.

3. **Variable Initialization**
	```cpp
	    int res = 0, n = nums.size(), need = 0;
	```
	Initialize `res` to 0 (this will store the result), `n` to the size of the vector `nums`, and `need` to 0 (this will track the minimum value that the next element must be greater than or equal to).

4. **Loop Initialization**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Start a loop to iterate through each element in the sorted vector `nums`.

5. **Increment Calculation**
	```cpp
	        res += max(need - nums[i], 0);
	```
	For each element, calculate how much it needs to be incremented (if necessary) to make it unique. If the current element is less than `need`, add the difference to `res`.

6. **Update `need`**
	```cpp
	        need = max(nums[i], need) + 1;
	```
	Update the value of `need` to ensure the next element is strictly greater than the current element, if needed.

7. **Return Statement**
	```cpp
	    return res;
	```
	Return the total number of increments required to make all elements in `nums` unique.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The time complexity is dominated by the sorting operation, which takes O(n log n) time.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage of the input array, with an additional O(1) space used for counting the increments.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-increment-to-make-array-unique/description/)

---
{{< youtube XPPs2Wj2YSk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

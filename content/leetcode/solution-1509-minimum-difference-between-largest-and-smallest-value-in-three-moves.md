
+++
authors = ["grid47"]
title = "Leetcode 1509: Minimum Difference Between Largest and Smallest Value in Three Moves"
date = "2024-06-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1509: Minimum Difference Between Largest and Smallest Value in Three Moves in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "SG7VnKzhfjo"
youtube_upload_date="2021-06-09"
youtube_thumbnail="https://i.ytimg.com/vi/SG7VnKzhfjo/maxresdefault.jpg"
comments = true
+++



---
You are given an integer array. In one move, you can change any element of the array to any value. Perform at most three moves to minimize the difference between the largest and smallest values of the array.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array nums where each element can range from -10^9 to 10^9.
- **Example:** `nums = [4, 3, 5, 2]`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- -10^9 <= nums[i] <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum difference between the maximum and minimum values in the array after performing at most three moves.
- **Example:** `0`
- **Constraints:**
	- Return the result as an integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to minimize the difference between the maximum and minimum values of the array after performing at most 3 moves.

- Step 1: Sort the array to easily access the smallest and largest values.
- Step 2: Try changing the largest and smallest values to reduce the difference.
- Step 3: Return the minimum difference after performing at most three moves.
{{< dots >}}
### Problem Assumptions ✅
- You are allowed to change any element to any other value.
- You can perform at most three moves.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [4, 3, 5, 2]`  \
  **Explanation:** After performing three moves, we can make all elements equal to 3, resulting in a minimum difference of 0.

- **Input:** `nums = [1, 6, 8, 10, 15]`  \
  **Explanation:** After performing three moves, the difference between the largest and smallest values is minimized to 1.

{{< dots >}}
## Approach 🚀
We need to minimize the difference between the largest and smallest values of the array by performing at most three moves.

### Initial Thoughts 💭
- Sorting the array helps in quickly accessing the smallest and largest values.
- Consider all possible ways to change the three largest and smallest values and check the resulting differences.
{{< dots >}}
### Edge Cases 🌐
- The array should not be empty as per the problem constraints.
- Ensure the solution works efficiently even with large arrays (up to 100,000 elements).
- Handle arrays with a small number of elements (e.g., 2 or 3 elements).
- Ensure that no element exceeds the allowed range of values.
{{< dots >}}
## Code 💻
```cpp
int minDifference(vector<int>& nums) {
    int n = nums.size();
    /* change one element to any other value in one move */
    /* get min diff between max and min value after performing atmost 3 moves */
    if(n < 5) return 0;
    sort(nums.begin(), nums.end());
    
    return min({nums[n - 1] - nums[3], nums[n - 2] - nums[2], nums[n - 3] - nums[1], nums[n - 4] - nums[0]});
}
```

This code defines the `minDifference` function that minimizes the difference between the maximum and minimum values in the array `nums` after performing at most three modifications. It calculates this by sorting the array and evaluating the differences between specific elements.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int minDifference(vector<int>& nums) {
	```
	Defines the `minDifference` function, which takes a vector `nums` as input and aims to minimize the difference between the maximum and minimum values after at most three changes.

2. **Variable Initialization**
	```cpp
	    int n = nums.size();
	```
	Initializes a variable `n` to store the size of the vector `nums`. This is used to determine the number of elements in the array.

3. **Condition Check**
	```cpp
	    if(n < 5) return 0;
	```
	Checks if the size of the array is less than 5. If it is, the function returns 0, as no moves are necessary in this case.

4. **Sorting**
	```cpp
	    sort(nums.begin(), nums.end());
	```
	Sorts the vector `nums` in ascending order to facilitate easier calculations of the possible differences between elements after moves.

5. **Min Difference Calculation**
	```cpp
	    return min({nums[n - 1] - nums[3], nums[n - 2] - nums[2], nums[n - 3] - nums[1], nums[n - 4] - nums[0]});
	```
	Calculates the minimum difference between the maximum and minimum values in the sorted array after performing at most three changes by evaluating specific differences.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The time complexity is O(n log n) due to the sorting step.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) as we store the array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/description/)

---
{{< youtube SG7VnKzhfjo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

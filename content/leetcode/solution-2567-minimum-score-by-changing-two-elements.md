
+++
authors = ["grid47"]
title = "Leetcode 2567: Minimum Score by Changing Two Elements"
date = "2024-02-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2567: Minimum Score by Changing Two Elements in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "MPtncVNtKW0"
youtube_upload_date="2023-02-18"
youtube_thumbnail="https://i.ytimg.com/vi/MPtncVNtKW0/maxresdefault.jpg"
comments = true
+++



---
You are given an integer array nums. Your goal is to minimize the score of the array after changing exactly two elements. The score is the sum of the low and high scores, where the low score is the minimum absolute difference between any two integers and the high score is the maximum absolute difference between any two integers.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array of integers.
- **Example:** `For example, nums = [2, 5, 10, 12, 8].`
- **Constraints:**
	- 3 <= nums.length <= 10^5
	- 1 <= nums[i] <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum score after changing exactly two elements of the nums array.
- **Example:** `For example, if nums = [2, 5, 10, 12, 8], the output is 4.`
- **Constraints:**
	- The score is calculated as the sum of the low and high scores.

{{< dots >}}
### Core Logic 🔍
**Goal:** To minimize the score, you need to find the best pair of numbers to modify such that both the low and high scores are minimized.

- 1. Sort the nums array.
- 2. Consider changing the two largest or the two smallest elements in the array.
- 3. Calculate the new low and high scores after each modification.
- 4. Return the minimum sum of the low and high scores.
{{< dots >}}
### Problem Assumptions ✅
- The input nums will always have at least three elements.
- The values of nums are within the specified range.
{{< dots >}}
## Examples 🧩
- **Input:** `For nums = [2, 5, 10, 12, 8], the optimal change is to replace 2 and 5 with 7, resulting in an array of [7, 7, 10, 12, 8].`  \
  **Explanation:** This modification results in a low score of 0 and a high score of 4, giving a total score of 4.

- **Input:** `For nums = [4, 3, 8], changing the first two elements to 5 results in an array of [5, 5, 8].`  \
  **Explanation:** This change leads to a low score of 0 and a high score of 3, giving a total score of 0.

{{< dots >}}
## Approach 🚀
The approach involves finding the best modification to minimize the score by considering changes to the two smallest and two largest elements in the array.

### Initial Thoughts 💭
- The solution requires minimizing both the high and low scores by changing only two elements.
- A sorted array will help in efficiently finding the elements that will minimize the low and high scores.
{{< dots >}}
### Edge Cases 🌐
- There are no empty inputs since nums will always have at least 3 elements.
- The solution needs to efficiently handle arrays with up to 100,000 elements.
- If all elements of nums are the same, the score will always be 0.
- The input will always contain at least three integers, and each integer will be between 1 and 10^9.
{{< dots >}}
## Code 💻
```cpp
int minimizeSum(vector<int>& nums) {
    int n= nums.size();
    sort(nums.begin(), nums.end());
    int a = nums[n - 3] - nums[0];
    int b = nums[n - 1] - nums[2];
    int c = nums[n - 2] - nums[1];
    return min({a, b, c});
    
}
```

This code implements the logic to minimize the sum of the differences between the selected elements from the sorted array.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	int minimizeSum(vector<int>& nums) {
	```
	Declaring the function `minimizeSum` which takes a vector `nums` as an argument and returns an integer. This function calculates the minimal sum difference between selected elements of the sorted array.

2. **Array Size Calculation**
	```cpp
	    int n= nums.size();
	```
	Here, we store the size of the input array `nums` into variable `n`.

3. **Sorting**
	```cpp
	    sort(nums.begin(), nums.end());
	```
	This step sorts the input array `nums` in ascending order, ensuring that we can calculate the differences between the smallest and largest elements.

4. **Arithmetic Operation**
	```cpp
	    int a = nums[n - 3] - nums[0];
	```
	Calculates the difference between the third-to-last element and the first element of the sorted array, storing the result in variable `a`.

5. **Arithmetic Operation**
	```cpp
	    int b = nums[n - 1] - nums[2];
	```
	Calculates the difference between the last element and the third element of the sorted array, storing the result in variable `b`.

6. **Arithmetic Operation**
	```cpp
	    int c = nums[n - 2] - nums[1];
	```
	Calculates the difference between the second-to-last element and the second element of the sorted array, storing the result in variable `c`.

7. **Return Statement**
	```cpp
	    return min({a, b, c});
	```
	Returns the smallest value among `a`, `b`, and `c`, which represents the minimized sum of differences.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n), where n is the length of the nums array.
- **Average Case:** O(n log n), due to the sorting step.
- **Worst Case:** O(n log n), where n is the length of the nums array.

The sorting step dominates the time complexity.

### Space Complexity 💾
- **Best Case:** O(n), where n is the length of the nums array.
- **Worst Case:** O(n), where n is the length of the nums array.

The space complexity is determined by the storage required for the nums array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-score-by-changing-two-elements/description/)

---
{{< youtube MPtncVNtKW0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

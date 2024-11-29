
+++
authors = ["grid47"]
title = "Leetcode 740: Delete and Earn"
date = "2024-08-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 740: Delete and Earn in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/740.webp"
youtube = "MnbTKT4-KLc"
youtube_upload_date="2023-07-05"
youtube_thumbnail="https://i.ytimg.com/vi/MnbTKT4-KLc/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/740.webp" 
    alt="A series of numbers where the optimal strategy to delete and earn is highlighted, glowing softly as the calculation is made"
    caption="Solution to LeetCode 740: Delete and Earn Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given an integer array nums. You want to maximize the number of points you can earn by performing the following operation any number of times: Pick any nums[i] and delete it to earn nums[i] points. Afterwards, you must delete every element equal to nums[i] - 1 and every element equal to nums[i] + 1.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is an integer array representing the numbers from which you will be selecting elements to delete and earn points.
- **Example:** `nums = [5, 6, 4]`
- **Constraints:**
	- 1 <= nums.length <= 2 * 10^4
	- 1 <= nums[i] <= 10^4

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum number of points you can earn by performing the operation some number of times.
- **Example:** `For nums = [5, 6, 4], the output should be 8.`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Maximize the total points earned from deleting elements and ensuring no adjacent elements (nums[i] - 1 or nums[i] + 1) are left.

- Count the occurrences of each number in the array.
- Create a dynamic programming array where dp[i] stores the maximum points obtainable by considering numbers from 1 to i.
- For each number, either choose to delete it and earn points or skip it and carry forward the previous maximum.
- Return the final value from the dynamic programming array.
{{< dots >}}
### Problem Assumptions ✅
- The input array nums will always contain at least one element.
{{< dots >}}
## Examples 🧩
- **Input:** `For nums = [5, 6, 4], the output is 8.`  \
  **Explanation:** By deleting the number 6 and 4, we maximize our points by choosing the best elements to remove.

{{< dots >}}
## Approach 🚀
A dynamic programming approach to maximize the total points by efficiently handling adjacent numbers.

### Initial Thoughts 💭
- This problem can be reduced to a dynamic programming problem where the state depends on whether we take the current element or skip it.
- We can optimize our solution by keeping track of maximum points for each number up to the largest value in the array.
{{< dots >}}
### Edge Cases 🌐
- The input will always contain at least one element, so no empty array cases will exist.
- For large inputs (up to 20,000 elements), the algorithm should efficiently handle the array within the time limits.
- If the array contains only one unique number, the algorithm should return the total points earned by deleting all occurrences of that number.
- The solution must efficiently handle inputs up to the largest constraint.
{{< dots >}}
## Code 💻
```cpp
int deleteAndEarn(vector<int>& nums) {
    int n = 10001;
    vector<int> val(n + 1, 0);
    vector<int> dp (n + 1, 0);
    
    for(int num : nums)
      val[num] += num;
    
    dp[0] = 0;
    dp[1] = val[0];
    for(int i = 1; i < n; i++)
    dp[i + 1] = max(dp[i], dp[i - 1] + val[i]);
    
    return dp[n];
}
```

This code solves the 'Delete and Earn' problem using dynamic programming. The problem asks to delete a number from an array and earn points equal to that number. If you delete a number, you cannot delete adjacent numbers.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int deleteAndEarn(vector<int>& nums) {
	```
	Defines the function that solves the problem. It takes an array of integers as input.

2. **Variable Initialization**
	```cpp
	    int n = 10001;
	```
	Initializes a variable `n` to store the size of the `val` and `dp` vectors, based on the maximum possible value in `nums`.

3. **Vector Initialization**
	```cpp
	    vector<int> val(n + 1, 0);
	```
	Creates a vector `val` to store the total points earned for each number.

4. **Vector Initialization**
	```cpp
	    vector<int> dp (n + 1, 0);
	```
	Creates a vector `dp` to store the maximum points that can be earned up to each number.

5. **Loop: Populating `val` vector**
	```cpp
	    for(int num : nums)
	```
	Iterates over each number in `nums` and updates the `val` vector.

6. **Update Operation**
	```cpp
	      val[num] += num;
	```
	Updates the `val` vector by adding the current number to its corresponding index.

7. **Base Case Setup**
	```cpp
	    dp[0] = 0;
	```
	Sets the base case for `dp[0]`, which is 0, representing that no points are earned when no numbers are considered.

8. **Base Case Setup**
	```cpp
	    dp[1] = val[0];
	```
	Sets the base case for `dp[1]` to be the value of `val[0]`, representing that the first number's point value is considered.

9. **Dynamic Programming Iteration**
	```cpp
	    for(int i = 1; i < n; i++)
	```
	Starts the dynamic programming loop to calculate the maximum points that can be earned up to each number.

10. **Dynamic Programming Transition**
	```cpp
	    dp[i + 1] = max(dp[i], dp[i - 1] + val[i]);
	```
	For each number `i`, calculates the maximum points by either taking the points up to `i` or including the points from `i` and skipping `i - 1`.

11. **Return Statement**
	```cpp
	    return dp[n];
	```
	Returns the maximum points that can be earned by considering all numbers.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the number of elements in the array.
- **Average Case:** O(n), as the algorithm only processes each element once.
- **Worst Case:** O(n), as each element is processed only once in a linear scan.

The time complexity is O(n), as we perform a constant amount of work for each element in the array.

### Space Complexity 💾
- **Best Case:** O(n), as we may need space for both the dynamic programming array and frequency counts.
- **Worst Case:** O(n), due to the space used by the dynamic programming array and frequency count array.

The space complexity is O(n) due to the space needed for the dynamic programming and frequency count arrays.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/delete-and-earn/description/)

---
{{< youtube MnbTKT4-KLc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |


+++
authors = ["grid47"]
title = "Leetcode 624: Maximum Distance in Arrays"
date = "2024-09-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 624: Maximum Distance in Arrays in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/624.webp"
youtube = "J0yYlj_oVTI"
youtube_upload_date="2024-08-16"
youtube_thumbnail="https://i.ytimg.com/vi/J0yYlj_oVTI/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/624.webp" 
    alt="Two arrays with the maximum distance between values highlighted, glowing as the distance is found."
    caption="Solution to LeetCode 624: Maximum Distance in Arrays Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given m sorted arrays. Your task is to pick two integers, each from a different array, and calculate the maximum distance between them, where the distance is defined as the absolute difference of the two numbers.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given m sorted arrays, each with an integer value.
- **Example:** `arrays = [[3,6,9], [1,4,7], [8,10,15]]`
- **Constraints:**
	- m == arrays.length
	- 2 <= m <= 10^5
	- 1 <= arrays[i].length <= 500
	- -10^4 <= arrays[i][j] <= 10^4
	- arrays[i] is sorted in ascending order.
	- There will be at most 10^5 integers in all the arrays.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum distance that can be achieved by selecting one integer from each of two different arrays.
- **Example:** `14`
- **Constraints:**
	- Return a single integer representing the maximum distance.

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the maximum distance by comparing the largest and smallest elements across arrays.

- Initialize variables to track the minimum and maximum values across the arrays.
- For each array, calculate the potential maximum distance using the largest value from the current array and the smallest value from the previous array, as well as vice versa.
- Update the result with the maximum distance found.
{{< dots >}}
### Problem Assumptions ✅
- The input arrays are correctly sorted in ascending order.
- Arrays may vary in size, and elements can be negative or positive.
{{< dots >}}
## Examples 🧩
- **Input:** `arrays = [[3,6,9], [1,4,7], [8,10,15]]`  \
  **Explanation:** In this case, the maximum distance is obtained by selecting the smallest value from the second array (1) and the largest value from the third array (15), resulting in a distance of 14.

{{< dots >}}
## Approach 🚀
The approach involves tracking the minimum and maximum values across arrays and calculating the potential distances for each pair of arrays.

### Initial Thoughts 💭
- We need an efficient way to calculate the maximum distance between two different arrays.
- By keeping track of the smallest and largest values across the arrays, we can calculate the maximum distance in linear time.
{{< dots >}}
### Edge Cases 🌐
- The problem guarantees that there will always be at least two arrays, so empty inputs do not need to be handled.
- Ensure the solution works efficiently even for the maximum constraint of 10^5 arrays.
- Handle arrays containing negative and positive numbers.
- The solution must handle arrays of different sizes and values, including edge cases like arrays with only one element.
{{< dots >}}
## Code 💻
```cpp
int maxDistance(vector<vector<int>>& arrays) {
    int res = 0, mn = 10000, mx = -10000;
    for (auto& a : arrays) {
        res = max(res, max(a.back()-mn, mx-a.front()));
        mn = min(mn, a.front()), mx = max(mx, a.back());
    }
    return res;        
}
```

This code defines a function `maxDistance` that calculates the maximum distance between the first and last elements of different arrays within a 2D vector. It keeps track of the minimum and maximum values encountered as it iterates through each sub-array to compute the maximum distance efficiently.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int maxDistance(vector<vector<int>>& arrays) {
	```
	This line declares the function `maxDistance`, which takes a reference to a 2D vector `arrays` and returns an integer representing the maximum distance between the first and last elements of the arrays.

2. **Variable Initialization**
	```cpp
	    int res = 0, mn = 10000, mx = -10000;
	```
	Three integer variables are initialized: `res` to store the result, `mn` to track the minimum value encountered, and `mx` to track the maximum value encountered.

3. **Loop Through Arrays**
	```cpp
	    for (auto& a : arrays) {
	```
	A `for` loop iterates through each sub-array `a` in the 2D vector `arrays`.

4. **Calculate Maximum Distance for Each Sub-array**
	```cpp
	        res = max(res, max(a.back()-mn, mx-a.front()));
	```
	For each sub-array, the function calculates the distance between the current minimum value (`mn`) and the last element of the sub-array (`a.back()`), and the distance between the current maximum value (`mx`) and the first element of the sub-array (`a.front()`). The result is updated with the maximum of these values.

5. **Update Min and Max Values**
	```cpp
	        mn = min(mn, a.front()), mx = max(mx, a.back());
	```
	The function updates `mn` to the minimum of the current `mn` and the first element of the sub-array (`a.front()`), and `mx` to the maximum of the current `mx` and the last element of the sub-array (`a.back()`), ensuring that the minimum and maximum values are kept up to date.

6. **Return Result**
	```cpp
	    return res;        
	```
	The function returns the value of `res`, which contains the maximum distance found between the first and last elements of any sub-array.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m)
- **Average Case:** O(m)
- **Worst Case:** O(m)

The solution iterates over the arrays once, so the time complexity is linear with respect to the number of arrays.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant as we only use a few variables to track the minimum and maximum values.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-distance-in-arrays/description/)

---
{{< youtube J0yYlj_oVTI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

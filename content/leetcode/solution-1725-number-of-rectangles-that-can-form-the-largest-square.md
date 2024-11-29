
+++
authors = ["grid47"]
title = "Leetcode 1725: Number Of Rectangles That Can Form The Largest Square"
date = "2024-05-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1725: Number Of Rectangles That Can Form The Largest Square in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "ajl13jUxfdM"
youtube_upload_date="2021-01-17"
youtube_thumbnail="https://i.ytimg.com/vi_webp/ajl13jUxfdM/maxresdefault.webp"
comments = true
+++



---
You are given an array `rectangles` where each element `rectangles[i] = [li, wi]` represents a rectangle with length `li` and width `wi`. You can cut a square from the rectangle as long as the side of the square is less than or equal to both the length and width of the rectangle. Your task is to find the largest possible square that can be cut from any of the given rectangles, and then return how many rectangles can produce that largest square.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an array `rectangles`, where each element represents a rectangle's length and width. Each rectangle is represented as a list of two integers.
- **Example:** `Input: rectangles = [[6, 9], [3, 8], [5, 7], [12, 6]]`
- **Constraints:**
	- 1 <= rectangles.length <= 1000
	- rectangles[i].length == 2
	- 1 <= li, wi <= 10^9
	- li != wi

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of rectangles that can form a square with the largest possible side length.
- **Example:** `Output: 2`
- **Constraints:**
	- The output is an integer representing the count of rectangles capable of forming the largest square.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the largest square that can be formed from any of the given rectangles and then determine how many rectangles can form that square.

- 1. For each rectangle, determine the largest square that can be cut from it. This is done by taking the minimum of its length and width.
- 2. Track the largest square found so far, and count how many rectangles can produce this square.
- 3. Return the count of rectangles that can form the largest square.
{{< dots >}}
### Problem Assumptions ✅
- Each rectangle is non-degenerate, meaning both the length and width are non-zero.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: rectangles = [[6, 9], [3, 8], [5, 7], [12, 6]]`  \
  **Explanation:** The largest squares from the rectangles have side lengths [6, 3, 5, 6]. The largest square has side length 6, and two rectangles can form a square of side 6, so the output is 2.

- **Input:** `Input: rectangles = [[7, 8], [5, 5], [9, 10], [6, 6]]`  \
  **Explanation:** The largest squares from the rectangles have side lengths [7, 5, 9, 6]. The largest square has side length 9, and only one rectangle can form a square of side 9, so the output is 1.

{{< dots >}}
## Approach 🚀
The approach involves finding the maximum side length of the square that can be formed from each rectangle and then counting how many rectangles can form the largest square.

### Initial Thoughts 💭
- The largest square that can be cut from a rectangle is limited by the smaller of its two sides (length or width).
- We can track the largest square side by comparing the minimum of length and width for each rectangle, then count how many rectangles share that maximum square size.
{{< dots >}}
### Edge Cases 🌐
- An empty list of rectangles is not a valid input as there should be at least one rectangle.
- The solution should efficiently handle cases where the number of rectangles is close to 1000.
- The rectangles with equal side lengths (e.g., a square) will always form a square of that side length.
- The solution must handle the large range of side lengths (up to 10^9).
{{< dots >}}
## Code 💻
```cpp
int countGoodRectangles(vector<vector<int>>& rectangles) {
    unordered_map<int,int>mp;
    int ans=0;
    for(auto i:rectangles){
        int m=min(i[0],i[1]);
        ans=max(ans,m);
        mp[m]++;
    }
    
    return mp[ans];

}
```

The function `countGoodRectangles` calculates how many rectangles of maximum possible square side length can be formed from the given list of rectangles. The algorithm first computes the smallest side of each rectangle and updates the count for each side length in a hash map. Finally, the function returns how many rectangles have the maximum side length.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int countGoodRectangles(vector<vector<int>>& rectangles) {
	```
	The function `countGoodRectangles` is defined, taking a vector of rectangles as input. Each rectangle is represented as a vector of two integers, where each element is a side length.

2. **Variable Declaration**
	```cpp
	    unordered_map<int,int>mp;
	```
	An unordered map `mp` is declared to store the frequency of each possible side length. The key is the side length, and the value is the count of rectangles with that side length.

3. **Variable Initialization**
	```cpp
	    int ans=0;
	```
	An integer `ans` is initialized to 0. This variable will store the side length of the largest square that can be formed from the rectangles.

4. **Loop Start**
	```cpp
	    for(auto i:rectangles){
	```
	A loop is started to iterate over each rectangle in the `rectangles` vector.

5. **Calculate Minimum Side**
	```cpp
	        int m=min(i[0],i[1]);
	```
	For each rectangle, the minimum of the two side lengths is calculated and stored in `m`. This represents the maximum possible square side length that can fit within this rectangle.

6. **Update Maximum Side Length**
	```cpp
	        ans=max(ans,m);
	```
	The `ans` variable is updated to store the maximum square side length found so far.

7. **Update Frequency Map**
	```cpp
	        mp[m]++;
	```
	The frequency of the current minimum side length `m` is incremented in the unordered map `mp`.

8. **Return Result**
	```cpp
	    return mp[ans];
	```
	The function returns the count of rectangles that have the maximum possible square side length `ans`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the number of rectangles.
- **Average Case:** O(n), since we examine each rectangle and its sides once.
- **Worst Case:** O(n), as we iterate through all rectangles.

The time complexity is linear with respect to the number of rectangles.

### Space Complexity 💾
- **Best Case:** O(1), as we only need a few variables.
- **Worst Case:** O(n), for storing the count of rectangles and the largest square side.

The space complexity is constant, aside from the input array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-rectangles-that-can-form-the-largest-square/description/)

---
{{< youtube ajl13jUxfdM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

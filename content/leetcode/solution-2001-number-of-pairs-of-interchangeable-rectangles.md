
+++
authors = ["grid47"]
title = "Leetcode 2001: Number of Pairs of Interchangeable Rectangles"
date = "2024-04-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2001: Number of Pairs of Interchangeable Rectangles in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Math","Counting","Number Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "lEQ8ZlLOuyQ"
youtube_upload_date="2021-09-12"
youtube_thumbnail="https://i.ytimg.com/vi/lEQ8ZlLOuyQ/maxresdefault.jpg"
comments = true
+++



---
You are given a list of rectangles, each represented by its width and height. Two rectangles are interchangeable if their width-to-height ratios are the same. Your task is to return the number of interchangeable rectangle pairs in the list.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a list of rectangles, where each rectangle is represented as a pair of integers: [width, height]. The number of rectangles is between 1 and 10^5, and each width and height is between 1 and 10^5.
- **Example:** `rectangles = [[6,12], [3,6], [5,10], [15,30]]`
- **Constraints:**
	- 1 <= n <= 10^5
	- 1 <= width_i, height_i <= 10^5
	- rectangles[i].length == 2

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the total number of pairs of interchangeable rectangles.
- **Example:** `6`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to calculate the number of interchangeable pairs of rectangles, which can be done by checking for rectangles with the same width-to-height ratio.

- 1. Compute the width-to-height ratio for each rectangle.
- 2. Use a hash map to store the frequency of each unique ratio.
- 3. For each unique ratio, calculate the number of interchangeable pairs using the frequency of that ratio.
- 4. Return the total count of pairs.
{{< dots >}}
### Problem Assumptions ✅
- The input list contains valid rectangles with width and height values between 1 and 10^5.
{{< dots >}}
## Examples 🧩
- **Input:** `rectangles = [[6,12], [3,6], [5,10], [15,30]]`  \
  **Explanation:** The width-to-height ratios for these rectangles are 6/12, 3/6, 5/10, and 15/30, which are all the same. Therefore, all 6 pairs of rectangles are interchangeable.

- **Input:** `rectangles = [[6,7], [7,8]]`  \
  **Explanation:** The width-to-height ratios for these rectangles are different, so there are no interchangeable pairs.

{{< dots >}}
## Approach 🚀
The solution involves calculating the width-to-height ratio for each rectangle and storing them in a hash map. The total number of interchangeable pairs is computed by considering how many rectangles share the same ratio.

### Initial Thoughts 💭
- The key observation is that rectangles with the same width-to-height ratio are interchangeable.
- This problem can be solved efficiently by using a hash map to track the frequency of each ratio.
{{< dots >}}
### Edge Cases 🌐
- If the input has only one rectangle, there are no interchangeable pairs.
- The solution should handle up to 10^5 rectangles efficiently.
- Rectangles with the same width and height will have a ratio of 1.
- Ensure that the solution can handle the full range of input sizes and values efficiently.
{{< dots >}}
## Code 💻
```cpp
long long interchangeableRectangles(vector<vector<int>>& rectangles) {
    unordered_map<double, int> mp;
    long long cnt = 0;
    for(auto r: rectangles) {
        double x = (double)r[0]/ r[1];
        if(mp.find(x) != mp.end()) cnt += mp[x];
        mp[x]++;
    }

    // int cnt = 0;
    // for(auto &it: mp) 
    // {
        // cout << it.second << ' ';
        // cnt = cnt + it.second * (it.second -1 ) / 2;
    // }

    return cnt;
}
```

The function counts the number of pairs of interchangeable rectangles from a given list. A rectangle is interchangeable with another if their width-to-height ratio is the same. It uses a hash map to track the frequency of each unique ratio.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	long long interchangeableRectangles(vector<vector<int>>& rectangles) {
	```
	Defines the function `interchangeableRectangles` that takes a vector of rectangles (represented as pairs of integers) and returns the count of interchangeable rectangle pairs.

2. **Variable Initialization**
	```cpp
	    unordered_map<double, int> mp;
	```
	Initializes an unordered map `mp` that will store the ratio of the width and height of each rectangle, mapped to the count of how many times that ratio has been encountered.

3. **Variable Initialization**
	```cpp
	    long long cnt = 0;
	```
	Initializes the variable `cnt` to store the count of interchangeable rectangle pairs.

4. **Looping Through Rectangles**
	```cpp
	    for(auto r: rectangles) {
	```
	Starts a loop to iterate over each rectangle in the `rectangles` vector.

5. **Ratio Calculation**
	```cpp
	        double x = (double)r[0]/ r[1];
	```
	Calculates the ratio of the rectangle's width to height and stores it in the variable `x`.

6. **Map Lookup**
	```cpp
	        if(mp.find(x) != mp.end()) cnt += mp[x];
	```
	Checks if the ratio `x` already exists in the map `mp`. If it does, the current count of rectangles with the same ratio is added to `cnt`.

7. **Map Update**
	```cpp
	        mp[x]++;
	```
	Increments the count for the ratio `x` in the map `mp` to track how many times this ratio has appeared.

8. **Return Statement**
	```cpp
	    return cnt;
	```
	Returns the total count of interchangeable rectangle pairs stored in `cnt`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the number of rectangles. We iterate over the list once to calculate ratios and update the hash map.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) because we store the frequency of each unique ratio in a hash map.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-pairs-of-interchangeable-rectangles/description/)

---
{{< youtube lEQ8ZlLOuyQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |


+++
authors = ["grid47"]
title = "Leetcode 497: Random Point in Non-overlapping Rectangles"
date = "2024-09-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 497: Random Point in Non-overlapping Rectangles in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Binary Search","Reservoir Sampling","Prefix Sum","Ordered Set","Randomized"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/497.webp"
youtube = "8kwPXbTMSnk"
youtube_upload_date="2020-08-22"
youtube_thumbnail="https://i.ytimg.com/vi/8kwPXbTMSnk/hqdefault.jpg?sqp=-oaymwEmCOADEOgC8quKqQMa8AEB-AHUBoAC4AOKAgwIABABGHIgZCgaMA8=&rs=AOn4CLAFskjPMvHmINXyYhzAGRh0xLe3Fw"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/497.webp" 
    alt="A series of non-overlapping rectangles where random points are chosen and softly illuminated as they are selected."
    caption="Solution to LeetCode 497: Random Point in Non-overlapping Rectangles Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given an array of non-overlapping axis-aligned rectangles. Each rectangle is represented by its bottom-left and top-right corner. Your task is to design a system that can pick a random integer point from the space covered by one of the given rectangles. A point on the perimeter of a rectangle is considered inside the rectangle.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array of rectangles, where each rectangle is represented by its bottom-left and top-right coordinates.
- **Example:** `[[[[1, 1, 4, 4], [-2, -2, 2, 2]]]]`
- **Constraints:**
	- 1 <= rects.length <= 100
	- rects[i].length == 4
	- -10^9 <= ai < xi <= 10^9
	- -10^9 <= bi < yi <= 10^9
	- xi - ai <= 2000
	- yi - bi <= 2000

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should return a random integer point inside the space covered by one of the rectangles.
- **Example:** `[2, 2]`
- **Constraints:**
	- The output is an array of two integers, representing the coordinates of the selected random point.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to implement a system that can select a random point from the space covered by the given rectangles, ensuring equal probability for each point.

- 1. For each rectangle, calculate the area it covers.
- 2. Create a prefix sum array to track the cumulative area of rectangles.
- 3. Use a random number generator to select a rectangle based on its area.
- 4. Pick a random point within the selected rectangle.
{{< dots >}}
### Problem Assumptions ✅
- All rectangles are non-overlapping and aligned to axes.
- The selected random points should be equally likely to be chosen from any of the given rectangles.
{{< dots >}}
## Examples 🧩
- **Input:** `[[[[1, 1, 4, 4], [-2, -2, 2, 2]]]]`  \
  **Explanation:** The first rectangle covers the area from (1, 1) to (4, 4), and the second rectangle covers the area from (-2, -2) to (2, 2). The 'pick' function randomly selects a point from one of these two rectangles, such as [2, 2] or [-1, -2].

{{< dots >}}
## Approach 🚀
The solution involves calculating the area of each rectangle, storing cumulative areas, and then using these areas to select a rectangle randomly. After selecting a rectangle, a random point is chosen from within it.

### Initial Thoughts 💭
- The solution needs to ensure that each point has equal probability of being selected.
- A prefix sum of the areas will allow efficient selection of rectangles based on their area.
- Efficiently implementing this using a prefix sum array will allow fast lookups and selections.
{{< dots >}}
### Edge Cases 🌐
- The problem guarantees that the input will contain at least one rectangle.
- The solution should efficiently handle up to 10^4 pick calls, so the algorithm must be optimized for speed.
- Points on the perimeter should also be considered as valid points inside the rectangle.
- Ensure that the algorithm is efficient enough to handle the upper limits of the input sizes.
{{< dots >}}
## Code 💻
```cpp
class Solution {
vector<int> v;
vector<vector<int>> rect;
public:

int area(vector<int> r) {
    
    return (r[2] - r[0] +1) * (r[3] - r[1] +1);
}

Solution(vector<vector<int>>& r) {
    rect = r;
    for(vector<int> re : r) {
        v.push_back(area(re) + (v.empty()? 0 : v.back()));
    }
}

vector<int> pick() {
    int d = rand() % v.back();
    int idz = upper_bound(v.begin(), v.end(), d) - v.begin();
    vector<int> r = rect[idz];
    return {
        rand() % (r[2] - r[0] +1) + r[0],
        rand() % (r[3] - r[1] +1) + r[1]
    };
}
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
```

The Solution class implements the logic to randomly pick a point within the given set of rectangles. It uses the area of the rectangles to decide the probability of selecting points from each rectangle.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Class Definition**
	```cpp
	class Solution {
	```
	Defines the `Solution` class, which will be used to encapsulate the logic for selecting random points within given rectangles.

2. **Variable Declaration**
	```cpp
	vector<int> v;
	```
	Declares a vector `v` that will store the cumulative area of rectangles to assist in random point selection based on area weights.

3. **Variable Declaration**
	```cpp
	vector<vector<int>> rect;
	```
	Declares a 2D vector `rect`, which stores the coordinates of the rectangles given as input.

4. **Access Specifier**
	```cpp
	public:
	```
	Marks the following methods as public, allowing them to be accessed by objects of the `Solution` class.

5. **Method Definition**
	```cpp
	int area(vector<int> r) {
	```
	Defines a helper method `area` to calculate the area of a given rectangle represented by the vector `r`.

6. **Area Calculation**
	```cpp
	    return (r[2] - r[0] +1) * (r[3] - r[1] +1);
	```
	Calculates the area of the rectangle using the formula `(width) * (height)`, where `r[0]`, `r[1]` are the coordinates of the bottom-left corner, and `r[2]`, `r[3]` are the coordinates of the top-right corner.

7. **Constructor Definition**
	```cpp
	Solution(vector<vector<int>>& r) {
	```
	Defines the constructor of the `Solution` class that initializes the `rect` vector and calculates the cumulative areas of the rectangles.

8. **Input Assignment**
	```cpp
	    rect = r;
	```
	Assigns the input vector `r` to the class-level `rect` variable, which stores the rectangle data.

9. **Loop**
	```cpp
	    for(vector<int> re : r) {
	```
	Iterates over each rectangle in the input `r` to compute the areas and accumulate them.

10. **Cumulative Area Calculation**
	```cpp
	        v.push_back(area(re) + (v.empty()? 0 : v.back()));
	```
	For each rectangle, calculates its area using the `area` method and adds it to the cumulative area vector `v`. If `v` is empty, it starts from 0.

11. **Method Definition**
	```cpp
	vector<int> pick() {
	```
	Defines the `pick` method, which randomly selects a point from one of the rectangles based on their area probabilities.

12. **Random Selection**
	```cpp
	    int d = rand() % v.back();
	```
	Generates a random number `d` between 0 and the total area of all rectangles (stored in the last element of `v`).

13. **Binary Search**
	```cpp
	    int idz = upper_bound(v.begin(), v.end(), d) - v.begin();
	```
	Uses binary search (`upper_bound`) to find the rectangle corresponding to the randomly generated area `d`.

14. **Rectangle Selection**
	```cpp
	    vector<int> r = rect[idz];
	```
	Selects the rectangle corresponding to the index `idz` from the `rect` vector.

15. **Return Statement**
	```cpp
	    return {
	```
	Starts returning the randomly selected point within the chosen rectangle.

16. **Random Coordinate Generation**
	```cpp
	        rand() % (r[2] - r[0] +1) + r[0],
	```
	Generates a random x-coordinate within the bounds of the selected rectangle.

17. **Random Coordinate Generation**
	```cpp
	        rand() % (r[3] - r[1] +1) + r[1]
	```
	Generates a random y-coordinate within the bounds of the selected rectangle.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(log n)
- **Average Case:** O(log n)
- **Worst Case:** O(log n)

The time complexity for selecting a rectangle is O(log n) due to the use of binary search on the prefix sum array.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to storing the prefix sum array and the rectangles.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/description/)

---
{{< youtube 8kwPXbTMSnk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

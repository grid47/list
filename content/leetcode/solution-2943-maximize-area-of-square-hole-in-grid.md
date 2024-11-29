
+++
authors = ["grid47"]
title = "Leetcode 2943: Maximize Area of Square Hole in Grid"
date = "2024-01-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2943: Maximize Area of Square Hole in Grid in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "PwzZ9UVWqBk"
youtube_upload_date="2023-11-25"
youtube_thumbnail="https://i.ytimg.com/vi/PwzZ9UVWqBk/maxresdefault.jpg"
comments = true
+++



---
You are given a grid with n + 2 horizontal bars and m + 2 vertical bars, creating 1x1 unit cells. You can remove some bars from the given arrays hBars (horizontal bars) and vBars (vertical bars). The remaining bars are fixed and cannot be removed. Your task is to determine the maximum area of a square-shaped hole that can be formed in the grid after removing some bars.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given the integers n and m, and two arrays of integers: hBars and vBars. The arrays represent the positions of horizontal and vertical bars in the grid.
- **Example:** `n = 2, m = 1, hBars = [2, 3], vBars = [2]`
- **Constraints:**
	- 1 <= n <= 10^9
	- 1 <= m <= 10^9
	- 1 <= hBars.length <= 100
	- 1 <= vBars.length <= 100
	- 2 <= hBars[i] <= n + 1
	- 2 <= vBars[i] <= m + 1
	- All values in hBars are distinct.
	- All values in vBars are distinct.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an integer representing the maximum area of a square-shaped hole that can be formed in the grid after removing some bars.
- **Example:** `For n = 2, m = 1, hBars = [2, 3], vBars = [2], the output is 4.`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to determine the maximum possible area of a square-shaped hole that can be created in the grid by removing some horizontal and vertical bars.

- Sort the hBars and vBars arrays.
- Calculate the maximum distance between consecutive bars in both horizontal and vertical directions.
- The maximum square area is the square of the minimum distance between the bars in the horizontal and vertical directions.
{{< dots >}}
### Problem Assumptions ✅
- The input arrays hBars and vBars contain distinct values and represent valid positions of the bars in the grid.
{{< dots >}}
## Examples 🧩
- **Input:** `n = 2, m = 1, hBars = [2, 3], vBars = [2]`  \
  **Explanation:** The maximum square-shaped hole can be obtained by removing horizontal bar 2 and vertical bar 2, creating a square of area 4.

- **Input:** `n = 1, m = 1, hBars = [2], vBars = [2]`  \
  **Explanation:** By removing horizontal bar 2 and vertical bar 2, a square-shaped hole of area 4 is formed.

- **Input:** `n = 2, m = 3, hBars = [2, 3], vBars = [2, 4]`  \
  **Explanation:** By removing horizontal bar 3 and vertical bar 4, a square-shaped hole with an area of 4 is created.

{{< dots >}}
## Approach 🚀
The approach involves sorting the bars and calculating the maximum square area by finding the largest gap between consecutive bars in both the horizontal and vertical directions.

### Initial Thoughts 💭
- The problem boils down to finding the largest gap between consecutive bars in both horizontal and vertical directions.
- Sorting the bars and calculating the maximum gap between consecutive bars will help us find the largest square that can be formed.
{{< dots >}}
### Edge Cases 🌐
- The input arrays hBars and vBars should never be empty, as per the problem's constraints.
- The problem allows very large values for n and m (up to 10^9), but the lengths of hBars and vBars are small (up to 100), making the problem feasible for the given constraints.
- If hBars and vBars contain bars placed very close to each other, the maximum square hole area will be smaller.
- The arrays hBars and vBars are guaranteed to have distinct values within the given range.
{{< dots >}}
## Code 💻
```cpp
int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
    vector<int>h;
    vector<int>v;
    sort(hBars.begin(),hBars.end());
    sort(vBars.begin(),vBars.end());
    for(auto i:hBars)
        h.push_back(i);
    for(auto i:vBars)
        v.push_back(i);
    int mv=1,mh=1;
    int c=1;
    for(int i=1;i<h.size();i++)
    {   
        
        if(h[i]==h[i-1]+1)
            c++;
        else
            c=1;
        mh=max(mh,c);
    }
    c=1;
    for(int i=1;i<v.size();i++)
    {   
        if(v[i]==v[i-1]+1)
            c++;
        else
            c=1;
        mv=max(mv,c);
    }
    int x=min(mh+1,mv+1);
    return x*x;
}
```

This function calculates the maximum square area that can be formed using horizontal and vertical bars. It first sorts the horizontal and vertical bar positions, then checks consecutive bars to determine the maximum distance between bars. Finally, it calculates the area of the largest square that can be formed.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
	```
	Defines the function 'maximizeSquareHoleArea' that takes the dimensions of the grid and vectors of horizontal and vertical bars as input, and returns the area of the largest square that can be formed.

2. **Vector Initialization**
	```cpp
	    vector<int>h;
	```
	Initializes an empty vector 'h' to store the horizontal bar positions.

3. **Vector Initialization**
	```cpp
	    vector<int>v;
	```
	Initializes an empty vector 'v' to store the vertical bar positions.

4. **Sort Horizontal Bars**
	```cpp
	    sort(hBars.begin(),hBars.end());
	```
	Sorts the 'hBars' vector in ascending order to process the bars in the correct order.

5. **Sort Vertical Bars**
	```cpp
	    sort(vBars.begin(),vBars.end());
	```
	Sorts the 'vBars' vector in ascending order to process the bars in the correct order.

6. **Push Horizontal Bars to Vector**
	```cpp
	    for(auto i:hBars)
	```
	Iterates over the sorted 'hBars' and pushes each element into the 'h' vector.

7. **Push Horizontal Bar to Vector**
	```cpp
	        h.push_back(i);
	```
	Adds the current horizontal bar position to the 'h' vector.

8. **Push Vertical Bars to Vector**
	```cpp
	    for(auto i:vBars)
	```
	Iterates over the sorted 'vBars' and pushes each element into the 'v' vector.

9. **Push Vertical Bar to Vector**
	```cpp
	        v.push_back(i);
	```
	Adds the current vertical bar position to the 'v' vector.

10. **Initialize Variables**
	```cpp
	    int mv=1,mh=1;
	```
	Initializes two variables 'mv' and 'mh' to store the maximum consecutive vertical and horizontal distances, respectively.

11. **Initialize Counter**
	```cpp
	    int c=1;
	```
	Initializes a counter 'c' to track the number of consecutive bars (either horizontal or vertical).

12. **Loop Through Horizontal Bars**
	```cpp
	    for(int i=1;i<h.size();i++)
	```
	Starts a loop to iterate through the 'h' vector (horizontal bars) starting from the second element.

13. **Consecutive Horizontal Bars Check**
	```cpp
	        if(h[i]==h[i-1]+1)
	```
	Checks if the current horizontal bar is consecutive to the previous one (i.e., if the difference between the current and previous bar is 1).

14. **Increment Counter**
	```cpp
	            c++;
	```
	If the current horizontal bar is consecutive to the previous one, increments the counter 'c'.

15. **Reset Counter**
	```cpp
	        else
	```
	If the bars are not consecutive, resets the counter 'c' to 1.

16. **Update Maximum Horizontal Distance**
	```cpp
	            c=1;
	```
	Resets the counter to 1, as the sequence of consecutive bars was broken.

17. **Update Maximum Horizontal Distance**
	```cpp
	        mh=max(mh,c);
	```
	Updates the maximum horizontal distance 'mh' to the maximum of the current 'mh' and the counter 'c'.

18. **Reset Counter for Vertical Bars**
	```cpp
	    c=1;
	```
	Resets the counter 'c' to 1 before checking the vertical bars.

19. **Loop Through Vertical Bars**
	```cpp
	    for(int i=1;i<v.size();i++)
	```
	Starts a loop to iterate through the 'v' vector (vertical bars) starting from the second element.

20. **Consecutive Vertical Bars Check**
	```cpp
	        if(v[i]==v[i-1]+1)
	```
	Checks if the current vertical bar is consecutive to the previous one (i.e., if the difference between the current and previous bar is 1).

21. **Increment Counter**
	```cpp
	            c++;
	```
	If the current vertical bar is consecutive to the previous one, increments the counter 'c'.

22. **Reset Counter**
	```cpp
	        else
	```
	If the bars are not consecutive, resets the counter 'c' to 1.

23. **Update Maximum Vertical Distance**
	```cpp
	            c=1;
	```
	Resets the counter to 1, as the sequence of consecutive bars was broken.

24. **Update Maximum Vertical Distance**
	```cpp
	        mv=max(mv,c);
	```
	Updates the maximum vertical distance 'mv' to the maximum of the current 'mv' and the counter 'c'.

25. **Calculate Square Size**
	```cpp
	    int x=min(mh+1,mv+1);
	```
	Calculates the size of the largest square possible using the minimum of the maximum horizontal and vertical distances, incremented by 1.

26. **Return Result**
	```cpp
	    return x*x;
	```
	Returns the area of the square, which is the square of the calculated size 'x'.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The time complexity is dominated by the sorting of the hBars and vBars arrays.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage of the input arrays.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximize-area-of-square-hole-in-grid/description/)

---
{{< youtube PwzZ9UVWqBk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

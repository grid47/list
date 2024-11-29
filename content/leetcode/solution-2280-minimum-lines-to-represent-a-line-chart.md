
+++
authors = ["grid47"]
title = "Leetcode 2280: Minimum Lines to Represent a Line Chart"
date = "2024-03-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2280: Minimum Lines to Represent a Line Chart in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Geometry","Sorting","Number Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "EkoNpVUBSVo"
youtube_upload_date="2022-05-22"
youtube_thumbnail="https://i.ytimg.com/vi_webp/EkoNpVUBSVo/maxresdefault.webp"
comments = true
+++



---
You are given a list of stock prices where each element represents the stock price on a specific day. The stock prices are given as pairs where the first element is the day number and the second element is the stock price for that day. A line chart can be drawn by plotting these prices on an XY-plane, where the X-axis represents the day and the Y-axis represents the price. Your task is to determine the minimum number of lines required to represent the stock prices as a continuous line chart.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a 2D array `stockPrices` where each element `stockPrices[i] = [day_i, price_i]` represents the stock price on `day_i` with a price of `price_i`.
- **Example:** `Input: stockPrices = [[1, 10], [2, 15], [3, 12], [4, 18], [5, 20]]`
- **Constraints:**
	- 1 <= stockPrices.length <= 10^5
	- stockPrices[i].length == 2
	- 1 <= day_i, price_i <= 10^9
	- All day_i are distinct.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is an integer representing the minimum number of lines needed to represent the stock price chart.
- **Example:** `Output: 2`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to calculate the minimum number of straight lines that can connect all the stock prices by determining if the points lie on the same straight line.

- Sort the stock prices by the day.
- Iterate through the stock prices and check if each consecutive pair lies on the same line as the previous pair.
- If a new line is required, increment the count.
{{< dots >}}
### Problem Assumptions ✅
- Stock prices will be provided in unsorted order, so sorting is required.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: stockPrices = [[1, 7], [2, 6], [3, 5], [4, 4], [5, 4], [6, 3], [7, 2], [8, 1]]`  \
  **Explanation:** The stock prices need 3 lines to be represented. The first line connects points (1, 7) to (4, 4). The second line connects (4, 4) to (5, 4), and the third line connects (5, 4) to (8, 1).

- **Input:** `Input: stockPrices = [[1, 3], [2, 5], [3, 7], [4, 9], [5, 11]]`  \
  **Explanation:** The stock prices form a single line where the price increases uniformly. Therefore, only one line is needed to represent the chart.

{{< dots >}}
## Approach 🚀
The approach involves iterating over the stock prices and checking if consecutive points lie on the same straight line. A new line is needed whenever the slope between consecutive points changes.

### Initial Thoughts 💭
- This problem can be solved efficiently by analyzing the slope between consecutive points and checking if they remain constant.
- Sorting the stock prices will help simplify checking consecutive points. The main task is to check if each consecutive triplet of points lies on the same straight line.
{{< dots >}}
### Edge Cases 🌐
- The input is always non-empty since stockPrices.length is at least 1.
- The solution should handle up to 100,000 stock prices efficiently.
- If all prices are the same, only one line is required.
- Sorting is O(n log n), and the overall complexity should not exceed O(n log n).
{{< dots >}}
## Code 💻
```cpp
int minimumLines(vector<vector<int>>& stk) {
    
    sort(stk.begin(), stk.end());
    
    int res = 1, n = stk.size();
    if (n < 2) return 0;

    for(int i = 2; i < n; i++) {
        long x1 = stk[i][0], x2 = stk[i - 1][0], x3 = stk[i - 2][0];
        long y1 = stk[i][1], y2 = stk[i - 1][1], y3 = stk[i - 2][1];
        
        long diff1 = (y3 - y2) * (x2 - x1);
        long diff2 = (y2 - y1) * (x3 - x2);
        
        if (diff1 != diff2) res++;
    }

    return res;
}
```

This function computes the minimum number of lines required to connect a set of points on a 2D plane. It sorts the points, then compares the slopes of consecutive triplets of points to determine if they lie on the same straight line. If not, the result counter `res` is incremented.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int minimumLines(vector<vector<int>>& stk) {
	```
	The function header for `minimumLines` which takes a vector of vectors `stk` representing a list of points (each point is a pair of coordinates), and returns the minimum number of lines required to connect these points.

2. **Sort Points**
	```cpp
	    sort(stk.begin(), stk.end());
	```
	This line sorts the vector `stk` in ascending order of points, which is essential to efficiently compare consecutive points and check if they lie on the same line.

3. **Initialize Variables**
	```cpp
	    int res = 1, n = stk.size();
	```
	Here, we initialize `res` to 1 (as at least one line is needed) and `n` to the number of points in `stk`. If there are fewer than 2 points, no line is needed, so the function would return 0.

4. **Early Exit**
	```cpp
	    if (n < 2) return 0;
	```
	If there are fewer than two points, no lines can be drawn, so the function returns 0.

5. **Loop Over Points**
	```cpp
	    for(int i = 2; i < n; i++) {
	```
	This `for` loop starts from index 2 and iterates over the points to compare triplets of points to check if they lie on the same line.

6. **Extract Points**
	```cpp
	        long x1 = stk[i][0], x2 = stk[i - 1][0], x3 = stk[i - 2][0];
	```
	These lines extract the x-coordinates of the current point (`x1`), the previous point (`x2`), and the point before that (`x3`) to check the slope between these points.

7. **Extract Points (y-coordinates)**
	```cpp
	        long y1 = stk[i][1], y2 = stk[i - 1][1], y3 = stk[i - 2][1];
	```
	Similarly, these lines extract the y-coordinates (`y1`, `y2`, and `y3`) of the current, previous, and second previous points.

8. **Calculate Slope Differences**
	```cpp
	        long diff1 = (y3 - y2) * (x2 - x1);
	```
	This calculates the first slope difference, which represents the difference in slopes between the last two points (`x1, y1` and `x2, y2`).

9. **Calculate Slope Differences (cont.)**
	```cpp
	        long diff2 = (y2 - y1) * (x3 - x2);
	```
	This calculates the second slope difference, representing the difference in slopes between the second and third points (`x2, y2` and `x3, y3`).

10. **Check Slopes**
	```cpp
	        if (diff1 != diff2) res++;
	```
	If the two slope differences (`diff1` and `diff2`) are not equal, this means the three points do not lie on the same straight line, so the result counter `res` is incremented.

11. **Return Statement**
	```cpp
	    return res;
	```
	Finally, the function returns the number of lines required to connect the points.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The time complexity is O(n log n) due to the sorting of the stock prices.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) for storing the sorted stock prices.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-lines-to-represent-a-line-chart/description/)

---
{{< youtube EkoNpVUBSVo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |


+++
authors = ["grid47"]
title = "Leetcode 1465: Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts"
date = "2024-06-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1465: Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "koGHcwtIaLY"
youtube_upload_date="2020-05-31"
youtube_thumbnail="https://i.ytimg.com/vi/koGHcwtIaLY/maxresdefault.jpg"
comments = true
+++



---
You are given a rectangular cake of size h x w. There are two arrays of integers, horizontalCuts and verticalCuts. Each element in horizontalCuts represents a horizontal cut, and each element in verticalCuts represents a vertical cut. Your task is to find the maximum area of a piece of cake that can be obtained after making all the cuts specified in the arrays. Since the result can be a large number, return it modulo 10^9 + 7.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of three parameters: the height h, the width w, and two arrays, horizontalCuts and verticalCuts. Each array contains the positions of the cuts. The arrays are non-empty, and the cuts are distinct.
- **Example:** `Input: h = 6, w = 5, horizontalCuts = [1, 4], verticalCuts = [2, 3]`
- **Constraints:**
	- 2 <= h, w <= 10^9
	- 1 <= horizontalCuts.length <= min(h - 1, 10^5)
	- 1 <= verticalCuts.length <= min(w - 1, 10^5)
	- 1 <= horizontalCuts[i] < h
	- 1 <= verticalCuts[i] < w
	- All elements in horizontalCuts and verticalCuts are distinct.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is a single integer, representing the maximum area of the piece of cake after the cuts, modulo 10^9 + 7.
- **Example:** `Output: 6`
- **Constraints:**
	- The result should be computed modulo 10^9 + 7.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to compute the maximum possible area of a piece of cake after all the cuts. This can be done by calculating the maximum gaps between horizontal and vertical cuts, and then multiplying those gaps to get the area.

- Sort both the horizontalCuts and verticalCuts arrays.
- Find the maximum gap between consecutive horizontal cuts, including the gaps from the top and bottom of the cake.
- Find the maximum gap between consecutive vertical cuts, including the gaps from the left and right sides of the cake.
- Multiply the two maximum gaps to get the maximum area, and return it modulo 10^9 + 7.
{{< dots >}}
### Problem Assumptions ✅
- The input arrays are valid and do not contain duplicate values.
- The height and width are sufficiently large to allow multiple cuts.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: h = 6, w = 5, horizontalCuts = [1, 4], verticalCuts = [2, 3]`  \
  **Explanation:** Output: 6. The maximum vertical gap is 2 (between cuts 2 and 3) and the maximum horizontal gap is 3 (between cuts 1 and 4). The area is 3 * 2 = 6.

- **Input:** `Input: h = 7, w = 6, horizontalCuts = [2, 5], verticalCuts = [1, 4]`  \
  **Explanation:** Output: 9. The maximum vertical gap is 3 (between cuts 1 and 4) and the maximum horizontal gap is 3 (between cuts 2 and 5). The area is 3 * 3 = 9.

{{< dots >}}
## Approach 🚀
To solve the problem, we need to find the largest horizontal and vertical gaps created by the cuts and then compute the area formed by these gaps. Sorting the cuts and considering the gaps between consecutive cuts (including the boundaries) allows us to efficiently compute the maximum area.

### Initial Thoughts 💭
- Sorting the cuts helps to easily calculate the gaps between consecutive cuts.
- The largest gaps will determine the maximum area.
- We should handle the boundaries (top/bottom for horizontal and left/right for vertical) by considering the first and last cuts as well.
{{< dots >}}
### Edge Cases 🌐
- The problem guarantees that both horizontalCuts and verticalCuts have at least one element.
- With a maximum of 10^5 cuts in each direction, sorting the cuts will take O(n log n) time, which is efficient enough.
- If there are cuts near the boundaries of the cake, the algorithm will still correctly compute the largest gaps.
- The solution must handle large values of h and w efficiently by focusing only on the cuts themselves.
{{< dots >}}
## Code 💻
```cpp
int maxArea(int h, int w, vector<int>& hr, vector<int>& vt) {
    
    int mx1 = 0, mx2 = 0;
    sort(hr.begin(), hr.end());
    sort(vt.begin(), vt.end());
    mx1 = h - hr.back();
    mx2 = w - vt.back();
    int prv = 0;
    for(int i = 0; i < hr.size(); i++) {
        mx1 = max(mx1, hr[i] - prv);
        prv = hr[i];
    }
    prv= 0;
    for(int i = 0; i < vt.size(); i++) {
        mx2 = max(mx2, vt[i] - prv);
        prv = vt[i];
    }      
    long long mxa = mx1, mxb = mx2;
    return (mxa * mxb) % 1000000007;
}
```

This function calculates the maximum area that can be obtained by cutting a rectangle using horizontal and vertical cuts. It uses sorting to calculate the largest gaps between cuts and returns the area modulo 1000000007.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int maxArea(int h, int w, vector<int>& hr, vector<int>& vt) {
	```
	Defines the function maxArea, which calculates the maximum area of a rectangle after performing horizontal and vertical cuts.

2. **Variable Initialization**
	```cpp
	    int mx1 = 0, mx2 = 0;
	```
	Initializes mx1 and mx2 to 0, which will later hold the maximum gap in the horizontal and vertical directions.

3. **Sorting**
	```cpp
	    sort(hr.begin(), hr.end());
	```
	Sorts the horizontal cut positions (hr) in ascending order.

4. **Sorting**
	```cpp
	    sort(vt.begin(), vt.end());
	```
	Sorts the vertical cut positions (vt) in ascending order.

5. **Calculate Max Horizontal Gap**
	```cpp
	    mx1 = h - hr.back();
	```
	Calculates the maximum horizontal gap by subtracting the last horizontal cut position from the height (h).

6. **Calculate Max Vertical Gap**
	```cpp
	    mx2 = w - vt.back();
	```
	Calculates the maximum vertical gap by subtracting the last vertical cut position from the width (w).

7. **Variable Initialization**
	```cpp
	    int prv = 0;
	```
	Initializes a variable prv to 0, which will be used to track the previous cut position during the iteration.

8. **Loop Start**
	```cpp
	    for(int i = 0; i < hr.size(); i++) {
	```
	Starts a loop to iterate through the horizontal cuts.

9. **Update Max Horizontal Gap**
	```cpp
	        mx1 = max(mx1, hr[i] - prv);
	```
	Updates mx1 with the maximum gap between the current horizontal cut and the previous one.

10. **Update Previous Horizontal Cut**
	```cpp
	        prv = hr[i];
	```
	Updates the previous horizontal cut position to the current one for the next iteration.

11. **Reset Previous Cut**
	```cpp
	    prv= 0;
	```
	Resets the previous cut position to 0 before starting the iteration over vertical cuts.

12. **Loop Start**
	```cpp
	    for(int i = 0; i < vt.size(); i++) {
	```
	Starts a loop to iterate through the vertical cuts.

13. **Update Max Vertical Gap**
	```cpp
	        mx2 = max(mx2, vt[i] - prv);
	```
	Updates mx2 with the maximum gap between the current vertical cut and the previous one.

14. **Update Previous Vertical Cut**
	```cpp
	        prv = vt[i];
	```
	Updates the previous vertical cut position to the current one for the next iteration.

15. **Calculate Area**
	```cpp
	    long long mxa = mx1, mxb = mx2;
	```
	Calculates the maximum area by multiplying the largest horizontal and vertical gaps.

16. **Return Statement**
	```cpp
	    return (mxa * mxb) % 1000000007;
	```
	Returns the result of the area modulo 1000000007 to avoid overflow.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The time complexity is dominated by the sorting of the horizontalCuts and verticalCuts arrays, where n is the length of the larger array (up to 10^5).

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n), where n is the length of the cuts arrays, as we need to store them for sorting.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/description/)

---
{{< youtube koGHcwtIaLY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

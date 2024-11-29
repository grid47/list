
+++
authors = ["grid47"]
title = "Leetcode 452: Minimum Number of Arrows to Burst Balloons"
date = "2024-09-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 452: Minimum Number of Arrows to Burst Balloons in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/452.webp"
youtube = "lPmkKnvNPrw"
youtube_upload_date="2024-03-18"
youtube_thumbnail="https://i.ytimg.com/vi/lPmkKnvNPrw/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/452.webp" 
    alt="A sequence of balloons gently bursting with each arrow, showing the optimal number of arrows needed."
    caption="Solution to LeetCode 452: Minimum Number of Arrows to Burst Balloons Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
There are several balloons attached to a flat wall, represented as intervals along the x-axis. Each balloon's horizontal span is given by a pair of integers [xstart, xend], and you must find the minimum number of arrows required to burst all the balloons. An arrow travels infinitely upwards and bursts any balloon that overlaps with its path.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a 2D array 'points' where each element is a pair of integers [xstart, xend], representing the starting and ending x-coordinates of the balloon's diameter.
- **Example:** `[[1, 5], [2, 6], [5, 8], [7, 9]]`
- **Constraints:**
	- 1 <= points.length <= 10^5
	- -2^31 <= xstart < xend <= 2^31 - 1

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of arrows required to burst all the balloons.
- **Example:** `2`
- **Constraints:**
	- The number of arrows must be minimized.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the minimum number of arrows needed to burst all the balloons.

- 1. Sort the intervals based on their end values.
- 2. Iterate through the sorted intervals, and for each balloon, check if it can be burst by the last shot arrow.
- 3. If a new arrow is needed, increment the count and update the position of the arrow.
{{< dots >}}
### Problem Assumptions ✅
- Each balloon has a well-defined x-coordinate range (xstart < xend).
- There is no overlap of the balloons if no arrows are fired.
{{< dots >}}
## Examples 🧩
- **Input:** `[[1, 5], [2, 6], [5, 8], [7, 9]]`  \
  **Explanation:** We can shoot two arrows: one at x=5 to burst the balloons [1,5], [2,6], and [5,8], and another at x=7 to burst [7,9].

- **Input:** `[[1,2], [3,4], [5,6], [7,8]]`  \
  **Explanation:** Since each balloon does not overlap with others, we need to shoot an arrow for each, resulting in 4 arrows.

- **Input:** `[[3, 4], [2, 3], [5, 6], [4, 5]]`  \
  **Explanation:** Shoot an arrow at x=3 to burst balloons [3,4], [2,3], and [4,5], and another arrow at x=5 to burst [5,6].

{{< dots >}}
## Approach 🚀
Sort the balloon intervals by their end points. Then, iterate through the sorted intervals, firing arrows at the end of each balloon's span when necessary to minimize the number of arrows.

### Initial Thoughts 💭
- We need to minimize the number of arrows while covering all balloons.
- Sorting by the end point allows us to use greedy strategy.
- Sorting the intervals by their end points will help us efficiently place arrows to cover overlapping intervals.
{{< dots >}}
### Edge Cases 🌐
- Empty input should not occur due to constraints.
- The solution should handle up to 100,000 points efficiently.
- Intervals with the same start and end value could be handled as separate balloons.
- Ensure sorting and iteration are efficient enough for large inputs.
{{< dots >}}
## Code 💻
```cpp
static bool cmp(vector<int> &a, vector<int> &b){
    return a[1] < b[1];
}
int findMinArrowShots(vector<vector<int>>& pts) {
    sort(pts.begin(), pts.end(), cmp);
    int cnt = 1, arp = pts[0][1];
    for(int i = 1; i < pts.size(); i++) {
        
        if(pts[i][0]<=arp) continue;
        cnt++;
        arp = pts[i][1];
    }
    return cnt;
}
```

This function solves the 'minimum number of arrows to burst balloons' problem using a greedy approach. It sorts the intervals and then iterates through them, counting the number of arrows needed.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Comparator Function**
	```cpp
	static bool cmp(vector<int> &a, vector<int> &b){
	```
	Defines a static comparator function `cmp` to be used for sorting the intervals. It compares the second element (end point) of the intervals.

2. **Comparator Logic**
	```cpp
	    return a[1] < b[1];
	```
	The comparator function returns true if the second element (end point) of the first interval is less than the second interval, allowing sorting by the end points.

3. **Function Definition**
	```cpp
	int findMinArrowShots(vector<vector<int>>& pts) {
	```
	Defines the function `findMinArrowShots` that accepts a 2D vector `pts`, where each inner vector represents an interval. The function returns the minimum number of arrows needed.

4. **Sorting**
	```cpp
	    sort(pts.begin(), pts.end(), cmp);
	```
	Sorts the intervals `pts` in ascending order based on their end points using the `cmp` comparator function.

5. **Initialization**
	```cpp
	    int cnt = 1, arp = pts[0][1];
	```
	Initializes the arrow count `cnt` to 1 (since at least one arrow is needed) and sets the first arrow position `arp` to the end point of the first interval.

6. **Loop Start**
	```cpp
	    for(int i = 1; i < pts.size(); i++) {
	```
	Starts a loop from the second interval (index 1) to process each subsequent interval.

7. **Arrow Check**
	```cpp
	        if(pts[i][0]<=arp) continue;
	```
	Checks if the start point of the current interval is less than or equal to the last arrow position. If so, no new arrow is needed, so it continues to the next interval.

8. **Arrow Count Increment**
	```cpp
	        cnt++;
	```
	Increments the arrow count since the current interval requires a new arrow.

9. **Arrow Position Update**
	```cpp
	        arp = pts[i][1];
	```
	Updates the arrow position `arp` to the end point of the current interval.

10. **Return Statement**
	```cpp
	    return cnt;
	```
	Returns the total count of arrows needed to burst all balloons.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

Sorting the balloons by their end points takes O(n log n) time. The iteration through the sorted list takes O(n) time.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

Space complexity is O(n) due to the need to store the input array and the sorted array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/)

---
{{< youtube lPmkKnvNPrw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

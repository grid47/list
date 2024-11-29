
+++
authors = ["grid47"]
title = "Leetcode 435: Non-overlapping Intervals"
date = "2024-09-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 435: Non-overlapping Intervals in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/435.webp"
youtube = "mHsj83NoZDA"
youtube_upload_date="2023-07-20"
youtube_thumbnail="https://i.ytimg.com/vi/mHsj83NoZDA/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/435.webp" 
    alt="A sequence of intervals with non-overlapping sections glowing softly, showing the optimal arrangement."
    caption="Solution to LeetCode 435: Non-overlapping Intervals Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given an array of intervals, where each interval is represented by a pair of integers [start, end], the goal is to determine the minimum number of intervals to remove to make the rest non-overlapping. Intervals that only touch at a point are considered non-overlapping.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an array of intervals, where each interval is represented as an array of two integers: [start, end].
- **Example:** `intervals = [[1, 2], [2, 3], [3, 4], [1, 3]]`
- **Constraints:**
	- 1 <= intervals.length <= 10^5
	- -5 * 10^4 <= starti < endi <= 5 * 10^4

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of intervals to remove to make the remaining intervals non-overlapping.
- **Example:** `1`
- **Constraints:**
	- If all intervals are already non-overlapping, return 0.
	- If no intervals can be removed to make them non-overlapping, return -1.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to minimize the number of intervals that must be removed to ensure the rest are non-overlapping.

- 1. Sort the intervals by their start times.
- 2. Use a greedy algorithm to keep the interval with the earliest end time, and remove intervals that overlap with it.
- 3. Track the number of removed intervals and return that count.
{{< dots >}}
### Problem Assumptions ✅
- Intervals are represented by pairs of integers, and each interval's start is less than its end.
- The intervals array is not empty and contains at least one interval.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: intervals = [[1,2],[2,3],[3,4],[1,3]]`  \
  **Explanation:** We remove the interval [1,3], and the remaining intervals are non-overlapping.

- **Input:** `Input: intervals = [[1,2],[1,2],[1,2]]`  \
  **Explanation:** We need to remove two of the [1,2] intervals to make the rest non-overlapping.

- **Input:** `Input: intervals = [[1,2],[2,3]]`  \
  **Explanation:** The intervals are already non-overlapping, so no removal is necessary.

{{< dots >}}
## Approach 🚀
We will use a greedy algorithm to minimize the number of intervals removed. The idea is to always keep the interval with the smallest end time to reduce the chance of overlaps.

### Initial Thoughts 💭
- Sorting the intervals by their end times will help us efficiently select intervals that minimize overlaps.
- By keeping intervals with the earliest end time, we can maximize the space available for future intervals, thereby minimizing the number of removed intervals.
{{< dots >}}
### Edge Cases 🌐
- If the intervals array is empty, return 0 as there are no intervals to remove.
- If the intervals array contains a large number of intervals, ensure the algorithm handles it efficiently.
- If all intervals are already non-overlapping, return 0.
- Handle cases where all intervals are identical, or where no intervals overlap.
{{< dots >}}
## Code 💻
```cpp
int eraseOverlapIntervals(vector<vector<int>>& ivl) {
    sort(ivl.begin(), ivl.end());
    int ans = 0;
    int n = ivl.size();
    int prv = 0;
    for(int cur = 1; cur < n; cur++) {
        // [1, 5]. [3, 6]
        // [2, 8]. [3, 5]
        if(ivl[cur][0] < ivl[prv][1]) {
            ans++;
            if(ivl[cur][1] <= ivl[prv][1])
                prv = cur;
        } else {
            prv = cur;
        }
    }
    return ans;
}
```

This function removes the minimum number of intervals to make the remaining intervals non-overlapping by applying a greedy strategy after sorting.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declarations And Calls**
	```cpp
	int eraseOverlapIntervals(vector<vector<int>>& ivl) {
	```
	Defines the function to process a vector of intervals.

2. **Sorting**
	```cpp
	    sort(ivl.begin(), ivl.end());
	```
	Sorts the intervals based on their start times to simplify processing.

3. **Variable Initialization**
	```cpp
	    int ans = 0;
	```
	Initializes a counter for tracking the number of intervals to remove.

4. **Length Of Collection**
	```cpp
	    int n = ivl.size();
	```
	Stores the size of the intervals vector for iteration.

5. **Variable Initialization**
	```cpp
	    int prv = 0;
	```
	Tracks the index of the last non-overlapping interval.

6. **For Loops**
	```cpp
	    for(int cur = 1; cur < n; cur++) {
	```
	Iterates over the intervals starting from the second one.

7. **Conditional Checks**
	```cpp
	        if(ivl[cur][0] < ivl[prv][1]) {
	```
	Checks if the current interval overlaps with the previous one.

8. **Increment**
	```cpp
	            ans++;
	```
	Increments the removal counter for overlapping intervals.

9. **Conditional Checks**
	```cpp
	            if(ivl[cur][1] <= ivl[prv][1])
	```
	Updates the reference to the current interval if it ends earlier.

10. **Assignment**
	```cpp
	                prv = cur;
	```
	Assigns the current interval index as the reference.

11. **Else Condition**
	```cpp
	        } else {
	```
	Handles the case where intervals do not overlap.

12. **Assignment**
	```cpp
	            prv = cur;
	```
	Updates the reference to the current non-overlapping interval.

13. **Return At End**
	```cpp
	    return ans;
	```
	Returns the total number of intervals removed.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(N log N), where N is the number of intervals, due to the sorting step.
- **Average Case:** O(N log N), due to the sorting step.
- **Worst Case:** O(N log N), where N is the number of intervals, due to the sorting step.

The main time complexity comes from sorting the intervals, and the subsequent iteration is O(N).

### Space Complexity 💾
- **Best Case:** O(N), for the space needed to store the intervals.
- **Worst Case:** O(N), where N is the number of intervals, to store the sorted intervals.

The space complexity is O(N) due to storing the intervals in memory and potentially the sorting operation.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/non-overlapping-intervals/description/)

---
{{< youtube mHsj83NoZDA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

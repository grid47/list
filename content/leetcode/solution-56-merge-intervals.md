
+++
authors = ["grid47"]
title = "Leetcode 56: Merge Intervals"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 56: Merge Intervals in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/56.webp"
youtube = "HCbKvBOlMVI"
youtube_upload_date="2024-06-13"
youtube_thumbnail="https://i.ytimg.com/vi/HCbKvBOlMVI/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/56.webp" 
    alt="Multiple flowing light intervals coming together and merging in perfect harmony."
    caption="Solution to LeetCode 56: Merge Intervals Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given an array of intervals where each interval is represented by a pair [start, end]. Merge all overlapping intervals and return a list of non-overlapping intervals that cover all the input intervals.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is an array of intervals, where each interval is a pair [start, end].
- **Example:** `[[1,3],[2,6],[8,10],[15,18]]`
- **Constraints:**
	- 1 <= intervals.length <= 10^4
	- intervals[i].length == 2
	- 0 <= starti <= endi <= 10^4

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an array of intervals where each interval represents a non-overlapping range that covers all intervals in the input.
- **Example:** `[[1, 6], [8, 10], [15, 18]]`
- **Constraints:**
	- The output should contain only non-overlapping intervals.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to merge any overlapping intervals and return the merged intervals as the result.

- 1. Sort the intervals by their starting value.
- 2. Initialize a variable to store the merged intervals.
- 3. Traverse through the sorted intervals, and for each interval, check if it overlaps with the last merged interval.
- 4. If they overlap, merge the intervals by updating the end of the last merged interval. Otherwise, add the current interval to the result.
{{< dots >}}
### Problem Assumptions ✅
- The intervals are represented as pairs of integers, where each pair follows the rule: starti <= endi.
{{< dots >}}
## Examples 🧩
- **Input:** `[[1, 3], [2, 6], [8, 10], [15, 18]]`  \
  **Explanation:** The intervals [1, 3] and [2, 6] overlap, so they are merged into [1, 6]. The intervals [8, 10] and [15, 18] do not overlap and are returned as is.

- **Input:** `[[1, 4], [4, 5]]`  \
  **Explanation:** The intervals [1, 4] and [4, 5] overlap at index 4, so they are merged into [1, 5].

{{< dots >}}
## Approach 🚀
The approach involves sorting the intervals and then merging the overlapping ones iteratively.

### Initial Thoughts 💭
- Sorting the intervals is essential to efficiently merge overlapping ones.
- This problem can be solved using a greedy approach by merging overlapping intervals in a single pass after sorting.
{{< dots >}}
### Edge Cases 🌐
- If the input is an empty list, return an empty list.
- The algorithm should efficiently handle large inputs (up to 10^4 intervals).
- Intervals that touch at the boundary (e.g., [1, 4] and [4, 5]) should be merged.
- The solution must run in O(n log n) time due to the sorting step.
{{< dots >}}
## Code 💻
```cpp
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> merged; // To store the merged intervals
    merged.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); ++i) {
        if (merged.back()[1] >= intervals[i][0]) {
            // Overlapping intervals, merge them
            merged.back()[1] = max(merged.back()[1], intervals[i][1]);
        } else {
            // Non-overlapping interval, add it to the merged list
            merged.push_back(intervals[i]);
        }
    }

    return merged;
}
```

This code efficiently merges overlapping intervals in a given list of intervals.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
	```
	This line declares a function named `merge` that takes a vector of intervals `intervals` as input and returns a vector of merged intervals.

2. **Sorting Intervals**
	```cpp
	    sort(intervals.begin(), intervals.end());
	```
	This line sorts the input intervals based on their starting points in ascending order.

3. **Result Vector Initialization**
	```cpp
	    vector<vector<int>> merged;
	```
	This line initializes an empty vector `merged` to store the merged intervals.

4. **Initialize First Interval**
	```cpp
	    merged.push_back(intervals[0]);
	```
	This line adds the first interval from the input to the `merged` vector as a starting point.

5. **Iterate Over Intervals**
	```cpp
	    for (int i = 1; i < intervals.size(); ++i) {
	```
	This loop iterates over the intervals starting from the second interval.

6. **Check for Overlap**
	```cpp
	        if (merged.back()[1] >= intervals[i][0]) {
	```
	This condition checks if the current interval overlaps with the last interval in the `merged` vector. Overlap occurs if the end of the last interval is greater than or equal to the start of the current interval.

7. **Merge Overlapping Intervals**
	```cpp
	            merged.back()[1] = max(merged.back()[1], intervals[i][1]);
	```
	If there's an overlap, the end point of the last interval in `merged` is updated to the maximum of its current end point and the end point of the current interval. This effectively merges the two overlapping intervals.

8. **Add Non-Overlapping Interval**
	```cpp
	        } else {
	```
	If there's no overlap, the current interval is added to the `merged` vector as a new, non-overlapping interval.

9. **Add Current Interval to Merged List**
	```cpp
	            merged.push_back(intervals[i]);
	```
	The current interval is added to the `merged` vector.

10. **Return Merged Intervals**
	```cpp
	    return merged;
	```
	The function returns the `merged` vector containing the merged intervals.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The time complexity is O(n log n), where n is the number of intervals, due to the sorting step.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n), where n is the number of intervals, since we store the result in a separate array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/merge-intervals/description/)

---
{{< youtube HCbKvBOlMVI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

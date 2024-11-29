
+++
authors = ["grid47"]
title = "Leetcode 57: Insert Interval"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 57: Insert Interval in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/57.webp"
youtube = "A8NUOmlwOlM"
youtube_upload_date="2021-07-16"
youtube_thumbnail="https://i.ytimg.com/vi/A8NUOmlwOlM/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/57.webp" 
    alt="A glowing new interval gently being inserted into an existing flow of light."
    caption="Solution to LeetCode 57: Insert Interval Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given an array of non-overlapping intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval, and intervals are sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval. Insert newInterval into intervals such that intervals is still sorted and there are no overlapping intervals. Merge overlapping intervals if necessary and return the updated list of intervals.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array of intervals sorted by their starting values and a new interval to insert.
- **Example:** `[[2, 4], [6, 8]], newInterval = [5, 7]`
- **Constraints:**
	- 0 <= intervals.length <= 10^4
	- intervals[i].length == 2
	- 0 <= starti <= endi <= 10^5
	- intervals is sorted by starti in ascending order.
	- newInterval.length == 2
	- 0 <= start <= end <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a list of intervals after inserting the new interval and merging any overlapping intervals.
- **Example:** `[[2, 4], [5, 8]]`
- **Constraints:**
	- The list should be sorted by the starting values of the intervals.
	- All intervals in the list should be non-overlapping after the insertion.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to merge overlapping intervals after inserting the new interval into the list.

- 1. Iterate through the intervals and insert the new interval in the correct position based on its start value.
- 2. Merge the new interval with any overlapping intervals as needed.
- 3. Return the final list of intervals after the insertion.
{{< dots >}}
### Problem Assumptions ✅
- The input intervals are sorted by their start times.
- The new interval may overlap with multiple intervals.
{{< dots >}}
## Examples 🧩
- **Input:** `[[2, 4], [6, 8]], newInterval = [5, 7]`  \
  **Explanation:** In this case, the new interval overlaps with the interval [6, 8], so they are merged into [5, 8]. The result is [[2, 4], [5, 8]].

- **Input:** `[[1, 3], [5, 6], [8, 10]], newInterval = [4, 8]`  \
  **Explanation:** Here, the new interval [4, 8] overlaps with [5, 6] and [8, 10], and the merged interval becomes [4, 10]. The result is [[1, 3], [4, 10]].

{{< dots >}}
## Approach 🚀
The approach involves inserting the new interval and merging overlapping intervals using a two-pass approach.

### Initial Thoughts 💭
- Intervals are already sorted by their start time, which simplifies the insertion process.
- By iterating through the list of intervals, we can find where the new interval fits and merge it with any overlapping intervals.
{{< dots >}}
### Edge Cases 🌐
- If the input list is empty, the solution should return the new interval as the only interval.
- The algorithm should handle up to 10^4 intervals efficiently.
- If the new interval does not overlap with any existing intervals, it should be inserted in the correct position.
- The solution must run efficiently with a time complexity of O(n), where n is the number of intervals.
{{< dots >}}
## Code 💻
```cpp
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> merged;
    int i = 0;

    while (i < intervals.size() && intervals[i][1] < newInterval[0]) {
        merged.push_back(intervals[i++]);
    }

    while (i < intervals.size() && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = min(intervals[i][0], newInterval[0]);
        newInterval[1] = max(intervals[i][1], newInterval[1]);
        i++;
    }

    merged.push_back(newInterval);

    while (i < intervals.size()) {
        merged.push_back(intervals[i++]);
    }

    return merged;
}
```

This code efficiently inserts a new interval into a list of non-overlapping intervals, merging overlapping intervals as necessary.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
	```
	This line declares a function named `insert` that takes a vector of intervals `intervals` and a new interval `newInterval` as input and returns a vector of merged intervals.

2. **Result Vector Initialization**
	```cpp
	    vector<vector<int>> merged;
	```
	This line initializes an empty vector `merged` to store the merged intervals.

3. **Index Initialization**
	```cpp
	    int i = 0;
	```
	This line initializes an index `i` to 0, which will be used to iterate over the `intervals` vector.

4. **Iterate Over Non-Overlapping Intervals**
	```cpp
	    while (i < intervals.size() && intervals[i][1] < newInterval[0]) {
	```
	This loop iterates over the intervals in `intervals` as long as their end points are less than the start of the `newInterval`. These intervals don't overlap with `newInterval`, so they are added directly to the `merged` vector.

5. **Add Non-Overlapping Intervals**
	```cpp
	        merged.push_back(intervals[i++]);
	```
	The current interval `intervals[i]` is added to the `merged` vector, and the `i` index is incremented.

6. **Merge Overlapping Intervals**
	```cpp
	    while (i < intervals.size() && intervals[i][0] <= newInterval[1]) {
	```
	This loop iterates over the intervals that overlap with `newInterval`. The start of `newInterval` is updated to the minimum of its current start and the start of the current interval, and the end of `newInterval` is updated to the maximum of its current end and the end of the current interval. This effectively merges the overlapping intervals.

7. **Update New Interval**
	```cpp
	        newInterval[0] = min(intervals[i][0], newInterval[0]);
	        newInterval[1] = max(intervals[i][1], newInterval[1]);
	```
	The `newInterval` is updated to encompass the overlapping interval.

8. **Increment Index**
	```cpp
	        i++;
	```
	The `i` index is incremented to move to the next interval.

9. **Add Merged Interval**
	```cpp
	    merged.push_back(newInterval);
	```
	After processing the overlapping intervals, the merged `newInterval` is added to the `merged` vector.

10. **Add Remaining Intervals**
	```cpp
	    while (i < intervals.size()) {
	```
	This loop iterates over the remaining intervals that don't overlap with `newInterval` and adds them to the `merged` vector.

11. **Add Remaining Intervals**
	```cpp
	        merged.push_back(intervals[i++]);
	```
	The current interval `intervals[i]` is added to the `merged` vector, and the `i` index is incremented.

12. **Return Merged Intervals**
	```cpp
	    return merged;
	```
	The function returns the `merged` vector containing the final list of merged intervals.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because we iterate through the intervals once.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n), where n is the number of intervals, due to the need to store the result array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/insert-interval/description/)

---
{{< youtube A8NUOmlwOlM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

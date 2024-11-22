
+++
authors = ["grid47"]
title = "Leetcode 3169: Count Days Without Meetings"
date = "2023-12-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3169: Count Days Without Meetings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "72-mDiuXbLk"
youtube_upload_date="2024-06-02"
youtube_thumbnail="https://i.ytimg.com/vi/72-mDiuXbLk/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countDays(int days, vector<vector<int>>& mt) {
        int net = days;
        int n = mt.size();
        sort(mt.begin(), mt.end());
        vector<int> tuned;
        vector<int> pt = mt[0];
        if(n == 1) return net - (pt[1] - pt[0] + 1);
        for(int i = 1; i < n; i++) {
            if (mt[i][0] <= pt[1])
                pt[1] = max(pt[1], mt[i][1]);
            else {
                net -= pt[1] - pt[0] + 1;
                pt = mt[i];
            }
            if(i + 1 == n) net -= pt[1] - pt[0] + 1;
        }
        return net;
    }
};
{{< /highlight >}}
---

### Problem Statement

Given a list of intervals, each representing a range of days, and a total number of days, the task is to determine the number of days that are **not covered** by any of the intervals. Each interval represents a range of days where certain events happen. The intervals can overlap, and the goal is to calculate the number of days outside the coverage of these intervals.

### Approach

To solve this problem, we need to process the intervals, merge overlapping ones, and compute the number of uncovered days.

### Key Steps:

1. **Sort the Intervals**: We start by sorting the intervals by their start day. This helps in efficiently merging overlapping intervals.
  
2. **Track Covered and Uncovered Days**: As we process the intervals, we need to track the days that are covered by one or more intervals. If two intervals overlap, we merge them and continue to the next interval. If an interval doesn't overlap with the current one, we subtract the number of days covered by the previous interval from the total number of days.

3. **Final Calculation**: After processing all intervals, we subtract the total number of covered days from the total days available (`days`).

### Code Breakdown (Step by Step)

The function `countDays` computes the number of days not covered by any of the intervals.

```cpp
int countDays(int days, vector<vector<int>>& mt) {
    int net = days; // Start by assuming all days are uncovered.
    int n = mt.size(); // Number of intervals.

    // Sort intervals based on their start day.
    sort(mt.begin(), mt.end());

    vector<int> pt = mt[0]; // Track the current interval being processed.
    if (n == 1) return net - (pt[1] - pt[0] + 1); // If there's only one interval, return the uncovered days.

    for (int i = 1; i < n; i++) {
        // If the current interval overlaps with the previous, merge them.
        if (mt[i][0] <= pt[1]) {
            pt[1] = max(pt[1], mt[i][1]); // Extend the end of the merged interval.
        } else {
            // No overlap, subtract the covered days of the previous interval.
            net -= pt[1] - pt[0] + 1;
            pt = mt[i]; // Update to the current interval.
        }
        // If it's the last interval, subtract its covered days.
        if (i + 1 == n) net -= pt[1] - pt[0] + 1;
    }

    return net; // Return the total uncovered days.
}
```

### Detailed Breakdown of the Code:

1. **Initialization**:  
   ```cpp
   int net = days;
   int n = mt.size();
   ```
   - `net`: This variable tracks the total number of uncovered days, which initially equals the total number of days (`days`).
   - `n`: The number of intervals in the input vector `mt`.

2. **Sorting the Intervals**:  
   ```cpp
   sort(mt.begin(), mt.end());
   ```
   - We sort the intervals in ascending order of their start day. Sorting ensures that we can easily merge overlapping intervals in the subsequent steps.

3. **Handling Special Case (Single Interval)**:  
   ```cpp
   if (n == 1) return net - (pt[1] - pt[0] + 1);
   ```
   - If there is only one interval, we can directly compute the number of uncovered days by subtracting the length of that interval (`pt[1] - pt[0] + 1`) from the total number of days (`days`).

4. **Iterating Over the Intervals**:  
   ```cpp
   for (int i = 1; i < n; i++) {
       if (mt[i][0] <= pt[1]) {
           pt[1] = max(pt[1], mt[i][1]);
       } else {
           net -= pt[1] - pt[0] + 1;
           pt = mt[i];
       }
       if (i + 1 == n) net -= pt[1] - pt[0] + 1;
   }
   ```
   - **Merging Overlapping Intervals**: If the start of the current interval (`mt[i][0]`) is less than or equal to the end of the previous interval (`pt[1]`), it means the two intervals overlap. In this case, we extend the end of the current merged interval to cover the maximum end day between the two intervals.
   
   - **Handling Non-overlapping Intervals**: If the current interval does not overlap with the previous one, we subtract the length of the previous interval from the `net` (which tracks uncovered days). Then, we update the `pt` variable to the current interval, which becomes the new active interval.

5. **Final Adjustment**:  
   ```cpp
   if (i + 1 == n) net -= pt[1] - pt[0] + 1;
   ```
   - After processing all intervals, we check if we are at the last interval. If so, we subtract the number of days covered by this last interval from `net`.

6. **Return the Result**:  
   ```cpp
   return net;
   ```
   - Finally, we return the `net` value, which contains the number of uncovered days after processing all the intervals.

### Example Walkthrough

Let's walk through an example to better understand the code.

#### Input:
```cpp
int days = 10;
vector<vector<int>> mt = {{1, 3}, {2, 5}, {6, 8}};
```

- Total days (`days`) = 10.
- Intervals (`mt`) = `{{1, 3}, {2, 5}, {6, 8}}`.

#### Processing:
1. **Sort the intervals**:  
   After sorting, `mt = {{1, 3}, {2, 5}, {6, 8}}` remains unchanged as it is already sorted.

2. **First Interval (`{1, 3}`)**:  
   - We initialize `pt = {1, 3}`.
   - Subtracting the length of this interval: `net = 10 - (3 - 1 + 1) = 6`.

3. **Second Interval (`{2, 5}`)**:  
   - The start of the current interval (2) is within the previous interval (ends at 3), so we merge the intervals.
   - Now, `pt = {1, 5}`.
   - No subtraction yet because the intervals are merged.

4. **Third Interval (`{6, 8}`)**:  
   - The start of the current interval (6) does not overlap with the merged interval (`{1, 5}`), so we subtract the length of the previous merged interval:  
   `net = 6 - (5 - 1 + 1) = 1`.
   - Now, `pt = {6, 8}`.

5. **Final Adjustment**:  
   - Subtracting the length of the last interval:  
   `net = 1 - (8 - 6 + 1) = 0`.

#### Output:
```cpp
0
```
The result is `0`, which means there are no uncovered days.

### Complexity

#### Time Complexity:
- **O(n log n)**: Sorting the intervals takes **O(n log n)** time, where `n` is the number of intervals. The iteration through the intervals after sorting takes **O(n)** time. Hence, the overall time complexity is dominated by the sorting step, resulting in **O(n log n)**.

#### Space Complexity:
- **O(n)**: The space complexity is **O(n)** due to the space used by the `mt` vector and additional variables used for storing the intervals and tracking the covered days.

### Conclusion

The solution efficiently calculates the number of uncovered days by sorting the intervals, merging overlapping intervals, and subtracting the covered days from the total days. The algorithm runs in **O(n log n)** time, making it optimal for large inputs. The space complexity is **O(n)**, which is also efficient given the problem constraints.

[`Link to LeetCode Lab`](https://leetcode.com/problems/count-days-without-meetings/description/)

---
{{< youtube 72-mDiuXbLk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |


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
comments = true
+++



---
You are given a positive integer `days` representing the total number of days an employee is available for work (starting from day 1). Additionally, you are given a 2D array `meetings`, where `meetings[i] = [start_i, end_i]` represents the start and end days (inclusive) of the ith meeting. Your task is to determine the number of days when the employee is available for work, but no meetings are scheduled.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer `days`, representing the total number of days the employee is available for work, and a 2D array `meetings` where each element contains two integers, `start_i` and `end_i`, representing the start and end days of each meeting.
- **Example:** `Example 1:
Input: days = 10, meetings = [[5,7],[1,3],[9,10]]
Output: 2
Explanation: The employee has no meetings scheduled on days 4 and 8.`
- **Constraints:**
	- 1 <= days <= 10^9
	- 1 <= meetings.length <= 10^5
	- 1 <= meetings[i][0] <= meetings[i][1] <= days

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an integer representing the number of days the employee is available for work, with no meetings scheduled.
- **Example:** `Example 1:
Input: days = 10, meetings = [[5,7],[1,3],[9,10]]
Output: 2`
- **Constraints:**
	- The output will be a non-negative integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to calculate the number of days where the employee is available for work, excluding the days with scheduled meetings.

- Sort the meeting intervals based on the start day.
- Iterate through the meetings and merge overlapping or adjacent meetings.
- Calculate the total number of days occupied by meetings.
- Subtract the total number of days occupied by meetings from the total available days to find the number of days the employee is free.
{{< dots >}}
### Problem Assumptions ✅
- The meetings may overlap, so they need to be merged.
- The meetings are scheduled between day 1 and the given number of days.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1:`  \
  **Explanation:** For `days = 10` and `meetings = [[5,7], [1,3], [9,10]]`, after merging the meetings, the days occupied are from day 1 to day 3 and day 5 to day 7, and day 9 to day 10. The employee is available on days 4 and 8, so the output is 2.

- **Input:** `Example 2:`  \
  **Explanation:** For `days = 5` and `meetings = [[2,4], [1,3]]`, after merging the meetings, the days occupied are from day 1 to day 4. The employee is available on day 5, so the output is 1.

- **Input:** `Example 3:`  \
  **Explanation:** For `days = 6` and `meetings = [[1,6]]`, the meeting occupies all 6 days. Therefore, the employee is not available on any day, so the output is 0.

{{< dots >}}
## Approach 🚀
We need to calculate the total number of days the employee is free by finding out the days that are not covered by any meetings. To do this, we first merge overlapping or adjacent meetings and then subtract the occupied days from the total available days.

### Initial Thoughts 💭
- We need to efficiently merge overlapping meetings and then calculate the free days.
- Sorting the meetings and merging overlapping ones will allow us to calculate the total number of occupied days. Subtracting that from the total available days will give us the answer.
{{< dots >}}
### Edge Cases 🌐
- There are no edge cases related to empty inputs as the number of meetings is always at least 1.
- For large inputs, ensure that the sorting and merging of meetings is efficient to handle up to 10^5 meetings.
- When all days are occupied by meetings, the result should be 0.
- The solution should efficiently handle large inputs, with up to 10^5 meetings.
{{< dots >}}
## Code 💻
```cpp
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
```

This function calculates the number of days left after subtracting days covered by intervals. Each interval represents a period of time, and the function handles overlaps by adjusting the count of days accordingly.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int countDays(int days, vector<vector<int>>& mt) {
	```
	Defines the function 'countDays' that takes an integer 'days' representing the total number of days and a vector of vectors 'mt' representing time intervals, and returns the adjusted number of days.

2. **Variable Initialization**
	```cpp
	    int net = days;
	```
	Initializes the variable 'net' with the value of 'days', which will later hold the result after subtracting the number of days covered by the intervals.

3. **Vector Size Calculation**
	```cpp
	    int n = mt.size();
	```
	Calculates the number of intervals in the input vector 'mt' and stores it in 'n'.

4. **Sorting Intervals**
	```cpp
	    sort(mt.begin(), mt.end());
	```
	Sorts the intervals in 'mt' based on the start time, ensuring that overlapping intervals are processed in the correct order.

5. **Vector Initialization**
	```cpp
	    vector<int> tuned;
	```
	Initializes an empty vector 'tuned', though it is not used in the subsequent code and can likely be removed.

6. **Initial Interval Setup**
	```cpp
	    vector<int> pt = mt[0];
	```
	Sets the first interval as the starting reference point 'pt' for the comparisons in the following steps.

7. **Single Interval Case**
	```cpp
	    if(n == 1) return net - (pt[1] - pt[0] + 1);
	```
	Handles the special case where there is only one interval, subtracting the length of that interval from 'net' to account for covered days.

8. **For Loop**
	```cpp
	    for(int i = 1; i < n; i++) {
	```
	Begins a loop that iterates through the remaining intervals (starting from index 1) to check for overlaps.

9. **Overlap Check**
	```cpp
	        if (mt[i][0] <= pt[1])
	```
	Checks if the start time of the current interval (mt[i][0]) overlaps with the end time of the previous interval (pt[1]).

10. **Update Interval**
	```cpp
	            pt[1] = max(pt[1], mt[i][1]);
	```
	If the intervals overlap, extends the 'pt' interval by updating the end time to the maximum of the current end time and the new interval's end time.

11. **Non-Overlapping Interval**
	```cpp
	        else {
	```
	Handles the case where the current interval does not overlap with the previous one.

12. **Subtract Covered Days**
	```cpp
	            net -= pt[1] - pt[0] + 1;
	```
	Subtracts the number of days covered by the current 'pt' interval from 'net' to account for the covered time.

13. **Update Reference Interval**
	```cpp
	            pt = mt[i];
	```
	Sets 'pt' to the current interval 'mt[i]' to continue processing.

14. **Final Adjustment**
	```cpp
	        if(i + 1 == n) net -= pt[1] - pt[0] + 1;
	```
	At the end of the loop, subtracts the number of days covered by the last interval from 'net', as the loop may not account for it.

15. **Return Result**
	```cpp
	    return net;
	```
	Returns the final value of 'net', which represents the remaining number of uncovered days after adjusting for all the intervals.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The time complexity is O(n log n) due to sorting the meetings.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n) for storing the meetings and the merged intervals.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/count-days-without-meetings/description/)

---
{{< youtube 72-mDiuXbLk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |


+++
authors = ["grid47"]
title = "Leetcode 539: Minimum Time Difference"
date = "2024-09-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 539: Minimum Time Difference in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","String","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/539.webp"
youtube = "LVBDzeUmNIQ"
youtube_upload_date="2024-09-16"
youtube_thumbnail="https://i.ytimg.com/vi/LVBDzeUmNIQ/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/539.webp" 
    alt="A series of times, with the minimum time difference glowing softly between the times."
    caption="Solution to LeetCode 539: Minimum Time Difference Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given a list of time points in 'HH:MM' format, return the minimum time difference between any two distinct time points in the list.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a list of time points in 'HH:MM' format.
- **Example:** `Input: timePoints = ['23:58', '00:05']`
- **Constraints:**
	- 2 <= timePoints.length <= 2 * 10^4
	- timePoints[i] is in 'HH:MM' format

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum time difference between any two time points in minutes.
- **Example:** `Output: 7`
- **Constraints:**
	- The returned value is the smallest time difference between any two distinct time points in the list.

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the minimum time difference between any two distinct time points in the list.

- Sort the list of time points in ascending order.
- Calculate the differences between consecutive time points.
- Also calculate the difference between the first and last time points, as the time range is circular.
- Return the minimum of all differences.
{{< dots >}}
### Problem Assumptions ✅
- The input list contains at least two time points.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: timePoints = ['23:58', '00:05']`  \
  **Explanation:** The minimum time difference between 23:58 and 00:05 is 7 minutes.

{{< dots >}}
## Approach 🚀
To solve this problem, we need to find the minimum difference in minutes between two time points in the list. Sorting the time points makes it easier to calculate the differences between consecutive points and handle the circular nature of the 24-hour clock.

### Initial Thoughts 💭
- Sorting the list of time points allows us to compare consecutive points to find the minimum difference.
- We must also consider the circular nature of the clock, where the earliest time and the latest time might have the smallest difference.
{{< dots >}}
### Edge Cases 🌐
- The input list will always contain at least two time points, so there are no empty inputs.
- Ensure that the solution efficiently handles lists with up to 2 * 10^4 time points.
- Handle time points close to midnight (e.g., '23:59' and '00:00').
- The input list contains valid time points in 'HH:MM' format.
{{< dots >}}
## Code 💻
```cpp
int findMinDifference(vector<string>& time) {
    
    sort(time.begin(), time.end());
    
    int n = time.size(), mindiff = INT_MAX;
    
    for(int i = 0; i < n; i++) {
        
        int diff = abs(timeDiff(time[(i - 1 +n)%n], time[i]));
        
        diff = min(diff, 1440 - diff); // 1440 = 24h in minutes
        mindiff = min(mindiff, diff);
    }
    
    return mindiff;
}

int timeDiff(string t1, string t2) {
    // cout << t1 << t2;
    int h1 = stoi(t1.substr(0, 2));
    int m1 = stoi(t1.substr(3, 2));
    int h2 = stoi(t2.substr(0, 2));
    int m2 = stoi(t2.substr(3, 2));
    return (h2 - h1) * 60 + (m2 - m1);
}
```

This code computes the minimum difference in minutes between any two times from a list of time strings. It sorts the times and calculates the minimum time difference in a circular manner, using 1440 (the total number of minutes in a day) to account for the wrap-around difference.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int findMinDifference(vector<string>& time) {
	```
	Defines the `findMinDifference` function which takes a vector of time strings as input and returns the minimum difference between any two times in minutes.

2. **Sort Operation**
	```cpp
	    sort(time.begin(), time.end());
	```
	Sorts the time strings in lexicographical order, ensuring that time differences are calculated in a sequential manner.

3. **Variable Initialization**
	```cpp
	    int n = time.size(), mindiff = INT_MAX;
	```
	Initializes variables: `n` holds the size of the `time` vector, and `mindiff` is set to the maximum integer value to track the minimum difference.

4. **Loop**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Begins a loop that iterates over all time strings, comparing adjacent times to calculate their differences.

5. **Time Difference Calculation**
	```cpp
	        int diff = abs(timeDiff(time[(i - 1 +n)%n], time[i]));
	```
	Calculates the absolute time difference between the current time and the previous time (using modulo for circular indexing).

6. **Min Time Difference Adjustment**
	```cpp
	        diff = min(diff, 1440 - diff); // 1440 = 24h in minutes
	```
	Adjusts the time difference to account for the wrap-around of the day, ensuring that the minimum difference is correctly calculated, even across midnight.

7. **Min Difference Update**
	```cpp
	        mindiff = min(mindiff, diff);
	```
	Updates the `mindiff` variable to store the smallest time difference encountered during the loop.

8. **Return Statement**
	```cpp
	    return mindiff;
	```
	Returns the minimum time difference found during the loop.

9. **Helper Function Definition**
	```cpp
	int timeDiff(string t1, string t2) {
	```
	Defines the helper function `timeDiff`, which calculates the time difference in minutes between two time strings.

10. **Time Parsing**
	```cpp
	    int h1 = stoi(t1.substr(0, 2));
	```
	Extracts the hour component from the first time string `t1` and converts it to an integer.

11. **Time Parsing**
	```cpp
	    int m1 = stoi(t1.substr(3, 2));
	```
	Extracts the minute component from the first time string `t1` and converts it to an integer.

12. **Time Parsing**
	```cpp
	    int h2 = stoi(t2.substr(0, 2));
	```
	Extracts the hour component from the second time string `t2` and converts it to an integer.

13. **Time Parsing**
	```cpp
	    int m2 = stoi(t2.substr(3, 2));
	```
	Extracts the minute component from the second time string `t2` and converts it to an integer.

14. **Time Difference Calculation**
	```cpp
	    return (h2 - h1) * 60 + (m2 - m1);
	```
	Calculates and returns the time difference in minutes between the two time strings `t1` and `t2`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The time complexity is O(n log n) due to the sorting step, where n is the number of time points.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage required for the sorted list of time points.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-time-difference/description/)

---
{{< youtube LVBDzeUmNIQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

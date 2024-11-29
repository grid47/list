
+++
authors = ["grid47"]
title = "Leetcode 2446: Determine if Two Events Have Conflict"
date = "2024-03-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2446: Determine if Two Events Have Conflict in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "mahSMDuJL9A"
youtube_upload_date="2022-10-23"
youtube_thumbnail="https://i.ytimg.com/vi_webp/mahSMDuJL9A/maxresdefault.webp"
comments = true
+++



---
Given two events, each with a start time and end time in the HH:MM format, determine if the two events overlap at any point in time. Return `true` if there is any overlap, otherwise return `false`.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** Each input consists of two arrays, `event1` and `event2`. Both arrays have two string elements representing the start and end times of the respective events.
- **Example:** `event1 = ["09:00","10:00"], event2 = ["09:30","11:00"]`
- **Constraints:**
	- event1.length == event2.length == 2
	- event1[i].length == event2[i].length == 5
	- startTime <= endTime

{{< dots >}}
### Output Specifications 📤
- **Output:** Return `true` if there is a conflict, meaning the two events overlap in time. Otherwise, return `false`.
- **Example:** `Output: true`
- **Constraints:**
	- Both input arrays are guaranteed to have exactly two elements each, representing valid time intervals.

{{< dots >}}
### Core Logic 🔍
**Goal:** Determine if there is an overlap between two time intervals.

- 1. Compare the start and end times of both events.
- 2. If the start time of the second event is before or at the end time of the first event, and the end time of the second event is after or at the start time of the first event, then the events overlap.
{{< dots >}}
### Problem Assumptions ✅
- The events are within the same day, and the times are given in valid 24-hour format.
{{< dots >}}
## Examples 🧩
- **Input:** `event1 = ["01:00","02:00"], event2 = ["01:30","03:00"]`  \
  **Explanation:** The events overlap from 01:30 to 02:00, so the answer is `true`.

- **Input:** `event1 = ["12:00","13:00"], event2 = ["14:00","15:00"]`  \
  **Explanation:** The events do not overlap, so the answer is `false`.

{{< dots >}}
## Approach 🚀
The approach involves comparing the time intervals of both events to check if there is any overlap.

### Initial Thoughts 💭
- If the start time of one event is before or at the end time of the other event, and the end time is after or at the start of the other event, the two events overlap.
- This problem can be solved with simple comparisons of the start and end times of the two events.
{{< dots >}}
### Edge Cases 🌐
- Input will not contain empty arrays as per the problem constraints.
- Event times are always within the valid 24-hour range, so we don't need to worry about very large numbers.
- When the start time and end time of both events are the same, the events will overlap, and the result should be `true`.
- The time format is always valid, so no need for further validation.
{{< dots >}}
## Code 💻
```cpp
bool haveConflict(vector<string>& event1, vector<string>& event2) {
    if(event2[0] <= event1[1] && event2[1] >= event1[0]) return true;
    return false;
}
```

This code defines a function `haveConflict` which checks if two events conflict by comparing their start and end times.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool haveConflict(vector<string>& event1, vector<string>& event2) {
	```
	This line defines the function `haveConflict` that takes two arguments, `event1` and `event2`, each representing a range of event start and end times.

2. **Conditional Check**
	```cpp
	    if(event2[0] <= event1[1] && event2[1] >= event1[0]) return true;
	```
	This condition checks if the start time of `event2` is before or at the end time of `event1`, and if the end time of `event2` is after or at the start time of `event1`. If both conditions are true, it indicates a conflict.

3. **Return Statement**
	```cpp
	    return false;
	```
	If no conflict is found, the function returns `false`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(1)
- **Worst Case:** O(1)

The time complexity is constant as we only need to compare the two time intervals.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant as we do not use additional data structures that grow with the input.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/determine-if-two-events-have-conflict/description/)

---
{{< youtube mahSMDuJL9A >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

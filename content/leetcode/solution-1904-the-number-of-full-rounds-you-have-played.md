
+++
authors = ["grid47"]
title = "Leetcode 1904: The Number of Full Rounds You Have Played"
date = "2024-04-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1904: The Number of Full Rounds You Have Played in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "kwvB82HHvoQ"
youtube_upload_date="2021-06-20"
youtube_thumbnail="https://i.ytimg.com/vi/kwvB82HHvoQ/maxresdefault.jpg"
comments = true
+++



---
You are participating in an online chess tournament where rounds start every 15 minutes, starting at 00:00. You are given two times: `loginTime` and `logoutTime`. Your task is to calculate the number of full rounds you have participated in during the period from `loginTime` to `logoutTime`.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** Two strings: `loginTime` and `logoutTime` representing the times when you log in and log out respectively.
- **Example:** `loginTime = "08:25", logoutTime = "09:05"`
- **Constraints:**
	- loginTime and logoutTime are in the format hh:mm.
	- 00 <= hh <= 23
	- 00 <= mm <= 59
	- loginTime and logoutTime are not equal.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of full chess rounds you have participated in during the given time window.
- **Example:** `1`
- **Constraints:**
	- The result is an integer representing the count of full rounds played.

{{< dots >}}
### Core Logic 🔍
**Goal:** Calculate the number of full chess rounds you have played between `loginTime` and `logoutTime`.

- Convert `loginTime` and `logoutTime` to minutes from 00:00.
- If `logoutTime` is earlier than `loginTime`, split the time into two parts: from `loginTime` to midnight, and from midnight to `logoutTime`.
- Count the full rounds (each lasting 15 minutes) in both parts of the time window.
{{< dots >}}
### Problem Assumptions ✅
- The input times are in the 24-hour format with no leading zeros in the time parts.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: loginTime = "22:50", logoutTime = "01:30"`  \
  **Explanation:** You played 1 full round from 22:50 to 23:00, and 5 full rounds from 00:00 to 01:30. Total = 6 full rounds.

{{< dots >}}
## Approach 🚀
We need to calculate the number of full rounds by breaking down the time window into multiple 15-minute intervals. We handle the case where the login and logout times span across midnight.

### Initial Thoughts 💭
- The rounds start every 15 minutes, so checking for full rounds involves dividing the time window into intervals of 15 minutes.
- By converting the time to minutes and iterating through the intervals, we can efficiently count full rounds.
{{< dots >}}
### Edge Cases 🌐
- Input times cannot be empty, as the constraints ensure they are always valid strings.
- The solution should efficiently handle the maximum number of rounds, even if `loginTime` and `logoutTime` span across the entire day.
- Handle the scenario where `logoutTime` is earlier than `loginTime` by splitting the time window across midnight.
- Ensure that input values are within the range 00:00 to 23:59.
{{< dots >}}
## Code 💻
```cpp
int numberOfRounds(string login, string logout) {
    
    int in = (((login[0] - '0') * 10 + (login[1]- '0')) * 60) + ((login[3] - '0') * 10 + (login[4] - '0'));
    int out = (((logout[0] - '0') * 10 + (logout[1]- '0')) * 60) + ((logout[3] - '0') * 10 + (logout[4] - '0'));
    // cout << in << " " << out;
    int cnt = 0;
    if(in > out) {
        for(int i = 0; i < 24 * 60; i += 15) {
            if(i + 15 <= out || i >= in) cnt++;
        }
        return cnt;
    }

    for(int i = 0; i < 24 * 60; i += 15) {
        // cout << "\n" << i; 
        if(i >= in && (i + 15) <= out) cnt++;
    }
    return cnt;
    
    
}
```

This function calculates the number of 15-minute intervals that overlap between two given times represented by the `login` and `logout` strings.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int numberOfRounds(string login, string logout) {
	```
	The function definition starts here. It takes two string parameters `login` and `logout`, representing the login and logout times in HH:MM format.

2. **Login Time Calculation**
	```cpp
	    int in = (((login[0] - '0') * 10 + (login[1]- '0')) * 60) + ((login[3] - '0') * 10 + (login[4] - '0'));
	```
	This line calculates the `in` time by converting the `login` string (HH:MM) to the number of minutes from midnight.

3. **Logout Time Calculation**
	```cpp
	    int out = (((logout[0] - '0') * 10 + (logout[1]- '0')) * 60) + ((logout[3] - '0') * 10 + (logout[4] - '0'));
	```
	This line calculates the `out` time by converting the `logout` string (HH:MM) to the number of minutes from midnight.

4. **Variable Initialization**
	```cpp
	    int cnt = 0;
	```
	This line initializes a counter `cnt` to 0, which will track the number of overlapping 15-minute intervals.

5. **Conditional Check**
	```cpp
	    if(in > out) {
	```
	This condition checks if the `in` time is greater than the `out` time, which could happen if the login time is after midnight, indicating a new day.

6. **For Loop (Overlapping Time Calculation)**
	```cpp
	        for(int i = 0; i < 24 * 60; i += 15) {
	```
	This for loop iterates through all possible 15-minute intervals in a day (from 0 to 1440 minutes).

7. **Interval Check**
	```cpp
	            if(i + 15 <= out || i >= in) cnt++;
	```
	This checks if the current 15-minute interval overlaps with the given time range, and increments the counter `cnt`.

8. **Return Value (Condition True)**
	```cpp
	        return cnt;
	```
	If the `in` time is greater than the `out` time, return the number of intervals counted so far.

9. **For Loop (Overlapping Time Calculation)**
	```cpp
	    for(int i = 0; i < 24 * 60; i += 15) {
	```
	This for loop iterates through all possible 15-minute intervals in a day (from 0 to 1440 minutes).

10. **Interval Check**
	```cpp
	        if(i >= in && (i + 15) <= out) cnt++;
	```
	This checks if the current 15-minute interval is fully within the `in` and `out` times and increments the counter `cnt`.

11. **Return Value (Else Block)**
	```cpp
	    return cnt;
	```
	If the `in` time is less than or equal to the `out` time, return the number of intervals counted so far.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity depends on how many rounds are counted, which is proportional to the number of 15-minute intervals in a 24-hour period (96 intervals).

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant, as we only use a few variables to store the start and end times and the count of rounds.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/the-number-of-full-rounds-you-have-played/description/)

---
{{< youtube kwvB82HHvoQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

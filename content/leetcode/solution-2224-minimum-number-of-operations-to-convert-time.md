
+++
authors = ["grid47"]
title = "Leetcode 2224: Minimum Number of Operations to Convert Time"
date = "2024-03-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2224: Minimum Number of Operations to Convert Time in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Greedy"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "N_iV4VXnq6g"
youtube_upload_date="2022-04-03"
youtube_thumbnail="https://i.ytimg.com/vi_webp/N_iV4VXnq6g/maxresdefault.webp"
comments = true
+++



---
You are given two 24-hour formatted times, `current` and `correct`. Each time is represented in the format 'HH:MM', where HH is the hour (00 to 23) and MM is the minutes (00 to 59). In one operation, you can increase the current time by 1, 5, 15, or 60 minutes. Your task is to determine the minimum number of operations required to convert the `current` time to the `correct` time.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given two strings `current` and `correct`, both in the format 'HH:MM', where the time is represented as a 24-hour clock.
- **Example:** `current = '08:30', correct = '09:20'`
- **Constraints:**
	- current and correct are in the format 'HH:MM'
	- current <= correct

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of operations needed to convert the `current` time to the `correct` time.
- **Example:** `Output: 2`
- **Constraints:**
	- The input strings `current` and `correct` will always be valid 24-hour time strings.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to calculate the difference in minutes between `current` and `correct`, then apply the largest operations first (60 minutes, 15 minutes, 5 minutes, and 1 minute) to minimize the number of operations.

- Convert the current and correct times to minutes.
- Calculate the difference between the two times in minutes.
- Iterate over the available operations (60, 15, 5, and 1 minute) to minimize the number of operations.
{{< dots >}}
### Problem Assumptions ✅
- The time difference will always be positive or zero.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: current = '08:30', correct = '09:20'`  \
  **Explanation:** The difference is 50 minutes. We can first add 60 minutes (to make it 09:30), and then subtract 10 minutes to reach 09:20. This requires 2 operations.

- **Input:** `Input: current = '06:10', correct = '07:05'`  \
  **Explanation:** The difference is 55 minutes. First, add 60 minutes (to make it 07:10), then subtract 5 minutes to reach 07:05. This requires 2 operations.

{{< dots >}}
## Approach 🚀
The approach involves converting both times into minutes, finding the difference, and applying the largest possible operations to minimize the number of steps required.

### Initial Thoughts 💭
- The time difference is key to solving this problem.
- Using the largest increments (60 minutes) first can quickly reduce the time difference.
{{< dots >}}
### Edge Cases 🌐
- The input is guaranteed to be valid and will always contain two time strings.
- The time difference between `current` and `correct` is manageable, as no time will exceed 1440 minutes (24 hours).
- When `current` is equal to `correct`, the output should be 0 operations.
- current <= correct.
{{< dots >}}
## Code 💻
```cpp
class Solution {
int getTime(string &s) {
    return stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3));
}
public:
int convertTime(string current, string correct) {
    int diff = getTime(correct) - getTime(current), ops[4] = {60,15,5,1}, ans = 0;
    for (int op : ops) {
        ans += diff / op;
        diff %= op;
    }
    return ans;
}
```

This code defines a solution class with a method `convertTime`, which calculates the number of operations required to convert one time string to another, using operations of 60, 15, 5, and 1 minute.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Class Declaration**
	```cpp
	class Solution {
	```
	This is the declaration of the class `Solution`, which contains the methods to solve the problem.

2. **Function Declaration**
	```cpp
	int getTime(string &s) {
	```
	The function `getTime` is defined to convert a time string `s` into an integer representing the total minutes.

3. **Return Statement**
	```cpp
	    return stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3));
	```
	This line of code converts the given time string `s` (in HH:MM format) into total minutes by extracting the hours and minutes separately.

4. **Access Modifier**
	```cpp
	public:
	```
	This marks the beginning of the public section, where methods accessible outside the class will be defined.

5. **Function Declaration**
	```cpp
	int convertTime(string current, string correct) {
	```
	The `convertTime` function is defined, which takes two time strings, `current` and `correct`, and calculates the number of operations to convert one into the other.

6. **Variable Initialization**
	```cpp
	    int diff = getTime(correct) - getTime(current), ops[4] = {60,15,5,1}, ans = 0;
	```
	The difference in minutes between the correct and current times is calculated. The array `ops` contains the available operation durations (60, 15, 5, and 1 minute). The variable `ans` is initialized to 0 to keep track of the number of operations.

7. **Loop**
	```cpp
	    for (int op : ops) {
	```
	A for loop iterates over each operation in `ops` to calculate how many times each operation can be performed.

8. **Update Answer**
	```cpp
	        ans += diff / op;
	```
	For each operation `op`, the number of times it can be applied is added to `ans`, and the difference `diff` is reduced accordingly.

9. **Update Difference**
	```cpp
	        diff %= op;
	```
	After performing the division, the remainder (`diff`) is updated to reflect the remaining time that couldn't be covered by the current operation.

10. **Return Statement**
	```cpp
	    return ans;
	```
	The function returns the total number of operations needed to convert the `current` time to the `correct` time.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1), as only a constant number of operations are needed regardless of the time difference.
- **Average Case:** O(1), since the number of available operations is fixed.
- **Worst Case:** O(1), the operations do not depend on the size of the input times.

The time complexity is constant because the solution always involves a fixed number of operations.

### Space Complexity 💾
- **Best Case:** O(1), as no additional space is required.
- **Worst Case:** O(1), since only a few variables are used.

The space complexity is constant since the solution only uses a few variables.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-number-of-operations-to-convert-time/description/)

---
{{< youtube N_iV4VXnq6g >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

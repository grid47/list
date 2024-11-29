
+++
authors = ["grid47"]
title = "Leetcode 1344: Angle Between Hands of a Clock"
date = "2024-06-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1344: Angle Between Hands of a Clock in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "evs3Po8Km7c"
youtube_upload_date="2020-07-15"
youtube_thumbnail="https://i.ytimg.com/vi/evs3Po8Km7c/maxresdefault.jpg"
comments = true
+++



---
Given an hour and minute value, return the smaller angle (in degrees) formed between the hour and minute hands of a clock.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two integers representing the hour (1 to 12) and the minute (0 to 59).
- **Example:** `hour = 6, minutes = 45`
- **Constraints:**
	- 1 <= hour <= 12
	- 0 <= minutes <= 59

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the smaller angle in degrees between the hour and minute hands of a clock.
- **Example:** `For hour = 6, minutes = 45, the output will be 22.5.`
- **Constraints:**
	- The answer should be within 10^-5 of the actual value.

{{< dots >}}
### Core Logic 🔍
**Goal:** Calculate the angle between the hour and minute hands of a clock and return the smaller angle.

- 1. Calculate the angle of the minute hand based on the number of minutes.
- 2. Calculate the angle of the hour hand, adjusting for the current minute.
- 3. Find the absolute difference between the two angles.
- 4. Return the smaller angle (either the absolute difference or 360 - difference).
{{< dots >}}
### Problem Assumptions ✅
- The given time values are always valid.
- The hour value is always between 1 and 12, and the minute value is between 0 and 59.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: hour = 6, minutes = 45`  \
  **Explanation:** At 6:45, the minute hand is at the 9th hour mark, and the hour hand is at 6:45, creating an angle of 22.5 degrees.

- **Input:** `Example 2: hour = 9, minutes = 15`  \
  **Explanation:** At 9:15, the minute hand is at the 3rd hour mark, and the hour hand is at 9:15, forming an angle of 52.5 degrees.

- **Input:** `Example 3: hour = 10, minutes = 0`  \
  **Explanation:** At 10:00, the angle between the two hands is exactly 60 degrees, as the minute hand is at 12 and the hour hand is at 10.

{{< dots >}}
## Approach 🚀
To find the smaller angle between the hour and minute hands, we calculate the positions of both hands and then compute the absolute difference between them.

### Initial Thoughts 💭
- The minute hand moves 6 degrees per minute, and the hour hand moves 30 degrees per hour, so we can use these values to calculate the angles.
- The key challenge is to adjust for the fact that the hour hand also moves as the minutes progress. This needs to be factored into the calculation.
{{< dots >}}
### Edge Cases 🌐
- There are no empty inputs since hour and minute are always valid values.
- There are no large inputs as the input values are bounded by 12 for the hour and 59 for the minutes.
- When minutes = 0, the angle between the hands will be a multiple of 30 degrees.
- Ensure that all calculations are performed correctly for boundary values like hour = 12 and minutes = 0.
{{< dots >}}
## Code 💻
```cpp
double angleClock(int h, int minutes) {
    
    double mn = 360 *(double)minutes/60;
    
    double hrs = 360 * ((double)(h == 12? 0: h) / 12) + 30* ((double)minutes/60);
    cout << mn << " " << hrs;
        
    return min(abs(mn - hrs), 360 - (abs(mn - hrs)));
}
```

This function calculates the smaller angle formed between the hour and minute hands of a clock at a given time `h` and `minutes`. It handles conversions to degrees and adjusts for edge cases like `h == 12`.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	double angleClock(int h, int minutes) {
	```
	Declares a function that calculates the angle between the hour and minute hands of a clock, given the hour and minute inputs.

2. **Minute Calculation**
	```cpp
	    double mn = 360 *(double)minutes/60;
	```
	Calculates the angle of the minute hand relative to the 12 o'clock position. Each minute represents 6 degrees.

3. **Hour Calculation**
	```cpp
	    double hrs = 360 * ((double)(h == 12? 0: h) / 12) + 30* ((double)minutes/60);
	```
	Calculates the angle of the hour hand, considering both the hour and fractional contribution of the minutes. Accounts for `h == 12` by resetting to 0.

4. **Angle Calculation**
	```cpp
	    return min(abs(mn - hrs), 360 - (abs(mn - hrs)));
	```
	Returns the smaller angle between the hour and minute hands by calculating both the direct and complementary angles.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(1)
- **Worst Case:** O(1)

The time complexity is constant since we only perform a few arithmetic operations.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant as we only need a few variables to store intermediate results.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/angle-between-hands-of-a-clock/description/)

---
{{< youtube evs3Po8Km7c >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

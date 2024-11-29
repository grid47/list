
+++
authors = ["grid47"]
title = "Leetcode 2651: Calculate Delayed Arrival Time"
date = "2024-02-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2651: Calculate Delayed Arrival Time in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "8a04uEm1FlE"
youtube_upload_date="2023-04-23"
youtube_thumbnail="https://i.ytimg.com/vi_webp/8a04uEm1FlE/maxresdefault.webp"
comments = true
+++



---
You are given two integers: 'arrivalTime', representing the scheduled arrival time of a train in hours (in 24-hour format), and 'delayedTime', representing the delay in hours. Your task is to compute the time at which the train will actually arrive at the station, taking into account the delay.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two integers: 'arrivalTime' (1 <= arrivalTime < 24) and 'delayedTime' (1 <= delayedTime <= 24).
- **Example:** `arrivalTime = 9, delayedTime = 4`
- **Constraints:**
	- 1 <= arrivalTime < 24
	- 1 <= delayedTime <= 24

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the time at which the train will arrive at the station, which can be in 24-hour format.
- **Example:** `Output: 13`
- **Constraints:**
	- The result will be an integer between 0 and 23 (inclusive).

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to compute the new arrival time after adding the delay to the given arrival time. The result should be returned in 24-hour format.

- Step 1: Add the 'delayedTime' to the 'arrivalTime'.
- Step 2: If the sum exceeds 24 hours, subtract 24 to wrap around the time in 24-hour format.
- Step 3: Return the final computed arrival time.
{{< dots >}}
### Problem Assumptions ✅
- The input values for 'arrivalTime' and 'delayedTime' are valid integers within the given constraints.
- The result is expected in 24-hour format.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: arrivalTime = 9, delayedTime = 4`  \
  **Explanation:** The scheduled arrival time is 9:00 hours. Adding a delay of 4 hours gives us 13:00 hours, so the output will be 13.

- **Input:** `Input: arrivalTime = 20, delayedTime = 7`  \
  **Explanation:** The scheduled arrival time is 20:00 hours. Adding a delay of 7 hours gives us 27:00, which, when wrapped around in 24-hour format, becomes 3:00 hours. So the output will be 3.

{{< dots >}}
## Approach 🚀
The approach is simple: Add the delay to the arrival time and handle wrapping around the 24-hour format using modulo operation.

### Initial Thoughts 💭
- We need to account for the fact that the time can exceed 24 hours and needs to be wrapped around.
- We can use the modulo operator to handle the wrapping around of time, ensuring the result stays within 0-23 hours.
{{< dots >}}
### Edge Cases 🌐
- There are no empty inputs as per the problem's constraints.
- Ensure the solution works efficiently when delayedTime equals the upper constraint of 24 hours.
- Consider the edge case where arrivalTime is near midnight (e.g., 23:00) and the delay pushes the time to the next day.
- The time values must always remain within the valid 24-hour format.
{{< dots >}}
## Code 💻
```cpp
int findDelayedArrivalTime(int at, int dt) {
    return (at + dt) % 24;
}
```

This function calculates the delayed arrival time, adjusting for a 24-hour time format.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int findDelayedArrivalTime(int at, int dt) {
	```
	This line defines the function 'findDelayedArrivalTime', which takes two integer parameters: 'at' (current time) and 'dt' (delayed time), and returns the delayed arrival time as an integer.

2. **Calculation**
	```cpp
	    return (at + dt) % 24;
	```
	This line calculates the delayed arrival time by adding the current time ('at') to the delay ('dt') and applying the modulus operator to ensure the result is within the 24-hour format.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(1)
- **Worst Case:** O(1)

The time complexity is constant since the solution involves a fixed number of operations regardless of input size.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant because we only need a fixed amount of extra space for storing the inputs and result.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/calculate-delayed-arrival-time/description/)

---
{{< youtube 8a04uEm1FlE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

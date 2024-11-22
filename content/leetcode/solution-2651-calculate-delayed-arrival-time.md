
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
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int findDelayedArrivalTime(int at, int dt) {
        return (at + dt) % 24;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks to determine the time at which an event will occur given the current time (`at`) and the delayed time (`dt`). The time operates on a 24-hour clock, and the result must reflect the correct time modulo 24 hours. This means if the delayed time causes the event to exceed 24 hours, the answer should wrap around to the correct time on the next day.

### Approach

To solve this problem, the approach uses simple modular arithmetic. The key concept here is that the time operates on a 24-hour cycle, and we need to compute the total delayed time modulo 24 hours. 

The problem is asking for the result of adding `at` (the current time) to `dt` (the delay), and then ensuring that the result wraps around after reaching 24 hours. This can be easily accomplished by taking the sum of `at` and `dt`, then performing a modulo operation by 24. The modulo operator (`%`) will ensure that if the sum exceeds 24, it wraps back to the beginning of the 24-hour clock cycle.

### Code Breakdown

1. **Function Definition:**
   ```cpp
   int findDelayedArrivalTime(int at, int dt) {
       return (at + dt) % 24;
   }
   ```
   - **Input Parameters:**
     - `at`: The current time in hours (an integer between 0 and 23).
     - `dt`: The delay in hours (an integer, could be positive or zero).
   - **Return Value:**
     - The time at which the event occurs after the delay, considering the wraparound behavior of a 24-hour clock.

2. **Modular Arithmetic:**
   - The function adds `at` and `dt`, which gives the total hours from midnight.
   - The expression `(at + dt) % 24` ensures that the resulting time is within the bounds of a 24-hour clock.
   - If the sum `at + dt` exceeds 23 (i.e., the 24th hour or beyond), the modulo operation wraps the result back within the range `[0, 23]`, ensuring a valid time on the clock.

3. **Time Calculation:**
   - The key operation here is `(at + dt) % 24`. It guarantees that no matter how large `dt` is, the result will always be between `0` and `23`, corresponding to valid hours on a 24-hour clock.
   - For instance:
     - If `at = 22` (10 PM) and `dt = 5`, the result would be `(22 + 5) % 24 = 27 % 24 = 3`, which represents 3 AM.
     - If `at = 23` (11 PM) and `dt = 1`, the result would be `(23 + 1) % 24 = 24 % 24 = 0`, which represents 12 AM (midnight) on the next day.

### Complexity

- **Time Complexity:**
  - The time complexity is **O(1)** since the solution involves only basic arithmetic operations (addition and modulo), which take constant time.

- **Space Complexity:**
  - The space complexity is **O(1)** as well, because no extra space is used other than for the input parameters and the result.

### Conclusion

This problem is a simple application of modular arithmetic to ensure that times are calculated correctly on a 24-hour clock. The use of the modulo operator guarantees that the result always falls within the valid range of `[0, 23]`. The solution is efficient with a constant time and space complexity of **O(1)**, making it well-suited for handling any input within the specified limits. The approach ensures that even if the delay causes the time to exceed 24 hours, the result will be correctly wrapped around to the appropriate hour of the day.

[`Link to LeetCode Lab`](https://leetcode.com/problems/calculate-delayed-arrival-time/description/)

---
{{< youtube 8a04uEm1FlE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

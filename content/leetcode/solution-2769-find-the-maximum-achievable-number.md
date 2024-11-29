
+++
authors = ["grid47"]
title = "Leetcode 2769: Find the Maximum Achievable Number"
date = "2024-02-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2769: Find the Maximum Achievable Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "uj_B91ycSGo"
youtube_upload_date="2023-07-09"
youtube_thumbnail="https://i.ytimg.com/vi/uj_B91ycSGo/maxresdefault.jpg"
comments = true
+++



---
Given two integers num and t, determine the maximum achievable number after performing at most t operations, where each operation allows simultaneous increments or decrements of num and the target number by 1.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two integers num and t.
- **Example:** `Input: num = 5, t = 2`
- **Constraints:**
	- 1 <= num, t <= 50

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum achievable number after at most t operations.
- **Example:** `Output: 9 for num = 5, t = 2`
- **Constraints:**
	- Output is a single integer representing the maximum achievable number.

{{< dots >}}
### Core Logic 🔍
**Goal:** Compute the maximum achievable number after at most t operations.

- The maximum achievable number is equal to num + 2 * t.
- Each operation increases both the number and num by 1 or decreases both by 1.
{{< dots >}}
### Problem Assumptions ✅
- The values of num and t are positive integers.
- Operations are limited to increasing or decreasing both num and the number simultaneously.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: num = 5, t = 2`  \
  **Explanation:** After two operations, the maximum achievable number is 9. Each operation increases num and the target number by 1.

- **Input:** `Input: num = 2, t = 3`  \
  **Explanation:** After three operations, the maximum achievable number is 8. Each operation increases num and the target number by 1.

{{< dots >}}
## Approach 🚀
The solution calculates the maximum achievable number using a direct mathematical formula based on the given constraints.

### Initial Thoughts 💭
- Each operation allows the target number to diverge from num by at most 2 units per operation.
- The problem can be solved using simple arithmetic.
- The maximum achievable number is calculated as num + 2 * t.
{{< dots >}}
### Edge Cases 🌐
- Not applicable, as num and t are always provided.
- Test for maximum values of num = 50 and t = 50 to ensure correctness.
- Smallest values of num = 1 and t = 1.
- Ensure no invalid input scenarios.
{{< dots >}}
## Code 💻
```cpp
int theMaximumAchievableX(int num, int t) {
    return num + 2 * t;
}
```

This function calculates the maximum achievable value of `X` by adding twice the value of `t` to the initial value of `num`.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int theMaximumAchievableX(int num, int t) {
	```
	Defines the function `theMaximumAchievableX`, which takes two integers `num` and `t` as input and calculates the maximum achievable value by adding twice `t` to `num`.

2. **Return Statement**
	```cpp
	    return num + 2 * t;
	```
	Calculates the result by adding `2 * t` to `num` and returns this value as the output of the function.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(1)
- **Worst Case:** O(1)

The computation involves a single arithmetic operation.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

No additional space is required beyond input storage.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-the-maximum-achievable-number/description/)

---
{{< youtube uj_B91ycSGo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

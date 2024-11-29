
+++
authors = ["grid47"]
title = "Leetcode 1227: Airplane Seat Assignment Probability"
date = "2024-07-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1227: Airplane Seat Assignment Probability in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Dynamic Programming","Brainteaser","Probability and Statistics"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "pHgWf79hNoY"
youtube_upload_date="2024-02-05"
youtube_thumbnail="https://i.ytimg.com/vi/pHgWf79hNoY/maxresdefault.jpg"
comments = true
+++



---
There are `n` passengers boarding an airplane with `n` seats. The first passenger has lost their ticket and picks a random seat. The remaining passengers sit in their assigned seat if available or pick a random seat if their assigned seat is taken. Return the probability that the nth person gets their own seat.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a single integer `n` (1 <= n <= 10^5), representing the number of passengers and seats.
- **Example:** `n = 3`
- **Constraints:**
	- 1 <= n <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is a floating-point number representing the probability that the nth person sits in their own seat.
- **Example:** `0.50000`
- **Constraints:**
	- Return the answer with a precision of 5 decimal places.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to compute the probability that the last passenger sits in their own seat.

- If there's only one passenger, they will always sit in their own seat (probability = 1).
- For more than one passenger, the probability follows a pattern where it is 0.5 for n >= 2.
{{< dots >}}
### Problem Assumptions ✅
- The first passenger randomly selects a seat.
- Each subsequent passenger will either sit in their assigned seat or pick a random seat if theirs is taken.
{{< dots >}}
## Examples 🧩
- **Input:** `n = 3`  \
  **Explanation:** For three passengers, the first has a 50% chance of sitting in their assigned seat. If they don't, the third passenger has a 50% chance of sitting in theirs. The total probability for the nth person is 0.5.

{{< dots >}}
## Approach 🚀
The problem boils down to a simple observation: the probability of the nth person sitting in their seat is always 0.5 for n >= 2, and 1 for n = 1.

### Initial Thoughts 💭
- For n = 1, the answer is trivially 1.
- For n >= 2, the answer is always 0.5 based on a probabilistic pattern observed.
- This problem does not require complex simulations or recursive calculations for large n. We can directly return the result based on the value of n.
{{< dots >}}
### Edge Cases 🌐
- No empty inputs are allowed.
- The solution should handle up to 10^5 efficiently.
- For n = 1, the probability is always 1.
- Ensure that the result is returned with a precision of 5 decimal places.
{{< dots >}}
## Code 💻
```cpp
double nthPersonGetsNthSeat(int n) {
    if(n == 1) return 1;
    return 1/2.0;
}
```

This function calculates the probability that the nth person gets their own seat in a scenario where the first person selects a seat at random and subsequent people sit in their assigned seats if available or select randomly from remaining seats.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	double nthPersonGetsNthSeat(int n) {
	```
	This is the function definition for `nthPersonGetsNthSeat`, which calculates the probability of the nth person sitting in their assigned seat.

2. **Conditional Check**
	```cpp
	    if(n == 1) return 1;
	```
	If there is only one person (n == 1), they will always sit in their own seat, so the function returns 1.

3. **Return Value**
	```cpp
	    return 1/2.0;
	```
	For all cases where n > 1, the probability is always 1/2 (50%) based on the problem's constraints, as the first person randomly chooses a seat, and from then on, the probability alternates.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(1)
- **Worst Case:** O(1)

The time complexity is constant since we are only checking if n is 1 or not.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant as no additional space is required beyond a simple check.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/airplane-seat-assignment-probability/description/)

---
{{< youtube pHgWf79hNoY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

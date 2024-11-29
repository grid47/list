
+++
authors = ["grid47"]
title = "Leetcode 319: Bulb Switcher"
date = "2024-10-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 319: Bulb Switcher in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Brainteaser"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/319.webp"
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/319.webp" 
    alt="A series of glowing bulbs switching on and off, with the final count of switched bulbs softly highlighted."
    caption="Solution to LeetCode 319: Bulb Switcher Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
There are n bulbs initially off. You toggle every ith bulb in the ith round, and at the end, you need to return how many bulbs remain on.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a single integer n, representing the number of bulbs.
- **Example:** `n = 4`
- **Constraints:**
	- 0 <= n <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of bulbs that are still on after performing n rounds.
- **Example:** `2`
- **Constraints:**
	- The solution should handle large values of n efficiently.

{{< dots >}}
### Core Logic 🔍
**Goal:** To determine how many bulbs remain on after n rounds of toggling.

- For each round i (1 to n), toggle every i-th bulb.
- A bulb remains on if it is toggled an odd number of times.
{{< dots >}}
### Problem Assumptions ✅
- The number of bulbs can be very large (up to 10^9), so a direct simulation approach is impractical.
{{< dots >}}
## Examples 🧩
- **Input:** `n = 4`  \
  **Explanation:** The bulbs at positions 1 and 4 remain on after all rounds.

- **Input:** `n = 9`  \
  **Explanation:** The bulbs at positions 1, 4, and 9 remain on after all rounds.

{{< dots >}}
## Approach 🚀
Instead of simulating each round, we recognize that bulbs that are toggled an odd number of times will remain on. A bulb is toggled an odd number of times if its position is a perfect square.

### Initial Thoughts 💭
- Each bulb is toggled an odd number of times if and only if its position is a perfect square.
- The problem boils down to counting the number of perfect squares less than or equal to n.
{{< dots >}}
### Edge Cases 🌐
- If n is 0, return 0.
- For large values of n, the solution must efficiently compute the integer square root without iterating through all bulbs.
- When n is a perfect square, ensure the count includes that square.
- The solution must efficiently handle up to 10^9 using the mathematical property of perfect squares.
{{< dots >}}
## Code 💻
```cpp
int bulbSwitch(int n) {
    return sqrt(n);
}
```

This function returns the number of bulbs that remain on after n bulbs are toggled in a particular pattern, using the mathematical property of perfect squares.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int bulbSwitch(int n) {
	```
	The function `bulbSwitch` takes an integer `n` as input, representing the number of bulbs, and returns an integer indicating the number of bulbs that remain on after the toggling process.

2. **Mathematical Operation**
	```cpp
	    return sqrt(n);
	```
	The function returns the square root of `n`, which represents the number of bulbs that remain on. This is based on the fact that only bulbs in positions that are perfect squares will remain on after toggling.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(1)
- **Worst Case:** O(1)

The time complexity is constant because we only need to compute the integer square root of n.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant as we only store a few variables.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/bulb-switcher/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

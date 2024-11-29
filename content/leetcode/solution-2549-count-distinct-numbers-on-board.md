
+++
authors = ["grid47"]
title = "Leetcode 2549: Count Distinct Numbers on Board"
date = "2024-02-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2549: Count Distinct Numbers on Board in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Math","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "oZFY64vwfXI"
youtube_upload_date="2023-01-29"
youtube_thumbnail="https://i.ytimg.com/vi/oZFY64vwfXI/maxresdefault.jpg"
comments = true
+++



---
You are given a positive integer `n`, initially placed on a board. For each number `x` on the board, find all integers `i` such that `1 <= i <= n` and `x % i == 1`. Add these numbers to the board. Your goal is to determine how many distinct integers will be present on the board after a billion days.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a single integer `n` which represents the number initially placed on the board.
- **Example:** `n = 6`
- **Constraints:**
	- 1 <= n <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of distinct integers on the board after performing the described procedure for one billion days.
- **Example:** `4`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the distinct numbers on the board after the given procedure is performed for one billion days.

- 1. Start with `n` as the initial number on the board.
- 2. For each number `x` on the board, find all `i` such that `x % i == 1`.
- 3. Add the values of `i` to the board if they are not already present.
- 4. Repeat the above steps for one billion days.
{{< dots >}}
### Problem Assumptions ✅
- The procedure will run for a large number of iterations (one billion days).
- The board will keep adding distinct numbers that satisfy the modulo condition.
{{< dots >}}
## Examples 🧩
- **Input:** `n = 6`  \
  **Explanation:** Initially, the number 6 is placed on the board. Over time, the numbers 2, 4, and 3 will be added to the board, resulting in the distinct numbers: 2, 3, 4, and 6.

- **Input:** `n = 7`  \
  **Explanation:** For `n = 7`, the numbers added to the board after the operations are 2, 3, 6, and 7, making the distinct numbers 2, 3, 6, and 7.

{{< dots >}}
## Approach 🚀
The key observation is that the process of adding numbers to the board can be efficiently modeled using the modulo operation to identify which numbers will appear on the board after many iterations.

### Initial Thoughts 💭
- The operation depends on finding numbers where `x % i == 1` for all current numbers `x` on the board.
- The numbers that appear on the board will be a result of modulo operations from previous numbers.
- If we start with `n`, we need to find all integers `i` such that `x % i == 1`. After a few iterations, a pattern emerges that allows us to count distinct values efficiently.
{{< dots >}}
### Edge Cases 🌐
- There are no cases where the input is empty, as the problem guarantees that `n >= 1`.
- For very large inputs of `n`, the solution must be optimized to avoid iterating over all days explicitly.
- Consider special cases where `n` is very small (e.g., `n = 1`) or where all numbers on the board quickly stabilize.
- Ensure the solution handles the upper constraint of `n = 100` efficiently.
{{< dots >}}
## Code 💻
```cpp
int distinctIntegers(int n) {
    if(n == 1 || n == 2) return 1;
    return n - 1;
}
```

This code defines the 'distinctIntegers' function which calculates the number of distinct integers in the set of integers from 1 to n. For n=1 or n=2, the function returns 1, otherwise, it returns n-1.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int distinctIntegers(int n) {
	```
	The function 'distinctIntegers' is defined with one parameter, 'n'. It calculates the number of distinct integers in a given set based on the value of 'n'.

2. **Condition Check**
	```cpp
	    if(n == 1 || n == 2) return 1;
	```
	If n is equal to 1 or 2, the function immediately returns 1 as the number of distinct integers in this case is always 1.

3. **Return Statement**
	```cpp
	    return n - 1;
	```
	If n is greater than 2, the function returns n-1, which represents the number of distinct integers in the set from 1 to n.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the number of distinct numbers on the board.
- **Average Case:** O(n), as the number of new numbers added can be at most proportional to `n`.
- **Worst Case:** O(n), as the number of distinct values that can appear on the board is bounded by `n`.

The time complexity is linear in terms of the size of `n`, as we need to process each number once.

### Space Complexity 💾
- **Best Case:** O(1), in cases where the number of distinct integers does not increase.
- **Worst Case:** O(n), as we store the distinct numbers on the board.

The space complexity is O(n), as we only need to store the distinct numbers added to the board.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/count-distinct-numbers-on-board/description/)

---
{{< youtube oZFY64vwfXI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

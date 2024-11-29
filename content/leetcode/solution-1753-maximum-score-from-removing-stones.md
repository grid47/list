
+++
authors = ["grid47"]
title = "Leetcode 1753: Maximum Score From Removing Stones"
date = "2024-05-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1753: Maximum Score From Removing Stones in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Greedy","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "PfcEkLJ725o"
youtube_upload_date="2021-02-07"
youtube_thumbnail="https://i.ytimg.com/vi_webp/PfcEkLJ725o/maxresdefault.webp"
comments = true
+++



---
You are given three piles of stones, with sizes `a`, `b`, and `c` respectively. In each turn, you can choose two different non-empty piles, remove one stone from each, and add 1 point to your score. The game stops when there are fewer than two non-empty piles left, meaning no more valid moves are available. Your task is to return the maximum score you can achieve.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given three integers, `a`, `b`, and `c`, representing the sizes of the three piles.
- **Example:** `Input: a = 3, b = 5, c = 7`
- **Constraints:**
	- 1 <= a, b, c <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum score that can be achieved in the game.
- **Example:** `Output: 7`
- **Constraints:**
	- The returned score is a non-negative integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** To find the maximum score, we need to perform moves in an optimal way by always selecting the two largest piles.

- 1. Sort the piles so that the largest pile is always chosen first.
- 2. Continuously remove stones from the two largest piles until fewer than two piles remain non-empty.
- 3. Keep a count of each move to compute the score.
{{< dots >}}
### Problem Assumptions ✅
- There are always at least one stone in each pile initially.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: a = 3, b = 5, c = 7`  \
  **Explanation:** Starting with piles (3, 5, 7), the optimal sequence of moves is to take stones from the largest two piles (5, 7) for 5 turns, then from the remaining two piles (3, 6) for 3 turns. This results in a total of 7 points.

- **Input:** `Input: a = 2, b = 4, c = 6`  \
  **Explanation:** With piles (2, 4, 6), one optimal sequence is to take from the 1st and 3rd piles for 2 turns, then from the 2nd and 3rd piles for 4 turns. This gives a total score of 6.

{{< dots >}}
## Approach 🚀
To achieve the maximum score, we should always pick the two largest piles, ensuring that we make as many moves as possible.

### Initial Thoughts 💭
- The problem revolves around efficiently selecting the two largest piles in each step.
- If we sort the piles at the start, we can always easily select the two largest piles.
{{< dots >}}
### Edge Cases 🌐
- The problem guarantees that all piles will have at least one stone.
- The solution must handle cases where each pile contains up to 100,000 stones.
- If two piles are empty after several moves, the game ends immediately.
- The solution must be optimized for large input values.
{{< dots >}}
## Code 💻
```cpp
int maximumScore(int a, int b, int c) {
    // a > b > c
    if(a < b)
    return maximumScore(b, a, c);
    if(b < c)
    return maximumScore(a, c, b);

    return b == 0? 0 : 1 + maximumScore(a - 1, b - 1, c);
}
```

The function calculates the maximum score by repeatedly selecting the two largest numbers and decrementing them until one of them becomes zero.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int maximumScore(int a, int b, int c) {
	```
	Declares a recursive function to compute the maximum score by decrementing the two largest numbers repeatedly.

2. **Conditional Check**
	```cpp
	    if(a < b)
	```
	Checks if `a` is smaller than `b` to rearrange the values.

3. **Recursive Call**
	```cpp
	    return maximumScore(b, a, c);
	```
	Swaps `a` and `b` to maintain the condition `a >= b >= c` and recursively calls the function.

4. **Conditional Check**
	```cpp
	    if(b < c)
	```
	Checks if `b` is smaller than `c` to rearrange the values.

5. **Recursive Call**
	```cpp
	    return maximumScore(a, c, b);
	```
	Swaps `b` and `c` to maintain the condition `a >= b >= c` and recursively calls the function.

6. **Base Case**
	```cpp
	    return b == 0? 0 : 1 + maximumScore(a - 1, b - 1, c);
	```
	Base case: If the second largest number `b` is zero, returns 0; otherwise, decrements the two largest numbers and adds 1 to the score.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(log(n)) for sorting the piles, followed by linear time processing.
- **Average Case:** O(n) as we make one move per iteration.
- **Worst Case:** O(n) where n is the maximum number of stones.

The time complexity is dominated by the sorting step, and the rest of the operations are linear.

### Space Complexity 💾
- **Best Case:** O(1), as no additional space is required beyond the input piles.
- **Worst Case:** O(1) for a constant number of variables used for computation.

The space complexity is constant, as the solution uses only a few variables to keep track of the piles and score.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-score-from-removing-stones/description/)

---
{{< youtube PfcEkLJ725o >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |


+++
authors = ["grid47"]
title = "Leetcode 1033: Moving Stones Until Consecutive"
date = "2024-07-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1033: Moving Stones Until Consecutive in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Brainteaser"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++



---
You are given three stones located at different positions on the X-axis. The positions are represented by three distinct integers `a`, `b`, and `c`. In one move, you can pick a stone from either of the two endpoints (the smallest or the largest position) and move it to any unoccupied position between the two endpoints. The game ends when all three stones are positioned at three consecutive spots on the X-axis. Your task is to determine the minimum and maximum number of moves required to reach this configuration.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given three distinct integers `a`, `b`, and `c` representing the positions of the stones.
- **Example:** `a = 3, b = 6, c = 10`
- **Constraints:**
	- 1 <= a, b, c <= 100
	- a, b, and c have different values.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an array of length 2 where the first element represents the minimum number of moves and the second element represents the maximum number of moves required to make the stones occupy three consecutive positions.
- **Example:** `Output: [1, 2]`
- **Constraints:**
	- The answer must include both the minimum and maximum number of moves.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to calculate the minimum and maximum number of moves to position the stones at three consecutive positions.

- 1. Sort the positions of the stones to identify the smallest, middle, and largest values.
- 2. If the difference between the largest and smallest values is 2, no moves are needed (i.e., the stones are already in consecutive positions).
- 3. To find the minimum moves, check if the middle stone is already adjacent to one of the endpoints (this would require only one move). Otherwise, two moves are needed.
- 4. To find the maximum moves, subtract 2 from the difference between the largest and smallest stone positions, as that will give the number of available positions between them.
{{< dots >}}
### Problem Assumptions ✅
- The positions of the stones are provided in distinct integers and are guaranteed to be within the specified bounds.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: a = 1, b = 3, c = 7`  \
  **Explanation:** In this case, the stones are at positions 1, 3, and 7. The minimum number of moves is 1: move the stone from position 7 to 4. The maximum number of moves is 2: move the stone from position 7 to 5, then move the stone from position 5 to 4.

- **Input:** `Input: a = 4, b = 5, c = 6`  \
  **Explanation:** In this case, the stones are already at consecutive positions, so no moves are needed. The minimum and maximum number of moves are both 0.

{{< dots >}}
## Approach 🚀
The solution involves sorting the stone positions and then checking the differences between them to determine the possible moves.

### Initial Thoughts 💭
- Sorting the positions of the stones is a good first step to simplify the calculation of the number of moves.
- After sorting, we can quickly determine if the stones are already in consecutive positions or if any moves are necessary.
{{< dots >}}
### Edge Cases 🌐
- There will always be three distinct positions given, so empty inputs are not possible.
- The solution should handle the constraints efficiently, but the problem size is small (only 3 positions).
- If the positions are already consecutive, the result will be [0, 0].
- The problem guarantees distinct positions, so no need to handle repeated values.
{{< dots >}}
## Code 💻
```cpp
vector<int> numMovesStones(int a, int b, int c) {
    vector<int> s {a, b, c};
    sort(s.begin(), s.end());
    
    if(s[2]-s[0] == 2) return {0, 0};
    
    
    
    return {min(s[1]- s[0], s[2]-s[1]) <= 2? 1 : 2, s[2] - s[0] - 2 };
}
```

This function calculates the minimum and maximum number of moves required to make three stones consecutive when placed on a number line.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<int> numMovesStones(int a, int b, int c) {
	```
	Define the function `numMovesStones` that calculates the minimum and maximum moves to align stones.

2. **Initialize Vector**
	```cpp
	    vector<int> s {a, b, c};
	```
	Initialize a vector `s` to store the stone positions.

3. **Sort Vector**
	```cpp
	    sort(s.begin(), s.end());
	```
	Sort the vector `s` to arrange stone positions in ascending order.

4. **Check Consecutive Case**
	```cpp
	    if(s[2]-s[0] == 2) return {0, 0};
	```
	Check if the stones are already consecutive. If so, return {0, 0} as no moves are needed.

5. **Calculate Moves**
	```cpp
	    return {min(s[1]- s[0], s[2]-s[1]) <= 2? 1 : 2, s[2] - s[0] - 2 };
	```
	Return the minimum and maximum moves required based on the distances between the stones.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(1)
- **Worst Case:** O(1)

The time complexity is O(1) as sorting three elements is constant time.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) since we are only using a constant amount of extra space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/moving-stones-until-consecutive/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

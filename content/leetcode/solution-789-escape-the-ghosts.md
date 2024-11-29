
+++
authors = ["grid47"]
title = "Leetcode 789: Escape The Ghosts"
date = "2024-08-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 789: Escape The Ghosts in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/789.webp"
youtube = "fCx9Fb_ghaA"
youtube_upload_date="2019-04-18"
youtube_thumbnail="https://i.ytimg.com/vi_webp/fCx9Fb_ghaA/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/789.webp" 
    alt="A set of ghosts where escape routes are traced, with each route softly glowing as it’s followed."
    caption="Solution to LeetCode 789: Escape The Ghosts Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are playing a simplified game on an infinite 2-D grid where you start at position [0, 0], and your goal is to reach a destination point target = [xtarget, ytarget]. There are several ghosts on the map, each with its starting position. You and the ghosts can all independently move one unit in any of the four cardinal directions (north, east, south, or west), or stay still. If you can reach the destination before any ghost catches up with you, you escape. You cannot escape if you reach any square at the same time as a ghost. Your task is to return true if it is possible to escape, otherwise return false.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given the positions of ghosts and a target point. The ghosts' positions are provided as a 2D array, and the target point is also given as an array of two integers.
- **Example:** `ghosts = [[1, 0], [0, 3]], target = [0, 1]`
- **Constraints:**
	- 1 <= ghosts.length <= 100
	- ghosts[i].length == 2
	- -10^4 <= xi, yi <= 10^4
	- target.length == 2
	- -10^4 <= xtarget, ytarget <= 10^4

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a boolean value: true if it is possible to escape, otherwise false.
- **Example:** `Output: true`
- **Constraints:**
	- The output will be a boolean value indicating whether you can escape or not.

{{< dots >}}
### Core Logic 🔍
**Goal:** Determine if it is possible to escape by reaching the target point before any ghost can catch up with you.

- Calculate the Manhattan distance from the starting position [0, 0] to the target point.
- For each ghost, calculate its Manhattan distance to the target.
- If any ghost's distance to the target is less than or equal to your distance to the target, you cannot escape and return false.
- If none of the ghosts can reach the target faster than you, return true.
{{< dots >}}
### Problem Assumptions ✅
- The input is always valid within the constraints.
- There are no obstacles between the start and target, only ghosts that can move simultaneously.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: ghosts = [[1,0],[0,3]], target = [0,1]`  \
  **Explanation:** In this example, the target [0, 1] can be reached in 1 move, and both ghosts at positions [1, 0] and [0, 3] cannot catch up before you. Hence, the output is true.

- **Input:** `Input: ghosts = [[1,0]], target = [2,0]`  \
  **Explanation:** In this case, the ghost at position [1, 0] can reach the target at the same time you do, preventing you from escaping. Thus, the output is false.

- **Input:** `Input: ghosts = [[2, 0]], target = [1, 0]`  \
  **Explanation:** Here, the ghost can reach the target at the same time as you, so escape is not possible, resulting in false.

{{< dots >}}
## Approach 🚀
We can calculate the Manhattan distance from the start point to the target and compare it to the distances of the ghosts to the target. If any ghost can reach the target before or at the same time as you, you cannot escape.

### Initial Thoughts 💭
- We need to check the distance between each ghost and the target and compare it to your distance to the target.
- The problem can be reduced to a simple check of whether the ghost's distance is greater than yours to the target. If a ghost is closer or the same distance, you cannot escape.
{{< dots >}}
### Edge Cases 🌐
- There are no empty inputs, as the number of ghosts is always at least 1.
- Handle cases where the number of ghosts is large (up to 100) by ensuring the solution is efficient.
- If ghosts are located at the same position as the target, you will not escape.
- Ensure that the ghost positions and target coordinates are within the specified constraints.
{{< dots >}}
## Code 💻
```cpp
bool escapeGhosts(vector<vector<int>>& gs, vector<int>& t) {
    int d = abs(t[0]) + abs(t[1]);
    for(auto it: gs)
    if(d >= abs(it[0] - t[0]) + abs(it[1] - t[1]))
    return false;
    return true;
}
```

This function determines if Pac-Man can escape the ghosts based on the distances between them. It checks if any ghost is closer to Pac-Man than the distance he can travel and returns true or false accordingly.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool escapeGhosts(vector<vector<int>>& gs, vector<int>& t) {
	```
	The function 'escapeGhosts' is defined with two parameters: 'gs', a vector of ghost positions, and 't', a vector representing Pac-Man's target position.

2. **Distance Calculation**
	```cpp
	    int d = abs(t[0]) + abs(t[1]);
	```
	This line calculates the Manhattan distance from Pac-Man's current position to the target position 't'. The absolute values of the differences in the x and y coordinates are added.

3. **Loop Through Ghosts**
	```cpp
	    for(auto it: gs)
	```
	A for-each loop is used to iterate over each ghost's position in the 'gs' vector.

4. **Distance Comparison**
	```cpp
	    if(d >= abs(it[0] - t[0]) + abs(it[1] - t[1]))
	```
	For each ghost, this condition checks if Pac-Man's travel distance 'd' is greater than or equal to the ghost's distance from Pac-Man. If so, it means the ghost can potentially catch Pac-Man.

5. **Return False**
	```cpp
	    return false;
	```
	If the condition is true, meaning a ghost can catch Pac-Man, the function returns 'false', indicating Pac-Man cannot escape.

6. **Return True**
	```cpp
	    return true;
	```
	If no ghosts can catch Pac-Man, the function returns 'true', indicating Pac-Man can escape.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(g), where g is the number of ghosts.
- **Average Case:** O(g), since we check each ghost once.
- **Worst Case:** O(g), where g is up to 100.

The time complexity is linear with respect to the number of ghosts since we calculate the distance for each ghost and compare it to your own.

### Space Complexity 💾
- **Best Case:** O(1), if no extra space is required apart from input data.
- **Worst Case:** O(g), where g is the number of ghosts (for storing their positions).

The space complexity is linear in the number of ghosts because we need to store their positions.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/escape-the-ghosts/description/)

---
{{< youtube fCx9Fb_ghaA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

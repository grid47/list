
+++
authors = ["grid47"]
title = "Leetcode 2511: Maximum Enemy Forts That Can Be Captured"
date = "2024-02-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2511: Maximum Enemy Forts That Can Be Captured in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "y7BwYY4UFak"
youtube_upload_date="2022-12-24"
youtube_thumbnail="https://i.ytimg.com/vi_webp/y7BwYY4UFak/maxresdefault.webp"
comments = true
+++



---
You are given a 0-indexed integer array forts representing the positions of several forts. Your goal is to move your army from one of your forts to an empty position and capture enemy forts along the way. The army captures all enemy forts that lie between the starting and destination points, and you want to maximize the number of enemy forts captured.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a list of integers where each integer represents a fort at that position. The value can be -1 (no fort), 0 (enemy fort), or 1 (fort under your command).
- **Example:** `forts = [1, 0, 0, -1, 0, 0, 0, 0, 1]`
- **Constraints:**
	- 1 <= forts.length <= 1000
	- -1 <= forts[i] <= 1

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be the maximum number of enemy forts that can be captured by moving the army from one of your forts to an empty position.
- **Example:** `4`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to determine the maximum number of enemy forts that can be captured in one move.

- Iterate through the array to identify all forts under your command (value 1).
- For each fort, check all possible moves to the right and left to find enemy forts (value 0) between the starting and destination points.
- Calculate the number of enemy forts that will be captured during the move and keep track of the maximum value.
{{< dots >}}
### Problem Assumptions ✅
- There will always be at least one fort or enemy fort in the input.
- The army cannot move over non-empty positions, meaning no valid move exists if no enemy forts lie between two forts under your command.
{{< dots >}}
## Examples 🧩
- **Input:** `forts = [1, 0, 0, -1, 0, 0, 0, 0, 1]`  \
  **Explanation:** In this example, the army can move from position 0 to position 3, capturing 2 enemy forts. The best move is from position 8 to position 3, capturing 4 enemy forts.

{{< dots >}}
## Approach 🚀
The approach involves iterating over the forts array to check the possible moves and counting the enemy forts that can be captured in each move.

### Initial Thoughts 💭
- A valid move requires the army to travel over only enemy forts, meaning the path between the start and end point must contain only 0s.
- If no enemy forts are in the path or if no forts are under our command, the result is 0.
{{< dots >}}
### Edge Cases 🌐
- There will always be at least one fort or enemy fort in the input.
- The solution should handle arrays of length up to 1000 efficiently.
- If there are no enemy forts in the path, no forts will be captured.
- Ensure the solution handles cases with no valid moves (e.g., when no forts are under your command).
{{< dots >}}
## Code 💻
```cpp
int captureForts(vector<int>& forts) {
int res = 0;
for (int i = 0, j = 0; i < forts.size(); ++i)
    if (forts[i] != 0) {
        if (forts[j] == -forts[i])
            res = max(res, i - j - 1);
        j = i;
    }
return res;
}
```

The `captureForts` function calculates the maximum distance between two forts of opposing sides (denoted as 1 and -1) in a given array. It iterates through the array, checks for opposing forts, and computes the maximum distance between them.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int captureForts(vector<int>& forts) {
	```
	Defines the `captureForts` function that takes a vector `forts` as input and returns an integer representing the maximum distance between two opposing forts.

2. **Variable Initialization**
	```cpp
	int res = 0;
	```
	Initializes the variable `res` to store the maximum distance between opposing forts. It is initially set to 0.

3. **Loop Structure**
	```cpp
	for (int i = 0, j = 0; i < forts.size(); ++i)
	```
	Starts a for loop that iterates through the `forts` array, using `i` as the index for the current fort and `j` as the index of the previous fort with a non-zero value.

4. **Condition Check**
	```cpp
	    if (forts[i] != 0) {
	```
	Checks if the current fort at index `i` is non-zero (i.e., it is either a 1 or -1, representing a fort of one side).

5. **Condition Check**
	```cpp
	        if (forts[j] == -forts[i])
	```
	Checks if the fort at index `j` is of the opposite side compared to the current fort at index `i`.

6. **Max Calculation**
	```cpp
	            res = max(res, i - j - 1);
	```
	If two opposing forts are found, it calculates the distance between them and updates `res` to the maximum of the current `res` and the new distance (`i - j - 1`).

7. **Variable Update**
	```cpp
	        j = i;
	```
	Updates `j` to the current index `i` to track the position of the last non-zero fort.

8. **Loop Structure**
	```cpp
	    }
	```
	Ends the if block checking for non-zero forts.

9. **Return Statement**
	```cpp
	return res;
	```
	Returns the value of `res`, which represents the maximum distance between two opposing forts.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n) when no valid moves are possible.
- **Average Case:** O(n) as we iterate through the array once to check each position.
- **Worst Case:** O(n) in the worst case when we check all possible moves between forts.

Time complexity is linear because we only need to scan the array once for each move.

### Space Complexity 💾
- **Best Case:** O(1), as we are not storing additional data structures.
- **Worst Case:** O(1), as we only store variables for the maximum number of captured forts.

The space complexity is constant since no extra space is required except for a few variables.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-enemy-forts-that-can-be-captured/description/)

---
{{< youtube y7BwYY4UFak >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

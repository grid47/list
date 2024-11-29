
+++
authors = ["grid47"]
title = "Leetcode 2038: Remove Colored Pieces if Both Neighbors are the Same Color"
date = "2024-04-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2038: Remove Colored Pieces if Both Neighbors are the Same Color in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","String","Greedy","Game Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "03zIcb12PKo"
youtube_upload_date="2023-10-02"
youtube_thumbnail="https://i.ytimg.com/vi_webp/03zIcb12PKo/maxresdefault.webp"
comments = true
+++



---
You are given a string `colors` consisting of two types of pieces, 'X' and 'Y', arranged in a line. Two players, Alex and Brian, play a game where they take turns removing pieces from the string. Alex moves first and can only remove a piece 'X' if both its neighbors are also 'X'. Similarly, Brian can only remove a piece 'Y' if both its neighbors are also 'Y'. Neither player can remove edge pieces. If a player cannot make a move, they lose. Determine whether Alex wins the game if both players play optimally.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a single string `colors` of length `n`, where `colors[i]` is either 'X' or 'Y', representing the pieces.
- **Example:** `"XXYXXY"`
- **Constraints:**
	- 1 <= colors.length <= 100000
	- colors consists only of the characters 'X' and 'Y'

{{< dots >}}
### Output Specifications 📤
- **Output:** Return `true` if Alex wins the game, or `false` if Brian wins the game.
- **Example:** `true`
- **Constraints:**
	- The result must be computed efficiently due to the constraints on input size.

{{< dots >}}
### Core Logic 🔍
**Goal:** Determine the winner by counting the number of valid moves for each player and checking if Alex has more valid moves than Brian.

- 1. Iterate through the string `colors`.
- 2. Count all segments of three consecutive 'X's (valid moves for Alex).
- 3. Count all segments of three consecutive 'Y's (valid moves for Brian).
- 4. Compare the counts: if Alex's count is greater than Brian's, return `true`; otherwise, return `false`.
{{< dots >}}
### Problem Assumptions ✅
- Players play optimally.
- The string always contains at least one 'X' or 'Y'.
{{< dots >}}
## Examples 🧩
- **Input:** `"XXYXYXX"`  \
  **Explanation:** Alex removes the middle 'X' from "XXYXYXX" to get "XYXYXX". Brian has no valid moves, so Alex wins. The function returns `true`.

- **Input:** `"YYXXYY"`  \
  **Explanation:** Neither Alex nor Brian has a valid move, so Brian wins because Alex cannot make the first move. The function returns `false`.

{{< dots >}}
## Approach 🚀
Count the number of valid moves for each player and determine the winner by comparing the counts.

### Initial Thoughts 💭
- A player can only remove a piece surrounded by identical neighbors.
- The game ends when neither player can make a valid move.
- Counting valid moves for each player provides a direct way to determine the winner.
{{< dots >}}
### Edge Cases 🌐
- Not applicable due to constraints.
- Strings with length close to the upper limit (100000).
- Strings where all characters are the same ('XXXXXX' or 'YYYYYY').
- Strings with no valid moves for either player ('XYXYXY').
- Must handle strings with maximum length efficiently.
{{< dots >}}
## Code 💻
```cpp
bool winnerOfGame(string colors) {
    int a = 0, b = 0;
    for(int i = 1; i < colors.size() - 1; i++) {
        if(colors[i - 1] == colors[i] && colors[i] == colors[i+1]) {
            if(colors[i] == 'A') a++;
            else b++;
        }
    }
    return a > b;
}
```

This function evaluates a game where two players, 'A' and 'B', are competing by marking a string of colors. The function counts the occurrences of consecutive matching colors and determines the winner based on who has more of such consecutive markings.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool winnerOfGame(string colors) {
	```
	This line defines the function `winnerOfGame` which takes a string `colors` as input. The function determines if player 'A' wins the game by counting consecutive matching colors.

2. **Variable Initialization**
	```cpp
	    int a = 0, b = 0;
	```
	Here, two variables `a` and `b` are initialized to zero. They will be used to count the number of consecutive matching color pairs for players 'A' and 'B' respectively.

3. **Loop**
	```cpp
	    for(int i = 1; i < colors.size() - 1; i++) {
	```
	This `for` loop iterates over the `colors` string, starting from the second character and stopping at the second-to-last character to check for consecutive matching colors.

4. **Condition Check**
	```cpp
	        if(colors[i - 1] == colors[i] && colors[i] == colors[i+1]) {
	```
	This `if` statement checks if the current character and its adjacent characters (previous and next) are the same. If true, it means there is a consecutive match of three identical colors.

5. **Increment Counter**
	```cpp
	            if(colors[i] == 'A') a++;
	```
	If the consecutive matching colors belong to player 'A' (i.e., the character is 'A'), the counter `a` is incremented by 1.

6. **Increment Counter**
	```cpp
	            else b++;
	```
	If the consecutive matching colors belong to player 'B' (i.e., the character is 'B'), the counter `b` is incremented by 1.

7. **Return Statement**
	```cpp
	    return a > b;
	```
	The function returns `true` if player 'A' has more consecutive matching colors than player 'B'. Otherwise, it returns `false`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The algorithm processes each character of the string once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The algorithm uses constant extra space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/description/)

---
{{< youtube 03zIcb12PKo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

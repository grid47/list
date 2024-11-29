
+++
authors = ["grid47"]
title = "Leetcode 2660: Determine the Winner of a Bowling Game"
date = "2024-02-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2660: Determine the Winner of a Bowling Game in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "UzLjzmjhVqs"
youtube_upload_date="2023-04-30"
youtube_thumbnail="https://i.ytimg.com/vi_webp/UzLjzmjhVqs/maxresdefault.webp"
comments = true
+++



---
In a bowling game, two players take turns to hit pins. Each player hits a certain number of pins per turn, and the total score is calculated based on how many pins they hit and whether they hit 10 pins in previous turns. If a player hits 10 pins in one of the previous two turns, their score for the current turn is doubled. The objective is to determine which player has the higher score after all turns have been played.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given two integer arrays, player1 and player2, where each element represents the number of pins hit by the corresponding player in each turn.
- **Example:** `Input: player1 = [3,10,2,5], player2 = [4,6,8,2]`
- **Constraints:**
	- 1 <= n <= 1000
	- 0 <= player1[i], player2[i] <= 10

{{< dots >}}
### Output Specifications 📤
- **Output:** Return 1 if player 1 has a higher score, 2 if player 2 has a higher score, and 0 in case of a draw.
- **Example:** `Output: 1`
- **Constraints:**
	- The output should be either 1, 2, or 0 based on the comparison of the scores.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to calculate the total score for both players and compare them to determine the winner.

- Step 1: For each player, iterate through their scores for each turn.
- Step 2: If the player hits 10 pins in the previous turn or the one before that, double the score for the current turn.
- Step 3: Sum all the scores for each player.
- Step 4: Compare the total scores and return the appropriate result based on which player's score is higher.
{{< dots >}}
### Problem Assumptions ✅
- The number of turns for both players is the same.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: player1 = [3,10,2,5], player2 = [4,6,8,2]`  \
  **Explanation:** Player 1's score is 3 + 10 + 2*2 + 5 = 25, and Player 2's score is 4 + 6 + 8 + 2 = 20. Therefore, Player 1 wins.

- **Input:** `Input: player1 = [5,1,4,10], player2 = [2,10,2,8]`  \
  **Explanation:** Player 1's score is 5 + 1 + 4 + 2*10 = 25, and Player 2's score is 2 + 10 + 2*2 + 8 = 24. Player 1 wins.

{{< dots >}}
## Approach 🚀
The approach involves iterating through the scores of both players and applying the logic for doubling the score based on the previous turns, then comparing the total scores.

### Initial Thoughts 💭
- The scores for each player can be computed by checking each turn and applying the bonus if a player hits 10 pins in any of the last two turns.
- We need to ensure that we check the last two turns for each player efficiently as we iterate through their scores.
{{< dots >}}
### Edge Cases 🌐
- There should always be at least one turn for both players.
- Handle the case where n is large, up to 1000 turns.
- If a player hits 0 pins for all turns, their score will naturally be 0.
- Ensure the solution handles cases where players alternate between high and low scores across multiple turns.
{{< dots >}}
## Code 💻
```cpp
int isWinner(vector<int>& p1, vector<int>& p2) {
    int sc1 = 0, sc2 = 0;
    int n = p1.size();
    for(int i = 0; i < n; i++) {
        if(i > 1 && (p1[i - 1] == 10 || p1[i - 2] == 10)) {
            sc1 += 2 * p1[i];
        } else if(i > 0 && p1[i - 1] == 10){
            sc1 += 2 * p1[i];                
        }
        else sc1 += p1[i];
        if(i > 1 && (p2[i - 1] == 10 || p2[i - 2] == 10)) {
            sc2 += 2 * p2[i];
        }else if(i > 0 && p2[i - 1] == 10){
            sc2 += 2 * p2[i];                
        } else sc2 += p2[i];            
    }
    if(sc1 > sc2) return 1;
    if(sc2 > sc1) return 2;
    return 0;
}
```

This function checks who the winner is in a game where players alternate turns. If a player scores a strike (10), their next score is doubled.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	int isWinner(vector<int>& p1, vector<int>& p2) {
	```
	This function begins by taking two vectors of integers representing the scores of two players, p1 and p2.

2. **Variable Initialization**
	```cpp
	    int sc1 = 0, sc2 = 0;
	```
	Here, we initialize the scores for player 1 and player 2 to zero.

3. **Size Calculation**
	```cpp
	    int n = p1.size();
	```
	We retrieve the size of the vector p1, which represents the number of turns played in the game.

4. **Looping Through Turns**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	We iterate through each turn (index) in the game.

5. **Conditional Logic**
	```cpp
	        if(i > 1 && (p1[i - 1] == 10 || p1[i - 2] == 10)) {
	```
	If the current turn follows a strike (10), the score for this turn is doubled.

6. **Score Calculation**
	```cpp
	            sc1 += 2 * p1[i];
	```
	Player 1's score is updated by doubling their current score if a strike is scored in the previous two turns.

7. **Conditional Logic**
	```cpp
	        } else if(i > 0 && p1[i - 1] == 10){
	```
	If only the previous turn was a strike, the current score is also doubled.

8. **Score Calculation**
	```cpp
	            sc1 += 2 * p1[i];                
	```
	Player 1’s score is updated by doubling their score if the previous turn was a strike.

9. **Default Score Addition**
	```cpp
	        else sc1 += p1[i];
	```
	Player 1's score is updated normally by adding the score from this turn.

10. **Conditional Logic**
	```cpp
	        if(i > 1 && (p2[i - 1] == 10 || p2[i - 2] == 10)) {
	```
	Similarly, we check if player 2 scores a double due to a strike in the previous two turns.

11. **Score Calculation**
	```cpp
	            sc2 += 2 * p2[i];
	```
	Player 2's score is updated by doubling their score if there was a strike in the previous two turns.

12. **Conditional Logic**
	```cpp
	        }else if(i > 0 && p2[i - 1] == 10){
	```
	If only the previous turn was a strike, player 2's current score is doubled.

13. **Score Calculation**
	```cpp
	            sc2 += 2 * p2[i];                
	```
	Player 2's score is updated by doubling their score if the previous turn was a strike.

14. **Default Score Addition**
	```cpp
	        } else sc2 += p2[i];            
	```
	If there was no strike, player 2’s score is added normally.

15. **Final Comparison**
	```cpp
	    if(sc1 > sc2) return 1;
	```
	After all turns, compare the scores. If player 1 has a higher score, return 1.

16. **Final Comparison**
	```cpp
	    if(sc2 > sc1) return 2;
	```
	If player 2 has a higher score, return 2.

17. **Final Comparison**
	```cpp
	    return 0;
	```
	If both players have the same score, return 0 to indicate a tie.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The solution iterates through the arrays of players, so the time complexity is linear, O(n), where n is the number of turns.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The solution uses a constant amount of extra space, O(1), as it only keeps track of the scores.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/determine-the-winner-of-a-bowling-game/description/)

---
{{< youtube UzLjzmjhVqs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

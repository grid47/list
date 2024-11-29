
+++
authors = ["grid47"]
title = "Leetcode 2682: Find the Losers of the Circular Game"
date = "2024-02-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2682: Find the Losers of the Circular Game in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "bNZuwqt1pg0"
youtube_upload_date="2023-05-14"
youtube_thumbnail="https://i.ytimg.com/vi/bNZuwqt1pg0/maxresdefault.jpg"
comments = true
+++



---
In this game, there are `n` friends sitting in a circle, numbered from 1 to `n`. The game starts with the 1st friend receiving a ball. The ball is passed to a friend `k` steps away in a clockwise direction, and then on each subsequent turn, the ball is passed to the friend `i * k` steps away, where `i` is the turn number (starting from 1). The game ends when any friend receives the ball for the second time. The friends who never receive the ball are considered the losers. The task is to return the list of losers in ascending order.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given two integers, `n` and `k`, where `n` is the number of friends and `k` is the number of steps the ball is passed on each turn.
- **Example:** `Input: n = 6, k = 3`
- **Constraints:**
	- 1 <= k <= n <= 50

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an array containing the losers of the game (the friends who never received the ball), sorted in ascending order.
- **Example:** `Output: [2, 4, 5, 6]`
- **Constraints:**
	- The output should be an array of integers.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to simulate the passing of the ball based on the given rules and track which friends never receive the ball.

- Step 1: Initialize an array to track whether each friend has received the ball.
- Step 2: Start with the 1st friend receiving the ball and pass it `k` steps away on each turn.
- Step 3: After each pass, mark the friend as having received the ball and continue passing it in increasing multiples of `k`.
- Step 4: Stop the game when any friend receives the ball for the second time.
- Step 5: Gather all the friends who never received the ball and return them as the losers.
{{< dots >}}
### Problem Assumptions ✅
- All input values are valid as per the problem constraints.
- The game will always end when a friend receives the ball for the second time.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: n = 6, k = 3`  \
  **Explanation:** In this case, the ball starts with the 1st friend and is passed 3 steps away each time. The game proceeds as follows: 1st friend -> 4th friend -> 1st friend (game ends). The losers are the friends who never received the ball: 2nd, 5th, and 6th friends.

- **Input:** `Input: n = 4, k = 2`  \
  **Explanation:** The ball starts with the 1st friend and is passed 2 steps away each time. The game proceeds as follows: 1st friend -> 3rd friend -> 1st friend (game ends). The losers are the 2nd and 4th friends.

{{< dots >}}
## Approach 🚀
We will simulate the game by passing the ball as per the rules and track the friends who receive the ball, using a simple array to mark each friend as they receive the ball.

### Initial Thoughts 💭
- We need to simulate the ball passing efficiently to track the friends who received the ball.
- A straightforward simulation should suffice as `n` is small enough (up to 50).
{{< dots >}}
### Edge Cases 🌐
- There will always be at least one friend, so no empty inputs.
- The solution should be efficient enough for `n` up to 50.
- The case where `k` equals `n` should be handled correctly, as the ball will be passed back to the 1st friend immediately.
- The ball will always return to a friend who has already received it, ensuring the game ends.
{{< dots >}}
## Code 💻
```cpp
vector<int> circularGameLosers(int n, int k) {
    vector<int> rcvd(n, 0);
    int i = 0;
    int cnt = 1;
    rcvd[0] = 1;
    while(rcvd[i] == 1) {
        i = (i + cnt * k) % n;            
        if(rcvd[i] == 1) break;
        rcvd[i] = 1;
        cnt++;
    }
    vector<int> ans;
    for(int j = 0; j < n; j++) {
        // cout << rcvd[j] << " ";
        if(rcvd[j] == 0) ans.push_back(j + 1);            
    }

    return ans;
}
```

The function 'circularGameLosers' simulates a game where players are eliminated in a circular fashion. Starting from player 1, the game progresses by skipping 'k' players each time, and the eliminated player is marked. The function returns a list of players who were not eliminated.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<int> circularGameLosers(int n, int k) {
	```
	The function 'circularGameLosers' is defined to take two arguments: an integer 'n' representing the number of players and an integer 'k' representing the number of steps between eliminations. The goal is to return the list of players who are not eliminated.

2. **Variable Initialization**
	```cpp
	    vector<int> rcvd(n, 0);
	```
	A vector 'rcvd' is initialized to size 'n', with all values set to 0, representing that no players are initially eliminated.

3. **Variable Initialization**
	```cpp
	    int i = 0;
	```
	The variable 'i' is initialized to 0 and will be used to keep track of the current player in the game.

4. **Variable Initialization**
	```cpp
	    int cnt = 1;
	```
	The variable 'cnt' is initialized to 1 and will keep track of the number of steps taken between eliminations.

5. **First Elimination**
	```cpp
	    rcvd[0] = 1;
	```
	The first player (index 0) is marked as eliminated by setting 'rcvd[0]' to 1.

6. **Game Loop**
	```cpp
	    while(rcvd[i] == 1) {
	```
	A while loop is initiated, continuing as long as the current player 'i' is marked as eliminated.

7. **Player Elimination Calculation**
	```cpp
	        i = (i + cnt * k) % n;            
	```
	The index 'i' is updated by moving 'k' steps forward, multiplied by 'cnt', and taken modulo 'n' to ensure it stays within the circular bounds of the array.

8. **Elimination Check**
	```cpp
	        if(rcvd[i] == 1) break;
	```
	If the current player is already eliminated, the loop breaks, ending the game.

9. **Player Elimination**
	```cpp
	        rcvd[i] = 1;
	```
	The current player 'i' is marked as eliminated by setting 'rcvd[i]' to 1.

10. **Step Increment**
	```cpp
	        cnt++;
	```
	The 'cnt' variable is incremented to account for the next step in the game, which will be used to calculate the next elimination.

11. **Result Vector Initialization**
	```cpp
	    vector<int> ans;
	```
	An empty vector 'ans' is initialized to store the indices of players who were not eliminated.

12. **Losers Collection Loop**
	```cpp
	    for(int j = 0; j < n; j++) {
	```
	A loop iterates through the 'rcvd' vector to identify the players who were not eliminated.

13. **Losers Identification**
	```cpp
	        if(rcvd[j] == 0) ans.push_back(j + 1);            
	```
	If the player 'j' is not eliminated (i.e., 'rcvd[j] == 0'), their index (adjusted by 1) is added to the 'ans' vector.

14. **Return Result**
	```cpp
	    return ans;
	```
	The 'ans' vector, containing the indices of the players who were not eliminated, is returned as the final result.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

We iterate over the friends once to simulate the ball passing process, which takes linear time.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

We use an array of size `n` to track the friends who received the ball.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-the-losers-of-the-circular-game/description/)

---
{{< youtube bNZuwqt1pg0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

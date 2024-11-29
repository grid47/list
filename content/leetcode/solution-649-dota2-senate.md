
+++
authors = ["grid47"]
title = "Leetcode 649: Dota2 Senate"
date = "2024-09-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 649: Dota2 Senate in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Greedy","Queue"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/649.webp"
youtube = "zZA5KskfMuQ"
youtube_upload_date="2023-05-04"
youtube_thumbnail="https://i.ytimg.com/vi/zZA5KskfMuQ/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/649.webp" 
    alt="A series of characters where the senate is divided and illuminated by those voting for or against, softly glowing."
    caption="Solution to LeetCode 649: Dota2 Senate Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
In a Senate made up of senators from two parties, Radiant and Dire, senators can either ban another senator from voting or announce victory if only one party remains with active senators. Predict which party will announce the victory and change the game.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a string representing the parties of each senator, where 'R' represents Radiant and 'D' represents Dire. The length of the string represents the number of senators.
- **Example:** `senate = "DRD"`
- **Constraints:**
	- 1 <= n <= 10^4
	- senate[i] is either 'R' or 'D'.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the party that will eventually announce victory: either 'Radiant' or 'Dire'.
- **Example:** `Output: 'Dire'`
- **Constraints:**
	- The output will be either 'Radiant' or 'Dire'.

{{< dots >}}
### Core Logic 🔍
**Goal:** Determine which party will be the last to have active senators left after the rounds of banning.

- 1. Initialize two queues, one for each party, to represent the senators' positions.
- 2. In each round, allow the senator with the smallest index in the queue to ban an opponent.
- 3. Repeat the rounds until all remaining senators are from the same party.
{{< dots >}}
### Problem Assumptions ✅
- Each senator can ban the other party's senator in each round.
- A senator can only announce the victory when all remaining senators belong to the same party.
{{< dots >}}
## Examples 🧩
- **Input:** `senate = "DRD"`  \
  **Explanation:** The first senator from Dire bans the second senator from Radiant. In the next round, the second senator from Radiant bans the remaining senator from Dire, allowing Radiant to announce victory.

{{< dots >}}
## Approach 🚀
Use two queues to simulate the round-based banning of senators. Each senator from the two parties will take turns banning the opponent until one party remains.

### Initial Thoughts 💭
- This is a simulation problem, so we can use queues to efficiently manage the senators in each round.
- We need to ensure that in each round, the senator with the smallest index bans an opponent and moves to the end of the queue.
{{< dots >}}
### Edge Cases 🌐
- The input string will not be empty, as there will always be at least one senator.
- Handle cases with the maximum number of senators (10^4) efficiently.
- If all senators belong to the same party, that party wins immediately.
- Ensure that the solution handles cases with large inputs within the time limits.
{{< dots >}}
## Code 💻
```cpp
string predictPartyVictory(string sen) {
    
    queue<int> q1, q2;
    int n = sen.size();
    for(int i = 0; i < sen.size(); i++)
    (sen[i] == 'R')? q1.push(i) : q2.push(i);

    while(!q1.empty() && !q2.empty()) {
        int r = q1.front(); q1.pop();
        int l = q2.front(); q2.pop();
        
        (r < l) ? q1.push(r + n) : q2.push(l + n);
        
    }
    return q1.size() > q2.size()  ?  "Radiant" : "Dire" ;
}
```

This function simulates a game where two parties, 'Radiant' (denoted by 'R') and 'Dire' (denoted by 'D'), take turns, and the one with more remaining players at the end wins. The function uses two queues to manage the players and determines the winner based on the queue sizes after all matchups.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Method Definition**
	```cpp
	string predictPartyVictory(string sen) {
	```
	The method `predictPartyVictory` is defined to determine the winning party in a game based on the string `sen`, where each character represents a player from either the 'Radiant' or 'Dire' team.

2. **Queue Initialization**
	```cpp
	    queue<int> q1, q2;
	```
	Two queues, `q1` and `q2`, are initialized to store the indices of the players for the 'Radiant' and 'Dire' teams, respectively.

3. **Determine Number of Players**
	```cpp
	    int n = sen.size();
	```
	The total number of players is determined by the length of the input string `sen`, which represents the players.

4. **Queue Population**
	```cpp
	    for(int i = 0; i < sen.size(); i++)
	```
	A loop iterates over the string `sen` to populate the two queues based on whether the character is 'R' (Radiant) or 'D' (Dire).

5. **Character Check**
	```cpp
	    (sen[i] == 'R')? q1.push(i) : q2.push(i);
	```
	For each character in `sen`, if it is 'R', the index is pushed to the Radiant queue `q1`, otherwise it is pushed to the Dire queue `q2`.

6. **Main Simulation Loop**
	```cpp
	    while(!q1.empty() && !q2.empty()) {
	```
	A while loop runs as long as both teams have players remaining in their respective queues.

7. **Queue Operations**
	```cpp
	        int r = q1.front(); q1.pop();
	```
	The first player from the Radiant team is retrieved and removed from `q1`.

8. **Queue Operations**
	```cpp
	        int l = q2.front(); q2.pop();
	```
	The first player from the Dire team is retrieved and removed from `q2`.

9. **Match Decision**
	```cpp
	        (r < l) ? q1.push(r + n) : q2.push(l + n);
	```
	A match is simulated by comparing the indices of the players. The player with the smaller index loses, and the losing player is sent to the back of the opposing team's queue, with their index incremented by the total number of players (to simulate their return in the next round).

10. **Determine Winner**
	```cpp
	    return q1.size() > q2.size()  ?  "Radiant" : "Dire" ;
	```
	After the while loop ends, the team with more players remaining in their queue is declared the winner. If `q1` (Radiant) has more players, 'Radiant' is returned; otherwise, 'Dire' is returned.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

Each senator is processed exactly once, so the time complexity is linear with respect to the number of senators.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the space required to store the two queues representing the two parties.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/dota2-senate/description/)

---
{{< youtube zZA5KskfMuQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

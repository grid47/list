
+++
authors = ["grid47"]
title = "Leetcode 2410: Maximum Matching of Players With Trainers"
date = "2024-03-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2410: Maximum Matching of Players With Trainers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "rvASCADV4Lw"
youtube_upload_date="2022-09-18"
youtube_thumbnail="https://i.ytimg.com/vi/rvASCADV4Lw/maxresdefault.jpg"
comments = true
+++



---
You are given two arrays: 'players' and 'trainers'. The array 'players' represents the abilities of different players, and the array 'trainers' represents the training capacities of various trainers. A player can be matched with a trainer if the player's ability is less than or equal to the trainer's capacity. The goal is to find the maximum number of valid matchings between players and trainers such that each player is matched with at most one trainer and vice versa.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two integer arrays: 'players' and 'trainers'.
- **Example:** `players = [5, 6, 8], trainers = [7, 2, 6, 8]`
- **Constraints:**
	- 1 <= players.length, trainers.length <= 10^5
	- 1 <= players[i], trainers[j] <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an integer that represents the maximum number of valid matchings between players and trainers.
- **Example:** `Output: 3`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to maximize the number of valid pairings by comparing the abilities of players with the training capacities of trainers.

- 1. Sort both the players and trainers arrays.
- 2. Use two pointers to try matching the smallest available player with the smallest available trainer that can accommodate them.
- 3. Move through both lists and count the valid pairings, ensuring each player and trainer is matched at most once.
{{< dots >}}
### Problem Assumptions ✅
- Players can only be matched with a trainer if their ability is less than or equal to the trainer's capacity.
- Each player and trainer can be matched at most once.
{{< dots >}}
## Examples 🧩
- **Input:** `players = [5, 6, 8], trainers = [7, 2, 6, 8]`  \
  **Explanation:** After sorting the arrays, players = [5, 6, 8] and trainers = [2, 6, 7, 8]. We can match player 5 with trainer 6, player 6 with trainer 7, and player 8 with trainer 8. Thus, the answer is 3.

- **Input:** `players = [1, 1, 1], trainers = [10]`  \
  **Explanation:** In this case, all players have the same ability (1), and there is only one trainer with capacity 10. The trainer can be matched with any of the three players, so the maximum number of matches is 1.

{{< dots >}}
## Approach 🚀
The solution uses sorting and a greedy approach to maximize the number of valid matchings between players and trainers.

### Initial Thoughts 💭
- The problem can be efficiently solved by sorting both the players and trainers arrays.
- By matching players from the smallest to the largest with the trainers, we can maximize the number of valid pairings.
- After sorting, we can use a two-pointer technique to find the optimal pairings.
{{< dots >}}
### Edge Cases 🌐
- The input arrays will not be empty as per the problem constraints.
- For large inputs, the solution needs to efficiently handle the sorting and matching process.
- If all players have the same ability, the solution should still handle the maximum number of matches correctly.
- If all trainers have much higher capacity than players, then the number of matches will be limited by the number of players.
- The solution should work within the given constraints of the problem.
{{< dots >}}
## Code 💻
```cpp
int matchPlayersAndTrainers(vector<int>& man, vector<int>& master) {
    
    priority_queue<int, vector<int>, greater<int>> pq, qq;
    
    int m = man.size(), n = master.size();
    
    for(int i = 0; i < m; i++) {
        pq.push(man[i]);
    }
    for(int i = 0; i < n; i++) {
        qq.push(master[i]);
    }
    int cnt = 0;
    while(!pq.empty() && !qq.empty()) {
        while(!qq.empty() && pq.top() > qq.top())
            qq.pop();
        if(!qq.empty()) {
            cnt++;
            qq.pop();
            pq.pop();
        }
    }
    
    return cnt;
}
```

This function matches players to trainers by comparing their skills using two priority queues. It returns the count of valid pairings where both player and trainer have matching skills.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int matchPlayersAndTrainers(vector<int>& man, vector<int>& master) {
	```
	Declares the function `matchPlayersAndTrainers` that takes two vectors representing players and trainers' skills.

2. **Queue Initialization**
	```cpp
	    priority_queue<int, vector<int>, greater<int>> pq, qq;
	```
	Creates two priority queues (`pq` for players and `qq` for trainers) to store their skills in ascending order.

3. **Size Calculation**
	```cpp
	    int m = man.size(), n = master.size();
	```
	Calculates the size of the `man` and `master` vectors to determine the number of players and trainers.

4. **For Loop - Players**
	```cpp
	    for(int i = 0; i < m; i++) {
	```
	Begins a loop to iterate through the players and push their skills into the `pq` priority queue.

5. **Queue Push - Players**
	```cpp
	        pq.push(man[i]);
	```
	Pushes the skill of the current player into the `pq` queue.

6. **For Loop - Trainers**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Begins a loop to iterate through the trainers and push their skills into the `qq` priority queue.

7. **Queue Push - Trainers**
	```cpp
	        qq.push(master[i]);
	```
	Pushes the skill of the current trainer into the `qq` queue.

8. **Counter Initialization**
	```cpp
	    int cnt = 0;
	```
	Initializes a counter variable `cnt` to keep track of the valid player-trainer pairings.

9. **While Loop - Main Matching**
	```cpp
	    while(!pq.empty() && !qq.empty()) {
	```
	Begins a while loop that runs as long as there are players and trainers in their respective queues.

10. **While Loop - Trainer Skill Comparison**
	```cpp
	        while(!qq.empty() && pq.top() > qq.top())
	```
	This inner while loop ensures that trainers with lesser skills than the current player are removed from the queue.

11. **Queue Pop - Trainer**
	```cpp
	            qq.pop();
	```
	Pops a trainer from the `qq` queue if their skill is less than the player's skill.

12. **If Statement - Valid Match**
	```cpp
	        if(!qq.empty()) {
	```
	Checks if there are still trainers left after removing those with insufficient skill to match the current player.

13. **Counter Increment**
	```cpp
	            cnt++;
	```
	Increments the counter `cnt` when a valid player-trainer match is found.

14. **Queue Pop - Player**
	```cpp
	            qq.pop();
	```
	Pops a trainer from the `qq` queue after a match is made.

15. **Queue Pop - Trainer**
	```cpp
	            pq.pop();
	```
	Pops a player from the `pq` queue after a match is made.

16. **Return Statement**
	```cpp
	    return cnt;
	```
	Returns the final count of valid player-trainer matches.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n), where n is the size of the larger of the two arrays (players or trainers).
- **Average Case:** O(n log n), as the sorting step dominates the complexity.
- **Worst Case:** O(n log n), since we are always sorting both arrays.

The solution involves sorting both arrays, which takes O(n log n) time.

### Space Complexity 💾
- **Best Case:** O(1), as no extra space is needed beyond the input arrays.
- **Worst Case:** O(1), as we only use a few additional variables to track the pointers and match counts.

The space complexity is constant, as no additional data structures are used beyond the input arrays.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-matching-of-players-with-trainers/description/)

---
{{< youtube rvASCADV4Lw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |


+++
authors = ["grid47"]
title = "Leetcode 1686: Stone Game VI"
date = "2024-05-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1686: Stone Game VI in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Greedy","Sorting","Heap (Priority Queue)","Game Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "D5uS2MXRhfk"
youtube_upload_date="2020-12-12"
youtube_thumbnail="https://i.ytimg.com/vi/D5uS2MXRhfk/maxresdefault.jpg"
comments = true
+++



---
Alice and Bob take turns playing a game with a pile of `n` stones, each having a value assigned by both players. They play optimally and aim to maximize their total points by choosing stones with the highest value for each player.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** Two arrays are given: `aliceValues` and `bobValues`. Both arrays represent how Alice and Bob value the stones, respectively. Each player will pick stones optimally to maximize their score.
- **Example:** `aliceValues = [3, 2], bobValues = [1, 4]`
- **Constraints:**
	- 1 <= n <= 10^5
	- 1 <= aliceValues[i], bobValues[i] <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** Return `1` if Alice wins, `-1` if Bob wins, or `0` if the game results in a draw.
- **Example:** `Output: 1`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Calculate the optimal moves for Alice and Bob and determine the winner based on the total scores.

- Use a priority queue to prioritize stones based on their combined value to both players.
- Simulate the turns, assigning points to Alice and Bob based on the stone they pick, starting with Alice.
{{< dots >}}
### Problem Assumptions ✅
- Both players play optimally and have full knowledge of each other's values.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: aliceValues = [5, 1], bobValues = [3, 6]`  \
  **Explanation:** Alice starts first and chooses the stone with value 5. Bob then takes the stone with value 6. The final score comparison shows Bob winning.

{{< dots >}}
## Approach 🚀
The goal is to maximize the total points for each player by taking the stones with the highest combined value first.

### Initial Thoughts 💭
- Both players can see each other's values, and they will prioritize stones based on their combined value.
- Simulate the game using a priority queue where each turn picks the stone with the maximum combined value for both players.
{{< dots >}}
### Edge Cases 🌐
- The input arrays should never be empty as per the problem constraints.
- For large inputs (up to 10^5 stones), ensure that the solution remains efficient.
- If all the values in both arrays are the same, the game will always result in a draw.
- The solution must efficiently handle the maximum array size of 10^5.
{{< dots >}}
## Code 💻
```cpp
int stoneGameVI(vector<int>& alice, vector<int>& bob) {
    int ap = 0, bp = 0;

    int n = alice.size();
    
    /*
        Take out stones with max points (alice[i] + bob[i])
        It either increase our winning chance
        or reduces the opponents winning chance
    */
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, less<pair<int,int>>> pq;
    
    for(int i = 0; i < n; i++) {
        pq.push({alice[i] + bob[i], i});
    }
    
    bool isA = true;
    while(!pq.empty()) {
        auto tmp = pq.top();
        pq.pop();
        if(isA) {
            ap += alice[tmp.second];
        } else {
            bp += bob[tmp.second];
        }
        isA = !isA;
    }
    // cout << ap << " " << bp;
    return ap > bp ? 1 : ap < bp ? -1: 0;
}
```

This function implements the stone game where two players, Alice and Bob, take turns picking stones. The goal is to maximize the player's score by selecting stones with the highest combined value (alice[i] + bob[i]). The function returns 1 if Alice wins, -1 if Bob wins, or 0 if it's a draw.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int stoneGameVI(vector<int>& alice, vector<int>& bob) {
	```
	Define the function 'stoneGameVI' that takes two vectors 'alice' and 'bob', representing the points for each player on each stone, and returns the outcome of the game.

2. **Variable Initialization**
	```cpp
	    int ap = 0, bp = 0;
	```
	Initialize variables 'ap' and 'bp' to 0. These will hold the cumulative scores for Alice and Bob, respectively.

3. **Size Calculation**
	```cpp
	    int n = alice.size();
	```
	Determine the size of the 'alice' vector, which is the same as the 'bob' vector, and store it in variable 'n'.

4. **Priority Queue Declaration**
	```cpp
	    priority_queue<pair<int,int>, vector<pair<int,int>>, less<pair<int,int>>> pq;
	```
	Declare a priority queue 'pq' to store pairs of integers, where the first value is the combined score of a stone (alice[i] + bob[i]) and the second value is the index of the stone. The queue is sorted in descending order based on the combined score.

5. **Loop Through Stones**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Start a loop to iterate through all the stones.

6. **Push to Priority Queue**
	```cpp
	        pq.push({alice[i] + bob[i], i});
	```
	Push a pair consisting of the combined score of the stone (alice[i] + bob[i]) and its index into the priority queue.

7. **Turn Indicator**
	```cpp
	    bool isA = true;
	```
	Initialize a boolean variable 'isA' to true, indicating that it's Alice's turn to pick a stone.

8. **While Loop**
	```cpp
	    while(!pq.empty()) {
	```
	Start a while loop that continues until the priority queue is empty, meaning all stones have been picked.

9. **Get Top Stone**
	```cpp
	        auto tmp = pq.top();
	```
	Get the stone with the highest combined score (top of the priority queue).

10. **Pop from Priority Queue**
	```cpp
	        pq.pop();
	```
	Remove the top stone from the priority queue.

11. **Check Turn**
	```cpp
	        if(isA) {
	```
	If it's Alice's turn (isA is true), proceed to update Alice's score.

12. **Update Alice's Score**
	```cpp
	            ap += alice[tmp.second];
	```
	Add the score of the current stone for Alice (alice[tmp.second]) to her total score (ap).

13. **Else Condition**
	```cpp
	        } else {
	```
	If it's not Alice's turn (it's Bob's turn), update Bob's score.

14. **Update Bob's Score**
	```cpp
	            bp += bob[tmp.second];
	```
	Add the score of the current stone for Bob (bob[tmp.second]) to his total score (bp).

15. **Toggle Turn**
	```cpp
	        isA = !isA;
	```
	Toggle the turn indicator (isA) to switch turns between Alice and Bob.

16. **Return Statement**
	```cpp
	    return ap > bp ? 1 : ap < bp ? -1: 0;
	```
	Return 1 if Alice has a higher score than Bob, -1 if Bob has a higher score, or 0 if their scores are equal (a draw).

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The time complexity is O(n log n) due to the priority queue operations.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) to store the priority queue and other intermediate data.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/stone-game-vi/description/)

---
{{< youtube D5uS2MXRhfk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

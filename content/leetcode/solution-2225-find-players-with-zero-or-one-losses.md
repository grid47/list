
+++
authors = ["grid47"]
title = "Leetcode 2225: Find Players With Zero or One Losses"
date = "2024-03-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2225: Find Players With Zero or One Losses in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sorting","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "rHZD8NrMq5s"
youtube_upload_date="2022-04-03"
youtube_thumbnail="https://i.ytimg.com/vi_webp/rHZD8NrMq5s/maxresdefault.webp"
comments = true
+++



---
You are given an array `matches` where each element `matches[i] = [winneri, loseri]` indicates that player `winneri` defeated player `loseri` in a match. Your task is to return a list `answer` of size 2 where:

- `answer[0]` contains the list of players who have never lost a match.
- `answer[1]` contains the list of players who have lost exactly one match.

The players in both lists should be sorted in increasing order.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a list of pairs `matches[i]` where each pair represents a match result. Each pair consists of two integers: the winner and the loser of the match.
- **Example:** `matches = [[1, 3], [2, 3], [3, 6], [5, 6], [5, 7], [4, 5], [4, 8], [4, 9], [10, 4], [10, 9]]`
- **Constraints:**
	- 1 <= matches.length <= 10^5
	- matches[i].length == 2
	- 1 <= winneri, loseri <= 10^5
	- winneri != loseri
	- All matches[i] are unique.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a list `answer` with two elements: the first element is a list of players who have never lost a match, and the second element is a list of players who have lost exactly one match. Both lists should be sorted in increasing order.
- **Example:** `Output: [[1, 2, 10], [4, 5, 7, 8]]`
- **Constraints:**
	- Both the lists `answer[0]` and `answer[1]` should be sorted in increasing order.

{{< dots >}}
### Core Logic 🔍
**Goal:** To determine the players who have lost no matches and exactly one match by tracking match results and counting losses for each player.

- Create a set of all players who have participated in at least one match.
- Create a map to count the number of losses for each player.
- Iterate over the set of players and check how many times each player has lost. Players with no losses go into the first list, and players with exactly one loss go into the second list.
{{< dots >}}
### Problem Assumptions ✅
- There will be no players with both zero and exactly one loss.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: matches = [[1, 3], [2, 3], [3, 6], [5, 6], [5, 7], [4, 5], [4, 8], [4, 9], [10, 4], [10, 9]]`  \
  **Explanation:** Players 1, 2, and 10 have never lost a match. Players 4, 5, 7, and 8 each lost exactly one match. Players 3, 6, and 9 have lost more than one match.

- **Input:** `Input: matches = [[2, 3], [1, 3], [5, 4], [6, 4]]`  \
  **Explanation:** Players 1, 2, 5, and 6 have never lost a match, while no player has lost exactly one match.

{{< dots >}}
## Approach 🚀
The approach involves iterating through the `matches` array and tracking the number of losses for each player. Players who have no losses are added to the first list, while those with exactly one loss are added to the second list.

### Initial Thoughts 💭
- We need to process the match results efficiently to track losses for each player.
- Using a map to count losses for each player should allow us to solve the problem in linear time.
{{< dots >}}
### Edge Cases 🌐
- Empty matches arrays are not allowed, as the constraints specify that `matches.length >= 1`.
- The solution must handle up to 100,000 matches efficiently.
- If a player has never lost any match, they should be included in the first list, and if a player lost exactly one match, they should be included in the second list.
- The results must be sorted in increasing order.
{{< dots >}}
## Code 💻
```cpp
vector<vector<int>> findWinners(vector<vector<int>>& matches) {
    unordered_set<int> u;
    map<int, int> ff;
    int n = matches.size();
    for(int i = 0; i < n; i++) {
        u.insert(matches[i][0]);
        u.insert(matches[i][1]);
        ff[matches[i][1]]++;
    }
    vector<vector<int>> arr(2);
    for(auto it = u.begin(); it != u.end(); it++) {
        if(!ff.count(*it)) arr[0].push_back(*it);
        else if(ff[*it] == 1) arr[1].push_back(*it);
    }
    sort(arr[0].begin(), arr[0].end());
    sort(arr[1].begin(), arr[1].end());
    return arr;
}
```

This code defines a solution for finding winners and losers from a list of match results. It stores the participants and counts their losses, sorting them into two categories: winners and losers. The result is returned as a 2D vector.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<vector<int>> findWinners(vector<vector<int>>& matches) {
	```
	The `findWinners` function is declared, which takes a vector of match results and returns a 2D vector containing winners and players with only one loss.

2. **Variable Declaration**
	```cpp
	    unordered_set<int> u;
	```
	An unordered set `u` is declared to store all unique players who participated in the matches.

3. **Variable Declaration**
	```cpp
	    map<int, int> ff;
	```
	A map `ff` is declared to count the number of losses for each player.

4. **Variable Initialization**
	```cpp
	    int n = matches.size();
	```
	The variable `n` is initialized to the size of the `matches` vector, representing the number of matches.

5. **Loop**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	A loop is started to iterate over each match in the `matches` vector.

6. **Insert Operation**
	```cpp
	        u.insert(matches[i][0]);
	```
	The first player of each match is inserted into the set `u` to ensure they are tracked as participants.

7. **Insert Operation**
	```cpp
	        u.insert(matches[i][1]);
	```
	The second player of each match is inserted into the set `u` to ensure they are also tracked as participants.

8. **Map Update**
	```cpp
	        ff[matches[i][1]]++;
	```
	The number of losses for the second player of the match is incremented in the map `ff`.

9. **Vector Initialization**
	```cpp
	    vector<vector<int>> arr(2);
	```
	A 2D vector `arr` is initialized with two empty vectors to store the winners and players with exactly one loss.

10. **Loop**
	```cpp
	    for(auto it = u.begin(); it != u.end(); it++) {
	```
	A loop is started to iterate over each player in the set `u`.

11. **Condition Check**
	```cpp
	        if(!ff.count(*it)) arr[0].push_back(*it);
	```
	If the player has no losses (i.e., not in the `ff` map), they are added to the first subvector `arr[0]`, which tracks the winners.

12. **Condition Check**
	```cpp
	        else if(ff[*it] == 1) arr[1].push_back(*it);
	```
	If the player has exactly one loss, they are added to the second subvector `arr[1]`, which tracks the players with one loss.

13. **Sort Operation**
	```cpp
	    sort(arr[0].begin(), arr[0].end());
	```
	The first subvector of winners is sorted in ascending order.

14. **Sort Operation**
	```cpp
	    sort(arr[1].begin(), arr[1].end());
	```
	The second subvector of players with exactly one loss is sorted in ascending order.

15. **Return Statement**
	```cpp
	    return arr;
	```
	The 2D vector `arr` containing the winners and players with exactly one loss is returned.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the number of matches.
- **Average Case:** O(n), since we process each match and player in linear time.
- **Worst Case:** O(n), as the input size can go up to 100,000 matches.

The time complexity is linear in terms of the number of matches.

### Space Complexity 💾
- **Best Case:** O(n), since we need space for the players and their loss counts.
- **Worst Case:** O(n), where n is the number of players in the worst case.

The space complexity is linear in terms of the number of players, which is proportional to the number of matches.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-players-with-zero-or-one-losses/description/)

---
{{< youtube rHZD8NrMq5s >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

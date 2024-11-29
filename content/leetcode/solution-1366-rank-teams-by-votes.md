
+++
authors = ["grid47"]
title = "Leetcode 1366: Rank Teams by Votes"
date = "2024-06-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1366: Rank Teams by Votes in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Sorting","Counting"]
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
In a special ranking system, each voter assigns a rank to all participating teams in a competition. The rankings are based on the most first-place votes, then second-place votes, and so on. If there is still a tie, teams are ranked alphabetically.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array of strings where each string represents the rankings given by a voter.
- **Example:** `votes = ["XYZ", "YZX", "ZXY", "XYZ", "YZX"]`
- **Constraints:**
	- 1 <= votes.length <= 1000
	- 1 <= votes[i].length <= 26
	- votes[i].length == votes[j].length for all 0 <= i, j < votes.length
	- Each character in a vote string is unique.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is a string containing all the teams ranked from highest to lowest based on the voting system.
- **Example:** `"XYZ"`
- **Constraints:**
	- The output string will contain all teams in the order of their ranks.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to rank teams based on their positions in the votes, resolving ties using subsequent positions, and sorting alphabetically if necessary.

- Count the number of first-place, second-place, third-place, etc., votes for each team.
- Sort teams primarily by the number of first-place votes, then second-place votes, and so on.
- If teams are still tied after considering all positions, sort them alphabetically.
{{< dots >}}
### Problem Assumptions ✅
- The input contains valid rankings where each character is a unique team in every vote string.
{{< dots >}}
## Examples 🧩
- **Input:** `votes = ["XYZ", "YZX", "ZXY", "XYZ", "YZX"]`  \
  **Explanation:** In this case, team X received the most first-place votes, so it ranks first. Team Y and team Z tie for second place but team Y has the most second-place votes, so it ranks second.

- **Input:** `votes = ["ABCDE", "DCBAE", "EABCD"]`  \
  **Explanation:** Team A received the most first-place votes across all voters, so it ranks first, followed by team B.

{{< dots >}}
## Approach 🚀
The approach involves counting the number of votes each team receives for each position and sorting them according to the ranking system.

### Initial Thoughts 💭
- The problem requires ranking teams based on votes for each position in a list of rankings.
- Sorting the teams by first-place votes, then second-place votes, and so on, will allow us to handle ties effectively.
{{< dots >}}
### Edge Cases 🌐
- If there is only one voter, their ranking is the final result.
- Ensure the solution handles large inputs efficiently, up to 1000 votes and 26 teams.
- If all teams are tied at each position, sort them alphabetically.
- Make sure to handle cases where there are multiple ties at various positions.
{{< dots >}}
## Code 💻
```cpp
string rankTeams(vector<string>& votes) {
    vector<vector<int>> count(26, vector<int> (27));
    for(char &c: votes[0])
    count[c - 'A'][26] = c;

    for(string& vote: votes)
    for(int i =0; i < vote.size(); i++)
    --count[vote[i] - 'A'][i];
    
    sort(count.begin(), count.end());
    string res;
    for(int i = 0; i < votes[0].length(); i++)
        res += count[i][26];
    
    return res;
}
```

This function ranks teams based on votes, where each vote is a string representing the ranking of teams. The function calculates the score of each team using a scoring system based on vote positions, sorts the teams based on their scores, and returns a string representing the ranked teams.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	string rankTeams(vector<string>& votes) {
	```
	This function takes a vector of strings 'votes', where each string represents a ranking of teams, and returns a string that represents the ranked order of the teams.

2. **Variable Initialization**
	```cpp
	    vector<vector<int>> count(26, vector<int> (27));
	```
	A 2D vector 'count' is initialized to store the ranking positions of 26 teams (A-Z), with each row representing a team and each column representing the position in the votes.

3. **First Vote Processing**
	```cpp
	    for(char &c: votes[0])
	```
	The first string in the 'votes' vector is iterated, and for each character (team), its corresponding position in the 'count' array is updated.

4. **Store Team Character**
	```cpp
	    count[c - 'A'][26] = c;
	```
	Stores the character representing the team in the last column (index 26) of the 'count' array. This keeps track of the team character in the count table.

5. **Iterate Over Votes**
	```cpp
	    for(string& vote: votes)
	```
	The function iterates over all the votes to process each vote string.

6. **Iterate Over Each Vote**
	```cpp
	    for(int i = 0; i < vote.size(); i++)
	```
	For each vote string, this loop iterates over each position in the vote to update the corresponding team's score.

7. **Update Team Score**
	```cpp
	    --count[vote[i] - 'A'][i];
	```
	For each team in the vote string, the corresponding team's score is decremented based on its position in the vote (lower positions have higher priority).

8. **Sort Teams**
	```cpp
	    sort(count.begin(), count.end());
	```
	The 'count' array is sorted based on the scores of the teams, placing the teams with the highest score first.

9. **Initialize Result String**
	```cpp
	    string res;
	```
	A string 'res' is initialized to store the result of the ranked teams.

10. **Construct Result String**
	```cpp
	    for(int i = 0; i < votes[0].length(); i++)
	```
	The function iterates over the length of the vote strings to construct the result string by adding teams in ranked order.

11. **Add Ranked Team to Result**
	```cpp
	        res += count[i][26];
	```
	For each ranked team, its character (team) is appended to the result string 'res'.

12. **Return Result**
	```cpp
	    return res;
	```
	The final ranked order of teams is returned as a string.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The time complexity is dominated by the sorting step, where n is the number of teams.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is linear in the number of teams, as we need to store counts for each team.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/rank-teams-by-votes/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

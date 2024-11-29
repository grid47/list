
+++
authors = ["grid47"]
title = "Leetcode 1626: Best Team With No Conflicts"
date = "2024-05-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1626: Best Team With No Conflicts in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "7kURH3btcV4"
youtube_upload_date="2023-01-31"
youtube_thumbnail="https://i.ytimg.com/vi/7kURH3btcV4/maxresdefault.jpg"
comments = true
+++



---
You are the manager of a basketball team, and you are tasked with selecting a team that maximizes the overall score. The score of the team is calculated by summing the individual scores of all the selected players. However, there is a rule: a conflict arises if a younger player has a strictly higher score than an older player. There is no conflict if players have the same age.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** Two lists are given, `scores` and `ages`, where each element in `scores` corresponds to the score of a player and each element in `ages` corresponds to the age of that player.
- **Example:** `scores = [2, 4, 8, 10, 12], ages = [1, 2, 3, 4, 5]`
- **Constraints:**
	- 1 <= scores.length, ages.length <= 1000
	- scores.length == ages.length
	- 1 <= scores[i] <= 106
	- 1 <= ages[i] <= 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum possible score of a valid team, where the team has no conflicts.
- **Example:** `Output: 36`
- **Constraints:**
	- The result is an integer representing the maximum score.

{{< dots >}}
### Core Logic 🔍
**Goal:** Maximize the total score of a valid team.

- 1. Pair each player's age with their score.
- 2. Sort the list of players based on their age in descending order.
- 3. Use dynamic programming to find the best possible score by avoiding conflicts.
{{< dots >}}
### Problem Assumptions ✅
- All players have a unique age or the same age, but the score is distinct for each player.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: scores = [2, 4, 8, 10, 12], ages = [1, 2, 3, 4, 5]`  \
  **Explanation:** You can select all the players without any conflicts, resulting in a total score of 36.

{{< dots >}}
## Approach 🚀
The approach is to use dynamic programming to maximize the score while avoiding conflicts between players.

### Initial Thoughts 💭
- Sorting players by age ensures that the condition of having no conflicts between players can be easily handled.
- The idea is to use a dynamic programming approach to compute the maximum score for each player while ensuring no conflicts.
{{< dots >}}
### Edge Cases 🌐
- If either the scores or ages list is empty, the output will be 0.
- For large inputs with the maximum number of players (1000), the algorithm should still perform efficiently.
- All players having the same score or age might result in different team configurations.
- Ensure the solution handles the upper bounds of input size and constraints.
{{< dots >}}
## Code 💻
```cpp
int bestTeamScore(vector<int>& scores, vector<int>& ages) {
    int n = ages.size();
    vector<pair<int, int>> palyer;
    for(int i = 0; i < n; i++)
    palyer.push_back({ages[i], scores[i]});

    sort(palyer.begin(), palyer.end(), greater<>());
    int ans = 0;
    vector<int> dp(n);
    for(int i = 0; i < n; i++) {
        pair<int, int> young = palyer[i];
        dp[i] = young.second;
        for(int j = 0; j < i; j++) {
            pair<int, int> elder = palyer[j];
            if(young.second <= elder.second)
            dp[i] = max(dp[i], dp[j] + young.second);
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}
```

This solution calculates the best possible team score where a team member’s score is strictly less than or equal to the previous member’s score. The solution uses dynamic programming to store the maximum possible score at each step.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Method Definition**
	```cpp
	int bestTeamScore(vector<int>& scores, vector<int>& ages) {
	```
	Define the main method 'bestTeamScore' which takes in two vectors: scores and ages.

2. **Variable Initialization**
	```cpp
	    int n = ages.size();
	```
	Initialize 'n' to be the size of the 'ages' vector, which is the total number of players.

3. **Variable Initialization**
	```cpp
	    vector<pair<int, int>> palyer;
	```
	Initialize a vector of pairs 'palyer' where each pair stores the age and score of a player.

4. **Loop Constructs**
	```cpp
	    for(int i = 0; i < n; i++)
	```
	Iterate through each player to add their age and score to the 'palyer' vector.

5. **Vector Manipulations**
	```cpp
	    palyer.push_back({ages[i], scores[i]});
	```
	Push a new pair containing the current player's age and score into the 'palyer' vector.

6. **Sorting**
	```cpp
	    sort(palyer.begin(), palyer.end(), greater<>());
	```
	Sort the 'palyer' vector in descending order based on age first, and score second (if ages are equal).

7. **Variable Initialization**
	```cpp
	    int ans = 0;
	```
	Initialize 'ans' to store the maximum score found during the process.

8. **Vector Initialization**
	```cpp
	    vector<int> dp(n);
	```
	Initialize a dynamic programming vector 'dp' to store the best scores at each player position.

9. **Loop Constructs**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Start an outer loop to go through each player in the sorted 'palyer' vector.

10. **Variable Initialization**
	```cpp
	        pair<int, int> young = palyer[i];
	```
	Assign the current player (sorted by age and score) to the variable 'young'.

11. **Vector Operations**
	```cpp
	        dp[i] = young.second;
	```
	Initialize 'dp[i]' with the score of the current player ('young').

12. **Loop Constructs**
	```cpp
	        for(int j = 0; j < i; j++) {
	```
	Start an inner loop to check previous players for a valid team formation.

13. **Variable Initialization**
	```cpp
	            pair<int, int> elder = palyer[j];
	```
	Assign the previous player to 'elder' to compare their score with 'young'.

14. **Conditional Statements**
	```cpp
	            if(young.second <= elder.second)
	```
	Check if the score of the current player ('young') is less than or equal to the score of the previous player ('elder').

15. **Mathematical Operations**
	```cpp
	            dp[i] = max(dp[i], dp[j] + young.second);
	```
	If valid, update 'dp[i]' by considering the best score combination of the current and previous player.

16. **Mathematical Operations**
	```cpp
	        ans = max(ans, dp[i]);
	```
	Update the maximum score 'ans' by considering the current best score at 'dp[i]'.

17. **Return Statement**
	```cpp
	    return ans;
	```
	Return the maximum score 'ans' which is the best team score.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n) due to sorting.
- **Average Case:** O(n^2) due to dynamic programming.
- **Worst Case:** O(n^2) due to dynamic programming and sorting.

The time complexity is dominated by the sorting step followed by the dynamic programming evaluation.

### Space Complexity 💾
- **Best Case:** O(n) for storing the dynamic programming table.
- **Worst Case:** O(n) for storing the dynamic programming table.

The space complexity is linear as we store the dynamic programming table.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/best-team-with-no-conflicts/description/)

---
{{< youtube 7kURH3btcV4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

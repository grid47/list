
+++
authors = ["grid47"]
title = "Leetcode 1583: Count Unhappy Friends"
date = "2024-06-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1583: Count Unhappy Friends in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "GpJUwhzx258"
youtube_upload_date="2020-09-13"
youtube_thumbnail="https://i.ytimg.com/vi/GpJUwhzx258/maxresdefault.jpg"
comments = true
+++



---
You are given a list of preferences for n friends, where n is always even. Each person has a list of friends they prefer, and these friends are represented by integers from 0 to n-1. The friends are divided into pairs, where each pair is denoted by a list [xi, yi], meaning xi is paired with yi and yi with xi. However, some of the pairings may cause unhappiness. A person is unhappy if they prefer someone who is paired with someone else, and that person also prefers them over their current partner. Your task is to return the number of unhappy friends.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an integer n representing the number of friends, a list preferences where preferences[i] is a list of integers representing the preferred friends for person i, and a list pairs where pairs[i] contains two integers denoting the pairing between two friends.
- **Example:** `Input: n = 4, preferences = [[1, 2, 3], [3, 2, 0], [3, 1, 0], [1, 2, 0]], pairs = [[0, 1], [2, 3]]`
- **Constraints:**
	- 2 <= n <= 500
	- n is even.
	- preferences.length == n
	- preferences[i].length == n - 1
	- 0 <= preferences[i][j] <= n - 1
	- preferences[i] does not contain i.
	- All values in preferences[i] are unique.
	- pairs.length == n/2
	- pairs[i].length == 2
	- xi != yi
	- 0 <= xi, yi <= n - 1
	- Each person is contained in exactly one pair.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of unhappy friends.
- **Example:** `Output: 2`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** To find the number of unhappy friends, we need to check each pairing to see if there is a more preferred person for one of the friends in the pair who also prefers them over their current partner.

- 1. Create a ranking matrix to represent the preference order of each friend.
- 2. Traverse the list of pairs and for each pair, check if any friend in the pair would be happier with someone else who prefers them back over their current partner.
- 3. Keep track of the unhappy friends and return the count.
{{< dots >}}
### Problem Assumptions ✅
- The number of friends is always even.
- Each person in the pairs is distinct and paired with exactly one other person.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: n = 4, preferences = [[1, 2, 3], [3, 2, 0], [3, 1, 0], [1, 2, 0]], pairs = [[0, 1], [2, 3]]`  \
  **Explanation:** In this example, Friend 1 is unhappy because they prefer Friend 3 over Friend 0, and Friend 3 prefers Friend 1 over Friend 2. Similarly, Friend 3 is unhappy because they prefer Friend 1 over Friend 2, and Friend 1 prefers Friend 3 over Friend 0. Therefore, the output is 2.

- **Input:** `Example 2: n = 2, preferences = [[1], [0]], pairs = [[1, 0]]`  \
  **Explanation:** In this case, both Friend 0 and Friend 1 are happy because they are paired with each other and have no better alternative. Therefore, the output is 0.

{{< dots >}}
## Approach 🚀
The approach involves checking the preferences of each person in the pairs and comparing them with other possible pairings to determine if anyone would be happier with a different person.

### Initial Thoughts 💭
- The problem essentially requires us to check if the current pairings are the optimal ones based on the preferences of the individuals.
- We can approach the solution by iterating through all possible pairs and determining if any of the pairings lead to unhappiness for the individuals.
{{< dots >}}
### Edge Cases 🌐
- The input will always contain at least two friends, as n >= 2.
- The solution must be optimized for n up to 500.
- If no pairings lead to unhappiness, the output should be 0.
- The solution should be efficient enough to handle the maximum input size.
{{< dots >}}
## Code 💻
```cpp
int unhappyFriends(int n, vector<vector<int>>& pref, vector<vector<int>>& pairs) {
    vector<vector<int>> rnk(n, vector<int>(n, INT_MAX));
    for(int i = 0; i < pref.size(); i++) {
        for(int j = 0; j < pref[i].size(); j++) {
            rnk[i][pref[i][j]] = j;                
        }
    }
    int cnt = 0;
    set<int> items;
    for(int i = 0; i < pairs.size(); i++) {
        for(int j = i + 1; j < pairs.size(); j++) {
            int x = pairs[i][0], y = pairs[i][1];
            int u = pairs[j][0], v = pairs[j][1];
            if((rnk[x][y] > rnk[x][u]) && (rnk[u][x] < rnk[u][v])) {
                items.insert(x);
                items.insert(u);
            }
            if((rnk[x][y] > rnk[x][v]) && (rnk[v][x] < rnk[v][u])) {
                items.insert(x);
                items.insert(v);
            }
            if((rnk[y][x] > rnk[y][u]) && (rnk[u][y] < rnk[u][v])) {
                items.insert(y);
                items.insert(u);
            }
            if((rnk[y][x] > rnk[y][v]) && (rnk[v][y] < rnk[v][u])) {
                items.insert(y);
                items.insert(v);
            }
        }
    }
    return items.size();
}
```

This is the complete code for the problem where we are tasked with finding the number of unhappy friends. The function calculates whether a friend is unhappy based on their ranking preferences and the current pairings.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int unhappyFriends(int n, vector<vector<int>>& pref, vector<vector<int>>& pairs) {
	```
	This function takes the number of friends, a 2D vector `pref` representing the preferences of the friends, and a 2D vector `pairs` representing the current pairings.

2. **Variable Initialization**
	```cpp
	    vector<vector<int>> rnk(n, vector<int>(n, INT_MAX));
	```
	We initialize a 2D vector `rnk` to store the ranking of each friend for other friends. It is initialized with `INT_MAX` to indicate that no ranking has been set initially.

3. **Nested Loop**
	```cpp
	    for(int i = 0; i < pref.size(); i++) {
	```
	We loop through each friend's preference list.

4. **Inner Loop**
	```cpp
	        for(int j = 0; j < pref[i].size(); j++) {
	```
	This inner loop goes through the preference list of the current friend `i`.

5. **Rank Assignment**
	```cpp
	            rnk[i][pref[i][j]] = j;                
	```
	Here, we assign the rank of friend `pref[i][j]` as `j` (their index in the preference list) for friend `i`.

6. **Counter Initialization**
	```cpp
	    int cnt = 0;
	```
	We initialize a counter `cnt` to track the number of unhappy friends.

7. **Set Initialization**
	```cpp
	    set<int> items;
	```
	We initialize a set `items` to store the indices of unhappy friends.

8. **Outer Loop Over Pairs**
	```cpp
	    for(int i = 0; i < pairs.size(); i++) {
	```
	This loop iterates over each pair of friends.

9. **Inner Loop Over Pairs**
	```cpp
	        for(int j = i + 1; j < pairs.size(); j++) {
	```
	This inner loop checks for each pair of pairs to identify unhappy friends.

10. **Extract Pair Elements**
	```cpp
	            int x = pairs[i][0], y = pairs[i][1];
	```
	Extract the pair `x` and `y` from the current pair `i`.

11. **Extract Pair Elements**
	```cpp
	            int u = pairs[j][0], v = pairs[j][1];
	```
	Extract the pair `u` and `v` from the next pair `j`.

12. **Unhappiness Check 1**
	```cpp
	            if((rnk[x][y] > rnk[x][u]) && (rnk[u][x] < rnk[u][v])) {
	```
	Check if `x` prefers `y` over `u`, and if `u` prefers `x` over `v`. If true, both `x` and `u` are unhappy.

13. **Insert Unhappy Friends**
	```cpp
	                items.insert(x);
	```
	Add `x` to the set of unhappy friends.

14. **Insert Unhappy Friends**
	```cpp
	                items.insert(u);
	```
	Add `u` to the set of unhappy friends.

15. **Unhappiness Check 3**
	```cpp
	            if((rnk[x][y] > rnk[x][v]) && (rnk[v][x] < rnk[v][u])) {
	```
	Check if `x` prefers `y` over `v`, and if `v` prefers `x` over `u`. If true, both `x` and `v` are unhappy.

16. **Insert Unhappy Friends**
	```cpp
	                items.insert(x);
	```
	Add `x` to the set of unhappy friends.

17. **Insert Unhappy Friends**
	```cpp
	                items.insert(v);
	```
	Add `v` to the set of unhappy friends.

18. **Unhappiness Check 5**
	```cpp
	            if((rnk[y][x] > rnk[y][u]) && (rnk[u][y] < rnk[u][v])) {
	```
	Check if `y` prefers `x` over `u`, and if `u` prefers `y` over `v`. If true, both `y` and `u` are unhappy.

19. **Insert Unhappy Friends**
	```cpp
	                items.insert(y);
	```
	Add `y` to the set of unhappy friends.

20. **Insert Unhappy Friends**
	```cpp
	                items.insert(u);
	```
	Add `u` to the set of unhappy friends.

21. **Unhappiness Check 7**
	```cpp
	            if((rnk[y][x] > rnk[y][v]) && (rnk[v][y] < rnk[v][u])) {
	```
	Check if `y` prefers `x` over `v`, and if `v` prefers `y` over `u`. If true, both `y` and `v` are unhappy.

22. **Insert Unhappy Friends**
	```cpp
	                items.insert(y);
	```
	Add `y` to the set of unhappy friends.

23. **Insert Unhappy Friends**
	```cpp
	                items.insert(v);
	```
	Add `v` to the set of unhappy friends.

24. **Return Result**
	```cpp
	    return items.size();
	```
	Return the number of unique unhappy friends.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2)

The time complexity is O(n^2) because for each pair, we check all other pairs to determine if there is an unhappy friend.

### Space Complexity 💾
- **Best Case:** O(n^2)
- **Worst Case:** O(n^2)

The space complexity is O(n^2) due to the storage of the preference rankings for each person.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/count-unhappy-friends/description/)

---
{{< youtube GpJUwhzx258 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

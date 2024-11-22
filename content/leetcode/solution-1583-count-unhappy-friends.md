
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
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
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
};
{{< /highlight >}}
---

### Problem Statement

The problem requires us to determine how many friends are "unhappy" in a given set of pairs based on their preferences. Each friend has a list of preferences for who they would like to pair with, and they become unhappy if there exists someone they prefer more than their current partner who also prefers them back over their own partner. Our goal is to efficiently count the number of such unhappy friends.

### Approach

To tackle the problem, we can break down the solution into a series of clear steps:

1. **Preference Ranking**: For each friend, create a ranking of their preferences. This ranking will help us quickly determine how much they prefer one friend over another.

2. **Iterate Through Pairs**: Check each pair of pairs to see if any friend in the pairs would prefer another friend over their current partner, thereby leading to unhappiness.

3. **Count Unhappy Friends**: Maintain a set to keep track of all unique friends who are unhappy to avoid double counting.

4. **Return the Count**: Finally, return the size of the set, which represents the number of unique unhappy friends.

This approach allows us to efficiently determine the number of unhappy friends by using a ranking system and systematic checking of pairs.

### Code Breakdown (Step by Step)

Let’s analyze the code to understand how it implements the above approach:

```cpp
class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& pref, vector<vector<int>>& pairs) {
        vector<vector<int>> rnk(n, vector<int>(n, INT_MAX));
```

- **Class Definition**: We define a class `Solution` with a public member function `unhappyFriends`.
- **Ranking Initialization**: We create a 2D vector `rnk` that will hold the rank of preferences for each friend. `rnk[i][j]` will represent the ranking of friend `j` in the preferences of friend `i`, initialized to `INT_MAX` to represent that the friendship hasn't been established yet.

#### Building the Ranking System

```cpp
        for(int i = 0; i < pref.size(); i++) {
            for(int j = 0; j < pref[i].size(); j++) {
                rnk[i][pref[i][j]] = j;                
            }
        }
```

- **Preference Ranking**: We iterate through each friend’s preferences. For each friend `i`, we set the rank of each of their preferred friends in the `rnk` array. The rank is the index of the friend in their preference list, which indicates how much they prefer that friend.

#### Checking for Unhappy Friends

```cpp
        int cnt = 0;
        set<int> items;
        for(int i = 0; i < pairs.size(); i++) {
            for(int j = i + 1; j < pairs.size(); j++) {
                int x = pairs[i][0], y = pairs[i][1];
                int u = pairs[j][0], v = pairs[j][1];
```

- **Loop through Pairs**: We use two nested loops to go through each pair of pairs in the list `pairs`. `x` and `y` are the two friends in the first pair, while `u` and `v` are from the second pair.

#### Checking Conditions for Unhappiness

```cpp
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
```

- **Conditions**: For each pair, we check the following conditions:
  - If friend `x` prefers friend `u` over their partner `y`, and `u` prefers `x` over their partner `v`.
  - Similar checks are made for other combinations of friends.
- **Inserting Unhappy Friends**: If any of the above conditions hold true, we add the unhappy friends into the set `items` to keep track of unique unhappy friends.

#### Returning the Result

```cpp
        return items.size();
    }
};
```

- **Final Output**: The size of the `items` set is returned, which indicates the total number of unique unhappy friends.

### Complexity

- **Time Complexity**: The time complexity of this algorithm is \( O(p^2) \), where \( p \) is the number of pairs. In the worst case, we may have to check every pair against every other pair.
  
- **Space Complexity**: The space complexity is \( O(n^2) \) for the ranking matrix `rnk`, plus \( O(k) \) for the set of unhappy friends, where \( k \) is the number of unique unhappy friends.

### Conclusion

The provided solution effectively counts the number of unhappy friends by utilizing a ranking system to compare preferences. The systematic iteration through pairs of pairs allows for a thorough evaluation of potential unhappiness conditions. This method is efficient given the constraints typically present in competitive programming scenarios.

The clear structure of the code, combined with the logical progression from preference ranking to unhappiness checking, makes it easy to understand and maintain. This solution can be adapted to other problems involving preferences and relationships, showcasing its versatility in algorithm design.

In summary, the algorithm achieves its goal through careful management of preferences and efficient checking mechanisms, providing a robust solution to the problem of unhappy friends.

[`Link to LeetCode Lab`](https://leetcode.com/problems/count-unhappy-friends/description/)

---
{{< youtube GpJUwhzx258 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

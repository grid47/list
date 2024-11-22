
+++
authors = ["grid47"]
title = "Leetcode 2101: Detonate the Maximum Bombs"
date = "2024-04-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2101: Detonate the Maximum Bombs in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Depth-First Search","Breadth-First Search","Graph","Geometry"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "8NPbAvVXKR4"
youtube_upload_date="2023-06-02"
youtube_thumbnail="https://i.ytimg.com/vi/8NPbAvVXKR4/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
    #define ll long long int
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> gph(n);
        for(int i = 0; i < n; i++) {

            ll x1 = bombs[i][0];
            ll y1 = bombs[i][1];
            ll r1 = bombs[i][2];

            for(int j = 0; j < n; j++) {
                if(i != j) {
                    ll x2 = abs(x1 - bombs[j][0]);
                    ll y2 = abs(y1 - bombs[j][1]);
                    if(x2 * x2 + y2 * y2 <= r1 * r1) {
                        gph[i].push_back(j);
                    }
                }
            }
        }

        int ans = INT_MIN;
        for(int i = 0; i < n; i++) {
            int c = 0;
            vector<bool> vistd(n, false);
            dfs(gph, vistd, c, i);
            ans = max(ans, c);
        }
        return ans;
    }

    void dfs(vector<vector<int>> &gph, vector<bool> &vstd, int &c, int i) {
        if(vstd[i]) return;
        vstd[i] = true;
        c++;
        for(int j: gph[i])
            if(!vstd[j])
            dfs(gph, vstd, c, j);
    }
};
{{< /highlight >}}
---

### Problem Statement

In this problem, you are given a list of bombs, where each bomb is defined by three properties: `[x, y, r]`. Here, `(x, y)` represents the coordinates of the bomb on a 2D plane, and `r` is its blast radius. If one bomb's blast radius overlaps with another bomb's location, the second bomb can be detonated, potentially leading to a chain reaction of detonations. The task is to determine the maximum number of bombs that can be detonated in a single chain reaction if we start with an optimally chosen bomb.

### Approach

The solution models the problem as a graph traversal, where each bomb represents a node in a graph, and an edge exists from bomb `i` to bomb `j` if bomb `j` is within the blast radius of bomb `i`. This allows us to represent the potential chain reactions as paths in the graph.

The approach is divided into three key steps:

1. **Build the Graph**:
   - For each bomb `i`, we calculate its blast range in relation to each other bomb `j`. If the Euclidean distance between `i` and `j` is within the radius of `i`, then `j` can be detonated if `i` is detonated.
   - We use the squared distance formula to avoid calculating square roots, which simplifies the comparison: `x^2 + y^2 <= r^2`.
   - For each bomb that falls within the blast range, we add an edge in the graph `gph`, represented as an adjacency list, indicating a possible detonation chain from `i` to `j`.

2. **Run Depth-First Search (DFS) to Count the Chain of Detonations**:
   - After constructing the graph, we perform a DFS from each bomb to determine the maximum number of bombs that can be detonated in a single chain reaction starting from that bomb.
   - For each bomb `i`, we maintain a counter `c` for the number of detonations and a `visited` vector to avoid revisiting any bomb within the same DFS call.
   - We explore all neighbors in the graph using DFS to count how many bombs can be detonated starting from bomb `i`.

3. **Track the Maximum Detonations Across All Starting Points**:
   - For each starting bomb, we update a global maximum with the count of detonated bombs.
   - Finally, we return the highest number of detonations found across all possible starting points.

### Code Breakdown (Step by Step)

Here's a step-by-step breakdown of the code:

1. **Define the Graph and Bomb Properties**:
   ```cpp
   int n = bombs.size();
   vector<vector<int>> gph(n);
   ```
   - `n` represents the number of bombs, and `gph` is an adjacency list of size `n` to store each bomb's blast reach.

2. **Build the Graph**:
   ```cpp
   for(int i = 0; i < n; i++) {
       ll x1 = bombs[i][0];
       ll y1 = bombs[i][1];
       ll r1 = bombs[i][2];
       for(int j = 0; j < n; j++) {
           if(i != j) {
               ll x2 = abs(x1 - bombs[j][0]);
               ll y2 = abs(y1 - bombs[j][1]);
               if(x2 * x2 + y2 * y2 <= r1 * r1) {
                   gph[i].push_back(j);
               }
           }
       }
   }
   ```
   - We iterate over each bomb `i` and calculate whether each other bomb `j` lies within `i`'s blast radius.
   - If `j` falls within `i`'s radius, we add an edge from `i` to `j` in `gph`.

3. **DFS to Count Detonations**:
   ```cpp
   int ans = INT_MIN;
   for(int i = 0; i < n; i++) {
       int c = 0;
       vector<bool> vistd(n, false);
       dfs(gph, vistd, c, i);
       ans = max(ans, c);
   }
   ```
   - `ans` is initialized to track the maximum chain of detonations.
   - For each bomb `i`, we initialize a counter `c` and a `visited` vector to track bombs that have already detonated in the current chain reaction.
   - We run DFS on each bomb and update `ans` with the maximum count of detonations.

4. **DFS Helper Function**:
   ```cpp
   void dfs(vector<vector<int>> &gph, vector<bool> &vstd, int &c, int i) {
       if(vstd[i]) return;
       vstd[i] = true;
       c++;
       for(int j: gph[i])
           if(!vstd[j])
               dfs(gph, vstd, c, j);
   }
   ```
   - This function performs DFS to traverse all reachable bombs starting from `i`.
   - If a bomb has already detonated (visited), we return. Otherwise, we mark it as visited and increment `c`.
   - For each neighboring bomb `j`, we recursively perform DFS if `j` hasn’t already been detonated.

5. **Return the Result**:
   ```cpp
   return ans;
   ```
   - `ans` holds the maximum number of bombs detonated in a single chain reaction. We return `ans` as the final answer.

### Complexity Analysis

- **Time Complexity**: The time complexity is approximately \(O(n^2)\) due to the nested loops used when building the graph, where `n` is the number of bombs. Each bomb is checked against every other bomb to determine if it falls within the blast range.
- **Space Complexity**: The space complexity is \(O(n^2)\) as we store the graph in an adjacency list, which could have up to \(n^2\) edges if every bomb can detonate every other bomb.

### Conclusion

This solution models the problem as a graph traversal where each bomb has edges to other bombs within its blast range. By simulating chain reactions using DFS, we efficiently calculate the maximum number of bombs that can be detonated. This approach highlights the use of graph theory and traversal algorithms in solving complex chain-reaction problems, where graph edges represent potential actions (in this case, detonations) based on spatial constraints. This method ensures we explore the optimal starting point to maximize the detonation count efficiently.

[`Link to LeetCode Lab`](https://leetcode.com/problems/detonate-the-maximum-bombs/description/)

---
{{< youtube 8NPbAvVXKR4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

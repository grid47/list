
+++
authors = ["grid47"]
title = "Leetcode 2924: Find Champion II"
date = "2024-01-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2924: Find Champion II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Graph"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "axwSqMVQ1x4"
youtube_upload_date="2023-11-05"
youtube_thumbnail="https://i.ytimg.com/vi/axwSqMVQ1x4/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        int ans = -1, count = 0;
        vector<int> indegree(n, 0);
        for(auto e: edges) indegree[e[1]]++;
        for(int i = 0; i < n; ++i) {
            if(indegree[i] == 0) {count++; ans = i; }
        }
        return count > 1?-1:ans;
    }
};
{{< /highlight >}}
---

### Problem Statement:
The task is to find the "champion" in a directed graph, where each node represents a player, and directed edges represent the outcomes of games between players. The champion is defined as a player who has not lost to any other player, meaning there are no incoming edges to that player from any other player. If there is more than one player with no incoming edges or if no such player exists, return `-1`.

This problem is essentially about identifying a node (player) in a directed graph with zero incoming edges. If there is exactly one such node, it is the champion; otherwise, the graph does not have a unique champion.

### Approach:
To solve this problem, we need to follow these steps:

1. **Understanding the Input:**
   The input consists of:
   - `n`: The number of players (nodes in the graph).
   - `edges`: A list of directed edges, where each edge `[u, v]` indicates that player `u` won against player `v` (there is a directed edge from `u` to `v`).

2. **Champion Criteria:**
   The champion should be a player who has:
   - Zero incoming edges, i.e., no other player has won against the champion.
   - If there is more than one such player or if no player satisfies this condition, the result should be `-1`.

3. **Graph Representation and In-degree Calculation:**
   We can calculate the number of incoming edges (in-degree) for each player. The player with zero in-degree is a candidate for the champion, but we must ensure there is exactly one player with this property.

4. **Algorithm Steps:**
   - Initialize an array `indegree` of size `n` to keep track of the number of incoming edges for each player.
   - Iterate over the list of edges and update the in-degree of the destination player for each edge.
   - After calculating the in-degree for all players, check how many players have zero in-degree. If exactly one player has zero in-degree, that player is the champion.
   - If more than one player has zero in-degree, return `-1`, as there cannot be a unique champion.

### Code Breakdown (Step by Step):

1. **Function Definition:**
   The function `findChampion` takes two arguments:
   - `n`: The number of players (nodes).
   - `edges`: A 2D vector representing the directed edges between players.

   ```cpp
   int findChampion(int n, vector<vector<int>>& edges) {
   ```

2. **Initialize Variables:**
   - `ans`: Initially set to `-1` to represent that no champion is found by default.
   - `count`: A counter to track how many players have zero in-degree.
   - `indegree`: A vector of size `n` initialized to `0`, which will store the number of incoming edges for each player.

   ```cpp
   int ans = -1, count = 0;
   vector<int> indegree(n, 0);
   ```

3. **Calculate In-Degree for Each Player:**
   The algorithm iterates over the list of edges, and for each edge `[u, v]`, it increments the in-degree of player `v`. This is because player `v` loses to player `u`, meaning there is a directed edge from `u` to `v`.

   ```cpp
   for(auto e: edges) indegree[e[1]]++;
   ```

   After this loop, the `indegree` vector contains the number of incoming edges for each player.

4. **Identify Players with Zero In-Degree:**
   The algorithm then iterates through the `indegree` vector to find players with zero in-degree. If a player has zero in-degree, it means that player has not lost to anyone else and is a candidate for being the champion. The `count` variable keeps track of how many players have zero in-degree, and `ans` stores the index of the last player with zero in-degree.

   ```cpp
   for(int i = 0; i < n; ++i) {
       if(indegree[i] == 0) { count++; ans = i; }
   }
   ```

5. **Return the Champion or -1:**
   After checking all players:
   - If more than one player has zero in-degree (`count > 1`), return `-1`, indicating that there is no unique champion.
   - Otherwise, return `ans`, the index of the player with zero in-degree, which is the champion.

   ```cpp
   return count > 1 ? -1 : ans;
   ```

### Complexity:

1. **Time Complexity:**
   The time complexity of this solution is \(O(n + m)\), where:
   - `n` is the number of players (nodes).
   - `m` is the number of edges (games).
   
   - The first loop iterates through all the edges, which takes \(O(m)\) time to update the in-degree of the destination players.
   - The second loop iterates through all the players (nodes), which takes \(O(n)\) time to check the in-degree of each player.
   
   Therefore, the overall time complexity is \(O(n + m)\), which is efficient for this problem.

2. **Space Complexity:**
   The space complexity is \(O(n)\), where `n` is the number of players. The algorithm uses an additional array `indegree` of size `n` to store the in-degree values. No other significant space is used, so the space complexity is linear in terms of the number of players.

### Conclusion:
This solution efficiently identifies the champion in a directed graph representing players and their game outcomes. The key idea is to track the number of incoming edges (in-degree) for each player. The player with zero incoming edges, if unique, is the champion. The algorithm ensures that the result is obtained in linear time with respect to the number of players and edges, making it suitable for large inputs.

The approach guarantees correctness by:
- Using the in-degree property to identify candidates for the champion.
- Ensuring there is exactly one player with zero in-degree to confirm the uniqueness of the champion.

The time complexity of \(O(n + m)\) ensures that the solution is efficient even for large graphs, and the space complexity of \(O(n)\) makes it scalable. This makes the solution an optimal choice for this problem.

[`Link to LeetCode Lab`](https://leetcode.com/problems/find-champion-ii/description/)

---
{{< youtube axwSqMVQ1x4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

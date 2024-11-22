
+++
authors = ["grid47"]
title = "Leetcode 841: Keys and Rooms"
date = "2024-08-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 841: Keys and Rooms in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Depth-First Search","Breadth-First Search","Graph"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "i89fYz8JX7U"
youtube_upload_date="2024-04-06"
youtube_thumbnail="https://i.ytimg.com/vi/i89fYz8JX7U/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> vis(rooms.size(), false);
        vis[0] = true;
        dfs(rooms, vis, 0);
        
        for(auto x: vis)
            if(!x) return x;
        
        return true;
    }
    
    void dfs(vector<vector<int>>& rooms, vector<bool> &vis, int cur) {
        vis[cur] = true;
        for(auto x: rooms[cur]) {
            if(!vis[x])
                dfs(rooms, vis, x);
        }
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks whether it is possible to visit all rooms starting from room 0 in a house represented by a 2D array, where each room contains a list of keys to other rooms. Specifically, the problem involves determining whether starting from room 0, we can use the keys in each room to unlock all other rooms. Each key in a room allows you to open a specific other room, and once opened, you can access the keys from that room and continue your exploration.

The task is to return `true` if it is possible to visit all rooms starting from room 0, and `false` otherwise.

### Approach

To solve this problem, we can treat the house as a graph, where each room is a node, and the keys represent edges between the rooms. The goal is to check if, starting from room 0, we can reach all other rooms. This problem can be solved using graph traversal techniques, specifically Depth-First Search (DFS), since it allows us to explore all reachable nodes from a starting node.

Here’s how we approach the solution:

1. **Graph Representation**: 
   - The rooms are represented as a 2D vector where each index corresponds to a room, and each entry in a room is a list of keys (room indices) that the room provides.
   - We start at room 0 and aim to explore all rooms by visiting each room’s keys.

2. **Tracking Visited Rooms**:
   - To track the rooms we’ve already visited, we use a `visited` vector initialized to `false` for all rooms. When we visit a room, we mark it as `true` in the `visited` array.
   - The traversal is initiated from room 0, and we explore all connected rooms by visiting each room’s keys.

3. **Depth-First Search (DFS)**:
   - The DFS algorithm is ideal for this problem because it explores as far as possible along each branch before backtracking. Starting from room 0, we recursively visit all rooms that can be unlocked by the keys in each room.
   - If, at the end of the traversal, all rooms are marked as visited, then all rooms are reachable, and we return `true`. If any room is not visited, we return `false`.

4. **Termination**:
   - After performing DFS, we simply check if all rooms are visited. If any room is unvisited, it means that room is inaccessible from room 0, and the answer should be `false`.

### Code Breakdown (Step by Step)

Let’s break down the code into its main components:

1. **Function Signature**:
   ```cpp
   bool canVisitAllRooms(vector<vector<int>>& rooms)
   ```
   This function takes a 2D vector `rooms`, where each subvector represents the list of keys available in each room. It returns `true` if all rooms are accessible from room 0, and `false` otherwise.

2. **Initialize Visited Vector**:
   ```cpp
   vector<bool> vis(rooms.size(), false);
   vis[0] = true;
   ```
   - `vis` is a boolean vector of size equal to the number of rooms. It tracks whether each room has been visited during DFS.
   - We initialize all rooms as not visited (`false`), and we set room 0 as visited (`true`) because we start from there.

3. **Perform Depth-First Search (DFS)**:
   ```cpp
   dfs(rooms, vis, 0);
   ```
   - We call the DFS function to start the exploration from room 0. This will visit all reachable rooms from room 0.

4. **DFS Function**:
   ```cpp
   void dfs(vector<vector<int>>& rooms, vector<bool>& vis, int cur) {
       vis[cur] = true;
       for (auto x : rooms[cur]) {
           if (!vis[x]) {
               dfs(rooms, vis, x);
           }
       }
   }
   ```
   - The DFS function takes the `rooms` array, the `visited` vector `vis`, and the current room index `cur` as arguments.
   - We first mark the current room as visited (`vis[cur] = true`).
   - Then, for each key in the current room (`rooms[cur]`), we recursively call DFS for any room that has not been visited yet (`if (!vis[x])`).

5. **Check if All Rooms are Visited**:
   ```cpp
   for (auto x : vis)
       if (!x) return x;
   return true;
   ```
   - After the DFS traversal, we check if all rooms have been visited. If any room is unvisited (`!x`), we return `false`. If all rooms have been visited, we return `true`.

6. **Return Result**:
   - Finally, we return `true` if all rooms are visited, meaning all rooms can be accessed starting from room 0.

### Complexity

1. **Time Complexity**:
   - The time complexity of this solution is **O(R + K)**, where `R` is the number of rooms, and `K` is the total number of keys (i.e., the total number of elements in all the rooms' key lists). This is because, in the worst case, we visit each room once and each key once while performing DFS. Therefore, the time complexity is linear in terms of the number of rooms and keys in total.

2. **Space Complexity**:
   - The space complexity is **O(R + K)** as well because we store the `visited` vector of size `R` and the recursive call stack for DFS, which can be at most `R` deep. Additionally, the space required to store the keys in each room contributes to the total space complexity.

### Conclusion

In conclusion, this solution efficiently checks whether all rooms can be visited starting from room 0 using Depth-First Search (DFS). By marking rooms as visited and recursively exploring each room’s keys, we ensure that we only visit each room once. The time and space complexities of the solution are both linear in terms of the number of rooms and keys, making this approach efficient for solving the problem even for large grids. This method leverages standard graph traversal techniques and is well-suited for problems involving connectivity in graphs or grids.

[`Link to LeetCode Lab`](https://leetcode.com/problems/keys-and-rooms/description/)

---
{{< youtube i89fYz8JX7U >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |


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
comments = true
+++



---
You are in a building with multiple rooms, each containing a set of keys to unlock other rooms. Initially, only the first room (room 0) is unlocked. You are tasked with determining whether you can visit all the rooms, starting from room 0. To enter a locked room, you must have its corresponding key, which can only be obtained by visiting other rooms.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a 2D array 'rooms' where each rooms[i] contains a list of keys that can be obtained by visiting room i. Each key in the list unlocks a specific room in the building. Your goal is to check if it's possible to visit all rooms starting from room 0.
- **Example:** `Input: rooms = [[1, 2], [3], [3], [0]]`
- **Constraints:**
	- 2 <= n <= 1000
	- 0 <= rooms[i].length <= 1000
	- 1 <= sum(rooms[i].length) <= 3000
	- 0 <= rooms[i][j] < n
	- All the values in rooms[i] are unique.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return true if it's possible to visit all rooms starting from room 0; otherwise, return false.
- **Example:** `Output: true`
- **Constraints:**
	- The output should be a boolean value: true if all rooms can be visited, false otherwise.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to use a depth-first search (DFS) approach to simulate visiting each room and collecting keys. Keep track of which rooms have been visited, and ensure all rooms can be visited by collecting the necessary keys.

- Step 1: Initialize a 'visited' array to track rooms that have been visited.
- Step 2: Use DFS starting from room 0, visiting all rooms that can be unlocked by the keys you collect.
- Step 3: Once all rooms are visited, return true. If there are any rooms that remain unvisited, return false.
{{< dots >}}
### Problem Assumptions ✅
- Each room contains a list of keys, which might allow access to other rooms.
- Starting at room 0, it is possible to gather keys to unlock additional rooms.
- The solution assumes that a DFS approach will help in determining whether all rooms can be visited.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: [[1, 2], [3], [3], [0]]`  \
  **Explanation:** Starting from room 0, we can collect key 1 and visit room 1. From room 1, we collect key 3 and visit room 3. Finally, from room 3, we collect key 0 and can visit all rooms.

- **Input:** `Input: [[1,3],[3,0,1],[2],[0]]`  \
  **Explanation:** Here, starting from room 0, we collect key 1 and visit room 1. However, we cannot access room 2 because the only key to room 2 is located in room 2 itself, which remains locked.

{{< dots >}}
## Approach 🚀
To solve this problem, we can use a depth-first search (DFS) strategy. Starting at room 0, we explore all accessible rooms by collecting keys. The DFS approach will ensure we cover all possible rooms that can be reached by following the key-paths.

### Initial Thoughts 💭
- We need to visit rooms iteratively, collecting keys along the way.
- DFS is a good fit for this problem, as it allows us to explore all reachable rooms from room 0.
- It is crucial to maintain a visited set to ensure we do not revisit rooms and fall into an infinite loop.
{{< dots >}}
### Edge Cases 🌐
- An empty input or a grid with fewer than 2 rooms would not be valid according to the constraints.
- If the number of rooms is large, ensure the DFS traversal is efficient enough to handle up to 1000 rooms.
- Ensure that rooms with no keys and rooms that cannot be unlocked are handled properly.
- The grid dimensions and key relationships should be carefully handled to ensure correctness.
{{< dots >}}
## Code 💻
```cpp
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
```

This function checks if all rooms can be visited, utilizing depth-first search (DFS) to explore the rooms recursively.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	bool canVisitAllRooms(vector<vector<int>>& rooms) {
	```
	This is the function declaration for `canVisitAllRooms`, which checks if all rooms can be visited starting from room 0.

2. **Variable Initialization**
	```cpp
	    vector<bool> vis(rooms.size(), false);
	```
	A vector `vis` is initialized to track whether each room has been visited. All rooms are initially marked as not visited.

3. **Set Start Room**
	```cpp
	    vis[0] = true;
	```
	The starting room (room 0) is marked as visited.

4. **DFS Call**
	```cpp
	    dfs(rooms, vis, 0);
	```
	The depth-first search (DFS) function is called to explore all rooms starting from room 0.

5. **Loop Through Visited Rooms**
	```cpp
	    for(auto x: vis)
	```
	A loop iterates through the `vis` vector to check if all rooms have been visited.

6. **Return False if Any Room is Unvisited**
	```cpp
	        if(!x) return x;
	```
	If any room has not been visited, the function immediately returns `false`.

7. **Return True if All Rooms are Visited**
	```cpp
	    return true;
	```
	If all rooms are visited, the function returns `true`.

8. **Empty Line**
	```cpp
	
	```
	An empty line for code separation.

9. **DFS Function Declaration**
	```cpp
	void dfs(vector<vector<int>>& rooms, vector<bool> &vis, int cur) {
	```
	This is the function declaration for `dfs`, which performs depth-first search to visit rooms recursively.

10. **Mark Current Room as Visited**
	```cpp
	    vis[cur] = true;
	```
	The current room is marked as visited.

11. **Loop Through Current Room's Neighbors**
	```cpp
	    for(auto x: rooms[cur]) {
	```
	The function loops through the rooms connected to the current room (`cur`) and recursively visits them if they haven't been visited.

12. **Check if Neighbor is Visited**
	```cpp
	        if(!vis[x])
	```
	The function checks if a neighboring room has been visited. If not, it proceeds to visit it.

13. **Recursive DFS Call**
	```cpp
	            dfs(rooms, vis, x);
	```
	A recursive call to the DFS function is made to visit the neighboring room (`x`).

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n + k)
- **Worst Case:** O(n + k)

The time complexity is proportional to the number of rooms (n) and the number of keys (k) that need to be processed during the DFS traversal.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n + k)

The space complexity is dependent on the space needed to track the visited rooms and the keys collected, which is O(n + k).

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/keys-and-rooms/description/)

---
{{< youtube i89fYz8JX7U >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

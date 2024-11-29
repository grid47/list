
+++
authors = ["grid47"]
title = "Leetcode 2039: The Time When the Network Becomes Idle"
date = "2024-04-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2039: The Time When the Network Becomes Idle in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Breadth-First Search","Graph"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "9URBYJ62lyY"
youtube_upload_date="2021-10-16"
youtube_thumbnail="https://i.ytimg.com/vi/9URBYJ62lyY/maxresdefault.jpg"
comments = true
+++



---
You are managing a network of servers connected by communication channels. One server, labeled as 0, acts as the master server, while the others are data servers. Each data server sends a message to the master server at the start and waits for a reply. The reply travels back via the same route the message took. If a server does not receive a reply within a specific period (defined by its patience value), it resends the message. The goal is to determine when the network will become idle, meaning there are no active messages being transmitted or received.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The network is represented by edges and patience values for each server.
- **Example:** `edges = [[0,1],[1,2]], patience = [0,3,2]`
- **Constraints:**
	- n == patience.length
	- 2 <= n <= 10^5
	- patience[0] == 0
	- 1 <= patience[i] <= 10^5 for 1 <= i < n
	- 1 <= edges.length <= min(10^5, n * (n - 1) / 2)
	- edges[i].length == 2
	- 0 <= ui, vi < n
	- ui != vi
	- No duplicate edges exist, and all servers are connected.

{{< dots >}}
### Output Specifications 📤
- **Output:** The function returns the earliest time (in seconds) when the network becomes idle.
- **Example:** `Output: 7`
- **Constraints:**
	- The returned time is a positive integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** Calculate the time at which the last reply is received, accounting for resending rules based on patience values.

- Construct a graph representation of the network using the edges.
- Perform a Breadth-First Search (BFS) to compute the shortest distance from the master server (0) to all other servers.
- For each server, calculate the round-trip time for its messages.
- Determine the last time a server resends its message before the network becomes idle.
- Find the maximum time across all servers and return it as the result.
{{< dots >}}
### Problem Assumptions ✅
- Messages travel optimally between servers using the shortest path.
- Replies are sent instantly upon reaching the master server.
- Servers only resend messages if they do not receive a reply within their patience interval.
{{< dots >}}
## Examples 🧩
- **Input:** `edges = [[0,1],[1,2]], patience = [0,3,2]`  \
  **Explanation:** Server 1 sends its message and receives a reply by second 2, so no resends occur. Server 2 resends its message once before receiving a reply by second 4. The network becomes idle at second 7.

- **Input:** `edges = [[0,1],[0,2],[1,2]], patience = [0,5,5]`  \
  **Explanation:** Both servers 1 and 2 receive replies by second 2. No resends occur, and the network becomes idle at second 3.

{{< dots >}}
## Approach 🚀
The solution uses BFS to compute shortest distances, followed by calculations of resending times and idle times for each server.

### Initial Thoughts 💭
- Shortest distance is crucial for determining the timing of replies.
- Servers with higher patience values may not resend messages often, reducing overall activity in the network.
- Using a BFS ensures efficient computation of shortest distances for all servers.
- Patience values affect the timing of last resends, which determines the idle time.
{{< dots >}}
### Edge Cases 🌐
- None, as input is guaranteed to have at least two servers.
- A fully connected network with maximum n = 10^5 servers.
- All servers except the master server have the same patience value.
- Servers are connected in a straight line.
- No duplicate edges and all servers are connected.
{{< dots >}}
## Code 💻
```cpp
int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {

    int n = patience.size();        
    vector<vector<int>> grid(n);
    
    for(auto e: edges) {
        grid[e[0]].push_back(e[1]);
        grid[e[1]].push_back(e[0]);
    }
    
    vector<int> sd(n, INT_MAX); // shortest distance(sd) to master;
    
    sd[0] = 0;
    
    queue<int> q;
    vector<int> vis(n, 0);
    q.push(0);
    vis[0] = 1;
    
    int t = 0;
    while(!q.empty()) {
        int sz = q.size();
            t++;            
        while(sz--) {
            int node = q.front();
            q.pop();
            for(auto it: grid[node]) {
                if(vis[it]) continue;
                vis[it] = true;
                sd[it] = t;
                q.push(it);
            }
        }
    }
    
    int mx = 0;
    for(int i = 0; i < n; i++) {
        int dist = 2 * sd[i];
        int pat = patience[i];
        if(pat >= dist) {
            mx = max(mx, dist);
        } else {
            
            int mod = dist % pat == 0? pat: dist % pat;
            
            mx = max(mx, dist - mod + dist);
        }
    }
    return mx + 1;
}
```

This function calculates the time when all nodes in a network become idle after communication. It computes the shortest distances from the source node, and based on the patience of each node, it determines when they will stop waiting for messages.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
	```
	The function `networkBecomesIdle` takes two arguments: a list of edges representing the network and a list `patience` containing the patience level of each node. It returns the time when the entire network becomes idle.

2. **Variable Initialization**
	```cpp
	    int n = patience.size();        
	```
	The variable `n` stores the number of nodes in the network, determined by the size of the `patience` array.

3. **Grid Initialization**
	```cpp
	    vector<vector<int>> grid(n);
	```
	The `grid` variable is initialized as a 2D vector to represent the network as an adjacency list, where each node points to its connected nodes.

4. **Building Adjacency List**
	```cpp
	    for(auto e: edges) {
	```
	This loop iterates over all edges in the network and constructs the adjacency list for each node by adding the connected nodes.

5. **Adjacency List Population**
	```cpp
	        grid[e[0]].push_back(e[1]);
	```
	For each edge, the nodes are bidirectionally connected, so this line adds the destination node to the source node’s adjacency list.

6. **Adjacency List Population**
	```cpp
	        grid[e[1]].push_back(e[0]);
	```
	Similarly, the destination node adds the source node to its adjacency list, completing the bidirectional connection.

7. **Distance Initialization**
	```cpp
	    vector<int> sd(n, INT_MAX); // shortest distance(sd) to master;
	```
	The `sd` vector is initialized to store the shortest distance from the master node (node 0) to all other nodes, initially set to `INT_MAX` (infinity).

8. **Distance Initialization**
	```cpp
	    sd[0] = 0;
	```
	The distance to the master node (node 0) is set to 0, as the master node is the starting point.

9. **Queue Initialization**
	```cpp
	    queue<int> q;
	```
	A queue `q` is initialized for Breadth-First Search (BFS) to traverse the network.

10. **Visited Initialization**
	```cpp
	    vector<int> vis(n, 0);
	```
	The `vis` vector is initialized to keep track of visited nodes during the BFS traversal.

11. **Queue Push**
	```cpp
	    q.push(0);
	```
	The master node (node 0) is pushed into the queue to start the BFS traversal.

12. **Visited Update**
	```cpp
	    vis[0] = 1;
	```
	The master node is marked as visited.

13. **Time Initialization**
	```cpp
	    int t = 0;
	```
	The variable `t` tracks the time it takes for each node to receive a message during the BFS traversal.

14. **BFS Loop**
	```cpp
	    while(!q.empty()) {
	```
	This `while` loop runs as long as there are nodes in the queue, performing the BFS to compute shortest distances.

15. **Queue Size**
	```cpp
	        int sz = q.size();
	```
	The variable `sz` stores the number of nodes in the current level of the BFS.

16. **Time Increment**
	```cpp
	            t++;            
	```
	The time `t` is incremented as we move to the next level of the BFS.

17. **BFS Inner Loop**
	```cpp
	        while(sz--) {
	```
	This inner loop iterates over each node in the current BFS level.

18. **Node Processing**
	```cpp
	            int node = q.front();
	```
	The current node is retrieved from the front of the queue for processing.

19. **Queue Pop**
	```cpp
	            q.pop();
	```
	The current node is removed from the queue.

20. **Neighbor Traversal**
	```cpp
	            for(auto it: grid[node]) {
	```
	This loop iterates over all the neighbors of the current node.

21. **Visited Check**
	```cpp
	                if(vis[it]) continue;
	```
	If a neighbor has already been visited, we skip it.

22. **Visited Update**
	```cpp
	                vis[it] = true;
	```
	The neighbor is marked as visited.

23. **Distance Update**
	```cpp
	                sd[it] = t;
	```
	The shortest distance to the neighbor is updated to the current time `t`.

24. **Queue Push**
	```cpp
	                q.push(it);
	```
	The neighbor is added to the queue for further processing.

25. **Max Time Calculation**
	```cpp
	    int mx = 0;
	```
	The variable `mx` will store the maximum time required for the last node to become idle.

26. **Time Calculation Loop**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	This loop calculates the time for each node to become idle.

27. **Distance to Time Calculation**
	```cpp
	        int dist = 2 * sd[i];
	```
	The time is calculated as twice the shortest distance because the message has to travel back and forth.

28. **Patience Check**
	```cpp
	        int pat = patience[i];
	```
	The patience of each node is retrieved to determine how long they will wait for a message before becoming idle.

29. **Patience Check Logic**
	```cpp
	        if(pat >= dist) {
	```
	If the node’s patience is greater than or equal to the distance, it will become idle after the message travels back and forth.

30. **Max Time Update**
	```cpp
	            mx = max(mx, dist);
	```
	The maximum time is updated if this node’s time is greater than the previous maximum.

31. **Patience Check Else**
	```cpp
	        } else {
	```
	If the node’s patience is less than the time required, it will become idle earlier.

32. **Mod Time Calculation**
	```cpp
	            int mod = dist % pat == 0? pat: dist % pat;
	```
	The time calculation is adjusted based on the node’s patience and the message travel time.

33. **Max Time Update**
	```cpp
	            mx = max(mx, dist - mod + dist);
	```
	The maximum time is updated based on the adjusted time calculation.

34. **Return Statement**
	```cpp
	    return mx + 1;
	```
	The function returns the maximum time `mx` plus 1 to account for the last time unit.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n + m), where n is the number of servers and m is the number of edges.
- **Average Case:** O(n + m)
- **Worst Case:** O(n + m)

BFS traversal and idle time calculation are linear in terms of servers and edges.

### Space Complexity 💾
- **Best Case:** O(n + m)
- **Worst Case:** O(n + m)

Graph representation and BFS queue storage dominate space usage.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/the-time-when-the-network-becomes-idle/description/)

---
{{< youtube 9URBYJ62lyY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

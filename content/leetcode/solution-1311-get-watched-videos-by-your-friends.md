
+++
authors = ["grid47"]
title = "Leetcode 1311: Get Watched Videos by Your Friends"
date = "2024-06-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1311: Get Watched Videos by Your Friends in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Breadth-First Search","Graph","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
        
    vector<string> watchedVideosByFriends(vector<vector<string>>& wv, vector<vector<int>>& f, int id, int k) {
        
        int n = f.size();
        vector<bool> vis(n, false);
        queue<int> q;
        q.push(id);
        vis[id] = true;
        
        while(k--) {
            int sz = q.size();
            while(sz--) {
                int top = q.front();
                q.pop();
                for(auto it: f[top]) {
                    if(!vis[it]) {
                        vis[it] = true;
                        q.push(it);
                    }
                }
            }
        }
        
        map<string, int> mp;
        while(!q.empty()) {
            int fr = q.front();
            q.pop();
            for(string x: wv[fr]) {
                mp[x]++;
            }
        }
        
        vector<pair<int, string>> ans;
        for(auto it: mp) {
            ans.push_back({it.second, it.first});
        }

        sort(ans.begin(), ans.end());
     
        vector<string> res;
        for(auto it: ans)
            res.push_back(it.second);
        
        return res;
    }
};
{{< /highlight >}}
---


### Problem Statement
Given a social network represented as an adjacency list, where each node represents a person, we are given:
1. A 2D list `wv` where `wv[i]` is a list of videos watched by person `i`.
2. A 2D list `f` where `f[i]` contains the IDs of person `i`'s friends.
3. An integer `id`, representing a specific person's ID.
4. An integer `k`, representing the "friendship level" (or depth of connections).

The goal is to retrieve a list of videos watched by friends exactly `k` levels away from the given `id`, sorted by frequency and then alphabetically.

### Approach
The approach is to use a Breadth-First Search (BFS) to find friends at the exact "friendship level" `k` and then determine which videos were watched by these friends. BFS is ideal here because it explores each friendship level layer by layer.

1. **Breadth-First Search (BFS)**:
   - Initialize a `queue` with the start person (`id`) and mark them as visited.
   - For each level up to `k`, process the current level's friends and add their friends (if unvisited) to the queue.
   - After reaching exactly `k` levels, the queue will contain the IDs of friends who are exactly `k` levels away from `id`.

2. **Counting Video Frequencies**:
   - Use a map to count the frequency of each video watched by the friends at level `k`. For each friend at level `k`, add their watched videos to the map, incrementing the count for each video.

3. **Sorting Videos by Frequency and Name**:
   - Sort the videos based on frequency and then lexicographically for videos with the same frequency.
   - Return a list of video names in the desired sorted order.

### Code Breakdown (Step by Step)

1. **Initialize the BFS and Visited Array**:
   - Mark the starting person as visited, push them to the queue, and set up a `vis` array to avoid revisiting.

   ```cpp
   int n = f.size();
   vector<bool> vis(n, false);
   queue<int> q;
   q.push(id);
   vis[id] = true;
   ```

2. **Perform BFS up to `k` Levels**:
   - For each level up to `k`, process each friend in the queue.
   - For each friend, push their unvisited friends to the queue for the next level.
   
   ```cpp
   while(k--) {
       int sz = q.size();
       while(sz--) {
           int top = q.front();
           q.pop();
           for(auto it: f[top]) {
               if(!vis[it]) {
                   vis[it] = true;
                   q.push(it);
               }
           }
       }
   }
   ```

3. **Count Video Frequencies for Friends at Level `k`**:
   - For each friend remaining in the queue after `k` levels, update the frequency map for their watched videos.

   ```cpp
   map<string, int> mp;
   while(!q.empty()) {
       int fr = q.front();
       q.pop();
       for(string x: wv[fr]) {
           mp[x]++;
       }
   }
   ```

4. **Sort Videos by Frequency and Alphabetically**:
   - Convert the map into a vector of pairs and sort them by frequency and then alphabetically.

   ```cpp
   vector<pair<int, string>> ans;
   for(auto it: mp) {
       ans.push_back({it.second, it.first});
   }
   sort(ans.begin(), ans.end());
   ```

5. **Extract Sorted Video Names**:
   - Create a result vector with only the sorted video names and return it.

   ```cpp
   vector<string> res;
   for(auto it: ans)
       res.push_back(it.second);
   
   return res;
   ```

### Complexity Analysis

- **Time Complexity**: \(O(n + e + m \log m)\)
   - \(O(n + e)\) for BFS traversal where \(n\) is the number of people and \(e\) is the number of friendships.
   - Counting video frequencies is \(O(m)\), where \(m\) is the total number of videos by level `k` friends.
   - Sorting the videos takes \(O(m \log m)\).

- **Space Complexity**: \(O(n + m)\) for the queue, visited array, map, and result vector.

### Conclusion
This solution efficiently finds the most-watched videos by friends at a specified friendship level using BFS and frequency-based sorting. It is well-suited for large social networks, as BFS efficiently explores levels and ensures that only friends exactly `k` levels away are considered. By organizing and sorting based on video popularity and lexicographical order, the solution provides clear and accurate results. This approach is both scalable and effective for friendship-based video recommendation systems.

[`Link to LeetCode Lab`](https://leetcode.com/problems/get-watched-videos-by-your-friends/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

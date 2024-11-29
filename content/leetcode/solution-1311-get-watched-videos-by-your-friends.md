
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
comments = true
+++



---
You are given `n` people with unique IDs and two lists: `watchedVideos` and `friends`. For a given ID and a level `k`, find the list of videos watched by people at exactly level `k` from you. Return the videos ordered by their frequency (in increasing order), and alphabetically if there is a tie in frequency.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two arrays: `watchedVideos` (list of lists of strings) and `friends` (list of lists of integers). Each list contains videos watched by each person and their corresponding friends, respectively.
- **Example:** `Input: watchedVideos = [["Music","Gaming"],["Vlog"],["Music","Gaming"],["Cooking"]], friends = [[1,2],[0,3],[0,3],[1,2]], id = 0, level = 1`
- **Constraints:**
	- 2 <= n <= 100
	- 1 <= watchedVideos[i].length <= 100
	- 1 <= watchedVideos[i][j].length <= 8
	- 0 <= friends[i].length < n
	- 0 <= friends[i][j] < n
	- 0 <= id < n
	- 1 <= level < n
	- if friends[i] contains j, then friends[j] contains i

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is a list of videos sorted first by frequency in increasing order, and alphabetically for ties in frequency.
- **Example:** `Output: ["Gaming","Music"]`
- **Constraints:**
	- The output list must contain videos ordered by frequency and alphabetically for tied frequencies.

{{< dots >}}
### Core Logic 🔍
**Goal:** Identify and sort the videos watched by people at exactly level `k` from the given `id`.

- Use breadth-first search (BFS) to traverse the graph of friends, identifying people at level `k` from the given `id`.
- Track the frequency of videos watched by people at level `k`.
- Sort the videos based on their frequency and alphabetically for ties.
{{< dots >}}
### Problem Assumptions ✅
- The input arrays are valid and all constraints are respected.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: watchedVideos = [["Music","Gaming"],["Vlog"],["Music","Gaming"],["Cooking"]], friends = [[1,2],[0,3],[0,3],[1,2]], id = 0, level = 1`  \
  **Explanation:** The BFS traversal identifies the people at level 1 from the given ID (0), and the videos they watched are counted. The result is the list of videos ordered by their frequency.

{{< dots >}}
## Approach 🚀
We will use a breadth-first search (BFS) approach to explore friends at different levels and track video frequencies.

### Initial Thoughts 💭
- BFS is ideal for finding people at a specific level in an unweighted graph like the friendship network.
- Start by exploring the friends of the given `id` at level 1, then expand to higher levels if necessary.
{{< dots >}}
### Edge Cases 🌐
- If there are no friends at the specified level, the result should be an empty list.
- Handle the case where `n` is large, ensuring the solution is efficient.
- Consider the case where all people watched the same video, and the video list should return only that video.
- Ensure the solution efficiently handles the constraints, including large numbers of videos and friends.
{{< dots >}}
## Code 💻
```cpp
    
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
```

This function 'watchedVideosByFriends' helps to determine the most watched videos by friends within a specific distance, 'k'. It uses breadth-first search (BFS) to explore the friend network, then counts how many times each video is watched by the friends up to 'k' steps away.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<string> watchedVideosByFriends(vector<vector<string>>& wv, vector<vector<int>>& f, int id, int k) {
	```
	The function 'watchedVideosByFriends' is declared, which takes in a list of video watch data 'wv', a list of friend relationships 'f', and the starting person 'id' and the maximum number of friend hops 'k'.

2. **Variable Initialization**
	```cpp
	    int n = f.size();
	```
	The size of the friend list 'f' is assigned to variable 'n', which helps manage array bounds when processing the friends list.

3. **Vector Initialization**
	```cpp
	    vector<bool> vis(n, false);
	```
	A boolean vector 'vis' is initialized to track whether a person has already been visited during the BFS traversal.

4. **Queue Initialization**
	```cpp
	    queue<int> q;
	```
	A queue 'q' is initialized to manage the BFS traversal, storing people who need to be processed.

5. **Queue Operation**
	```cpp
	    q.push(id);
	```
	The starting person 'id' is added to the queue to begin the BFS traversal.

6. **Visiting Initialization**
	```cpp
	    vis[id] = true;
	```
	The 'vis' vector is updated to mark the starting person as visited.

7. **While Loop**
	```cpp
	    while(k--) {
	```
	The outer while loop iterates 'k' times, processing friends up to 'k' hops away.

8. **Queue Size Calculation**
	```cpp
	        int sz = q.size();
	```
	The size of the queue is stored in 'sz', representing the number of people to be processed in the current level of BFS.

9. **While Loop**
	```cpp
	        while(sz--) {
	```
	A nested while loop processes each person in the queue at the current level of BFS.

10. **Queue Front Operation**
	```cpp
	            int top = q.front();
	```
	The person at the front of the queue is stored in 'top'. This person will be processed.

11. **Queue Operation**
	```cpp
	            q.pop();
	```
	The front person is removed from the queue after being processed.

12. **Iterating Through Friends**
	```cpp
	            for(auto it: f[top]) {
	```
	For each friend of 'top' (the current person), the code checks if the friend has already been visited.

13. **Visiting Check**
	```cpp
	                if(!vis[it]) {
	```
	If the friend has not been visited, the code marks them as visited and pushes them to the queue for further processing.

14. **Visiting Update**
	```cpp
	                    vis[it] = true;
	```
	The friend 'it' is marked as visited in the 'vis' vector.

15. **Queue Operation**
	```cpp
	                    q.push(it);
	```
	The friend 'it' is added to the queue to be processed in subsequent iterations.

16. **Map Initialization**
	```cpp
	    map<string, int> mp;
	```
	A map 'mp' is initialized to track how many times each video has been watched by friends within 'k' hops.

17. **Map Processing**
	```cpp
	    while(!q.empty()) {
	```
	This loop processes the remaining people in the queue after 'k' levels of BFS.

18. **Queue Front Operation**
	```cpp
	        int fr = q.front();
	```
	The front person in the queue is processed.

19. **Queue Operation**
	```cpp
	        q.pop();
	```
	The front person is removed from the queue.

20. **Iterating Through Videos**
	```cpp
	        for(string x: wv[fr]) {
	```
	For each video watched by the current person 'fr', the map 'mp' is updated to count how many times each video is watched.

21. **Map Update**
	```cpp
	            mp[x]++;
	```
	The map 'mp' is updated to increment the count of video 'x' for the current person.

22. **Sorting**
	```cpp
	    sort(ans.begin(), ans.end());
	```
	The 'ans' vector is sorted by the video watch count, and in case of ties, by video name alphabetically.

23. **Result Initialization**
	```cpp
	    vector<string> res;
	```
	A vector 'res' is initialized to store the final sorted list of videos.

24. **Result Population**
	```cpp
	    for(auto it: ans)
	```
	This loop populates the 'res' vector with the video names from the sorted 'ans' list.

25. **Result Insertion**
	```cpp
	        res.push_back(it.second);
	```
	Each video name is added to the result vector 'res'.

26. **Return Statement**
	```cpp
	    return res;
	```
	The function returns the sorted list of video names that are the most watched by friends within 'k' hops.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n + m log m) - In the best case, only one level is processed and sorting is applied to a small set of videos.
- **Average Case:** O(n + m log m) - Where n is the number of people and m is the number of videos watched.
- **Worst Case:** O(n + m log m) - The BFS traversal visits all friends, and sorting is done on all videos for the level.

The time complexity is O(n + m log m), where n is the number of people and m is the number of videos.

### Space Complexity 💾
- **Best Case:** O(n + m) - Even in the best case, space is required to store the frequency of videos and the BFS queue.
- **Worst Case:** O(n + m) - The space complexity depends on the space needed for BFS traversal and the frequency map.

The space complexity is O(n + m), where n is the number of people and m is the number of videos.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/get-watched-videos-by-your-friends/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

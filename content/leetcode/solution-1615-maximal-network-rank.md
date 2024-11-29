
+++
authors = ["grid47"]
title = "Leetcode 1615: Maximal Network Rank"
date = "2024-05-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1615: Maximal Network Rank in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Graph"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "WCfyVhtldoU"
youtube_upload_date="2024-04-07"
youtube_thumbnail="https://i.ytimg.com/vi/WCfyVhtldoU/maxresdefault.jpg"
comments = true
+++



---
You are given a network of cities, where some cities are directly connected by bidirectional roads. The network rank between two cities is defined as the total number of roads connected to either of the cities. If a road connects both cities, it is only counted once. The task is to find the maximal network rank for any pair of distinct cities in the infrastructure.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer n representing the number of cities and an array roads, where each element in roads[i] = [ai, bi] represents a bidirectional road between cities ai and bi.
- **Example:** `n = 4, roads = [[0, 1], [0, 3], [1, 2], [1, 3]]`
- **Constraints:**
	- 2 <= n <= 100
	- 0 <= roads.length <= n * (n - 1) / 2
	- roads[i].length == 2
	- 0 <= ai, bi <= n-1
	- ai != bi
	- Each pair of cities has at most one road connecting them.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximal network rank, which is the highest network rank among all pairs of different cities.
- **Example:** `For n = 4 and roads = [[0, 1], [0, 3], [1, 2], [1, 3]], the output would be 4.`
- **Constraints:**
	- The output should be a single integer representing the maximal network rank.

{{< dots >}}
### Core Logic 🔍
**Goal:** To find the maximal network rank, iterate through all pairs of cities and calculate their network rank by considering the number of directly connected roads to either city, ensuring duplicate counting is avoided.

- First, calculate the number of roads connected to each city.
- Use a map to store connections between cities to avoid double counting the same road.
- For each pair of cities, calculate their combined network rank and update the maximum rank found.
- Return the highest network rank after checking all pairs of cities.
{{< dots >}}
### Problem Assumptions ✅
- The cities are numbered from 0 to n-1, and roads are bidirectional.
- Each pair of cities can have at most one direct road between them.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: n = 4, roads = [[0, 1], [0, 3], [1, 2], [1, 3]]`  \
  **Explanation:** Here, cities 0 and 1 have 4 roads connected (0-1, 0-3, 1-2, 1-3). The maximal network rank is 4.

- **Input:** `Input: n = 5, roads = [[0, 1], [0, 3], [1, 2], [1, 3], [2, 3], [2, 4]]`  \
  **Explanation:** For cities 1 and 2, the network rank is 5, as they are connected by 5 roads in total.

{{< dots >}}
## Approach 🚀
We can solve this problem by calculating the network rank for every pair of cities and selecting the maximum value.

### Initial Thoughts 💭
- We need to iterate through each pair of cities and calculate their network rank.
- The network rank for any pair of cities can be computed by summing the direct connections and subtracting any common connections.
{{< dots >}}
### Edge Cases 🌐
- If there are no roads, the network rank is 0, as no cities are connected.
- For a large number of cities, the solution must be efficient to handle the upper limit of n = 100.
- If there are only two cities with one road, the network rank is simply 2.
- The algorithm must handle cases where the number of roads is minimal or maximal.
{{< dots >}}
## Code 💻
```cpp
int maximalNetworkRank(int n, vector<vector<int>>& roads) {
    
    vector<int> inward(n, 0);
    map<int, set<int>> mp;
    for(auto it: roads) {
        inward[it[0]]++;
        inward[it[1]]++;
        mp[it[0]].insert(it[1]);
        mp[it[1]].insert(it[0]);
    }
    
    int mx = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            mx = max(mx, inward[i] + inward[j] - (mp.count(i) && mp[i].count(j)? 1: 0));
        }
    }
    return mx;
}
```

This is a function to calculate the maximal network rank for a given graph represented by `n` cities and a list of bidirectional roads.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int maximalNetworkRank(int n, vector<vector<int>>& roads) {
	```
	Define the function `maximalNetworkRank` that takes the number of cities `n` and a list of roads as input.

2. **Variable Initialization**
	```cpp
	    
	```
	Prepare for variable initialization.

3. **Variable Initialization**
	```cpp
	    vector<int> inward(n, 0);
	```
	Initialize a vector `inward` of size `n` with all values set to 0 to keep track of the number of roads connected to each city.

4. **Data Structure Initialization**
	```cpp
	    map<int, set<int>> mp;
	```
	Initialize a map `mp` to store the cities and their respective connected cities using sets.

5. **Loop**
	```cpp
	    for(auto it: roads) {
	```
	Iterate through each road in the `roads` list.

6. **Inward Counting**
	```cpp
	        inward[it[0]]++;
	```
	Increase the count for the first city in the current road.

7. **Inward Counting**
	```cpp
	        inward[it[1]]++;
	```
	Increase the count for the second city in the current road.

8. **Graph Construction**
	```cpp
	        mp[it[0]].insert(it[1]);
	```
	Add the second city to the set of connected cities for the first city.

9. **Graph Construction**
	```cpp
	        mp[it[1]].insert(it[0]);
	```
	Add the first city to the set of connected cities for the second city.

10. **Max Calculation**
	```cpp
	    int mx = 0;
	```
	Initialize the variable `mx` to store the maximum network rank.

11. **Loop**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Start a loop through each city in the graph.

12. **Loop**
	```cpp
	        for(int j = 0; j < n; j++) {
	```
	Start a nested loop to compare every pair of cities.

13. **Condition**
	```cpp
	            if(i == j) continue;
	```
	Skip if the two cities are the same.

14. **Max Calculation**
	```cpp
	            mx = max(mx, inward[i] + inward[j] - (mp.count(i) && mp[i].count(j)? 1: 0));
	```
	Calculate the network rank for the current pair of cities and update `mx` if a higher value is found.

15. **Return**
	```cpp
	    return mx;
	```
	Return the maximum network rank found.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2)

In the worst case, we calculate the network rank for all pairs of cities, which results in O(n^2) time complexity.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n^2)

The space complexity is O(n^2) due to storing the connections between cities, and O(n) in the best case if the roads are sparse.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximal-network-rank/description/)

---
{{< youtube WCfyVhtldoU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

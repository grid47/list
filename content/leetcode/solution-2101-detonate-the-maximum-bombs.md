
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
comments = true
+++



---
You are given a list of bombs represented by a 2D array 'bombs' where each bomb is described by three integers: [xi, yi, ri]. xi and yi denote the X and Y coordinates of the bomb, while ri is its blast radius. Your task is to find the maximum number of bombs that can be detonated by initiating a detonation of one bomb.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a 2D integer array 'bombs' where each element represents a bomb. Each bomb is defined by three integers: the X-coordinate, Y-coordinate, and blast radius of the bomb.
- **Example:** `bombs = [[1, 1, 3], [4, 1, 3]]`
- **Constraints:**
	- 1 <= bombs.length <= 100
	- bombs[i].length == 3
	- 1 <= xi, yi, ri <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum number of bombs that can be detonated by initiating the detonation of one bomb.
- **Example:** `Output: 2`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to calculate the maximum number of bombs that can be detonated starting from any bomb, considering the chain reaction that may happen.

- 1. For each bomb, calculate the range of bombs that it can detonate based on its blast radius.
- 2. Perform a DFS (Depth-First Search) to find how many bombs can be detonated if the current bomb is detonated.
- 3. Track the maximum number of detonated bombs for all possible starting bombs.
{{< dots >}}
### Problem Assumptions ✅
- All bombs have circular blast ranges.
- A bomb can only detonate another bomb if it lies within its blast radius.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: bombs = [[1, 1, 3], [4, 1, 3]]`  \
  **Explanation:** If you detonate the first bomb, it will only detonate itself. If you detonate the second bomb, both bombs will detonate because their blast radii overlap.

{{< dots >}}
## Approach 🚀
The approach to solving this problem involves calculating the bombs affected by detonating any given bomb and tracking the maximum chain reaction.

### Initial Thoughts 💭
- The problem essentially boils down to a graph traversal problem where bombs are connected based on their blast ranges.
- By modeling the bombs as nodes in a graph, with edges representing detonations, we can perform a DFS to find the maximum chain reaction.
{{< dots >}}
### Edge Cases 🌐
- Handle the case where the input array is empty (though the problem guarantees at least 1 bomb).
- Ensure that the solution handles up to 100 bombs efficiently.
- Handle cases where bombs are far apart or have no overlapping ranges.
- The constraints ensure that the problem can be solved in O(n^2) time, given that n <= 100.
{{< dots >}}
## Code 💻
```cpp
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
```

This code defines a solution for finding the maximum number of detonations that can occur by setting off a bomb. It uses a graph representation and depth-first search (DFS) to simulate the bomb detonation process and compute the result.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Code Initialization**
	```cpp
	class Solution {
	```
	Declares the Solution class that contains the solution method.

2. **Code Setup**
	```cpp
	#define ll long long int
	```
	Defines 'll' as a shorthand for long long integer type to handle large numbers.

3. **Access Control**
	```cpp
	public:
	```
	Specifies the public access modifier for methods that follow, making them accessible outside the class.

4. **Function Declaration**
	```cpp
	int maximumDetonation(vector<vector<int>>& bombs) {
	```
	Declares the 'maximumDetonation' function which takes a 2D vector of bomb coordinates and returns the maximum number of detonations.

5. **Variable Declaration**
	```cpp
	    int n = bombs.size();
	```
	Initializes the variable 'n' to the number of bombs in the input vector.

6. **Graph Setup**
	```cpp
	    vector<vector<int>> gph(n);
	```
	Creates a graph represented by an adjacency list where each bomb's connections are stored.

7. **Graph Construction**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Starts a loop to iterate through each bomb to build the graph of connections based on detonation range.

8. **Bomb Coordinate Extraction**
	```cpp
	        ll x1 = bombs[i][0];
	```
	Extracts the x-coordinate of the ith bomb.

9. **Bomb Coordinate Extraction**
	```cpp
	        ll y1 = bombs[i][1];
	```
	Extracts the y-coordinate of the ith bomb.

10. **Bomb Radius Extraction**
	```cpp
	        ll r1 = bombs[i][2];
	```
	Extracts the radius of detonation for the ith bomb.

11. **Connection Checking**
	```cpp
	        for(int j = 0; j < n; j++) {
	```
	Starts a loop to check for potential connections between the ith bomb and all other bombs.

12. **Condition Check**
	```cpp
	            if(i != j) {
	```
	Ensures that the bomb is not checking itself for a connection.

13. **Distance Calculation**
	```cpp
	                ll x2 = abs(x1 - bombs[j][0]);
	```
	Calculates the horizontal distance between the two bombs.

14. **Distance Calculation**
	```cpp
	                ll y2 = abs(y1 - bombs[j][1]);
	```
	Calculates the vertical distance between the two bombs.

15. **Condition Check**
	```cpp
	                if(x2 * x2 + y2 * y2 <= r1 * r1) {
	```
	Checks if the second bomb lies within the detonation radius of the first bomb.

16. **Graph Update**
	```cpp
	                    gph[i].push_back(j);
	```
	Adds the second bomb as a neighbor in the graph of the first bomb, indicating a potential detonation.

17. **Variable Initialization**
	```cpp
	    int ans = INT_MIN;
	```
	Initializes the variable 'ans' to store the maximum detonation count, starting with a very low value.

18. **Loop for Result Calculation**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Starts a loop to process each bomb and calculate its potential detonation result.

19. **Counter Initialization**
	```cpp
	        int c = 0;
	```
	Initializes a counter variable 'c' to count the number of detonations for the current bomb.

20. **Visited Flags Initialization**
	```cpp
	        vector<bool> vistd(n, false);
	```
	Initializes a vector to track which bombs have been visited during the DFS traversal.

21. **DFS Call**
	```cpp
	        dfs(gph, vistd, c, i);
	```
	Calls the depth-first search function to explore all detonations that start from the ith bomb.

22. **Result Update**
	```cpp
	        ans = max(ans, c);
	```
	Updates the maximum detonation result 'ans' based on the count 'c' for the current bomb.

23. **Return Statement**
	```cpp
	    return ans;
	```
	Returns the maximum number of detonations from the function.

24. **DFS Function Declaration**
	```cpp
	void dfs(vector<vector<int>> &gph, vector<bool> &vstd, int &c, int i) {
	```
	Declares the depth-first search function that explores all reachable bombs from a starting bomb.

25. **Base Case Check**
	```cpp
	    if(vstd[i]) return;
	```
	Checks if the bomb has already been visited, and if so, returns to avoid redundant processing.

26. **Mark as Visited**
	```cpp
	    vstd[i] = true;
	```
	Marks the current bomb as visited to prevent revisiting it.

27. **Increment Counter**
	```cpp
	    c++;
	```
	Increments the detonation counter for the current bomb.

28. **DFS Recursive Call**
	```cpp
	    for(int j: gph[i])
	```
	Loops over all bombs that can be detonated from the current bomb.

29. **Recursive DFS Call**
	```cpp
	        if(!vstd[j])
	            dfs(gph, vstd, c, j);
	```
	Recursively calls DFS for each unvisited bomb connected to the current bomb.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2)

In the worst case, we need to check the blast range for each pair of bombs, leading to O(n^2) time complexity.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n^2)

We store a graph representation of the bomb interactions, which takes O(n^2) space in the worst case.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/detonate-the-maximum-bombs/description/)

---
{{< youtube 8NPbAvVXKR4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

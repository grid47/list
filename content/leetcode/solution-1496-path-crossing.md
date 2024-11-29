
+++
authors = ["grid47"]
title = "Leetcode 1496: Path Crossing"
date = "2024-06-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1496: Path Crossing in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "VWRJBNP7uH8"
youtube_upload_date="2023-12-23"
youtube_thumbnail="https://i.ytimg.com/vi/VWRJBNP7uH8/maxresdefault.jpg"
comments = true
+++



---
You are given a string path where each character represents a movement direction ('N' for north, 'S' for south, 'E' for east, 'W' for west). Starting from the origin (0, 0), follow the path and check if you cross your own path at any point, meaning visiting a location more than once. Return true if the path crosses itself, and false otherwise.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a string path consisting of 'N', 'S', 'E', and 'W', where each character represents a movement direction.
- **Example:** `path = "NEWS"`
- **Constraints:**
	- 1 <= path.length <= 10^4
	- path[i] is one of 'N', 'S', 'E', 'W'.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return true if the path crosses itself, meaning you visit a location you have already been to. Otherwise, return false.
- **Example:** `Output: false`
- **Constraints:**
	- The path will contain at least one character.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to track the movements and check if any position is visited more than once using a set data structure.

- Initialize a set to store visited coordinates.
- Iterate through the characters in the path, updating the current position based on the direction.
- If the current position has been visited before, return true.
- If the loop finishes without revisiting a position, return false.
{{< dots >}}
### Problem Assumptions ✅
- The path consists of valid directions only.
{{< dots >}}
## Examples 🧩
- **Input:** `path = "NEWS"`  \
  **Explanation:** The path starts at the origin, moves north, then east, then west, and finally south, visiting no location twice, so it does not cross itself.

- **Input:** `path = "NESWN"`  \
  **Explanation:** After moving north, east, south, west, and then north again, the path revisits the origin, so it crosses itself.

{{< dots >}}
## Approach 🚀
We can efficiently determine if the path crosses by keeping track of each position we visit using a set. If we ever encounter a position that we have already visited, we know the path crosses.

### Initial Thoughts 💭
- A set is ideal for this problem since it allows constant time lookups to check if a location has been visited.
- By iterating over the path and updating our current position, we can easily check if any position has been revisited.
{{< dots >}}
### Edge Cases 🌐
- An empty input path is not valid since the constraints ensure at least one move.
- The solution must handle path lengths up to 10^4 efficiently.
- If the path moves in a complete loop, it will return true since the origin will be revisited.
- The solution must be efficient enough to handle paths with lengths up to 10^4.
{{< dots >}}
## Code 💻
```cpp
bool isPathCrossing(string path) {
    int x = 0,y=0;
    set<pair<int,int>>s;
    s.insert({0,0});
    for(char p: path){
        if(p == 'N') y++;
        else if(p == 'S')y--;
        else if(p == 'E') x++;
        else x--;
        
        if(s.find({x,y}) != s.end()) return true;
        else s.insert({x,y});
    }
    return false;
}
```

The `isPathCrossing` function checks if a given path crosses itself. It simulates the movement along the path and keeps track of visited coordinates using a set. If a coordinate is revisited, it returns `true`; otherwise, it returns `false`.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	bool isPathCrossing(string path) {
	```
	The function `isPathCrossing` takes a string `path` as input and returns a boolean indicating whether the path crosses itself.

2. **Variable Initialization**
	```cpp
	    int x = 0, y = 0;
	```
	Initialize `x` and `y` to 0. These variables represent the current position along the path on a 2D grid, starting at the origin (0,0).

3. **Set Initialization**
	```cpp
	    set<pair<int, int>> s;
	```
	Initialize a set `s` to store the visited coordinates as pairs of integers. This will help track previously visited positions.

4. **Set Insertion**
	```cpp
	    s.insert({0, 0});
	```
	Insert the starting coordinate (0,0) into the set `s` as the initial position.

5. **Loop**
	```cpp
	    for(char p: path){
	```
	Start a loop to iterate over each character in the `path` string. Each character represents a direction to move.

6. **Movement**
	```cpp
	        if(p == 'N') y++;
	```
	If the character is 'N' (North), increment `y` to move one unit up along the y-axis.

7. **Movement**
	```cpp
	        else if(p == 'S') y--;
	```
	If the character is 'S' (South), decrement `y` to move one unit down along the y-axis.

8. **Movement**
	```cpp
	        else if(p == 'E') x++;
	```
	If the character is 'E' (East), increment `x` to move one unit to the right along the x-axis.

9. **Movement**
	```cpp
	        else x--;
	```
	If the character is 'W' (West), decrement `x` to move one unit to the left along the x-axis.

10. **Position Check**
	```cpp
	        if(s.find({x, y}) != s.end()) return true;
	```
	Check if the current position (x, y) has been visited before by searching the set `s`. If the position is found, it means the path crosses itself, so return `true`.

11. **Set Update**
	```cpp
	        else s.insert({x, y});
	```
	If the current position has not been visited before, insert it into the set `s` to mark it as visited.

12. **Return Statement**
	```cpp
	    return false;
	```
	If no crossing was detected after checking all directions in the path, return `false`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the length of the path, since we only need to iterate over the path once and check each position in the set.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage required for the set of visited positions.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/path-crossing/description/)

---
{{< youtube VWRJBNP7uH8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

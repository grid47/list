
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
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
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
};
{{< /highlight >}}
---

### Problem Statement

The problem requires us to determine if a path crosses itself given a sequence of movements in a 2D plane. The path is described by a string consisting of the characters 'N', 'S', 'E', and 'W', representing movements in the north, south, east, and west directions, respectively. The goal is to return `true` if the path crosses itself at any point and `false` otherwise.

### Approach

To solve this problem, we can use a set to track the coordinates of all the points visited during the traversal of the path. Each time we move in a given direction, we will check if we have already visited the new coordinates. If we find that a coordinate has been visited before, it indicates that the path has crossed itself.

1. **Initialize Coordinates**: Start at the origin `(0, 0)`, which will be our initial position.
2. **Track Visited Positions**: Use a set to keep track of all visited coordinates, starting with the origin.
3. **Iterate Over Movements**: For each character in the input string, update the current position based on the movement indicated by the character.
4. **Check for Crossings**: After each movement, check if the new position already exists in the set of visited positions.
5. **Return Result**: If a crossing is detected, return `true`. If no crossings are found after processing all movements, return `false`.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    bool isPathCrossing(string path) {
```
This line declares a class `Solution` with a public member function `isPathCrossing`, which takes a string `path` as an argument.

#### Step 1: Initialize Variables

```cpp
        int x = 0, y = 0;
        set<pair<int, int>> s;
        s.insert({0, 0});
```
- `x` and `y` are initialized to `0`, representing the starting point `(0, 0)`.
- A set `s` of pairs is used to store the coordinates of all visited points. The initial position `(0, 0)` is inserted into the set.

#### Step 2: Iterate Over Each Character

```cpp
        for(char p: path) {
```
This for loop iterates through each character `p` in the `path` string.

#### Step 3: Update Coordinates Based on Direction

```cpp
            if(p == 'N') y++;
            else if(p == 'S') y--;
            else if(p == 'E') x++;
            else x--;
```
- The coordinates are updated based on the direction indicated by the character:
  - 'N' (north) increases the `y` coordinate.
  - 'S' (south) decreases the `y` coordinate.
  - 'E' (east) increases the `x` coordinate.
  - 'W' (west) decreases the `x` coordinate.

#### Step 4: Check for Crossing

```cpp
            if(s.find({x, y}) != s.end()) return true;
            else s.insert({x, y});
```
- After updating the coordinates, the code checks if the new position `(x, y)` is already in the set `s`.
- If it is found, the function immediately returns `true`, indicating that the path crosses itself.
- If not found, the new position is added to the set of visited coordinates.

#### Step 5: Return False if No Crossing Found

```cpp
        return false;
    }
};
```
- If the loop completes without finding a crossing, the function returns `false`, indicating that the path does not cross itself.

### Complexity

#### Time Complexity
- The time complexity of this algorithm is **O(n)**, where `n` is the length of the input string `path`. Each character is processed exactly once, and set operations (insert and find) are average **O(1)** due to the underlying hash table implementation.

#### Space Complexity
- The space complexity is also **O(n)** in the worst case, where all coordinates in the path are unique and stored in the set.

### Conclusion

This implementation efficiently determines whether a path crosses itself using a simple set-based approach to track visited coordinates. The sliding window concept of checking and updating coordinates allows for straightforward logic without needing complex data structures or algorithms.

**Key Points**:
- **Efficiency**: The O(n) time complexity ensures that the solution is efficient for long paths.
- **Simplicity**: Using a set for tracking visited positions simplifies the logic and makes the code easy to understand.
- **Robustness**: The code handles all movement directions and checks for crossings effectively.

In summary, this solution is an excellent example of using a set data structure to keep track of visited locations in a grid, allowing for quick detection of revisited points, thereby solving the path crossing problem efficiently and elegantly.

[`Link to LeetCode Lab`](https://leetcode.com/problems/path-crossing/description/)

---
{{< youtube VWRJBNP7uH8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

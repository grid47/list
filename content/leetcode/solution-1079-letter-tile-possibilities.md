
+++
authors = ["grid47"]
title = "Leetcode 1079: Letter Tile Possibilities"
date = "2024-07-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1079: Letter Tile Possibilities in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Backtracking","Counting"]
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
    int numTilePossibilities(string tiles) {
        set<string> ans;
        set<int> seen;

        gen(tiles, 0, "", ans, seen);
        return ans.size();
    }

    void gen(string tiles, int idx, string res, set<string> &ans, set<int> &vis ) {
        if(idx == tiles.size()) return;
        for(int i = 0; i < tiles.size(); i++) {
            if(!vis.count(i)) {
                vis.insert(i);
                ans.insert(res + tiles[i]);
    gen(tiles, idx + 1, res + tiles[i], ans, vis);
                vis.erase(i);
            }
        }
    }
};
{{< /highlight >}}
---



### Problem Statement
The problem involves finding the number of distinct combinations that can be formed from a given string of tiles, where each tile can be used only once in each combination. For example, given the string "AAB", we can form combinations such as "A", "AA", "AB", "B", and "AAB". The task is to return the total number of unique combinations that can be created using the tiles, including all possible lengths.

### Approach
The approach to solve this problem employs a backtracking technique. We recursively generate all possible combinations of tiles by choosing each tile and generating new combinations without repeating the same tile. The key steps in the approach are:

1. Use a set to store unique combinations of tile arrangements.
2. Use a helper function to explore all possible combinations recursively.
3. Keep track of which tiles have been used in the current combination to avoid duplicates.
4. Generate combinations of varying lengths by continuously adding tiles to the current result until all possibilities are explored.

### Code Breakdown (Step by Step)

1. **Class Definition**:
   The `Solution` class encapsulates the method for finding the number of tile possibilities.

   ```cpp
   class Solution {
   public:
   ```

2. **Main Function**:
   The method `numTilePossibilities` takes a string `tiles` as input and initializes the process to find all unique combinations.

   ```cpp
   int numTilePossibilities(string tiles) {
       set<string> ans;
       set<int> seen;
   ```

3. **Generating Combinations**:
   A set called `ans` is created to store unique combinations, and another set `seen` is created to track the indices of tiles used in the current combination. The function `gen` is called to start generating combinations.

   ```cpp
       gen(tiles, 0, "", ans, seen);
       return ans.size();
   ```

4. **Recursive Function Definition**:
   The `gen` function is defined to recursively explore combinations of tiles.

   ```cpp
   void gen(string tiles, int idx, string res, set<string> &ans, set<int> &vis ) {
   ```

5. **Base Case**:
   The base case for the recursion checks if the index `idx` equals the size of the string. If true, the function simply returns, as there are no more tiles to process.

   ```cpp
       if(idx == tiles.size()) return;
   ```

6. **Exploring Tile Combinations**:
   A loop iterates through each tile in the `tiles` string. If a tile at index `i` has not been visited (`!vis.count(i)`), we proceed to include it in the current combination.

   ```cpp
       for(int i = 0; i < tiles.size(); i++) {
           if(!vis.count(i)) {
   ```

7. **Marking Tiles as Used**:
   The current tile index `i` is added to the `vis` set to indicate that this tile is currently being used in the combination.

   ```cpp
               vis.insert(i);
   ```

8. **Storing the Combination**:
   The combination formed by appending the current tile to `res` is inserted into the `ans` set to ensure uniqueness.

   ```cpp
               ans.insert(res + tiles[i]);
   ```

9. **Recursive Call**:
   The `gen` function is called recursively, incrementing the index to explore further combinations that include the current tile.

   ```cpp
               gen(tiles, idx + 1, res + tiles[i], ans, vis);
   ```

10. **Backtracking**:
   After exploring combinations with the current tile, we remove the index from `vis`, allowing the tile to be used in other combinations.

   ```cpp
               vis.erase(i);
           }
       }
   }
   ```

11. **Return Statement**:
   The `numTilePossibilities` function returns the size of the `ans` set, which represents the total number of unique tile arrangements.

   ```cpp
   return ans.size();
   }
   ```

### Complexity Analysis
- **Time Complexity**: The time complexity of this algorithm can be estimated as \(O(N!)\), where \(N\) is the length of the `tiles` string. This is because we are generating all possible permutations of the string, which grows factorially as the number of tiles increases. The set operations (insertion and lookup) are average \(O(1)\) time, but due to the recursive nature, the depth can lead to exponential growth in combinations.
  
- **Space Complexity**: The space complexity is \(O(N)\) due to the space used by the recursion stack in the backtracking approach and the space used to store unique combinations in the set. In the worst case, the set can hold up to \(N!\) combinations, depending on the tiles provided.

### Conclusion
The provided C++ code efficiently calculates the number of distinct combinations that can be formed using a given set of tiles. By leveraging backtracking and a set to store unique combinations, the solution systematically explores all possible arrangements, ensuring no duplicates. This approach is particularly effective for generating combinations from a collection with potentially repeating elements.

This implementation highlights the power of recursion in solving combinatorial problems and showcases efficient handling of unique data using sets. For larger strings of tiles, the performance may vary, but the algorithm remains an excellent approach for understanding the fundamentals of combinatorial generation and backtracking techniques.

In summary, this solution provides a robust and efficient way to count unique tile arrangements, making it suitable for various applications, including games and puzzles that involve string manipulations.


[`Link to LeetCode Lab`](https://leetcode.com/problems/letter-tile-possibilities/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

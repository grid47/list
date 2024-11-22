
+++
authors = ["grid47"]
title = "Leetcode 2766: Relocate Marbles"
date = "2024-02-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2766: Relocate Marbles in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sorting","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "bH2EmMR5jpU"
youtube_upload_date="2023-07-08"
youtube_thumbnail="https://i.ytimg.com/vi_webp/bH2EmMR5jpU/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        map<int, int> mp;  
        for(auto n: nums) mp[n] = 1;
        for(int i = 0; i < moveFrom.size(); ++i){
            if(mp[moveFrom[i]] && moveFrom[i] != moveTo[i]) {
                mp[moveTo[i]] = 1;  mp[moveFrom[i]] = 0;
            }
        }
        vector<int> ans;
        for(auto m: mp) if(m.second) ans.push_back(m.first);
        return ans;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem requires us to simulate the movement of marbles on a one-dimensional track. You are given an initial configuration of marbles, represented by an array `nums`, where each value represents a distinct position on the track that contains a marble. You are also given two arrays `moveFrom` and `moveTo`, which represent the marble positions that need to be relocated. For each pair of corresponding positions, the marble at `moveFrom[i]` is moved to `moveTo[i]`. The task is to return the final positions of the marbles sorted in increasing order.

### Approach

To solve this problem efficiently, we can follow the below steps:

1. **Track the Positions of Marbles**:
   We can use a `map` (or dictionary) to keep track of the positions that have marbles. This allows efficient look-up, insertion, and deletion of marbles from their respective positions. Initially, we will mark each position in the input array `nums` as having a marble.

2. **Simulate the Moves**:
   For each move, we check if the position in `moveFrom` contains a marble (i.e., if it exists in the map and is non-zero). If it does, we remove the marble from the `moveFrom` position and place it in the `moveTo` position.

3. **Return the Final Marble Positions**:
   After processing all the moves, the positions of the marbles are stored in the map. We will extract these positions and return them sorted in increasing order.

### Code Breakdown (Step by Step)

Let’s go through the code line by line to understand the logic:

1. **Map Initialization**:
   ```cpp
   map<int, int> mp;
   ```
   We initialize a `map` named `mp` where the keys represent the positions on the track, and the values represent whether there is a marble at that position (1 for marble, 0 for no marble). A map is chosen because it allows us to efficiently check, update, and remove marbles.

2. **Mark Initial Marble Positions**:
   ```cpp
   for(auto n: nums) mp[n] = 1;
   ```
   Here, we iterate through the `nums` array, which contains the initial positions of the marbles. For each position, we update the map `mp` to mark that the marble is present at that position.

3. **Simulating the Movement**:
   ```cpp
   for(int i = 0; i < moveFrom.size(); ++i) {
       if(mp[moveFrom[i]] && moveFrom[i] != moveTo[i]) {
           mp[moveTo[i]] = 1;
           mp[moveFrom[i]] = 0;
       }
   }
   ```
   - We loop through each pair of `moveFrom[i]` and `moveTo[i]`, where we need to move a marble from position `moveFrom[i]` to position `moveTo[i]`.
   - For each move, we check if a marble exists at position `moveFrom[i]` (`mp[moveFrom[i]]`). We also ensure that the source and destination are not the same (`moveFrom[i] != moveTo[i]`), as there’s no need to move a marble to the same position.
   - If both conditions are satisfied, we:
     - Set the `moveTo[i]` position in the map to 1 (indicating a marble is now at this position).
     - Set the `moveFrom[i]` position in the map to 0 (indicating the marble is removed from the source position).

4. **Collect Final Marble Positions**:
   ```cpp
   vector<int> ans;
   for(auto m: mp) if(m.second) ans.push_back(m.first);
   return ans;
   ```
   - After all moves are simulated, we create a result vector `ans` to store the final positions of the marbles.
   - We iterate over the `map` and collect all keys (positions) where the value is 1, which represents positions where marbles are currently located.
   - The `map` inherently stores the keys in sorted order, so we don’t need to perform any additional sorting.
   - Finally, we return the `ans` vector containing the sorted positions of the marbles.

### Complexity Analysis

#### Time Complexity:
1. **Initialization of Marble Positions**:
   - The initialization of the map from the `nums` array takes \(O(m)\) time, where \(m\) is the size of the `nums` array.
   
2. **Processing the Moves**:
   - For each move in the `moveFrom` and `moveTo` arrays, we perform constant-time operations to check and update the map (`mp[moveFrom[i]]` and `mp[moveTo[i]]`), which takes \(O(1)\) per move. Thus, the total time for processing all moves is \(O(k)\), where \(k\) is the number of moves.

3. **Collecting the Final Positions**:
   - We iterate over the `map` to collect all positions with marbles. Since the map contains at most \(m\) unique positions, this step takes \(O(m)\) time.
   
   Therefore, the total time complexity is \(O(m + k)\), where:
   - \(m\) is the number of unique positions in `nums` (or the size of the map).
   - \(k\) is the number of moves.

#### Space Complexity:
1. **Map Storage**:
   - The `map` `mp` stores the marble positions and their status. In the worst case, it will store as many entries as the number of unique positions in the input array `nums`, which is \(O(m)\).
   
2. **Result Vector**:
   - The result vector `ans` will store the final positions of the marbles, which can also be at most \(O(m)\).
   
Thus, the space complexity is \(O(m)\), where \(m\) is the number of unique positions.

### Conclusion

This solution efficiently simulates the process of relocating marbles based on the given `moveFrom` and `moveTo` arrays. By using a `map`, we can keep track of the current positions of the marbles in constant time for each move. The approach is both time and space efficient, with a time complexity of \(O(m + k)\), where \(m\) is the number of unique marble positions and \(k\) is the number of moves.

The solution handles edge cases, such as when marbles are moved to the same position or when no moves are made, by ensuring that only valid moves are processed. The use of a `map` also ensures that the final marble positions are returned in sorted order without needing additional sorting. This solution is optimal for the given problem and should perform well even for large inputs.

[`Link to LeetCode Lab`](https://leetcode.com/problems/relocate-marbles/description/)

---
{{< youtube bH2EmMR5jpU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

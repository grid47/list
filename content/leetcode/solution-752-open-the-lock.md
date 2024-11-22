
+++
authors = ["grid47"]
title = "Leetcode 752: Open the Lock"
date = "2024-08-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 752: Open the Lock in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Breadth-First Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/752.webp"
youtube = "Pzg3bCDY87w"
youtube_upload_date="2022-01-19"
youtube_thumbnail="https://i.ytimg.com/vi/Pzg3bCDY87w/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/752.webp" 
    alt="A lock with combination digits, where each correct digit softly glows as it’s guessed correctly."
    caption="Solution to LeetCode 752: Open the Lock Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        if (dead.count("0000")) return -1;
        queue<string> q({"0000"});
        
        for(int turn = 0;!q.empty(); turn++) {
            for(int i = q.size(); i > 0; i--) {
                auto curr = q.front(); q.pop();
                cout << curr << ' ' << target << endl;
                if (curr == target) return turn;
                for(auto it : neighbours(curr)) {
                    if(dead.count(it)) continue;
                    dead.insert(it);
                    q.push(it);
                }
            }
        }
        return -1;
    }

    vector<string> neighbours(const string &code) {
        vector<string> res;
        for(int i = 0; i < 4; i++) {
            for(int diff = -1; diff <= 1; diff++) {
                string nei = code;
                nei[i] = (nei[i] - '0' + diff + 10) % 10 + '0';
                res.push_back(nei);
            }
        }
        return res;
    }

};
{{< /highlight >}}
---

### Problem Statement

The problem asks us to find the minimum number of turns required to unlock a combination lock, starting from the "0000" combination and aiming to reach a target combination, while avoiding certain "deadends." Each turn allows us to change one digit of the combination by either increasing or decreasing it by one, and we are provided with a list of "deadends," which are combinations that we should avoid. The task is to return the minimum number of turns required to reach the target combination or `-1` if it's not possible.

### Approach

To solve this problem, we can use **Breadth-First Search (BFS)**. BFS is ideal for problems like this because it explores all possibilities level by level, ensuring that the first time we encounter the target combination, we have found the shortest path (minimum number of turns).

Here’s a step-by-step breakdown of how we can apply BFS to this problem:

1. **Initial State**: Start with the combination "0000."
2. **Queue**: Use a queue to explore all possible combinations. Each element in the queue represents a combination we can reach from the current state, and the queue will hold combinations for which we still need to explore their neighbors.
3. **Deadends**: Maintain a set of "deadends" (combinations we should avoid), and skip any combination that is in the "deadends" set.
4. **Neighbor Exploration**: For each combination, generate all its neighbors by changing one digit at a time, either increasing or decreasing it by 1. This step generates the next valid combinations we can explore.
5. **Track Turns**: Track the number of turns or levels of BFS that have been completed to reach a particular combination.
6. **Termination**: If we reach the target combination, return the number of turns. If the queue is empty and we haven’t reached the target, return `-1` to indicate that it's impossible to reach the target.

### Code Breakdown (Step by Step)

1. **Initialization**:
   - We first convert the `deadends` vector into an unordered set for fast lookup. This allows us to quickly check if a combination is a deadend.
   - If "0000" is a deadend, immediately return `-1` since we can't start from there.
   - Initialize the queue with the starting combination "0000" and begin BFS.
   ```cpp
   unordered_set<string> dead(deadends.begin(), deadends.end());
   if (dead.count("0000")) return -1;
   queue<string> q({"0000"});
   ```

2. **BFS Loop**:
   - The BFS loop continues until the queue is empty. Each iteration of BFS represents a "turn" or level of exploration.
   - For each turn, we process each element in the queue. For every combination in the queue, we generate its neighbors and add them to the queue if they are not deadends and haven’t been visited yet.
   ```cpp
   for (int turn = 0; !q.empty(); turn++) {
       for (int i = q.size(); i > 0; i--) {
           auto curr = q.front(); q.pop();
           cout << curr << ' ' << target << endl;  // For debugging
           if (curr == target) return turn;
           for (auto it : neighbours(curr)) {
               if (dead.count(it)) continue;
               dead.insert(it);  // Mark as visited
               q.push(it);
           }
       }
   }
   return -1;  // If the queue is empty and target is not found
   ```

3. **Generating Neighbors**:
   - For each combination, the function `neighbours()` generates all the possible combinations by changing one digit at a time, either increasing or decreasing that digit by one. This is done for each of the four digits in the combination.
   - Each change is computed in the following way: for each digit, we add 1 (clockwise) or subtract 1 (counterclockwise) and apply modulo 10 to wrap around the digit. This ensures we can handle changes from '9' to '0' and vice versa.
   ```cpp
   vector<string> neighbours(const string &code) {
       vector<string> res;
       for (int i = 0; i < 4; i++) {
           for (int diff = -1; diff <= 1; diff++) {
               string nei = code;
               nei[i] = (nei[i] - '0' + diff + 10) % 10 + '0';
               res.push_back(nei);
           }
       }
       return res;
   }
   ```

4. **Termination**:
   - The BFS loop terminates either when we find the target combination, in which case we return the number of turns taken, or when the queue is empty and the target is not found, indicating it's impossible to reach the target.

### Complexity Analysis

- **Time Complexity**:
  - Each combination is explored at most once. There are 10,000 possible combinations (from "0000" to "9999"). For each combination, we generate up to 8 neighbors (changing each of the 4 digits by +1 or -1). Thus, the time complexity is **O(10,000 * 8)**, which simplifies to **O(1)** since the number of possible combinations is constant.
  
- **Space Complexity**:
  - The space complexity is dominated by the storage of combinations in the queue and the set of deadends. The queue can hold at most all possible combinations, and the set of deadends can store up to 10,000 combinations. Therefore, the space complexity is **O(10,000)**, which is also considered constant for practical purposes.

### Conclusion

This solution efficiently solves the problem of finding the minimum number of turns to open the lock using a BFS approach. The key advantage of BFS is that it guarantees the shortest path to the target combination by exploring all possibilities level by level. By avoiding deadends and efficiently generating neighbors, the algorithm ensures that we can solve the problem in an optimal manner.

The solution is both time-efficient and space-efficient, leveraging BFS to explore all possible combinations while ensuring that we don’t revisit states unnecessarily. Additionally, using a set to track deadends and visited combinations ensures that the algorithm avoids cycles and redundant computations.

This approach is scalable and well-suited for problems involving search spaces with limited size, such as this one where there are only 10,000 possible combinations. It can be extended or adapted to similar problems where BFS or graph traversal is applicable.

[`Link to LeetCode Lab`](https://leetcode.com/problems/open-the-lock/description/)

---
{{< youtube Pzg3bCDY87w >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

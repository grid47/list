
+++
authors = ["grid47"]
title = "Leetcode 2682: Find the Losers of the Circular Game"
date = "2024-02-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2682: Find the Losers of the Circular Game in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "bNZuwqt1pg0"
youtube_upload_date="2023-05-14"
youtube_thumbnail="https://i.ytimg.com/vi/bNZuwqt1pg0/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<int> rcvd(n, 0);
        int i = 0;
        int cnt = 1;
        rcvd[0] = 1;
        while(rcvd[i] == 1) {
            i = (i + cnt * k) % n;            
            if(rcvd[i] == 1) break;
            rcvd[i] = 1;
            cnt++;
        }
        vector<int> ans;
        for(int j = 0; j < n; j++) {
            // cout << rcvd[j] << " ";
            if(rcvd[j] == 0) ans.push_back(j + 1);            
        }

        return ans;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks to simulate a circular game where `n` players are involved, and each player is assigned a number from `1` to `n`. The players start at position 1, and the game proceeds by eliminating players according to a specific step size `k`. The goal is to determine which players are not eliminated in the game, returning their positions.

Specifically, the rules of the game are:
1. The game starts at position `1`.
2. From the current position, move forward by `k` steps, considering the positions circularly (i.e., after reaching position `n`, wrap back to position `1`).
3. Once a player is reached, they are eliminated and marked as "received."
4. The process continues until all the remaining players are eliminated.

The function should return a list of the positions of the players who are not eliminated.

### Approach

The game can be modeled using an array where each index represents a player, and the value at each index indicates whether the player has been eliminated (`1` if eliminated, `0` if not). The solution involves simulating the game step by step.

The process can be broken down as follows:

1. **Initialization**: Create an array `rcvd` of size `n` to keep track of eliminated players, initialized with `0`. We also initialize the game starting at position `0` (i.e., the first player).
   
2. **Simulation**: Start the game by marking the first player as eliminated (`rcvd[0] = 1`), and then simulate the game loop. The loop continues to eliminate players by moving `k` steps forward each time.

3. **Circular Movement**: Since the game is played in a circular manner, the index is computed using modulo operation to ensure that when we exceed the bounds of the array, we wrap around to the beginning.

4. **Termination**: The game continues until we revisit a player who has already been eliminated, which breaks the loop.

5. **Final Result**: After the loop finishes, the remaining players (those who are not eliminated) are collected and returned as the result.

### Code Breakdown (Step by Step)

#### Step 1: Initialize the Tracking Array

```cpp
vector<int> rcvd(n, 0);
int i = 0;
int cnt = 1;
rcvd[0] = 1;
```

- **`rcvd`**: An array of size `n` is created and initialized to all `0`. Each index represents a player, and the value at that index will be `1` if the player is eliminated, or `0` if the player is still in the game.
- **`i = 0`**: The game starts with the first player (index `0`).
- **`cnt = 1`**: This variable keeps track of how many players have been eliminated.
- **`rcvd[0] = 1`**: The first player is eliminated immediately to start the process.

#### Step 2: Simulate the Game

```cpp
while(rcvd[i] == 1) {
    i = (i + cnt * k) % n;
    if(rcvd[i] == 1) break;
    rcvd[i] = 1;
    cnt++;
}
```

- **`while(rcvd[i] == 1)`**: The game continues until we revisit a player who has already been eliminated. This ensures we don't loop indefinitely.
- **`i = (i + cnt * k) % n;`**: This calculates the new position `i` after moving `k` steps forward. The modulo operation ensures the circular movement, meaning after reaching `n`, we wrap back to `0`.
- **`if(rcvd[i] == 1) break;`**: If the player at the new position `i` has already been eliminated (`rcvd[i] == 1`), we break the loop since no more players can be eliminated.
- **`rcvd[i] = 1;`**: If the player hasn't been eliminated, mark them as eliminated (`rcvd[i] = 1`).
- **`cnt++`**: Increment the count of eliminated players (`cnt`), as one more player has been eliminated.

#### Step 3: Collect Non-Eliminated Players

```cpp
vector<int> ans;
for(int j = 0; j < n; j++) {
    if(rcvd[j] == 0) ans.push_back(j + 1);
}
```

- **`ans`**: A vector to store the positions of players who were not eliminated.
- **`for(int j = 0; j < n; j++)`**: Iterate through all players.
- **`if(rcvd[j] == 0) ans.push_back(j + 1);`**: If a player is not eliminated (`rcvd[j] == 0`), add their position (index `j + 1` because positions are 1-based) to the `ans` vector.

#### Step 4: Return the Result

```cpp
return ans;
```

- The function returns the vector `ans` containing the positions of all players who were not eliminated.

### Complexity

#### Time Complexity

- **Initialization of `rcvd`**: The initialization of the array `rcvd` takes **O(n)** time.
- **Game Simulation**: The while loop runs until all players are eliminated, or the loop revisits a player. In the worst case, each player can be visited multiple times, but since we eliminate one player per iteration, the loop will run at most `n` times.
  - The computation inside the loop (index calculation and update of the `rcvd` array) is constant time, so the total complexity for the game simulation is **O(n)**.
- **Final Result**: Collecting the non-eliminated players also takes **O(n)** time.

- **Overall Time Complexity**: The total time complexity is **O(n)**, where `n` is the number of players.

#### Space Complexity

- The space complexity is **O(n)** because we are using an array `rcvd` of size `n` to track eliminated players, and an additional vector `ans` to store the non-eliminated players.

- **Overall Space Complexity**: The space complexity is **O(n)**.

### Conclusion

This solution efficiently simulates the circular game by using an array to track eliminated players and iterating through the array with the given step size `k`. The algorithm computes the positions of the players who are not eliminated and does so in linear time, making it well-suited for large input sizes.

[`Link to LeetCode Lab`](https://leetcode.com/problems/find-the-losers-of-the-circular-game/description/)

---
{{< youtube bNZuwqt1pg0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |


+++
authors = ["grid47"]
title = "Leetcode 909: Snakes and Ladders"
date = "2024-08-08"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 909: Snakes and Ladders in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Breadth-First Search","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "6lH4nO3JfLk"
youtube_upload_date="2022-01-08"
youtube_thumbnail="https://i.ytimg.com/vi/6lH4nO3JfLk/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    void getCoordinate(int n, int s, int &row, int &col) {
        row = n-1-(s-1)/n;
        col = (s-1)%n;
        if((n%2 ==1 && row%2==1) || (n%2==0 && row%2==0))
            col= n-1-col;
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<bool> seen(n*n+1, false);
        seen[1] = true;
        queue<pair<int, int>> q;
        q.push({1, 0});
        while(!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            int row, col, s = p.first, dist = p.second;
            if(s == n*n) 
                return dist;
            for(int i = 1; s+i<= n *n && i<=6;i++) {
                getCoordinate(n, s+i, row, col);
                int sfinal = board[row][col] == -1? s+i:board[row][col];
                if(seen[sfinal] == false) {
                    seen[sfinal] = true;
                    q.push({sfinal, dist + 1});
                }
            }
        }
        return -1;
    }
};
{{< /highlight >}}
---

### Problem Statement

In this problem, you are tasked with simulating a game of **Snakes and Ladders** on an `n x n` board, where the positions are numbered sequentially from 1 to `n*n`. The goal is to start at position 1 and reach the last position `n*n` with the minimum number of dice rolls. Each dice roll can land on a number between 1 and 6. If a player lands on a snake, they are forced to slide back to another position, and if they land on a ladder, they are immediately transported to a higher position. The goal is to return the minimum number of dice rolls required to reach the last position, or -1 if it is not possible.

### Approach

To solve this problem, we can model the game as a **shortest path problem** on a graph:
1. **Board as Graph**: Each square on the board can be thought of as a node in a graph, where edges represent dice rolls from 1 to 6.
2. **Breadth-First Search (BFS)**: Since we want to find the shortest path (minimum number of dice rolls), we can use **BFS**. BFS guarantees that the first time we reach the last position (`n*n`), we have done so in the fewest number of steps.
3. **Handling Snakes and Ladders**: If a player lands on a square with a snake or ladder, they are immediately transported to a different square. This can be handled by checking the board value at that square, and if it's not `-1` (which indicates no snake or ladder), we move the player to the new square.

### Code Breakdown (Step by Step)

#### **Helper Function: `getCoordinate`**

```cpp
void getCoordinate(int n, int s, int &row, int &col) {
    row = n-1-(s-1)/n;
    col = (s-1)%n;
    if((n%2 ==1 && row%2==1) || (n%2==0 && row%2==0))
        col= n-1-col;
}
```

- The helper function `getCoordinate` converts the linear position `s` into the corresponding row and column on the board.
- The position is calculated by dividing and taking the modulo with respect to the size of the board `n`.
- The board has a **zig-zag** pattern where the rows alternate in direction. If the row number is odd, the board's direction is reversed.
- The function updates the `row` and `col` by using these rules, ensuring we can correctly map a linear index to the 2D board.

#### **Main Function: `snakesAndLadders`**

```cpp
int snakesAndLadders(vector<vector<int>>& board) {
    int n = board.size();
    vector<bool> seen(n*n+1, false);
    seen[1] = true;
    queue<pair<int, int>> q;
    q.push({1, 0});
```

- The function starts by initializing the board's size `n` and a `seen` array to track which positions have been visited.
- We initialize BFS with the first position (1) and a distance of 0 (since we start at position 1).
- A queue is used to process the BFS, where each element is a pair of the form `{position, distance}`.

```cpp
    while(!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        int row, col, s = p.first, dist = p.second;
        if(s == n*n) 
            return dist;
```

- The main BFS loop dequeues the front of the queue and extracts the current position `s` and the current distance `dist`.
- If the current position `s` is equal to `n*n`, we've reached the goal, and we return the distance, which represents the minimum number of dice rolls.

```cpp
        for(int i = 1; s+i<= n *n && i<=6; i++) {
            getCoordinate(n, s+i, row, col);
            int sfinal = board[row][col] == -1 ? s+i : board[row][col];
            if(seen[sfinal] == false) {
                seen[sfinal] = true;
                q.push({sfinal, dist + 1});
            }
        }
    }
    return -1;
}
```

- For each position, we attempt to roll the dice and move to the next 6 possible positions.
- We use `getCoordinate` to determine the row and column corresponding to the new position.
- If the board value at the new position is not `-1`, this means there is a snake or ladder, and we move to the new position specified by the board value.
- If the final position (after accounting for any snakes or ladders) hasn't been visited yet, we mark it as visited and enqueue it with an incremented distance.
- If no solution is found (i.e., we exhaust the queue without reaching `n*n`), we return -1.

### Complexity

#### **Time Complexity**

- **O(n^2)**: We visit each square on the board at most once. In each iteration of the BFS, we process up to 6 potential moves (dice rolls). Therefore, the time complexity is proportional to the number of squares on the board, which is \( O(n^2) \).

#### **Space Complexity**

- **O(n^2)**: We need space for the `seen` array to track visited positions, as well as a queue for BFS. In the worst case, the queue can store all positions, so the space complexity is also \( O(n^2) \).

### Conclusion

This solution efficiently solves the Snakes and Ladders problem using a **Breadth-First Search (BFS)** approach to simulate the process of rolling dice and moving across the board. By modeling the problem as a shortest-path graph problem, we ensure that we can find the minimum number of moves required to reach the final position. The BFS approach guarantees that we always explore the shortest paths first, and the use of a queue helps in processing each potential dice roll step-by-step. This method efficiently handles the constraints of the problem and provides an optimal solution with a time complexity of \( O(n^2) \).

[`Link to LeetCode Lab`](https://leetcode.com/problems/snakes-and-ladders/description/)

---
{{< youtube 6lH4nO3JfLk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

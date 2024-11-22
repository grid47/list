
+++
authors = ["grid47"]
title = "Leetcode 2038: Remove Colored Pieces if Both Neighbors are the Same Color"
date = "2024-04-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2038: Remove Colored Pieces if Both Neighbors are the Same Color in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","String","Greedy","Game Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "03zIcb12PKo"
youtube_upload_date="2023-10-02"
youtube_thumbnail="https://i.ytimg.com/vi_webp/03zIcb12PKo/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool winnerOfGame(string colors) {
        int a = 0, b = 0;
        for(int i = 1; i < colors.size() - 1; i++) {
            if(colors[i - 1] == colors[i] && colors[i] == colors[i+1]) {
                if(colors[i] == 'A') a++;
                else b++;
            }
        }
        return a > b;
    }
};
{{< /highlight >}}
---

### Problem Statement

In this problem, we are given a string `colors`, where each character is either 'A' or 'B'. The characters represent colored stones arranged in a line. Two players, Alice and Bob, play a game in which they can remove stones based on the following rule:
- A player can only remove a stone if there are three consecutive stones of their color (e.g., "AAA" or "BBB").
- Alice can only remove stones of color 'A', and Bob can only remove stones of color 'B'.

The players alternate turns, starting with Alice. The game continues until neither player can make a move. The objective is to determine if Alice wins, i.e., if she can make more moves than Bob.

### Approach

To solve this problem, we:
1. **Count Possible Moves for Each Player**: Traverse through the string and count how many segments of three consecutive 'A's exist, which represent potential moves for Alice, and count segments of three consecutive 'B's, representing moves for Bob.
2. **Compare Moves**: After counting, compare Alice's moves (`a`) with Bob's moves (`b`). If Alice has more moves than Bob, she will win; otherwise, Bob will win or it will be a draw if Alice cannot win.

The game can only proceed when there are segments of three consecutive 'A's or 'B's. Since the problem asks us to return `true` if Alice has more moves and wins, and `false` otherwise, the approach simply involves counting and comparison.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    bool winnerOfGame(string colors) {
        int a = 0, b = 0;
```

- We initialize two variables, `a` and `b`, to keep track of the moves Alice and Bob can make, respectively.

```cpp
        for(int i = 1; i < colors.size() - 1; i++) {
```

- We start iterating from index `1` and go up to `colors.size() - 2` because we need to check triplets (`colors[i - 1], colors[i], colors[i + 1]`).

```cpp
            if(colors[i - 1] == colors[i] && colors[i] == colors[i+1]) {
                if(colors[i] == 'A') a++;
                else b++;
            }
        }
```

- For each position `i`, we check if it forms a triplet of the same color as `colors[i-1]`, `colors[i]`, and `colors[i+1]`.
  - If the triplet is "AAA", we increment `a`, indicating a move for Alice.
  - If the triplet is "BBB", we increment `b`, indicating a move for Bob.

```cpp
        return a > b;
    }
};
```

- After the loop, we simply compare `a` and `b`. If Alice has more moves (`a > b`), the function returns `true`, meaning Alice wins. If `a <= b`, Bob either wins or they tie, in which case the function returns `false`.

### Complexity

- **Time Complexity**: O(n), where `n` is the length of the `colors` string. We iterate through `colors` once, checking each character for potential moves.
- **Space Complexity**: O(1), as we only use a few integer variables to track counts.

### Conclusion

This solution efficiently determines the winner by counting the number of possible moves for Alice and Bob. Since moves can only be made from groups of three consecutive 'A's or 'B's, we simply check and count these patterns. The solution is optimal in both time and space, providing a clear and efficient way to determine the game's outcome based on the conditions given.

[`Link to LeetCode Lab`](https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/description/)

---
{{< youtube 03zIcb12PKo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

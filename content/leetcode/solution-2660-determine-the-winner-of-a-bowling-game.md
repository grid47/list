
+++
authors = ["grid47"]
title = "Leetcode 2660: Determine the Winner of a Bowling Game"
date = "2024-02-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2660: Determine the Winner of a Bowling Game in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "UzLjzmjhVqs"
youtube_upload_date="2023-04-30"
youtube_thumbnail="https://i.ytimg.com/vi_webp/UzLjzmjhVqs/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int isWinner(vector<int>& p1, vector<int>& p2) {
        int sc1 = 0, sc2 = 0;
        int n = p1.size();
        for(int i = 0; i < n; i++) {
            if(i > 1 && (p1[i - 1] == 10 || p1[i - 2] == 10)) {
                sc1 += 2 * p1[i];
            } else if(i > 0 && p1[i - 1] == 10){
                sc1 += 2 * p1[i];                
            }
            else sc1 += p1[i];
            if(i > 1 && (p2[i - 1] == 10 || p2[i - 2] == 10)) {
                sc2 += 2 * p2[i];
            }else if(i > 0 && p2[i - 1] == 10){
                sc2 += 2 * p2[i];                
            } else sc2 += p2[i];            
        }
        if(sc1 > sc2) return 1;
        if(sc2 > sc1) return 2;
        return 0;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem involves simulating a bowling game between two players, `p1` and `p2`, who each roll a series of frames. Each player gets a score for each roll, but if a player rolls a strike (a score of 10), the subsequent rolls are worth double. The task is to determine the winner of the game based on the rules mentioned and return `1` if player `p1` wins, `2` if player `p2` wins, or `0` if it is a tie.

### Approach

In this bowling game, the primary challenge is calculating the scores based on special rules for strikes. A strike, represented by a score of 10, influences the score of the subsequent roll(s). If the previous roll or the two preceding rolls were strikes, the current roll is worth double. 

To solve the problem:
1. We iterate through both players' scores, calculating their total score while taking into account the rule for strikes.
2. We keep track of two scores: `sc1` for player 1 and `sc2` for player 2.
3. For each roll, we check the conditions for a strike and adjust the score accordingly.
4. After processing all frames, we compare the scores of both players and return the winner.

### Code Breakdown (Step by Step)

```cpp
int isWinner(vector<int>& p1, vector<int>& p2) {
    int sc1 = 0, sc2 = 0;
    int n = p1.size();
```
- **Line 1-3**: We define the function `isWinner`, which takes two vectors `p1` and `p2`, representing the scores of player 1 and player 2, respectively.
- **Line 2**: Two variables `sc1` and `sc2` are initialized to 0 to keep track of the total scores for player 1 and player 2.
- **Line 3**: We determine the number of frames `n` based on the size of the vector `p1`, assuming both players have the same number of frames.

```cpp
    for(int i = 0; i < n; i++) {
        if(i > 1 && (p1[i - 1] == 10 || p1[i - 2] == 10)) {
            sc1 += 2 * p1[i];
        } else if(i > 0 && p1[i - 1] == 10){
            sc1 += 2 * p1[i];                
        }
        else sc1 += p1[i];
```
- **Line 4-9**: This loop iterates over each frame for player 1. We check the conditions for a strike:
  - **Condition 1**: If the previous roll or the two preceding rolls were strikes (i.e., `p1[i - 1] == 10 || p1[i - 2] == 10`), the current roll is worth double.
  - **Condition 2**: If only the immediate previous roll was a strike (i.e., `p1[i - 1] == 10`), the current roll is worth double.
  - **Else**: If no strike condition applies, the current roll is simply added to `sc1`.

```cpp
        if(i > 1 && (p2[i - 1] == 10 || p2[i - 2] == 10)) {
            sc2 += 2 * p2[i];
        } else if(i > 0 && p2[i - 1] == 10){
            sc2 += 2 * p2[i];                
        } else sc2 += p2[i];            
    }
```
- **Line 10-15**: Similarly, we perform the same checks for player 2:
  - **Condition 1**: If the previous roll or the two preceding rolls were strikes, the current roll is worth double for player 2.
  - **Condition 2**: If only the immediate previous roll was a strike, the current roll is worth double for player 2.
  - **Else**: If no strike condition applies, the current roll is added to `sc2`.

```cpp
    if(sc1 > sc2) return 1;
    if(sc2 > sc1) return 2;
    return 0;
}
```
- **Line 16-18**: After iterating over all frames for both players, we compare the final scores `sc1` and `sc2`.
  - If `sc1` (player 1's score) is greater than `sc2` (player 2's score), we return `1` to indicate player 1 wins.
  - If `sc2` is greater than `sc1`, we return `2` to indicate player 2 wins.
  - If both scores are equal, we return `0` to indicate a tie.

### Complexity

#### Time Complexity:
- The solution loops through both player scores in a single `for` loop. The time complexity of iterating through the scores is **O(n)**, where `n` is the number of frames (or the number of elements in `p1` and `p2`).
- Since the loop only contains constant time operations (comparisons and additions), the overall time complexity is **O(n)**.

#### Space Complexity:
- The space complexity is **O(1)** because the solution uses a constant amount of extra space to store temporary variables (`sc1`, `sc2`, and `n`), regardless of the size of the input vectors.

### Conclusion

This solution efficiently determines the winner of the bowling game by simulating the score calculation process, factoring in the bonus points awarded for strikes. It iterates over the frames, checks the strike conditions, and calculates the total scores for each player. The solution has a time complexity of **O(n)** and space complexity of **O(1)**, making it suitable for large inputs. The implementation is simple, clear, and easy to understand, providing an optimal way to determine the winner in a bowling game with strike rules.

[`Link to LeetCode Lab`](https://leetcode.com/problems/determine-the-winner-of-a-bowling-game/description/)

---
{{< youtube UzLjzmjhVqs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |


+++
authors = ["grid47"]
title = "Leetcode 837: New 21 Game"
date = "2024-08-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 837: New 21 Game in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Dynamic Programming","Sliding Window","Probability and Statistics"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "zKi4LzjK27k"
youtube_upload_date="2023-05-25"
youtube_thumbnail="https://i.ytimg.com/vi/zKi4LzjK27k/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    double new21Game(int n, int k, int w) {
        

        if(k == 0 || n >= k + w)
            return 1;

        
        /*
        
        You will get number x (1 to w) in a draw, with probablity 1 / w
        
        if you need probablity of getting i points in a draw
        
        we can do slecting (i - x) points with probablity dp[i - x] and
        selecting x with probablity x
        
        so doing it together dp[i - x] * 1 / w
        
        and this to every x in [1, w] to get net prob of dp[i].
        
        once the pionts has crossed a limit k, there will be no more selections.
        
        then we look for only the over flows from previous trials.

        why target probablity counted from k onward instead of dp[n].

        */        
        
        vector<double> dp(n+1);
        dp[0] = 1;
        double Wsum = 1.0, res = 0.0;
        for(int i = 1; i <= n; i++) {
            dp[i] = Wsum/ w;
            if(i < k) Wsum += dp[i];
            else res += dp[i];
            if(i - w >= 0) Wsum -= dp[i - w];
        }
        return res;
    }
};
{{< /highlight >}}
---

### Problem Statement

In this problem, we are tasked with solving a variant of the "21 Game" in a probabilistic setting. In the game, we are given a total number of points `n`, a threshold value `k` (which is the target), and a range `w` of possible points you can get in each draw. The task is to calculate the probability of achieving exactly `n` points or fewer, starting from a score of `0`, without exceeding `n` points.

- **n**: The total score we aim to achieve or exceed.
- **k**: The threshold score, at which we stop drawing cards (if the score is greater than or equal to `k`, no more cards are drawn).
- **w**: The maximum value a single card can have in a draw.

### Approach

The goal is to compute the probability of reaching a score less than or equal to `n` without exceeding `n`. The game has certain dynamics, where you draw cards, and each card has a value from `1` to `w`. If a score `i` exceeds `n`, the game ends, and we do not continue drawing cards. We need to calculate the probability that the game ends in a score less than or equal to `n`.

#### Key Observations:

1. The game ends as soon as your score reaches or exceeds `k`. If the score exceeds `n`, it is also an end condition.
2. Every time you draw a card, you gain between 1 and `w` points, and the probability of drawing a particular card value is `1/w`.
3. The dynamic programming approach works well here. We use a DP array, `dp[i]`, to store the probability of reaching exactly `i` points at any given time. The main challenge is to efficiently calculate these probabilities without redundantly computing subproblems.
4. We start by initializing `dp[0] = 1` because starting from score `0` is guaranteed. Then, we calculate probabilities for each score up to `n`.

### Code Breakdown (Step by Step)

```cpp
vector<double> dp(n+1);
dp[0] = 1;
double Wsum = 1.0, res = 0.0;
```
- We initialize an array `dp` of size `n + 1` to store the probabilities. The element `dp[i]` will represent the probability of having exactly `i` points.
- We set `dp[0] = 1` because the probability of starting from `0` is always 1.
- `Wsum` is used to maintain the sum of the probabilities from the previous `w` states (i.e., the sum of probabilities for scores that can contribute to the current score).

```cpp
for(int i = 1; i <= n; i++) {
    dp[i] = Wsum / w;
    if(i < k) Wsum += dp[i];
    else res += dp[i];
    if(i - w >= 0) Wsum -= dp[i - w];
}
```
- For each score `i` from `1` to `n`, we compute the probability of reaching `i` points by considering all possible previous states that can contribute to this score.
  - The probability `dp[i]` is computed as the sum of probabilities of drawing any card that leads to score `i`, which is given by `Wsum / w` (as we divide the sum by `w` because each draw has an equal probability).
- If `i < k`, we add `dp[i]` to `Wsum` since we are still drawing cards and the score has not reached the threshold `k`.
- If `i >= k`, we stop drawing cards and add `dp[i]` to the result `res` because this is the score we are interested in.
- If `i - w >= 0`, we subtract `dp[i - w]` from `Wsum` to ensure that the sliding window of probabilities is kept up to date.

Finally, the result `res` will contain the total probability of reaching a score from `k` to `n` without exceeding `n`.

```cpp
return res;
```
- Return the result `res`, which contains the total probability of achieving a score within the required range.

### Complexity

#### Time Complexity:

- **O(n)**: We loop through each score from `1` to `n`. For each score, we perform constant time operations (adding and subtracting values to/from `Wsum`). Thus, the overall time complexity is linear with respect to the number of scores `n`.

#### Space Complexity:

- **O(n)**: We use an array `dp` of size `n + 1` to store the probabilities for each score from `0` to `n`. The space complexity is therefore proportional to `n`.

### Conclusion

The `new21Game` function computes the probability of achieving a score within the allowed range by using dynamic programming. By maintaining a running sum of probabilities (`Wsum`), the solution efficiently calculates the required probability for each score. The sliding window technique ensures that we do not redundantly compute overlapping subproblems, making this approach both time and space efficient.

This solution is optimal for solving the problem with a time complexity of **O(n)** and space complexity of **O(n)**, making it scalable for large inputs.

This approach uses concepts of dynamic programming, sliding window, and probabilistic calculations, all of which contribute to its efficiency in solving the "new21Game" problem.

[`Link to LeetCode Lab`](https://leetcode.com/problems/new-21-game/description/)

---
{{< youtube zKi4LzjK27k >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

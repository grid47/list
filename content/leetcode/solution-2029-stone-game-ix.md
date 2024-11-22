
+++
authors = ["grid47"]
title = "Leetcode 2029: Stone Game IX"
date = "2024-04-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2029: Stone Game IX in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Greedy","Counting","Game Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "7r34JD5ud-c"
youtube_upload_date="2021-10-03"
youtube_thumbnail="https://i.ytimg.com/vi/7r34JD5ud-c/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int> m(3, 0);
        for(int a: stones)
        m[a % 3]++;
        if(min(m[2], m[1]) == 0)
        return max(m[1], m[2]) > 2 && m[0] % 2 >0;
        return abs(m[1] - m[2]) > 2 || m[0] % 2 == 0;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem revolves around a two-player game involving a pile of stones. Players take turns removing stones from the pile, and the game rules specify that players can remove stones with specific properties. The objective is to determine whether the first player has a winning strategy given an array of stone values. Each stone value can be categorized based on its modulo 3 value, which influences the game's outcome.

### Approach

To determine if the first player can always win, we can break down the game using the properties of the stones based on their modulo values. The key steps in our approach include:

1. **Counting Stones by Remainder**: We will categorize stones into three groups based on their values when divided by 3:
   - Stones with a remainder of 0 (i.e., `value % 3 == 0`)
   - Stones with a remainder of 1 (i.e., `value % 3 == 1`)
   - Stones with a remainder of 2 (i.e., `value % 3 == 2`)

2. **Analyzing Game Conditions**: The winning conditions depend on the counts of these stones. The first player's strategy will rely on how many stones are present in each category:
   - If there are no stones with a remainder of 1 or 2, the first player can only take stones with a remainder of 0. In this case, if there is more than one stone, the second player will always win.
   - If there are stones with either remainder, we analyze their counts to determine if the first player can manipulate the game toward their advantage.

3. **Establishing Winning Conditions**: The game's outcome is determined by the following conditions:
   - If one type of remainder (either 1 or 2) has zero stones, the first player can only win if they can ensure that there are more than two stones of the other type and an odd count of stones with a remainder of 0.
   - If both types of remainders are present, the first player wins if the absolute difference in counts of the stones with remainders of 1 and 2 is greater than 2 or if the count of stones with remainder 0 is even.

### Code Breakdown (Step by Step)

Now, let's delve into the provided code to understand its functionality:

```cpp
class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
```
- Here, we define the `Solution` class and the method `stoneGameIX`, which accepts a vector of integers representing the stones.

```cpp
        vector<int> m(3, 0);
        for(int a: stones)
            m[a % 3]++;
```
- We initialize a vector `m` of size 3 to count the stones based on their modulo 3 values. The loop iterates through the `stones` vector and increments the appropriate index of `m` based on the modulo result.

```cpp
        if(min(m[2], m[1]) == 0)
            return max(m[1], m[2]) > 2 && m[0] % 2 > 0;
```
- This condition checks if there are no stones of one of the remainders (either 1 or 2). If so, it checks if there are more than two stones of the other type and if the count of stones with remainder 0 is odd. If both conditions are true, the first player can win.

```cpp
        return abs(m[1] - m[2]) > 2 || m[0] % 2 == 0;
```
- If both types of stones are present, the method checks whether the absolute difference between the counts of stones with remainders 1 and 2 is greater than 2 or if the count of stones with remainder 0 is even. If either condition holds, the first player has a winning strategy.

### Complexity

- **Time Complexity**: The time complexity is O(n), where n is the number of stones. This is because we need to iterate through the `stones` array once to populate the counts.

- **Space Complexity**: The space complexity is O(1) since we only use a fixed-size array of size 3 to store the counts of the stones based on their remainders.

### Conclusion

In conclusion, the `stoneGameIX` method effectively determines if the first player has a winning strategy based on the modulo classification of the stones. By leveraging simple counting and logical conditions, we can derive the outcome of the game efficiently. The implementation is straightforward, relying on basic properties of numbers, which makes it not only effective but also easy to understand. This solution illustrates how game theory can be applied to seemingly simple problems, providing insights into strategic decision-making based on available resources.

[`Link to LeetCode Lab`](https://leetcode.com/problems/stone-game-ix/description/)

---
{{< youtube 7r34JD5ud-c >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

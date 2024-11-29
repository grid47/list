
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
comments = true
+++



---
Alice and Bob are playing a game with stones. The sequence of `n` stones has values given in an array `stones`. Players take turns to remove a stone. The player who removes a stone, making the sum of all removed stones divisible by 3, loses. If all stones are removed, Bob wins automatically. Determine if Alice wins or Bob wins, assuming both play optimally.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array `stones` representing the values of the stones. Alice and Bob alternate turns, starting with Alice. On each turn, one stone is removed.
- **Example:** `stones = [3, 2]`
- **Constraints:**
	- 1 <= stones.length <= 10^5
	- 1 <= stones[i] <= 10^4

{{< dots >}}
### Output Specifications 📤
- **Output:** Return `true` if Alice wins and `false` if Bob wins.
- **Example:** ``
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to determine the winner of the game based on the values of the stones and the optimal moves by both players.

- 1. Count the number of stones with values that leave remainders of 0, 1, and 2 when divided by 3.
- 2. Use the counts of stones with each remainder to decide the optimal moves for Alice and Bob.
- 3. Check if the sum of the removed stones after each turn is divisible by 3 to determine the winner.
{{< dots >}}
### Problem Assumptions ✅
- Players will always play optimally and aim to avoid the sum of removed stones being divisible by 3.
{{< dots >}}
## Examples 🧩
- **Input:** `stones = [3, 2]`  \
  **Explanation:** Alice removes the stone with value 2, and Bob removes the stone with value 3. The sum of the removed stones is 5, which is not divisible by 3, so Alice wins.

- **Input:** `stones = [1, 1, 1]`  \
  **Explanation:** Alice removes one stone (value 1), Bob removes another (value 1), and Alice removes the last one (value 1). The sum is 3, divisible by 3, so Alice loses and Bob wins.

- **Input:** `stones = [4, 6, 2]`  \
  **Explanation:** Alice removes the stone with value 2, Bob removes the stone with value 4, and Alice removes the last stone with value 6. The sum is 12, divisible by 3, so Alice wins.

{{< dots >}}
## Approach 🚀
To solve this problem, we need to simulate the game and determine who will win given the sequence of stones and the optimal play strategy.

### Initial Thoughts 💭
- The game is primarily determined by the number of stones that leave remainders of 0, 1, and 2 when divided by 3.
- The game ends when one player causes the sum of the removed stones to be divisible by 3.
- By analyzing the remainders of the stone values modulo 3, we can determine the optimal strategy for both Alice and Bob.
{{< dots >}}
### Edge Cases 🌐
- Not applicable since there will always be at least one stone.
- Ensure the solution is optimized for large inputs (up to 10^5 stones).
- If all stones are divisible by 3, Bob will always win.
- Ensure the algorithm is efficient enough to handle the maximum input size within the time limits.
{{< dots >}}
## Code 💻
```cpp
bool stoneGameIX(vector<int>& stones) {
    vector<int> m(3, 0);
    for(int a: stones)
    m[a % 3]++;
    if(min(m[2], m[1]) == 0)
    return max(m[1], m[2]) > 2 && m[0] % 2 >0;
    return abs(m[1] - m[2]) > 2 || m[0] % 2 == 0;
}
```

This function determines the winner of the Stone Game IX based on the division of stones into three groups (modulo 3). It uses counters to track the number of stones in each group and applies game logic to decide the winner.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool stoneGameIX(vector<int>& stones) {
	```
	This defines the 'stoneGameIX' function, which accepts a vector of stones and returns a boolean indicating whether the current player wins the game.

2. **Array Initialization**
	```cpp
	    vector<int> m(3, 0);
	```
	This initializes a vector 'm' of size 3, used to store the counts of stones divided into 3 groups based on their remainder when divided by 3.

3. **Loop Start**
	```cpp
	    for(int a: stones)
	```
	This loop iterates through each stone in the 'stones' vector, performing the modulo operation to categorize the stones into one of three groups.

4. **Update Counter**
	```cpp
	    m[a % 3]++;
	```
	For each stone 'a', this increments the corresponding counter in the 'm' vector based on the result of 'a % 3'.

5. **Condition Check**
	```cpp
	    if(min(m[2], m[1]) == 0)
	```
	This checks whether one of the groups (1 or 2 modulo 3) has zero stones, which will influence the game's outcome.

6. **Return Condition 1**
	```cpp
	    return max(m[1], m[2]) > 2 && m[0] % 2 >0;
	```
	This checks if the maximum count between groups 1 and 2 is greater than 2 and if the count of group 0 is odd, deciding the winner.

7. **Return Condition 2**
	```cpp
	    return abs(m[1] - m[2]) > 2 || m[0] % 2 == 0;
	```
	If the first condition is not met, this checks if the absolute difference between groups 1 and 2 is greater than 2 or if the count of group 0 is even, deciding the winner.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The algorithm runs in linear time relative to the number of stones.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant because we only need to track the counts of stones with different remainders modulo 3.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/stone-game-ix/description/)

---
{{< youtube 7r34JD5ud-c >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

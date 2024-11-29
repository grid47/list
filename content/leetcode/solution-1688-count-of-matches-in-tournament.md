
+++
authors = ["grid47"]
title = "Leetcode 1688: Count of Matches in Tournament"
date = "2024-05-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1688: Count of Matches in Tournament in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "lslcc0tumpU"
youtube_upload_date="2023-12-05"
youtube_thumbnail="https://i.ytimg.com/vi/lslcc0tumpU/maxresdefault.jpg"
comments = true
+++



---
In a tournament with `n` teams, each round involves pairing teams for matches. The number of matches depends on whether `n` is even or odd. Calculate the total number of matches played in the tournament until a winner is determined.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a single integer `n`, the number of teams in the tournament.
- **Example:** `Input: n = 9`
- **Constraints:**
	- 1 <= n <= 200

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a single integer representing the total number of matches played in the tournament.
- **Example:** `Output: 8`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to calculate the total number of matches played during the entire tournament, taking into account the number of teams in each round.

- If the number of teams is even, `n / 2` matches are played and `n / 2` teams advance.
- If the number of teams is odd, `(n - 1) / 2` matches are played and `(n - 1) / 2 + 1` teams advance.
- Repeat this process until only one team remains, counting the matches at each step.
{{< dots >}}
### Problem Assumptions ✅
- At least one team is always present in the tournament.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: n = 9`  \
  **Explanation:** The tournament progresses through multiple rounds. In each round, the number of matches is determined based on whether the number of teams is even or odd. The total matches are accumulated as we move towards the final winner.

{{< dots >}}
## Approach 🚀
To solve the problem, simulate the tournament by calculating the number of matches played in each round based on the current number of teams. Keep track of the total number of matches until only one team is left.

### Initial Thoughts 💭
- The number of matches in each round is simple to calculate based on whether the number of teams is even or odd.
- We can use recursion or iteration to repeatedly reduce the number of teams and accumulate the match count until we reach the final winner.
{{< dots >}}
### Edge Cases 🌐
- The input `n` should always be a valid positive integer, so empty inputs will not be encountered.
- The algorithm must efficiently handle the maximum number of teams, which is 200.
- If `n` is 1, no matches are played, and the total matches is 0.
- Ensure that the solution works within the constraint `1 <= n <= 200`.
{{< dots >}}
## Code 💻
```cpp
int numberOfMatches(int n) {
    if(n==0) return 0;
    if(n==1) return 0;
    int ans = n / 2;
    if(n & 1)
    ans += numberOfMatches(n/2 + 1);
    else
    ans += numberOfMatches(n/2);
    return ans;
}
```

This function recursively calculates the total number of matches in a tournament with `n` players, assuming each match eliminates one player and each round reduces the number of players by half. The recursion continues until there are no more matches to play.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int numberOfMatches(int n) {
	```
	Define the function 'numberOfMatches' that takes an integer `n`, representing the number of players, and returns the total number of matches in the tournament.

2. **Base Case 1**
	```cpp
	    if(n==0) return 0;
	```
	Base case: If there are no players (`n == 0`), return 0 matches as there are no players to compete.

3. **Base Case 2**
	```cpp
	    if(n==1) return 0;
	```
	Base case: If there is only one player (`n == 1`), return 0 matches as a single player cannot compete.

4. **Initialize Answer**
	```cpp
	    int ans = n / 2;
	```
	Initialize the answer `ans` as the integer division of `n` by 2, representing the matches in the current round (each match eliminates one player).

5. **Odd Players Check**
	```cpp
	    if(n & 1)
	```
	Check if the number of players `n` is odd using bitwise AND (`n & 1`). If `n` is odd, there will be one player left after the matches in the current round.

6. **Recursive Call (Odd Players)**
	```cpp
	    ans += numberOfMatches(n/2 + 1);
	```
	If the number of players is odd, recursively call `numberOfMatches` with `n/2 + 1` players, as one player will have a 'bye' and not participate in the current round.

7. **Else Condition**
	```cpp
	    else
	```
	If the number of players is even, proceed to the next step without any players getting a 'bye'.

8. **Recursive Call (Even Players)**
	```cpp
	    ans += numberOfMatches(n/2);
	```
	If the number of players is even, recursively call `numberOfMatches` with `n/2` players, as there are no 'byes' in this round.

9. **Return Statement**
	```cpp
	    return ans;
	```
	Return the total number of matches calculated for the current round and all subsequent rounds.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(log n)
- **Average Case:** O(log n)
- **Worst Case:** O(log n)

The time complexity is O(log n) because the number of teams is halved in each round.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) since the solution uses constant space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/count-of-matches-in-tournament/description/)

---
{{< youtube lslcc0tumpU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

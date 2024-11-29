
+++
authors = ["grid47"]
title = "Leetcode 1395: Count Number of Teams"
date = "2024-06-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1395: Count Number of Teams in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Binary Indexed Tree","Segment Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "zONHzIqCr-o"
youtube_upload_date="2024-07-29"
youtube_thumbnail="https://i.ytimg.com/vi/zONHzIqCr-o/maxresdefault.jpg"
comments = true
+++



---
You are given a list of soldiers, each with a unique rating. You need to form teams of 3 soldiers from this list. A valid team is one where the soldiers' ratings are either strictly increasing or strictly decreasing as we move from left to right in the team. The team must satisfy the condition that the indices (i, j, k) follow 0 <= i < j < k < n.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a list of integers representing the soldiers' ratings.
- **Example:** `rating = [3, 6, 1, 4, 5]`
- **Constraints:**
	- n == rating.length
	- 3 <= n <= 1000
	- 1 <= rating[i] <= 105
	- All the integers in rating are unique.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is the total number of valid teams of size 3 that can be formed based on the ratings.
- **Example:** `Output: 4`
- **Constraints:**
	- The output will be an integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** To count the number of valid teams that can be formed.

- For each combination of three indices (i, j, k), check if the ratings are in increasing or decreasing order.
- Sum up all valid teams.
{{< dots >}}
### Problem Assumptions ✅
- The ratings are given in an array, and no two soldiers have the same rating.
- You can form multiple teams with the same soldiers in different orders.
{{< dots >}}
## Examples 🧩
- **Input:** `rating = [3, 6, 1, 4, 5]`  \
  **Explanation:** The valid teams are: (3, 4, 5), (6, 1, 4), (6, 1, 5), and (6, 4, 1).

{{< dots >}}
## Approach 🚀
The problem can be solved by brute force, where we check each possible triplet of indices (i, j, k) and verify if they form a valid team.

### Initial Thoughts 💭
- We need to check all combinations of 3 soldiers from the list.
- We can optimize by using dynamic programming or a memoization approach to reduce redundant checks.
{{< dots >}}
### Edge Cases 🌐
- Not applicable as n is always at least 3.
- Ensure that the approach scales for large inputs, up to n = 1000.
- Consider inputs where the ratings are in strictly increasing or strictly decreasing order.
- Avoid brute force solutions that involve checking all possible triplets for larger inputs.
{{< dots >}}
## Code 💻
```cpp

int memo[1001][1001][4];
vector<int> rate;

int dp(int idx, int prv, int cnt) {
    if(cnt == 3) return 1;
    if(idx == rate.size()) return 0;
    if(memo[idx][prv + 1][cnt] != -1) return memo[idx][prv + 1][cnt];
    int ans = 0;
    if(prv == -1 || rate[idx] > rate[prv]) {
        ans += dp(idx + 1, idx, cnt + 1);
    }
    ans += dp(idx + 1, prv, cnt);
    
    return memo[idx][prv + 1][cnt] = ans;
}

int numTeams(vector<int>& rate) {
    this->rate = rate;
    memset(memo, -1, sizeof(memo));
    int res1 = dp(0, -1, 0);

    reverse(this->rate.begin(),this->rate.end());

    memset(memo, -1, sizeof(memo));        
    int res2 = dp(0, -1, 0);

    return res1 + res2;
}
```

This function calculates the number of possible teams that can be formed based on certain conditions using dynamic programming with memoization.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	int memo[1001][1001][4];
	```
	We create a memoization table 'memo' to store intermediate results of subproblems.

2. **Variable Initialization**
	```cpp
	vector<int> rate;
	```
	We declare a vector 'rate' to store the ratings of the players.

3. **Base Case Check**
	```cpp
	int dp(int idx, int prv, int cnt) {
	```
	The function takes three arguments: the current index 'idx', the previous index 'prv', and the count of players in the current team 'cnt'.

4. **Base Case Check**
	```cpp
	    if(cnt == 3) return 1;
	```
	If we have selected three players, we return 1, as a valid team has been formed.

5. **Base Case Check**
	```cpp
	    if(idx == rate.size()) return 0;
	```
	If we have processed all the ratings and haven’t formed a team, we return 0.

6. **Memoization Check**
	```cpp
	    if(memo[idx][prv + 1][cnt] != -1) return memo[idx][prv + 1][cnt];
	```
	If the result for the current state is already computed, we return the stored result to avoid redundant calculations.

7. **Recursive Case**
	```cpp
	    int ans = 0;
	```
	We initialize a variable 'ans' to store the number of valid teams.

8. **Recursive Case**
	```cpp
	    if(prv == -1 || rate[idx] > rate[prv]) {
	```
	If the current rating is greater than the previous player's rating, we proceed to form a team.

9. **Recursive Case**
	```cpp
	        ans += dp(idx + 1, idx, cnt + 1);
	```
	We call the 'dp' function recursively to include the current player and increase the team count.

10. **Recursive Case**
	```cpp
	    ans += dp(idx + 1, prv, cnt);
	```
	We also recursively check if the current player can be skipped (no change in team).

11. **Memoization Storage**
	```cpp
	    return memo[idx][prv + 1][cnt] = ans;
	```
	Return the computed result and store it in the memoization table for future reference.

12. **Main Function**
	```cpp
	int numTeams(vector<int>& rate) {
	```
	The 'numTeams' function calculates the total number of valid teams.

13. **Variable Setup**
	```cpp
	    this->rate = rate;
	```
	We store the input ratings in the class variable 'rate'.

14. **Memoization Setup**
	```cpp
	    memset(memo, -1, sizeof(memo));
	```
	We initialize the memoization table with -1 to signify that no subproblem has been solved yet.

15. **Recursive Call**
	```cpp
	    int res1 = dp(0, -1, 0);
	```
	We call the 'dp' function to calculate the result for the first order of ratings.

16. **Reverse Setup**
	```cpp
	    reverse(this->rate.begin(),this->rate.end());
	```
	We reverse the 'rate' vector to handle the reversed case.

17. **Memoization Setup**
	```cpp
	    memset(memo, -1, sizeof(memo));        
	```
	Reinitialize the memoization table before calling the 'dp' function again.

18. **Recursive Call**
	```cpp
	    int res2 = dp(0, -1, 0);
	```
	We calculate the result for the reversed ratings.

19. **Final Calculation**
	```cpp
	    return res1 + res2;
	```
	Return the total number of valid teams from both the original and reversed rating order.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^3)
- **Average Case:** O(n^3)
- **Worst Case:** O(n^3)

Since we are checking each combination of 3 soldiers, the time complexity is cubic in the worst case.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

We use a constant amount of space beyond the input list, so the space complexity is O(1).

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/count-number-of-teams/description/)

---
{{< youtube zONHzIqCr-o >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

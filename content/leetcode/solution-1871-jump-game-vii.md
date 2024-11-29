
+++
authors = ["grid47"]
title = "Leetcode 1871: Jump Game VII"
date = "2024-05-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1871: Jump Game VII in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Dynamic Programming","Sliding Window","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "v1HpZUnQ4Yo"
youtube_upload_date="2021-05-23"
youtube_thumbnail="https://i.ytimg.com/vi/v1HpZUnQ4Yo/maxresdefault.jpg"
comments = true
+++



---
You are given a binary string `s` and two integers `minJump` and `maxJump`. Initially, you are at index `0` of the string `s`, which is guaranteed to be '0'. You can move from index `i` to index `j` if: i + minJump <= j <= min(i + maxJump, s.length - 1), and s[j] == '0'. Return `true` if it’s possible to reach the last index of the string (`s.length - 1`), or `false` otherwise.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are provided with a binary string `s` and two integers `minJump` and `maxJump`. The string `s` contains only '0' and '1'.
- **Example:** `For s = "011010", minJump = 2, maxJump = 3.`
- **Constraints:**
	- 2 <= s.length <= 105
	- s[i] is either '0' or '1'.
	- s[0] == '0'
	- 1 <= minJump <= maxJump < s.length

{{< dots >}}
### Output Specifications 📤
- **Output:** Return `true` if it’s possible to reach the last index, or `false` if it’s impossible.
- **Example:** `For the input s = "011010", minJump = 2, maxJump = 3, the output is `true`.`
- **Constraints:**
	- The output must be a boolean value.

{{< dots >}}
### Core Logic 🔍
**Goal:** We need to determine if there exists a valid sequence of jumps that reaches the last index.

- Initialize a dynamic programming array `dp` to track which indices can be reached.
- Iterate through the string and use the previous `dp` values to determine if the current index can be reached.
- Use sliding window technique to efficiently update the reachable indices based on `minJump` and `maxJump`.
{{< dots >}}
### Problem Assumptions ✅
- The string always starts with '0' at index 0.
- At least one valid path exists in some test cases.
{{< dots >}}
## Examples 🧩
- **Input:** `For the input s = "011010", minJump = 2, maxJump = 3.`  \
  **Explanation:** The first move can be from index 0 to index 3 (using minJump = 2). From there, you can move from index 3 to index 5, reaching the last index.

- **Input:** `For the input s = "01101110", minJump = 2, maxJump = 3.`  \
  **Explanation:** No valid jumps exist because there’s no way to reach the last index.

{{< dots >}}
## Approach 🚀
We use a dynamic programming approach where we maintain a sliding window to efficiently track the reachable indices based on `minJump` and `maxJump`.

### Initial Thoughts 💭
- We need to efficiently calculate which indices are reachable from each position.
- Using a sliding window of reachable indices helps avoid unnecessary recalculations.
- The goal is to minimize the time complexity while ensuring correctness by checking each possible jump within the given constraints.
{{< dots >}}
### Edge Cases 🌐
- Not applicable as the string length is at least 2.
- Ensure that the algorithm scales for larger values of `s.length`.
- Test with a string of length 2, where only the first and last index can be reached.
- Check edge cases for large values of `minJump` and `maxJump`.
{{< dots >}}
## Code 💻
```cpp
bool canReach(string s, int mnj, int mxj) {
    int n = s.length();
    vector<bool> dp(n, false);
    dp[0] = true;
    int pre = 0;
    for(int i = 0; i < n; i++) {
    
        if(i >= mnj && dp[i - mnj])
            pre++;

        if(i > mxj && dp[i - mxj -1])
            pre--;

        if (pre > 0) dp[i] = s[i] == '0';       
    }
    return dp[n - 1];
}
```

This code checks if it's possible to reach the last index of a binary string using a sliding window-based dynamic programming approach, constrained by minimum and maximum jump values.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Initialization**
	```cpp
	bool canReach(string s, int mnj, int mxj) {
	```
	Define the function to determine reachability in a binary string with jump constraints.

2. **Initialization**
	```cpp
	    int n = s.length();
	```
	Calculate the length of the binary string.

3. **Initialization**
	```cpp
	    vector<bool> dp(n, false);
	```
	Initialize a DP array to track reachable indices, all set to false initially.

4. **Initialization**
	```cpp
	    dp[0] = true;
	```
	Mark the starting index as reachable.

5. **Sliding Window**
	```cpp
	    int pre = 0;
	```
	Initialize a variable to track the sliding window sum for reachability.

6. **Loop**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Iterate through each index of the binary string.

7. **Sliding Window**
	```cpp
	        if(i >= mnj && dp[i - mnj])
	```
	If within range, increment the sliding window sum if the jump from a reachable index is valid.

8. **Sliding Window**
	```cpp
	            pre++;
	```
	Increase the sliding window sum for valid jumps.

9. **Sliding Window**
	```cpp
	        if(i > mxj && dp[i - mxj -1])
	```
	If the jump exceeds the maximum constraint, decrement the sliding window sum.

10. **Sliding Window**
	```cpp
	            pre--;
	```
	Decrease the sliding window sum for invalid jumps.

11. **Condition**
	```cpp
	        if (pre > 0) dp[i] = s[i] == '0';
	```
	Mark the current index as reachable if the sliding window sum is positive and the index is valid ('0').

12. **Return**
	```cpp
	    return dp[n - 1];
	```
	Return whether the last index is reachable based on the DP array.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The solution iterates over the string once while updating reachable indices, resulting in a time complexity of O(n).

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

We use a DP array of size n to store the reachable states, hence the space complexity is O(n).

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/jump-game-vii/description/)

---
{{< youtube v1HpZUnQ4Yo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

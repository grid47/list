
+++
authors = ["grid47"]
title = "Leetcode 2086: Minimum Number of Food Buckets to Feed the Hamsters"
date = "2024-04-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2086: Minimum Number of Food Buckets to Feed the Hamsters in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Dynamic Programming","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "aDb0N0ZBvZQ"
youtube_upload_date="2021-11-27"
youtube_thumbnail="https://i.ytimg.com/vi_webp/aDb0N0ZBvZQ/maxresdefault.webp"
comments = true
+++



---
You are given a string representing hamster positions. The string consists of 'H' for a hamster and '.' for an empty space. You must place food buckets in empty positions such that all hamsters are fed. A hamster is fed if a food bucket is placed at one of its adjacent positions. Your task is to return the minimum number of food buckets required to feed all the hamsters. If it is impossible, return -1.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a string 'hamsters' of length n (1 <= n <= 10^5). The string consists of 'H' for hamster positions and '.' for empty positions.
- **Example:** `".H.H."`
- **Constraints:**
	- 1 <= hamsters.length <= 10^5
	- hamsters[i] is either 'H' or '.'

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of food buckets needed to feed all hamsters, or -1 if it is impossible to feed all hamsters.
- **Example:** `2`
- **Constraints:**
	- Return -1 if it's impossible to feed all hamsters.

{{< dots >}}
### Core Logic 🔍
**Goal:** We aim to feed all hamsters with the minimum number of food buckets placed in empty spaces.

- Iterate through the string and find empty spaces ('.') near a hamster ('H').
- For each hamster, place a food bucket in an adjacent empty space if possible.
- If a hamster cannot be fed (no empty space next to it), return -1.
{{< dots >}}
### Problem Assumptions ✅
- There is at least one hamster in the string.
- All empty spaces are potential places for food buckets.
{{< dots >}}
## Examples 🧩
- **Input:** `".H.H."`  \
  **Explanation:** By placing a food bucket at index 2, both hamsters at indices 1 and 3 will be fed.

{{< dots >}}
## Approach 🚀
To solve the problem efficiently, we can iterate through the string and check the positions of the hamsters. For each hamster, we try to place food buckets in adjacent empty spaces. We should keep track of the positions where food buckets are placed to ensure all hamsters are fed.

### Initial Thoughts 💭
- Hamsters that are isolated between empty spaces will require multiple food buckets.
- Adjacent food buckets can feed multiple hamsters.
- We need to handle each hamster carefully to ensure minimal food bucket usage.
{{< dots >}}
### Edge Cases 🌐
- The string is guaranteed to contain at least one hamster.
- The solution should work efficiently with strings of length up to 100,000.
- If all positions are occupied by hamsters, no food bucket is needed.
- Ensure that the solution runs within the time limit for large inputs.
{{< dots >}}
## Code 💻
```cpp
vector<int> memo;
int dp(int idx, string &ham) {
    if(idx >= ham.size()) {
        // cout << ham << "\n";
        return 0;
    }
    if(memo[idx] != -1) return memo[idx];
    
    int ans = 100001;
    if(ham[idx] == 'H') {
        if(idx + 1 < ham.size() && ham[idx + 1] == '.') {
            // ham[idx + 1] = 'C';
            ans = min(ans, 1 + dp(idx + 3, ham));
            // ham[idx + 1] = '.';
        }
        if(idx - 1 >= 0 && (ham[idx - 1] == '.')) {
            // ham[idx - 1] = 'C';
            ans = min(ans, 1 + dp(idx + 1, ham));
            // ham[idx - 1] = '.';                    
        }
    } else {
        ans = dp(idx + 1, ham);
    }
    
    return memo[idx] = ans;
}

int minimumBuckets(string ham) {
    int n = ham.size();
    memo.resize(n, -1);
    int ans = dp(0, ham);
    return ans >= 100001? -1: ans;
}
```

This code defines a dynamic programming solution to the problem of placing buckets in a hamster maze. It uses a recursive function `dp` to minimize the number of buckets needed, where the hamster can move in the maze according to specific rules.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	vector<int> memo;
	```
	This line initializes a vector `memo` to store the results of subproblems for dynamic programming (memoization). The vector is used to avoid redundant calculations for the same index.

2. **Function Definition**
	```cpp
	int dp(int idx, string &ham) {
	```
	This defines the recursive function `dp`, which takes an index `idx` and a reference to a string `ham` as arguments. The function will return the minimum number of buckets needed for the hamster starting at index `idx`.

3. **Base Case**
	```cpp
	    if(idx >= ham.size()) {
	```
	This checks if the current index `idx` is out of bounds of the string `ham`. If so, the recursion ends and returns 0, as no more buckets are needed.

4. **Base Case Return**
	```cpp
	        return 0;
	```
	If the index `idx` is beyond the maze, the function returns 0, signifying no more buckets are needed.

5. **Memoization Check**
	```cpp
	    if(memo[idx] != -1) return memo[idx];
	```
	This checks if the result for the current index `idx` has already been computed. If so, it returns the stored result from `memo` to avoid recalculating it.

6. **Variable Initialization**
	```cpp
	    int ans = 100001;
	```
	This initializes a variable `ans` with a large value (100001), which will store the minimum number of buckets needed for the current recursive call.

7. **Condition for 'H'**
	```cpp
	    if(ham[idx] == 'H') {
	```
	This checks if the current character at index `idx` in the string `ham` is 'H', which represents the hamster that needs to be placed into a bucket.

8. **Check Right Movement**
	```cpp
	        if(idx + 1 < ham.size() && ham[idx + 1] == '.') {
	```
	This checks if there is a valid position to the right of the hamster (i.e., if the index `idx + 1` is within bounds and the character is '.' which is an empty space).

9. **Recursive Call**
	```cpp
	            ans = min(ans, 1 + dp(idx + 3, ham));
	```
	This line calculates the minimum number of buckets needed by recursively calling the `dp` function. It places the hamster in the right bucket (if possible) and skips 3 positions ahead.

10. **End Right Movement Check**
	```cpp
	        }
	```
	End of the right movement check.

11. **Check Left Movement**
	```cpp
	        if(idx - 1 >= 0 && (ham[idx - 1] == '.')) {
	```
	This checks if there is a valid position to the left of the hamster where a bucket can be placed (i.e., if the index `idx - 1` is valid and the character is '.' which represents an empty space).

12. **Recursive Call Left**
	```cpp
	            ans = min(ans, 1 + dp(idx + 1, ham));
	```
	This recursively calls the `dp` function to calculate the minimum number of buckets required by placing a bucket in the left space and moving one step ahead.

13. **Else Case for Non-H**
	```cpp
	    } else {
	```
	This condition is executed if the current character in `ham` is not 'H'. It moves to the next index without placing a bucket.

14. **Recursive Call Else**
	```cpp
	        ans = dp(idx + 1, ham);
	```
	If the current position does not require a bucket, the function simply moves to the next index.

15. **Memoization Assignment**
	```cpp
	    return memo[idx] = ans;
	```
	This assigns the result of the current recursive call to the `memo` vector at index `idx`, which allows for memoization of previously calculated subproblems.

16. **Main Function**
	```cpp
	int minimumBuckets(string ham) {
	```
	This is the main function `minimumBuckets`, which is responsible for initializing the memoization vector and calling the recursive `dp` function.

17. **Size Calculation**
	```cpp
	    int n = ham.size();
	```
	This calculates the size of the input string `ham`, which represents the hamster maze.

18. **Resize Memoization**
	```cpp
	    memo.resize(n, -1);
	```
	This resizes the `memo` vector to match the size of the input string `ham`, initializing all values to -1.

19. **Call DP**
	```cpp
	    int ans = dp(0, ham);
	```
	This calls the `dp` function starting from index 0 and stores the result in `ans`.

20. **Return Final Result**
	```cpp
	    return ans >= 100001? -1: ans;
	```
	This checks the result of `dp`. If the value is still the initial large number (indicating no valid solution), it returns -1. Otherwise, it returns the result.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n) if there are no isolated hamsters and food buckets can be placed efficiently.
- **Average Case:** O(n) for scanning and placing food buckets.
- **Worst Case:** O(n) due to the need to scan the entire string.

The time complexity is linear in the size of the string.

### Space Complexity 💾
- **Best Case:** O(n) when all spaces are empty and need tracking.
- **Worst Case:** O(n) for storing food bucket placements and the string.

Space complexity is linear due to string traversal and food bucket placement tracking.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-number-of-food-buckets-to-feed-the-hamsters/description/)

---
{{< youtube aDb0N0ZBvZQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

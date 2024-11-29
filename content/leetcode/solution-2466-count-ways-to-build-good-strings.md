
+++
authors = ["grid47"]
title = "Leetcode 2466: Count Ways To Build Good Strings"
date = "2024-03-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2466: Count Ways To Build Good Strings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "t0QkjXhE02g"
youtube_upload_date="2023-05-14"
youtube_thumbnail="https://i.ytimg.com/vi/t0QkjXhE02g/maxresdefault.jpg"
comments = true
+++



---
You are tasked with constructing binary strings using the characters '0' and '1'. The string can be built by repeatedly appending '0' zero times or '1' one times, where 'zero' and 'one' are given values. The length of the final string must lie between 'low' and 'high', inclusive. Your task is to find how many different binary strings can be created that meet these requirements. Return the count modulo 1e9 + 7.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are provided with four integers: low, high, zero, and one. The integers 'low' and 'high' define the range for the possible lengths of the resulting binary string, while 'zero' and 'one' specify how many times the character '0' or '1' can be appended at each step.
- **Example:** `low = 2, high = 4, zero = 1, one = 2`
- **Constraints:**
	- 1 <= low <= high <= 105
	- 1 <= zero, one <= low

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of distinct binary strings that can be constructed such that their length lies between 'low' and 'high' inclusive. The answer should be returned modulo 1e9 + 7.
- **Example:** `For low = 2, high = 4, zero = 1, one = 2, the output is 6.`
- **Constraints:**
	- The result should be an integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** We need to calculate the number of distinct good binary strings that can be constructed using the provided constraints.

- For each possible length between 'low' and 'high', calculate the number of ways to construct a binary string of that length using dynamic programming.
- Store previously computed results to avoid redundant calculations.
- Return the sum of the results modulo 1e9 + 7.
{{< dots >}}
### Problem Assumptions ✅
- The input will always respect the given constraints.
{{< dots >}}
## Examples 🧩
- **Input:** `For low = 2, high = 4, zero = 1, one = 2`  \
  **Explanation:** The good binary strings that can be formed are: '00', '11', '000', '011', '110', '111'. There are 6 distinct strings, so the output is 6.

{{< dots >}}
## Approach 🚀
The solution uses dynamic programming to efficiently count the number of distinct binary strings for each length between 'low' and 'high'.

### Initial Thoughts 💭
- This problem can be solved efficiently using dynamic programming to keep track of previously computed results for subproblems.
- Dynamic programming is the best approach here because it avoids recalculating the number of ways to form strings of the same length multiple times.
{{< dots >}}
### Edge Cases 🌐
- The problem guarantees that the input values will always be within the valid range.
- Ensure that the solution works within the time limits for inputs where high can be as large as 100,000.
- If zero equals one, the problem becomes simpler as the number of ways to form strings is identical for both cases.
- The solution needs to handle inputs where the difference between low and high can be large.
{{< dots >}}
## Code 💻
```cpp
class Solution {
int mod = 1e9 + 7;
public:
int countGoodStrings(int low, int high, int zero, int one) {
    
    vector<int> dp(high + 1, -1);
    int ans = 0;
    for(int i = low; i <= high; i++) {
        ans = (ans + score(i, dp, zero, one)) % mod;
    }
    return ans;
}

int score(int target, vector<int> &dp, int zero, int one) {
    if(target == 0)      return 1;
    if(target < 1 )      return 0;
    if(dp[target] != -1) return dp[target];

    long long sum = score(target - zero, dp, zero, one) + score(target - one, dp, zero, one);

    return dp[target] = sum % mod;
}
```

This code implements a dynamic programming solution to calculate the number of good strings within a specified range. It uses memoization to optimize repeated calculations.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Class Definition**
	```cpp
	class Solution {
	```
	Defines the main class for the solution.

2. **Variable Initialization**
	```cpp
	int mod = 1e9 + 7;
	```
	Declares a constant modulus to handle large numbers and prevent overflow.

3. **Access Modifier**
	```cpp
	public:
	```
	Marks the following methods as accessible from outside the class.

4. **Function Definition**
	```cpp
	int countGoodStrings(int low, int high, int zero, int one) {
	```
	Defines the main function to count good strings within a range.

5. **Vector Initialization**
	```cpp
	    vector<int> dp(high + 1, -1);
	```
	Initializes a DP array to store intermediate results, reducing redundant calculations.

6. **Variable Initialization**
	```cpp
	    int ans = 0;
	```
	Initializes a variable to store the cumulative count of good strings.

7. **Loop**
	```cpp
	    for(int i = low; i <= high; i++) {
	```
	Iterates through each number in the given range.

8. **DP Calculation**
	```cpp
	        ans = (ans + score(i, dp, zero, one)) % mod;
	```
	Updates the result using the `score` function while applying modulus to avoid overflow.

9. **Return Statement**
	```cpp
	    return ans;
	```
	Returns the total count of good strings.

10. **Recursive Function**
	```cpp
	int score(int target, vector<int> &dp, int zero, int one) {
	```
	Defines a helper function to recursively calculate the number of good strings for a target value.

11. **Base Case**
	```cpp
	    if(target == 0)      return 1;
	```
	Returns 1 if the target is 0, as an empty string is a valid good string.

12. **Base Case**
	```cpp
	    if(target < 1 )      return 0;
	```
	Returns 0 if the target is negative, as it is not valid.

13. **Memoization Check**
	```cpp
	    if(dp[target] != -1) return dp[target];
	```
	Checks if the value for the current target is already computed to avoid redundant calculations.

14. **Recursive Calculation**
	```cpp
	    long long sum = score(target - zero, dp, zero, one) + score(target - one, dp, zero, one);
	```
	Recursively calculates the sum of ways to achieve the target using `zero` and `one` steps.

15. **Memoization Store**
	```cpp
	    return dp[target] = sum % mod;
	```
	Stores the computed result for the current target in the DP array and returns it.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n) where n is the difference between high and low.
- **Average Case:** O(n)
- **Worst Case:** O(n)

The solution computes the number of ways to form strings for each length in the range between low and high.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) because of the dynamic programming array used to store intermediate results.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/count-ways-to-build-good-strings/description/)

---
{{< youtube t0QkjXhE02g >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

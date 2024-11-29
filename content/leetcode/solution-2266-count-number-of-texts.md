
+++
authors = ["grid47"]
title = "Leetcode 2266: Count Number of Texts"
date = "2024-03-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2266: Count Number of Texts in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Math","String","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "LdM0WLfhF_4"
youtube_upload_date="2022-05-08"
youtube_thumbnail="https://i.ytimg.com/vi/LdM0WLfhF_4/maxresdefault.jpg"
comments = true
+++



---
Alice is texting Bob using her phone's keypad. Each digit from '2' to '9' maps to multiple letters, and Alice has to press a key several times to type each letter. However, due to a transmission error, Bob receives a string of digits corresponding to the number of key presses rather than the message itself. Your task is to determine how many possible messages Alice could have sent, given the sequence of digits Bob received. The answer should be returned modulo 1e9 + 7.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a string `pressedKeys`, which contains digits from '2' to '9' representing the sequence of key presses Bob received.
- **Example:** `pressedKeys = '33322'`
- **Constraints:**
	- 1 <= pressedKeys.length <= 10^5
	- pressedKeys only contains digits from '2' to '9'.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of possible messages that Alice could have sent, modulo 1e9 + 7.
- **Example:** `Output: 6`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** We need to determine the number of valid text messages that Alice could have sent based on the received sequence of key presses. The key insight is that consecutive identical digits represent the pressing of multiple letters corresponding to the digit's position on the keypad.

- Use dynamic programming to keep track of the number of possible ways to decode the sequence of key presses.
- For each digit, check how many ways the preceding sequence could be decoded given the number of times the current digit is pressed.
- If multiple consecutive digits are the same, consider all possible letter combinations that could have been typed using those key presses.
{{< dots >}}
### Problem Assumptions ✅
- The input string will only contain digits from '2' to '9'.
- The number of possible messages must be computed modulo 1e9 + 7.
{{< dots >}}
## Examples 🧩
- **Input:** `pressedKeys = '33322'`  \
  **Explanation:** The possible text messages Alice could have sent are: 'caa', 'cab', 'cbc', 'dda', 'ddb', 'dbc'. So the result is 6.

- **Input:** `pressedKeys = '555555'`  \
  **Explanation:** The possible text messages Alice could have sent are: 'kk', 'kl', 'lm', 'ln'. So the result is 4.

{{< dots >}}
## Approach 🚀
We can use dynamic programming to solve this problem efficiently. We define a dp array where dp[i] represents the number of possible messages for the substring of the first i characters of pressedKeys.

### Initial Thoughts 💭
- The problem can be broken down into considering how many possible combinations we can generate from consecutive key presses of the same digit.
- By using dynamic programming, we can avoid recalculating subproblems multiple times and efficiently solve the problem in linear time.
{{< dots >}}
### Edge Cases 🌐
- There will always be at least one digit in pressedKeys.
- The solution must be optimized to handle inputs of size up to 10^5 efficiently.
- Consider edge cases where digits repeat many times, such as '2222' or '7777777'.
- The solution must work within the constraints and return the result modulo 1e9 + 7.
{{< dots >}}
## Code 💻
```cpp
class Solution {
int mod = 1e9 + 7;
public:
int countTexts(string s) {
    int n = s.size();
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for(int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] % mod;
        if(i > 1 && s[i - 1] == s[i - 2]) {
            dp[i] = (dp[i] + dp[i - 2]) % mod;
            if(i > 2 && s[i - 1] == s[i - 3]) {
                dp[i] = (dp[i] + dp[i - 3]) % mod;
                if(i > 3 && (s[i-1]=='7' || s[i-1]=='9') && s[i - 1] == s[i - 4]) {
                    dp[i] = (dp[i] + dp[i - 4]) % mod;                        
                }
            }
        }
    }

    return dp[n];
}
```

This is the solution for counting the number of ways to form valid text messages by pressing keys on a mobile keypad. The function uses dynamic programming to track all possible ways to generate sequences for the given string input.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Class Declaration**
	```cpp
	class Solution {
	```
	Defines a class called `Solution` that contains the solution to the problem.

2. **Variable Initialization**
	```cpp
	int mod = 1e9 + 7;
	```
	Initializes a constant `mod` to the value 10^9 + 7, which will be used to avoid overflow by taking the result modulo this value.

3. **Access Modifier**
	```cpp
	public:
	```
	Specifies the access level for the subsequent members, indicating that they are publicly accessible.

4. **Function Declaration**
	```cpp
	int countTexts(string s) {
	```
	Defines the function `countTexts` which takes a string `s` as input and returns an integer representing the number of ways the string can be formed based on keypress patterns.

5. **Variable Declaration**
	```cpp
	    int n = s.size();
	```
	Calculates the size of the string `s` and stores it in the variable `n`.

6. **Dynamic Programming Initialization**
	```cpp
	    vector<int> dp(n + 1, 0);
	```
	Initializes a dynamic programming array `dp` of size `n+1` to store the number of valid ways to form sequences up to each position in the string.

7. **Base Case Initialization**
	```cpp
	    dp[0] = 1;
	```
	Sets the base case of the dynamic programming array, as there is one way to form an empty string.

8. **Loop Start**
	```cpp
	    for(int i = 1; i <= n; i++) {
	```
	Begins a loop over the string from index 1 to `n` to calculate the number of ways to form valid sequences.

9. **Dynamic Programming Transition**
	```cpp
	        dp[i] = dp[i - 1] % mod;
	```
	At each step, updates the number of ways to form a valid sequence by considering the previous value and applying modulo `mod` to prevent overflow.

10. **Condition Check for Adjacent Characters**
	```cpp
	        if(i > 1 && s[i - 1] == s[i - 2]) {
	```
	Checks if the current character is the same as the previous one, which allows for additional ways to form sequences.

11. **Dynamic Programming Transition for Two Consecutive Characters**
	```cpp
	            dp[i] = (dp[i] + dp[i - 2]) % mod;
	```
	If the last two characters are the same, adds the number of ways to form sequences considering the previous two characters.

12. **Condition Check for Three Consecutive Characters**
	```cpp
	            if(i > 2 && s[i - 1] == s[i - 3]) {
	```
	Checks if the current character is the same as the character two positions back, allowing for additional sequence combinations.

13. **Dynamic Programming Transition for Three Consecutive Characters**
	```cpp
	                dp[i] = (dp[i] + dp[i - 3]) % mod;
	```
	If the last three characters are the same, updates the sequence count by adding the possibilities from the previous three characters.

14. **Condition Check for Special Case with '7' or '9'**
	```cpp
	                if(i > 3 && (s[i-1]=='7' || s[i-1]=='9') && s[i - 1] == s[i - 4]) {
	```
	Checks for a special case where the current character is either '7' or '9' and the same as the fourth character back, enabling further sequence combinations.

15. **Dynamic Programming Transition for Four Consecutive Characters**
	```cpp
	                    dp[i] = (dp[i] + dp[i - 4]) % mod;                        
	```
	Adds the number of ways to form sequences considering the last four characters if they meet the special conditions.

16. **Return Statement**
	```cpp
	    return dp[n];
	```
	Returns the final result, which is the number of valid sequences for the entire input string `s`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) since we process each character of the input string once.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the dp array used to store the number of possible messages for each substring.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/count-number-of-texts/description/)

---
{{< youtube LdM0WLfhF_4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

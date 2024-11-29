
+++
authors = ["grid47"]
title = "Leetcode 91: Decode Ways"
date = "2024-10-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 91: Decode Ways in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/91.webp"
youtube = "6aEyTjOwlJU"
youtube_upload_date="2021-07-08"
youtube_thumbnail="https://i.ytimg.com/vi/6aEyTjOwlJU/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/91.webp" 
    alt="A glowing key unlocking multiple pathways, symbolizing decoding and transformation."
    caption="Solution to LeetCode 91: Decode Ways Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You have intercepted a string of numbers that encodes a message. The message is decoded using the following mapping:

"1" -> 'A',
"2" -> 'B',
...
"26" -> 'Z'.

However, there are multiple ways to decode the string, as some numbers can represent a single letter (e.g., '1' for 'A', '12' for 'L'). Your task is to return the number of possible ways to decode the string. Note that strings containing invalid encodings (e.g., starting with zero or having codes larger than 26) should not be considered valid.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a string s consisting only of digits, representing the encoded message.
- **Example:** `Input: s = "1234"`
- **Constraints:**
	- 1 <= s.length <= 100
	- s contains only digits

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is an integer, representing the number of valid ways to decode the string.
- **Example:** `Output: 3`
- **Constraints:**
	- The output should fit within a 32-bit integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to count the number of ways the string can be decoded, by considering all possible valid groupings of numbers into letters and ensuring no invalid decodings (such as those starting with 0).

- Check if the first character is '0', which would make the string invalid.
- Use dynamic programming or memoization to store the number of ways to decode the string from each position.
- At each step, consider both single-digit and two-digit numbers (if valid), and recursively calculate the number of decodings for the remaining substring.
{{< dots >}}
### Problem Assumptions ✅
- The input string is guaranteed to be non-empty and contain only digits.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: s = "1234"`  \
  **Explanation:** "1234" can be decoded in three ways: as 'ABCD' (1 2 3 4), 'LCD' (12 3 4), or 'AWD' (1 23 4).

- **Input:** `Input: s = "226"`  \
  **Explanation:** "226" can be decoded as: 'BBF' (2 2 6), 'VF' (22 6), or 'BZ' (2 26).

- **Input:** `Input: s = "06"`  \
  **Explanation:** "06" cannot be decoded because '06' is not a valid encoding, so the output is 0.

{{< dots >}}
## Approach 🚀
We can solve this problem using dynamic programming. We will keep track of the number of ways to decode the string up to each position, considering both single-digit and two-digit numbers where valid.

### Initial Thoughts 💭
- This problem can be solved using dynamic programming or memoization to store intermediate results and avoid recalculating the same subproblems.
- The key observation is that valid encodings are formed by single digits ('1' to '9') and valid two-digit combinations ('10' to '26').
- The presence of '0' as a standalone digit or paired with another number (e.g., '10') requires careful handling to avoid invalid decodings.
{{< dots >}}
### Edge Cases 🌐
- An empty input string should return 0, as there are no ways to decode an empty string.
- For large input strings, the solution should still be efficient and handle up to 100 characters.
- Strings that start with '0' or contain invalid two-digit combinations (e.g., '30', '40') should return 0.
- Ensure that the solution works within the given constraint of a string length of up to 100 characters.
{{< dots >}}
## Code 💻
```cpp
int numDecodings(string s) {
    if (s.empty() || s[0] == '0') return 0;
    vector<int> dp(s.size() + 1, 0);
    dp[0] = 1;
    dp[1] = s[0] == '0' ? 0 : 1;
    for (int i = 2; i <= s.size(); i++) {
        int one_digit = stoi(s.substr(i - 1, 1));
        int two_digit = stoi(s.substr(i - 2, 2));
        if (one_digit >= 1) {
            dp[i] += dp[i - 1];
        }
        if (two_digit >= 10 && two_digit <= 26) {
            dp[i] += dp[i - 2];
        }
    }
    return dp[s.size()];
}
```

This code calculates the number of ways to decode a string of digits into letters.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int numDecodings(string s) {
	```
	Declares a function `numDecodings` that takes a string `s` of digits as input and returns the number of ways to decode it.

2. **Edge Case Check**
	```cpp
	    if (s.empty() || s[0] == '0') return 0;
	```
	Checks for edge cases: if the string is empty or starts with '0', there are no valid decodings.

3. **Array Initialization**
	```cpp
	    vector<int> dp(s.size() + 1, 0);
	```
	Initializes a dynamic programming array `dp` of size `s.size() + 1` to store the number of decodings for substrings ending at each index.

4. **Base Case Initialization**
	```cpp
	    dp[0] = 1;
	```
	Sets the base case: there is one way to decode an empty string.

5. **Base Case Initialization**
	```cpp
	    dp[1] = s[0] == '0' ? 0 : 1;
	```
	Sets the base case for the first character: if it's '0', there are no decodings; otherwise, there's one.

6. **Loop Iteration**
	```cpp
	    for (int i = 2; i <= s.size(); i++) {
	```
	Iterates through the string, starting from the second character.

7. **Substring Extraction, String to Integer Conversion**
	```cpp
	        int one_digit = stoi(s.substr(i - 1, 1));
	```
	Extracts the current digit and converts it to an integer.

8. **Substring Extraction, String to Integer Conversion**
	```cpp
	        int two_digit = stoi(s.substr(i - 2, 2));
	```
	Extracts the two-digit number formed by the current and previous digits and converts it to an integer.

9. **Conditional Update**
	```cpp
	        if (one_digit >= 1) {
	            dp[i] += dp[i - 1];
	        }
	```
	If the current digit is valid (1-9), adds the number of decodings for the substring ending at the previous index to the current `dp[i]`. This corresponds to decoding the current digit as a single-digit letter.

10. **Conditional Update**
	```cpp
	        if (two_digit >= 10 && two_digit <= 26) {
	            dp[i] += dp[i - 2];
	        }
	```
	If the two-digit number is valid (10-26), adds the number of decodings for the substring ending at the index two positions before to the current `dp[i]`. This corresponds to decoding the current two digits as a single letter.

11. **Return**
	```cpp
	    return dp[s.size()];
	```
	Returns the final value in the `dp` array, which represents the total number of decodings for the entire string.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the length of the input string.
- **Average Case:** O(n)
- **Worst Case:** O(n), since we only need to process each character of the string once.

The time complexity is linear because each character is processed once.

### Space Complexity 💾
- **Best Case:** O(1), if no storage is required.
- **Worst Case:** O(n), where n is the length of the input string, for storing the dynamic programming or memoization array.

The space complexity is linear due to the storage requirements for the dynamic programming array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/decode-ways/description/)

---
{{< youtube 6aEyTjOwlJU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

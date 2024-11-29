
+++
authors = ["grid47"]
title = "Leetcode 1513: Number of Substrings With Only 1s"
date = "2024-06-08"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1513: Number of Substrings With Only 1s in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "9cPoRqw5I_8"
youtube_upload_date="2020-07-12"
youtube_thumbnail="https://i.ytimg.com/vi/9cPoRqw5I_8/maxresdefault.jpg"
comments = true
+++



---
Given a binary string s, return the number of substrings that consist entirely of '1's. Since the result can be large, return the answer modulo (10^9 + 7).
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a binary string s, where each character is either '0' or '1'.
- **Example:** `s = "1010101"`
- **Constraints:**
	- 1 <= s.length <= 10^5
	- s[i] is either '0' or '1'.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of substrings that contain only '1's modulo (10^9 + 7).
- **Example:** `9`
- **Constraints:**
	- Return the result modulo (10^9 + 7).

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to calculate the total number of substrings consisting only of '1's. This can be done by grouping consecutive '1's together and applying the formula for the number of substrings from a sequence of length n: ( rac{n(n+1)}{2} ).

- Step 1: Traverse the string to find groups of consecutive '1's.
- Step 2: For each group of consecutive '1's, calculate the number of substrings using the formula ( rac{n(n+1)}{2} ), where n is the length of the group.
- Step 3: Sum all the values from step 2 and take the result modulo (10^9 + 7).
{{< dots >}}
### Problem Assumptions ✅
- The string contains at least one character.
- The string is composed only of '0' and '1'.
{{< dots >}}
## Examples 🧩
- **Input:** `s = "1010101"`  \
  **Explanation:** In this case, we can see that there are multiple occurrences of '1'. The valid substrings consist of individual '1's, pairs of '1's, and triplets of '1's, totaling 9 valid substrings.

- **Input:** `s = "0001"`  \
  **Explanation:** Only one substring consisting of '1' exists, so the output is 1.

{{< dots >}}
## Approach 🚀
The problem can be solved by iterating through the string and counting the number of consecutive '1's. For each group of '1's, we calculate the number of valid substrings using the formula ( rac{n(n+1)}{2} ).

### Initial Thoughts 💭
- The string can have multiple groups of consecutive '1's.
- We need to iterate through the string and calculate the number of substrings for each group of '1's.
{{< dots >}}
### Edge Cases 🌐
- There is no need to handle empty inputs as the problem guarantees at least one character.
- Ensure that the solution efficiently handles strings with lengths up to 100,000 characters.
- Handle cases where the string consists only of '0's or only of '1's.
- The algorithm must run in O(n) time to handle large inputs efficiently.
{{< dots >}}
## Code 💻
```cpp
int numSub(string s) {
    long cnt = 0, mod = (int) 1e9 + 7;

    long tmp = 0, n = s.size();
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') {
            tmp++;
        }
        
        if(s[i] == '0' || i == n - 1) {
            cnt = (cnt + tmp * (tmp + 1) / 2) % mod;
            tmp = 0;
        }
        
    }
    return cnt;
}
```

This code defines the `numSub` function that calculates the number of substrings containing only the character '1' in a binary string `s`. The result is returned modulo `1e9 + 7`. The function iterates through the string, counting consecutive '1's and computing the sum of valid substrings based on this count.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int numSub(string s) {
	```
	Defines the `numSub` function that takes a string `s` as input and calculates the number of substrings containing only '1' using a mathematical approach.

2. **Variable Initialization**
	```cpp
	    long cnt = 0, mod = (int) 1e9 + 7;
	```
	Initializes `cnt` to 0, which will store the total number of valid substrings, and `mod` with the value (10^9 + 7) to take the result modulo this value.

3. **Variable Initialization**
	```cpp
	    long tmp = 0, n = s.size();
	```
	Initializes `tmp` to 0, which will be used to count consecutive '1's, and `n` to the size of the string `s`.

4. **Loop Start**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Starts a loop that iterates through each character in the string `s`.

5. **Condition Check**
	```cpp
	        if(s[i] == '1') {
	```
	Checks if the current character is '1'. If true, it increments the counter for consecutive '1's.

6. **Increment Counter**
	```cpp
	            tmp++;
	```
	Increments the `tmp` variable, which keeps track of the number of consecutive '1's.

7. **Condition Check**
	```cpp
	        if(s[i] == '0' || i == n - 1) {
	```
	Checks if the current character is '0' or if the loop has reached the last character in the string. This condition handles the end of a sequence of '1's or the end of the string.

8. **Calculate Valid Substrings**
	```cpp
	            cnt = (cnt + tmp * (tmp + 1) / 2) % mod;
	```
	Calculates the number of valid substrings from the current sequence of consecutive '1's. This is done by adding the sum of the first `tmp` natural numbers, i.e., ( rac{tmp 	imes (tmp + 1)}{2} ), to `cnt`, and takes the result modulo `mod`.

9. **Reset Temporary Counter**
	```cpp
	            tmp = 0;
	```
	Resets the `tmp` counter to 0, as the sequence of consecutive '1's has ended.

10. **Return Result**
	```cpp
	    return cnt;
	```
	Returns the total count of valid substrings stored in `cnt`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) since we are iterating through the string once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) because we only need a constant amount of space to store intermediate variables.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-substrings-with-only-1s/description/)

---
{{< youtube 9cPoRqw5I_8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

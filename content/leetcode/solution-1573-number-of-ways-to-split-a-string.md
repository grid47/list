
+++
authors = ["grid47"]
title = "Leetcode 1573: Number of Ways to Split a String"
date = "2024-06-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1573: Number of Ways to Split a String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "DVcHb_poT6E"
youtube_upload_date="2020-09-05"
youtube_thumbnail="https://i.ytimg.com/vi/DVcHb_poT6E/maxresdefault.jpg"
comments = true
+++



---
Given a binary string, you need to split it into three non-empty parts such that each part contains the same number of '1's. You must return the total number of ways to split the string, with the result modulo 10^9 + 7.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a binary string, meaning it contains only '0's and '1's.
- **Example:** `Input: s = "110101"`
- **Constraints:**
	- 3 <= s.length <= 10^5
	- Each character in s is either '0' or '1'.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be the number of ways to split the binary string into three parts where each part has the same number of '1's. The result should be returned modulo 10^9 + 7.
- **Example:** `Output: 3`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to count how many ways we can split the string into three parts such that each part has the same number of '1's.

- First, count the total number of '1's in the string.
- If the total number of '1's is not divisible by 3, return 0 since it's not possible to split them evenly.
- Divide the total number of '1's by 3 to find the number of '1's each part should contain.
- Track the possible positions where the first and second cuts can be made to split the string into three parts with an equal number of '1's.
{{< dots >}}
### Problem Assumptions ✅
- The string is guaranteed to contain only '0's and '1's.
- The total number of '1's in the string is divisible by 3 for a valid split.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: s = "110101"`  \
  **Explanation:** The string has 4 '1's, so each part must have 4 / 3 = 1 '1'. The valid splits are: "1|1|01", "1|10|1", and "11|0|1".

- **Input:** `Example 2: s = "1001"`  \
  **Explanation:** The string has 2 '1's, which is not divisible by 3, so there are no valid ways to split the string.

- **Input:** `Example 3: s = "0000"`  \
  **Explanation:** The string has 0 '1's, so any valid split would be a valid solution, and the number of splits is 3.

{{< dots >}}
## Approach 🚀
The problem involves counting how many ways we can split the string into three parts such that each part contains the same number of '1's. We first calculate the total number of '1's, check if it is divisible by 3, and then find positions to make the cuts.

### Initial Thoughts 💭
- The total number of '1's must be divisible by 3 for an equal split.
- We can use the positions of '1's to count the valid splits.
- By counting the number of '1's and tracking the positions where each cut can occur, we can efficiently calculate the number of valid splits.
{{< dots >}}
### Edge Cases 🌐
- The string will always have at least 3 characters.
- The algorithm should efficiently handle strings with lengths up to 10^5.
- Strings with all '0's have multiple valid splits.
- Ensure that the solution handles the maximum input size efficiently.
{{< dots >}}
## Code 💻
```cpp
int numWays(string s) {
    
    long n = s.size();
    int one = 0;
    for(char x: s)
        one += (x == '0')? 0: 1;
    
    int mod = (int) 1e9 + 7;
    
    if(one == 0) return (int)((n - 2) * (n - 1) / 2 % mod);
    
        
    if(one % 3 != 0) return 0;
    
    long long waysOfFirstCut = 0, waysOfSecondCut = 0;
    int net = one / 3, tmp = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') tmp++;
        if(tmp == net) waysOfFirstCut++;
        else if(tmp == 2 * net) waysOfSecondCut++;
    }
    
    return (int)(waysOfFirstCut *waysOfSecondCut % mod) ;
}
```

This function calculates the number of ways to divide a binary string into three parts with equal numbers of '1's. It returns the result modulo 1e9 + 7.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int numWays(string s) {
	```
	Defines the function `numWays` which takes a string `s` as input and returns an integer representing the number of ways to divide the string into three parts with equal '1's.

2. **Size Calculation**
	```cpp
	    long n = s.size();
	```
	Calculates the size of the string `s` and stores it in `n`.

3. **Count '1's**
	```cpp
	    int one = 0;
	```
	Initializes a counter variable `one` to count the number of '1's in the string `s`.

4. **Loop Through String**
	```cpp
	    for(char x: s)
	```
	Starts a loop to iterate through each character `x` in the string `s`.

5. **Count '1's in String**
	```cpp
	        one += (x == '0')? 0: 1;
	```
	Increments the counter `one` for each '1' encountered in the string `s`.

6. **Modulo Definition**
	```cpp
	    int mod = (int) 1e9 + 7;
	```
	Defines the modulus value `mod` as 1e9 + 7 to avoid overflow and ensure the result fits within the limits.

7. **Edge Case for Zero '1's**
	```cpp
	    if(one == 0) return (int)((n - 2) * (n - 1) / 2 % mod);
	```
	Handles the edge case where there are no '1's in the string. In this case, the number of ways to divide the string into three equal parts is calculated using the formula (n-2)*(n-1)/2.

8. **Check for Divisibility by 3**
	```cpp
	    if(one % 3 != 0) return 0;
	```
	Checks if the total number of '1's is divisible by 3. If not, it's impossible to divide the string into three equal parts, so it returns 0.

9. **Cut Variables Initialization**
	```cpp
	    long long waysOfFirstCut = 0, waysOfSecondCut = 0;
	```
	Initializes two variables `waysOfFirstCut` and `waysOfSecondCut` to keep track of the possible positions for the first and second cuts.

10. **Net Calculation**
	```cpp
	    int net = one / 3, tmp = 0;
	```
	Calculates `net`, the number of '1's in each part of the string (one-third of the total number of '1's), and initializes `tmp` to count the '1's encountered while iterating through the string.

11. **Loop Through String Again**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Starts a loop to iterate through the string `s` again to find the positions where the cuts can be made.

12. **Count '1's During Iteration**
	```cpp
	        if(s[i] == '1') tmp++;
	```
	Increments the counter `tmp` whenever a '1' is encountered during the iteration.

13. **First Cut Count**
	```cpp
	        if(tmp == net) waysOfFirstCut++;
	```
	If the counter `tmp` reaches `net`, it means the first cut can be made, so `waysOfFirstCut` is incremented.

14. **Second Cut Count**
	```cpp
	        else if(tmp == 2 * net) waysOfSecondCut++;
	```
	If the counter `tmp` reaches `2 * net`, it means the second cut can be made, so `waysOfSecondCut` is incremented.

15. **Return Result**
	```cpp
	    return (int)(waysOfFirstCut * waysOfSecondCut % mod);
	```
	Calculates the total number of ways to divide the string into three equal parts by multiplying the number of ways to make the first and second cuts. The result is taken modulo `mod`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) due to the need to iterate over the string to count the '1's and find valid split positions.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) since only a few variables are used to track the counts and positions.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-ways-to-split-a-string/description/)

---
{{< youtube DVcHb_poT6E >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

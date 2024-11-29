
+++
authors = ["grid47"]
title = "Leetcode 2564: Substring XOR Queries"
date = "2024-02-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2564: Substring XOR Queries in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "0J1aVGfArWs"
youtube_upload_date="2023-02-12"
youtube_thumbnail="https://i.ytimg.com/vi_webp/0J1aVGfArWs/maxresdefault.webp"
comments = true
+++



---
You are given a binary string `s` and a 2D array of queries. Each query is represented as [firsti, secondi], where `firsti` and `secondi` are integers. For each query, you need to find the shortest substring of `s` whose decimal value XORed with `firsti` equals `secondi`.

In other words, find a substring whose decimal value, when XORed with `firsti`, results in `secondi`. If such a substring exists, return its starting and ending indices (0-indexed). If no such substring exists, return [-1, -1].

If there are multiple valid substrings, return the one with the smallest starting index.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a binary string `s` and a list of queries where each query consists of two integers `firsti` and `secondi`.
- **Example:** `s = '101101', queries = [[0,5], [1,2]]`
- **Constraints:**
	- 1 <= s.length <= 10^4
	- 1 <= queries.length <= 10^5
	- 0 <= firsti, secondi <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** For each query, return the starting and ending indices of the shortest valid substring or [-1, -1] if no valid substring exists.
- **Example:** `Output: [[0,2], [2,3]]`
- **Constraints:**
	- The output should be a list of pairs of integers where each pair corresponds to the indices of the valid substring or [-1, -1] if no valid substring is found.

{{< dots >}}
### Core Logic 🔍
**Goal:** To efficiently find the shortest valid substring for each query.

- Convert the binary string into decimal values of substrings.
- For each query, calculate the XOR of `firsti` and `secondi` to get the target value.
- Check if the target value can be found as a decimal value of a substring of `s`.
- Return the indices of the substring if it exists, otherwise return [-1, -1].
{{< dots >}}
### Problem Assumptions ✅
- The input binary string is valid and consists only of '0' and '1'.
- The queries array contains valid integer pairs within the specified range.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1:`  \
  **Explanation:** Given the string s = '101101' and queries = [[0,5], [1,2]], we can find the following substrings: 

For the first query, the substring '101' (indices 0 to 2) has a decimal value of 5, and 5 XOR 0 equals 5, so the answer is [0, 2].
For the second query, the substring '11' (indices 2 to 3) has a decimal value of 3, and 3 XOR 1 equals 2, so the answer is [2, 3].

- **Input:** `Example 2:`  \
  **Explanation:** Given the string s = '0101' and queries = [[12,8]], there is no substring whose decimal value XORed with 12 equals 8, so the answer is [-1, -1].

- **Input:** `Example 3:`  \
  **Explanation:** Given the string s = '1' and queries = [[4,5]], the substring '1' (indices 0 to 0) has a decimal value of 1, and 1 XOR 4 equals 5, so the answer is [0, 0].

{{< dots >}}
## Approach 🚀
The approach to solving this problem involves finding all possible substrings of the binary string and checking their decimal values. For each query, we can calculate the target XOR value and search for the substring whose decimal value matches the target.

### Initial Thoughts 💭
- The XOR operation is reversible, so for each query, we can calculate the target value by XORing the two integers.
- We need to efficiently search for substrings whose decimal values match the target.
- Precomputing all possible substrings and storing their decimal values can speed up the search for each query.
{{< dots >}}
### Edge Cases 🌐
- If the binary string is empty, the answer should be [-1, -1] for all queries.
- Ensure that the solution works efficiently even with large input sizes, such as strings of length up to 10^4 and up to 10^5 queries.
- Handle edge cases where the binary string contains only '0's or '1's.
- The solution should handle queries efficiently by leveraging preprocessing and fast search techniques.
{{< dots >}}
## Code 💻
```cpp

string str(int n) {
    string ans = "";
    if(n == 0) return "0";
    while(n) {
        if(n & 1) {
            ans = "1" + ans;
        } else {
            ans = "0" + ans;
        }
        n >>= 1;
    }
    return ans;
}

vector<int> substr(string m, string s) {
    if(m.size() < s.size()) return vector<int>{-1, -1};
    for(int i = 0; i < m.size(); i++) {
        int j = 0;
        while(j < s.size() && i + j < m.size() && m[i + j] == s[j]) j++;
        if(j == s.size()) return vector<int>{i, i + j - 1};
    }
    return vector<int>{-1, -1};
}

vector<vector<int>> substringXorQueries(string m, vector<vector<int>>& q) {
    int n = q.size();

    map<int, vector<int>> mp;
    int k = m.size();
    for(int j = 0; j < k; j++) {
        if(m[j] == '0') {
            if(!mp.count(0)) mp[0] = {j, j};
            continue;
        }
        int num = 0;
        for(int i = j; i <= min(j + 31, k - 1); i++) {
            num = (num << 1) + (m[i] - '0');
            if(!mp.count(num)) mp[num] = {j, i};
        }
    }
    vector<vector<int>> ans(n, vector<int>{-1, -1});
    for(int i = 0; i < n; i++) {
        int num = (q[i][0] ^ q[i][1]);
        if(mp.count(num))
        ans[i] = mp[num];
    }        
    return ans;
}
```

This is the complete implementation for solving the problem. The code contains functions for converting a number to a binary string, searching for substrings, and solving XOR queries on substrings.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	string str(int n) {
	```
	Function to convert an integer to its binary string representation.

2. **Variable Initialization**
	```cpp
	    string ans = "";
	```
	Initializes an empty string to hold the binary result.

3. **Edge Case Handling**
	```cpp
	    if(n == 0) return "0";
	```
	Handles the special case where the input number is zero by returning "0".

4. **Looping and Bitwise Operation**
	```cpp
	    while(n) {
	```
	Iterates while n is not zero.

5. **Conditional Statement**
	```cpp
	        if(n & 1) {
	```
	Checks if the least significant bit of n is 1.

6. **String Manipulation**
	```cpp
	            ans = "1" + ans;
	```
	Adds '1' to the beginning of the binary result string.

7. **Else Condition**
	```cpp
	        } else {
	```
	If the least significant bit is 0.

8. **String Manipulation**
	```cpp
	            ans = "0" + ans;
	```
	Adds '0' to the beginning of the binary result string.

9. **Bitwise Operation**
	```cpp
	        n >>= 1;
	```
	Right shifts n by 1 bit to process the next bit.

10. **Return Statement**
	```cpp
	    return ans;
	```
	Returns the final binary string.

11. **Function Definition**
	```cpp
	vector<int> substr(string m, string s) {
	```
	Function to find the substring s in string m and return its indices.

12. **Edge Case Handling**
	```cpp
	    if(m.size() < s.size()) return vector<int>{-1, -1};
	```
	Handles the case where s is longer than m.

13. **Looping**
	```cpp
	    for(int i = 0; i < m.size(); i++) {
	```
	Loops through string m to search for substring s.

14. **Variable Initialization**
	```cpp
	        int j = 0;
	```
	Initializes a counter for matching characters.

15. **Nested Loop**
	```cpp
	        while(j < s.size() && i + j < m.size() && m[i + j] == s[j]) j++;
	```
	Checks if substring s matches a portion of m starting at index i.

16. **Conditional Statement**
	```cpp
	        if(j == s.size()) return vector<int>{i, i + j - 1};
	```
	If the full substring s is found, return its indices.

17. **Return Statement**
	```cpp
	    return vector<int>{-1, -1};
	```
	If the substring is not found, return [-1, -1].

18. **Function Definition**
	```cpp
	vector<vector<int>> substringXorQueries(string m, vector<vector<int>>& q) {
	```
	Function to solve multiple XOR substring queries on string m.

19. **Variable Initialization**
	```cpp
	    int n = q.size();
	```
	Initializes the number of queries.

20. **Map Initialization**
	```cpp
	    map<int, vector<int>> mp;
	```
	Creates a map to store results of XOR computations.

21. **Variable Initialization**
	```cpp
	    int k = m.size();
	```
	Initializes the size of string m.

22. **Looping**
	```cpp
	    for(int j = 0; j < k; j++) {
	```
	Loops through each character in string m.

23. **Conditional Statement**
	```cpp
	        if(m[j] == '0') {
	```
	Checks if the character in m is '0'.

24. **Map Insertion**
	```cpp
	            if(!mp.count(0)) mp[0] = {j, j};
	```
	Adds a mapping for the value '0'.

25. **Continue Statement**
	```cpp
	            continue;
	```
	Continues to the next iteration if the character is '0'.

26. **Variable Initialization**
	```cpp
	        int num = 0;
	```
	Initializes a variable to hold the current number.

27. **Nested Loop**
	```cpp
	        for(int i = j; i <= min(j + 31, k - 1); i++) {
	```
	Loops through the next 32 bits or until the end of string m.

28. **Bitwise Operation**
	```cpp
	            num = (num << 1) + (m[i] - '0');
	```
	Constructs the number by shifting bits and adding the current bit.

29. **Map Insertion**
	```cpp
	            if(!mp.count(num)) mp[num] = {j, i};
	```
	Inserts the current number and its corresponding range into the map.

30. **Return Statement**
	```cpp
	    vector<vector<int>> ans(n, vector<int>{-1, -1});
	```
	Initializes a result vector with default [-1, -1] values.

31. **Looping**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Iterates over all queries.

32. **Bitwise Operation**
	```cpp
	        int num = (q[i][0] ^ q[i][1]);
	```
	Computes the XOR of the two query values.

33. **Map Lookup**
	```cpp
	        if(mp.count(num))
	```
	Checks if the XOR result is present in the map.

34. **Return Statement**
	```cpp
	            ans[i] = mp[num];
	```
	If found, updates the answer with the corresponding range.

35. **Return Statement**
	```cpp
	    return ans;
	```
	Returns the final answer for all queries.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n^2)

The time complexity depends on preprocessing the binary string and the number of queries. The worst case occurs when checking all possible substrings for each query.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n^2)

The space complexity is determined by the need to store all possible substrings and their decimal values.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/substring-xor-queries/description/)

---
{{< youtube 0J1aVGfArWs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

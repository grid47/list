
+++
authors = ["grid47"]
title = "Leetcode 2800: Shortest String That Contains Three Strings"
date = "2024-02-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2800: Shortest String That Contains Three Strings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Greedy","Enumeration"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "920NY6GKUEk"
youtube_upload_date="2023-07-30"
youtube_thumbnail="https://i.ytimg.com/vi_webp/920NY6GKUEk/maxresdefault.webp"
comments = true
+++



---
Given three strings 'a', 'b', and 'c', find a string that contains all three of these strings as substrings and has the minimum possible length. If there are multiple such strings, return the lexicographically smallest one.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given three strings, 'a', 'b', and 'c'. Each string consists of lowercase English letters.
- **Example:** `Input: a = 'apple', b = 'banana', c = 'orange'`
- **Constraints:**
	- 1 <= a.length, b.length, c.length <= 100
	- a, b, c consist only of lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a string that contains all three strings 'a', 'b', and 'c' as substrings and has the minimum length. If there are multiple valid answers, return the lexicographically smallest one.
- **Example:** `Output: 'bananaorange'`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the shortest string that contains all three given strings as substrings.

- 1. Identify the possible overlapping parts of the strings to minimize the total length.
- 2. Try all permutations of the strings to find the lexicographically smallest solution.
- 3. Combine the strings efficiently using the overlap method and return the result.
{{< dots >}}
### Problem Assumptions ✅
- The input strings are non-empty and consist only of lowercase English letters.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: a = 'apple', b = 'banana', c = 'orange'`  \
  **Explanation:** The lexicographically smallest string that contains all three strings as substrings is 'bananaorange'.

- **Input:** `Input: a = 'cat', b = 'bat', c = 'rat'`  \
  **Explanation:** The shortest and lexicographically smallest string that contains all three strings as substrings is 'catbat'.

{{< dots >}}
## Approach 🚀
The problem can be solved by finding the minimal overlap between each pair of strings and combining them efficiently.

### Initial Thoughts 💭
- Finding the minimal overlap between strings will allow us to reduce the length of the combined string.
- We need to explore permutations of the three strings to ensure we get the lexicographically smallest result.
{{< dots >}}
### Edge Cases 🌐
- The input strings will never be empty based on the problem constraints.
- The algorithm should be optimized to handle strings up to 100 characters long.
- If all strings are identical, the output will be the same string.
- The solution must handle strings of length up to 100 efficiently.
{{< dots >}}
## Code 💻
```cpp

string mn(string a, string b) {
    return (a.size() < b.size() || (a.size() == b.size() && a < b))? a: b;
}

string attach(string a, string b) {
    if(a.find(b) != string::npos) return a;
    for(int i = 0; i < a.size(); i++) {
        string t1 = a.substr(i), t2 = b.substr(0, t1.size());
        if(t1 == t2) return a + b.substr(t1.size());
    }
    return a + b;
}

string solve(string a, string b, string c) {
    string t1 = attach(a, b);
    string t2 = attach(b, a);
    
    string ret1 = attach(t1, c);
    string ret2 = attach(c, t1);
    string ret3 = attach(t2, c);
    string ret4 = attach(c, t2);        
    return mn(mn(ret1, ret2), mn(ret3, ret4));
}

string minimumString(string a, string b, string c) {
    return mn(mn(solve(a, b, c), solve(a, c, b)), solve(b, c, a));
}
```

This code defines several string manipulation functions, including `mn` for finding the lexicographically smaller string, `attach` to concatenate strings with specific matching conditions, and `solve` to combine strings in a minimum way. The function `minimumString` computes the smallest string by considering all possible combinations of input strings.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Initialization**
	```cpp
	
	```
	This section initializes the necessary functions that will be used to solve the problem.

2. **Define Mn Function**
	```cpp
	string mn(string a, string b) {
	```
	The `mn` function returns the lexicographically smaller of two strings. It compares the sizes of the strings and, if they are equal, compares them lexicographically.

3. **Mn Comparison Logic**
	```cpp
	    return (a.size() < b.size() || (a.size() == b.size() && a < b))? a: b;
	```
	This line performs the comparison between the two strings `a` and `b`. It first checks their lengths and, if they are equal, it checks which string is lexicographically smaller.

4. **Define Attach Function**
	```cpp
	string attach(string a, string b) {
	```
	The `attach` function concatenates two strings, ensuring that no duplicate parts are added if they already match.

5. **Attach Function Logic**
	```cpp
	    if(a.find(b) != string::npos) return a;
	```
	If string `b` is already a part of string `a`, the function directly returns `a` without modification.

6. **Attach Loop**
	```cpp
	    for(int i = 0; i < a.size(); i++) {
	```
	This loop checks the various substrings of `a` to find a match with the beginning of `b`.

7. **Attach Substring Check**
	```cpp
	        string t1 = a.substr(i), t2 = b.substr(0, t1.size());
	```
	For each substring of `a`, it compares it with the beginning part of `b`.

8. **Attach Match Found**
	```cpp
	        if(t1 == t2) return a + b.substr(t1.size());
	```
	If a matching substring is found, the function returns `a` with the remaining part of `b` concatenated to it.

9. **Attach Return**
	```cpp
	    return a + b;
	```
	If no matching substring was found, the function simply concatenates `a` and `b`.

10. **Define Solve Function**
	```cpp
	string solve(string a, string b, string c) {
	```
	The `solve` function takes three strings and combines them using the `attach` function to generate possible combinations.

11. **Solve Function Attachments**
	```cpp
	    string t1 = attach(a, b);
	```
	The first combination of `a` and `b` is created and stored in `t1`.

12. **Solve Function Reverse Attachment**
	```cpp
	    string t2 = attach(b, a);
	```
	The second combination of `b` and `a` is created and stored in `t2`.

13. **Solve Function Further Attachments**
	```cpp
	    string ret1 = attach(t1, c);
	```
	The result of combining `t1` with `c` is stored in `ret1`.

14. **Solve Function More Attachments**
	```cpp
	    string ret2 = attach(c, t1);
	```
	The result of combining `c` with `t1` is stored in `ret2`.

15. **Solve Function Attach Remaining**
	```cpp
	    string ret3 = attach(t2, c);
	```
	The result of combining `t2` with `c` is stored in `ret3`.

16. **Solve Function Final Attachment**
	```cpp
	    string ret4 = attach(c, t2);        
	```
	The result of combining `c` with `t2` is stored in `ret4`.

17. **Solve Function Return**
	```cpp
	    return mn(mn(ret1, ret2), mn(ret3, ret4));
	```
	The function returns the smallest of the four possible combinations using the `mn` function.

18. **Define MinimumString Function**
	```cpp
	string minimumString(string a, string b, string c) {
	```
	The `minimumString` function computes the minimum string formed by all possible combinations of the input strings `a`, `b`, and `c`.

19. **MinimumString Logic**
	```cpp
	    return mn(mn(solve(a, b, c), solve(a, c, b)), solve(b, c, a));
	```
	The function returns the smallest string from all the combinations generated by calling the `solve` function with different orderings of `a`, `b`, and `c`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n!)
- **Average Case:** O(n!)
- **Worst Case:** O(n!)

The time complexity is dominated by the permutations of the three strings (3! = 6 permutations). For each permutation, the overlap checking requires linear time, so the overall complexity is O(6n), which simplifies to O(n).

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) because we only store the intermediate results of string combinations.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/shortest-string-that-contains-three-strings/description/)

---
{{< youtube 920NY6GKUEk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

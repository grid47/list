
+++
authors = ["grid47"]
title = "Leetcode 1023: Camelcase Matching"
date = "2024-07-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1023: Camelcase Matching in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","String","Trie","String Matching"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "h9I_yFNeMgo"
youtube_upload_date="2024-07-02"
youtube_thumbnail="https://i.ytimg.com/vi_webp/h9I_yFNeMgo/maxresdefault.webp"
comments = true
+++



---
You are given a list of query strings and a pattern. A query string matches the pattern if you can insert lowercase English letters into the pattern such that it becomes the query string. Each character from the pattern must be placed in order without changing its relative positions, and you may not add any characters that are not in the pattern.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a list of query strings and a string pattern.
- **Example:** `queries = ["ABCdEF", "AbCdEFG", "ACE", "AcEfG", "AcdFEG"], pattern = "ACE"`
- **Constraints:**
	- 1 <= pattern.length, queries.length <= 100
	- 1 <= queries[i].length <= 100
	- queries[i] and pattern consist of English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is a boolean array where each element indicates whether the corresponding query string matches the pattern or not.
- **Example:** `Output: [true, true, true, false, false]`
- **Constraints:**
	- The output array must contain a boolean value for each query string.

{{< dots >}}
### Core Logic 🔍
**Goal:** We need to check if we can insert lowercase letters into the pattern in a way that the pattern becomes the query string. This can be done by scanning both the pattern and query string simultaneously and ensuring the pattern's characters appear in the same order in the query.

- 1. For each query, iterate through the characters of the query and the pattern simultaneously.
- 2. Check if each character in the query matches the corresponding character in the pattern, skipping over any lowercase characters in the query.
- 3. If all characters in the pattern are matched in order, return true for that query; otherwise, return false.
{{< dots >}}
### Problem Assumptions ✅
- The pattern and query strings consist only of uppercase and lowercase English letters.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: queries = ["ABCdEF", "AbCdEFG", "ACE", "AcEfG", "AcdFEG"], pattern = "ACE"`  \
  **Explanation:** In this case, 'ABCdEF' can be formed by inserting 'B' and 'D' into the pattern 'ACE', so the output is true. 'AbCdEF' can be formed by inserting 'b', 'C' and 'G', so the output is true. 'ACE' is already equal to the pattern, so the output is true. 'AcEfG' doesn't match the pattern because of extra characters in the middle, so the output is false. 'AcdFEG' doesn't match because of extra characters and incorrect ordering, so the output is false.

{{< dots >}}
## Approach 🚀
The approach is to use a two-pointer technique to check if the characters of the pattern appear in the correct order in each query string, allowing for lowercase characters to be inserted.

### Initial Thoughts 💭
- We can utilize two pointers, one for the pattern and one for the query string, to verify if the pattern characters appear in the correct order in the query.
- By iterating through the query string and matching characters from the pattern, we can determine if the pattern is a subsequence of the query.
{{< dots >}}
### Edge Cases 🌐
- If the query or pattern is empty, return false.
- If there are large numbers of queries or very long query strings, the algorithm should still perform efficiently.
- Handle cases where the query contains only lowercase letters or the pattern contains only uppercase letters.
- Ensure the solution handles edge cases, such as patterns and queries with special characters.
{{< dots >}}
## Code 💻
```cpp
vector<bool> camelMatch(vector<string>& queries, string pattern) {
    
    vector<bool> res;
    
    for(string q: queries) {
        
        bool ret = match(q, pattern);
        
        res.push_back(ret);
    }

    return res;
}

bool match(string q, string p) {
    
    int j = 0;
    
    for(int i = 0; i < q.size(); i++) {
        
        if(j < p.size()&&q[i] == p[j]) {
            j++;
            continue;
        }else if(q[i] >= 'A' && 
           q[i] <= 'Z')
            return false;               
           
    }
    
    return j == p.size();
    
}

```

This is the complete code that implements the camelCase string matching algorithm. It checks if each query matches the given pattern according to camel case rules. The `camelMatch` function iterates through each query, passing it to the `match` function, which determines whether the query matches the pattern. The code handles checking capital and lowercase characters and returns a boolean result.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<bool> camelMatch(vector<string>& queries, string pattern) {
	```
	Define the function `camelMatch` which takes a list of queries and a string pattern to check if the queries match the camelCase pattern.

2. **Variable Initialization**
	```cpp
	    vector<bool> res;
	```
	Initialize a result vector `res` to store boolean values indicating whether each query matches the pattern.

3. **Looping**
	```cpp
	    for(string q: queries) {
	```
	Iterate over each string in the `queries` list.

4. **Function Call**
	```cpp
	        bool ret = match(q, pattern);
	```
	Call the helper function `match` to check if the query string `q` matches the pattern.

5. **Result Collection**
	```cpp
	        res.push_back(ret);
	```
	Store the result of the `match` function (true or false) into the `res` vector.

6. **Return Statement**
	```cpp
	    return res;
	```
	Return the result vector containing the match status for each query.

7. **Helper Function Definition**
	```cpp
	bool match(string q, string p) {
	```
	Define the helper function `match` to check if a single query string matches the camelCase pattern.

8. **Variable Initialization**
	```cpp
	    int j = 0;
	```
	Initialize an index `j` to track the position in the pattern string `p`.

9. **Looping**
	```cpp
	    for(int i = 0; i < q.size(); i++) {
	```
	Iterate over each character in the query string `q`.

10. **Character Comparison**
	```cpp
	        if(j < p.size()&&q[i] == p[j]) {
	```
	Check if the current character in `q` matches the current character in `p`.

11. **Index Update**
	```cpp
	            j++;
	```
	Increment the index `j` to move to the next character in the pattern.

12. **Continue**
	```cpp
	            continue;
	```
	Continue to the next iteration of the loop if the characters match.

13. **Condition Check**
	```cpp
	        }else if(q[i] >= 'A' && 
	```
	Check if the character in `q` is an uppercase letter.

14. **Condition Check**
	```cpp
	           q[i] <= 'Z')
	```
	Ensure the character is within the range of uppercase letters.

15. **Early Return**
	```cpp
	            return false;               
	```
	Return `false` if an uppercase letter in `q` is encountered that doesn't match the pattern.

16. **Return Statement**
	```cpp
	    return j == p.size();
	```
	Return `true` if all characters in the pattern have been matched; otherwise, return `false`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(m * n)

The time complexity is O(m * n) where m is the number of queries and n is the length of each query. In the worst case, we need to compare each query string with the pattern.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) because we are using only a few additional variables for the two pointers and the result.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/camelcase-matching/description/)

---
{{< youtube h9I_yFNeMgo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

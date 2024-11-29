
+++
authors = ["grid47"]
title = "Leetcode 833: Find And Replace in String"
date = "2024-08-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 833: Find And Replace in String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "J6Gtc4haYHg"
youtube_upload_date="2021-07-19"
youtube_thumbnail="https://i.ytimg.com/vi/J6Gtc4haYHg/maxresdefault.jpg"
comments = true
+++



---
You are given a string s and k replacement operations. Each replacement operation consists of an index, a source substring, and a target substring. For each operation, check if the source substring occurs at the given index in s. If it does, replace the substring with the target. All operations are performed simultaneously, meaning they do not affect each other's indexing. The task is to return the modified string after all operations are applied.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string s and three arrays: indices, sources, and targets. Each element in indices represents the starting position of a source substring in s, and each corresponding element in sources is the substring to replace. The corresponding element in targets is the substring to replace sources with.
- **Example:** `Input: s = 'hello', indices = [0, 3], sources = ['he', 'lo'], targets = ['hi', 'ya']`
- **Constraints:**
	- 1 <= s.length <= 1000
	- k == indices.length == sources.length == targets.length
	- 1 <= k <= 100
	- 0 <= indices[i] < s.length
	- 1 <= sources[i].length, targets[i].length <= 50
	- s consists of only lowercase English letters
	- sources[i] and targets[i] consist of only lowercase English letters

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is the modified string after performing all replacement operations on s simultaneously.
- **Example:** `Output: 'hiya'`
- **Constraints:**
	- The result should be the string after all replacements have been applied, without affecting the indexing of subsequent replacements.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to apply all k replacements to the string s and return the final modified string. Each replacement should be checked, and if the source substring matches at the specified index, it should be replaced by the target substring.

- Step 1: Create a list of index-source-target triples to store the replacement operations.
- Step 2: Sort the replacement operations in descending order of their indices to ensure replacements do not interfere with each other.
- Step 3: For each operation, check if the source substring matches the substring at the given index in s. If it does, replace it with the target.
- Step 4: Return the final string after all replacements have been applied.
{{< dots >}}
### Problem Assumptions ✅
- The input string s and the replacement arrays are valid according to the constraints.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: s = 'hello', indices = [0, 3], sources = ['he', 'lo'], targets = ['hi', 'ya']`  \
  **Explanation:** In this example, 'he' at index 0 is replaced by 'hi', and 'lo' at index 3 is replaced by 'ya', resulting in the string 'hiya'.

- **Input:** `Input: s = 'abcd', indices = [0, 2], sources = ['a', 'cd'], targets = ['eee', 'ffff']`  \
  **Explanation:** Here, 'a' at index 0 is replaced by 'eee', and 'cd' at index 2 is replaced by 'ffff', resulting in 'eeebffff'.

{{< dots >}}
## Approach 🚀
To solve this problem, we need to apply each replacement operation in such a way that no two replacements interfere with each other. This can be done by sorting the replacement operations in descending order of their indices and performing the replacements sequentially.

### Initial Thoughts 💭
- We need to ensure that replacements are applied without changing the index positions of subsequent operations.
- Sorting the operations by their indices in descending order will allow us to apply the replacements from the end of the string to the beginning, preventing overlap.
{{< dots >}}
### Edge Cases 🌐
- An empty string for s or empty arrays for indices, sources, or targets should not occur as per the problem constraints.
- The solution should handle large inputs where s has up to 1000 characters and k is up to 100.
- Ensure that all source substrings are non-overlapping and fit within the string boundaries.
- The solution should efficiently handle the maximum input size.
{{< dots >}}
## Code 💻
```cpp
string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
    /*
    
    string s
    indices - arr of int
    src       arr of str
    tgt       arr of str
    
    */
    
    vector<pair<int, int>> ind;
    
    for(int i = 0; i < indices.size(); i++)
        ind.push_back({indices[i], i});
    
    sort(ind.rbegin(), ind.rend());
    
    for(auto it: ind) {
        string src = sources[it.second], tgt = targets[it.second];
        if(s.substr(it.first, src.size()) == src)
            s = s.substr(0, it.first) + tgt + s.substr(it.first+ src.size());
    }
    
    return s;
}
```

This function takes a string and performs replacement of multiple substrings in the input string based on the given indices, sources, and targets. The replacements are performed from the end to prevent index shifting.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
	```
	Define the function 'findReplaceString' which takes four arguments: a string 's' and vectors for indices, source substrings, and target replacements.

2. **Parameter Declaration**
	```cpp
	    string s
	```
	Declares the string variable 's' that will be processed.

3. **Variable Declaration**
	```cpp
	    vector<pair<int, int>> ind;
	```
	Declares a vector 'ind' to store pairs of indices and their respective positions for sorting.

4. **For Loop**
	```cpp
	    for(int i = 0; i < indices.size(); i++)
	```
	Iterates over the 'indices' vector to process each index and associate it with its position.

5. **Push to Vector**
	```cpp
	        ind.push_back({indices[i], i});
	```
	Pushes the pair of index and its position into the 'ind' vector for sorting.

6. **Sort**
	```cpp
	    sort(ind.rbegin(), ind.rend());
	```
	Sorts the 'ind' vector in reverse order to ensure replacements happen from the end of the string.

7. **For Loop**
	```cpp
	    for(auto it: ind) {
	```
	Iterates over the sorted pairs of indices to perform replacements in the string.

8. **String Manipulation**
	```cpp
	        string src = sources[it.second], tgt = targets[it.second];
	```
	Extracts the corresponding source and target strings based on the current index.

9. **Conditional Check**
	```cpp
	        if(s.substr(it.first, src.size()) == src)
	```
	Checks if the substring of 's' at the current position matches the source string.

10. **String Replacement**
	```cpp
	            s = s.substr(0, it.first) + tgt + s.substr(it.first+ src.size());
	```
	Performs the replacement of the source substring with the target string.

11. **Return Statement**
	```cpp
	    return s;
	```
	Returns the modified string after all replacements.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(k log k + n), where k is the number of replacement operations and n is the length of the string s.
- **Average Case:** O(k log k + n), where k is the number of operations and n is the length of the string.
- **Worst Case:** O(k log k + n), which occurs when all operations need to be checked and applied to the entire string.

The time complexity is dominated by the sorting of the operations, followed by the sequential replacement checks.

### Space Complexity 💾
- **Best Case:** O(k), if no additional space is required beyond the input data.
- **Worst Case:** O(k), as we store the indices, sources, and targets in arrays, which are of size k.

The space complexity is primarily determined by the storage of the replacement operations.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-and-replace-in-string/description/)

---
{{< youtube J6Gtc4haYHg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

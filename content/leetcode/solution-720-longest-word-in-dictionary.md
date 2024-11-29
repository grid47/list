
+++
authors = ["grid47"]
title = "Leetcode 720: Longest Word in Dictionary"
date = "2024-08-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 720: Longest Word in Dictionary in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Trie","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/720.webp"
youtube = "t2jdltmqnlY"
youtube_upload_date="2020-06-17"
youtube_thumbnail="https://i.ytimg.com/vi/t2jdltmqnlY/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/720.webp" 
    alt="A dictionary where the longest word is highlighted, softly glowing as it stands out."
    caption="Solution to LeetCode 720: Longest Word in Dictionary Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given an array of strings `words`, return the longest word in the list that can be built progressively one character at a time by other words in the list.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array of strings `words`, where each string represents a word in the dictionary.
- **Example:** `words = ["b", "ba", "ban", "bana", "banana"]`
- **Constraints:**
	- 1 <= words.length <= 1000
	- 1 <= words[i].length <= 30
	- words[i] consists of lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the longest word that can be formed progressively from other words in the list. If there is a tie, return the lexicographically smallest word.
- **Example:** `"banana"`
- **Constraints:**
	- The result should be a string representing the longest word that can be progressively built.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to identify the longest word that can be formed one character at a time by other words in the list.

- Sort the list of words lexicographically to ensure that we check the smallest words first.
- Use a set to keep track of the words that can be progressively formed.
- For each word, check if it can be formed by adding one character at a time from another word that is already in the set.
- If a word can be formed, update the result if it is longer or lexicographically smaller than the current result.
{{< dots >}}
### Problem Assumptions ✅
- The list of words is guaranteed to contain at least one word.
- All words are in lowercase English letters.
{{< dots >}}
## Examples 🧩
- **Input:** `words = ["b", "ba", "ban", "bana", "banana"]`  \
  **Explanation:** The word 'banana' can be built progressively from 'b', 'ba', 'ban', and 'bana', making it the longest valid word.

- **Input:** `words = ["d", "do", "dog", "dogs", "dot", "done"]`  \
  **Explanation:** The word 'dog' can be built progressively from 'd' and 'do', whereas 'dogs' cannot be built from any previous word.

{{< dots >}}
## Approach 🚀
The solution leverages sorting and set operations to efficiently find the longest word that can be built progressively.

### Initial Thoughts 💭
- We need to check each word's ability to be progressively built from smaller words.
- Sorting the words helps to check shorter words first, ensuring that we find the longest valid word in lexicographical order.
{{< dots >}}
### Edge Cases 🌐
- If the list is empty, the result should be an empty string.
- Handle cases where the input list contains a large number of words (up to 1000).
- Handle cases where the result is a single character word or where no valid word can be built.
- Ensure that sorting and set operations work efficiently within the problem's constraints.
{{< dots >}}
## Code 💻
```cpp
string longestWord(vector<string>& words) {

    sort(words.begin(),words.end());
    unordered_set<string> mp;
    string res="";
    
    for(string w: words){
        if(w.size() == 1 || mp.count(w.substr(0, w.size() -1))) {
            res = w.size()>res.size()? w:res;
            mp.insert(w);
        }
    }
    return res;
}

```

This function finds the longest word in a dictionary that can be built one character at a time by other words in the dictionary.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	string longestWord(vector<string>& words) {
	```
	Defines the function to find the longest word that meets the criteria.

2. **Sorting**
	```cpp
	    sort(words.begin(),words.end());
	```
	Sorts the words lexicographically to ensure smaller words are processed first.

3. **Data Structure**
	```cpp
	    unordered_set<string> mp;
	```
	Initializes a hash set to store valid prefixes of words.

4. **Initialization**
	```cpp
	    string res="";
	```
	Initializes an empty string to store the result.

5. **Loop**
	```cpp
	    for(string w: words){
	```
	Iterates through each word in the sorted list.

6. **Condition Check**
	```cpp
	        if(w.size() == 1 || mp.count(w.substr(0, w.size() -1))) {
	```
	Checks if the word is a single character or if its prefix exists in the hash set.

7. **Update Result**
	```cpp
	            res = w.size()>res.size()? w:res;
	```
	Updates the result if the current word is longer than the existing result.

8. **Insert**
	```cpp
	            mp.insert(w);
	```
	Adds the current word to the hash set as a valid prefix.

9. **Return Statement**
	```cpp
	    return res;
	```
	Returns the longest word that satisfies the conditions.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n) for sorting the words, where n is the number of words.
- **Average Case:** O(n log n) for sorting and O(n * m) for checking each word (n is the number of words, m is the average length of the words).
- **Worst Case:** O(n log n) for sorting and O(n * m) for checking each word.

The time complexity is dominated by the sorting step, followed by checking the progressive formation of each word.

### Space Complexity 💾
- **Best Case:** O(n) for storing the words in a set.
- **Worst Case:** O(n) for storing the words in a set.

The space complexity is O(n) due to the set used for tracking the valid words.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/longest-word-in-dictionary/description/)

---
{{< youtube t2jdltmqnlY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |


+++
authors = ["grid47"]
title = "Leetcode 966: Vowel Spellchecker"
date = "2024-08-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 966: Vowel Spellchecker in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "Twas2VoFXW4"
youtube_upload_date="2021-01-02"
youtube_thumbnail="https://i.ytimg.com/vi/Twas2VoFXW4/maxresdefault.jpg"
comments = true
+++



---
Design a spellchecker that corrects a given word from a query based on specific rules. For each query, find a matching word from the given wordlist by applying exact matches, case-insensitive matches, or vowel error corrections. Return the corrected word, or an empty string if no match is found.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The problem takes in a wordlist of valid words and a set of query words to check against the wordlist.
- **Example:** ` "wordlist": ["Orange", "blue", "Red", "green"], "queries": ["orange", "BLUE", "rEd", "grane", "yellow"] `
- **Constraints:**
	- 1 <= wordlist.length, queries.length <= 5000
	- 1 <= wordlist[i].length, queries[i].length <= 7
	- Each word in wordlist and queries consists only of English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a list of corrected words for the queries based on the rules, or an empty string for unmatched queries.
- **Example:** `["Orange", "blue", "Red", "", ""]`
- **Constraints:**
	- The output list must have the same length as the queries.
	- Each output corresponds to the corrected word for the respective query.

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the best match for each query using exact matching, case-insensitive matching, or vowel-error correction.

- Convert the wordlist into sets and maps for fast lookups.
- Check if the query matches a word exactly in the wordlist.
- If no exact match, check for case-insensitive matches.
- If no case-insensitive match, replace vowels in the query and check for vowel-error matches.
- Return the first match for each query based on precedence or an empty string if no match is found.
{{< dots >}}
### Problem Assumptions ✅
- All queries will be processed independently.
- The wordlist and queries contain only valid English words.
{{< dots >}}
## Examples 🧩
- **Input:** ` "wordlist": ["Orange", "blue", "Red", "green"], "queries": ["orange", "BLUE", "rEd", "grane", "yellow"] `  \
  **Explanation:** Query 'orange' matches 'Orange' exactly ignoring case, 'BLUE' matches 'blue', 'rEd' matches 'Red'. Query 'grane' has a vowel error but doesn't match any word. 'yellow' has no match in the wordlist. Output: ['Orange', 'blue', 'Red', '', ''].

{{< dots >}}
## Approach 🚀
Use sets and hashmaps to efficiently check for matches based on the precedence rules. Iterate through queries and match each using exact, case-insensitive, and vowel-error rules in order.

### Initial Thoughts 💭
- Exact matches are straightforward using a set.
- Case-insensitive matches require storing lowercase versions of the wordlist.
- Vowel-error matching needs normalization of vowels to a common character for easy comparison.
- The precedence of rules ensures a clear order of checks for each query.
- Preprocessing the wordlist into maps will significantly improve lookup efficiency.
{{< dots >}}
### Edge Cases 🌐
- Queries or wordlist is empty. Output should be an empty list.
- Maximum allowable length of wordlist and queries. Ensure performance scales.
- All queries fail to match any word. Output should be all empty strings.
- Queries differ only by case or vowels from wordlist entries.
- Queries with completely mismatched characters have no valid output.
- Wordlist with duplicate words should behave as if the duplicates are removed.
{{< dots >}}
## Code 💻
```cpp
vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
    unordered_set words(wordlist.begin(), wordlist.end());
    unordered_map<string, string> cap, vowel;
    for(string w : wordlist) {
        string lower = tolow(w), devvowel = todev(w);
        cap.insert({lower, w});
        vowel.insert({devvowel, w});
    }

    for(int i = 0; i < queries.size(); i++) {
        
        if (words.count(queries[i])) continue;
        
        string lower = tolow(queries[i]), devvowel = todev(queries[i]);
        
        if(cap.count(lower))
             queries[i] = cap[lower];
        else if(vowel.count(devvowel))
             queries[i] = vowel[devvowel];
        else queries[i] = "";
    }
    return queries;

}

string tolow(string w) {
    for(char &c : w)
    c = tolower(c);
    return w;
}

string todev(string w) {
    w = tolow(w);
    for(char &c:w)
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c=='u')
        c = '#';
    return w;
}
```

The function handles spellchecking with three approaches: exact matches, capitalization-insensitive matches, and vowel-insensitive matches. Helper functions convert strings for case normalization and vowel masking.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
	```
	The main function takes a word list and a list of queries, returning corrected spellings based on specific rules.

2. **Data Structure Initialization**
	```cpp
	    unordered_set words(wordlist.begin(), wordlist.end());
	```
	Stores the words from the word list in a set for fast lookups.

3. **Data Structure Initialization**
	```cpp
	    unordered_map<string, string> cap, vowel;
	```
	Maps to store the first occurrence of words based on capitalization and vowel masking.

4. **Loop**
	```cpp
	    for(string w : wordlist) {
	```
	Iterates through the word list to populate maps for transformations.

5. **String Manipulations**
	```cpp
	        string lower = tolow(w), devvowel = todev(w);
	```
	Transforms the word into lowercase and a vowel-masked version.

6. **Map Insertion**
	```cpp
	        cap.insert({lower, w});
	```
	Inserts the lowercase version into the capitalization map.

7. **Map Insertion**
	```cpp
	        vowel.insert({devvowel, w});
	```
	Inserts the vowel-masked version into the vowel map.

8. **Loop**
	```cpp
	    for(int i = 0; i < queries.size(); i++) {
	```
	Iterates through the queries to apply spellchecking.

9. **Conditional Check**
	```cpp
	        if (words.count(queries[i])) continue;
	```
	Skips processing if the query matches exactly in the word set.

10. **String Manipulations**
	```cpp
	        string lower = tolow(queries[i]), devvowel = todev(queries[i]);
	```
	Generates lowercase and vowel-masked versions of the query.

11. **Conditional Check**
	```cpp
	        if(cap.count(lower))
	```
	Checks for a capitalization-insensitive match.

12. **Map Access**
	```cpp
	             queries[i] = cap[lower];
	```
	Replaces the query with the matched word from the capitalization map.

13. **Conditional Check**
	```cpp
	        else if(vowel.count(devvowel))
	```
	Checks for a vowel-insensitive match.

14. **Map Access**
	```cpp
	             queries[i] = vowel[devvowel];
	```
	Replaces the query with the matched word from the vowel map.

15. **Default Assignment**
	```cpp
	        else queries[i] = "";
	```
	Sets the query to an empty string if no match is found.

16. **Return Statement**
	```cpp
	    return queries;
	```
	Returns the modified list of queries.

17. **Function Declaration**
	```cpp
	string tolow(string w) {
	```
	Helper function to convert a string to lowercase.

18. **Loop**
	```cpp
	    for(char &c : w)
	```
	Iterates through the characters of the string.

19. **Character Conversion**
	```cpp
	    c = tolower(c);
	```
	Converts each character to lowercase.

20. **Return Statement**
	```cpp
	    return w;
	```
	Returns the transformed lowercase string.

21. **Function Declaration**
	```cpp
	string todev(string w) {
	```
	Helper function to convert a string to its vowel-masked version.

22. **String Manipulations**
	```cpp
	    w = tolow(w);
	```
	Converts the string to lowercase for uniformity.

23. **Loop**
	```cpp
	    for(char &c:w)
	```
	Iterates through the characters of the string.

24. **Conditional Check**
	```cpp
	    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c=='u')
	```
	Checks if the character is a vowel.

25. **Character Conversion**
	```cpp
	        c = '#';
	```
	Replaces vowels with the '#' symbol.

26. **Return Statement**
	```cpp
	    return w;
	```
	Returns the transformed vowel-masked string.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(Q)
- **Average Case:** O(Q + W)
- **Worst Case:** O(Q * L)

Q = number of queries, W = number of words in wordlist, L = length of the longest word.

### Space Complexity 💾
- **Best Case:** O(W)
- **Worst Case:** O(W * L)

Space used for storing preprocessed wordlist mappings and queries.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/vowel-spellchecker/description/)

---
{{< youtube Twas2VoFXW4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

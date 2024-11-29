
+++
authors = ["grid47"]
title = "Leetcode 1451: Rearrange Words in a Sentence"
date = "2024-06-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1451: Rearrange Words in a Sentence in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "ZMdBEJX3gog"
youtube_upload_date="2020-05-17"
youtube_thumbnail="https://i.ytimg.com/vi_webp/ZMdBEJX3gog/maxresdefault.webp"
comments = true
+++



---
Given a sentence consisting of space-separated words, rearrange the words in the sentence such that they are ordered by increasing length. Words with the same length should retain their original order. The first word of the rearranged sentence must start with a capital letter, and all other words must be in lowercase.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a single string, `text`, representing the sentence. The first letter of `text` is capitalized, and all subsequent letters are lowercase, with words separated by a single space.
- **Example:** `Input: text = 'Sorting is fun'`
- **Constraints:**
	- 1 <= text.length <= 10^5
	- The sentence starts with a capital letter.
	- Words are separated by a single space.

{{< dots >}}
### Output Specifications 📤
- **Output:** A string representing the rearranged sentence where words are ordered by their length, starting with a capitalized first word. Words of equal length retain their original order.
- **Example:** `Output: 'Is fun sorting'`
- **Constraints:**
	- The output must preserve the capitalization of the first word and lowercase all other words.
	- Words of the same length must retain their original order.

{{< dots >}}
### Core Logic 🔍
**Goal:** Rearrange the words in the input sentence by their lengths, ensuring formatting and order constraints are maintained.

- Split the input sentence into individual words.
- Normalize the case of the words, converting all to lowercase except the first word.
- Pair each word with its length and its original index.
- Sort the words by their length. If two words have the same length, retain their original order using the index.
- Reconstruct the sentence, capitalizing the first word and separating words with a single space.
{{< dots >}}
### Problem Assumptions ✅
- The input string is valid and conforms to the constraints.
- Words are separated by exactly one space with no trailing or leading spaces.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: text = 'Coding is challenging'`  \
  **Explanation:** Output: 'Is coding challenging'. The words are ordered by their lengths: 'is' (2), 'coding' (6), 'challenging' (11).

- **Input:** `Input: text = 'Sorting can be hard'`  \
  **Explanation:** Output: 'Be can hard sorting'. Words are ordered by length: 'be' (2), 'can' (3), 'hard' (4), 'sorting' (7).

- **Input:** `Input: text = 'A quick brown fox jumps'`  \
  **Explanation:** Output: 'A fox quick brown jumps'. Words are ordered as: 'A' (1), 'fox' (3), 'quick' (5), 'brown' (5), 'jumps' (5). The order of equal-length words is preserved.

{{< dots >}}
## Approach 🚀
Use a combination of string manipulation and sorting to reorder the words while maintaining formatting.

### Initial Thoughts 💭
- The task requires splitting the sentence into words for processing.
- Sorting by length is straightforward, but maintaining the original order for words of the same length requires additional data.
- The output format must capitalize the first word and lowercase others.
- Sorting can be performed efficiently using a stable sort, leveraging the word lengths and original indices.
{{< dots >}}
### Edge Cases 🌐
- Input: text = '' -> Output: ''. An empty string remains empty.
- Input: A sentence with 10^5 characters -> Ensure the solution runs within the time complexity of O(n log n).
- Input: text = 'A B C' -> Output: 'A B C'. Single-letter words retain their order.
- Input: text = 'This is a very very long sentence' -> Handles words of varying lengths and duplicates correctly.
- Handles cases where all words have the same length.
{{< dots >}}
## Code 💻
```cpp
string arrangeWords(string txt) {
    
    int n = txt.size();
    vector<vector<int>> arr;
    map<int, string> mp;
    int prv = 0, cnt = 0;
    for(int i = 0; i < n; i++) {
        if(txt[i] == ' ' || i == n - 1) {
            string str;
            int len;
            if(i == n - 1) {
                len = i + 1 - prv;
            } else {
                len = i - prv;
            }
            str = txt.substr(prv, len);
            if(prv == 0) str[0] = str[0] - 'A' + 'a';
            cnt++;
            mp[cnt] = str;
            arr.push_back({len, cnt});
            prv = i + 1;
        }
    }
    sort(arr.begin(), arr.end());
    string res = "";
    for(int i = 0; i < arr.size(); i++) {
        res += mp[arr[i][1]];
        if(i != arr.size() - 1) res += ' ';
    }
    res[0] = res[0] - 'a' + 'A';
    return res;
}
```

This function rearranges the words in the given string such that the words are sorted by their lengths in ascending order. The first character of the first word is capitalized.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	string arrangeWords(string txt) {
	```
	The function 'arrangeWords' is declared, which takes a string 'txt' and returns a string. It will rearrange the words in 'txt' based on their lengths.

2. **Variable Initialization**
	```cpp
	    int n = txt.size();
	```
	This line initializes the variable 'n' to the size of the input string 'txt', which will be used to iterate through the string.

3. **Data Structure Initialization**
	```cpp
	    vector<vector<int>> arr;
	```
	A 2D vector 'arr' is initialized to store word lengths and their respective count indexes for sorting.

4. **Data Structure Initialization**
	```cpp
	    map<int, string> mp;
	```
	A map 'mp' is created to associate each word with a unique count, which will help later in sorting and reconstructing the sentence.

5. **Variable Initialization**
	```cpp
	    int prv = 0, cnt = 0;
	```
	Variables 'prv' and 'cnt' are initialized to help track the starting index of each word and assign it a unique count for sorting.

6. **Loop Start**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	A loop is started that will iterate through the entire string 'txt' character by character.

7. **Conditional Check**
	```cpp
	        if(txt[i] == ' ' || i == n - 1) {
	```
	This conditional checks if the current character is a space or the last character in the string, indicating the end of a word.

8. **Variable Initialization**
	```cpp
	            string str;
	```
	A temporary string 'str' is initialized to hold the current word as it's being extracted.

9. **Variable Initialization**
	```cpp
	            int len;
	```
	The variable 'len' will store the length of the current word.

10. **Conditional Logic**
	```cpp
	            if(i == n - 1) {
	```
	This conditional checks if the current character is the last character in the string, handling the last word's length.

11. **Length Calculation**
	```cpp
	                len = i + 1 - prv;
	```
	For the last word, the length is calculated as the distance from 'prv' (the start of the word) to the last character.

12. **Else Case**
	```cpp
	            } else {
	```
	For all other words (not the last one), calculate the length of the word between spaces.

13. **Length Calculation**
	```cpp
	                len = i - prv;
	```
	For non-last words, the length is calculated as the distance from the previous word's end to the current space.

14. **Conditional End**
	```cpp
	            }
	```
	End of the conditional block determining word length.

15. **Word Extraction**
	```cpp
	            str = txt.substr(prv, len);
	```
	The current word is extracted from 'txt' starting from index 'prv' with the length 'len'.

16. **Character Manipulation**
	```cpp
	            if(prv == 0) str[0] = str[0] - 'A' + 'a';
	```
	If it's the first word, the first character is converted to lowercase.

17. **Variable Increment**
	```cpp
	            cnt++;
	```
	Increment the count for the current word.

18. **Data Structure Update**
	```cpp
	            mp[cnt] = str;
	```
	Add the word to the map 'mp' with its unique count as the key.

19. **Data Structure Update**
	```cpp
	            arr.push_back({len, cnt});
	```
	Push the word's length and count into the vector 'arr'.

20. **Variable Update**
	```cpp
	            prv = i + 1;
	```
	Update 'prv' to point to the next word's starting position.

21. **Sorting**
	```cpp
	    sort(arr.begin(), arr.end());
	```
	Sort the vector 'arr' based on word lengths (ascending order).

22. **String Initialization**
	```cpp
	    string res = "";
	```
	Initialize an empty string 'res' to build the final result.

23. **Loop Start**
	```cpp
	    for(int i = 0; i < arr.size(); i++) {
	```
	Loop through the sorted vector 'arr' to reconstruct the sentence.

24. **String Construction**
	```cpp
	        res += mp[arr[i][1]];
	```
	Append each word from the map 'mp' to the result string 'res'.

25. **String Construction**
	```cpp
	        if(i != arr.size() - 1) res += ' ';
	```
	If not the last word, add a space after each word.

26. **Character Manipulation**
	```cpp
	    res[0] = res[0] - 'a' + 'A';
	```
	Capitalize the first character of the resulting string.

27. **Return Statement**
	```cpp
	    return res;
	```
	Return the rearranged string as the result.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

Sorting the words based on length and index requires O(n log n), where n is the number of characters in the string.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The additional space is used for storing the words, their lengths, and indices during sorting.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/rearrange-words-in-a-sentence/description/)

---
{{< youtube ZMdBEJX3gog >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

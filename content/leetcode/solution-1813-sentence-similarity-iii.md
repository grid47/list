
+++
authors = ["grid47"]
title = "Leetcode 1813: Sentence Similarity III"
date = "2024-05-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1813: Sentence Similarity III in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "MMMd7dMv4Ak"
youtube_upload_date="2021-04-12"
youtube_thumbnail="https://i.ytimg.com/vi/MMMd7dMv4Ak/maxresdefault.jpg"
comments = true
+++



---
You are given two sentences, sentence1 and sentence2, which consist of words separated by spaces. Two sentences are considered similar if you can insert any number of words (including none) into one of the sentences to make them identical. The inserted words must be separated by spaces.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** Each input consists of two strings, sentence1 and sentence2, which are sentences made up of words separated by spaces.
- **Example:** `sentence1 = "I am learning", sentence2 = "I learning"`
- **Constraints:**
	- sentence1.length, sentence2.length <= 100
	- sentence1 and sentence2 consist of lowercase and uppercase English letters and spaces.
	- The words in sentence1 and sentence2 are separated by a single space.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return true if the sentences can be made equal by inserting words into one of the sentences. Otherwise, return false.
- **Example:** `Output: true`
- **Constraints:**
	- The output should be a boolean indicating if the sentences are similar.

{{< dots >}}
### Core Logic 🔍
**Goal:** To check if one sentence can be transformed into the other by inserting words in between.

- Split both sentence1 and sentence2 into individual words.
- Find the longest common prefix and suffix between the two lists of words.
- If one sentence can be made equal by inserting words from the other sentence in the middle, return true. Otherwise, return false.
{{< dots >}}
### Problem Assumptions ✅
- The sentences consist of only uppercase and lowercase English letters and spaces.
- The words in the sentences are separated by a single space.
{{< dots >}}
## Examples 🧩
- **Input:** `sentence1 = "I am learning", sentence2 = "I learning"`  \
  **Explanation:** The words 'I' and 'learning' are common in both sentences. You can insert 'am' between them to make the sentences identical.

- **Input:** `sentence1 = "Hi there", sentence2 = "Hi"`  \
  **Explanation:** The word 'Hi' is common in both sentences, and we can insert 'there' after 'Hi' in sentence2 to make the sentences identical.

{{< dots >}}
## Approach 🚀
To determine if one sentence can be made identical to another, we will check for common prefix and suffix of words and allow insertion of words in between.

### Initial Thoughts 💭
- We can solve this problem by splitting the sentences into words.
- Then, we can compare common prefixes and suffixes of the two sentences.
- If the two sentences have a common prefix and suffix, we can insert the remaining words from one sentence into the other to make them identical.
{{< dots >}}
### Edge Cases 🌐
- The sentences will not be empty as per the given constraints.
- The solution should work efficiently within the constraint that sentence length is <= 100.
- Consider cases where one sentence is a subset of the other or where the sentences have no common words.
- The input strings will not contain leading or trailing spaces.
{{< dots >}}
## Code 💻
```cpp
bool areSentencesSimilar(string s1, string s2) {
    
    deque<string> a, b;
    string tmp = "";
    
    for(char c: s1) {
        if(c == ' ') a.push_back(tmp), tmp = "";
        else tmp += c;
    }
    a.push_back(tmp), tmp = "";
    for(char c: s2) {
        if(c == ' ') b.push_back(tmp), tmp = "";
        else tmp += c;
    }        
    b.push_back(tmp), tmp = "";
    
    while(a.size() != 0 && b.size() != 0 && (a.front() == b.front())) a.pop_front(), b.pop_front();
    while(a.size() != 0 && b.size() != 0 && (a.back() == b.back())) a.pop_back(), b.pop_back();
    
    if(a.size() == 0 || b.size() == 0) return true;
    return false;
}
```

This function `areSentencesSimilar` compares two sentences to check if they are similar by stripping the matching words from the start and end of both sentences. It uses two deques to split each sentence into words and removes matching words from both ends until a mismatch is found or one of the sentences is empty.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool areSentencesSimilar(string s1, string s2) {
	```
	This line defines the function `areSentencesSimilar`, which takes two strings `s1` and `s2` as input and returns a boolean value indicating whether the two sentences are similar based on their words.

2. **Deque Initialization**
	```cpp
	    deque<string> a, b;
	```
	Two deques `a` and `b` are initialized to store words from the two input sentences `s1` and `s2`.

3. **Temporary Variable**
	```cpp
	    string tmp = "";
	```
	A temporary string `tmp` is initialized to accumulate characters of each word as we traverse the sentences.

4. **Splitting Sentence 1**
	```cpp
	    for(char c: s1) {
	```
	This loop iterates over each character of the first sentence `s1` to split it into individual words.

5. **Word Separation**
	```cpp
	        if(c == ' ') a.push_back(tmp), tmp = "";
	```
	When a space is encountered, the current word `tmp` is added to deque `a`, and `tmp` is reset to an empty string for the next word.

6. **Word Accumulation**
	```cpp
	        else tmp += c;
	```
	If the character is not a space, it is added to the temporary string `tmp`.

7. **Final Word in Sentence 1**
	```cpp
	    a.push_back(tmp), tmp = "";
	```
	After the loop ends, the last word in `tmp` is pushed to deque `a`.

8. **Splitting Sentence 2**
	```cpp
	    for(char c: s2) {
	```
	This loop iterates over each character of the second sentence `s2` to split it into individual words.

9. **Word Separation for Sentence 2**
	```cpp
	        if(c == ' ') b.push_back(tmp), tmp = "";
	```
	When a space is encountered in the second sentence, the current word `tmp` is added to deque `b`, and `tmp` is reset.

10. **Word Accumulation for Sentence 2**
	```cpp
	        else tmp += c;
	```
	If the character is not a space, it is added to the temporary string `tmp`.

11. **Final Word in Sentence 2**
	```cpp
	    b.push_back(tmp), tmp = "";
	```
	The last word of `tmp` is added to deque `b` after the loop ends.

12. **Removing Matching Words from Front**
	```cpp
	    while(a.size() != 0 && b.size() != 0 && (a.front() == b.front())) a.pop_front(), b.pop_front();
	```
	This loop compares and removes matching words from the front of both deques `a` and `b`.

13. **Removing Matching Words from Back**
	```cpp
	    while(a.size() != 0 && b.size() != 0 && (a.back() == b.back())) a.pop_back(), b.pop_back();
	```
	This loop compares and removes matching words from the back of both deques `a` and `b`.

14. **Final Check for Similarity**
	```cpp
	    if(a.size() == 0 || b.size() == 0) return true;
	```
	If either deque is empty (indicating all words have been matched), the function returns `true`, indicating the sentences are similar.

15. **Return False**
	```cpp
	    return false;
	```
	If neither deque is empty, the sentences are not similar, and the function returns `false`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the number of words in the longest sentence.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n), where n is the number of words in the sentences, since we need to store the words in separate lists.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/sentence-similarity-iii/description/)

---
{{< youtube MMMd7dMv4Ak >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

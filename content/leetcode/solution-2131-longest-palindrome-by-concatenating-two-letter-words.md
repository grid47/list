
+++
authors = ["grid47"]
title = "Leetcode 2131: Longest Palindrome by Concatenating Two Letter Words"
date = "2024-04-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2131: Longest Palindrome by Concatenating Two Letter Words in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Greedy","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "kBMf-m5we-8"
youtube_upload_date="2022-01-08"
youtube_thumbnail="https://i.ytimg.com/vi_webp/kBMf-m5we-8/maxresdefault.webp"
comments = true
+++



---
You are given an array of strings, where each string consists of two lowercase English letters. The task is to create the longest possible palindrome by selecting some of these strings and concatenating them in any order. Each string can be used at most once. A palindrome is a string that reads the same forward and backward. Return the length of the longest palindrome that can be created, or 0 if it's not possible to create any palindrome.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an array of strings where each string has exactly two lowercase English letters.
- **Example:** `words = ['ab', 'ba', 'aa', 'bb']`
- **Constraints:**
	- 1 <= words.length <= 10^5
	- words[i].length == 2
	- words[i] consists of lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an integer representing the length of the longest palindrome that can be formed using the given strings.
- **Example:** `Input: words = ['ab', 'ba', 'aa', 'bb'] Output: 8`
- **Constraints:**
	- The solution must return the length of the longest possible palindrome.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find pairs of words and possibly one central word to form the longest palindrome.

- 1. Iterate through the array of words and count how many of each word exist.
- 2. Look for pairs of words (e.g., 'ab' and 'ba') that can form palindromes when combined.
- 3. If a word consists of identical letters (e.g., 'aa'), count them for potential center placement in the palindrome.
- 4. Return the length of the longest palindrome formed.
{{< dots >}}
### Problem Assumptions ✅
- There will always be a valid input of at least one word.
- The number of words will always be even or odd as per the given constraints.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: words = ['ab', 'ba', 'aa', 'bb']`  \
  **Explanation:** In this case, 'ab' and 'ba' can form a palindrome pair, and 'aa' and 'bb' can form another. The longest palindrome formed is 'ab' + 'aa' + 'bb' = 'abbbba', which has a length of 8.

- **Input:** `Input: words = ['xx', 'yy', 'zz']`  \
  **Explanation:** Here, 'xx' can form a palindrome on its own, but 'yy' and 'zz' don't have pairs to form a larger palindrome. The longest palindrome formed is 'xx', which has a length of 2.

{{< dots >}}
## Approach 🚀
To solve this problem, we need to count pairs of words that can form palindromes and find a potential central word for the palindrome.

### Initial Thoughts 💭
- We can pair words that are reverse of each other to form the largest possible palindrome.
- We need to track word frequencies and identify pairs and possible center words that can maximize the palindrome length.
{{< dots >}}
### Edge Cases 🌐
- Empty input arrays should not be allowed, as the problem guarantees that there will always be words in the list.
- Ensure the solution is efficient for the upper limit of the input size (10^5 words).
- When all words are the same (e.g., ['aa', 'aa', 'aa']), only one word can form the center of the palindrome.
- The solution must be efficient in both time and space to handle large inputs.
{{< dots >}}
## Code 💻
```cpp
int longestPalindrome(vector<string>& words) {
    int ans = 0;
    int unpaired = 0;
    unordered_map<string, int> mp;

    for(string w: words) {
        if(w[0] == w[1]) {
            if(mp[w] > 0) {
                unpaired--;
                ans += 4;
                mp[w]--;
            } else {
                unpaired++;
                mp[w]++;
            }
        } else {
            string rev = w;
            reverse(rev.begin(), rev.end());
            if(mp[rev] > 0) {
                ans += 4;
                mp[rev]--;
            } else mp[w]++;
        }
    }


    if (unpaired > 0) ans += 2;
    return ans;
}
```

This function takes a vector of strings, where each string consists of two characters. It calculates the longest palindrome that can be formed by pairing words and their reverse counterparts.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int longestPalindrome(vector<string>& words) {
	```
	Function definition that initializes the longestPalindrome function which takes a vector of words as input.

2. **Variable Initialization**
	```cpp
	    int ans = 0;
	```
	Initializes a variable 'ans' to 0, which will hold the total length of the longest palindrome.

3. **Variable Initialization**
	```cpp
	    int unpaired = 0;
	```
	Initializes a counter 'unpaired' to track words that cannot be paired with their reverse.

4. **Data Structure Initialization**
	```cpp
	    unordered_map<string, int> mp;
	```
	Declares an unordered map 'mp' to store the frequency of each word.

5. **Loop**
	```cpp
	    for(string w: words) {
	```
	Begins a loop to iterate over each word in the input vector.

6. **Condition**
	```cpp
	        if(w[0] == w[1]) {
	```
	Checks if the current word consists of two identical characters.

7. **Condition**
	```cpp
	            if(mp[w] > 0) {
	```
	If a pair of the same word exists in the map, decrease unpaired count and add 4 to the result.

8. **Action**
	```cpp
	                unpaired--;
	```
	Decreases the unpaired count when a matching pair is found.

9. **Action**
	```cpp
	                ans += 4;
	```
	Adds 4 to the answer since each word pair contributes 4 to the palindrome.

10. **Action**
	```cpp
	                mp[w]--;
	```
	Decreases the frequency of the current word in the map.

11. **Action**
	```cpp
	            } else {
	```
	If no pair is found for the word, increase the unpaired count.

12. **Action**
	```cpp
	                unpaired++;
	```
	Increases the unpaired count when no matching pair exists.

13. **Action**
	```cpp
	                mp[w]++;
	```
	Increases the frequency of the current word in the map.

14. **Condition**
	```cpp
	        } else {
	```
	Checks if the current word consists of two different characters.

15. **Action**
	```cpp
	            string rev = w;
	```
	Stores the reverse of the current word in the variable 'rev'.

16. **Action**
	```cpp
	            reverse(rev.begin(), rev.end());
	```
	Reverses the string 'rev' to check for palindrome matches.

17. **Condition**
	```cpp
	            if(mp[rev] > 0) {
	```
	Checks if a reverse pair for the current word exists in the map.

18. **Action**
	```cpp
	                ans += 4;
	```
	Adds 4 to the answer when a reverse pair is found.

19. **Action**
	```cpp
	                mp[rev]--;
	```
	Decreases the frequency of the reversed word in the map.

20. **Action**
	```cpp
	            } else mp[w]++;
	```
	If no reverse pair is found, increase the frequency of the current word in the map.

21. **Final Check**
	```cpp
	    if (unpaired > 0) ans += 2;
	```
	If there are any unpaired words left, add 2 to the result to account for one word in the middle of the palindrome.

22. **Return Statement**
	```cpp
	    return ans;
	```
	Returns the final length of the longest palindrome that can be formed.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the number of words, as we only need to iterate through the list and check frequencies.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n), as we store the frequency of each word in a hashmap.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/description/)

---
{{< youtube kBMf-m5we-8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

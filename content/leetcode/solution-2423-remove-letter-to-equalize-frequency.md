
+++
authors = ["grid47"]
title = "Leetcode 2423: Remove Letter To Equalize Frequency"
date = "2024-03-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2423: Remove Letter To Equalize Frequency in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "wXKif4MwAtI"
youtube_upload_date="2022-10-01"
youtube_thumbnail="https://i.ytimg.com/vi_webp/wXKif4MwAtI/maxresdefault.webp"
comments = true
+++



---
You are given a string consisting of lowercase English letters. You must remove one letter from the string so that the frequency of all remaining letters is equal. Return true if it is possible to achieve this by removing exactly one letter, otherwise return false.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a string word consisting of lowercase English letters.
- **Example:** `word = "abcc"`
- **Constraints:**
	- 2 <= word.length <= 100
	- word consists of lowercase English letters only.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return true if it is possible to remove one letter so that all remaining letters have equal frequency, otherwise return false.
- **Example:** `Output: true`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Determine if it is possible to remove one letter so that all remaining characters have equal frequencies.

- 1. Count the frequency of each letter in the string.
- 2. Count how many times each frequency appears in the string.
- 3. If there are more than two distinct frequencies, return false.
- 4. If there is only one frequency, check if all letters have this frequency or if one letter appears once (removable).
- 5. If the two frequencies differ by 1 and one letter has that frequency, it can be removed to balance frequencies, return true.
{{< dots >}}
### Problem Assumptions ✅
- The string will always contain at least 2 characters.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: word = "abcc"`  \
  **Explanation:** By removing the last 'c', the frequency of 'a', 'b', and 'c' becomes equal (1 for each). Hence, the answer is true.

- **Input:** `Input: word = "aazz"`  \
  **Explanation:** It is impossible to remove one letter and make the frequency of all characters equal because the frequencies of 'a' and 'z' differ, and neither can be reduced to equal the other.

{{< dots >}}
## Approach 🚀
We need to check if it's possible to remove one character so that the frequencies of all remaining characters are equal. This can be done by analyzing the frequency distribution of characters in the string.

### Initial Thoughts 💭
- The problem requires checking how frequencies of characters are distributed.
- By counting frequencies and the frequency of frequencies, we can easily determine if removing a letter will balance the remaining frequencies.
{{< dots >}}
### Edge Cases 🌐
- The problem guarantees that word will have at least 2 characters.
- The solution should efficiently handle strings of length 100.
- Check for cases where only one letter appears multiple times and all others appear once.
- Ensure that time complexity is O(n) for counting frequencies.
{{< dots >}}
## Code 💻
```cpp
bool equalFrequency(string word) {
    unordered_map<char, int> mp;
    map<int, int> mp2;
    for(auto c: word)  mp[c]++;
    
    for(auto m: mp)  mp2[m.second]++;
    
    
    if(mp2.size() > 2) return false;
    map<int, int>::iterator it1 = mp2.begin();
    map<int, int>::iterator it2 = mp2.begin();
    it2++;
    
    if(mp2.size() == 1){
        if(mp.size() == 1 || it1->first == 1) return true;
        return false;
    }
   
    
    if(it1->first == 1 && it1->second == 1) return true;
    if(it1->first == it2->first-1 && it2->second == 1) return true;
    return false;
}
```

This function checks whether a string has equal frequency of characters after removing or modifying at most one character.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool equalFrequency(string word) {
	```
	Defines the function 'equalFrequency' which accepts a string and returns a boolean value indicating whether it is possible to equalize the frequency of characters in the string.

2. **Data Structure Initialization**
	```cpp
	    unordered_map<char, int> mp;
	```
	Declares an unordered map 'mp' to store the frequency count of each character in the word.

3. **Data Structure Initialization**
	```cpp
	    map<int, int> mp2;
	```
	Declares a map 'mp2' to store how many times each frequency appears.

4. **Frequency Counting**
	```cpp
	    for(auto c: word)  mp[c]++;
	```
	Loops through each character in the word, incrementing its count in the map 'mp'.

5. **Frequency Counting**
	```cpp
	    for(auto m: mp)  mp2[m.second]++;
	```
	Iterates over the map 'mp' to fill 'mp2' with the frequency of each frequency.

6. **Validation**
	```cpp
	    if(mp2.size() > 2) return false;
	```
	If there are more than two different frequencies, return false as it is impossible to make the frequencies equal by removing or modifying one character.

7. **Iterator Setup**
	```cpp
	    map<int, int>::iterator it1 = mp2.begin();
	```
	Creates an iterator 'it1' pointing to the beginning of the 'mp2' map.

8. **Iterator Setup**
	```cpp
	    map<int, int>::iterator it2 = mp2.begin();
	```
	Creates another iterator 'it2' also pointing to the beginning of the 'mp2' map.

9. **Iterator Adjustment**
	```cpp
	    it2++;
	```
	Moves the second iterator 'it2' to the second element in the 'mp2' map.

10. **Condition Check**
	```cpp
	    if(mp2.size() == 1){
	```
	Checks if there is only one frequency in 'mp2', indicating all characters have the same frequency.

11. **Condition Check**
	```cpp
	        if(mp.size() == 1 || it1->first == 1) return true;
	```
	If there is only one character or all characters have a frequency of 1, return true (it is possible to equalize frequencies).

12. **Condition Check**
	```cpp
	        return false;
	```
	If neither of the previous conditions are met, return false.

13. **Final Condition**
	```cpp
	    if(it1->first == 1 && it1->second == 1) return true;
	```
	If the frequency of 1 appears exactly once, return true as it can be equalized by removing a single character.

14. **Final Condition**
	```cpp
	    if(it1->first == it2->first-1 && it2->second == 1) return true;
	```
	If the difference between the two frequencies is 1 and the second frequency occurs exactly once, return true.

15. **Final Condition**
	```cpp
	    return false;
	```
	Return false if none of the conditions for equalizing the frequencies are met.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) where n is the length of the string, as we need to traverse the string and perform frequency analysis.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the two hash maps used for counting character and frequency distributions.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/remove-letter-to-equalize-frequency/description/)

---
{{< youtube wXKif4MwAtI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

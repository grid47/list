
+++
authors = ["grid47"]
title = "Leetcode 2182: Construct String With Repeat Limit"
date = "2024-04-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2182: Construct String With Repeat Limit in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Greedy","Heap (Priority Queue)","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "PZT5c2SFAYs"
youtube_upload_date="2022-02-20"
youtube_thumbnail="https://i.ytimg.com/vi/PZT5c2SFAYs/maxresdefault.jpg"
comments = true
+++



---
Given a string of lowercase letters and an integer limit, construct a new string such that no character appears more than the given limit times consecutively. The new string should be lexicographically largest while satisfying this condition. You can use any subset of characters from the given string.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** A string of lowercase English letters and an integer repeatLimit.
- **Example:** `Input: s = 'bbaaccd', repeatLimit = 2`
- **Constraints:**
	- 1 <= repeatLimit <= s.length <= 10^5
	- s consists of only lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** A lexicographically largest string satisfying the condition that no character appears more than repeatLimit times consecutively.
- **Example:** `Output: 'ccbbaa'`
- **Constraints:**
	- No character appears consecutively more than repeatLimit times.
	- Characters are used from the input string.

{{< dots >}}
### Core Logic 🔍
**Goal:** Construct the lexicographically largest string that satisfies the repeatLimit constraint.

- Count the frequency of each character in the string.
- Use a max-heap to process characters by their lexicographical order and frequency.
- Construct the result string by adding characters within the repeatLimit constraint.
- Handle cases where the highest frequency character cannot continue by inserting the next highest character.
{{< dots >}}
### Problem Assumptions ✅
- Input string is not empty.
- repeatLimit is at least 1.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: s = 'abcabc', repeatLimit = 2`  \
  **Explanation:** The result is 'ccbbaa'. Each character appears at most twice consecutively, and the string is lexicographically largest.

- **Input:** `Input: s = 'xyzxxy', repeatLimit = 3`  \
  **Explanation:** The result is 'yyxxyz'. The character 'y' appears 2 times consecutively, while 'x' and 'z' appear at most 2 times.

{{< dots >}}
## Approach 🚀
Utilize a max-heap to manage characters based on their lexicographical order and frequency. Construct the string incrementally while respecting the repeatLimit constraint.

### Initial Thoughts 💭
- The lexicographical order can be maintained using a max-heap.
- The repeatLimit constraint requires careful tracking of character counts.
- A greedy approach prioritizing the largest available character should work.
- If a character exceeds the repeatLimit, switch to the next largest character temporarily.
{{< dots >}}
### Edge Cases 🌐
- No valid result as the input string must have at least one character.
- An input string of length 10^5 with repeated characters.
- An input string with all characters the same, e.g., 'aaaa'.
- An input string with all unique characters, e.g., 'abcd'.
- Ensure no character exceeds repeatLimit consecutively in the output.
{{< dots >}}
## Code 💻
```cpp
string repeatLimitedString(string s, int repeatLimit) {
    vector<int> freq(26, 0);
    for(char ch: s) freq[ch - 'a']++;
    priority_queue<pair<char, int>> pq;

    for(int i = 0; i < 26; i++)
    if(freq[i] > 0) pq.push(make_pair((char) 'a' + i, freq[i]));

    string ans = "";
    while(!pq.empty()) {
        pair<char, int> p = pq.top();
        pq.pop();
        int cnt = p.second;
        for(int i = 0; i < repeatLimit && cnt-- > 0; i++) ans.push_back(p.first);

        if(cnt > 0 && !pq.empty()) {
            pair<char, int> sp = pq.top();
            pq.pop();
            ans.push_back(sp.first);
            if(sp.second > 1) {
                sp.second--;
                pq.push(sp);
            }
            p.second = cnt;
            pq.push(p);
        }
    }
    return ans;
}
```

This function repeats characters from the input string `s` but limits consecutive occurrences of the same character to `repeatLimit`. The function uses a priority queue to manage the frequency of characters and ensures that characters are repeated while adhering to the repeat limit.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	string repeatLimitedString(string s, int repeatLimit) {
	```
	Define a function that takes a string `s` and an integer `repeatLimit` to return a new string with repeated characters, subject to the `repeatLimit`.

2. **Variable Initialization**
	```cpp
	    vector<int> freq(26, 0);
	```
	Initialize a vector `freq` to store the frequency of each character (26 letters from 'a' to 'z').

3. **Character Frequency Counting**
	```cpp
	    for(char ch: s) freq[ch - 'a']++;
	```
	Iterate through the input string `s` and increment the frequency count of each character.

4. **Priority Queue Setup**
	```cpp
	    priority_queue<pair<char, int>> pq;
	```
	Create a priority queue `pq` to store pairs of characters and their corresponding frequencies in descending order.

5. **Loop for Frequency to Queue**
	```cpp
	    for(int i = 0; i < 26; i++)
	```
	Loop through the frequency array to add characters with non-zero frequencies to the priority queue.

6. **Queue Population**
	```cpp
	    if(freq[i] > 0) pq.push(make_pair((char) 'a' + i, freq[i]));
	```
	If a character has a non-zero frequency, push it to the priority queue along with its frequency.

7. **String Initialization**
	```cpp
	    string ans = "";
	```
	Initialize an empty string `ans` to build the final result.

8. **Main Loop**
	```cpp
	    while(!pq.empty()) {
	```
	Start a while loop that continues as long as there are characters in the priority queue.

9. **Extract Maximum Frequency Pair**
	```cpp
	        pair<char, int> p = pq.top();
	```
	Extract the character with the highest frequency from the priority queue.

10. **Pop Maximum Frequency Pair**
	```cpp
	        pq.pop();
	```
	Remove the character-frequency pair from the priority queue.

11. **Store Remaining Count**
	```cpp
	        int cnt = p.second;
	```
	Store the remaining count of the character in the variable `cnt`.

12. **Repeat Characters**
	```cpp
	        for(int i = 0; i < repeatLimit && cnt-- > 0; i++) ans.push_back(p.first);
	```
	Push the character `p.first` to the result string `ans` up to the `repeatLimit` number of times, decrementing the count.

13. **Re-check Queue**
	```cpp
	        if(cnt > 0 && !pq.empty()) {
	```
	Check if the current character still has remaining counts and if there are other characters in the priority queue.

14. **Process Next Character**
	```cpp
	            pair<char, int> sp = pq.top();
	```
	Extract the character with the second highest frequency from the priority queue.

15. **Pop Next Character**
	```cpp
	            pq.pop();
	```
	Remove the second highest frequency character from the queue.

16. **Add Next Character**
	```cpp
	            ans.push_back(sp.first);
	```
	Add the second character to the result string `ans`.

17. **Re-insert Reduced Character**
	```cpp
	            if(sp.second > 1) {
	```
	If the second character has more than one occurrence left, reduce its frequency and add it back to the queue.

18. **Update First Character**
	```cpp
	                sp.second--;
	```
	Decrement the frequency of the second character.

19. **Re-add Second Character**
	```cpp
	                pq.push(sp);
	```
	Push the second character back into the priority queue after decrementing its frequency.

20. **Re-add First Character**
	```cpp
	            }
	```
	Complete the process of re-adding the characters to the queue.

21. **Update First Character Frequency**
	```cpp
	            p.second = cnt;
	```
	Update the frequency of the first character after adding it to the result.

22. **Re-add First Character to Queue**
	```cpp
	            pq.push(p);
	```
	Push the first character back into the priority queue with its updated frequency.

23. **Return Result**
	```cpp
	    return ans;
	```
	Return the final string `ans`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log k)
- **Average Case:** O(n log k)
- **Worst Case:** O(n log k)

Heap operations dominate the time complexity, where n is the string length and k is the number of distinct characters.

### Space Complexity 💾
- **Best Case:** O(k)
- **Worst Case:** O(k)

Heap storage and frequency tracking require space proportional to the number of distinct characters.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/construct-string-with-repeat-limit/description/)

---
{{< youtube PZT5c2SFAYs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

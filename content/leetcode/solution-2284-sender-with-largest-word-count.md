
+++
authors = ["grid47"]
title = "Leetcode 2284: Sender With Largest Word Count"
date = "2024-03-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2284: Sender With Largest Word Count in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "j5BlwSyz3F8"
youtube_upload_date="2022-05-28"
youtube_thumbnail="https://i.ytimg.com/vi_webp/j5BlwSyz3F8/maxresdefault.webp"
comments = true
+++



---
You are given two arrays: one containing a series of messages, and another with the names of the senders corresponding to each message. A message is a list of words separated by spaces. Your task is to determine which sender has sent the most words across all their messages. If there is a tie for the most words, return the sender with the lexicographically larger name.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are provided with two arrays, messages and senders, both of length n. Each message corresponds to a sender in the same index.
- **Example:** `Input: messages = ["I love coding","How are you today?","Great to see you here!"], senders = ["Bob","Charlie","Bob"]`
- **Constraints:**
	- 1 <= n <= 10^4
	- 1 <= messages[i].length <= 100
	- 1 <= senders[i].length <= 10
	- messages[i] consists of uppercase and lowercase English letters and spaces.
	- Each message has no leading or trailing spaces.
	- senders[i] consists of uppercase and lowercase English letters only.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the sender who sent the most words across all their messages. If there is a tie, return the sender with the lexicographically larger name.
- **Example:** `Output: "Bob"`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to identify the sender with the largest word count across all their messages. If multiple senders share the maximum word count, return the one with the lexicographically larger name.

- Iterate through the list of senders and messages.
- Count the number of words in each message.
- Maintain a record of total word counts for each sender.
- At the end of the iteration, identify the sender with the highest word count. If there's a tie, return the lexicographically larger name.
{{< dots >}}
### Problem Assumptions ✅
- Each sender sends at least one message.
- The word count can be calculated by splitting the message string by spaces.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: messages = ["I love coding","How are you today?","Great to see you here!"], senders = ["Bob","Charlie","Bob"]`  \
  **Explanation:** Here, Bob sends 2 words in the first message and 5 words in the last message, for a total of 7 words. Charlie sends 4 words, so Bob is the sender with the largest word count.

- **Input:** `Input: messages = ["Coding is fun","What are you doing?"], senders = ["Alice","Bob"]`  \
  **Explanation:** Alice sends 3 words in the first message, while Bob sends 4 words. Bob, having sent more words, is returned.

{{< dots >}}
## Approach 🚀
To solve this problem efficiently, we'll iterate through the arrays to calculate the total word count for each sender. Then, we'll compare the word counts and return the sender with the highest count, resolving ties based on lexicographical order.

### Initial Thoughts 💭
- The word count for each message can be easily determined by counting spaces and adding one.
- We need to handle ties by lexicographical order.
- We can use a hashmap to track the total word count for each sender.
{{< dots >}}
### Edge Cases 🌐
- Messages and senders arrays cannot be empty.
- The algorithm should efficiently handle up to 10^4 messages.
- Messages with varying spaces between words and senders with the same number of words.
- Consider the lexicographical order in case of ties.
{{< dots >}}
## Code 💻
```cpp
string largestWordCount(vector<string>& messages, vector<string>& senders) {

    unordered_map<string, int> cnt;
    string res;
    int max_cnt = 0;
    for(int i = 0; i < senders.size(); i++) {
        int words = count(begin(messages[i]), end(messages[i]), ' ') + 1;
        int cur = cnt[senders[i]] += words;
        if((cur > max_cnt) || (cur == max_cnt && senders[i] > res)) {
            res = senders[i];
            max_cnt = cur;
        }
    }

    return res;
}
```

This function takes two vectors: `messages` (a list of messages sent) and `senders` (a list of corresponding senders), and returns the sender with the most words across their messages. If two senders have the same number of words, it returns the sender with the lexicographically larger name.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	string largestWordCount(vector<string>& messages, vector<string>& senders) {
	```
	The function `largestWordCount` is defined to return a string (the sender with the most words). It takes two vectors of strings: `messages` (the content of messages) and `senders` (the names of the senders).

2. **Initialize Count Map**
	```cpp
	    unordered_map<string, int> cnt;
	```
	An unordered map `cnt` is initialized, where the keys are sender names and the values are the total word counts for each sender's messages.

3. **Initialize Result Variables**
	```cpp
	    string res;
	```
	A string `res` is declared to store the sender with the maximum word count.

4. **Initialize Maximum Count**
	```cpp
	    int max_cnt = 0;
	```
	An integer `max_cnt` is initialized to track the highest word count encountered during iteration.

5. **Iterate Over Senders**
	```cpp
	    for(int i = 0; i < senders.size(); i++) {
	```
	A `for` loop is started to iterate over each sender in the `senders` vector and corresponding messages in `messages`.

6. **Count Words in Message**
	```cpp
	        int words = count(begin(messages[i]), end(messages[i]), ' ') + 1;
	```
	The number of words in the current message (`messages[i]`) is calculated by counting spaces and adding 1 (to account for the last word).

7. **Update Word Count for Sender**
	```cpp
	        int cur = cnt[senders[i]] += words;
	```
	The word count for the current sender is updated by adding the number of words in their message.

8. **Check for Maximum Word Count**
	```cpp
	        if((cur > max_cnt) || (cur == max_cnt && senders[i] > res)) {
	```
	If the current sender's word count exceeds `max_cnt` or equals it but has a lexicographically larger name than the current result (`res`), the sender becomes the new candidate.

9. **Update Result and Max Count**
	```cpp
	            res = senders[i];
	```
	If the condition is satisfied, the sender with the maximum word count (or the lexicographically larger name) is saved as `res`.

10. ****
	```cpp
	            max_cnt = cur;
	```
	The variable `max_cnt` is updated to the current word count (`cur`) of the sender.

11. **Return the Result**
	```cpp
	    return res;
	```
	The function returns the sender with the maximum word count (or the lexicographically largest sender name in case of a tie).

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) where n is the number of messages because we process each message and sender once.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

We store the word count for each sender, so the space complexity is O(n) where n is the number of unique senders.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/sender-with-largest-word-count/description/)

---
{{< youtube j5BlwSyz3F8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

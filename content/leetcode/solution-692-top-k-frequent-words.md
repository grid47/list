
+++
authors = ["grid47"]
title = "Leetcode 692: Top K Frequent Words"
date = "2024-08-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 692: Top K Frequent Words in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Trie","Sorting","Heap (Priority Queue)","Bucket Sort","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/692.webp"
youtube = "jEm_HfkIk9s"
youtube_upload_date="2021-02-05"
youtube_thumbnail="https://i.ytimg.com/vi/jEm_HfkIk9s/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/692.webp" 
    alt="A list of words where the most frequent ones glow softly, indicating their popularity."
    caption="Solution to LeetCode 692: Top K Frequent Words Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given a list of words and an integer k, return the k most frequent words in the list. The words should be sorted by their frequency in descending order. If two words have the same frequency, they should be sorted lexicographically.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array of words and an integer k.
- **Example:** `words = ["apple", "banana", "apple", "orange", "banana", "banana"], k = 2`
- **Constraints:**
	- 1 <= words.length <= 500
	- 1 <= words[i].length <= 10
	- words[i] consists of lowercase English letters.
	- k is in the range [1, the number of unique words]

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the k most frequent words sorted by frequency and lexicographical order.
- **Example:** `["banana", "apple"]`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to determine the k most frequent words from the given list and sort them by their frequency and lexicographical order.

- Count the frequency of each word using a hash map.
- Sort the words first by frequency (descending) and then lexicographically.
- Return the first k words from the sorted list.
{{< dots >}}
### Problem Assumptions ✅
- The input list is non-empty.
- There is at least one unique word in the list.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: words = ["apple", "banana", "apple", "orange", "banana", "banana"], k = 2`  \
  **Explanation:** The words 'banana' and 'apple' are the two most frequent words. 'banana' appears 3 times and 'apple' appears 2 times, so they are returned as the result.

- **Input:** `Example 2: words = ["cat", "dog", "bird", "dog", "dog", "bird", "bird"], k = 3`  \
  **Explanation:** Both 'dog' and 'bird' appear 3 times, so they come first, followed by 'cat'. The result is ['dog', 'bird', 'cat'].

{{< dots >}}
## Approach 🚀
The solution involves counting the frequency of each word using a hash map and then sorting the words based on their frequency and lexicographical order.

### Initial Thoughts 💭
- We need to count the frequency of each word.
- Sorting needs to be done based on frequency and lexicographical order for ties.
- A priority queue or sorting could help in efficiently getting the top k frequent words.
{{< dots >}}
### Edge Cases 🌐
- If words is an empty list, the result should be an empty list.
- Ensure the solution works within time constraints for large input sizes.
- If k equals the number of unique words, the function should return all the words.
- Ensure the solution handles edge cases like all words having the same frequency.
{{< dots >}}
## Code 💻
```cpp
vector<string> topKFrequent(vector<string>& words, int k) {
    unordered_map<string, int> mp;
    for(string str: words)
        mp[str]++;

    priority_queue<tup_t, vector<tup_t>, cmp> pq;
    for(auto it: mp) {
        auto tp = make_tuple(it.second, it.first);
        pq.push(tp);
    }
    vector<string> ans;
    while(k-- > 0) {
        auto e = pq.top();
        ans.push_back(get<1>(e));
        pq.pop();
    }
    return ans;
}
```

This code defines a function `topKFrequent` that returns the k most frequent words from a list of words. It first counts the frequency of each word using an unordered map, then stores the frequency and corresponding word in a priority queue, and finally pops the k most frequent words.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Method Definition**
	```cpp
	vector<string> topKFrequent(vector<string>& words, int k) {
	```
	This defines the `topKFrequent` function, which takes a vector of words and an integer 'k', and returns the top k most frequent words.

2. **Variable Initialization**
	```cpp
	    unordered_map<string, int> mp;
	```
	This initializes an unordered map 'mp' to store the frequency of each word.

3. **Looping**
	```cpp
	    for(string str: words)
	```
	This loop iterates over each word in the 'words' vector.

4. **Frequency Calculation**
	```cpp
	        mp[str]++;
	```
	This increments the count for each word in the unordered map.

5. **Priority Queue Initialization**
	```cpp
	    priority_queue<tup_t, vector<tup_t>, cmp> pq;
	```
	This initializes a priority queue 'pq' to store words and their frequencies, sorted by frequency using a custom comparator.

6. **Looping**
	```cpp
	    for(auto it: mp) {
	```
	This loop iterates over the entries in the unordered map 'mp' (word-frequency pairs).

7. **Tuple Creation**
	```cpp
	        auto tp = make_tuple(it.second, it.first);
	```
	This creates a tuple 'tp' containing the word's frequency (it.second) and the word itself (it.first).

8. **Priority Queue Insertion**
	```cpp
	        pq.push(tp);
	```
	This inserts the tuple 'tp' (word and its frequency) into the priority queue.

9. **Vector Initialization**
	```cpp
	    vector<string> ans;
	```
	This initializes an empty vector 'ans' to store the top k most frequent words.

10. **While Loop**
	```cpp
	    while(k-- > 0) {
	```
	This while loop runs until the top k frequent words are found (decrements k each time).

11. **Priority Queue Access**
	```cpp
	        auto e = pq.top();
	```
	This retrieves the top element (highest frequency) from the priority queue.

12. **Vector Insertion**
	```cpp
	        ans.push_back(get<1>(e));
	```
	This adds the word (second element of the tuple) to the 'ans' vector.

13. **Priority Queue Pop**
	```cpp
	        pq.pop();
	```
	This removes the top element (highest frequency) from the priority queue.

14. **Return Statement**
	```cpp
	    return ans;
	```
	This returns the vector 'ans', which contains the top k most frequent words.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log k)
- **Average Case:** O(n log k)
- **Worst Case:** O(n log n)

Sorting the words by frequency and lexicographical order takes O(n log n) time, but we are only interested in the top k words, so the best and average case is O(n log k).

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

We use extra space to store the frequency of each word, which is O(n), where n is the number of unique words.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/top-k-frequent-words/description/)

---
{{< youtube jEm_HfkIk9s >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

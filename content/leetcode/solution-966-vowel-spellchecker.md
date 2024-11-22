
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
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
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
};
{{< /highlight >}}
---

### Problem Statement

The problem at hand involves performing a spellchecking operation on a list of queries, using a provided wordlist of correctly spelled words. For each query, we need to return the correct word from the wordlist if it exists, or return an empty string if no match is found.

In addition to exact matches, we are asked to handle two special cases:
1. **Case-insensitivity**: If the query is an exact match but with different casing (e.g., "hello" vs "HELLO"), it should still be considered a match.
2. **Vowel-insensitivity**: If the query is almost correct except for differences in vowels (i.e., vowels can be replaced with a special character like `#`), it should still be considered a match. For example, "hello" and "h#ll#" should be treated as equivalent, since only vowels differ.

We are required to return the correct word for each query or an empty string if no match is found.

### Approach

To solve this problem efficiently, we can break it down into the following steps:

1. **Exact Matching**: First, we check if a query exactly matches any word in the wordlist. This can be achieved using a set for fast lookups.

2. **Case-insensitive Matching**: We handle case-insensitive matches by converting both the query and the words in the wordlist to lowercase before comparing them. This ensures that "hello", "Hello", and "HELLO" are treated as identical.

3. **Vowel-insensitive Matching**: We replace vowels (`a`, `e`, `i`, `o`, `u`) in the query and the words with a special character (e.g., `#`) to ignore vowel differences. This allows queries like "h#ll#" to match "hello".

4. **Data Structures**: We use the following data structures:
   - A set (`unordered_set`) to store the words in the wordlist for fast exact match lookups.
   - Two maps (`unordered_map`): one for case-insensitive mappings and another for vowel-insensitive mappings.
   
   The maps will help us retrieve the correct word from the wordlist if we encounter a query that matches in case or vowel-insensitivity.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set words(wordlist.begin(), wordlist.end());
        unordered_map<string, string> cap, vowel;
```

1. **Initialization**:
   - We start by creating an `unordered_set` called `words` to store all the words in the `wordlist` for quick exact lookups.
   - We also initialize two `unordered_map` objects:
     - `cap` will store mappings of lowercase words to their original word (to handle case-insensitive matching).
     - `vowel` will store mappings of vowel-insensitive versions of words to their original word.

```cpp
        for(string w : wordlist) {
            string lower = tolow(w), devvowel = todev(w);
            cap.insert({lower, w});
            vowel.insert({devvowel, w});
        }
```

2. **Populating Maps**:
   - We iterate over each word in the `wordlist`. For each word `w`:
     - We generate a lowercase version of the word using the `tolow` function.
     - We generate a vowel-insensitive version of the word using the `todev` function.
     - We store the original word in the `cap` map, using the lowercase version as the key.
     - We store the original word in the `vowel` map, using the vowel-insensitive version as the key.

```cpp
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
```

3. **Query Processing**:
   - For each query in `queries`, we:
     - First check if the query exists exactly in the `words` set. If it does, we leave the query unchanged.
     - If no exact match is found, we convert the query to lowercase and check if it matches any word in the `cap` map. If a match is found, we update the query to the correct word.
     - If no match is found in `cap`, we check if the vowel-insensitive version of the query matches any word in the `vowel` map. If a match is found, we update the query to the correct word.
     - If no match is found in either map, we set the query to an empty string.

4. **Helper Functions**:
```cpp
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

- **`tolow` Function**:
  - The `tolow` function converts a string to lowercase by iterating over each character and using the `tolower` function.
  
- **`todev` Function**:
  - The `todev` function first converts the word to lowercase using `tolow`. Then, it replaces all vowels (`a`, `e`, `i`, `o`, `u`) with the special character `#`. This ensures that vowel differences are ignored when comparing words.

### Complexity

- **Time Complexity**: 
  - The time complexity is **O(N + Q)**, where:
    - `N` is the number of words in the `wordlist`.
    - `Q` is the number of queries.
  - We build the `unordered_set` and `unordered_map` in **O(N)** time.
  - For each query, we perform at most two lookups in the maps (`cap` and `vowel`), both of which are **O(1)** on average due to the properties of hashmaps. Therefore, checking all `Q` queries takes **O(Q)** time.

- **Space Complexity**:
  - The space complexity is **O(N)**, where `N` is the number of words in the `wordlist`. This is because we store all the words in the `unordered_set` and `unordered_map` objects.

### Conclusion

This solution efficiently solves the problem of spellchecking with case-insensitivity and vowel-insensitivity. By leveraging hashmaps and sets, the solution ensures fast lookups for exact matches, case-insensitive matches, and vowel-insensitive matches. The approach is highly optimized for both time and space, with a linear time complexity relative to the number of words and queries. This makes the solution scalable for larger inputs and ensures quick responses even for a large number of queries.

[`Link to LeetCode Lab`](https://leetcode.com/problems/vowel-spellchecker/description/)

---
{{< youtube Twas2VoFXW4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

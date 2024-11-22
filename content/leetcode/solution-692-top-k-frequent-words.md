
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
**Code:**

{{< highlight cpp >}}
using tup_t = tuple<int, string>;
class cmp {
public:
    bool operator() (const tup_t &p1, const tup_t &p2) {
        if(get<0>(p1) == get<0>(p2)) return get<1>(p1) > get<1>(p2);
        else return get<0>(p1) < get<0>(p2);
    }
};

class Solution {
public:
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
};
{{< /highlight >}}
---

### Problem Statement:
The task is to find the **k most frequent words** in a given list of words. If there are ties (i.e., multiple words have the same frequency), return them in **lexicographical order** (i.e., alphabetical order).

To solve this, the function must efficiently track the frequency of each word in the list and then return the `k` most frequent ones in the correct order. The problem requires us to prioritize both the frequency of the words and lexicographical order when frequencies are equal.

### Approach:
To approach this problem, the following steps are executed:

1. **Count the Frequency of Each Word**: 
   Use an **unordered map (hashmap)** to count how often each word appears in the input list.

2. **Use a Custom Comparator with a Priority Queue**:
   - A **priority queue (max-heap)** is used to store words based on their frequencies.
   - Since a max-heap prioritizes larger values, we need to invert this behavior for this problem using a custom comparator.
   - The comparator ensures that the word with the highest frequency is always at the top. If two words have the same frequency, they are ordered lexicographically (alphabetically) in reverse.

3. **Extract the k Most Frequent Words**:
   - After building the heap, the top element of the heap is the most frequent word. We continue popping from the heap until we have extracted `k` words.

4. **Return the Result**:
   - The result is stored in a vector, which is returned at the end.

### Code Breakdown (Step by Step):

#### 1. **Counting Word Frequencies**:
```cpp
unordered_map<string, int> mp;
for(string str: words)
    mp[str]++;
```
- An **unordered_map** is used to store the frequency of each word. The key is the word itself, and the value is the count of how many times the word appears in the input `words` vector.
- As we iterate through each word in the `words` vector, we increase its corresponding frequency in the map.

#### 2. **Custom Comparator for Priority Queue**:
```cpp
using tup_t = tuple<int, string>;

class cmp {
public:
    bool operator() (const tup_t &p1, const tup_t &p2) {
        if(get<0>(p1) == get<0>(p2)) return get<1>(p1) > get<1>(p2);
        else return get<0>(p1) < get<0>(p2);
    }
};
```
- We define a custom comparator class `cmp` that compares pairs of words and their frequencies.
- **`tup_t`** is a tuple where the first element is the frequency (`int`) and the second is the word (`string`).
- The comparator ensures:
  - Words with **higher frequencies** are prioritized (if `get<0>(p1) < get<0>(p2)`).
  - If two words have the **same frequency**, they are ordered in **lexicographical (alphabetical)** order by comparing their string values (`get<1>(p1) > get<1>(p2)`).

#### 3. **Priority Queue Initialization and Population**:
```cpp
priority_queue<tup_t, vector<tup_t>, cmp> pq;
for(auto it: mp) {
    auto tp = make_tuple(it.second, it.first);
    pq.push(tp);
}
```
- We create a **priority queue** `pq` where the elements are tuples of (frequency, word).
- We then iterate through the frequency map `mp` and push each word-frequency pair (tuple) into the priority queue. The priority queue is automatically ordered according to the custom comparator `cmp`, ensuring that the most frequent words appear at the top.

#### 4. **Extracting the k Most Frequent Words**:
```cpp
vector<string> ans;
while(k-- > 0) {
    auto e = pq.top();
    ans.push_back(get<1>(e));
    pq.pop();
}
```
- We initialize an empty vector `ans` to store the result.
- We extract the top `k` elements from the priority queue, which are the most frequent words. Each time we pop an element, we get the word (using `get<1>(e)`) and push it into the `ans` vector.
- The `pq.top()` function gives us the word with the highest frequency, and `pq.pop()` removes it from the queue.

#### 5. **Returning the Result**:
```cpp
return ans;
```
- After extracting the `k` most frequent words, we return the result stored in the vector `ans`.

### Complexity:

#### Time Complexity:
- **Counting Word Frequencies**: Iterating through the `words` array to populate the `unordered_map` takes **O(n)** time, where `n` is the number of words in the input.
- **Building the Priority Queue**: Inserting `m` (number of unique words) elements into the priority queue takes **O(m log m)** time, where `m` is the number of unique words.
- **Extracting k Words**: Extracting the top `k` words from the priority queue takes **O(k log m)** time, where `m` is the number of unique words.
- Thus, the overall time complexity is **O(n + m log m + k log m)**. In the worst case, `m` can be as large as `n`, so the time complexity is approximately **O(n log n)**.

#### Space Complexity:
- The space complexity is **O(m)**, where `m` is the number of unique words in the input list. This is because the main space consumption comes from storing the frequency map and the priority queue, both of which store at most `m` elements.

### Conclusion:
This solution efficiently solves the problem of finding the `k` most frequent words in a list while handling ties using lexicographical ordering. The use of a custom comparator in a priority queue ensures that the solution is both time-efficient and correct, as it respects the required sorting criteria. The algorithm efficiently handles large inputs with a time complexity of **O(n log n)**, where `n` is the size of the input. Additionally, the solution makes use of auxiliary space proportional to the number of unique words in the input.

[`Link to LeetCode Lab`](https://leetcode.com/problems/top-k-frequent-words/description/)

---
{{< youtube jEm_HfkIk9s >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

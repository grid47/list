
+++
authors = ["grid47"]
title = "Leetcode 763: Partition Labels"
date = "2024-08-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 763: Partition Labels in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Two Pointers","String","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/763.webp"
youtube = "B7m8UmZE-vw"
youtube_upload_date="2021-10-26"
youtube_thumbnail="https://i.ytimg.com/vi_webp/B7m8UmZE-vw/maxresdefault.webp"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/763.webp" 
    alt="A string where partitions are made, each partition softly glowing as it is formed."
    caption="Solution to LeetCode 763: Partition Labels Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char, int> mp;
        for(int i = 0; i < s.size(); i++)
            mp[s[i]] = i;
        
        vector<int> res;
        int prv = -1, mx = mp[s[0]];
        for(int i = 0; i < s.size(); i++) {
            mx = max(mx, mp[s[i]]);
            if(i == mx || i == s.size() - 1) {
                res.push_back(i - prv);
                prv = mx;
            }
        }
        return res;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem is to partition a string into as many parts as possible, such that each letter appears in at most one part. The goal is to return the sizes of these parts. The string consists of lowercase English letters.

#### Example:
For the string `s = "abac"`, the partition could be:
- Part 1: "ab"
- Part 2: "ac"

For the string `s = "eccbbbbdec"`, the partitions would be:
- Part 1: "e"
- Part 2: "cc"
- Part 3: "bb"
- Part 4: "b"
- Part 5: "dec"

The objective is to compute the lengths of these partitions and return them.

### Approach

The problem requires us to partition the string such that each character only appears once within each partition. This means that once we have included a character in a partition, the rest of its occurrences must also appear within the same partition. The key insight here is to track the farthest position each character appears and adjust the partitions dynamically.

#### Key Insights:

1. **Tracking the Last Occurrence**: We need to know where the last occurrence of each character is. Once we know this, we can extend the partition to include all instances of the character.

2. **Greedy Partitioning**: As we traverse the string, we need to keep track of the furthest index that any character has appeared up to that point. Once the current index reaches this maximum, we can create a partition.

3. **Efficient Calculation**: The solution involves two passes over the string — one to determine the last occurrence of each character, and another to determine the partitions.

### Code Breakdown (Step by Step)

#### Step 1: Mapping the Last Occurrence of Each Character

```cpp
map<char, int> mp;
for(int i = 0; i < s.size(); i++)
    mp[s[i]] = i;
```

- A `map` (or hash map) is used to store the last index of each character in the string. The key is the character, and the value is the last index where that character appears. We loop through the string and update the map for each character.
  
- This map will allow us to efficiently track the last occurrence of every character in the string.

#### Step 2: Initializing Variables for Partitioning

```cpp
vector<int> res;
int prv = -1, mx = mp[s[0]];
```

- `res`: A vector to store the size of each partition.
- `prv`: This variable keeps track of the starting index of the current partition. Initially, it's set to `-1` because we haven't started the first partition yet.
- `mx`: This variable holds the index of the furthest position that we've seen up to this point. Initially, it is set to the last occurrence of the first character `s[0]`.

#### Step 3: Traversing the String to Form Partitions

```cpp
for(int i = 0; i < s.size(); i++) {
    mx = max(mx, mp[s[i]]);
    if(i == mx || i == s.size() - 1) {
        res.push_back(i - prv);
        prv = mx;
    }
}
```

- The `for` loop traverses each character in the string.
  
- For each character at index `i`, we update `mx` to be the maximum of the current `mx` and the last occurrence of the character `s[i]`. This ensures that `mx` always represents the farthest index that we need to include in the current partition.

- The condition `if(i == mx || i == s.size() - 1)` checks if the current index `i` is equal to the last occurrence of the character (i.e., we have included all instances of this character in the current partition). If so, we:
  - Push the size of the current partition (`i - prv`) into the `res` vector.
  - Update `prv` to `mx`, marking the start of the next partition.

- The partition ends when `i` reaches `mx` or when `i` is the last character in the string (`i == s.size() - 1`).

#### Step 4: Returning the Result

```cpp
return res;
```

- After the loop completes, `res` contains the sizes of the partitions, and the function returns this vector.

### Complexity

#### Time Complexity:
- The time complexity of the solution is **O(n)**, where `n` is the length of the string `s`. This is because:
  - The first loop (to build the map of last occurrences) iterates through the string once.
  - The second loop (to form the partitions) also iterates through the string once.
  
- Each iteration performs constant-time operations (updating the map and comparing indices), so the total time complexity is linear.

#### Space Complexity:
- The space complexity is **O(n)**, where `n` is the number of unique characters in the string (which is at most 26 for lowercase English letters). The `map` stores the last index for each character, and the `res` vector stores the sizes of the partitions.

### Conclusion

This solution efficiently solves the problem of partitioning a string into parts where each letter appears in at most one part. By using a greedy approach to determine the furthest occurrence of each character, the algorithm ensures that each partition contains all instances of the characters it includes.

- **Time Complexity**: **O(n)**, where `n` is the length of the string.
- **Space Complexity**: **O(n)**, where `n` is the number of unique characters in the string.

This solution is both time and space efficient, making it a good fit for large strings, and it ensures that we partition the string optimally. The use of a map to store the last occurrence of each character allows us to dynamically adjust the partition as we traverse the string, ensuring correctness.

[`Link to LeetCode Lab`](https://leetcode.com/problems/partition-labels/description/)

---
{{< youtube B7m8UmZE-vw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

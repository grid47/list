
+++
authors = ["grid47"]
title = "Leetcode 1177: Can Make Palindrome from Substring"
date = "2024-07-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1177: Can Make Palindrome from Substring in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Bit Manipulation","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "tCr-y-1P2J8"
youtube_upload_date="2024-06-27"
youtube_thumbnail="https://i.ytimg.com/vi_webp/tCr-y-1P2J8/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& q) {
        vector<bool> ans;
        
        vector<int> pt(1,0);
        int mask = 0;
        
        for(int i = 0; i < s.length(); i++) {
        pt.push_back(mask ^= 1 << (s[i] - 'a'));
        }
        
        
        for(int i = 0; i < q.size(); i++) {
        
auto &v = q[i];

  
int cnt = __builtin_popcount(pt[v[1]+1] ^ pt[v[0]]);

    ans.push_back(cnt/2 <= v[2]);
        }
        
        return ans;
    }
};
{{< /highlight >}}
---



### Problem Statement
The task is to determine whether a substring of a given string can be rearranged to form a palindrome. For a substring to be rearranged into a palindrome:
1. If its length is even, all characters must appear an even number of times.
2. If its length is odd, exactly one character can appear an odd number of times (the rest must be even).

Given a string `s` and a list of queries, each query specifies a substring defined by two indices and a maximum number of character changes allowed. The goal is to check for each query whether the substring can be rearranged into a palindrome with the allowed changes.

### Approach
The solution uses a bit manipulation technique to efficiently track the character counts and determine if the substring can be rearranged into a palindrome. Here's how it works:
1. **Prefix XOR Mask**: For each character in the string, a bitmask (using integers) keeps track of the parity (even or odd count) of each character's occurrences.
2. **Processing Queries**: For each query, compute the number of characters with odd counts in the specified substring using the precomputed masks. Determine if this number of odd-count characters can be made even using the allowed changes.

### Code Breakdown (Step by Step)

Let's break down the implementation step by step:

```cpp
class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& q) {
        vector<bool> ans;
        
        vector<int> pt(1,0);
        int mask = 0;
```

- **Lines 1-4**: The `Solution` class contains the `canMakePaliQueries` method. It takes a string `s` and a 2D vector of queries `q` as input.
- A vector `ans` is initialized to store the results of each query.
- `pt` is a vector initialized with one element (0), which will hold the prefix masks for the characters in the string.
- The variable `mask` is initialized to zero; this will be used to maintain the parity of character counts.

```cpp
        for(int i = 0; i < s.length(); i++) {
            pt.push_back(mask ^= 1 << (s[i] - 'a'));
        }
```

- **Lines 6-8**: This loop iterates over each character in the string `s`.
- For each character, a bit manipulation operation updates the `mask`. The expression `1 << (s[i] - 'a')` creates a bitmask where the bit corresponding to the character is toggled. The XOR operation (`^=`) toggles the bit, effectively keeping track of the parity of occurrences.
- The updated mask is then pushed into the `pt` vector, which will be used to quickly determine the odd character counts in any substring.

```cpp
        for(int i = 0; i < q.size(); i++) {
            auto &v = q[i];
```

- **Lines 10-12**: This loop processes each query from the vector `q`. The variable `v` is a reference to the current query, which consists of three elements: the start index, the end index, and the allowed number of changes.

```cpp
            int cnt = __builtin_popcount(pt[v[1]+1] ^ pt[v[0]]);
```

- **Line 14**: This line computes the number of odd-count characters in the substring defined by the query.
- The expression `pt[v[1]+1] ^ pt[v[0]]` computes the XOR of the prefix masks at the end and start indices of the substring. This operation yields a mask that represents the character counts in the substring.
- The `__builtin_popcount` function counts the number of set bits (i.e., odd counts) in the resulting mask, giving the count of characters with odd occurrences.

```cpp
            ans.push_back(cnt / 2 <= v[2]);
        }
```

- **Line 15**: The final check determines if the number of odd characters divided by two (since each character can be changed to make pairs) is less than or equal to the allowed changes (`v[2]`). If true, it means the substring can be rearranged into a palindrome under the given constraints.
- The result is pushed into the `ans` vector.

```cpp
        return ans;
    }
};
```

- **Line 17**: The method returns the vector `ans`, which contains the results of all queries.

### Complexity
1. **Time Complexity**: 
   - Building the prefix mask takes \(O(n)\), where \(n\) is the length of the string.
   - Each query is processed in \(O(1)\) due to the prefix masks.
   - Therefore, the total time complexity is \(O(n + m)\), where \(m\) is the number of queries.
  
2. **Space Complexity**: 
   - The space used for the prefix masks is \(O(n)\) and the output vector is \(O(m)\), leading to a total space complexity of \(O(n + m)\).

### Conclusion
The `canMakePaliQueries` function effectively determines whether the specified substrings of a given string can be rearranged into palindromes. By utilizing bit manipulation to track character occurrences, the function processes queries efficiently, achieving optimal time complexity. This approach demonstrates a powerful method for solving character frequency problems in strings and showcases how bitwise operations can simplify complex counting tasks. The solution is robust and efficient, making it suitable for large strings and numerous queries, thus addressing the problem requirements effectively.

[`Link to LeetCode Lab`](https://leetcode.com/problems/can-make-palindrome-from-substring/description/)

---
{{< youtube tCr-y-1P2J8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

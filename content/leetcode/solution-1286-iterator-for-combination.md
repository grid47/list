
+++
authors = ["grid47"]
title = "Leetcode 1286: Iterator for Combination"
date = "2024-07-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1286: Iterator for Combination in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Backtracking","Design","Iterator"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "LzYlG_p1-zs"
youtube_upload_date="2020-08-13"
youtube_thumbnail="https://i.ytimg.com/vi/LzYlG_p1-zs/hqdefault.jpg?sqp=-oaymwEmCOADEOgC8quKqQMa8AEB-AHUBoAC4AOKAgwIABABGH8gEygXMA8=&rs=AOn4CLB17AilTYp_dTSeqhi2A9mL6rGv5g"
+++



---
**Code:**

{{< highlight cpp >}}
class CombinationIterator {
public:
    string str;
    int len;
    vector<string> ans;
    map<int, int> mp;
    void bt(int idx, string &tmp) {
        if(tmp.size() == len) {
            ans.push_back(tmp);
            return;
        }
        if(idx == str.size()) {
            return;
        }
        
        for(int i = idx; i < str.size(); i++) {
            tmp += str[i];
            bt(i + 1, tmp);
            tmp.pop_back();
        }
        
    }
    int idx = 0;
    CombinationIterator(string chars, int len) {
        this->len = len;
        sort(chars.begin(), chars.end());
        str = chars;
        string tmp = "";
        bt(0, tmp);
    }
    
    string next() {
        return ans[idx++];
    }
    
    bool hasNext() {
        if(idx < ans.size()) return true;
        return false;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
{{< /highlight >}}
---



### Problem Statement
The task is to create a class called `CombinationIterator` that generates all possible combinations of a given length from a set of characters. The combinations should be generated in lexicographical order, and the iterator should provide two primary functionalities:
1. Retrieve the next combination with the `next()` method.
2. Check if there are more combinations available with the `hasNext()` method.

For example, given the characters "abc" and a combination length of `2`, the combinations in lexicographical order would be: "ab", "ac", "bc".

### Approach
To achieve this, we can utilize a backtracking algorithm to generate all combinations of the specified length. Here's how the approach works:

1. **Sorting the Input**: We first sort the input string of characters to ensure the combinations are generated in lexicographical order.
2. **Backtracking Function**: We define a recursive backtracking function that constructs combinations by exploring each character's inclusion or exclusion in the current combination.
3. **Storage of Combinations**: All valid combinations are stored in a vector.
4. **Iterator Functionality**: The iterator provides methods to retrieve combinations and check for remaining combinations.

### Code Breakdown (Step by Step)

```cpp
class CombinationIterator {
public:
    string str;
    int len;
    vector<string> ans;
    map<int, int> mp;
```
- **Lines 1-5**: The class `CombinationIterator` is defined, with member variables:
  - `str`: The input string of characters.
  - `len`: The desired length of combinations.
  - `ans`: A vector to hold all valid combinations.
  - `mp`: (not used in the final code but declared here, possibly for future enhancements).

```cpp
    void bt(int idx, string &tmp) {
        if(tmp.size() == len) {
            ans.push_back(tmp);
            return;
        }
        if(idx == str.size()) {
            return;
        }
```
- **Lines 6-13**: The backtracking function `bt` is defined:
  - It takes the current index `idx` and a reference to the temporary string `tmp` that holds the current combination.
  - If the size of `tmp` equals the desired length `len`, the combination is complete and added to `ans`.
  - If `idx` reaches the size of `str`, it returns to backtrack.

```cpp
        for(int i = idx; i < str.size(); i++) {
            tmp += str[i];
            bt(i + 1, tmp);
            tmp.pop_back();
        }
    }
```
- **Lines 14-20**: The loop iterates through the characters starting from `idx`:
  - Each character at index `i` is added to `tmp`.
  - The function calls itself recursively with the next index (`i + 1`), effectively exploring the next level of combinations.
  - After the recursive call, the last character is removed from `tmp` (backtracking) to explore other combinations.

```cpp
    int idx = 0;
    CombinationIterator(string chars, int len) {
        this->len = len;
        sort(chars.begin(), chars.end());
        str = chars;
        string tmp = "";
        bt(0, tmp);
    }
```
- **Lines 21-29**: The constructor initializes the iterator:
  - It sets `len` and sorts `chars` to ensure lexicographical order.
  - The sorted characters are stored in `str`.
  - An empty string `tmp` is initialized, and the backtracking function is called starting from index `0`.

```cpp
    string next() {
        return ans[idx++];
    }
```
- **Lines 30-32**: The `next` method returns the next combination:
  - It returns the combination at the current index `idx` and then increments `idx` for the next call.

```cpp
    bool hasNext() {
        if(idx < ans.size()) return true;
        return false;
    }
};
```
- **Lines 33-37**: The `hasNext` method checks for remaining combinations:
  - It returns `true` if there are more combinations left (i.e., `idx` is less than the size of `ans`); otherwise, it returns `false`.

### Complexity Analysis
1. **Time Complexity**:
   - The overall time complexity for generating combinations is \(O(\binom{n}{k})\), where \(n\) is the number of characters and \(k\) is the combination length. This is because we are generating all possible combinations of length \(k\).
   - Each combination generation can take linear time, hence leading to a total time complexity of \(O(k \cdot \binom{n}{k})\) when considering storage in `ans`.

2. **Space Complexity**:
   - The space complexity is \(O(k \cdot \binom{n}{k})\) due to storing all the combinations in the `ans` vector.
   - Additionally, space is used for the `tmp` string during recursion, but this is limited to the size of `k`, so it can be considered constant with respect to the number of combinations.

### Conclusion
The `CombinationIterator` class effectively generates combinations of a specified length from a set of characters using a backtracking approach. The combination generation ensures that the results are in lexicographical order, and the iterator provides an easy interface for retrieving the next combination and checking for remaining combinations. This implementation is efficient for the problem at hand and demonstrates the power of recursion and backtracking in generating combinatorial structures.

By understanding this class, developers can learn how to implement combination generation and iterator patterns in C++, which can be applied to a variety of problems in algorithm design and competitive programming.

[`Link to LeetCode Lab`](https://leetcode.com/problems/iterator-for-combination/description/)

---
{{< youtube LzYlG_p1-zs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |


+++
authors = ["grid47"]
title = "Leetcode 677: Map Sum Pairs"
date = "2024-08-31"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 677: Map Sum Pairs in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Design","Trie"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/677.webp"
youtube = "GwiKly7UJbQ"
youtube_upload_date="2020-06-20"
youtube_thumbnail="https://i.ytimg.com/vi/GwiKly7UJbQ/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/677.webp" 
    alt="A map where sum pairs are found and highlighted with glowing connections."
    caption="Solution to LeetCode 677: Map Sum Pairs Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class TrieNode {
    vector<TrieNode*> next;
    int sum = 0;
    string s;
public:
    TrieNode() {
        s = "";
        sum = 0;
        next.resize(26, NULL);
    }
    void add(string key, int val) {
        TrieNode* root = this;
        for(int i = 0; i < key.size(); i++) {
            int idx = key[i] - 'a';
            if(root->next[idx] == NULL)
                root->next[idx] = new TrieNode();
            root = root->next[idx];
            root->sum += val;
        }
        root->s = key;
    }
    
    int val(string key) {
        TrieNode* root = this;
        for(int i = 0; i < key.size(); i++) {
            int idx = key[i] - 'a';
            if(root->next[idx] == NULL)
                return 0;
            root = root->next[idx];
        }        
        return root->sum;
    }
};

class MapSum {
    TrieNode* root;
    map<string, int> store;
public:
    MapSum() {
        root = new TrieNode();
    }
    
    void insert(string key, int val) {
        int x = val;
        if(store[key] > 0)
            val = val - store[key];
            
        root->add(key, val);
        store[key] = x;
    }
    
    int sum(string prefix) {
        return root->val(prefix);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
{{< /highlight >}}
---

### Problem Statement:

The problem involves implementing a class `MapSum` which supports two operations efficiently:
1. **`insert(key, value)`**: Inserts a key-value pair into the map. If the key already exists, the new value should replace the old one.
2. **`sum(prefix)`**: Returns the sum of all values associated with keys that start with the given prefix.

The challenge is to provide a solution where both operations are handled in an efficient manner, especially when dealing with large numbers of keys.

### Approach:

To solve this problem efficiently, we need to handle both operations—insert and sum—optimally. A good approach is to use a **Trie (prefix tree)** to store the keys and their associated values. The trie will allow efficient insertion and prefix-based sum calculation. Here's the detailed approach:

1. **Trie Data Structure**: 
   - A **Trie** is a tree-like data structure where each node represents a character in a word. The structure enables fast retrieval of words with common prefixes and allows for efficient insertions.
   - Each node in the Trie will store:
     - A list of child nodes for each character (26 children, one for each lowercase letter).
     - A `sum` field that tracks the sum of all values associated with the keys that pass through or end at this node.
     - A string `s` to keep track of the word associated with the node, which is useful to avoid redundant inserts in case a key is modified.

2. **Insert Operation**:
   - For each key-value pair, insert the key into the Trie character by character. For each character of the key, if the node corresponding to that character does not exist, create a new node. As you traverse the trie, update the `sum` field of each node to reflect the running sum of values for keys that pass through that node.

3. **Sum Operation**:
   - For a given prefix, simply traverse the trie following the characters of the prefix. Once the traversal is complete, the `sum` field of the last node will contain the sum of values for all keys that share this prefix.

4. **Handling Updates (Replacement)**:
   - If a key already exists, subtract the old value from all nodes along its path in the trie and then add the new value. This ensures that the map is updated correctly without needing a full re-insertion.

By using a Trie, we can achieve efficient insertions and prefix sum calculations, both of which are critical for solving the problem within time limits.

### Code Breakdown (Step by Step):

#### Step 1: `TrieNode` Class
```cpp
class TrieNode {
    vector<TrieNode*> next;
    int sum = 0;
    string s;
public:
    TrieNode() {
        s = "";
        sum = 0;
        next.resize(26, NULL);  // Initialize the next vector for 26 characters (a-z)
    }
    void add(string key, int val) {
        TrieNode* root = this;
        for (int i = 0; i < key.size(); i++) {
            int idx = key[i] - 'a';  // Convert char to index (0 for 'a', 1 for 'b', etc.)
            if (root->next[idx] == NULL)
                root->next[idx] = new TrieNode();  // Create a new node if it doesn't exist
            root = root->next[idx];  // Move to the next node
            root->sum += val;  // Update the sum for the current node
        }
        root->s = key;  // Store the key in the leaf node
    }
    
    int val(string key) {
        TrieNode* root = this;
        for (int i = 0; i < key.size(); i++) {
            int idx = key[i] - 'a';  // Convert char to index
            if (root->next[idx] == NULL)
                return 0;  // Return 0 if no prefix is found
            root = root->next[idx];  // Move to the next node
        }
        return root->sum;  // Return the sum at the node corresponding to the prefix
    }
};
```
- The `TrieNode` class represents each node in the Trie.
- It contains a vector of 26 pointers (`next`), representing child nodes for each letter of the alphabet.
- The `sum` field tracks the sum of values for all keys that pass through or end at this node.
- The `add` method inserts a key into the Trie, updating the `sum` values along the path.
- The `val` method calculates the sum of values for all keys starting with the given prefix.

#### Step 2: `MapSum` Class
```cpp
class MapSum {
    TrieNode* root;
    map<string, int> store;  // Stores key-value pairs to track value updates
public:
    MapSum() {
        root = new TrieNode();  // Initialize the root of the Trie
    }
    
    void insert(string key, int val) {
        int x = val;
        if (store[key] > 0)
            val = val - store[key];  // Subtract the old value to ensure correct sum
        root->add(key, val);  // Add the key with the new value to the Trie
        store[key] = x;  // Store the new value in the map
    }
    
    int sum(string prefix) {
        return root->val(prefix);  // Return the sum of values for the given prefix
    }
};
```
- The `MapSum` class manages the Trie (`root`) and a map (`store`) that tracks the most recent value for each key.
- The `insert` method handles inserting a new key-value pair, updating the Trie and the map. If the key already exists, the old value is subtracted before adding the new value to ensure correctness.
- The `sum` method calculates the sum of all values for keys that begin with the given prefix by querying the Trie.

#### Example Usage:
```cpp
MapSum* obj = new MapSum();
obj->insert("apple", 3);  // Insert key "apple" with value 3
int sum1 = obj->sum("ap");  // Query the sum of values for keys starting with "ap" (should return 3)
obj->insert("apple", 2);  // Update key "apple" with value 2
int sum2 = obj->sum("ap");  // Query the sum again after the update (should return 2)
obj->insert("app", 5);  // Insert key "app" with value 5
int sum3 = obj->sum("ap");  // Query the sum (should return 7)
```

### Complexity:

#### Time Complexity:
- **`insert(key, value)`**: The time complexity is `O(L)` where `L` is the length of the key. This is because we traverse each character of the key once to insert it into the Trie and update the sums.
- **`sum(prefix)`**: The time complexity is `O(L)` where `L` is the length of the prefix. We only need to traverse the nodes corresponding to the prefix to get the sum.

#### Space Complexity:
- **`O(N * L)`** where `N` is the number of keys and `L` is the average length of the keys. Each key potentially adds `L` nodes to the Trie, and the map stores `N` key-value pairs.

### Conclusion:

The solution efficiently handles the `insert` and `sum` operations using a Trie data structure. By using the Trie to store prefixes and associated sums, we achieve fast lookups for prefix-based sum queries. The addition of the `store` map ensures that we correctly handle key updates by adjusting the Trie sums when values change. This approach provides optimal time and space complexity for the given problem, making it suitable for large datasets.

[`Link to LeetCode Lab`](https://leetcode.com/problems/map-sum-pairs/description/)

---
{{< youtube GwiKly7UJbQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

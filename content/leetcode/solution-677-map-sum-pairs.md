
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
comments = true
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
Design a map-like data structure that supports key-value insertion and sum queries for keys starting with a specific prefix.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a series of operations on the MapSum object. You will be given a list of operations, where each operation can either insert a key-value pair into the map or request the sum of values for a given prefix.
- **Example:** `["apple", 3], ["ap"]`
- **Constraints:**
	- 1 <= key.length, prefix.length <= 50
	- key and prefix consist only of lowercase English letters.
	- 1 <= val <= 1000
	- At most 50 calls will be made to insert and sum.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output for each operation will be either null (for insert operations) or the result of a sum operation.
- **Example:** `3, 5`
- **Constraints:**
	- The output for insert operations is always null.
	- The sum operation returns an integer value.

{{< dots >}}
### Core Logic 🔍
**Goal:** Efficiently handle insertions and prefix sum queries by storing keys and their corresponding values.

- 1. For insertions, store key-value pairs in a map-like structure.
- 2. For sum queries, efficiently search for all keys starting with the given prefix and sum their values.
{{< dots >}}
### Problem Assumptions ✅
- The map structure will be used efficiently with respect to the number of insertions and sum queries.
{{< dots >}}
## Examples 🧩
- **Input:** `["apple", 3], ["ap"]`  \
  **Explanation:** In this example, the sum of keys starting with 'ap' is just 3 because 'apple' is the only key in the map that starts with 'ap'.

- **Input:** `["apple", 3], ["app", 2], ["ap"]`  \
  **Explanation:** After inserting 'app' with value 2, the sum of keys starting with 'ap' is 5, which is the sum of 'apple' (3) and 'app' (2).

{{< dots >}}
## Approach 🚀
To implement this map-like structure, we will use a trie to store keys and their cumulative values. This allows us to efficiently compute the sum of all values with a given prefix.

### Initial Thoughts 💭
- Trie structures are well-suited for operations involving prefixes.
- We can store each key in the trie, while maintaining cumulative sums along each path to efficiently compute prefix sums.
{{< dots >}}
### Edge Cases 🌐
- If there are no insertions, a sum query should return 0.
- With a large number of insertions and sum queries, the trie structure will help ensure that the operations remain efficient.
- Handle the case where multiple insertions for the same key should overwrite the previous value.
- Ensure that the trie is efficiently implemented to handle up to 50 insert and sum operations.
{{< dots >}}
## Code 💻
```cpp
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
```

This code defines a TrieNode structure and a MapSum class that supports inserting key-value pairs and calculating the sum of values for a given prefix.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	int sum = 0;
	```
	Initialize a variable to store the sum of values for keys stored in the trie.

2. **Variable Initialization**
	```cpp
	string s;
	```
	Initialize a string variable to store the key in the TrieNode.

3. **Access Control**
	```cpp
	public:
	```
	This section defines public methods for the class.

4. **Constructor**
	```cpp
	TrieNode() {
	```
	Constructor to initialize a TrieNode with default values: an empty string and sum set to zero.

5. **Assignment**
	```cpp
	    s = "";
	```
	Assign an empty string to the string variable s in the TrieNode.

6. **Assignment**
	```cpp
	    sum = 0;
	```
	Assign zero to the sum variable to initialize it.

7. **Container Initialization**
	```cpp
	    next.resize(26, NULL);
	```
	Resize the next container (a vector of TrieNode pointers) to hold 26 elements, each initialized to NULL, representing the 26 letters of the alphabet.

8. **Method Definition**
	```cpp
	void add(string key, int val) {
	```
	Define the 'add' method to insert a key and its associated value into the trie.

9. **Pointer Initialization**
	```cpp
	    TrieNode* root = this;
	```
	Initialize a pointer root to point to the current TrieNode instance.

10. **Loop**
	```cpp
	    for(int i = 0; i < key.size(); i++) {
	```
	Iterate over each character in the given key.

11. **Index Calculation**
	```cpp
	        int idx = key[i] - 'a';
	```
	Calculate the index corresponding to the current character in the key.

12. **Condition**
	```cpp
	        if(root->next[idx] == NULL)
	```
	Check if the trie node corresponding to the current character does not exist.

13. **Pointer Initialization**
	```cpp
	            root->next[idx] = new TrieNode();
	```
	If the trie node does not exist, create a new TrieNode and assign it to the corresponding position in the next array.

14. **Pointer Update**
	```cpp
	        root = root->next[idx];
	```
	Move the root pointer to the next trie node.

15. **Sum Update**
	```cpp
	        root->sum += val;
	```
	Add the value to the sum of the current trie node.

16. **Assignment**
	```cpp
	    root->s = key;
	```
	Assign the key to the string variable s in the final trie node.

17. **Method Definition**
	```cpp
	int val(string key) {
	```
	Define the 'val' method to retrieve the sum of values for the given key.

18. **Pointer Initialization**
	```cpp
	    TrieNode* root = this;
	```
	Initialize a pointer root to point to the current TrieNode instance.

19. **Loop**
	```cpp
	    for(int i = 0; i < key.size(); i++) {
	```
	Iterate over each character in the given key.

20. **Index Calculation**
	```cpp
	        int idx = key[i] - 'a';
	```
	Calculate the index corresponding to the current character in the key.

21. **Condition**
	```cpp
	        if(root->next[idx] == NULL)
	```
	Check if the trie node corresponding to the current character does not exist.

22. **Return**
	```cpp
	            return 0;
	```
	Return 0 if the trie node does not exist, meaning the key is not in the trie.

23. **Pointer Update**
	```cpp
	        root = root->next[idx];
	```
	Move the root pointer to the next trie node.

24. **Return**
	```cpp
	    return root->sum;
	```
	Return the sum of values for the given key.

25. **Class Definition**
	```cpp
	class MapSum {
	```
	Define the MapSum class, which uses a TrieNode to implement the insert and sum operations.

26. **Pointer Initialization**
	```cpp
	TrieNode* root;
	```
	Initialize a pointer root to point to a TrieNode.

27. **Container Initialization**
	```cpp
	map<string, int> store;
	```
	Initialize a map to store the key-value pairs.

28. **Constructor**
	```cpp
	public:
	MapSum() {
	```
	Define the constructor for MapSum, which initializes the root pointer to a new TrieNode.

29. **Pointer Initialization**
	```cpp
	    root = new TrieNode();
	```
	Initialize the root pointer to a new TrieNode.

30. **Method Definition**
	```cpp
	void insert(string key, int val) {
	```
	Define the 'insert' method to insert a key-value pair into the map and trie.

31. **Value Adjustment**
	```cpp
	    int x = val;
	```
	Store the current value of the key.

32. **Condition**
	```cpp
	    if(store[key] > 0)
	```
	Check if the key is already in the map and adjust the value.

33. **Value Update**
	```cpp
	        val = val - store[key];
	```
	Adjust the new value by subtracting the old value.

34. **Method Call**
	```cpp
	    root->add(key, val);
	```
	Call the 'add' method of TrieNode to insert the key-value pair into the trie.

35. **Map Update**
	```cpp
	    store[key] = x;
	```
	Update the map with the new value for the key.

36. **Method Definition**
	```cpp
	int sum(string prefix) {
	```
	Define the 'sum' method to calculate the sum of values for all keys starting with the given prefix.

37. **Method Call**
	```cpp
	    return root->val(prefix);
	```
	Call the 'val' method of TrieNode to get the sum for the given prefix.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(k) where k is the length of the key or prefix.
- **Average Case:** O(k) where k is the length of the key or prefix.
- **Worst Case:** O(k) where k is the length of the key or prefix.

Both insert and sum operations take O(k) time, where k is the length of the key or prefix.

### Space Complexity 💾
- **Best Case:** O(n * k) where n is the number of keys and k is the length of the keys.
- **Worst Case:** O(n * k) where n is the number of keys and k is the length of the keys.

The space complexity depends on the number of keys and their lengths, as each key and its associated value are stored in the trie.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/map-sum-pairs/description/)

---
{{< youtube GwiKly7UJbQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

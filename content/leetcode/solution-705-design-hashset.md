
+++
authors = ["grid47"]
title = "Leetcode 705: Design HashSet"
date = "2024-08-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 705: Design HashSet in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Linked List","Design","Hash Function"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/705.webp"
youtube = "VymjPQUXjL8"
youtube_upload_date="2023-05-30"
youtube_thumbnail="https://i.ytimg.com/vi/VymjPQUXjL8/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/705.webp" 
    alt="A set of elements where the hashset design is highlighted, with each element glowing softly in its unique location."
    caption="Solution to LeetCode 705: Design HashSet Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Design a custom HashSet without using any built-in hash table libraries. Implement the MyHashSet class with methods to add, remove, and check the existence of a value.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a set of operations to perform on a custom HashSet. The operations are: add, remove, and contains, each involving a key (an integer).
- **Example:** `Input: ["MyHashSet", "add", "add", "contains", "contains", "add", "contains", "remove", "contains"]
[[], [1], [2], [1], [3], [2], [2], [2], [2]]`
- **Constraints:**
	- 0 <= key <= 10^6
	- At most 10^4 operations will be made on the HashSet.

{{< dots >}}
### Output Specifications 📤
- **Output:** The function should return the results of the operations. If the operation is add or remove, return null. If the operation is contains, return a boolean value (true or false).
- **Example:** `Output: [null, null, null, true, false, null, true, null, false]`
- **Constraints:**
	- The set should handle both insertion and deletion operations efficiently.

{{< dots >}}
### Core Logic 🔍
**Goal:** Design a HashSet that efficiently supports the add, remove, and contains operations using a custom approach.

- 1. Create a HashSet using an array of linked lists (or other structure) to store values.
- 2. Implement the add function to insert a value into the HashSet if it doesn't already exist.
- 3. Implement the remove function to remove a value if it exists in the HashSet.
- 4. Implement the contains function to check if a value exists in the HashSet.
{{< dots >}}
### Problem Assumptions ✅
- The keys in the HashSet are integers within the specified range.
- The operations are done in sequence, and the set is empty at the start.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: ["MyHashSet", "add", "add", "contains", "contains", "add", "contains", "remove", "contains"]
[[], [1], [2], [1], [3], [2], [2], [2], [2]]`  \
  **Explanation:** In this example, we first add 1 and 2 to the HashSet. We check if 1 is present (it is), then check for 3 (it isn't). Adding 2 again doesn't change the set, checking for 2 shows it is present, removing 2 removes it from the set, and checking for 2 afterward shows it isn't present.

{{< dots >}}
## Approach 🚀
We will design the HashSet using an array of linked lists to store the values. The key will be hashed to determine which linked list to check for the presence of the value.

### Initial Thoughts 💭
- The problem requires designing a set with efficient add, remove, and contains operations.
- The HashSet should ideally perform operations in constant time (O(1)) on average.
- We can use the modulo operator to map keys to an index in an array, and handle collisions using linked lists.
{{< dots >}}
### Edge Cases 🌐
- The set is initially empty, so we need to handle that scenario properly when performing operations.
- The HashSet should be efficient even with a large number of operations, so consider the size of the set and collisions.
- The key 0 is a valid input and should be handled correctly.
- Ensure that the HashSet can handle up to 10^6 keys and 10^4 operations efficiently.
{{< dots >}}
## Code 💻
```cpp
//     int val;
//     ListNode* next;
//     ListNode(int val, ListNode* nxt) {
//         this->val = val
//         this->next = nxt;
//     }
// };

class MyHashSet {
public:
int sz = 10000;
vector<ListNode*> lst;
MyHashSet() {
    lst.resize(sz, NULL);
}

void add(int key) {
    int num = key%sz;
    if(lst[num] == NULL) {
        lst[num] = new ListNode(key, NULL);
        return;
    }
    ListNode* cur = lst[num], *prv = NULL;
    while(cur) {
        if(cur->val == key) return;
        prv = cur;
        cur = cur->next;
    }
    prv->next = new ListNode(key, NULL);
}

void remove(int key) {
    int num = key%sz;
    if(lst[num] == NULL) {
        return;
    }
    if(lst[num]->val == key) {
        auto it = lst[num];
        lst[num] = lst[num]->next;
        it->next = NULL;            
        return;
    }
    ListNode* cur = lst[num]->next, *prv = lst[num];
    while(cur) {
        if(cur->val == key) {
            prv->next = cur->next;
            cur->next = NULL;
            return;
        }
        prv = cur;
        cur = cur->next;
    }
}

bool contains(int key) {
    int num = key%sz;
    ListNode* cur = lst[num];
    while(cur) {
        if(cur->val == key) {
            return true;
        }
        cur = cur->next;
    }
    return false;
}
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
```

This code defines a custom hash set (MyHashSet) using an array of linked lists. It implements methods to add, remove, and check if a key is contained in the set.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Class Definition**
	```cpp
	class MyHashSet {
	```
	Begin definition of the MyHashSet class.

2. **Access Specifier**
	```cpp
	public:
	```
	Public access section of the class.

3. **Variable Initialization**
	```cpp
	int sz = 10000;
	```
	Initialize the size of the hash set to 10000.

4. **Data Structure Initialization**
	```cpp
	vector<ListNode*> lst;
	```
	Declare a vector of ListNode pointers to store the linked list chains.

5. **Constructor**
	```cpp
	MyHashSet() {
	```
	Constructor to initialize the hash set.

6. **Vector Resize**
	```cpp
	    lst.resize(sz, NULL);
	```
	Resize the vector to hold 'sz' number of elements, initialized to NULL.

7. **Method Definition**
	```cpp
	void add(int key) {
	```
	Method to add a key to the hash set.

8. **Modular Arithmetic**
	```cpp
	    int num = key%sz;
	```
	Calculate the index in the hash table using modulo operation.

9. **Condition Check**
	```cpp
	    if(lst[num] == NULL) {
	```
	Check if the list at the calculated index is empty.

10. **Memory Allocation**
	```cpp
	        lst[num] = new ListNode(key, NULL);
	```
	Allocate a new ListNode and add it to the list at the calculated index.

11. **Return Statement**
	```cpp
	        return;
	```
	Return if the key was added successfully.

12. **List Traversal**
	```cpp
	    ListNode* cur = lst[num], *prv = NULL;
	```
	Initialize pointers to traverse the linked list at the calculated index.

13. **While Loop**
	```cpp
	    while(cur) {
	```
	Iterate through the linked list at the calculated index.

14. **Condition Check**
	```cpp
	        if(cur->val == key) return;
	```
	If the key already exists, return without adding it.

15. **Pointer Update**
	```cpp
	        prv = cur;
	```
	Move the 'prv' pointer to the current node.

16. **Pointer Update**
	```cpp
	        cur = cur->next;
	```
	Move the 'cur' pointer to the next node in the list.

17. **Node Insertion**
	```cpp
	    prv->next = new ListNode(key, NULL);
	```
	Insert the new key at the end of the list.

18. **Method Definition**
	```cpp
	void remove(int key) {
	```
	Method to remove a key from the hash set.

19. **Modular Arithmetic**
	```cpp
	    int num = key%sz;
	```
	Calculate the index in the hash table using modulo operation.

20. **Condition Check**
	```cpp
	    if(lst[num] == NULL) {
	```
	Check if the list at the calculated index is empty.

21. **End If Condition**
	```cpp
	        return;
	```
	Return if the list is empty, as the key cannot be removed.

22. **Remove Head Node**
	```cpp
	    if(lst[num]->val == key) {
	```
	If the head node contains the key, remove it.

23. **Memory Deallocation**
	```cpp
	        auto it = lst[num];
	```
	Temporary pointer to hold the node to be removed.

24. **Pointer Update**
	```cpp
	        lst[num] = lst[num]->next;
	```
	Update the head of the list to the next node.

25. **Memory Deallocation**
	```cpp
	        it->next = NULL;
	```
	Disconnect the removed node from the list.

26. **Return Statement**
	```cpp
	        return;
	```
	Return after the node is removed.

27. **List Traversal**
	```cpp
	    ListNode* cur = lst[num]->next, *prv = lst[num];
	```
	Initialize pointers to traverse the linked list at the calculated index.

28. **While Loop**
	```cpp
	    while(cur) {
	```
	Iterate through the linked list to find the key.

29. **Condition Check**
	```cpp
	        if(cur->val == key) {
	```
	If the key is found, remove it.

30. **Pointer Update**
	```cpp
	            prv->next = cur->next;
	```
	Remove the key from the list by updating pointers.

31. **Memory Deallocation**
	```cpp
	            cur->next = NULL;
	```
	Disconnect the node to be removed from the list.

32. **Return Statement**
	```cpp
	            return;
	```
	Return after the key is removed.

33. **Pointer Update**
	```cpp
	        prv = cur;
	```
	Move the 'prv' pointer to the current node.

34. **Pointer Update**
	```cpp
	        cur = cur->next;
	```
	Move the 'cur' pointer to the next node.

35. **Method Definition**
	```cpp
	bool contains(int key) {
	```
	Method to check if a key is present in the hash set.

36. **Modular Arithmetic**
	```cpp
	    int num = key%sz;
	```
	Calculate the index in the hash table using modulo operation.

37. **List Traversal**
	```cpp
	    ListNode* cur = lst[num];
	```
	Initialize a pointer to traverse the linked list at the calculated index.

38. **While Loop**
	```cpp
	    while(cur) {
	```
	Iterate through the list to search for the key.

39. **Condition Check**
	```cpp
	        if(cur->val == key) {
	```
	If the key is found, return true.

40. **Return Statement**
	```cpp
	    return false;
	```
	Return false if the key was not found.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1), when the key is directly mapped to an index and there are no collisions.
- **Average Case:** O(1), assuming that the hashing function distributes keys evenly and collisions are rare.
- **Worst Case:** O(n), in the case of many collisions at a particular index in the array.

The time complexity for each operation is O(1) on average, but can degrade to O(n) in the worst case due to hash collisions.

### Space Complexity 💾
- **Best Case:** O(m), where m is the size of the underlying array used for storing the keys.
- **Worst Case:** O(n), where n is the number of elements stored in the set, as the space complexity depends on the number of keys inserted.

The space complexity is linear with respect to the number of keys stored in the HashSet.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/design-hashset/description/)

---
{{< youtube VymjPQUXjL8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

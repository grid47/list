
+++
authors = ["grid47"]
title = "Leetcode 380: Insert Delete GetRandom O(1)"
date = "2024-09-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 380: Insert Delete GetRandom O(1) in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Math","Design","Randomized"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/380.webp"
youtube = "j4KwhBziOpg"
youtube_upload_date="2022-03-16"
youtube_thumbnail="https://i.ytimg.com/vi/j4KwhBziOpg/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/380.webp" 
    alt="A sequence of elements being added or deleted, with each random selection softly highlighted."
    caption="Solution to LeetCode 380: Insert Delete GetRandom O(1) Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Design a data structure that supports three operations: insert, remove, and getRandom. The insert operation adds an element to the set if it is not already present. The remove operation removes an element from the set if it exists. The getRandom operation returns a random element from the set, with each element having an equal probability of being selected.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of multiple function calls, starting with the creation of the RandomizedSet object. The operations 'insert(val)', 'remove(val)', and 'getRandom()' are called sequentially.
- **Example:** `Example input: [[], [1], [2], [2], [], [1], [2], []]`
- **Constraints:**
	- -2^31 <= val <= 2^31 - 1
	- At most 2 * 10^5 calls will be made to insert, remove, and getRandom.
	- There will always be at least one element in the set when getRandom() is called.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is a list of results corresponding to the sequence of operations performed.
- **Example:** `Example output: [null, true, false, true, 2, true, false, 2]`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Use a combination of a list and a hash map to efficiently perform insertions, removals, and random selections in constant time on average.

- Use a list to store elements and a hash map to store their indices for fast access.
- In the insert operation, check if the element already exists. If not, add it to the list and map the value to its index.
- In the remove operation, replace the element to be removed with the last element in the list, update its index in the map, and then pop the last element.
- In the getRandom operation, simply pick a random index from the list.
{{< dots >}}
### Problem Assumptions ✅
- The elements are stored uniquely in the set.
- The set will always have at least one element when getRandom() is called.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: [[], [1], [2], [2], [], [1], [2], []]`  \
  **Explanation:** We track elements in the set, and after each operation, we provide the result for that operation. For example, 'insert(1)' returns true because 1 is inserted, while 'remove(2)' returns false because 2 was not in the set.

- **Input:** `Example 2: [[], [5], [], [10], [5], []]`  \
  **Explanation:** After each operation, the result is either true, false, or a random element from the set.

{{< dots >}}
## Approach 🚀
We use a list to store elements and a hash map to store indices, allowing for O(1) average time complexity for all operations.

### Initial Thoughts 💭
- We need to maintain efficient O(1) time for insert, remove, and getRandom operations.
- A list allows for O(1) time access, while the hash map helps with O(1) element removal and index tracking.
- The key challenge is efficiently handling the removal operation while maintaining the ability to return a random element.
{{< dots >}}
### Edge Cases 🌐
- No empty operations will be allowed as the problem guarantees at least one element when getRandom() is called.
- Ensure the solution works efficiently with up to 2 * 10^5 operations.
- Handle edge cases where the value is at the boundary of the allowed range (-2^31 or 2^31 - 1).
- Ensure O(1) time complexity for each of the operations.
{{< dots >}}
## Code 💻
```cpp
vector<int> a;
unordered_map<int,int> m;
public:
RandomizedSet() {
}
bool insert(int val) {
    if(m.find(val)!=m.end())
        return false;
    else{
        a.push_back(val);
        m[val]=a.size()-1;
        return true;
    }
}

bool remove(int val) {
    if(m.find(val)==m.end())
        return false;
    else{
        int last=a.back(); 
        a[m[val]]=a.back();
        a.pop_back();
        m[last]=m[val];   
        m.erase(val);
        return true;
    }
}

int getRandom() {
    return a[rand()%a.size()];
}
```

This code implements a RandomizedSet class with three functions: insert, remove, and getRandom. It uses an unordered map to store values and a vector to keep track of the order.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	vector<int> a;
	```
	This line initializes a vector `a` to store the values inserted into the set.

2. **Variable Initialization**
	```cpp
	unordered_map<int,int> m;
	```
	This line initializes an unordered map `m` to store each value and its corresponding index in the vector `a`.

3. **Constructor**
	```cpp
	public:
	```
	This marks the beginning of the public section where functions are defined.

4. **Constructor Definition**
	```cpp
	RandomizedSet() {
	```
	This is the constructor for the RandomizedSet class, initializing the data structures.

5. **Insert Function**
	```cpp
	bool insert(int val) {
	```
	This function attempts to insert a value `val` into the set. It returns false if the value already exists, otherwise it inserts the value and returns true.

6. **Conditionals**
	```cpp
	    if(m.find(val)!=m.end())
	```
	This checks if the value already exists in the set by looking it up in the unordered map.

7. **Return Statement**
	```cpp
	        return false;
	```
	If the value already exists, the function returns `false` to indicate the insertion was unsuccessful.

8. **Insert Action**
	```cpp
	    else{
	```
	This marks the beginning of the block of code to execute if the value does not already exist.

9. **Insert Action**
	```cpp
	        a.push_back(val);
	```
	The value is pushed onto the vector `a` to store it.

10. **Insert Action**
	```cpp
	        m[val]=a.size()-1;
	```
	The value is mapped to its index in the vector `a` in the unordered map `m`.

11. **Return Statement**
	```cpp
	        return true;
	```
	If the insertion is successful, the function returns `true`.

12. **Remove Function**
	```cpp
	bool remove(int val) {
	```
	This function attempts to remove a value `val` from the set. It returns false if the value does not exist, otherwise it removes the value and returns true.

13. **Conditionals**
	```cpp
	    if(m.find(val)==m.end())
	```
	This checks if the value exists in the unordered map `m`. If it doesn't exist, the function will return false.

14. **Return Statement**
	```cpp
	        return false;
	```
	If the value does not exist, the function returns `false` to indicate the removal was unsuccessful.

15. **Remove Action**
	```cpp
	    else{
	```
	This marks the beginning of the block of code to execute if the value exists.

16. **Remove Action**
	```cpp
	        int last=a.back(); 
	```
	The last value from the vector `a` is stored in the variable `last`.

17. **Remove Action**
	```cpp
	        a[m[val]]=a.back();
	```
	The last value is moved to the position of the value being removed in the vector.

18. **Remove Action**
	```cpp
	        a.pop_back();
	```
	The last value is removed from the vector `a` after it is moved to the position of the removed value.

19. **Remove Action**
	```cpp
	        m[last]=m[val];   
	```
	The index of the last value is updated in the unordered map `m`.

20. **Remove Action**
	```cpp
	        m.erase(val);
	```
	The value is removed from the unordered map `m`.

21. **Return Statement**
	```cpp
	        return true;
	```
	If the removal is successful, the function returns `true`.

22. **Get Random Function**
	```cpp
	int getRandom() {
	```
	This function returns a random value from the set by selecting a random index from the vector `a`.

23. **Get Random Action**
	```cpp
	    return a[rand()%a.size()];
	```
	A random index is selected from the vector `a`, and the corresponding value is returned.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(1)
- **Worst Case:** O(1)

All operations (insert, remove, getRandom) have an average time complexity of O(1) due to the use of a list and a hash map.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) as we need to store the elements in a list and a hash map, where n is the number of elements in the set.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/insert-delete-getrandom-o1/description/)

---
{{< youtube j4KwhBziOpg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

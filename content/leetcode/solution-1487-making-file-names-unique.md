
+++
authors = ["grid47"]
title = "Leetcode 1487: Making File Names Unique"
date = "2024-06-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1487: Making File Names Unique in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "B9hKZonstN0"
youtube_upload_date="2020-06-21"
youtube_thumbnail="https://i.ytimg.com/vi/B9hKZonstN0/maxresdefault.jpg"
comments = true
+++



---
You are given an array 'names' where each element represents a folder name. You will create folders sequentially at each minute. If a folder with the same name already exists, a suffix of the form '(k)' is added, where k is the smallest positive integer such that the resulting name is unique.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** An array of strings 'names' of size n, where each string represents a folder name.
- **Example:** `names = ["doc", "doc", "img", "doc(1)"]`
- **Constraints:**
	- 1 <= names.length <= 5 * 10^4
	- 1 <= names[i].length <= 20
	- names[i] consists of lowercase English letters, digits, and/or round brackets.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an array of strings where each string is the folder name assigned by the system after the respective minute.
- **Example:** `Output: ["doc", "doc(1)", "img", "doc(1)(1)"]`
- **Constraints:**
	- The returned list must contain n strings, one for each folder name assigned.

{{< dots >}}
### Core Logic 🔍
**Goal:** Create folder names in such a way that they are unique by appending the smallest integer k to the name if necessary.

- 1. Initialize a dictionary to track the frequency of folder names.
- 2. Iterate over the 'names' array.
- 3. If the folder name is already in the dictionary, append '(k)' where k is the smallest integer that makes the name unique.
- 4. Update the dictionary with the new name and continue.
{{< dots >}}
### Problem Assumptions ✅
- The folder names are case-sensitive.
- The suffix '(k)' is always appended to the original name in case of a conflict.
{{< dots >}}
## Examples 🧩
- **Input:** `names = ["doc", "doc", "img", "doc(1)"]`  \
  **Explanation:** The first 'doc' is assigned as 'doc', the second 'doc' gets a suffix '(1)', and so on.

- **Input:** `names = ["file", "file", "file", "image"]`  \
  **Explanation:** The first 'file' is assigned as 'file', the second gets '(1)', the third gets '(2)', and 'image' remains 'image'.

{{< dots >}}
## Approach 🚀
To ensure that folder names are unique, a dictionary is used to track existing names and their frequencies. Whenever a conflict occurs, the smallest integer suffix is added to the name.

### Initial Thoughts 💭
- Using a dictionary to track folder names will help in efficiently checking for conflicts.
- The system needs to append the smallest valid suffix (k) for names that conflict, which can be achieved by incrementing the counter for each name.
{{< dots >}}
### Edge Cases 🌐
- If the input list is empty, the output should also be empty.
- Handle cases where the number of folders is close to the upper limit (50,000).
- Names that include digits or brackets should be processed correctly.
- Ensure the solution is efficient enough to handle the maximum input size.
{{< dots >}}
## Code 💻
```cpp
vector<string> getFolderNames(vector<string>& names) {
    map<string, int> mp;
    
    for(int i = 0; i < names.size(); i++) {
        
        if(mp.count(names[i])) {
            int k = mp[names[i]];
            while(mp.count(names[i] + "(" + to_string(k) + ")")) {
                k++;
                mp[names[i]]++;
            }
            mp[names[i]]++;
            names[i] = names[i] + "(" + to_string(k) + ")";
        }

        mp[names[i]] = 1;
    }
    return names;
}
```

The `getFolderNames` function takes a list of folder names and ensures that each name is unique by appending a number to duplicate folder names. If a folder name already exists, it appends a number in the form of `(k)` until a unique name is found.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Method**
	```cpp
	vector<string> getFolderNames(vector<string>& names) {
	```
	The function starts by accepting a vector of strings, `names`, which contains the folder names. It will modify this vector to ensure all names are unique.

2. **Variable Initialization**
	```cpp
	    map<string, int> mp;
	```
	A map `mp` is initialized to keep track of how many times each folder name appears. The key is the folder name, and the value is the number of times it has been encountered.

3. **Loop**
	```cpp
	    for(int i = 0; i < names.size(); i++) {
	```
	This loop iterates over each folder name in the `names` vector to process it and ensure uniqueness.

4. **Condition**
	```cpp
	        if(mp.count(names[i])) {
	```
	If the current folder name already exists in the map (`mp`), we need to modify the name to make it unique.

5. **Variable Initialization**
	```cpp
	            int k = mp[names[i]];
	```
	The variable `k` is initialized to the current count of the folder name in the map. This will be used to append a unique number to the name.

6. **Loop**
	```cpp
	            while(mp.count(names[i] + "(" + to_string(k) + ")")) {
	```
	This while loop checks if the current name with an appended `(k)` already exists in the map. If it does, we increment `k` to try a higher number.

7. **Variable Increment**
	```cpp
	                k++;
	```
	Increment `k` to try the next possible number in the sequence for the modified folder name.

8. **Map Update**
	```cpp
	                mp[names[i]]++;
	```
	Update the map to increment the count of the original folder name, indicating that we're trying a new modified version of it.

9. **Map Update**
	```cpp
	            mp[names[i]]++;
	```
	After finding a unique name, increment the count of the original folder name in the map.

10. **Modify Name**
	```cpp
	            names[i] = names[i] + "(" + to_string(k) + ")";
	```
	The current folder name is updated by appending `(k)` to it, where `k` is the number that ensures the name is unique.

11. **Map Update**
	```cpp
	        mp[names[i]] = 1;
	```
	If the folder name is new (not encountered before), initialize its count in the map to `1`.

12. **Return**
	```cpp
	    return names;
	```
	Finally, return the modified vector `names`, which now contains unique folder names.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1) for each folder if no conflicts occur.
- **Average Case:** O(n) where n is the number of folders.
- **Worst Case:** O(n * k) where k is the number of suffixes added in the worst case.

The worst case occurs when many folder names conflict, requiring checking multiple suffixes.

### Space Complexity 💾
- **Best Case:** O(n) as we need to store the result array.
- **Worst Case:** O(n) for the space used by the dictionary storing the folder names.

The space complexity is proportional to the number of unique folder names.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/making-file-names-unique/description/)

---
{{< youtube B9hKZonstN0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

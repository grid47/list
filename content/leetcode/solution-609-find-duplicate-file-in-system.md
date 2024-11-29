
+++
authors = ["grid47"]
title = "Leetcode 609: Find Duplicate File in System"
date = "2024-09-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 609: Find Duplicate File in System in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/609.webp"
youtube = "3GP6BA1oXQw"
youtube_upload_date="2021-02-15"
youtube_thumbnail="https://i.ytimg.com/vi/3GP6BA1oXQw/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/609.webp" 
    alt="A computer directory where duplicate files are identified and softly glowing, showing their locations."
    caption="Solution to LeetCode 609: Find Duplicate File in System Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given a list of directory paths, each containing file names and their content, return the groups of duplicate files that have the same content.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** Each string represents a directory path followed by multiple files and their contents in the format 'filename(content)'.
- **Example:** `paths = ["root/x 1.txt(abc) 2.txt(def)", "root/y 3.txt(abc)", "root/y/z 4.txt(def)", "root 5.txt(ghj)"]`
- **Constraints:**
	- 1 <= paths.length <= 2 * 10^4
	- 1 <= paths[i].length <= 3000
	- 1 <= sum(paths[i].length) <= 5 * 10^5
	- paths[i] consist of English letters, digits, '/', '.', '(', ')', and ' '.
	- No two files in the same directory have the same name.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a list of groups of file paths that have identical content.
- **Example:** `[["root/x/1.txt", "root/y/3.txt"], ["root/x/2.txt", "root/y/z/4.txt"]]`
- **Constraints:**
	- The returned list should group files with the same content.
	- Files should be in the order they appear in the input list.

{{< dots >}}
### Core Logic 🔍
**Goal:** Identify and group files that share identical content.

- Parse each directory info to extract file paths and content.
- Use a map to store file contents as keys and their corresponding file paths as values.
- Group file paths that have the same content into a list.
{{< dots >}}
### Problem Assumptions ✅
- File contents are represented as strings enclosed in parentheses.
- File names are unique within a given directory.
{{< dots >}}
## Examples 🧩
- **Input:** `paths = ["root/x 1.txt(abc) 2.txt(def)", "root/y 3.txt(abc)", "root/y/z 4.txt(def)", "root 5.txt(ghj)"]`  \
  **Explanation:** Here, file '1.txt' in 'root/x' and '3.txt' in 'root/y' both have content 'abc', so they are grouped together. Similarly, '2.txt' in 'root/x' and '4.txt' in 'root/y/z' have identical content 'def', so they form another group.

{{< dots >}}
## Approach 🚀
The approach involves mapping file contents to their file paths and grouping files with identical content.

### Initial Thoughts 💭
- Files with identical content should be grouped together regardless of their location.
- A hash map can be used to store and retrieve file content efficiently.
{{< dots >}}
### Edge Cases 🌐
- An empty list of paths.
- Handling large file systems with more than 10^4 paths.
- Files with empty content or unique content.
- Make sure to handle files of different sizes efficiently.
{{< dots >}}
## Code 💻
```cpp
vector<vector<string>> findDuplicate(vector<string>& paths) {
    unordered_map<string, vector<string>> mp;
    vector<vector<string>> result;

    for(auto path: paths) {
        stringstream ss(path);
        string root;
        string s;
        getline(ss, root, ' ');
        while(getline(ss, s, ' ')) {
            string fileName = root + '/' + s.substr(0, s.find('('));
            string fileContent = s.substr(s.find('(') + 1, s.find(')') - s.find('(')-1);
            mp[fileContent].push_back(fileName);
        }
    }

    for (auto file : mp) {
        if(file.second.size() > 1)
        result.push_back(file.second);
    }

    return result;
}
```

This function `findDuplicate` identifies duplicate files based on their content from a list of file paths. It uses a hash map to group file paths by their content and returns a list of file groups with more than one file having the same content.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<vector<string>> findDuplicate(vector<string>& paths) {
	```
	Declares the function `findDuplicate` which takes a reference to a vector of file paths as input and returns a vector of vectors containing duplicate file paths.

2. **Variable Initialization (mp)**
	```cpp
	    unordered_map<string, vector<string>> mp;
	```
	Initializes an unordered map `mp` where the key is the content of a file and the value is a vector of file paths containing that content.

3. **Variable Initialization (result)**
	```cpp
	    vector<vector<string>> result;
	```
	Initializes an empty vector `result` which will store groups of duplicate file paths.

4. **Loop Through Paths**
	```cpp
	    for(auto path: paths) {
	```
	Iterates over each file path in the input `paths` vector.

5. **String Stream Setup**
	```cpp
	        stringstream ss(path);
	```
	Initializes a stringstream `ss` with the current file path `path` to extract the root and file details.

6. **Root String Initialization**
	```cpp
	        string root;
	```
	Declares a string variable `root` to store the root directory of the file.

7. **File String Initialization**
	```cpp
	        string s;
	```
	Declares a string variable `s` to store individual file names and their content.

8. **Extract Root Directory**
	```cpp
	        getline(ss, root, ' ');
	```
	Extracts the root directory (before the first space) from the stringstream and assigns it to `root`.

9. **Loop Through Files in Directory**
	```cpp
	        while(getline(ss, s, ' ')) {
	```
	Iterates over the rest of the file details in the stringstream. Each file is separated by a space.

10. **File Name Extraction**
	```cpp
	            string fileName = root + '/' + s.substr(0, s.find('('));
	```
	Extracts the file name (before the opening parenthesis) and constructs the full file path using the root directory.

11. **File Content Extraction**
	```cpp
	            string fileContent = s.substr(s.find('(') + 1, s.find(')') - s.find('(')-1);
	```
	Extracts the content of the file from within the parentheses.

12. **Store in Map**
	```cpp
	            mp[fileContent].push_back(fileName);
	```
	Stores the file path in the map `mp` under the corresponding file content as the key.

13. **Loop Through Map**
	```cpp
	    for (auto file : mp) {
	```
	Iterates over each entry in the map `mp`, where the key is the file content and the value is a vector of file paths.

14. **Check for Duplicates**
	```cpp
	        if(file.second.size() > 1)
	```
	Checks if there are multiple files with the same content (i.e., a duplicate).

15. **Store Duplicates**
	```cpp
	        result.push_back(file.second);
	```
	Adds the group of duplicate file paths to the `result` vector.

16. **Return Result**
	```cpp
	    return result;
	```
	Returns the vector `result` containing groups of duplicate file paths.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(N)
- **Average Case:** O(N)
- **Worst Case:** O(N)

In the worst case, we may have to process each file and content, so the time complexity is linear in the number of files.

### Space Complexity 💾
- **Best Case:** O(N)
- **Worst Case:** O(N)

The space complexity is also O(N) due to storing file paths and contents in a map.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-duplicate-file-in-system/description/)

---
{{< youtube 3GP6BA1oXQw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

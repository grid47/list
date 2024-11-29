
+++
authors = ["grid47"]
title = "Leetcode 1233: Remove Sub-Folders from the Filesystem"
date = "2024-07-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1233: Remove Sub-Folders from the Filesystem in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String","Depth-First Search","Trie"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "sFv6T_wLS4k"
youtube_upload_date="2021-03-03"
youtube_thumbnail="https://i.ytimg.com/vi_webp/sFv6T_wLS4k/maxresdefault.webp"
comments = true
+++



---
You are given a list of folder paths, where each path represents a folder in the file system. The task is to remove all sub-folders from the list, keeping only the main folders.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a list of folder paths. Each path starts with a '/' and may contain one or more sub-folder paths.
- **Example:** `folders = ['/home/user/docs', '/home/user', '/home/user/docs/photos', '/home/user/music']`
- **Constraints:**
	- 1 <= folder.length <= 4 * 10^4
	- 2 <= folder[i].length <= 100
	- folder[i] contains only lowercase letters and '/'
	- Each folder path is unique

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a list of folder paths with all sub-folders removed.
- **Example:** `["/home/user", "/home/user/music"]`
- **Constraints:**
	- The output should not contain any sub-folder paths.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to remove any folder that is a sub-folder of another folder in the list.

- Sort the folder paths lexicographically.
- Use a trie structure to store and check for sub-folders.
- Add a folder to the result list only if it is not a sub-folder of any other folder.
{{< dots >}}
### Problem Assumptions ✅
- Each folder path starts with a '/' and contains valid characters.
{{< dots >}}
## Examples 🧩
- **Input:** `folders = ['/home/user/docs', '/home/user', '/home/user/docs/photos', '/home/user/music']`  \
  **Explanation:** The folders '/home/user/docs' and '/home/user/docs/photos' are sub-folders of '/home/user', so they are removed. The remaining folders are '/home/user' and '/home/user/music'.

- **Input:** `folders = ['/a/b/c', '/a/b', '/a/c', '/a']`  \
  **Explanation:** The folders '/a/b/c', '/a/b', and '/a/c' are sub-folders of '/a', so only '/a' remains.

{{< dots >}}
## Approach 🚀
To solve this problem, we first sort the folder paths lexicographically and then use a trie data structure to remove sub-folders.

### Initial Thoughts 💭
- Sorting the folder paths lexicographically ensures that sub-folders will appear after their parent folders.
- Using a trie helps efficiently check if a folder is a sub-folder of another.
{{< dots >}}
### Edge Cases 🌐
- Not applicable, as the input will always contain at least one folder.
- The solution should handle up to 40,000 folder paths efficiently.
- Ensure that folder paths are unique, and no folder path starts with an empty string or contains invalid characters.
- The folder paths are guaranteed to be well-formed and unique.
{{< dots >}}
## Code 💻
```cpp
vector<string> removeSubfolders(vector<string>& folder) {

    sort(folder.begin(), folder.end());
    vector<string> ans;
    TrieNode* root = new TrieNode(false);
    for(int i = 0; i < folder.size(); i++) {
        if(root->add(folder[i]))
            ans.push_back(folder[i]);
    }
    return ans;
}
```

This function removes subfolders from a list of folder paths. It uses a Trie to efficiently check if a folder is a subfolder of another.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<string> removeSubfolders(vector<string>& folder) {
	```
	This is the function definition for `removeSubfolders`. It takes a vector of folder paths and returns a vector with subfolders removed.

2. **Sorting**
	```cpp
	    sort(folder.begin(), folder.end());
	```
	The folder paths are sorted in lexicographical order to ensure that the parent folder always appears before its subfolder.

3. **Result Initialization**
	```cpp
	    vector<string> ans;
	```
	An empty vector `ans` is initialized to store the folder paths that are not subfolders of others.

4. **Trie Initialization**
	```cpp
	    TrieNode* root = new TrieNode(false);
	```
	A new TrieNode `root` is created to serve as the root of the Trie. The `false` parameter indicates that this node does not represent the end of a valid folder path.

5. **Iterating Over Folders**
	```cpp
	    for(int i = 0; i < folder.size(); i++) {
	```
	A loop is started to iterate over each folder in the sorted `folder` vector.

6. **Checking for Subfolders**
	```cpp
	        if(root->add(folder[i]))
	```
	The function `add` is called on the root TrieNode to check if the current folder is a subfolder of any previously processed folder. If it is not a subfolder, the folder is added to the result.

7. **Adding to Result**
	```cpp
	            ans.push_back(folder[i]);
	```
	If the folder is not a subfolder, it is added to the `ans` vector, which will be returned at the end.

8. **Return Statement**
	```cpp
	    return ans;
	```
	The function returns the `ans` vector, which contains the folder paths that are not subfolders of any other folder.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The solution primarily depends on sorting the folder paths and checking each folder using the trie structure.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is proportional to the number of folder paths and the trie storage.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/description/)

---
{{< youtube sFv6T_wLS4k >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

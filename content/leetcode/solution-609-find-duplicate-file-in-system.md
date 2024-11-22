
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
**Code:**

{{< highlight cpp >}}
class Solution {
public:
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
};
{{< /highlight >}}
---

### Problem Statement

The problem asks us to identify and return all the duplicate files in a given list of paths. Each path consists of a root directory followed by a list of files in that directory. Each file contains a name and its associated content. Our goal is to return all groups of files that have the same content, indicating that they are duplicates. Each file's content is enclosed in parentheses, and files with the same content should be grouped together in the output.

### Approach

To solve this problem, we need to:
1. Process each path in the input list, extracting file names and their corresponding content.
2. Use a hash map (unordered map) to group file names by their content. The key in the map will be the content, and the value will be a list of file names that share the same content.
3. After processing all the paths, we should filter and return only those content groups that contain more than one file, as these represent the duplicate files.

The approach utilizes the fact that:
- File content is the key differentiator for duplicates.
- A hash map allows efficient grouping and lookup based on content.
- We need to handle the path and file content parsing carefully.

### Code Breakdown (Step by Step)

#### Step 1: Initialize Data Structures
```cpp
unordered_map<string, vector<string>> mp;
vector<vector<string>> result;
```
- We use an unordered map `mp` to store file content as the key and a vector of file paths as the value. This allows us to group files by content.
- `result` is a vector that will store the final list of duplicate files.

#### Step 2: Iterate Through Paths
```cpp
for (auto path : paths) {
    stringstream ss(path);
    string root;
    string s;
    getline(ss, root, ' ');
    while (getline(ss, s, ' ')) {
```
- We iterate through each `path` in the input `paths` list. Each `path` contains a root directory followed by files with names and contents.
- A `stringstream` is used to parse the `path` string, where we first extract the root directory (`root`), and then extract each file (denoted by `s`).

#### Step 3: Parse Each File's Name and Content
```cpp
string fileName = root + '/' + s.substr(0, s.find('('));
string fileContent = s.substr(s.find('(') + 1, s.find(')') - s.find('(') - 1);
```
- For each file string `s`, we:
  - Extract the file name by taking the substring of `s` before the opening parenthesis `(`.
  - Extract the content of the file by taking the substring between the parentheses `()`. This is achieved by finding the positions of `(` and `)` in the string.

#### Step 4: Group Files by Content
```cpp
mp[fileContent].push_back(fileName);
```
- We use the content of the file (`fileContent`) as the key in the map `mp`. The corresponding value is a vector of file names that share this content. If multiple files have the same content, they will be added to the vector for that content key.

#### Step 5: Filter and Collect Duplicate Files
```cpp
for (auto file : mp) {
    if (file.second.size() > 1)
        result.push_back(file.second);
}
```
- After processing all the paths and files, we iterate through the map `mp` and check for entries where the size of the vector (the number of files) is greater than 1. This indicates that these files are duplicates.
- We push all groups of duplicate files into the `result` vector.

#### Step 6: Return the Result
```cpp
return result;
```
- Finally, we return the `result` vector, which contains the groups of duplicate files.

### Complexity

#### Time Complexity:
- **O(N * M)**: 
  - Where `N` is the number of paths in the input list `paths`, and `M` is the average number of files per path.
  - We loop through each path, split it into its root directory and files, and for each file, we extract its content and name. The operations inside the loop (parsing the file name and content, and adding it to the map) take constant time on average.
  - Therefore, the overall time complexity is proportional to the total number of files across all paths.

#### Space Complexity:
- **O(K)**: 
  - Where `K` is the total number of files in all paths, as we store the files in the map `mp`. Each file's name and content are stored in the map, so the space complexity is proportional to the number of files.

### Conclusion

This solution efficiently identifies and groups duplicate files based on their content. The approach leverages hash maps for efficient lookup and grouping, ensuring that we can process each file in constant time. The algorithm handles parsing of file names and contents carefully, ensuring that even files with the same name but different content are correctly treated as separate files. The solution is optimal with respect to both time and space, making it well-suited for handling large inputs efficiently.

[`Link to LeetCode Lab`](https://leetcode.com/problems/find-duplicate-file-in-system/description/)

---
{{< youtube 3GP6BA1oXQw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

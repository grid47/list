
+++
authors = ["grid47"]
title = "Leetcode 2424: Longest Uploaded Prefix"
date = "2024-03-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2424: Longest Uploaded Prefix in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Binary Search","Union Find","Design","Binary Indexed Tree","Segment Tree","Heap (Priority Queue)","Ordered Set"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "8UaltcVnL5E"
youtube_upload_date="2022-10-01"
youtube_thumbnail="https://i.ytimg.com/vi_webp/8UaltcVnL5E/maxresdefault.webp"
comments = true
+++



---
You are given a stream of n distinct videos, each represented by a unique number from 1 to n. You need to design a data structure that tracks the longest prefix of uploaded videos at any point in time. A prefix is considered uploaded if all videos from 1 to i (inclusive) have been uploaded to the server.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two types of operations. The first operation initializes the system with n distinct videos. The second operation uploads a specific video to the server. The third operation returns the length of the longest uploaded prefix.
- **Example:** `LUPrefix(5); upload(4); longest(); upload(2); longest(); upload(1); longest();`
- **Constraints:**
	- 1 <= n <= 10^5
	- 1 <= video <= n
	- All video numbers are distinct.
	- At most 2 * 10^5 operations (upload and longest) will be performed.

{{< dots >}}
### Output Specifications 📤
- **Output:** For each 'longest' operation, return the length of the longest uploaded prefix.
- **Example:** `Output: [null, 0, null, 1, null, 3]`
- **Constraints:**
	- The result should be an integer representing the length of the longest uploaded prefix.

{{< dots >}}
### Core Logic 🔍
**Goal:** Track and return the longest sequence of consecutively uploaded videos starting from 1.

- 1. Maintain an array or set to track which videos have been uploaded.
- 2. For each 'upload' operation, mark the corresponding video as uploaded.
- 3. After each upload, check how many consecutive videos starting from 1 have been uploaded, and update the longest uploaded prefix.
- 4. For 'longest' operations, simply return the length of the current longest prefix.
{{< dots >}}
### Problem Assumptions ✅
- All video numbers are distinct and within the range from 1 to n.
{{< dots >}}
## Examples 🧩
- **Input:** `LUPrefix(5); upload(4); longest(); upload(2); longest(); upload(1); longest();`  \
  **Explanation:** Initially, no videos are uploaded, so the longest prefix is 0. After uploading video 4, no continuous prefix exists, so longest remains 0. After uploading video 2, the longest prefix is still 0, as video 1 hasn't been uploaded yet. Once video 1 is uploaded, the longest prefix becomes [1], and then with videos 1, 2, and 4 uploaded, the longest prefix becomes [1, 2, 3].

{{< dots >}}
## Approach 🚀
We need to design an efficient way to track the longest uploaded prefix after each 'upload' operation.

### Initial Thoughts 💭
- We need to keep track of uploaded videos in a way that allows quick determination of the longest continuous prefix.
- An array or set can be used to mark uploaded videos, and we can keep track of the longest prefix by iterating through uploaded videos starting from 1.
{{< dots >}}
### Edge Cases 🌐
- There will always be at least one 'longest' operation after initialization, so empty inputs won't occur.
- For large inputs, ensure that the algorithm can handle the maximum constraints of 100,000 videos and 200,000 operations.
- Consider cases where the uploaded videos are in a non-sequential order.
- Ensure that the implementation does not exceed time limits, especially for large inputs.
{{< dots >}}
## Code 💻
```cpp
int i;
vector<bool> arr;
LUPrefix(int n) {
    arr.resize(n + 1);
    i = 1;
}

void upload(int vid) {
    arr[vid] = true;
    while(i < arr.size() && arr[i]) i++;
}

int longest() {
    return i - 1;
}
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
```

This code defines the `LUPrefix` class, which manages the upload of videos and keeps track of the longest prefix of videos uploaded.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Declaration**
	```cpp
	int i;
	```
	Declares an integer variable `i` to keep track of the current index of the longest prefix.

2. **Variable Declaration**
	```cpp
	vector<bool> arr;
	```
	Declares a vector of booleans `arr` to store the uploaded videos' status (true if uploaded, false otherwise).

3. **Constructor**
	```cpp
	LUPrefix(int n) {
	```
	Constructor to initialize the `LUPrefix` object with a given number `n` representing the total number of videos.

4. **Constructor Initialization**
	```cpp
	    arr.resize(n + 1);
	```
	Resizes the `arr` vector to accommodate `n+1` elements, ensuring it can hold all video upload statuses.

5. **Constructor Initialization**
	```cpp
	    i = 1;
	```
	Initializes `i` to 1, which indicates the starting index for the longest uploaded video.

6. **Function Definition**
	```cpp
	void upload(int vid) {
	```
	Defines the `upload` function, which updates the video upload status for a specific video `vid`.

7. **Upload Logic**
	```cpp
	    arr[vid] = true;
	```
	Marks the video at index `vid` as uploaded by setting its status to true.

8. **Upload Logic**
	```cpp
	    while(i < arr.size() && arr[i]) i++;
	```
	This loop increments `i` as long as there are uploaded videos, moving through the longest prefix.

9. **Function Definition**
	```cpp
	int longest() {
	```
	Defines the `longest` function, which returns the length of the longest prefix of uploaded videos.

10. **Return Statement**
	```cpp
	    return i - 1;
	```
	Returns the length of the longest prefix of uploaded videos by subtracting 1 from `i`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(1)
- **Worst Case:** O(n)

The time complexity for 'upload' and 'longest' operations is O(1), while initialization takes O(n) to set up the system.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the need to store the state of uploaded videos.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/longest-uploaded-prefix/description/)

---
{{< youtube 8UaltcVnL5E >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |


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
+++



---
**Code:**

{{< highlight cpp >}}
class LUPrefix {
public:
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
 */
{{< /highlight >}}
---

### Problem Statement

The problem requires simulating the process of uploading videos in sequential order and determining the length of the longest continuous sequence of uploaded videos starting from the first one. Specifically, the goal is to efficiently track the longest prefix of uploaded videos in sequential order from `1` to `n` after multiple upload operations.

### Approach

To solve this problem, we can take advantage of the sequential nature of the video uploads. The problem essentially boils down to keeping track of the first missing video from the sequence starting from `1`. Once a video is uploaded, we check whether it completes or extends the longest sequence of videos starting from the first video.

#### Key Observations:
- Each upload either extends the current longest sequence of uploaded videos or doesn't change it.
- The longest sequence of consecutive uploaded videos can be tracked using an index `i` that keeps track of the next expected video. 
- If `i` is the next video that is missing, uploading videos up to `i-1` will complete the sequence.

### Code Breakdown (Step by Step)

#### Step 1: Class Definition and Initialization

```cpp
class LUPrefix {
public:
    int i;
    vector<bool> arr;
    LUPrefix(int n) {
        arr.resize(n + 1);  // Create an array to track uploaded videos
        i = 1;  // Initialize the next expected video to 1
    }
};
```

- The class `LUPrefix` is defined to manage the video upload system.
- `i` is an integer that tracks the next expected video. It starts from 1 because we expect video 1 to be uploaded first.
- `arr` is a boolean vector where each element represents whether a particular video has been uploaded or not. The size of this vector is `n + 1` to accommodate for 1-based indexing (i.e., `arr[1]` represents video 1, `arr[2]` represents video 2, etc.).

#### Step 2: The `upload` Function

```cpp
void upload(int vid) {
    arr[vid] = true;  // Mark the video as uploaded
    while(i < arr.size() && arr[i]) i++;  // Update the next expected video
}
```

- The `upload` function takes an integer `vid`, which represents the ID of the uploaded video.
- It marks the corresponding video in the `arr` array as uploaded by setting `arr[vid] = true`.
- The `while` loop then checks if the next expected video (`i`) has been uploaded. If so, it increments `i` to look for the next video that needs to be uploaded. This loop ensures that `i` always points to the next missing video in the sequence.

#### Step 3: The `longest` Function

```cpp
int longest() {
    return i - 1;  // Return the length of the longest prefix
}
```

- The `longest` function simply returns `i - 1`, which represents the length of the longest continuous sequence of uploaded videos starting from 1.
- This works because the value of `i` represents the next missing video, so `i - 1` gives us the length of the longest continuous sequence.

### Complexity

#### Time Complexity:
- **`O(1)` per `upload` operation**: The `upload` operation is efficient, as it only requires marking a video as uploaded in the array (`arr[vid] = true`) and incrementing the index `i` as necessary. The while loop only runs until the next missing video is found, but in the worst case, it increments `i` a constant number of times (since it only progresses when a new video is uploaded sequentially).
- **`O(1)` per `longest` operation**: The `longest` function simply returns the value of `i - 1`, which is a constant time operation.

#### Space Complexity:
- **`O(n)`**: The space complexity is determined by the size of the array `arr`, which is `n + 1` to track the status of all videos from 1 to `n`. Therefore, the space complexity is linear in terms of the number of videos `n`.

### Conclusion

The solution efficiently tracks the longest sequence of uploaded videos using an array and a simple index. The key insight is recognizing that we don't need to check the entire sequence of videos each time we upload one. Instead, we maintain a pointer (`i`) to track the next expected video and update it when new videos are uploaded sequentially.

This approach allows both the `upload` and `longest` operations to be performed in constant time, making it highly efficient even for large input sizes. The space complexity is also optimal, as we only need to store the upload status for each video.

The solution is ideal for scenarios where videos are uploaded in a sequence, and we need to efficiently track the longest contiguous sequence of uploaded videos.

[`Link to LeetCode Lab`](https://leetcode.com/problems/longest-uploaded-prefix/description/)

---
{{< youtube 8UaltcVnL5E >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |

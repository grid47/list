
class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int idx = -1, n = arr.size();
        for(int i = n - 1; i > 0; i--) {
            // cout<< arr[i] << " " << arr[i - 1] << '\n';
            if(arr[i] < arr[i - 1]) {
                idx = i - 1;
                break;
            }
        }
        // cout << idx;
        if(idx == -1) return arr;

        for(int i = n - 1; i > idx; i--) {
            if(arr[i] < arr[idx] && arr[i] != arr[i - 1]) {
                swap(arr[i], arr[idx]);
                break;
            }
        }
        return arr;
    }
};
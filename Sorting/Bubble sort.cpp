#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n^2) in worst and average case, O(n) in best case (already sorted array)
// Space Complexity: O(1)

class Solution {
  public:
    void bubbleSort(vector<int>& arr) {
        int n = arr.size();
        
        // Loop runs from end towards start, placing largest elements at correct positions
        for (int i = n - 1; i > 0; i--) {
            int didSwap = 0; // to check if any swapping happened
            
            // inner loop compares adjacent elements
            for (int j = 0; j <= i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    // swapping if elements are out of order
                    int temp = arr[j + 1];
                    arr[j + 1] = arr[j];
                    arr[j] = temp;
                    didSwap = 1;
                }
            }
            
            // if no swaps in this pass, array is already sorted
            if (didSwap == 0) {
                break;
            }
        }
    }
};

int main() {
    Solution obj;
    int n;
    cin >> n; 
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i]; 
    
    obj.bubbleSort(arr); // calling bubble sort
    
    for (int i = 0; i < n; i++) cout << arr[i] << " "; // printing sorted array
    cout << endl;
    
    return 0;
}

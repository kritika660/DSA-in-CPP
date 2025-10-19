#include <iostream>
#include <vector>
using namespace std;

bool isPossible(vector<int>& arr, int n, int m, int mid){
    int studentCount = 1, pageSum = 0;

    for(int i = 0; i <n ; i++){
        if (arr[i] > mid) return false;

        if(pageSum + arr[i] <= mid){
            pageSum += arr[i];
        }else{
            studentCount++;
            if(studentCount > m)return false;
            pageSum = arr[i];
        }
    }

    return true;
}

int findPages(vector<int>& arr, int n, int m) {
    /*
        1. vector<int> arr;
        2. arr[i] -> number of pages exist in the book
        3. ther are m students

        -> task is to allocate all the books to the student, find a possible solutio
    */
    if (m > n) return -1;

    int s = 0, sum = 0;
    for(int i = 0; i <n ; i++){
        sum += arr[i];
    }
    // sum = accumulate(arr.begin(), arr.end(), 0);
    int e = sum, ans = -1, mid;

    while(s <= e){
        mid = s + (e - s)/2;
        if(isPossible(arr, n, m, mid)){
            ans = mid;
            e = mid - 1;
        }else{
            s = mid + 1;
        }
    }
    return ans;
}


int main(int argc, char* argv[]) {

    vector<int> arr = {10, 20, 30, 40, 50};
    cout << "Answer: " << findPages(arr, 5, 2) << endl;
}   
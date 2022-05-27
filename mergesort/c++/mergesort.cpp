#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

void print(vector<int>& vec) {
    string res;
    for(const auto &num : vec) {
        if(&num != &vec[0])
            res += ", ";
        res += to_string(num);
    }
    cout << res << "\n";
}

vector<int> merge(vector<int>& left, vector<int>& right) {
    int leftPtr = 0, rightPtr = 0;
    vector<int> mergedList;
    mergedList.reserve(left.size() + right.size());

    while(leftPtr < left.size() || rightPtr < right.size()) {
        int leftNum = INF, rightNum = INF;

        if(leftPtr < left.size())
            leftNum = left[leftPtr];

        if(rightPtr < right.size())
            rightNum = right[rightPtr];
        mergedList.push_back(min(leftNum, rightNum));

        if(leftNum < rightNum)
            leftPtr++;
        else
            rightPtr++;
    }

    return mergedList;
}

vector<int> mergesort(vector<int>& list) {
    if(list.size() <= 1) {
        return list;
    }

    vector<int> left(list.begin(), list.begin() + list.size()/2 );
    vector<int> right(list.begin() + list.size()/2, list.end());

    left = mergesort(left);
    right = mergesort(right);

    vector<int> resultList = merge(left, right);
    return resultList;
}


int main() {

    vector<int> list{2, 8, 5, 3, 9, 4, 1, 7};
    cout << "before sorting:" << "\n";
    print(list);


    cout << "\nafter sorting:" << "\n";
    list = mergesort(list);
    print(list);

    return 0;
}
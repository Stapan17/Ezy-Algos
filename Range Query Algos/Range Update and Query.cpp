#include<bits/stdc++.h>
using namespace std;

const int N = 100000;

int arr[N];
int segTree[4*N];

// Building Segment Tree
void buildTree(int index, int start, int end) {
    
    // leaf node
    if(start == end) {
        segTree[index] = arr[start];
        return;
    }

    int mid = (start + end) / 2;

    // building left tree
    buildTree(2 * index, start, mid);
    
    // building right tree
    buildTree(2 * index + 1, mid + 1, end);

    // each node in segment tree contains sum of its childs
    segTree[index] = segTree[2 * index] + segTree[2 * index + 1];
}

// Updating Segment Tree
// Update Query: add val to every value from idx l to r
void updateTree(int index, int start, int end, int l, int r, int val) {

    // outside of the given range
    if(start > end or start > r or end < l) {
        return;
    }

    // leaf node
    if(start == end) {
        arr[start] += val;
        segTree[index] += val;
        return;
    }

    int mid = (start + end) / 2;

    // will update both the sides depending upon l and r
    updateTree(2 * index, start, mid, l, r, val);
    updateTree(2 * index + 1, mid + 1, end, l, r, val);

    // updating parent beacause childs may get updated
    segTree[index] = segTree[2 * index] + segTree[2 * index + 1];
}

// Quering Segment Tree
// Give me sum of values at l to r indexes
int queryTree(int index, int start, int end, int l, int r) {

    // no overlap, either side
    if(r < start or end < l)
        return 0;

    // complete overlap, in between
    if(l <= start and end <= r)
        return segTree[index];

    // partial overlap, quering both side 
    int mid = (start + end) / 2;

    int left = queryTree(2 * index, start, mid, l, r);
    int right = queryTree(2 * index + 1, mid + 1, end, l, r);

    return (left + right);

}

// we can also merge build and update function both are identical
int main() {

    int n;
    cin >> n;

    for(int i=0; i<n; i++)
        cin >> arr[i];

    int query;
    cin >> query;

    while(query--) {
        char operation;
        cin >> operation;

        int l, r;
        cin >> l >> r;

        if(operation == 'U') {
            int val;
            cin >> val;

            updateTree(1, 0, n-1, l-1, r-1, val);
        }
        else {
            int ans = queryTree(1, 0, n-1, l, r);
            cout << ans << "\n";
        }
    }

    return 0;
}

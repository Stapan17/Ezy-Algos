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
// Update Query: change val at idx 
void updateTree(int index, int start, int end, int idx, int val) {

    // leaf node
    if(start == end) {
        arr[idx] = val;
        segTree[index] = val;
        return;
    }

    int mid = (start + end) / 2;

    // will go left subtree if the idx of val is between start and mid otherwise right
    if(start <= idx and idx <= mid)
        updateTree(2 * index, start, mid, idx, val);
    else
        updateTree(2 * index + 1, mid + 1, end, idx, val);

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

        if(operation == 'U') {
            int idx, val;
            cin >> idx >> val;

            updateTree(1, 0, n-1, idx-1, val);
        }
        else {
            int l, r;
            cin >> l >> r;

            int ans = queryTree(1, 0, n-1, l, r);
            cout << ans << "\n";
        }
    }

    return 0;
}

#include<bits/stdc++.h>
using namespace std;

const int N = 100000;

int arr[N];
int segTree[4*N];
int lazy[4*N];

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

void applyUpdate(int index, int start, int end) {
    segTree[index] += (end - start + 1) * lazy[index];

    if(start != end) {
        lazy[2 * index] += lazy[index]; 
        lazy[2 * index + 1] += lazy[index];
    }
    lazy[index] = 0;
}

// Updating Segment Tree
// Update Query: change val at idx 
void updateTree(int index, int start, int end, int l, int r, int val) {

    // current index we are processing has some pending updates
    // then will first apply those updates
    // and make theirs childs as lazy
    if(lazy[index] != 0)
        applyUpdate(index, start, end);

    // no overlap, completely outside
    if(start > end or start > r or end < l) 
        return;

    // full overlap
    if(start >= l and end <= r) {
        segTree[index] += (end - start + 1) * val;

        // not leaf node
        // then will mark its childs as lazy
        // as updation on them is remaining
        if(start != end) {
            lazy[2 * index] += val;
            lazy[2 * index + 1] += val;
        }
        return;
    }

    int mid = (start + end) / 2;
    updateTree(2 * index, start, mid, l, r, val);
    updateTree(2 * index + 1, mid + 1, end, l, r, val);

    segTree[index] = segTree[2 * index] + segTree[2 * index + 1];
}

// Quering Segment Tree
// Give me sum of values at l to r indexes
int queryTree(int index, int start, int end, int l, int r) {

    // no overlap, either side
    if(start > end or r < start or end < l)
        return 0;

    if(lazy[index] != 0)
        applyUpdate(index, start, end);

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

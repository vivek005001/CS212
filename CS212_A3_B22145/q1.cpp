#include <bits/stdc++.h>
using namespace std;

void buildSegTree(vector<int> &arr, int v, int tl, int tr, vector<int> &t)
{
    if (tl == tr)
    {
        t[v] = arr[tl];
    }
    else
    {
        int tm = (tl + tr) / 2;
        buildSegTree(arr, v * 2, tl, tm, t);
        buildSegTree(arr, v * 2 + 1, tm + 1, tr, t);
        t[v] = 0;
    }
}

void increment(int v, int tl, int tr, int l, int r, int add, vector<int> &t)
{
    if (l > r)
    {
        return;
    }
    if (l == tl && r == tr)
    {
        t[v] += add;
    }
    else
    {
        int tm = (tl + tr) / 2;
        increment(v * 2, tl, tm, l, min(r, tm), add, t);
        increment(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, add, t);
    }
}

int get(int v, int tl, int tr, int pos, vector<int> &t)
{
    if (tl == tr)
    {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm)
    {
        return t[v] + get(v * 2, tl, tm, pos, t);
    }
    else
    {
        return t[v] + get(v * 2 + 1, tm + 1, tr, pos, t);
    }
}

void update(int v, int tl, int tr, int pos, int val, vector<int> &t)
{
    if (tl == tr)
    {
        t[v] = val;
    }
    else
    {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
        {
            update(v * 2, tl, tm, pos, val, t);
        }
        else
        {
            update(v * 2 + 1, tm + 1, tr, pos, val, t);
        }
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> store(n);
    vector<int> t(4 * n);
    vector<int> out;

    for (int j = 0; j < n; j++)
    {
        int t;
        cin >> store[j];
    }

    buildSegTree(store, 1, 0, n - 1, t);
    vector<string> operand;

    for (int i = 0; i < k; i++)
    {
        char s;
        cin >> s;
        if (s == 'G')
        {
            int pos;
            cin >> pos;
            int ans = get(1, 0, n - 1, pos - 1, t);
            out.push_back(ans);
        }
        else if (s == 'I')
        {
            int l, r, add;
            cin >> l >> r >> add;
            increment(1, 0, n - 1, l - 1, r - 1, add, t);
        }
        else if (s == 'U')
        {
            int pos, val;
            cin >> pos >> val;
            update(1, 0, n - 1, pos - 1, val, t);
        }
    }

    for (auto i : out)
    {
        cout << i << " "; 
    }

    return 0;
}

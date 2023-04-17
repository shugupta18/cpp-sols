#include <bits/stdc++.h>
#include <iostream>
#include <limits.h>
#include <vector>
//#include "customTree.h"
//#include "customLL.h"

using namespace std;

#define MOD 1000000007
#define vi vector<int>
#define vb vector<bool>
#define pb push_back
#define vpii vector<pair<int, int>>
#define vvi vector<vector<int>>
#define vvb vector<vector<bool>>
#define ll long long
#define F first
#define S second
#define ii int, int
#define pii pair<int, int>
#define SIZE(arr) (sizeof(arr)/sizeof(arr[0]))
#define max3_(a, b, c) (max(a, max(b, c)))
#define min3_(a, b, c) (min(a, min(b, c)))
#define addMod(a, b) (int)( (ll)(a)%MOD + (b)%MOD )%MOD
#define prdMod(a, b) (int)( (ll)(a)%MOD * (b)%MOD )%MOD
#define repIt(it, v) for(auto it=v.begin(); it!=v.end(); it++)
#define rep(i, a, b) for(i=a; i<b; i++)
#define rep_(i, a, b) for(int i=a; i<b; i++)
#define repr(i, b, a) for(i=b; i>=a; i--)
#define repr_(i, b, a) for(int i=b; i>=a; i--)
#define MIN INT_MIN
#define MAX INT_MAX
#define INF 0x3f3f3f3f
#define umap unordered_map

//template <typename T>
//void printVec(T v)
//{
//    for(auto i=v.begin(); i!=v.end(); i++) {
//        cout << *i << " ";
//    }
//    cout << endl;
//}
//
//template <typename T>
//void printMat (vector<vector<T>>& v)
//{
//    int n = v.size();
//    if (!n) return;
//    int m = v[0].size();
//    for (int i=0; i<n; i++){
//        for (int j=0; j<m; j++)
//            cout << v[i][j] << " ";
//        cout << endl;
//    }
//}
//
//int powMod(int a, int b, int c)
//{
//    int res = 1;
//    a = a%c;
//    while(b)
//    {
//        if(b & 1) res = (res*a)%c;
//        a = (a*a)%c;
//        b >>= 1;
//    }
//    return res;
//}
//
//bool compare(pii a, pii b)
//{
//    return a.F != b.F ? a.F < b.F : a.S < b.S;
//}
//
//// solve the questions
//
//void matrixDS ()
//{
////    vvi v ={{2, 1, 4, 3},
////     {1, 2, 3, 2},
////     {3, 6, 2, 3},
////     {5, 2, 5, 3}};
////    int r = distinct(v, 4);
////    cout << r << endl;
//}
//
//void arrayDS()
//{
////    vi v = {1, 5, 4, 3, 2};
////    int n = v.size();
////    minSwaps(v);
////    int r = minSwaps(v);
////    cout << r << endl;
////    vi r = subarraySum(v, n, t);
////    printVec(r);
////    return;
//}
//
//void linkedListDS()
//{
////    Node *head=NULL, *tail=NULL;
////    pushBack(head, tail, 1);
////    pushBack(head, tail, 2);
////    pushBack(head, tail, 3);
////    pushBack(head, tail, 4);
////    pushBack(head, tail, 5);
////    pushBack(head, tail, 6);
////    printLL(head);
////
////
////
////    Node* r = removeAllDuplicates(head);
////    printLL(r);
////    return;
//}
//
//void binaryTreeDS()
//{
//
//}
//
//int reverse(int x)
//{
//    ll res = 0;
//    while(x)
//    {
//        res = res*10 + x%10;
//        cout << res << endl;
//        x = x/10;
//
//        if(res<MIN || MAX<res) return 0;
//    }
//
//    return (int)res;
//}
//
//void algoDP()
//{
//    vi v = {1 ,2, 3, 4, 5};
//    printVec(v);
////    vi v = {5, 2, 6, 1};
////
////    set<int, greater<int>> st;
////    rep_(i, 0, 4)
////        st.insert(v[i]);
////    while(!st.empty())
////    {
////        int t = *st.begin(); st.erase(st.begin());
////        cout << t << " ";
////    }
////    cout << endl;
////    printVec(res);
//}

//int findIndex(vi &v, int k)
//{
//    int n = v.size();
//    if(!n) return -1;
//    if(k<v[0] || k>v[n-1]) return -1;
//    int l=0, h=n-1, mid=0;
//
//    while(l<h)
//    {
//        mid = l + (h-l)/2;
//        if(v[mid] == k)
//        {
//            if(mid-1>=0 && v[mid-1]==k) h = mid-1;
//            else return mid;
//        }
//        else if(v[mid] < k)
//            l = mid+1;
//        else if(k < v[mid])
//            h = mid-1;
//    }
//
//    return v[l] == k ? l : -1;
//}

int maxPlat(vector<int> a, vector<int> d)
{
    int n = a.size();
    if(d.size() != n) return -1;
    if(!n) return 0;
    int res=1, cnt=1;
    set<pii> st;

    for(int i=0; i<n; i++)
    {
        st.insert(pii(a[i], 0)); // arrival
        st.insert(pii(d[i], 1)); // departure
    }

    while(!st.empty())
    {
        pii t = *st.begin();
        st.erase(st.begin());

        if(t.second==0)     // arrival
        {
            if(cnt>0)
                cnt--;
            else
            {
                res++;
                cnt=0;
            }
        }
        else // departure
            cnt++;
    }
    return res;
}

long long func(int n, int x, int y)
{
    if(y > n-x+1) return -1;
    long long res = 0;
    res += (x*(x+1))/2 + x*(y-1) + ((y-2)*(y-1))/2;
    return res;
}

int maxLen(vector<int> v)
{
    int n = v.size();
    if(!n || n==1) return 0;
    int i=0;
    int res = 0;
    long long s = 0;
    unordered_map<long long, int> mp;
    for(i=0; i<n; i++)
    {
        if(v[i] == 0) s += -1;
        else s += 1;
        if(mp.find(s) != mp.end()) // s is present in mp
            res = max(res, i-mp[s]);
        else
            mp[s] = i;
    }

    return res;
}


pair<int, int> findIndices(vector<int> vec, int t)
{
    int n = vec.size();
    if(!n || n==1) return pair<int, int>(-1, -1);
    pair<int, int> res;
    int l=0, h=n-1, i=0;
    int s = 0;
    int diff = INT_MAX;
    vector<pii> v;

    for(i=0; i<n; i++) v.pb({vec[i], i});
    sort(v.begin(), v.end()); // on the base of value

    while(l<h)
    {
        s = v[l].F+v[h].F;
        if( abs(t-s) < diff )
        {
            res.F=v[l].S, res.S=v[h].S;
            diff = abs(t-s);
        }
        if(s<t) l++;
        else if(s == t) return res;
        else h--;
    }

    return res;
}

int findParent(vector<int> &par, int u)
{
    if(par[i] == i) return i;
    return par[i] = findParent(par, par[i]);
}

void doUnion(vector<int> &par, vector<int> &rnk, int u, int v)
{
    int x = findParent(par, u);
    int y = findParent(par, v);

    if(rnk[x] < rnk[y])
        par[y] = x;
    else if(rnk[x] > rnk[y])
        par[x] = y;
    else {
        par[y] = x;
        rnk[x]++;
    }
    return;
}

int findMST(int n, vector<pair<int, pii> e) // weight {v1, v2}
{
    if(!e.size()) return 0;
    sort(e.begin(), e.end());

    int i=0, sz=e.size();
    int w=0, u=0, v=0;
    int res =0;
    vector<int> par(n, 0);
    vector<int> rnk(n, 1);
    for(i=0; i<n; i++) par[i] = i;

    for(i=0; i<sz; i++)
    {
        w = e.F, u=e.S.F, v=e.S.S;
        if(findParent(par, u) != findParent(par, v))
        {
            doUnion(par, rnk, u, v);
            res += w;
        }
    }
    return res;
}




int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    int target = 10;
    pair<int, int> res = findIndices(v, target);
    cout << res.F << " " << res.S << endl;
//    vector<int> arr = {900, 940, 950, 1100, 1120, 1500, 1800};
//    vector<int> dep = {910, 1200, 1120, 1130, 1135, 1900, 2000};
//    int res = maxPlat(arr, dep);
//    cout << res << endl;
//    vector<vector<int>> mat = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
//    int res minSteps(mat);
//    cout << res << endl;
    return 0;
}

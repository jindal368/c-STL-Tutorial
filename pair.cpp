#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;

void pairExplain()
{
    pair<int, pair<int, int>> p = {1, {5, 9}};
    cout << p.first << " " << p.second.second;
    pair<pair<int, int>, pair<int, int>> p2 = {{1, 3}, {2, 4}};
    cout << p2.first.first << " " << p2.first.second << " " << p.second.second << " " << p.second.first;
}

void vectorsExplain()
{
    vector<int> v; //{empty vector
    v.push_back(1);
    v.emplace_back(2);

    vector<pair<int, int>> vec;
    vec.push_back({2, 4});
    vec.emplace_back(3, 6);

    vector<int> v3(5, 100);

    vector<int> v4(v3);
    for (auto it = v3.begin(); it != v3.end(); it++)
    {
        cout << *(it) << " ";
    }
    auto it2 = v.end();
    cout << *(it2) << " last element : " << v.back();

    v.erase(v.begin()); // remove data from vector

    // remove data from range
    v3.erase(v3.begin() + 1, v3.begin() + 4);

    v3.insert(v3.begin(), 1000);
    v3.insert(v3.begin() + 1, 2, 10);
    //insert entire vector into another vector
    for (auto it = v3.begin(); it != v3.end(); it++)
    {
        cout << *(it) << "\n";
    }
    cout << "\n";
    vector<int> c(2, 50);
    v3.insert(v3.begin(), c.begin(), c.end());

    for (auto it = v3.begin(); it != v3.end(); it++)
    {
        cout << *(it) << "\n";
    }
    cout << v3.size();

    v3.pop_back();

    v3.swap(v);

    v3.clear();

    cout << v3.empty();
}

void explainStack()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    cout << st.top();

    st.pop();
    cout << st.size();
    cout << st.empty(); //return boolean

    stack<int> st1;
    st1.push(1);
    cout << "before swap\n";
    cout << "ST : top :" << st.top();
    cout << "\nST1: top :" << st1.top();
    st1.swap(st);
    cout << "\nAfter swap";
    cout << "\nST : top :" << st.top();
    cout << "\nST1: top :" << st1.top();
}
void explainQueue()
{
    queue<int> q1;
    q1.push(1);
    q1.push(2);
    q1.emplace(3);
    cout << q1.back() << "\n";
    q1.back() += 5;
    cout << "Laast element afetr increment upto 5 : " << q1.back();

    cout << "\n"
         << q1.front();
    q1.pop(); // pop from starting

    cout << "\nfirst element after pop : " << q1.front();
}

void explainPriorityQueue()
{
    //nothing but a max or min heap
    priority_queue<int> pq;
    // by default store value as max heap i.e, descending order..
    pq.push(6);
    pq.push(16);
    pq.push(116);
    pq.push(36);
    pq.push(0);

    cout << "top of Pq : " << pq.top();
    pq.pop();

    cout << "\n After pop top of stack : " << pq.top();

    //minimum heap........
    priority_queue<int, vector<int>, greater<int>> pq2;
    pq2.push(100);
    pq2.push(10);
    pq2.push(60);
    pq2.push(80);
    pq2.push(0);

    cout << "\n Top of PQ2 : " << pq2.top();

    pq2.pop();

    cout << "\n after pop top of PQ2 : " << pq2.top();
}

void explainSet()
{
    set<int> st;
    st.insert(1);
    st.insert(2);
    st.insert(2);
    st.insert(3);
    st.insert(4);
    st.insert(5);
    st.insert(6);
    cout << "Set st : ";
    for (auto it = st.begin(); it != st.end(); it++)
    {
        cout << *(it) << " ";
    }
    auto it1 = st.find(6);
    cout << *(it1);

    st.erase(it1); // it taks constant time......
    st.erase(6);   // it takes log(N) time ....
    cout << "\nSet st After erase 6 : ";
    for (auto it = st.begin(); it != st.end(); it++)
    {
        cout << *(it) << " ";
    }
    //erase range of vakues in constant time ..
    auto it2 = st.find(2);
    auto it3 = st.find(5);
    st.erase(it2, it3);

    cout << "\nAfter erase range of elements : ";
    for (auto it = st.begin(); it != st.end(); it++)
    {
        cout << *(it) << " ";
    }
    st.insert(7);
    st.insert(8);
    st.insert(10);
    st.insert(70);
    st.insert(57);
    auto itUpper = st.upper_bound(57);
    auto itLower = st.lower_bound(8);

    cout << "\n Lower bound : " << *(itLower);
    cout << "\n Upper bound : " << *(itUpper);
}
void explainMultiSet()
{
    // same as set only diff. is it allow duplicate elemnt but in sorted order
    multiset<int> mst1;
    mst1.insert(1);
    mst1.insert(1);
    mst1.insert(1);
    mst1.insert(2);
    mst1.insert(2);
    mst1.insert(3);
    // erase all particular  elemnt
    mst1.erase(1); // log(N)
    cout << "After all 1 erase : ";
    for (auto i = mst1.begin(); i != mst1.end(); i++)
    {
        cout << *(i) << " ";
    }

    cout << "After one 2 erase : ";
    auto it = mst1.find(2);
    mst1.erase(it);
    for (auto i : mst1)
    {
        cout << i << " ";
    }
}

void explainUSet()
{
    //same as set diff. is => it is unordered
}
void explainMap()
{
    //concept to key value pairs
    map<int, int> mp1;            //{1,2}
    map<int, pair<int, int>> mp2; // {1, {3,5}}
    map<pair<int, int>, int> mp3; // {{2,3},5}

    //insert in map
    mp1[1] = 1;
    mp1[2] = 4;

    mp2[1] = {1, 1};
    mp2[2] = {4, 8};
    mp2[3] = {9, 27};
    mp2[4] = {16, 64};

    mp3[{1, 1}] = 1;
    mp3[{2, 3}] = 2;
    mp3[{5, 8}] = 3;
    mp3[{10, 15}] = 4;

    for (auto it1 : mp1)
    {
        cout << it1.first << " " << it1.second << endl;
    }
    for (auto it2 : mp2)
    {
        cout << it2.first << " {" << it2.second.first << " " << it2.second.second << "}" << endl;
    }
    for (auto it3 : mp3)
    {
        cout << "{" << it3.first.first << " " << it3.first.second << "}"
             << " " << it3.second << endl;
    }
    //find the spot.......

    auto it4 = mp1.find(2);
    mp1.erase(it4);
    cout << "After erase : " << endl;
    for (auto it5 : mp1)
    {
        cout << it5.first << " " << it5.second << endl;
    }
}

void explainMultiMap()
{
    // same as map diffr .  is  => it can store mulitple same keys
}

void explainUMap()
{
    // same as set and unordered set
}

bool comp(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.second < p2.second)
    {
        return true;
    }
    else if (p1.second == p2.second)
    {
        if (p1.first > p2.first)
        {
            return true;
        }
    }
    return false;
}
void explainExtraSTR()
{
    pair<int, int> arr[] = {{1, 2}, {2, 1}, {4, 1}, {5, 5}};
    int n = sizeof(arr);
    n /= 8;
    cout << "Before Sorting : " << endl;
    for (auto it1 : arr)
    {
        cout << it1.first << " " << it1.second << endl;
    }
    sort(arr, arr + n, comp);
    cout << "After Sorting : " << endl;
    for (auto it2 : arr)
    {
        cout << it2.first << " " << it2.second << endl;
    }

    //count no of digit in binary of decimal

    int num1 = 9;
    int c1 = __builtin_popcount(num1);
    long long num2 = 9999999999999;
    int c2 = __builtin_popcountll(num2);

    //permutation of given string,,,p
    string s1 = "abcd";
    int c = 1;
    vector<string> allPerm;
    do
    {
        // cout << c++ << " : " << s1 << endl;
        allPerm.push_back(s1);
    } while (next_permutation(s1.begin(), s1.end()));

    for (auto it : allPerm)
    {
        cout << c++ << " : " << it << endl;
    }

    //find max element in given range
    int arr1[] = {1, 2, 3, 4, 5, 6};

    int length = sizeof(arr1) / 4;

    int maxElement = *max_element(arr1, arr1 + length);
    cout << "MaxElement : " << maxElement;
}
int main()
{
    // explainPriorityQueue();
    // explainQueue();
    // explainStack();
    // pairExplain();
    // vectorsExplain();
    // explainSet();
    // explainMultiSet();
    // explainMap();
    explainExtraSTR();
}
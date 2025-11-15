-   ALgorithms
-   Containers
-   Functions
-   Iterators

--  Pairs
    Declare : pair<int,int> p = {1,3};
    Access : p.first , p.second
    Nested Declare : pair<int, pair<int,int>> p = {1,{2,3}}
    Access : p.first , p.second.first , p.second.second
    Declare Arrays of pairs : pair<int,int> arr[] = {{1,2},{2,3},{3,4}}
    Access : arr[1].second

--  Vectors ----> Dynamic Array
    Declare : vector<int> v; vector<pair<int,int>> v; vector<int> v(5,10) -> {10,10,10,10,10}; vector<int> v(5) -> 5 elements with 0 or garbage; vector<int> v1(5,20) -> vector<int> v2(v1) -> v2 copies v1

    Functions : 
    -   push_back : v.push_back(num) -> pushes the element into the vector at end -> Takes constant Time
    -   emplace_back : v.emplace_back(num) -> same as push_back only difference is it force to push element at next memory location avoiding constructing a new one -> Takes constant time

    Vectors Pointers:
    -   v.begin() : Points to the first element of Vector
    -   v.end() : Points to the element just next of the last element of vector; {1,3,2,4,5} : it will point the element just after 5 not 5

    -   Iterators
        -   Declare : vector<int>::iterator it = v.begin, auto it = v.begin()
        -   it -> gives position, *it -> gives value at that point
    
    -   Traversal/looping through Vectors : for(auto it=v.begin();it!=v.end();it++) ; for(auto it : v)

    -   Erase -> Takes constant time if Erasing is at the end, if not at the end it will be O(N)
        -   v.erase(v.begin()+1) -> removes the second element from the Array
        -   v.erase(v.begin()+2, v.begin()+4) -> [) -> first parameter is included : last position is excluded

    -   Insert -> Takes constant time if insertion is at the end, if not at the end it will be O(N)
        -   v.insert(v.begin(), 300) -> insert 300 at position v.begin()
        -   v.insert(v.begin()+1,2,10) -> insert 2 10's (10,10) at position v.begin()+1
        -   vector<int> copy(2,50) -> v.insert(v.begin(), copy.begin(), copy.end()) -> it inserts copy vector atrting from position 
        v.begin()

    -   v.pop_back() -> removes the last element : Takes constant Time
    -   v1.swap(v2) -> swaps the vector values
    -   v.clear() -> Empty the Vector
    -   v.empty() -> True : if vector is empty, False : if vector is not empty  

--  List -----> Double Linked List
    Declare : list<int> ls;

    -   ls.push_back(2) -> pushes element at the end - O(1)
    -   ls.emplace_back(4) -> same as in Vectors - O(1)
    -   ls. push_front(3) -> Pushes at the front - O(1)
    -   ls.emplace_front(3) -> same as in Vectors - O(1)

    NOTE: begin, end, clear, insert, size, swap : same as it works in Vectors.

--  Deque ------> Double Ended Queue (Implemented using Double Linked List) : Unlike a vector which is optimized for insertions/deletions at the end, or a list which is efficient for insertions/deletions anywhere but lacks direct element access, a std::deque provides efficient push_front(), pop_front(), push_back(), and pop_back() operations.
    
    Declare : deque<int> dq;

    -   dq.push_back()
    -   dq.emplac_back()
    -   dq.push_front()
    -   dq.emplace_front()
    -   dq.pop_back()
    -   dq.pop_front()
    -   dq.back()
    -   dq.front()

    all above functions take constant time

    NOTE: begin, end, clear, insert, size, swap : same as it works in Vectors.

--  Stack 
    Declare : stack<int> st;

    -   st.push() : Pushes at back
    -   st.emplace()
    -   st.top()
    -   st.top()
    -   st.size()
    -   st.empty()
    -   st1.swap(st2)

    all functions take constant time

--  Queue
    Declare : queue<int> q;

    -   q.push() : Pushes at front
    -   q.emplace()
    -   q.back()
    -   q.front()
    -   q.back()
    -   q.pop()

    all functions take constant time

    NOTE: size,swap as same as stack

--  Prority Queue (Max Heap/Min Heap)
    Declare : priority_queue<int> pq; -----> Max heap
              priority_queue<int, vector<int>, greater<int>> pq; -----> Min Heap
    
    -   pq.push() : O(log n)
    -   pq.emplace() : O(log n)
    -   pq.top()
    -   pq.pop() ------> in max heap - max element is popped out - in min heap - min element is popped out : O(log n)

    -   Custom Comparator :
        priority_queue<Type, Container, Comparator> pq;
        struct Compare {
            bool operator()(const pair<int,int>& a, const pair<int,int>& b) {
                // return true if 'a' has LOWER priority than 'b'
                // (so 'b' will be above 'a' in heap)
                if (a.second == b.second)
                    return a.first > b.first;   // tie-breaker: smaller first has higher priority
                return a.second > b.second;     // min-heap by second
            }
        };

        priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> pq;
        Remember:
            -   If comp(a, b) == true, that means "a is below b in priority".
            -   So you invert the logic compared to normal sorting.


--  Set (Self Balancing Binary Tree) : Unique Value, Sorted
    Declare : set<int> st;

    -   st.insert() -> inserts an element but takes o(log n) time
    -   st.emplace() -> same as vector
    -   Doesn't take Duplicate Values
    -   auto it = st.find(num) -> points to the location if found otherwise points to st.end() if not found : takes O(log n) time
    -   st.erase(n) -> removes that element : takes O(log n) time
        -   st.erase(it1,it2) -> will erase all from it1 to it2
    -   st.count(n) -> it will only return 1 if number found else will return 0

    -   st.upper_bound(num) : will return the location of the number which is just greater than num : O(log n)
    -   st.lower_bound(num) : will return the location of the number which is equal to num or just greater than num : O(log n)

    NOTE: begin, end, size, empty, swap : same as it works in Vectors.

--  Multiset -> same as set but can take duplicate values -> Only Sorted
    Declare : multiset<int> ms;

    -   ms.insert()
    -   ms.erase(num) -> will erase all num present in container
    -   ms.count() -> will count the num 

--  Unordered set ------> Hashtable : unique
    Declare : unordered_set<int> st;

    -   all above functions of set is same here except upper bound and lower bound. Only Difference is here it takes O(1) Time.

--  Map --> self balancing Binary tree. Typically used Red-Black Tree :: should have unique key
    Declare : map<int,int> mp; map<int, pair<int,int>> mp; 

    -   mp[1] = 2 -> key is 1 and value is 2
    -   Duplicate keys are not allowed
    -   mp.insert({a,b}); mp.emplace({a,b})
    -   Access : mp.first, mp.second
    -   mp.find(num) : returns value of the key - takes O(log n)
    -   Lower_bound and upper_bound same as set

--  Multimap --> same as Map but can take duplicate keys
    Declare : multimap<int,int> mp;

    -   all as same as Map

--  Unordered map --> Implemented as Hash Table
    Declare : unordered_map<int,int> mp;

    -   all above functions of map is same here except upper bound and lower bound. Only Difference is here it takes O(1) Time.
    -   for(auto it : umap) ---> it is the copy of item so it.first and it.second
    for(auto it = umap.begin(),it!=umap.end();it++) -----> it is a pointer now - it->first,it->second

--  Algorithms

    -   Sorting
        -   Increasing Order : sort(a,a+n); sort(v.begib(),v.end()); 
        -   Decreasing Order : sort(a, a+n, greater<int>);

        -   Custom comparison Function
            pair<int,int> a[] = {{1,2},{2,1},{4,1}}
            sort(a,a+n,comp) ---> comp should only return bool value
            bool comp(pair<int,int> p1, pair<int,int> p2){
                if(p1.second<p2.second>)
                    return true;
                if(p1.second>p2.second)
                    return false;
                if(p1.first<p2.first)
                    return true;
                return false;
            }

    -   __builtin_popcount(num) -> will return the number of set bits in num (in 32 bits)
    -   __builtin_popcountll(num) -> for long long num
    -   string s = "123"
        sort(s.begin(),s.end())
        do{
            cout<<s<<endl;
        }while(next_permutation(s.begin(),s.end()))
        -   It will print one by one all permuation Alphabetically
            NOTE: If instead of 123 if I gave 321 then permuation wise it won't print any other combination because alphabetically 321 is last permutation. so to print all we should always sort first
    -   *max_element(a,a+n) -> will return max element and max_element will point to max element in the vector





              
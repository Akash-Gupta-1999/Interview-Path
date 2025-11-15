-   STRING
    -   String to Integer and Vice-versa
        -   to_string(num) : converts integer to a string
        -   stoi("123") : converts string to integer

    -   substring
        string substr(size_t start, size_t length = npos) const; -> s.substr(0,i+1) ---> starts from 0 and takes i+1 char
    
    -   find
        str.find(goal) != string::npos (will return npos if not found the substring goal in str)
    
    -   s = "AKASH"  ; string temp = s[i] + s[i-1] - Never do this it will add ascii, temp = s.substr(i-1,2);

    -   string(1,postfix[i]) : string s1(1, 'a');   // "a"   :::::::::: string s2(5, 'x');   // "xxxxx"

    -   stringstream in C++
        🔹 What is it?

            stringstream (in <sstream>) lets you treat a string as a stream (like cin/cout).

            istringstream → read from string

            ostringstream → write to string

            stringstream → both read & write

        🔹 Basic Usage
            #include <sstream>
            #include <iostream>
            using namespace std;

            int main() {
                stringstream ss;

                // Write into stream
                ss << 10 << " " << 20 << " " << 30;

                // Read back
                int a, b, c;
                ss >> a >> b >> c;
                cout << a << " " << b << " " << c; // 10 20 30
            }

        🔹 Key Functions

            ss << value → insert into stream

            ss >> value → extract from stream

            ss.str() → get/set underlying string

            getline(ss, token, delim) → split by delimiter
        
        -   string data = "10,20,30";
            stringstream ss(data);
            string token;

            while (getline(ss, token, ',')) {
                cout << token << " "; // 10 20 30
            }


-   Array Declaration
    -   for int : in main we can declare 10^6 size of array while in global we can do 10^7
    -   for bool : in main we can declare 10^7 size of array while in global we can do 10^8

-   Calculation of mid : (low+high)/2 may overflow so always use : low + (high-low)/2

-   for(auto it : umap) ---> it is the copy of item so it.first and it.second
    for(auto it = umap.begin(),it!=umap.end();it++) -----> it is a pointer now - it->first,it->second
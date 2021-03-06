#include "doctest.h"
#include "range.hpp"
#include "accumulate.hpp"
#include "filterfalse.hpp"
#include "compress.hpp"
#include <vector>
#include <string>
#include <set>
#include <iostream>
using namespace itertools;
using namespace std;


TEST_CASE("Test Range")
{
    int check=1;
    //pass all the int in range and check if i==check in every location
    for(int i : range(1,11)){
        CHECK(check++==i); 
    }
    check=11;
    //pass all the int in range and check that aren't check(11)
    for(int i : range(1,11)){
        CHECK(check!=i);
    }

    vector<int> result = {20,21,22,23,24,25,26,27};
    int j = 0;
    //pass all the int in the vector and in range and check if they are equals
    for(int i : range(20,28)){
        CHECK(i == result.at(j));
        j++;
    }


}


TEST_CASE("Test Accumulate"){
    //check for a string case
    vector<string> v = {"a", "b", "c", "d", "e"};
    string words[] = {"a", "ab", "abc", "abcd", "abcde"};
    int j = 0;
    for(auto i : accumulate(v)){
        CHECK(i == words[j]);
        j++;
    }

    //check accumulate with a range and lambada function
    vector<int> result2 = {3,12,60,360,2520,20160};
    j=0;
    for (int i: accumulate(range(3,9),[](int x, int y){return x*y;})) // 3,3*4,3*4*5,3*4*5*6,3*4*5*6*7,3*4*5*6*7*8
    {
        CHECK(i == result2.at(j));
        ++j;
    }

    //check accumulate with a lambada function 
    j=0;
    vector<int> result3={1,3,6,10,15,21,28,36,45};
    for (int i: accumulate(range(1,9),[](int x, int y){return x+y;})) // 1,1+2,1+2+3,1+2+3+4,1+2+3+4+5..... ,1+2+3+4+5+6+7+8+9
    {
                CHECK(i == result3.at(j));
        ++j;
    }

}

TEST_CASE("Test FilterFalse"){
    //check filterfalse with an boolean lambada(even=true)
    vector<int> result = {5,7};
    int j = 0;
    for (auto i: filterfalse([](int i){return i%2==0;}, range(5,9)) )
    {
        CHECK(i == result.at(j));
        ++j;
    }

    //the same but odd
    vector<int> result2 = {5,7};
    j = 0;
    range r59(5,9);
    for (auto i: filterfalse([](int i){return i%2==0;}, r59) )
    {
        CHECK(i == result2.at(j));
        ++j;
    }
    CHECK(j == 2);


}

TEST_CASE("Test compress"){
//compress with range - the odd place 
    vector<bool> b;
    for (int j = 1; j < 20; ++j) {
        b.push_back(j%2 == 1);
    }
    range range1(1,20);
    for (auto i : compress(range1, b)) {
        CHECK(i%2 == 1);
    }
}

TEST_CASE("Test Compress")
{
    vector<int> result = {7};
    int j = 0;
    vector<bool> fftf {false,false,true,false};
    for (auto i: compress(range(5,9), fftf) )  {
        CHECK(i == result.at(j));
        ++j;
    }
    CHECK(j == 1);

    result.clear();
    j = 0;

    result = {1,7,11,20};
    j = 0;
    vector<int> myvec = {1,3,7,10,11,16,20};
    vector<bool> tftftft {true,false,true,false,true,false,true};
    for (auto i: compress(myvec, tftftft) )
    {
        CHECK(i == result.at(j));
        ++j;
    }
    CHECK(j == 4);


    result.clear();
    j = 0;

    vector<char> resultString = {'I','L', 'o', 'v', 'e', 'C', '+','+'};
    j = 0;

    vector<bool> tfffttttttt {true,false,false,false,true,true,true,true,true,true,true};
    string s1 {"InotLoveC++"};
    for (auto i: compress(s1, tfffttttttt)) {
        CHECK(resultString.at(j) == i);
        ++j;
    }
    CHECK(j == 8);



    j = 0;

    vector<bool> myVectorBool2 {false,false,false,false,false,false,false,false,false,false,false};
    
    for (auto i: compress(string("InotLoveC++"), myVectorBool2))
    {
        CHECK(0==1); // not need to get in
        ++j;
    }
    CHECK(j == 0);



    result.clear();
    j = 0;


}

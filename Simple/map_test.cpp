//
// Created by 94456 on 7/3/2022.
//


// Map Test


#include<iostream>
#include<string>
#include<unordered_map>
#include<map>

using namespace std;

int main()
{
    map<int,int> a={{1,1},{3,4}};

    int b=a.count(3);

    printf("Map\n");
    printf(to_string(b).c_str());


    printf("\n");
    unordered_map<int,int> c={{1,1},{3,5},{3,4}};

    int d=c.count(3);
    printf("Unordered_map\n");
    printf(to_string(d).c_str());

    printf(typeid(c[3]).name());
    printf("\n");
    printf(to_string(c[3]).c_str());

    return 0;
}





//
// Created by Brian_Tsui on 2022.09.19.
//


// Meide 01


#include<iostream>


using namespace std;


class Solution{
public:
};


int main(){

    unsigned int a;
    int n;

    cin>>a>>n;

    int size=sizeof(a)*8;
    n = n%size;
    a= (a<<(size-n)|(a>>n));//右移

    cout<<a<<endl;








    cout<<"Hello Meide 01 !"<<endl;

    return 0;
}
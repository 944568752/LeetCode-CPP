//
// Created by 94456 on 8/30/2022.
//


// Three Sum


#include<iostream>
#include<vector>


using namespace std;


class Solution{
public:

};

bool oneCharacter(char* str)
{
    int i = 0,j=i+1;
    while (*str != '\0')
    {
        while(*(str+j) !='\0')
        {
            if (*(str) == *(str + j))
            {
                return false;
            }
            ++j;
        }
        j = i+1;
        ++i;
        ++str;
    }
    return true;
}


int main(){

    cout<<oneCharacter("est\0")<<endl;

    cout<<"Hello i7 6700 !"<<endl;
    printf("Hello threeSum !\n");

    return 0;
}
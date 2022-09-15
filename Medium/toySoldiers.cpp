//
// Created by Brian_Tsui on 2022.09.13.
//


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int soldier_nums,operate_nums;
    cin>>soldier_nums>>operate_nums;

    vector<int> soldiers(soldier_nums);
    for(int i=0;i<soldier_nums;i++){
        int num;
        cin>>num;
        soldiers[i]=num;
    }

    for(int i=0;i<operate_nums;i++){
        int flag,num;
        cin>>flag>>num;
        if(flag==2){
            sort(soldiers.begin(),soldiers.begin()+num,greater<int> ());
        }
        else if(flag==1){
            sort(soldiers.begin(),soldiers.begin()+num);
        }
    }

    for(int i=0;i<soldier_nums;i++){
        cout<<soldiers[i]<<' ';
    }

    return 0;
}
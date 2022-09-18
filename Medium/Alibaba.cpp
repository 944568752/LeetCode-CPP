//
// Created by Brian_Tsui on 2022.09.16.
//


// Alibaba


#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>


using namespace std;



int main(){

    int n;
    cin>>n;

    vector<int> nums(n,0);

    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    int operate=0;

    while(true){
        int num_min=*min_element(nums.begin(),nums.end());
        int num_max=*max_element(nums.begin(),nums.end());

        if(num_max-num_min==1){
            break;
        }

        sort(nums.begin(),nums.end());

        float avg=accumulate(nums.begin(),nums.end(),0.0)/n;

        if(avg-nums[0]>nums[n-1]-avg){
            nums[0]++;
            operate++;
        }
        else{
            nums[n-1]--;
            operate++;
        }

    }

    cout<<operate<<endl;

    return 0;
}
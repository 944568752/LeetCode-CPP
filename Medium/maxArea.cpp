//
// Created by 94456 on 8/29/2022.
//


// maxArea


#include<iostream>
#include<vector>


using namespace std;


class Solution{
public:
    // 双指针-盛最多水的容器
    int maxArea(vector<int> &height){
        // 容器的最大容积
        int max_capacity=0;

        // 容器的左边界
        int left=0;
        // 容器的右边界
        int right=height.size()-1;

        // 如果左右边界没有靠拢,则保持循环
        while(left<right){
            // 记录左右两边中的最短边
            int width=0;
            if(height[left]<height[right]){
                width=height[left];
            }
            else{
                width=height[right];
            }

            // 比较容器的容积与当前最大容积
            if(max_capacity<width*(right-left)){
                // 如果容积变大,则更新当前最大容积的值
                max_capacity=width*(right-left);
            }

            // 如果左边是短板,则左边右移
            if(height[left]<height[right]){
                left++;
            }
            // 如果右边是短板,则右边左移
            else{
                right--;
            }

        }

        // 返回容器的最大容积
        return max_capacity;
    }
};


int main(){

    printf("Hello maxArea ! \n");

    return 0;
}
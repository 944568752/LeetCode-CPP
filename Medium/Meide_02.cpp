//
// Created by Brian_Tsui on 2022.09.19.
//


#include <iostream>
#include<vector>
#include<algorithm>


using namespace std;
class Joseph
{
public:
    Joseph(int n,int m,int k=1):n(n),m(m),k(k){}
    void simulate();

private:
    int m, n,k;
};
void Joseph::simulate()
{
    int *a=new int[50];//存储数的数组
    int lef = n;//剩余标记的人数
    int p = k-1;//指向起始位置
    int i = 0;
    int number = 0;
    int *flag=new int [50];

    //两个数组初始化
    for (i; i < n; i++)
    {
        a[i] = i + 1;
        flag[i] = 1;
    }
    for (i = n; i < 50; i++)
    {
        a[i] = 0;
        flag[i] = 0;
    }

    while (lef >= 1)
    {
        number = m;//报号数
        while (number>0)
        {
            if (flag[p] == 1)
            {
                number--;
                p++;
            }
            else if (p >= n) p = 0;
            else  p++;
        }
        cout << a[p - 1] << " ";
        flag[p-1] = 0;
        lef--;
    }
}
int main()
{
//    int m, n, k=0;
//    cin >> n >> m;
//    Joseph obj(n, m, k);
//    obj.simulate();

    string a="cuihanlin";

    sort(a.begin(),a.end());

    cout<<a<<endl;

    return 0;
}



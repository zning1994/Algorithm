//
//  main.cpp
//  ZeroOneKnapsackProblem
//
//  Created by ZNing on 15/11/25.
//  Copyright © 2015年 ZNing. All rights reserved.
//
//  第三次实验：0-1背包问题的求解
//  程序基于Xcode编写，在Xcode编译器上运行正常，如在其他编译器无法运行请自行调整。
//

#include <iostream>
using namespace std;

//物品数据结构
typedef struct commodity
{
    int value;  //价值
    int weight; //重量
}commodity;

const int N = 3;  //物品个数
const int W = 50; //背包的容量

//初始物品信息
commodity goods[N+1]={{0,0},{60,10},{100,20},{120,30}};
int SelectArray[N+1][W+1];

int max_value();

int main(int argc, const char * argv[]) {
    int maxvalue = max_value();
    cout<<"The max value is: ";
    cout<<maxvalue<<endl;
    int remainspace = W;
    //输出所选择的物品列表：
    for(int i=N; i>=1; i--)
    {
        if (remainspace >= goods[i].weight)
        {
            if ((SelectArray[i][remainspace]-SelectArray[i-1][remainspace-goods[i].weight]==goods[i].value))
            {
                cout << "item " << i << " is selected!" << endl;
                remainspace = remainspace - goods[i].weight;//如果第i个物品被选择，那么背包剩余容量将减去第i个物品的重量 ;
            }
        }
    }
    return 0;
}

int max_value()
{
    //初始没有物品时候，背包的价值为0
    for(int w=1;w<=W;++w)
        SelectArray[0][w] = 0;
    for(int i=1;i<=N;++i)
    {
        SelectArray[i][0] = 0;  //背包容量为0时，最大价值为0
        for(int w=1;w<=W;++w)
        {
            if(goods[i].weight <= w)  //当前物品i的重量小于等于w，进行选择
            {
                if( (goods[i].value + SelectArray[i-1][w-goods[i].weight]) > SelectArray[i-1][w])
                    SelectArray[i][w] = goods[i].value + SelectArray[i-1][w-goods[i].weight];
                else
                    SelectArray[i][w] = SelectArray[i-1][w];
            }
            else //当前物品i的重量大于w，不选择
                SelectArray[i][w] = SelectArray[i-1][w];
        }
    }
    return SelectArray[N][W];  //最终求得最大值
}

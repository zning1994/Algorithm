//
//  main.cpp
//  DivideAndConquer
//
//  Created by ZNing on 15/11/18.
//  Copyright © 2015年 ZNing. All rights reserved.
//
//  第二次实验：分治法进行汉诺塔问题的求解
//  程序基于Xcode编写，在Xcode编译器上运行正常，如在其他编译器无法运行请自行调整。
//

#include <iostream>
using namespace std;

void MoveHanoi(char i, char j){
    //输出移动过程
    cout << "将柱子"<< i <<"上的盘子移动到柱子"<< j << endl;
}

void HanoiTower(int n, char a, char b, char c){
    if(n==1)
        MoveHanoi(a, c);
    else
    {
        HanoiTower(n-1, a, c, b);
        MoveHanoi(a, c);
        HanoiTower(n-1, b, a, c);
    }
}

int main(int argc, const char * argv[]) {
    //cout << "Hello, World!\n";
    int num=0;
    cout << "请输入盘子的数量：";
    cin >> num;
    cout << "移动这" << num <<"个盘子的步骤如下："<<endl;
    HanoiTower(num, '1', '2', '3');
    cout << "移动完成" <<endl;
    return 0;
}

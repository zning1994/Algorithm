//
//  main.cpp
//  ComputerAlgorithm
//
//  Created by ZNing on 15/11/11.
//  Copyright © 2015年 ZNing. All rights reserved.
//
//  第一次实验：二分查找
//  程序基于Xcode编写，在Xcode编译器上运行正常，如在其他编译器无法运行请自行调整。
//

#include <iostream>
using namespace std;

int BinarySearch(const int *Array,int start,int end,int key){
    //二分查找非递归算法
    int left,right;
    int mid;
    left=start;
    right=end;
    while (left+1<right) {
        mid=(left+right)/2;
        if (key==Array[mid]) {
            return mid;
        }
        else if (key<Array[mid]){
            right=mid;
        }
        else{
            left=mid;
        }
    }
    return -1;//未找到，抛出异常
}

int binarySearchOfRecursion(const int *Array,int start,int end,int key){
    //二分查找递归算法（效率不高，未调用）
    int left,right;
    int mid;
    left=start;
    right=end;
    if (key<Array[mid]) {
        return (binarySearchOfRecursion(Array,left,mid,key));
    }
    else if (key>Array[mid]){
        return (binarySearchOfRecursion(Array,mid+1,right,key));
    }
    else{
        return mid;
    }
    return -1;//未找到，抛出异常
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int MAXM;
    cout << "请输入数值个数，按回车结束：";
    cin >> MAXM;
    cout << "请输入数组元素，按顺序以空格分隔，按回车结束：";
    int i=0,numArray[MAXM+10],key;
    while (i!=MAXM) {
        cin >> numArray[i];
        i++;
    }
    cout << "请输入所要查找的元素，按回车结束：";
    cin >> key;
    int result = BinarySearch(numArray,0,i,key);
    if (result==-1) {
        cout <<"查找失败，无此元素" << endl;
        return 0;
    }
    cout << "查找成功，其位置为" << result+1 <<endl;
    return 0;
}

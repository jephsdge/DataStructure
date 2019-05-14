#ifndef _SEQLIST_H
#define _SEQLIST_H

#include <iostream>
#include "LinearList.h"

using namespace std;

const int defaultSize = 100;
template <class T>
class SeqList : public LinearList<T>
{
protected:
    T *data;
    int maxSize;
    int last;
    void reSize(int newSize);

public:
    SeqList(int sz = defaultSize);          //构造函数
    SeqList(SeqList<T> &L);                 //构造函数
    ~SeqList() { delete[] data; }           //析构函数
    int Size() const { return maxSize; }    //返回最大容量
    int Length() const { return last + 1; } //返回当前长度
    int Search(T &x) const;                 //搜索x在表中的位置
    int Locate(int i) const;                //定位第i个表项
    bool getData(int i, T &x) const         //获得第i项的值
    {
        if (i > 0 && i <= last + 1)
        {
            x = data[i - 1];
            return true;
        }
        else
            return false;
    }
    void setData(int i, T &x) //设置第i项的值
    {
        if (i > 0 && i <= last + 1)
            data[i - 1] = x;
    }
    bool Insert(int i, T &x);                                  //将x插入到第i项中
    bool Remove(int i, T &x);                                  //删除第i项
    bool IsEmpty() { return (last == -1) ? true : false; }     //判断是否为空
    bool IsFull() { return (last == maxSize) ? true : false; } //判断是否满表
    void intput();                                             //输入表
    void output();                                             //输出表
};

//构造函数
template <class T>
SeqList<T>::SeqList(int sz)
{
    //通过指定sz的值来确定表的容量
    if (sz > 0) //sz合法
    {
        maxSize = sz; last = -1;
        data = new T[maxSize];
        if (data == NULL)
        {
            cerr << "存储分配有错误！" << endl;
            exit(1);
        }
    }
}


#endif
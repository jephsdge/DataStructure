#ifndef H_LINEARLIST_H
#define H_LINEARLIST_H

#define true 1
#define flase 0

template <class T>
class LinearList
{
public:
    LinearList();
    ~LinearList();
    virtual int Size() const = 0;
    virtual int Length() const = 0;
    virtual int Search(T &x) const = 0;
    virtual int Locate(int i) const = 0;
    virtual bool getData(int i, T &x) const = 0;
    virtual void setData(int i, T &x) = 0;
    virtual bool Insert(int i, T &x) = 0;
    virtual bool Remove(int i, T &x) = 0;
    virtual bool IsEmpty() const = 0;
    virtual bool IsFull() const = 0;
    virtual void Sort() = 0;
    virtual void input() = 0;
    virtual void output() = 0;
};


#endif
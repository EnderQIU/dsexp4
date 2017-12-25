//
// Created by 邱添爽 on 2017/12/25.
//

#ifndef DSEXP4_HASHTABLE_H
#define DSEXP4_HASHTABLE_H

#include <iostream>

using namespace std;
enum ResultCode{
    Success, NeverUsed, NotPresent, Overflow, Duplicate,
};

// 双散列法二次探查散列表
template <class T>
class HashTable{
private:
    ResultCode Find(T& x, int& pos)const;
    static int M;
    T* ht;
    bool* empty;
    static int h1(T key);
    static int h2(T key);
public:
    explicit HashTable(int divisor=11);
    ~HashTable(){delete[]ht;delete[] empty;};
    ResultCode Search(T& x)const ;
    ResultCode Insert(T& x);
    ResultCode Remove(T& x);
    string Display();
};

template <class T>
int HashTable::h1(T key) {
    return key.getKey() % M;
}

template <class T>
int HashTable::h2(T key) {
    return key.getKey() % M + 1;
}

template <class T>
HashTable::HashTable(int divisor) {
    M = divisor;
    ht = new T[M];
    empty = new bool[M];
    for (int i=0;i<M;i++){
        empty[i] = true;
        ht[i] = NeverUsed;
    }
}

template <class T>
ResultCode HashTable<T>::Find(T &x, int &pos) const {
    // 调用主散列函数
    pos =  h1(x);
    int i = pos, j = -1;
    if (!empty[pos] && ht[pos] == x) {
        x = ht[pos];
        return Success;  // 用主散列函数就搜索到了结果
    }
    // 调用次散列函数
    int delta = h2(x);
    do{
        pos += delta;
        if (!empty[pos] && ht[pos] == x) return Success;
    }while(pos<=M);
    // 不存在
    return NotPresent;
}

template <class T>
ResultCode HashTable::Search(T &x) const {
    int pos;
    if(Find(x, pos) == Success){
        // 显示数据
        cout<<ht[pos].display()<<endl;
        return Success;
    }
    cout<<"该学号不存在"<<endl;
    return NotPresent;
}

template <class T>
ResultCode HashTable::Insert(T &x) {
    int pos;
    ResultCode result = Find(x, pos);
    if (result == NotPresent){
        ht[pos] = x;  // 将新元素插入空值处，并打上已使用标记
        empty[pos] = false;
        return Success;
    }
    if(result == Duplicate) return Duplicate;  // 存在重复元素
    return Overflow;  // 表已满
}

template <class T>
ResultCode HashTable::Remove(T &x) {
    int pos;
    if(Find(x, pos) == Success){
        ht[pos] = NeverUsed;
        return Success;
    }
    return NotPresent;
}

template <class T>
string HashTable::Display() {
    string result = "";
    for(int i = 0;i<11;i++){
        if (!empty[i]){
            result += ht[i].display() + "\n";
        }
    }
    return result;
}

#endif //DSEXP4_HASHTABLE_H

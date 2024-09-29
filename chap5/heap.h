#ifndef HEAP_H
#define HEAP_H

#define PARENT(i) return ((i-1) / 2)
#define LEFT(i) return (2 * i + 1)
#define RIGHT(i) (LEFT(i) + 1)

template <class T>
using HeapCmpFn = int (*)(T &a, T &b);

int def_cmp(const int &a, const int &b)
{
    return a > b;
}

template <class T>
class Heap {
public:
    enum HeapType {
        BIG,    // 大堆
        LITTLE, // 小堆
    };
    Heap(int _cap = 10, HeapType _type = BIG, HeapCmpFn<T> cmpFn = def_cmp);
    ~Heap();
    void Heapify(int i); // 维护堆性质

private:
    T *data;
    int cap, size;
    HeapType type;
    int (*HeapCmp)(const T &a, const T &b);
};


template <class T>
Heap<T>::Heap(int _cap, HeapType _type, HeapCmpFn<T> cmpFn)
: cap(_cap), type(_type), HeapCmp(def_cmp)
{
    data = new T[_cap];
    size = 0;
}

template <class T>
Heap<T>::~Heap()
{
    if (data)
        delete data;
}

template <class T>
void Heap<T>::Heapify(int i)
{
    int l, r, largest;

    l = LEFT(i);
    r = RIGHT(i);
    
    if (i > size)
        return;
    
    

    
}

#endif
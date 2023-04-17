// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <iostream>
#include <string>

template <typename T, int size>

struct TPQueue{
 private:
    T* arr;
    int first, last, count;

 public:
    TPQueue() : first(0), last(0), count(0) { arr = new T[size]; }
    void push(const T& sum) {
        if (count == 0) {
            for (int q = 0; q < size; ++q) {
                arr[q].ch = '0';
                arr[q].prior = 0;
                first = 0, last = 0, count = 0;
            }
        }
        if (count == size) {
            throw std::string("Full!");
        } else {
            if (count == 0 || arr[last + 1].prior == 0
            && arr[last-1].prior >= sum.prior) {
                arr[last % size].ch = sum.ch;
                arr[last % size].prior = sum.prior;
            }
            if (count == 0 || arr[last + 1].prior == 0
            && arr[last].prior >= sum.prior) {
                arr[last % size].ch = sum.ch;
                arr[last % size].prior = sum.prior;
            } else {
                for (int q = first; q < last; ++q) {
                    if (arr[q].prior <= sum.prior) {
                        for (int w = last; w > q; --w) {
                            arr[w].ch = arr[w - 1].ch;
                            arr[w].prior = arr[w - 1].prior;
                        }
                        arr[q].ch = sum.ch;
                        arr[q].prior = sum.prior;
                        break;
                    }
                }
            }
            last++;
            count++;
        }
    }
    const T& pop() {
        if (count == 0) {
            throw std::string("Empty!");
        }
        count--;
        return arr[(first++ % size)];
    }
};

struct SYM {
    char ch;
    int prior;
};


#endif  // INCLUDE_TPQUEUE_H_

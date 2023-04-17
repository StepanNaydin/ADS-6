// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <iostream>
#include <string>

template <typename T, int size>

struct TPQueue{
private:
    T arr[size];
    int first = 0, last = 0, count = 0;

public:
    void push(const T& sum) {
        if (count == size) {
            throw std::string("Full!");
        } else {
            if (count == 0 || arr[last + 1].prior == 0 && arr[last-1].prior >= sum.prior) {
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
            if (last == size) {
                last = 0;
            }
            count++;
        }
    }
    const T& pop() {
        if (count == 0) {
            throw std::string("Empty!");
        }
        if (first == size) {
            first = 0;
        }
        count--;
        return arr[(first++ % size)];
    }
};

struct SYM {
    SYM(char ch = '0', int prior = 0) : ch(ch), prior(prior) {}
    char ch;
    int prior;
};


#endif  // INCLUDE_TPQUEUE_H_

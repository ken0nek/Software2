/* test-queue.cpp */
#include <iostream>
#include <deque>

void Print(std::deque<int> deq) {
    std::cout << "queue -> ";
    for (std::deque<int>::iterator itc = deq.end()-1;
            itc != deq.begin()-1; itc--) {
        std::cout << *itc;
        if (itc != deq.begin()) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "FIFO:" << std::endl;
    std::deque<int> fq;
    fq.push_front(12);
    fq.push_front(99);
    fq.push_front(37);
    Print(fq);

    int *n;
    while (!fq.empty()) {
        n = &fq.front();
        fq.pop_front();
        std::cout << "remove " << *n << std::endl;
    }

    std::cout << "LIFO:" << std::endl;
    std::deque<int> lq;
    lq.push_front(12);
    lq.push_front(99);
    lq.push_front(37);
    Print(lq);

    while (!lq.empty()) {
        n = &lq.back();
        lq.pop_back();
        std::cout << "remove " << *n << std::endl;
    }
}

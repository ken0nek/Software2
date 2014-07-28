/* queue3.h */
#include <iostream>
#include <deque>
#include "node.h"

using namespace std;
class FIFOQueue : public deque<int> {
    public:
        Node *First() {
            return back();
        }
        void Insert(deque &n) {
            return push_front(n);
        }
        deque *RemoveFirst() {
            deque *r = First();
            pop_back();
            return r;
        }
};

// class LIFOQueue : public deque<int> {
//     public:
//         Node *First() {
//             return front();
//         }
//         void Insert(Node &n) {
//             return push_front(n);
//         }
//         Node *RemoveFirst() {
//             Node *r = First();
//             pop_front();
//             return r;
//         }
// };

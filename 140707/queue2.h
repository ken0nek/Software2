/* queue2.h */
#include <iostream>
#include "elem.h"

using namespace std;
j
class Queue { // LIFO queue
    private:
        Elem *root;
    public:
        Queue() {
            root = NULL;
        };
        ~Queue(){};

        bool Empty() {
            return (root == NULL ? true : false);
        }
        Elem* First() {
            return root;
        }
        Elem* RemoveFirst() {
            Elem *ret = First();
            root = ret->next();
            return ret;
        }
        void Insert(Elem &n) {
            n.setnext(root);
            root = &n;
        }

        void Print() {
            Elem *ptr = root;
            cout << "queue -> ";
            while (ptr) {
                cout << " " << ptr->state;
                ptr = ptr->next();
            }
            cout << endl;
        }
};

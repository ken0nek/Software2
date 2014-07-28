/* queue1.h */
#include <iostream>
#include "elem.h"

using namespace std;

class Queue { // FIFO queue
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
            if (root == NULL) {
                root = &n;
            } else {
                Elem *ptr = root;
                while (ptr->next()) {
                    ptr = ptr->next();
                }
                ptr->setnext(&n);
                n.setnext(NULL);
            }
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

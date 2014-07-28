/* test-queue.cpp */
#include "queue1.h"

int main() {
    Elem n1 = Elem(12, NULL);
    Elem n2 = Elem(99, NULL);
    Elem n3 = Elem(37, NULL);
    Queue q = Queue();

    q.Insert(n1);
    q.Insert(n2);
    q.Insert(n3);

    q.Print();

    Elem *n;
    while (!q.Empty()) {
        n = q.RemoveFirst();
        cout << "remove " << n->state << endl;
    }
}

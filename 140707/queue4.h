/* queue4.h */

class LIFOQueue : public deque<int> {
    public:
        Node *First() {
            return front();
        }
        void Insert(Node *n) {
            return push_front(n);
        }
        Node *RemoveFirst() {
            Node *r = First();
            pop_front();
            return r;
        }
};

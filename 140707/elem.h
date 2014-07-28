/* elem.h */
class Elem {
    public:
        int state; // can be used as an index
        Elem *nextptr;

        Elem(int s, Elem *p) {
            state = s;
            nextptr = p;
        }
        ~Elem(){};

        Elem* next() {
            return nextptr;
        }
        void setnext(Elem *p) {
            nextptr = p;
        }
};

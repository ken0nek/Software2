/* node.h */
class Node {
    public:
        int state; // can be used as an index
        Node *parentptr;
        int action;
        int depth;
        int pathCost;
        Node (int s, Node *p) {
            state = s;
            parentptr = p;
            if (parentpt == NULL) {
                depth = 1;
            } else {
                depth = parentptr->depth + 1;
            }
        }
        ~Node() {}
        Node (const Node &node) {
            state = node.state;
            parentptr = node.parentptr;
            depth = node.depth;
        }
        Node *parent() {
            if (parentpt != NULL) {
                return parentptr;
            } else {
                return this;
            }
        }
        static int count;
        static vector < Node * >all;
        static Node *factory() {
            return parentptr;
        }
        static Node *factory(int s, Node *p) {
            Node *retval = new Node(s, p);
            all.push_back(retval);
            count++;
            return retval;
        }

};

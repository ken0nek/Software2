#include <vector>
#include <algorithm>
#include <functional>

class Lab {
    private:
        //LabMember* members[36];
        std::vector<LabMember*> members;
        int n_members;

    public:
        Lab() {
            n_members = 0;
        }
        ~Lab() {}

        static bool labmember_less(const LabMember* a, const LabMember* b) { 
            //fprintf(stderr, "%c %c", a->name[0], b->name[0]);
            return a->name[0] < b->name[0]; 
        }
        //struct labmember_less {
        //    bool operator() (const LabMember& a, const LabMember& b) const {
        //        return a.name[0] < b.name[0];
        //    }
        //};

        void AddMember(LabMember* new_member) {
            members.push_back(new_member);
            //members[n_members] = new_member;
            n_members++;
        }
        void PrintMember() {
            std::sort(members.begin(), members.end(), labmember_less);
            //std::sort(members.begin(), members.end(), std::less<LabMember*>());
            for (std::vector<LabMember*>::iterator l=members.begin();l!=members.end();l++) {
                (*l)->PrintInfo();
            }
            //int i;
            //for (i=0; i<n_members; i++) {
            //    members[i]->PrintInfo();
            //}
        }
};

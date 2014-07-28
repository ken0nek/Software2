/* labmember4.h */
#include <iostream>
class LabMember {
    //protected:
    public:
        char name[32];
        LabMember() {};
        LabMember(char* _name) {
            strcpy(name, _name);
        }
        ~LabMember() {
        }

        bool operator<(const LabMember l) const {
            return (name[0] < l.name[0]) ? true : false;
        }
        bool operator>(const LabMember l) const {
            return (name[0] > l.name[0]) ? true : false;
        }
        void SetName(char* _name) {
            sprintf(name, "Mr. %s", _name);
        }
        char* GetName() {
            return name;
        }

        virtual void PrintInfo() {};
};

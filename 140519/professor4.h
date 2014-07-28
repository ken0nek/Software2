class Professor : public LabMember {
    private:
        int room;
    public:
        Professor() : LabMember() {}
        Professor(char* _name) : LabMember(_name) {
            room = 0;
        }
        ~Professor() {
        }

        void SetName(char* _name) {
            sprintf(name, "Prof. %s", _name);
        }
        void SetRoom(int _room) {
            room = _room;
        }
        int GetRoom() {
            return room;
        }
        void PrintInfo() {
            printf("professor name=%s, room=%d\n", GetName(), GetRoom());
        }
};

class LabMember {
	protected:
		char name[32];

	public:
		LabMember() {}
		LabMember(char* _name) {
			strcpy(name, _name);
		}
		~LabMember() {
		}

		char* SetName(char* _name) {
			sprintf(name, "Mr. %s", _name);
		}

		char* GetName() {
			return name;
		}

		virtual void PrintInfo() {};
};
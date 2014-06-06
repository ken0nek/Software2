class Lab {
	LabMember* members[36];
	int n_members;

	public:
		Lab() {
			n_members = 0;
		}
		~Lab() {
		}

		void AddMember(LabMember* new_member) {
			members[n_members] = new_member;
			n_members++;
		}

		void PrintMember() {
			int i;
			for (int i = 0; i < n_members; i++) {
				members[i] -> PrintInfo();
			}
		}
};
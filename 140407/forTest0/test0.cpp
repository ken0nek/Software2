// test0.cpp //
#include <iostream>
using namespace std;

int test(int i, int j){
	return (i * j);
}

int main(int argc, char const *argv[])
{
	int i, j , k;
	i = 2;
	j = 3;
	k = test(i, j);

	if(k > 5) {
		cout << ">5" << endl;
	} else {
		cout << "<=5" << endl;
	}
	return 0;
}
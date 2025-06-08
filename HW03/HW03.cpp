#include "HW03.h"
#include <iostream>

using namespace std;

int main() {

	SimpleVector<int> intvec;

	intvec.push_back(4);
	intvec.push_back(3);
	intvec.push_back(2);
	intvec.push_back(1);

	for (int i = 0; i < 10; i++)
	{
		intvec.push_back(i);
	}

	cout << "size : " << intvec.size() << " capacity : " << intvec.capacity() << endl;
	for (int i = 0; i < intvec.size(); i++)
	{
		cout << intvec.data[i] << " ";
	}
	cout << endl;

	intvec.pop_back();
	intvec.pop_back();
	intvec.sortData();
	for (int i = 0; i < intvec.size(); i++)
	{
		cout << intvec.data[i] << " ";
	}

	return 0;
}
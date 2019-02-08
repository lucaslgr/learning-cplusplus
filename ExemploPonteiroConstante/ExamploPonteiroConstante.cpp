#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	const int vet[] = {1, 2, 3};
	const int* p1;
	int const* p2;
	int* const p3 = new int[3];
	
	p1 = &vet[0];
	p2 = &vet[1];
	
	cout << *p1 <<endl;
	cout << *p2 <<endl;
		
	return 0;
}
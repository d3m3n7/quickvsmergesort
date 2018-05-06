#include <iostream>
#include <ctime>//srand/rand
#include <cstdlib> //srand/rand
#include <math.h> //pow log10
using namespace std;

int main(){
	int t_seed;
	srand(t_seed= time(NULL));
	int N = rand() % 1000000;
	cout << N <<endl;

}

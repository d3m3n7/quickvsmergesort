#include <iostream>
#include <ctime>//srand/rand
#include <cstdlib> //srand/rand
#include <math.h> //pow log10
using namespace std;

int main(){
	int t_seed;
	srand(t_seed= time(NULL));
	int N;
	cin>>N;
	int C = 8;
	cout << N << " " << t_seed <<" "<< C << endl;
	C = pow(10,C);
	for (int i= 0; i < N ; ++i){
		
		cout << rand() % C  << " "; 
	}
	cout << endl;

}

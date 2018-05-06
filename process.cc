#include <iostream>
using namespace std;
int I = 3; //amb quants nombres es fa el calcul
int main(){
	double time;
	int seed, seed_ini,N,N_ini;
	double SUM_time = 0;
	int c = 0;
	while(cin>>time>>seed>>N){
		if (c < I) {
			SUM_time += time; 
			seed_ini = seed;
			N_ini = N;
			
		}
		if (c == I) {
			c = 0; 
			cout << SUM_time/double(I) << "	" << seed_ini << "	" << N_ini << endl;
			SUM_time = time; 
		}		
		c++;	
	}
	cout << SUM_time/double(I) << "	" << seed_ini << "	" << N_ini << endl;
}

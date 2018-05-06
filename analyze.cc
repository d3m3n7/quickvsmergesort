#include <iostream>
using namespace std;
int main(){
	int N,seed,C;
	double temps;
	cin>>N>>seed>>C;
	int n,n_temp;
	cin >> n_temp;
 	bool ordenat = true;
	for (int i=0; i < N-1 and ordenat; i++){
		cin>>n;
		if(n<n_temp) ordenat = false;
		n_temp = n;
	}
	if (ordenat){
		string s;
		for (int i= 0; i < 4;++i) cin>>s;
		cin >> temps;
	}

	if (ordenat) cout << "SUPERAT" << endl;
	else cout << "ERROR , n = " << n<<endl;
	cout << "---------------------------------" << endl;
	cout << "Temps: " << temps << endl;
	cout << "Seed: "<< seed<<endl;
	cout << "Size: "<< N << endl;
	cout << "Cyphers: " << C << endl;
	cout << "---------------------------------" << endl;

}

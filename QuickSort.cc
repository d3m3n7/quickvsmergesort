#include <iostream>
#include <vector>
using namespace std;
int C;	//xifres de cada element (DEFAULT)
int N;	//nombre d'elements del vector (DEFAULT)

int partition(vector <int>& T, int i, int j){
	int x = T[i], ii = i-1, jj = j+1;
	while(1){
		while(x < T[--jj]);
		while(T[++ii] < x);
		if (ii >= jj) return jj;
		swap(T[ii],T[jj]);
	}
}


void quickSort (vector <int>& T, int i, int j){
	if (i < j){
		int q = partition (T,i,j);
		quickSort (T,i,q);
		quickSort(T,q+1,j);
	}
}
/*LLEGEIX UN FITXER DE TEXT INPUT.TXT*/
int main(){
	int seed;
	cin>>N>>seed>>C;
	vector <int> experiment(N);
	int n;
	for (int i=0; i < N; i++){
		cin>>n;
		experiment[i]=n;
	}
	
	int start_s=clock();
	quickSort(experiment, 0, N-1);
	int stop_s=clock();
	cout << N <<" "<< seed <<" "<< C << endl;
	for (int i=0; i < N; i++){
		cout<<experiment[i]<<" ";
	}
	cout << endl;
	cout << "---------------------------------" << endl;
	cout << "Time in ms: "<< (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
	cout << "Seed: "<< seed <<endl;
	cout << "Size: "<< N << endl;
	cout << "Cyphers: " << C << endl;
	cout << "------------QUICKSORT------------" << endl;

}

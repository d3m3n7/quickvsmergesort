#include <iostream>
#include <vector>
using namespace std;
int C = 4;	//xifres de cada element (DEFAULT)
int N = 1000;	//nombre d'elements del vector (DEFAULT)

void fusion(vector <int>& T, int i,int m, int j){
	vector<int> B(j-i+1);
	int ii = i, jj = m+1, k= 0;
	while(ii<=m and jj <=j){
		if (T[ii] <= T[jj]) B[k++] = T[ii++];
		else B[k++] = T[jj++];
	}
	while (ii <= m) B[k++] = T[ii++];
	while (jj <= j) B[k++] = T[jj++];
	for (k = 0; k <= j-i; ++k) T[i+k] = B[k]; 
}


void mergeSort (vector <int>& T, int i, int j){
	if (i < j){
		int m = (i+j)/2	;
		mergeSort(T,i,m);
		mergeSort(T,m+1,j);
		fusion(T,i,m,j);
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
	mergeSort(experiment, 0, N-1);
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
	cout << "------------MERGESORT------------" << endl;

}

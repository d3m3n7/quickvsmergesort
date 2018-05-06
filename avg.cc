#include <iostream>
#include <stdlib.h>//atoi()
#include <fstream>

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
#include <time.h>


using namespace std;
void desa(char caso){
	string s;
	cin>>s;
	int N;
	if (s=="SUPERAT"){
		ofstream fsalida;
		if (caso == 'M')fsalida.open("timeM.log",ios::app);
		if (caso == 'Q')fsalida.open("timeQ.log",ios::app);
		
		double time;
		int seed;
		cin >> s;
		cin >> s;
		
			

		if (fsalida.is_open()){
			cin >> time;
			fsalida << time << "	";
			cin >> s;
			cin >> seed;
			fsalida << seed << "	";
			cin >> s;
			cin >> N;
			fsalida << N << endl;
			
		}
		fsalida.close();
	}
}

int main(int argc, char *argv[]){
	
	desa(argv[1][0]);	
}


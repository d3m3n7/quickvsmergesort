all: nGen vGen MergeSort QuickSort analyze avg process
nGen: nGen.o
	g++ -o nGen nGen.o

nGen.o: nGen.cc
	g++ -c nGen.cc
vGen: vGen.o
	g++ -o vGen vGen.o

vGen.o: vGen.cc
	g++ -c vGen.cc
MergeSort: MergeSort.o
	g++ -o MergeSort MergeSort.o

MergeSort.o: MergeSort.cc
	g++ -c MergeSort.cc

QuickSort: QuickSort.o
	g++ -o QuickSort QuickSort.o

QuickSort.o: QuickSort.cc
	g++ -c QuickSort.cc


analyze: analyze.o
	g++ -o analyze analyze.o

analyze.o: analyze.cc
	g++ -c analyze.cc


avg: avg.o
	g++ -o avg avg.o

avg.o: avg.cc
	g++ -c avg.cc


process: process.o
	g++ -o process process.o

process.o: process.cc
	g++ -c process.cc



HACER_3_PRUEBAS:
	./nGen >N.inp
	./vGen <N.inp> vector.inp

	./MergeSort <vector.inp >M.out
	./QuickSort <vector.inp >Q.out
	./analyze <M.out >veredict_M.txt
	./analyze <Q.out >veredict_Q.txt
	./avg M <veredict_M.txt
	./avg Q <veredict_Q.txt

	./MergeSort <vector.inp >M.out
	./QuickSort <vector.inp >Q.out
	./analyze <M.out >veredict_M.txt
	./analyze <Q.out >veredict_Q.txt
	./avg M <veredict_M.txt
	./avg Q <veredict_Q.txt

	./MergeSort <vector.inp >M.out
	./QuickSort <vector.inp >Q.out
	./analyze <M.out >veredict_M.txt
	./analyze <Q.out >veredict_Q.txt
	./avg M <veredict_M.txt
	./avg Q <veredict_Q.txt

MAKE_LOGS:
	./process <timeM.log >LOG_M.log
	./process <timeQ.log >LOG_Q.log
	

clean:
	rm *.o

fclean:
	rm nGen
	rm vGen
	rm MergeSort
	rm QuickSort
	rm analyze
	rm avg
	rm process
rm:
	
	rm *.inp
	rm *.out
	rm *.txt
	rm *.log
	

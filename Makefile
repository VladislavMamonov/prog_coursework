all: bin/sorting build/libfsdyn.so

bin/sorting: build/main.o build/InsertionSort.o build/HeapSort.o build/AdditionalFunctions.o
	gcc -Wall -Werror build/main.o build/InsertionSort.o build/HeapSort.o build/AdditionalFunctions.o -o bin/sorting

build/main.o: src/main.c
	gcc -Wall -Werror -c src/main.c -o build/main.o

build/InsertionSort.o: src/InsertionSort.c
	gcc -Wall -Werror -fPIC -c src/InsertionSort.c -o build/InsertionSort.o

build/HeapSort.o: src/HeapSort.c
	gcc -Wall -Werror -fPIC -c src/HeapSort.c -o build/HeapSort.o

build/AdditionalFunctions.o: src/AdditionalFunctions.c
	gcc -Wall -Werror -fPIC -c src/AdditionalFunctions.c -o build/AdditionalFunctions.o

build/libfsdyn.so: build/InsertionSort.o build/HeapSort.o build/AdditionalFunctions.o
	gcc -shared -o build/libfsdyn.so build/InsertionSort.o build/HeapSort.o build/AdditionalFunctions.o



clean:
	rm -rf build/*.o bin/sorting 
	rm -rf build/*.so
	rm -rf build/libfsdyn.so
all: bin/sorting

bin/sorting: build/main.o build/InsertionSort.o build/HeapSort.o build/AdditionalFunctions.o
	gcc -Wall -Werror -L. -LibSort build/main.o build/InsertionSort.o build/HeapSort.o build/AdditionalFunctions.o -o bin/sorting

build/main.o: src/main.c
	gcc -Wall -Werror -c src/main.c -o build/main.o

build/InsertionSort.o: src/InsertionSort.c
	gcc -Wall -Werror -fPIC -c src/InsertionSort.c -o build/InsertionSort.o

build/HeapSort.o: src/HeapSort.c
	gcc -Wall -Werror -fPIC -c src/HeapSort.c -o build/HeapSort.o

build/AdditionalFunctions.o: src/AdditionalFunctions.c
	gcc -Wall -Werror -fPIC -c src/AdditionalFunctions.c -o build/AdditionalFunctions.o


clean:
	rm -rf build/*.o bin/sorting
echo "Teste Proposto no Projeto\n"
g++ -std=c++11 -pedantic -I include/ src/driver_gremlins.cpp -o bin/exe && ./bin/exe

echo "Teste comparador SO vs GM\n"

g++ -std=c++11 -pedantic -I include/ src/drive_comparador.cpp -o bin/exe && ./bin/exe 

echo "Teste Allocate\n"

g++ -std=c++11 -pedantic -I include/ src/driver_generico.cpp -o bin/exe -D TIPO1 && ./bin/exe

echo "Teste Allocate_best\n"

g++ -std=c++11 -pedantic -I include/ src/driver_generico.cpp -o bin/exe -D TIPO2 && ./bin/exe

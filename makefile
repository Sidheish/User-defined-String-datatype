target = main.o string.o func_def.o
c++ = g++
project : $(target)
	${c++} ${target} -o project

main.o : main.cpp
	${c++} -c main.cpp
string.o: string.cpp
	${c++} -c string.cpp
func_def.o: func_def.cpp
	${c++} -c func_def.cpp

clear :
	@ echo "cleaning up"
	@ rm *.o

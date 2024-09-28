main: main.cpp
	g++ -o main.exe main.cpp -Llib/ -Iincludes/ -lraylib -lgdi32 -lwinmm
	.\main.exe

clean:
	del main.exe
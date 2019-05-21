# MTA-Transportation-Units-Info
This project is still being implemented.
The idea is to find a shortest path from one station to another by using a Breadth-First Search algorithm.

An early (partial) version of the project can be launched by downloading the files, and compiling the project with C++11 or later.

main.cpp contains one of the variations of the tasks that this project solves. Another variations can be tested by modifying the parameters in findShortestPath function in main.cpp file. Each parameter has to be a legitimate station found in names_of_stations.csv file. The program will output the shortest available route (if there is one) between the 2 stations, the names of which are passed as parameters. The output will be as follows: First station --> Second station --> Third station --> ... --> Last Station.
The files names_of_stations.csv and connections.csv represent a small part of the NYC subway system with about 8 stations (and connections between them) on the D,F,N, and Q lines close to Coney Island - Stillwell Avenue station.

!Please note that an alternative version of main.cpp, names_of_stations.csv, and connections.csv is available (main_alternative.cpp, names_of_stations_alternative.csv, etc), and these files show what the final input files and final output will look like. For now, only N and Q lines are available and can be accessed (see main_alternative.cpp for syntax)!

To compile and run the program:
1) Download all the files in the same folder
2) Compile with at least C++11. (g++ -std=c++11 main.cpp Station.cpp PathFinder.cpp)
3) Run the program (./a.out)

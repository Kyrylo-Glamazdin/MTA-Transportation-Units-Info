# MTA-Transportation-Units-Info

The idea of this project is to find a shortest path from one station to another by using a Breadth-First Search algorithm.

The project can be launched by downloading the files, and compiling them with C++11 or later.

main.cpp contains one of the variations of the tasks that this project solves. Another variations can be tested by modifying the parameters in printShortestPath function in main.cpp file. Each parameter has to be a legitimate station found in names_of_stations.csv file. The program will output the shortest available route (if there is one) between the 2 stations, the names of which are passed as parameters to printShortestPath function in main.cpp. The shortest route is the one with the smallest number of stations involved. The output will be as follows:

First station
Second station
Third station
...
Last Station

The files names_of_stations.csv and connections.csv represent a a full NYC subway system (with some simplifications) with about all of its stations and connections between them, including the express connections.
For a proper execution of the program, these files must be present in the same folder with the other files, must be in the right format as specified in these files, may not be empty and may not contain duplicate lines.


To compile and run the program:
1) Download all the files in the same folder
2) Compile with at least C++11. (g++ -std=c++11 main.cpp Station.cpp PathFinder.cpp)
3) Run the program (./a.out)

/*
 This file was created and modified by Kyrylo Glamazdin.
 
 This is the place to test the project and its main function for finding the shortest
 path between the two stations. In order to test the program, the following steps must
 be executed:
 1. Create an object of the PathFinder class.
 2. Read names of the stations from the input file.
 3. Read the connections between the stations from the input file.
 4. Print shortest path between the stations by calling printShortestPath function with
 the names of the stations as the parameters.
 5. Deallocate the memory.
 
 Copyright © 2019 Kyrylo Glamazdin.
*/

#include "PathFinder.hpp"

int main(){
    
    //create an object of the PathFinder class
    PathFinder the_path;
    
    //read the names of the stations and the connections between them
    the_path.readStationsInput("names_of_stations.csv");
    the_path.readConnectionsInput("connections.csv");
    
    //find and print the shortest path between the 2 stations
    the_path.printShortestPath("Bay Pkwy: N", "Times Sq - 42 St: N,Q,R,S,W,1,2,3,7");
    
    //deallocate memory
    the_path.delete_stations();
    
    
    return 0;
}

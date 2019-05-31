/*
 This file was created and modified by Kyrylo Glamazdin.
 
 This is the interface for the PathFinder class.
 It is used to read and process the input files with the names of the stations and
 the connections between them, and it creates the shortest possible path between the two stations
 (if there is one) by using the Breadth-First Search Algorithm.
 
 Copyright © 2019 Kyrylo Glamazdin.
*/

#ifndef PATHFINDER_
#define PATHFINDER_

#include <fstream>
#include <queue>
#include <string>
#include "Station.hpp"

class PathFinder{

public:
    
    /***CONSTRUCTORS***/
    
    //default constructor initializes an empty PathFinder object that can be
    //populated with stations and can find the shortest path to the needed station
    PathFinder();
    
    /***MUTATOR METHODS***/
    
    //adds a pointer to the station to stations_ vector
    void addStation(Station* st);
    //adds a pointer to the station to visited_stations_ vector
    void addVisitedStation(Station* visited_station);
    //deletes each object in stations_
    void delete_stations();
    
    /***HELPER METHODS***/
    
    //returns true if there is a pointer to a Station object that holds station_name in
    //the stations_ vector
    bool checkIfStationIsValid(string station_name) const;
    //returns true if there is a pointer to station with the name station_name in
    //visited_stations_ vector
    bool checkIfStationHasBeenVisited(string station_name) const;
    //returns true if there are at least 2 identical lines in the input
    //@pre: input file is not empty
    bool checkIfInputContainsIdenticalLines(const string name_of_input_file);
    //returns true if found at least 1 line in the input file with format other than
    //Name_of_station -> Name_of station
    //@pre: input file is not empty
    bool checkIfConnectionsAreInWrongFormat(const string name_of_input_file);
    //returns true if a string is at least 2 characters long and first 2 characters are '//'
    bool isComment(const string line_to_check);
    
    /***PROCESSING INPUT & DATA***/
    
    //@pre: input file does not contain stations with identical names
    //reads an input from a file and stores the stations in the stations_ vector
    //@param name_of_input_file accesses an external file by its name
    void readStationsInput(const string name_of_input_file);
    //@pre: input file contains no identical lines (connections)
    //reads an input from a file in format Station->Adjacent_Station on each line
    //accesses stations in stations_ vector that correspond by name with the station before
    //the arrow, and stores that station with the name after the arrow in its adjacent stations.
    //For example, reading a input "Times Square - 42 Street-> 34 Street - Herald Square" will
    //find a station, whose name corresponds to "Times Square - 42 Street" in stations_ vector,
    //then will find a station whose name is "34 Street - Herald Square" in the same vector,
    //and add a pointer to "34 Street - Herald Square" to the adjacent_nodes_ vector of
    //"Times Square - 42nd Street" station
    void readConnectionsInput(const string name_of_input_file);
    /*
     @param first_station is the name of the station from which the shortest path
     is to be found.
     @param last_station is the name of the destination station
     @pre: first_station and last_station are valid names of the stations (i.e. there
     are stations with such names in stations_ vector).
     This function serves as a wrapper for findShortestPath private function.
     It calls findShortestPath with first_station and last_station parameters,
     and prints the shortest path from first_station to last_station, if there is one.
     The printing is in the following format:
     
     First Station
     Second Station
     ...
     Last Station
     
     Only the actual names of the stations are displayed (i.e. the 'Times Square - 42 St' station
     will be displayed as 'Times Square - 42 St' without mentioning the trains that stop there).
    */
    void printShortestPath(string first_station, string last_station);

private:
    
    /***PROCESSING INPUT & DATA***/
    
    /*
     @param first_station is the name of the station from which the shortest path
     is to be found.
     @param last_station is the name of the destination station
     @pre: first_station and last_station are valid names of the stations (i.e. there
     are stations with such names in stations_ vector)
     finds the shortest path from first_station to last_station and returns a vector
     with pointers to each station in this path.
     In order to find the shortest path, this function uses a Breadth-First Search
     algorithm by utilizing a queue with all partial paths. These paths can be seen
     as the Tree structures where each path vector in the queue holds a sequence of
     stations that are adjacent to each other and exclude repetititon (one station
     other than the departure station can appear only once in only one of the paths,
     because if station is already present in one partial path, the shortest path
     to this station is already found and there is no need to include it again).
     returns an empty vector if there is no route
    */
    vector<Station*> findShortestPath(string first_station, string last_station);
    
    /***ACCESSOR METHODS***/
    
    //returns a pointer to the station with the name (item) is station_name
    //if station is not found, returns nullptr
    Station* getStationByName(string station_name) const;
    
    /***HELPER METHODS***/
    
    //deletes extra characters from the input string
    void trimInput(string& input_line);
    
    /***VARIABLES***/
    
    //the total number of pointers to Station objects in stations_ vector
    int num_of_stations_;
    //the total number of stations that have already been visited
    int num_of_visited_stations_;
    //a vector that hods pointers to the station objects initialized from input
    vector<Station*> stations_;
    //a vector that stores all the stations that have been already visited
    vector<Station*> visited_stations_;
};

#endif

/*
 This file was created and modified by Kyrylo Glamazdin.
 
 This is the interface for the Station class.
 A station is represented by its name and the trains that stop at this Station.
 Also, a station holds a vector of all the adjacent stations, which can be accessed
 directly from this station.
 The methods below are used to retrieve and modify the relevant variables and information
 about this Station.
 
 Copyright © 2019 Kyrylo Glamazdin.
*/

#ifndef STATION_
#define STATION_
#include <iostream>
#include <vector>
using namespace std;

class Station{
public:
    /***CONSTRUCTORS***/
    
    //parameterized constructor
    //@param station_name is the string that contains the name of the station.
    //It will be stored in full_station_name_
    Station (const string& station_name);
    //parameterized constructor
    //@param station_name is the string that contains the name of the station.
    //It will be stored in full_station_name_
    //@param adjacent_stations is the vector containing the nodes that are
    //adjacent to this station
    Station (const string& station_name, vector <Station* > adjacent_stations);
    
    
    /***MUTATOR METHODS***/
    
    //@param the_name is the name of this station
    //sets the full name of the station
    void setFullStationName(const string& the_name);
    //adds a station to adjacent_stations_ vector
    //@param adjacent_stations is the vector with the pointers to stations that are adjacent to this station
    void addAdjacentStation(Station* adjacent_station);
    
    //@param trains is a string with the name of the station and the trains that stop in it.
    //trains_vector_ is filled with strings that represent train names
    void setTrains(const string trains_line);
    //@param train is the string that hold the name of the trains that will be added to the
    //end of train_vector_
    void addTrain(const string train);
    //sets the name of the station without the sequence of trains
    void setActualName();
    //removes extra spaces from the name of the train
    void trimTrain(string& input_line);
    
    /***ACCESSOR METHODS***/
    
    //returns full_station_name_
    string getFullStationName() const;
    //returns adjacent_stations_
    vector<Station*> getAdjacentStations() const;
    //returns num_of_adjacent_stations_
    int getNumOfAdjacentStations() const;
    
    //returns train_vector_
    vector<string> getTrains() const;
    //returns num_of_trains_
    int getNumOfTrains() const;
    //returns actual_station_name_
    string getActualName() const;
    
private:
    //the full name of the station
    string full_station_name_;
    //vector with pointers to stations that are adjacent to this station
    vector <Station*> adjacent_stations_;
    //number of stations adjacent to this station
    int num_of_adjacent_stations_;
    //vector that will hold the names of the trains (ex. 'Q' or '5')
    vector <string> train_vector_;
    //the number of trains that stop at this station
    int num_of_trains_;
    //the name of the station without the trains
    //ex. Node with item 'Kings Highway: B,Q' will have a name 'Kings Highway'
    string actual_station_name_;
};

#endif

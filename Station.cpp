#include "Station.hpp"

/***CONSTRUCTORS***/

Station::Station(const string& station_name){
    num_of_adjacent_stations_ = 0;
    full_station_name_ = station_name;
    num_of_trains_ = 0;
    actual_station_name_ = "";
}//end constructor

Station::Station(const string& station_name, vector <Station*> adjacent_stations){
    num_of_adjacent_stations_ = adjacent_stations.size();
    full_station_name_ = station_name;
    adjacent_stations_ = adjacent_stations;
    num_of_trains_ = 0;
}//end constructor

/***MUTATOR METHODS***/

void Station::setFullStationName(const string& the_name){
    full_station_name_ = the_name;
}//end setFullStationName

void Station::addAdjacentStation(Station* adjacent_station){
    adjacent_stations_.push_back(adjacent_station);
    num_of_adjacent_stations_++;
}//end setAdjacentStation

void Station::setTrains(const vector<string> trains){
    num_of_trains_ = trains.size();
    train_vector_ = trains;
}//end setTrains

void Station::addTrain(const string train){
    train_vector_.push_back(train);
    num_of_trains_++;
}//end setTrain

void Station::setActualName(){
    string the_name = "";
    int i = 0;
    while (i < getFullStationName().size() && (int)getFullStationName()[i] != 58){
        the_name.push_back(getFullStationName()[i]);
        i++;
    }
    actual_station_name_ = the_name;
}//end setStationName

/***ACCESSOR METHODS***/

string Station::getFullStationName() const{
    return full_station_name_;
}//end getFullStationName

vector<Station*> Station::getAdjacentStations() const{
    return adjacent_stations_;
}//end getAdjacentStations

int Station::getNumOfAdjacentStations() const{
    return num_of_adjacent_stations_;
}//end getNumOfAdjacentStations

vector<string> Station::getTrains() const{
    return train_vector_;
}

int Station::getNumOfTrains() const{
    return num_of_trains_;
}

string Station::getActualName() const{
    return actual_station_name_;
}//end getActualName

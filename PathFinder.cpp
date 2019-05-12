#include "PathFinder.hpp"

/***CONSTRUCTORS***/

PathFinder::PathFinder(){
    num_of_stations_ = 0;
    num_of_visited_stations_ = 0;
}//end constructor

/***ACCESSOR METHODS***/

Station* PathFinder::getStationByName(string station_name) const{
    for (int i = 0; i < num_of_stations_; i++){
        if (stations_[i]->getItem() == station_name){
            return stations_[i];
        }
    }
    return nullptr;
}//end getStationByName

/***MUTATOR METHODS***/

void PathFinder::addStation(Station* st){
    stations_.push_back(st);
    num_of_stations_++;
}//end addStation

void PathFinder::addVisitedStation(Station* visited_station){
    visited_stations_.push_back(visited_station);
    num_of_visited_stations_++;
}//end addVisitedStation

void PathFinder::delete_stations(){
    for (int i = 0; i < num_of_stations_; i++){
        delete stations_[i];
        stations_[i] = nullptr;
    }
    num_of_stations_ = 0;
}

/***HELPER METHODS***/

bool PathFinder::checkIfStationIsValid(string station_name) const{
    //calls getStationByName with a passed parameter and returns true if station is found
    //i.e. getStationByName returns value other than nullptr
    return getStationByName(station_name) != nullptr;
}//end checkIfStationIsValid

bool PathFinder::checkIfStationHasBeenVisited(string station_name) const{
    for (int i = 0; i < num_of_visited_stations_; i++){
        if (visited_stations_[i]->getItem() == station_name){
            return true;
        }
    }
    return false;
}//end checkIfStationHasBeenVisited

bool PathFinder::checkIfInputContainsIdenticalLines(string name_of_input_file){
    string next_line = "";
    vector<string> input_elements;
    ifstream input_file (name_of_input_file); //open fstream
    while(getline(input_file, next_line)){
        input_elements.push_back(next_line); //add each line as a string to input_elements vector
    }
    input_file.close();
    
    //if identical element is found, return true. else return false
    for (int i = 0; i < input_elements.size(); i++){
        for (int j = i+1; j < input_elements.size(); j++){
            if (input_elements[i].size() > 0 && input_elements[j].size() > 0 && input_elements[i] == input_elements[j]){
                return true;
            }
        }
    }
    return false;
}//end checkIfInputContainsIdenticalLines

/***PROCESSING INPUT & DATA***/

void PathFinder::readStationsInput(const string name_of_input_file){
    string next_line = "";
    ifstream input_file (name_of_input_file);
    //throw an exception if an input file is invalid, i.e. if there are duplicate lines or
    //if the file is empty
    try{
        bool invalid_file = (input_file.peek() == ifstream::traits_type::eof() || checkIfInputContainsIdenticalLines(name_of_input_file));
        if (invalid_file){
            throw invalid_file;
        }
    }
    catch (bool invalid_file){
        cerr << "Invalid File" << endl;
        input_file.close();
        return;
    }
    
    //if file is valid, create a new Station with the name taken from each line of input file,
    //and, if its length is greater than 0, add a station to stations_ vector
    while(getline(input_file, next_line)){
        if (next_line.size() > 0){
            Station* station_to_be_added = new Station(next_line);
            addStation(station_to_be_added);
        }
    }
    
    input_file.close();
}//end readStationsInput

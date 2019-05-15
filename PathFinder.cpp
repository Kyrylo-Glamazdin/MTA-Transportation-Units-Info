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

bool PathFinder::checkIfInputContainsIdenticalLines(const string name_of_input_file){
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

bool PathFinder::checkIfConnectionsAreInWrongFormat(const string name_of_input_file){
    string next_line = "";
    vector<string> input_elements;
    ifstream input_file (name_of_input_file); //open fstream
    while(getline(input_file, next_line)){
        input_elements.push_back(next_line); //copying each element to input_elements vector
    }
    input_file.close(); //close fstream
    
    //if the number of arrows (->) in a line is not equal to 1, then the line is in the wrong format
    for(int i = 0; i < input_elements.size(); i++){
        int arrow_counter = 0;
        for (int j = 0; j < input_elements[i].size() - 1; j++){
            //an arrow is found if one of the characters in the string is '-' and the
            //following is '>'
            if ((int)input_elements[i][j] == 45 && (int)input_elements[i][j+1] == 62){
                arrow_counter++;
            }
        }
        //formatting is wrong if at least one line contains less or more than 1 arrow '->'
        if (arrow_counter != 1){
            return true;
        }
    }
    return false; //return false if format is correct
}

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
        cerr << "Invalid Stations File" << endl;
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

void PathFinder::readConnectionsInput(const string name_of_input_file){
    string next_line = "";
    ifstream input_file (name_of_input_file);
    //throw an exception if an input file is invalid, i.e. if there are duplicate lines or
    //if the file is empty
    try{
        bool invalid_file = (input_file.peek() == ifstream::traits_type::eof() || checkIfInputContainsIdenticalLines(name_of_input_file) ||
            checkIfConnectionsAreInWrongFormat(name_of_input_file));
        if (invalid_file){
            throw invalid_file;
        }
    }
    catch (bool invalid_file){
        cerr << "Invalid Connections File" << endl;
        input_file.close();
        return;
    }
    //!!!!TODO add trim function
    while(getline(input_file, next_line)){
        //each line from input has to be greater than 3,
        //so that it is not empty, contains at least 1 arrow (->), and at least 2 stations
        //that are at least 1 characters long each
        string departure_station = "";
        string adjacent_station = "";
        if (next_line.size() > 3){
            int index = 0;
            while(index < next_line.size() - 1){
                if (!((int)next_line[index] == 45 && (int)next_line[index + 1] == 62)){
                    departure_station.push_back(next_line[index]);
                }
                else{
                    break;
                }
                index++;
            }
            
            index+=2;
            while (index < next_line.size()){
                adjacent_station.push_back(next_line[index]);
                index++;
            }
        }
        
        try{
            bool station_doesnt_exist = (getStationByName(departure_station) == nullptr ||
                getStationByName(adjacent_station) == nullptr);
            if (station_doesnt_exist){
                throw station_doesnt_exist;
            }
        }
        catch (bool station_doesnt_exist){
            cerr << "Station " << departure_station <<
            " OR station " << adjacent_station << " doesn't exist" << endl;
            input_file.close();
            return;
        }
        getStationByName(departure_station)->addAdjacentNode(getStationByName(adjacent_station));
        departure_station = "";
        adjacent_station = "";
    }
    
    input_file.close();
}//end readConnectionsInput

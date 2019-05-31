/*
 This file was created and modified by Kyrylo Glamazdin.
 
 This is the implementation of the constructors and methods of the Station class.
 For more information please see the interface for this class.
 
 Copyright © 2019 Kyrylo Glamazdin.
*/

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

void Station::setTrains(const string trains_line){
    int i = 0;
    while (i < trains_line.size() && (int)trains_line[i] != 58){
        i++;
    }
    i++;
    string next_train = "";
    while (i < trains_line.size()){
        if ((int)trains_line[i] == 44){
            trimTrain(next_train);
            if (next_train.size() > 0){
                train_vector_.push_back(next_train);
                num_of_trains_++;
            }
            next_train = "";
        }
        else{
            next_train.push_back(trains_line[i]);
        }
        i++;
    }
    trimTrain(next_train);
    //add the last train (which doesn't have a comma after its name) to train_vector_
    if (next_train.size() > 0){
        train_vector_.push_back(next_train);
        num_of_trains_++;
    }
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

void Station::trimTrain(string& input_line){
    //find first non-space character
    int left_index = 0;
    while(left_index < input_line.size() && (int)input_line[left_index] == 32){
        left_index++;
    }
    //if the number of spaces is equal to the size of input_line, then the whole string consists of spaces
    if (left_index == input_line.size()){
        input_line = ""; //return empty string
        return;
    }
    
    //if a string consists not only of spaces, find the number of spaces on the right size
    int right_index = 0;
    while(right_index < input_line.size() && (int)input_line[input_line.size() - 1 - right_index] == 32){
        right_index++;
    }
    int difference = input_line.size() - right_index - left_index; //the length of substring with no spaces on the sides
    string shortened = input_line.substr(left_index, difference); //remove extra spaces
    input_line = shortened;
}//end trimTrain

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

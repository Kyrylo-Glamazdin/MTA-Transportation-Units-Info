#include "Station.hpp"

/***CONSTRUCTORS***/

Station::Station(const string& station_name):Node<string>(station_name){
    num_of_trains_ = 0;
}//end constructor

Station::Station(const string& station_name, vector <Node<string>* > adjacent_stations):
    Node<string>(station_name, adjacent_stations){
        num_of_trains_ = 0;
}//end constructor

/***MUTATOR METHODS***/

void Station::setTrains(const vector<string> trains){
    num_of_trains_ = trains.size();
    train_vector_ = trains;
}//end setTrains

void Station::addTrain(const string train){
    train_vector_.push_back(train);
    num_of_trains_++;
}//end setTrain

/***ACCESSOR METHODS***/

vector<string> Station::getTrains() const{
    return train_vector_;
}

int Station::getNumOfTrains() const{
    return num_of_trains_;
}

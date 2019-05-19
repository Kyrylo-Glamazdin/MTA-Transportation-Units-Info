#include "PathFinder.hpp"

/***CONSTRUCTORS***/

PathFinder::PathFinder(){
    num_of_stations_ = 0;
    num_of_visited_stations_ = 0;
}//end constructor

/***ACCESSOR METHODS***/

Node<string>* PathFinder::getStationByName(string station_name) const{
    for (int i = 0; i < num_of_stations_; i++){
        if (stations_[i]->getItem() == station_name){
            return stations_[i];
        }
    }
    return nullptr;
}//end getStationByName

/***MUTATOR METHODS***/

void PathFinder::addStation(Node<string>* st){
    stations_.push_back(st);
    num_of_stations_++;
}//end addStation

void PathFinder::addVisitedStation(Node<string>* visited_station){
    visited_stations_.push_back(visited_station);
    num_of_visited_stations_++;
}//end addVisitedStation

void PathFinder::delete_stations(){
    for (int i = 0; i < num_of_stations_; i++){
        delete stations_[i];
        stations_[i] = nullptr;
    }
    stations_.clear();
    num_of_stations_ = 0;
}

/***HELPER METHODS***/

bool PathFinder::checkIfStationIsValid(string station_name) const{
    //calls getStationByName with a passed parameter and returns true if station is found
    //i.e. getStationByName returns value other than nullptr
    return station_name.size() > 0 && getStationByName(station_name) != nullptr;
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
            if (!isComment(input_elements[i]) && input_elements[i].size() > 0 && input_elements[j].size() > 0 && input_elements[i] == input_elements[j]){
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
        if (!isComment(input_elements[i]) && arrow_counter != 1){
            return true;
        }
    }
    return false; //return false if format is correct
}

void PathFinder::trimInput(string& input_line){
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
}//end trimInput

bool PathFinder::isComment(const string line_to_check){
    return line_to_check.size() > 1 && (int)line_to_check[0] == 47 && (int)line_to_check[1] == 47;
}//end is comment

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
        if (next_line.size() > 0 && !isComment(next_line)){
            trimInput(next_line);
            Node<string>* station_to_be_added = new Station(next_line);
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
    while(getline(input_file, next_line)){
        //each line from input has to be greater than 3,
        //so that it is not empty, contains at least 1 arrow (->), and at least 2 stations
        //that are at least 1 characters long each
        if (!isComment(next_line)){
            string departure_station = "";
            string adjacent_station = "";
            if (next_line.size() > 3){
                int index = 0;
                //read the departure station
                while(index < next_line.size() - 1){
                    if (!((int)next_line[index] == 45 && (int)next_line[index + 1] == 62)){
                        departure_station.push_back(next_line[index]);
                    }
                    else{
                        break;
                    }
                    index++;
                }
            
                //skip the arrow
                index+=2;
                //read the destination station
                while (index < next_line.size()){
                    adjacent_station.push_back(next_line[index]);
                    index++;
                }
            }
            //remove extra characters on the sides
            trimInput(departure_station);
            trimInput(adjacent_station);
            //if both stations are valid, create a connection
            if (checkIfStationIsValid(departure_station) && checkIfStationIsValid(adjacent_station)){
                getStationByName(departure_station)->addAdjacentNode(getStationByName(adjacent_station));
            }
            else{
                cerr << "Station '" << departure_station <<
                "' OR station '" << adjacent_station << "' doesn't exist" << endl << endl;
            }
            departure_station = "";
            adjacent_station = "";
        }
    }
    
    input_file.close();
}//end readConnectionsInput

vector<Node<string>*> PathFinder::findShortestPath(string first_station, string last_station){
    //remove extra characters on the sides of first_station and last_station
    trimInput(first_station);
    trimInput(last_station);
    //if first_station or last_station doesn't exist, terminate the function
    try{
        bool station_doesnt_exist = (!(checkIfStationIsValid(first_station) &&
                                     checkIfStationIsValid(last_station)));
        if (station_doesnt_exist){
            throw station_doesnt_exist;
        }
    }
    catch (bool station_doesnt_exist){
        cerr << "Station '" << first_station <<
        "' OR station '" << last_station << "' doesn't exist" << endl;
        vector<Node<string>*> empty_vector;
        return empty_vector;
    }
    
    //create a queue to hold the possiblie routes
    queue<vector<Node<string>*> > possible_paths;
    Node<string>* current_station = getStationByName(first_station);
    //mark first_station as visited
    addVisitedStation(current_station);
    vector<Node<string>*> partial_routes;
    //add first station to the vector and push it int the queue
    partial_routes.push_back(current_station);
    possible_paths.push(partial_routes);
    
    //try to find a path while queue is not empty
    //if queue is empty, then there is no path
    while(!possible_paths.empty()){
        //the front of the queue is always a ponential shortest path.
        //retrieve a vector with partial poute from the front of the vector
        vector<Node<string>*> potential_solution = possible_paths.front();
        possible_paths.pop();
        //a shortest route is found when the last station in the vector from the front of the queue is a last_station, passed as a parameter
        if (potential_solution.size() > 0
            && potential_solution[potential_solution.size() - 1]->getItem() == last_station){
            return potential_solution;
        }
        //for each of the adjacent stations to the last station in the vector from the front of the queue,
        //copy a current partial route into the new vector, push each adjacent station to the back
        //of the vector, and push the resulting vector to the back of the queue
        for (int i = 0; i < potential_solution[potential_solution.size() - 1]->getNumOfAdjacentNodes(); i++){
            Node<string>* station_adjacent_to_current = potential_solution[potential_solution.size() - 1]->getAdjacentNodes()[i];
            if(!checkIfStationHasBeenVisited(station_adjacent_to_current->getItem())){
                vector<Node<string>*> copy_of_potential_solution = potential_solution;
                copy_of_potential_solution.push_back(station_adjacent_to_current);
                addVisitedStation(station_adjacent_to_current);
                possible_paths.push(copy_of_potential_solution);
            }
        }
    }
    //return an empty vector if the route is not found
    vector<Node<string>*> empty_vector;
    return empty_vector;
}//end findShortestPath

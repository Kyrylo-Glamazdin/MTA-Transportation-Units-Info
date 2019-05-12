#ifndef STATION_
#define STATION_

#include "Node.hpp"

class Station: public Node<string>{
public:
    /***CONSTRUCTORS***/
    
    //parameterized constructor
    //@param station_name is the string that contains the name of the station.
    //It will be passed to the Node and will be stored in item_
    Station (const string& station_name);
    //parameterized constructor
    //@param station_name is the string that contains the name of the station.
    //It will be passed to the Node and will be stored in item_
    //@param adjacent_stations is the vector containing the nodes that are
    //adjacent to this station. Since Station is derived from Node, in the node class
    //a private variable adjacent_nodes_ will hold a vector with items of type Node<string>,
    //which are the pointers to the adjacent stations.
    Station (const string& station_name, vector <Node<string>* > adjacent_stations);
    
    
    /***MUTATOR METHODS***/
    
    //@param trains is a vector with objects of type strings that represent the names
    //of the trains at this station
    //The value of trains_vector_ are replaced with the values of trains
    void setTrains(const vector<string> trains);
    //@param train is the string that hold the name of the trains that will be added to the
    //end of train_vector_
    void addTrain(const string train);
    
    /***ACCESSOR METHODS***/
    
    //returns train_vector_
    vector<string> getTrains() const;
    //returns num_of_trains_
    int getNumOfTrains() const;
    
private:
    //vector that will hold the names of the trains (ex. 'Q' or '5')
    vector <string> train_vector_;
    //the number of trains that stop at this station
    int num_of_trains_;
};

#endif

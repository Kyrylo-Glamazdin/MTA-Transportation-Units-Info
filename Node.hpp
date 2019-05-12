#ifndef NODE_
#define NODE_
#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Node{
public:
    /*CONSTRUCTORS*/
    
    //constructor with an element
    //@param an_item is the main element that the node holds
    Node (const T& an_item);
    //constructor with an element and a vector of adjacent nodes
    //@param an_item is the main element that the node holds
    //@param adjacent_nodes is the vector with the pointers to nodes that are adjacent to this node
    Node (const T& an_item, vector <Node<T>* > adjacent_nodes);
    
    /*MUTATOR METHODS*/
    
    //@param an_item is the main element that the node holds
    void setItem(const T& an_item);
    //@param adjacent_nodes is the vector with the pounters to nodes that are adjacent to this node
    void setAdjacentNodes(vector <Node<T>* > adjacent_nodes);
    //@param adjacent_node is the node to be added to adjacent_nodes_ vector
    void addAdjacentNode(Node<T>* adjacent_node);
    
    /*ACCESSOR METHODS*/
    
    //returns item_
    T getItem() const;
    //returns adjacent_nodes_
    vector<Node<T>* > getAdjacentNodes() const;
    //returns num_of_adjacent_nodes
    int getNumOfAdjacentNodes() const;
private:
    //the main element that the node holds
    T item_;
    //vector with pointers to nodes that are adjacent to this node
    vector <Node<T>* > adjacent_nodes_;
    //number of nodes adjacent to this nodes
    int num_of_adjacent_nodes_;
};

#include "Node.cpp"
#endif

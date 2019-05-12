#include "Node.hpp"

/***CONSTRUCTORS***/


template <class T>
Node<T>::Node(const T& an_item){
    num_of_adjacent_nodes_ = 0;
    item_ = an_item;
}//end constructor

template <class T>
Node<T>::Node(const T& an_item, vector<Node<T>* > adjacent_nodes){
    num_of_adjacent_nodes_ = adjacent_nodes.size();
    item_ = an_item;
    adjacent_nodes_ = adjacent_nodes;
}//end constructor


/***MUTATOR METHODS***/

template <class T>
void Node<T>::setItem(const T& an_item){
    item_ = an_item;
}//end setItem

template <class T>
void Node<T>::setAdjacentNodes(vector<Node<T>* > adjacent_nodes){
    num_of_adjacent_nodes_ = adjacent_nodes.size();
    adjacent_nodes_ = adjacent_nodes;
}//end setAdjacentNodes

template <class T>
void Node<T>::addAdjacentNode(Node<T>* adjacent_node){
    adjacent_nodes_.push_back(adjacent_node);
    num_of_adjacent_nodes_++;
}

/***ACCESSOR METHODS***/

template <class T>
T Node<T>::getItem() const{
    return item_;
}//end getItem

template <class T>
vector<Node<T>* > Node<T>::getAdjacentNodes() const{
    return adjacent_nodes_;
}//end getAdjacentNodes

template <class T>
int Node<T>::getNumOfAdjacentNodes() const{
    return num_of_adjacent_nodes_;
}//end getNumOfAdjacentNodes

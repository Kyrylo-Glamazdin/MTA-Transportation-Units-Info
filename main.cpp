#include "Node.hpp"
#include "Station.hpp"
#include "PathFinder.hpp"

int main(){
    
    PathFinder p;
    
    p.readStationsInput("names_of_stations.csv");
    p.readConnectionsInput("connections.csv");
    vector<Node<string>*> result = p.findShortestPath("New Utrecht Av", "Sheepshead Bay");
    
    for (int i = 0; i < result.size(); i++){
        if (i < result.size() - 1){
            cout << result[i]->getItem() << " --> ";
        }
        else{
            cout << result[i]->getItem() << endl;
        }
    }
    
    
    p.delete_stations();
    
    return 0;
}

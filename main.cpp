#include "PathFinder.hpp"

int main(){
    
    PathFinder p;
    
    p.readStationsInput("names_of_stations.csv");
    p.readConnectionsInput("connections.csv");
    vector<Station*> result = p.findShortestPath("New Utrecht Av", "Sheepshead Bay");
    
    for (int i = 0; i < result.size(); i++){
        if (i < result.size() - 1){
            cout << result[i]->getActualName() << " --> ";
        }
        else{
            cout << result[i]->getActualName() << endl;
        }
    }
    
    
    p.delete_stations();
    
    
    return 0;
}

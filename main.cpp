#include "PathFinder.hpp"

int main(){
    
    PathFinder p;
    p.readStationsInput("names_of_stations.csv");
    p.readConnectionsInput("connections.csv");
    vector<Station*> result = p.findShortestPath("Bay Pkwy: N", "Times Sq - 42 St: N,Q,R,S,W,1,2,3,7");
    
    cout << endl;
    
    for (int i = 0; i < result.size(); i++){
        cout << result[i]->getActualName() << endl;
    }
    
    cout << endl;
    
    p.delete_stations();
    
    
    return 0;
}

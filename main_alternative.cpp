#include "PathFinder.hpp"

int main(){
    
    PathFinder p;
    p.readStationsInput("names_of_stations_alternative.csv");
    p.readConnectionsInput("connections_alternative.csv");
    vector<Station*> result = p.findShortestPath("Coney Island - Stillwell Av: D,F,N,Q", "Times Sq - 42 St: N,Q,R,S,W,1,2,3,7");
    
    cout << endl;
    
    for (int i = 0; i < result.size(); i++){
        cout << result[i]->getActualName() << endl;
    }
    
    cout << endl;
    
    p.delete_stations();
    
    
    return 0;
}

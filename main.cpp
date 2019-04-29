#include "date.h"
#include "query_handler.h"

using namespace std;

int main(){
    auto since_epoch = chrono::steady_clock::now().time_since_epoch();
    int seed = chrono::duration_cast<chrono::milliseconds>(since_epoch).count();
    srand(seed);
    while(true){
        string query;
        getline(cin, query);
        QueryHandler handler;
        handler.Handle(query);
    }

    return 0;
}
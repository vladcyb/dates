#include "date.h"
#include "query_handler.h"

int main(){
    auto since_epoch = std::chrono::steady_clock::now().time_since_epoch();
    int seed = std::chrono::duration_cast<std::chrono::milliseconds>(since_epoch).count();
    srand(seed);
    while(true){
        std::string query;
        std::getline(std::cin, query);
        QueryHandler handler;
        handler.Handle(query);
    }
    return 0;
}
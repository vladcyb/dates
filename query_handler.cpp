#include "query_handler.h"

void QueryHandler::Handle(const std::string& query) const {
    std::stringstream ss(query);
    std::string first_word;
    ss >> first_word;
    if (first_word == "generate"){
        int count_dates_to_generate;
        std::string output_filename;
        ss >> count_dates_to_generate;
        ss >> output_filename;
        std::ofstream out(output_filename);
        for(int i = 0; i < count_dates_to_generate; ++i){
            out << DateGenerator::GetRandomDate() << endl;
        }
        out.close();
    }
}
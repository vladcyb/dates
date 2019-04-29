#ifndef QUERY_HANDLER_H
#define QUERY_HANDLER_H

#include "date_generator.h"

class QueryHandler{
public:
    void Handle(const std::string& query) const;
private:
    std::ifstream::pos_type GetSize(const std::string& filename) const;
    bool CheckOnFails(std::stringstream& ss, const std::string& message) const;
    bool CheckWriteAvailable(std::ofstream& out, const std::string& output_filename) const;
};


#endif   // QUERY_HANDLER_H
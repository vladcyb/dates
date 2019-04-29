#ifndef QUERY_HANDLER_H
#define QUERY_HANDLER_H

#include "date_generator.h"

class QueryHandler{
public:
    void Handle(const std::string& query) const;
private:
    std::ifstream::pos_type GetSize(const string& filename) const;
};


#endif   // QUERY_HANDLER_H
#ifndef KLV_PARSER_H_
#define KLV_PARSER_H_

#include <fstream>

class KLVParser {
public:
    KLVParser(const std::ifstream &source, int keyLength);
};

#endif /* KLV_PARSER_H_ */
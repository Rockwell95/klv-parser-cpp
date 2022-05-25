#ifndef STREAM_PARSER_H_
#define STREAM_PARSER_H_

#include <string>
#include <unordered_map>
#include <fstream>
#include "KLVParser.h"

using std::string;
using std::unordered_map;
using std::byte;

class StreamParser {
private:
    unordered_map<byte, byte> _parsers;

    std::ifstream _source;
    KLVParser _iterStream;

    unordered_map<byte, byte>::iterator _current;

public:
    explicit StreamParser(std::ifstream &source);

    ~StreamParser() = default;

    unordered_map<byte, byte>::iterator begin();
    unordered_map<byte, byte>::iterator end();

    void addParser(byte parser);
};

#endif /*STREAM_PARSER_H_*/
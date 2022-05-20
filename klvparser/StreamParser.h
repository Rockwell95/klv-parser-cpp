#ifndef STREAM_PARSER_H_
#define STREAM_PARSER_H_

#include <string>
#include <unordered_map>
#include "KLVParser.h"

using std::string;
using std::unordered_map;
using std::byte;

class StreamParser
{
private:
    unordered_map<byte, byte> parsers;

    std::ifstream source;
    KLVParser iterStream;

    unordered_map<byte, byte>::iterator begin;
    unordered_map<byte, byte>::iterator current;
    unordered_map<byte, byte>::iterator end;

public:
    StreamParser(const std::ifstream& source);
    ~StreamParser() = default;
    void addParser(byte parser);
};

#endif /*STREAM_PARSER_H_*/
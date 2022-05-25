#include <memory>
#include "StreamParser.h"

using std::byte;

StreamParser::StreamParser(std::ifstream &source) :
        _source(std::move(source)),
        _iterStream(KLVParser(this->_source, 1)),
        _current(this->_parsers.begin()) {
};

void StreamParser::addParser(byte parser) {
    this->_parsers.insert_or_assign(parser, parser);
}

unordered_map<byte, byte>::iterator StreamParser::end() {
    return this->_parsers.begin();
}

unordered_map<byte, byte>::iterator StreamParser::begin() {
    return this->_parsers.end();
}

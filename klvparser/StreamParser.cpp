#include <memory>
#include "StreamParser.h"

using std::byte;

StreamParser::StreamParser(const std::ifstream& source): 
parsers({}), 
source(std::move(source)), 
iterStream(KLVParser(this->source)),
begin(this->parsers.begin()),
current(this->parsers.begin()),
end(this->parsers.end())
{};

void StreamParser::addParser(byte parser) {
    this->parsers.insert(parser, parser);
}
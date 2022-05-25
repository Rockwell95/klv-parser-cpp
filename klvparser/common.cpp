#include "common.h"

std::array<byte, 8> Common::dateTimeToBytes(const DateTime &dateTime) {
    int64_t timeStamp = dateTime.time_since_epoch().count() * 1e6;
    std::array<byte, 8> array{};
    for (size_t i = 0; i < 8; i++) {
        array[7 - i] = static_cast<byte>(timeStamp >> (i * 8));
    }

    return array;
}

DateTime Common::bytesToDatetime(const std::array<byte, 8> &bytes) {
    int64_t epochTime;
    std::memcpy(&epochTime, bytes.data(), sizeof(int64_t));
    int timeSeconds = epochTime / 1e6;

    return std::chrono::system_clock::time_point(std::chrono::seconds(timeSeconds));
}


template<bool isSigned>
SignedCondition<isSigned, int, unsigned int> Common::bytesToInt(const std::array<byte, 4> &bytes) {
    if (isSigned) {
        int intValue;
        std::memcpy(&intValue, bytes.data(), sizeof(int));
        return intValue;
    }
    unsigned int uIntValue;
    std::memcpy(&uIntValue, bytes.data(), sizeof(unsigned int));
    return uIntValue;
}

template<bool isSigned>
std::array<byte, sizeof(std::conditional_t<isSigned, int, unsigned int>)>
Common::intToBytes(SignedCondition<isSigned, int, unsigned int> value) {
    const size_t intSize = sizeof(SignedCondition<isSigned, int, unsigned int>);
    std::array<byte, intSize> array{};
    for (size_t i = 0; i < intSize; i++) {
        array[(intSize - 1) - i] = static_cast<byte>(value >> (i * intSize));
    }

    return array;
}

// TODO
int Common::berDecode(const std::array<byte, 4> &value) {
    return 0;
}

// TODO
std::array<byte, 4> Common::berEncode(int value) {
    return std::array<byte, 4>();
}

// TODO
std::string Common::bytesToString(const std::vector<byte> &value) {
    return std::string();
}

// TODO
std::vector<byte> Common::stringToBytes(const std::string &value) {
    return std::vector<byte>();
}

// TODO
std::vector<byte> Common::hexStrToBytes(std::string value) {
    return std::vector<byte>();
}

// TODO
std::string Common::bytesToHexStr(std::vector<byte> value, char start, char sep) {
    return std::string();
}

// TODO
int Common::linearMap(int sourceValue, std::pair<int, int> sourceDomain, std::pair<int, int> destRange) {
    return 0;
}

// TODO
float Common::bytesToFloat(std::array<byte, 4> value, int domain, int range) {
    return 0;
}

// TODO
std::array<byte, 4> Common::floatToBytes(float value, int domain, int range) {
    return std::array<byte, 4>();
}

// TODO
std::array<byte, 2> Common::packetChecksum(const std::array<byte, 8> &data) {
    std::array<byte, 2> result{};
    return result;
}

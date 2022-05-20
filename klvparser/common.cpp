#include "common.h"

byte* Common::dateTimeToBytes(const DateTime &dateTime)
{
    int64_t timeStamp = dateTime.time_since_epoch().count() * 1e6;
    byte array[8];
    for (size_t i = 0; i < 8; i++)
    {
        array[3 - i] = static_cast<byte>(timeStamp >> (i * 8));
    }

    return array;
}

DateTime Common::bytesToDatetime(const byte *bytes)
{
    long epochTime;
    std::memcpy(&epochTime, bytes, sizeof(long));
    int timeSeconds = epochTime / 1e6;

    return std::chrono::system_clock::time_point(std::chrono::seconds(timeSeconds));
}
#ifndef COMMON_H_
#define COMMON_H_

#include <iostream>
#include <array>
#include <vector>
#include <chrono>
#include <cstring>

using std::byte;
using DateTime = std::chrono::system_clock::time_point;

template<bool Signed, class Type1, class Type2>
using SignedCondition = std::conditional_t<Signed, Type1, Type2>;

namespace Common {

    /**
     * @brief Return bytes representing UTC time in microseconds.
     *
     * @param dateTime Chrono date object
     * @return byte* Date object as Byte array
     */
    std::array<byte, 8> dateTimeToBytes(const DateTime &dateTime);

    /**
     * @brief Return datetime from microsecond bytes
     *
     * @param bytes Byte array of binary data for datetime
     * @return DateTime chrono date_time object.
     */
    DateTime bytesToDatetime(const std::array<byte, 8> &bytes);

    /**
     * Return integer given bytes.
     * @param bytes Byte array to convert to int
     * @return int
     */
    template<bool isSigned>
    SignedCondition<isSigned, int, unsigned int> bytesToInt(const std::array<byte, 4> &bytes);

    /**
     * Return bytes given integer
     * @tparam isSigned Whether or not the integer is signed or unsigned (necessary for runtime typing)
     * @param value Integer value to convert to byte array
     * @return byte array
     */
    template<bool isSigned>
    std::array<byte, sizeof(SignedCondition<isSigned, int, unsigned int>)>
    intToBytes(SignedCondition<isSigned, int, unsigned int> value);

    // def ber_decode(value):
    //     """Return decoded BER length as integer given bytes."""
    //     if bytes_to_int(value) < 128:
    //         if len(value) > 1:
    //             raise ValueError

    //         # Return BER Short Form
    //         return bytes_to_int(value)
    //     else:
    //         if len(value) != (value[0] - 127):
    //             raise ValueError

    //         # Return BER Long Form
    //         return bytes_to_int(value[1:])
    int berDecode(const std::array<byte, 4> &value);

    // def ber_encode(value):
    //     """Return encoded BER length as bytes given integer."""
    //     if value < 128:
    //         # BER Short Form
    //         return int_to_bytes(value)
    //     else:
    //         # BER Long Form
    //         byte_length = ((value.bit_length() - 1) // 8) + 1

    //         return int_to_bytes(byte_length + 128) + int_to_bytes(value, length=byte_length)
    std::array<byte, 4> berEncode(int value);

    // def bytes_to_str(value):
    //     """Return UTF-8 formatted string from bytes object."""
    //     return bytes(value).decode('UTF-8')
    std::string bytesToString(const std::vector<byte> &value);

    // def str_to_bytes(value):
    //     """Return bytes object from UTF-8 formatted string."""
    //     return bytes(str(value), 'UTF-8')
    std::vector<byte> stringToBytes(const std::string &value);

    // def hexstr_to_bytes(value):
    //     """Return bytes object and filter out formatting characters from a string of hexadecimal numbers."""
    //     return bytes.fromhex(''.join(filter(str.isalnum, value)))
    std::vector<byte> hexStrToBytes(std::string value);

    // def bytes_to_hexstr(value, start='', sep=' '):
    //     """Return string of hexadecimal numbers separated by spaces from a bytes object."""
    //     return start + sep.join(["{:02X}".format(byte) for byte in bytes(value)])
    std::string bytesToHexStr(std::vector<byte> value, char start = '\0', char sep = ' ');

    // def linear_map(src_value, src_domain, dst_range):
    //     """Maps source value (src_value) in the source domain
    //     (source_domain) onto the destination range (dest_range) using linear
    //     interpretation.

    //     Except that at the moment src_value is a bytes value that once converted
    //     to integer that it then is on the src_domain.

    //     Ideally would like to move the conversion from bytes to int externally.

    //     Once value is same base and format as src_domain (i.e. converted from bytes),
    //     it should always fall within the src_domain. If not, that's a problem.
    //     """
    //     src_min, src_max, dst_min, dst_max = src_domain + dst_range
    //     # assert(src_min <= src_value <= src_max)

    //     if not (src_min <= src_value <= src_max):
    //         raise ValueError

    //     slope = (dst_max - dst_min) / (src_max - src_min)
    //     dst_value = slope * (src_value - src_min) + dst_min

    //     if not (dst_min <= dst_value <= dst_max):
    //         raise ValueError

    //     return dst_value
    int linearMap(int sourceValue, std::pair<int, int> sourceDomain, std::pair<int, int> destRange);

    // def bytes_to_float(value, _domain, _range):

    //     """Convert the fixed point value self.value to a floating point value."""
    //     src_value = int().from_bytes(value, byteorder='big', signed=(min(_domain) < 0))
    //     try:
    //            return linear_map(src_value, _domain, _range)
    //     except ValueError:
    //            raise TypeError
    float bytesToFloat(std::array<byte, 4> value, int domain, int range);

    // def float_to_bytes(value, _domain, _range):
    //     """Convert the fixed point value self.value to a floating point value."""
    //     # Some classes like MappedElement are calling float_to_bytes with arguments _domain
    //     # and _range in the incorrect order. The naming convention used is confusing and
    //     # needs addressed. Until that time, swap the order here as a workaround...
    //     src_domain, dst_range = _range, _domain
    //     src_min, src_max, dst_min, dst_max = src_domain + dst_range
    //     length = int((dst_max - dst_min - 1).bit_length() / 8)
    //     dst_value = linear_map(value, src_domain=src_domain, dst_range=dst_range)
    //     return round(dst_value).to_bytes(length, byteorder='big', signed=(dst_min < 0))
    std::array<byte, 4> floatToBytes(float value, int domain, int range);

    // def packet_checksum(data):
    //     """Return two byte checksum from a SMPTE ST 336 KLV structured bytes object."""
    //     length = len(data) - 2
    //     word_size, mod = divmod(length, 2)

    //     words = sum(unpack(">{:d}H".format(word_size), data[0:length - mod]))

    //     if mod:
    //         words += data[length - 1] << 8

    //     return pack('>H', words & 0xFFFF)
    std::array<byte, 2> packetChecksum(const std::array<byte, 8> &data);

}

#endif /* COMMON_H_ */
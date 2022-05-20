#ifndef COMMON_H_
#define COMMON_H_

#include <iostream>
#include <chrono>
#include <cstring>

using std::byte;
using DateTime = std::chrono::system_clock::time_point;

namespace Common {

/**
 * @brief Return bytes representing UTC time in microseconds.
 * 
 * @param dateTime Chrono date object
 * @return byte* Date object as Byte array 
 */
byte* dateTimeToBytes(const DateTime &dateTime);

/**
 * @brief Return datetime from microsecond bytes
 *
 * @param bytes Byte array of binary data for datetime
 * @return DateTime chrono date_time object.
 */
DateTime bytesToDatetime(const byte *bytes);

// def bytes_to_int(value, signed=False):
//     """Return integer given bytes."""
//     return int.from_bytes(bytes(value), byteorder='big', signed=signed)

// def int_to_bytes(value, length=1, signed=False):
//     """Return bytes given integer"""
//     return int(value).to_bytes(length, byteorder='big', signed=signed)

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

// def ber_encode(value):
//     """Return encoded BER length as bytes given integer."""
//     if value < 128:
//         # BER Short Form
//         return int_to_bytes(value)
//     else:
//         # BER Long Form
//         byte_length = ((value.bit_length() - 1) // 8) + 1

//         return int_to_bytes(byte_length + 128) + int_to_bytes(value, length=byte_length)

// def bytes_to_str(value):
//     """Return UTF-8 formatted string from bytes object."""
//     return bytes(value).decode('UTF-8')

// def str_to_bytes(value):
//     """Return bytes object from UTF-8 formatted string."""
//     return bytes(str(value), 'UTF-8')

// def hexstr_to_bytes(value):
//     """Return bytes object and filter out formatting characters from a string of hexadecimal numbers."""
//     return bytes.fromhex(''.join(filter(str.isalnum, value)))

// def bytes_to_hexstr(value, start='', sep=' '):
//     """Return string of hexadecimal numbers separated by spaces from a bytes object."""
//     return start + sep.join(["{:02X}".format(byte) for byte in bytes(value)])

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

// def bytes_to_float(value, _domain, _range):

//     """Convert the fixed point value self.value to a floating point value."""
//     src_value = int().from_bytes(value, byteorder='big', signed=(min(_domain) < 0))
//     try:
//            return linear_map(src_value, _domain, _range)
//     except ValueError:
//            raise TypeError

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

// def packet_checksum(data):
//     """Return two byte checksum from a SMPTE ST 336 KLV structured bytes object."""
//     length = len(data) - 2
//     word_size, mod = divmod(length, 2)

//     words = sum(unpack(">{:d}H".format(word_size), data[0:length - mod]))

//     if mod:
//         words += data[length - 1] << 8

//     return pack('>H', words & 0xFFFF)

}

#endif /* COMMON_H_ */
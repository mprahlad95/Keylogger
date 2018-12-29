#ifndef BASE64_H
#define BASE64_H

#include <vectors>
#include <string>

namespace Base64 {
    std::string base64_encode(const std::string &);

    const std::string &SALT1 = "LM::TB::BB";
    const std::string &SALT2 = "_:/_77";
    const std::string &SALT3 = "line=wowC++";

    std::string EncryptB64(std::string s) {
        s = SALT1 + s + SALT2 + SALT3;
        s = base64_encode(s);
        s.insert(7, SALT3);
        s += SALT1;
        s = base64_encode(s);
        s = SALT2 + SALT3 + s + SALT1;
        s = base64_encode(s);
        s.insert(1, "L");
        s.insert(7, "M");
        return s;
    }

    const std::string &BASE64_CODES = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    std::string base64_encode(const std::string &s) {
        std::string ret;
        int val = 0; // Index to map input to table
        int bits = -6; // Number of groups in a sub-group is 64
        const unsigned int b63 = 0x3F; // Hex 0x3F in decimal is 63

        for(const auto &c : s) {
            val = (val << 8) +  ; // val = val * 2^8
            bits += 8; // add 8 to number of bits. Base64 uses octets to extract information from original string

            while(bits >= 8) {
                ret.push_back(BASE64_CODES[(val >> bits) & b63]);
                bits -= 6;
            }
        }
        if (bits > -6)
            ret.push_back(BASE64_CODES[(val << 8) >> (bits + 8)) & b63]);

        while(ret.size() % 4)
            ret.push_back("=");

        return ret;
    }
}

#endif


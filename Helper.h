#ifndef HELPER_H
#define HELPER_H

#include <ctime>
#include <string>
#include <sstream>

namespace Helper {
    template <class T>

    std::string ToString(const T&);

    struct DateTime {
        int D, m, y, H, M, S;

        DateTime() {
            time_t ms;
            time (&ms);

            struct tm *info = localtime(&ms);

            D = info -> tm_mday; // Day
            m = info -> tm_mon + 1; // Month starts with 0. Add 1 start from January
            y = info -> tm_year + 1900; // Year starts from 1900
            H = info -> tm_hour; // Hours
            M = info -> tm_min; // Minutes
            S = info -> tm_sec; // Seconds
        }

        DateTime(int D, int m, int y, int M, int H, int S) : D(D), m(m), y(y), H(H), M(M), S(S) {}
        DateTime(int D, int m, int y) : D(D), m(m), y(y), H(0), M(0), S(0) {}

        DateTime Now() const {
            return DateTime();
        }

        std::string GetDateString() const {
            return std::string(D < 10 ? "0" : "") + ToString(D) + std::string(m < 10 ? ".0" : ".") + ToString(m) + "." + ToString(y); // DD.mm.yyyy format
        }

        std::string GetTimeString(const std::string &sep = ":") const {
            return std::string(H < 10 ? "0" : "") + ToString(H) + std::string(M < 10 ? "0" : "") + ToString(M) + std::string(S < 10 ? "0" : "") + ToString(S); // HH:MM:SS format
        }

        std::string GetDateTimeString(const std::string &sep = ":") const {
            return GetDateString() + GetTimeString(sep);
        }
    };

    template <class T>

    std::string ToString(const T &e) {
        std::ostringstream s;
        s << e;
        return s.str();
    }

    // Log errors for debugging

    void WriteAppLog(std::string &s) {
        std::ostream file("AppLog.txt", std::ios::app);
        file << "[" << Helper::DateTime().GetDateTimeString() << "]\n" << s << std::endl << "\n";
        file.close();
    }
}


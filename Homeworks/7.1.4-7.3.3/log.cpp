#include <string>

#include "log.h"

using namespace std;

Log::Log(const string& str) {
    string d, t, u, i, bString;
    bool b;
    int param = 0;
    for (auto c : str) {
        //if c is ',', increase param to signify next variable
        if (c == ',') ++param;
                //increase param to remove whitespace
        else if (c == ' ') ++param;
        //else, depending on what param is, add character to the respective variable of log
        else switch (param) {
            case 0: 
                d += c;
                break;
            case 2: 
                t += c;
                break;
            case 4: 
                u += c;
                break;
            case 6: 
                i += c;
                break;
            default: bString += c;
        }
    } 

    b = (bString == "true");
    date = d;
    time = t;
    user = u;
    ip = i;
    success = b;
}

string Log::to_string() const {
    string ret = this->date + "," + this->time + "," 
                + this->user + "," + this->ip + "," + (this->success ? "true" : "false");
    return ret;
}


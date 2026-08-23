#include <iostream>
#include <string>


std::string parse_10digit_number(std::string number) {
    std::string result;
    return result.substr(0, 4) + " " + result.substr(4, 3) + " " + result.substr(7, 3);
}


std::string parse_phone_number(std::string number) {
    switch(number.size()) {
        case 10:
            return "004 " + parse_10digit_number(number);
        case 12:
            return "(004)" + parse_10digit_number(number.substr(2, number.size() - 2));
        case 13:
            return "(004) " + parse_10digit_number(number.substr(3, number.size() - 3));
        default:
            return "";
    }
}


int main() {
    int size;
    std::string phone_number;

    for (int i = 0; i < size; i++) {
        std::cin >> phone_number;
        std::cout << parse_phone_number(phone_number) << std::endl;
    }
}

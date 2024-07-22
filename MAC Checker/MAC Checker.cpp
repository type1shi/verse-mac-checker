#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <sstream>
#include "json.hpp" // Include the json.hpp header file
#include "skStr.h"

#include <Windows.h>
#include <chrono>
#include <thread>
#include <ctime>

const std::string black = "\033[30m";
const std::string red = "\033[31m";
const std::string green = "\033[32m";
const std::string yellow = "\033[33m";
const std::string blue = "\033[34m";
const std::string magenta = "\033[35m";
const std::string cyan = "\033[36m";
const std::string white = "\033[37m";

const std::string bright_black = "\033[90m";
const std::string bright_red = "\033[91m";
const std::string bright_green = "\033[92m";
const std::string bright_yellow = "\033[93m";
const std::string bright_blue = "\033[94m";
const std::string bright_magenta = "\033[95m";
const std::string bright_cyan = "\033[96m";
const std::string bright_white = "\033[97m";

const std::string bg_black = "\033[40m";
const std::string bg_red = "\033[41m";
const std::string bg_green = "\033[42m";
const std::string bg_yellow = "\033[43m";
const std::string bg_blue = "\033[44m";
const std::string bg_magenta = "\033[45m";
const std::string bg_cyan = "\033[46m";
const std::string bg_white = "\033[47m";

const std::string bg_bright_black = "\033[100m";
const std::string bg_bright_red = "\033[101m";
const std::string bg_bright_green = "\033[102m";
const std::string bg_bright_yellow = "\033[103m";
const std::string bg_bright_blue = "\033[104m";
const std::string bg_bright_magenta = "\033[105m";
const std::string bg_bright_cyan = "\033[106m";
const std::string bg_bright_white = "\033[107m";

const std::string light_yellow = "\033[93m"; // Light yellow
const std::string light_blue = "\033[96m"; // Light blue
const std::string pink = "\033[95m";

const std::string reset = "\033[0m";

using json = nlohmann::json;

std::vector<std::string> getMacAddresses() {
    std::vector<std::string> macAddresses;
    std::string command = "getmac /FO CSV /NH";
    std::string result;

    FILE* pipe = _popen(command.c_str(), "r");
    if (!pipe) {
        return macAddresses;
    }

    char buffer[128];
    while (fgets(buffer, sizeof(buffer), pipe) != NULL) {
        result += buffer;
    }

    _pclose(pipe);

    std::stringstream ss(result);
    std::string line;

    while (std::getline(ss, line)) {
        std::string mac;
        std::stringstream lineStream(line);
        std::getline(lineStream, mac, ','); // Get the first column which is the MAC address
        mac = mac.substr(1, mac.length() - 2); // Remove surrounding quotes
        macAddresses.push_back(mac);
    }

    return macAddresses;
}

void WriteToJson(const std::string& filename, const std::vector<std::string>& macs) {
    json j = macs;

    std::ofstream file(filename);
    if (file.is_open()) {
        file << j.dump(4); // Pretty print with an indent of 4 spaces
        file.close();
    }
}

std::vector<std::string> ReadFromJson(const std::string& filename) {
    std::vector<std::string> macs;
    std::ifstream file(filename);
    if (file.is_open()) {
        json j;
        file >> j;
        file.close();
        macs = j.get<std::vector<std::string>>();
    }
    return macs;
}

bool compareMacAddresses(const std::vector<std::string>& currentMacs, const std::vector<std::string>& previousMacs) {
    if (currentMacs.size() != previousMacs.size()) {
        return false;
    }
    for (const auto& mac : currentMacs) {
        if (std::find(previousMacs.begin(), previousMacs.end(), mac) == previousMacs.end()) {
            return false;
        }
    }
    return true;
}

void resizeConsole(int width, int height) {
    // Get the handle to the standard output device (the console)
    HWND console = GetConsoleWindow();
    RECT r;
    // Get the current window size and position
    GetWindowRect(console, &r);
    // Move and resize the window
    MoveWindow(console, r.left, r.top, width, height, TRUE);
}

using namespace std;

int main(int argc, char* argv[]) 
{
    cout << red << " ";
    system("cls");

    if (argc > 1 && std::string(argv[1]) == "-2") {
        std::string consoleTitleca1 = skCrypt("VERSE Mac Checker | Replica by .type_shi. | -2").decrypt();
        SetConsoleTitleA(consoleTitleca1.c_str());

        system("cls");
        std::cout << light_yellow << skCrypt("\n  (!) This is a replica of the original VERSE Mac checker made by .type_shi. on discord\n") << reset << std::endl;
        std::cout << red << skCrypt("  (!) This wasn't created to harm anyone of the VERSE community as I love VERSE\n") << reset << std::endl;
        Sleep(6000);
        system("cls");
        return 0;
    }

    if (argc > 1 && std::string(argv[1]) == "-credits") {
        std::string consoleTitleca12 = skCrypt("VERSE Mac Checker | Replica by .type_shi. | -credits").decrypt();
        SetConsoleTitleA(consoleTitleca12.c_str());
        system("cls");
        std::cout << light_yellow << skCrypt("\n  (!) This is a replica of the original VERSE Mac checker made by .type_shi. on discord\n") << reset << std::endl;
        std::cout << red << skCrypt("  (!) This wasn't created to harm anyone of the VERSE community as I love VERSE\n") << reset << std::endl;
        Sleep(6000);
        system("cls");
        return 0;
    }

    if (argc > 1 && std::string(argv[1]) == "-help") {
        std::string consoleTitleca12 = skCrypt("VERSE Mac Checker | Replica by .type_shi. | -credits").decrypt();
        SetConsoleTitleA(consoleTitleca12.c_str());
        system("cls");
        std::cout << light_yellow << skCrypt("\n  (!) This is a replica of the original VERSE Mac checker made by .type_shi. on discord\n") << reset << std::endl;
        std::cout << red << skCrypt("  (!) This wasn't created to harm anyone of the VERSE community as I love VERSE\n") << reset << std::endl;
        Sleep(6000);
        system("cls");
        return 0;
    }

    


    //std::string consoleTitle = skCrypt("VERSE Mac Checker | Replica by .type_shi.").decrypt();
    //SetConsoleTitleA(consoleTitle.c_str());

    //resizeConsole(800, 600);

    std::vector<std::string> currentMacAddresses = getMacAddresses();

    std::cout << magenta << skCrypt("\n  [!] CURRENT MAC-ADDRESSES:\n\n\n") << reset;
    for (const auto& mac : currentMacAddresses) {
        std::cout << "  " << mac << "\n";
    }

    std::vector<std::string> previousMacAddresses = ReadFromJson("macAddresses.json");

    if (previousMacAddresses.empty()) {
        if (!currentMacAddresses.empty()) {
            WriteToJson("macAddresses.json", currentMacAddresses);
            std::cout << green << skCrypt("\n\n  FILE CONFIG (OLD SERIALS) HAS BEEN CREATED.\n") << reset;
            std::cout << skCrypt("\n\n  PRESS ENTER TO EXIT, & CHECK SERIALS AGAIN AFTER.\n");
            std::cin.get();
            return 0;
        }
    }
    else {
        std::cout << bright_blue << skCrypt("\n\n  [!] PREVIOUS MAC-ADDRESSES:\n\n\n") << reset;
        for (const auto& mac : previousMacAddresses) {
            std::cout << "  " << mac << "\n";
        }

        if (!compareMacAddresses(currentMacAddresses, previousMacAddresses)) {
            std::cout << green << skCrypt("\n\n  [+] SOME MAC ADDRESS HAS BEEN CHANGED!\n");
            std::cout << yellow << skCrypt("\n\n  [+] MAKE SURE THAT ALL YOUR MAC-ADDRESSES ARE CHANGED.\n") << reset;
        }
        else {
            std::cout << red << skCrypt("\n\n  [-] NO CHANGES DETECTED.\n");
            std::cout << skCrypt("\n\n  [-] MAKE SURE TO RUN THE SPOOFER...\n");
            std::cout << skCrypt("\n\n  [-] IF SPOOFER DIDN'T WORK, REACH OUT TO SUPPORT & MAKE SURE TO READ THE FAQS...\n");
        }
    }

    std::cout << reset << skCrypt("\n\n  PRESS ENTER TO EXIT CHECKER...\n");
    std::cin.get();

    return 0;
}

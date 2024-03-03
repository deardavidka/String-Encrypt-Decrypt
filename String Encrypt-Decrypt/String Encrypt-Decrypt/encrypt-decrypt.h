#pragma once
#include <string>
#include <vector>


struct RebornStudio_EncDecStr {
    std::string encode(const std::string& str);
    std::string decode(const std::string& str);
    void setup_mov();
private:
    bool setuped = false;
    std::string alphabet = "A3Bn@op=q1rOP;Clm2Q0Rst4u!(vwE&Fghi+j7kTGHI6J$a/bcd5ef-UVW)%XYx8yzKL9M_N\\SDZ";
    int mov[2500] = { };
} encdec;

void RebornStudio_EncDecStr::setup_mov() {
    for (unsigned int i = 0; i < 2500; i++) {
        this->mov[i] = 1;
        this->mov[i + 1] = 2;
        i = i + 1;
    }
    this->setuped = true;
}

std::string RebornStudio_EncDecStr::encode(const std::string& input) {
    if (this->setuped == false) { this->setup_mov(); }
    std::vector<char> word(input.begin(), input.end());
    for (int i = 0; i < (int)input.length(); i++) {
        for (int j = 0; j < (int)this->alphabet.length(); j++) {
            if (word[i] == this->alphabet[j]) {
                int mov_size = (j + mov[i]) % (int)this->alphabet.length();
                word[i] = this->alphabet[mov_size];
                break;
            }
        }
    }
    std::string str(word.begin(), word.end());
    return str;
}

std::string RebornStudio_EncDecStr::decode(const std::string& input) {
    if (this->setuped == false) { this->setup_mov(); }
    std::vector<char> word(input.begin(), input.end());
    for (int i = 0; i < (int)input.length(); i++) {
        for (int j = 0; j < (int)this->alphabet.length(); j++) {
            if (word[i] == this->alphabet[j]) {
                int mov_size = (j - mov[i]) % (int)this->alphabet.length();
                word[i] = this->alphabet[(j - mov[i]) % this->alphabet.length()];
                break;
            }
        }
    }
    std::string str(word.begin(), word.end());
    return str;
}


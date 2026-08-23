#include <iostream> // std::cout, cerr
#include <fstream> // ifstream
#include <sstream> // stringstream
#include <cstdint>
#include <bitset>
#include <cstdlib>

class PGM_Image
{
public:
    std::string name;
    int numrows;
    int numcols;
    int max_px_val;
    uint8_t* data;

    PGM_Image(std::string name);
    void save(std::string name);
};

PGM_Image::PGM_Image(std::string name) : name(name), numrows(0), numcols(0), max_px_val(0), data(nullptr)
{
    std::ifstream infile(this->name);
    std::stringstream ss;
    std::string inputLine = "";

    if (!infile) {
        std::cerr << "Failed to open image " << this->name;
        std::exit(EXIT_FAILURE);
    }

    // First line : version
    std::getline(infile, inputLine);
    //std::cout << "Version: " << inputLine << std::endl;

    // Second line: numcols numrows
    std::getline(infile, inputLine);
    ss << inputLine;
    ss >> this->numcols >> this->numrows;
    //std::cout << this->numcols << " columns and " << this->numrows << " rows" << std::endl;

    // Third line: max pixel value
    std::getline(infile, inputLine);
    ss = std::stringstream();

    ss << inputLine;
    ss >> this->max_px_val;
    //std::cout << "Px val is " << this->max_px_val << std::endl;

    std::filebuf *pbuf = infile.rdbuf();
    std::streamsize curr = pbuf->pubseekoff(0, infile.cur);
    std::streamsize size = pbuf->pubseekoff(0, infile.end);
    pbuf->pubseekoff(curr, infile.beg);

    //std::cout << "Curr is " << curr << "\n";
    //std::cout << "Size is " << size - curr << "\n";
    //std::cout << "Size is " << this->numrows * this->numcols << "\n";

    this->data = new uint8_t[this->numrows * this->numcols];
    pbuf->sgetn(reinterpret_cast<char*>(this->data), this->numrows * this->numcols);

    infile.close();
}

void PGM_Image::save(std::string name)
{
    std::ofstream outfile (name);
    if (!outfile) {
        std::cerr << "Failed to open image " << this->name;
        std::exit(EXIT_FAILURE);
    }

    // Version P5 means that the PGM data is in binary form
    outfile << "P5" << std::endl;
    outfile << this->numcols << " " << this->numrows << std::endl;
    outfile << this->max_px_val << std::endl;
    std::streambuf * pbuf = outfile.rdbuf();
    pbuf->sputn (reinterpret_cast<char*>(this->data), this->numcols * this->numrows);
    outfile.close();
}

class SteganoDecoder
{
public:
    static std::string lsb_decode_message(PGM_Image &img);
};

std::string SteganoDecoder::lsb_decode_message(PGM_Image &img)
{
    // TODO implement me!
    return std::string();
}

int main()
{
    PGM_Image img("lyutsifer-ig.pgm");

    auto msg = SteganoDecoder::lsb_decode_message(img);
    std::cout << msg << "\n";
}

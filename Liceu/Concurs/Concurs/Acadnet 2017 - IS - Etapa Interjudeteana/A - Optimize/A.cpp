/*
    Acadnet 2017 - Etapa Interjudeteana
    Problema A - Optimize Nule
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>

#define INPUT_FILENAME "input.txt"
#define OUTPUT_FILENAME "output.txt"

/*
	Aceasta este singura functie pe care aveti
	voie sa o modificati / rescrieti.
*/
void nule(std::vector<int> &v)
{
    int i, j, aux, size = v.size();
    bool swaped;

    for(i = 0; i < size - 1; i++) {
        swaped = false;
        for(j = 0; j < size - i - 1; j++) {
            if(v[j] == 0) {
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
                swaped = true;
            }
        }

        if(!swaped)
            break;
    }
}

int main(void)
{
    std::vector<int> v;
    int size, i, x;
    std::ifstream input_file;
    std::ofstream output_file;

    // Read vector from input file
    input_file.open(INPUT_FILENAME);
    if(!input_file.good()) {
        std::cout << "Failed to open " << INPUT_FILENAME << std::endl;
        exit(-1);
    }

    input_file >> size;

    v.reserve(size);

    for(i = 0; i < size; i++) {
        input_file >> x;
        v.push_back(x);
    }

    input_file.close();


    // Call nule() function
    nule(v);

    // Print vector to output file
    output_file.open(OUTPUT_FILENAME);
    if(!output_file.good()) {
        std::cout << "Failed to open " << OUTPUT_FILENAME << std::endl;
        exit(-1);
    }

    output_file << size << std::endl;
    for(i = 0; i < size; i++)
        output_file << v[i] << " ";

    output_file << std::endl;
    output_file.close();
    return 0;
}

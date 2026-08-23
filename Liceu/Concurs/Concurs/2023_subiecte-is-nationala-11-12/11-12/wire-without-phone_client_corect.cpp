#include "client.h"

#define SEND_BITS_STEPS 60

using namespace std;

struct client_state {
    uint cycle = 0;

    uint msg = 0;
    bool is_last = false;
    bool is_first = false;

    uint pow = 1;
    uint final_value = 0;
};

// Managerul are nevoie de asta si e obligatoriu
client_state* new_state() {
    return new client_state;
}

////////////////////////////// API IMPLEMENTATION //////////////////////////////

void begin_message(client_state *state, uint msg) {
    state->msg = msg;
    state->is_last = true;
}

// Toti clientii trimit 1, in primul ciclu
void step1() {
    send(1);
}

// Clientii verifica sa vada daca au valoarea 0 in registru.
// Daca are registrul 1, inseamna ca in primul ciclu, un client din stanga
//  sa i-a trimis un numar. Deci, el nu poate fi primul client.
void step2(client_state *state) {
    if (get_register() == 0) {
        state->is_first = true;
    }
    set_register(0);
}

// Am gasit o metoda. Pot trimite mesajul in binar. Se va propaga de la ultimul
//  client pana la primul.
// Ideea este in codul de eroare care e returnat de send.
// Se poate transmite 0 sau 1, in functie de ceea ce returneaza send: OK sau ERR
// Ultimul client isi seteaza registrul 499 sau 500.
// Penultimul client apeleaza send(1). Daca intoarce eroare, inseamna ca
//  ultimul client si-a setat registrul 500. Altfel, 499.
// Primii clienti trebuie sa astepte sa se propage bitii. Astfel, mai intai
//  ei fac send(2) pentru a verifica daca clientul din dreapta a inceput sa
//  primeasca biti. Daca intoarce OK, inseamna ca clientul din dreapta are
//  registrul 0 si inca nu a primit nimic.
//
// Primul client reconstruieste final_value, folosind bitii primiti.
void step3(client_state *state) {
    if (state->is_last) {
        set_register(499 + state->msg % 2);
        state->msg /= 2;

        return;
    } else if (send(2) == OK) {
        return;
    }

    // At this point, the next client's register
    //  should be 499 or 500.

    int bit = (send(1) == ERR) ? 1 : 0;
    set_register(499 + bit);
    state->final_value += bit * state->pow;
    state->pow *= 2;
}

void update(client_state *state) {
    if (state->cycle == 0) {
        step1();
    } else if (state->cycle == 1) {
        step2(state);
    } else if (state->cycle < SEND_BITS_STEPS) {
        step3(state);
    } else if (state->cycle == SEND_BITS_STEPS && state->is_first) {
        write(state->final_value);
    }

    state->cycle++;
}

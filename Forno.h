/**
 * Oggetto forno per simulare funzionamento fisico di riscaldamento/raffreddamento. E' molto semplificato. Servirà per fare due test
 * con un PID.
 * Il forno si scalda se acceso e se viene settata una potenza diversa (maggiore) a zero.
 * Indipendentemente che sia attivo il riscaldamento o meno, il forno subisce anche un fenomeno di raffreddamento. 
 * La funzione aggiorna() si occupa di modificare la temperatura del forno. 
 */ 

#pragma once

#include "Arduino.h"

enum statoForno {
    SPENTO,
    ACCESO
};


class Forno {
    const _max_temp = 300.0;
    const _min_temp = 20.0;
    double _temperatura = 0.0;
    double _potenzaPercentuale;  //potenza del forno settata (in futuro dinamicamente dal PID)
    double _riscaldamento;       //variazione temperatura causata dall'azione di riscaldamento
    double _raffreddamento;      // variazione temperatura causata dall'azione di raffreddamento
    double _tassoRiscaldamento;  //una caratteristica del forno, un k che definisce il tasso di riscaldamento. 
    double _tassoRaffreddamento; //una caratteristica del forno, un k che definisce il tasso di raffreddamento. 
    statoForno _stato = SPENTO;  // enum, acceso o spento

public:
    Forno( double tassoRiscaldamento, double tassoRaffreddamento );  // costruttore
    void aggiorna();                                                 // aggiorna la temperatura del forno
    double temperatura();                                            // funzione che restituisce la temperatura attuale del forno
    statoForno stato();                                              // funzione che restituisce lo stato (acceso/spento) del forno
    void accendi();                                                  // metodo per accendere il forno
    void spegni();                                                   // metodo per spegnere il forno
    void impostaPotenzaPercentuale(double potenza);                  // metodo che imposta la potenza di riscaldamento del forno
};

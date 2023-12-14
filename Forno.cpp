#include "forno.h"


// Costruttore
Forno::Forno(double tassoRiscaldamento, double tassoRaffreddamento)
    : temperatura(0.0), tassoRiscaldamento(tassoRiscaldamento), tassoRaffreddamento(tassoRaffreddamento) {
        stato = SPENTO;
    }


void Forno::aggiorna(){
    // Simuliamo il raffreddamento con una funzione logistica. Il raffreddamento è legato alla temperatura. Maggiore temperatura significa maggior raffreddamento
    raffreddamento = 100.0 * exp(-tassoRaffreddamento * millis() / 1000.0)* (temperatura / 100.0);
    temperatura = riscaldamento - raffreddamento;

    //clippo valori di uscita tra 20°C e 300°C
    if (temperatura > 300.0) {
        temperatura = 300.0;
    }

    if (temperatura < 20.0) {
        temperatura = 20.0;
    }
}

void Forno::impostaStato(statoForno nuovoStato){
    stato = nuovoStato;
}

Forno::statoForno Forno::ottieniStato(){
    return stato;
}


void Forno::riscalda(double potenzaPercentuale){
    
    if (stato == ACCESO)
    {
        
        // Simuliamo un aumento di temperatura basato su una funzione logistica. Il riscaldamento è legato alla potenza impostata del forno.
        riscaldamento = 100.0 * potenzaPercentuale * (1 - exp(-tassoRiscaldamento * millis() / 1000.0));
    }
    aggiorna();
}

double Forno::ottieniTemperatura() {
    // Funzione per ottenere la temperatura attuale del forno
    return temperatura;
}
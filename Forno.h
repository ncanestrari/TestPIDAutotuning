#ifndef FORNO_H
#define FORNO_H
#include "Arduino.h"

class Forno {
    //attenzione. La struttura dell'enum va dichiarata prima di dichiarare una variabile di questo tipo, altrimenti giustamente impazzisce.
    public:
        enum statoForno {
            ACCESO,
            SPENTO
        };

    private:
        double temperatura;
        double potenzaPercentuale;
        double riscaldamento;
        double raffreddamento;
        double tassoRiscaldamento;
        double tassoRaffreddamento;
        statoForno stato;

    public:
        Forno( double tassoRiscaldamento, double tassoRaffreddamento );
        void aggiorna();
        void raffredda();
        double ottieniTemperatura();
        statoForno ottieniStato();
        void impostaStato(statoForno nuovoStato);
        void impostaPotenzaPercentuale(double potenza);   
        
};

#endif  // FORNO_H
#ifndef FORNO_H
#define FORNO_H
#include "Arduino.h"

class Forno {

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
        void riscalda(double potenzaPercentuale);
        void raffredda();
        double ottieniTemperatura();
        statoForno ottieniStato();
        void impostaStato(statoForno nuovoStato);
        

        
        
};

#endif  // FORNO_H
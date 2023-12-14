#include "forno.h"



Forno mioForno (0.01,0.002);


void setup()
{


}


void loop()
{
    mioForno.aggiorna();

    double temperaturaAttuale = mioForno.ottieniTemperatura();

    
    Serial.println("La temperatura del forno è " + String(temperaturaAttuale) + " °C");
}


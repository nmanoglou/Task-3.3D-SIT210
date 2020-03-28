int ledRed = D6;
int ledBlue = D4;

void setup()
{
    // initalise both pins as output pins
    pinMode(ledRed, OUTPUT);
    pinMode(ledBlue, OUTPUT);
    
    // set the voltage on both pins to 0
    digitalWrite(ledRed, LOW);
    digitalWrite(ledBlue, LOW);
    
    // subscribe to the photon buddy in the RIOT lab
    Particle.subscribe("Deakin_RIOT_SIT210_Photon_Buddy", myHandler);
}

// function which will make the red led blink 3 times when the 'wave' signal is detected
void wave()
{
    for (int i = 0; i < 3; i++)
    {
        digitalWrite(ledRed, HIGH);
        delay(500);
        digitalWrite(ledRed, LOW);
        delay(500);
    }


}

// fucntion which will make the blue led blink 5 times when the 'pat' signal is detected
void pat()
{
    for (int i = 0; i < 5; i++)
    {
        digitalWrite(ledBlue, HIGH);
        delay(500);
        digitalWrite(ledBlue, LOW);
        delay(500);
    }
}

// the myhandler function which will initiate the wave or pat functions when the signal is detected
void myHandler(const char *event, const char *data)
{
    if (strcmp(data, "wave") == 0)
    {
        wave();
    }
    
    else if (strcmp(data, "pat") == 0)
    {
        pat();
    }
}

void loop()
{
    
}

/******************************************************************************
 * AAR-04 AREXX ARDUINO ROBOT
 * Pin Overview
 *
 * Little Sketch to get an overview over the pins and their status.
 *
 ******************************************************************************
 * Autors
 * HeinrichAD
 *
 ******************************************************************************
 * License
 * GNU General Public License v3.0, see LICENSE file.
 *
 ******************************************************************************
 * Source code
 * https://github.com/HeinrichAD/Arduino-PinOverview
 *
******************************************************************************/

#include <SerialExtended.h>

// Baudrate for serial monitor.
#define SERIAL_BAUD 9600


// Table refresh time.
// Time to refresh/ read new all Pin states.
// Time in miliseconds.
int refreshTime;

// Last run time.
unsigned long last;


// put your setup code here, to run once:
void setup() {
    // set up the serial port
    Serial.begin(SERIAL_BAUD);
  
    // Default 1 seconds/ 1000 miliseconds.
    refreshTime = 1000;

    last = millis();
    printTable();

    delay(2000);
}


// put your main code here, to run repeatedly:
void loop() {
    unsigned long now = millis();
    if ((now - last) < refreshTime)
        return;

    last = now;

    //SuperSerial.Clear();
    refreshTable();
}


void printTable() {
    char buf[76];

    Serial.println("+--- DIGITAL PINS --------------------------------------------------------+");
    sprintf(buf, "| No. | Value | Description%048c", '|');                                         Serial.println(buf);
    Serial.println("+-----+-------+-----------------------------------------------------------+");
    sprintf(buf, "|  01 | <val> | <description>%046c", '|');                                       Serial.println(buf);
    sprintf(buf, "|  02 | <val> | LED 16 / Right motor gear photo sensor LED%017c", '|');          Serial.println(buf);
    sprintf(buf, "|  03 | <val> | LED 17 / Left motor gear photo sensor LED%018c", '|');           Serial.println(buf);
    sprintf(buf, "|  04 | <val> | <description>%046c", '|');                                       Serial.println(buf);
    sprintf(buf, "|  05 | <val> | <description>%046c", '|');                                       Serial.println(buf);
    sprintf(buf, "|  06 | <val> | <description>%046c", '|');                                       Serial.println(buf);
    sprintf(buf, "|  07 | <val> | LED 1 / Line LED / LED between photo sensors%015c", '|');        Serial.println(buf);
    sprintf(buf, "|  08 | <val> | LED 2%054c", '|');                                               Serial.println(buf);
    sprintf(buf, "|  09 | <val> | <description>%046c", '|');                                       Serial.println(buf);
    sprintf(buf, "|  10 | <val> | <description>%046c", '|');                                       Serial.println(buf);
    sprintf(buf, "|  11 | <val> | <description>%046c", '|');                                       Serial.println(buf);
    sprintf(buf, "|  12 | <val> | <description>%046c", '|');                                       Serial.println(buf);
    sprintf(buf, "|  13 | <val> | LED 14%053c", '|');                                              Serial.println(buf);
    Serial.println("+-----+-------+-----------------------------------------------------------+");
    Serial.println("");
    Serial.println("+--- ANALOG PINS ---------------------------------------------------------+");
    sprintf(buf, "| No. | Value | Description%048c", '|');                                         Serial.println(buf);
    Serial.println("+-----+-------+-----------------------------------------------------------+");
    sprintf(buf, "|  01 | <val> | <description>%046c", '|');                                       Serial.println(buf);
    sprintf(buf, "|  02 | <val> | <description>%046c", '|');                                       Serial.println(buf);
    sprintf(buf, "|  03 | <val> | <description>%046c", '|');                                       Serial.println(buf);
    sprintf(buf, "|  04 | <val> | <description>%046c", '|');                                       Serial.println(buf);
    sprintf(buf, "|  05 | <val> | [Right motor forward]%038c", '|');                               Serial.println(buf);
    sprintf(buf, "|  06 | <val> | Left photo sensor / [Right motor backward]%017c", '|');          Serial.println(buf);
    sprintf(buf, "|  07 | <val> | Right photo sensor%041c", '|');                                  Serial.println(buf);
    sprintf(buf, "|  08 | <val> | <description>%046c", '|');                                       Serial.println(buf);
    sprintf(buf, "|  09 | <val> | [Left motor forward]%039c", '|');                                Serial.println(buf);
    sprintf(buf, "|  10 | <val> | [Left motor backward]%038c", '|');                               Serial.println(buf);
    Serial.println("+-----+-------+-----------------------------------------------------------+");
}


void refreshTable() {
    SuperSerial.CursorHome();
    SuperSerial.CursorDown(2);
    SuperSerial.CursorForward(13);

    for (int digiCounter = 1; digiCounter < 14; ++digiCounter)
    {
        SuperSerial.CursorDown();
        SuperSerial.Backspace(5);

        int read = digitalRead(digiCounter);
        if (read == 0)
            Serial.print("  LOW");
        else
            Serial.print(" HIGH");
    }

    SuperSerial.CursorDown(5);

    for (int anaCounter = 1; anaCounter < 11; ++anaCounter)
    {
        SuperSerial.CursorDown();
        SuperSerial.Backspace(5);

        char buf[6];
        sprintf(buf, "%5d", analogRead(anaCounter));
        Serial.print(buf);
    }
}


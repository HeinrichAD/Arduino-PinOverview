/******************************************************************************
 * Arduino - Pin Overview
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
 * **GIT REPOSITORY URL**
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
    sprintf(buf, "|  00 | <val> | RX - <description>%041c", '|');                                  Serial.println(buf);
    sprintf(buf, "|  01 | <val> | TX - <description>%041c", '|');                                  Serial.println(buf);
    sprintf(buf, "|  02 | <val> | <description>%046c", '|');                                       Serial.println(buf);
    sprintf(buf, "|  03 | <val> | <description>%046c", '|');                                       Serial.println(buf);
    sprintf(buf, "|  04 | <val> | <description>%046c", '|');                                       Serial.println(buf);
    sprintf(buf, "|  05 | <val> | <description>%046c", '|');                                       Serial.println(buf);
    sprintf(buf, "|  06 | <val> | <description>%046c", '|');                                       Serial.println(buf);
    sprintf(buf, "|  07 | <val> | <description>%046c", '|');                                       Serial.println(buf);
    sprintf(buf, "|  08 | <val> | <description>%046c", '|');                                       Serial.println(buf);
    sprintf(buf, "|  09 | <val> | <description>%046c", '|');                                       Serial.println(buf);
    sprintf(buf, "|  10 | <val> | <description>%046c", '|');                                       Serial.println(buf);
    sprintf(buf, "|  11 | <val> | <description>%046c", '|');                                       Serial.println(buf);
    sprintf(buf, "|  12 | <val> | <description>%046c", '|');                                       Serial.println(buf);
    sprintf(buf, "|  13 | <val> | <description>%046c", '|');                                       Serial.println(buf);
    Serial.println("+-----+-------+-----------------------------------------------------------+");
    Serial.println("");
    Serial.println("+--- ANALOG PINS ---------------------------------------------------------+");
    sprintf(buf, "| No. | Value | Description%048c", '|');                                         Serial.println(buf);
    Serial.println("+-----+-------+-----------------------------------------------------------+");
    sprintf(buf, "|  A0 | <val> | <description>%046c", '|');                                       Serial.println(buf);
    sprintf(buf, "|  A1 | <val> | <description>%046c", '|');                                       Serial.println(buf);
    sprintf(buf, "|  A2 | <val> | <description>%046c", '|');                                       Serial.println(buf);
    sprintf(buf, "|  A3 | <val> | <description>%046c", '|');                                       Serial.println(buf);
    sprintf(buf, "|  A4 | <val> | <description>%046c", '|');                                       Serial.println(buf);
    sprintf(buf, "|  A5 | <val> | <description>%046c", '|');                                       Serial.println(buf);
    Serial.println("+-----+-------+-----------------------------------------------------------+");
}


void refreshTable() {
    SuperSerial.CursorHome();
    SuperSerial.CursorDown(2);
    SuperSerial.CursorForward(13);

    for (int digiCounter = 0; digiCounter < 14; ++digiCounter)
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

    for (int anaCounter = 0; anaCounter < 6; ++anaCounter)
    {
        SuperSerial.CursorDown();
        SuperSerial.Backspace(5);

        char buf[6];
        sprintf(buf, "%5d", analogRead(anaCounter));
        Serial.print(buf);
    }
}


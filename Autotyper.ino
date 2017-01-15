
#if 0
#include <SPI.h>
#include <PN532_SPI.h>
#include <PN532.h>
#include <NfcAdapter.h>
#include <Keyboard.h>

PN532_SPI pn532spi(SPI, 10);
NfcAdapter nfc = NfcAdapter(pn532spi);
#else

#include <Wire.h>
#include <PN532_I2C.h>
#include <PN532.h>
#include <NfcAdapter.h>
#include <Keyboard.h>

PN532_I2C pn532_i2c(Wire);
NfcAdapter nfc = NfcAdapter(pn532_i2c);
String uid = "0";
#endif

void setup(void) {
    Serial.begin(115200);
    Serial.println("NDEF Reader");
    nfc.begin();
}

void loop(void) {
    Serial.println("\nScan a NFC tag\n");
    if (nfc.tagPresent())
    {
        NfcTag tag = nfc.read();
        uid = tag.getUidString();
        uid.replace(" ", "");
        Serial.println(uid);
        if (uid == "0123456789ABCD") {
            Keyboard.write('P');
            Keyboard.write('a');
            Keyboard.write('s');
            Keyboard.write('s');
            Keyboard.write('p');
            Keyboard.write('h');
            Keyboard.write('r');
            Keyboard.write('a');
            Keyboard.write('s');
            Keyboard.write('e');
            Keyboard.write(KEY_RETURN);
            delay(5000); //makes sure the password isn't repeated
        }
    }
}

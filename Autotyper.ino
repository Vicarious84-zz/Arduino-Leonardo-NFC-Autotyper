
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
        NfcTag tag = nfc.read(); // Reads the RFID/NFC tag
        uid = tag.getUidString(); // Fetches UID from the tag and save it in variable "uid"
        Serial.println(uid); // Shows the UID of the scanned RFID/NFC tag in Serial Monitor
        /* RFID/NFC tag with 4 byte UID */
        if (uid == "01 23 45 67") {
            Keyboard.print("Hello, World!"); // Sends the string "Hello, World!" to the computer
            Keyboard.write(KEY_RETURN); // Sends Enter
            delay(5000); //makes sure the password isn't repeated
        }
        /* RFID/NFC tag with 7 byte UID */
        else if (uid == "01 23 45 67 89 AB CD") {
            Keyboard.print("Passphrase"); // Sends the string "Passphrase" to the computer
            Keyboard.write(KEY_RETURN); // Sends Enter
            delay(5000); //makes sure the password isn't repeated
        }
    }
}

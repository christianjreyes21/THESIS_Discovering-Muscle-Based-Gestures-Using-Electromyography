#include <SD.h>
const int chipSelect = 4;
int String3_5 [270];
int index = 0;

void setup() {
  Serial.begin(9600);
  Serial.print("Initializing SD Card....");
  if(!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not Present");
    return;
  }
  Serial.println("Card Initialized");
  File dataFile = SD.open("Test_Gestures.txt");
  if(dataFile) {
    while(dataFile.available()) {
      Serial.write(dataFile.read());
      String3_5[index] = Serial.read();
      index++;
      String3_5[index] = '\0';
    }
    dataFile.close();
  } else {
    Serial.println("File does not exist or named wrong");
  }
}

void loop() {
}

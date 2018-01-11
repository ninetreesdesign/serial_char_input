// read a single character
// if using IDE's monitor, set to "No line ending"

int char_in = 0;   // for incoming serial data
int i = 0;

void setup() {
	Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps

	// t, t1 to measure comm initialization time...
	int t = millis();
	while (!Serial && (millis() - t < 8000)) {    // continues if the monitor window is never opened
		; // wait for serial port to connect. Needed for Leonardo & Teensyduino 3
	}
	delay(300);
	Serial.print("Port connectd: " + String(millis() - t) + " ms\n\n");
}


void loop() {
	// send data only when you receive data:
	if (Serial.available() > 0) {
		// read the incoming byte:
		char_in = Serial.read();

		Serial.print(i);
		Serial.print(": ");
		Serial.printf("[%c]  %02d dec   %02X hex\n",char_in,char_in,char_in); // note: type is "c" not "s"

        // or use 
        Serial.print("    ");
        Serial.write(char_in); Serial.println();
		i++;
	}
}



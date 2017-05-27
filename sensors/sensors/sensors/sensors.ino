/*
 Name:		sensors.ino
 Created:	25.05.2017 13:04:07
 Author:	robert
*/


int trigger[4] = { 10,11,12,13 };     // VL, VR, HL, HR
int echo[4] = { 14,15,16,17 };        // VL, VR, HL, HR

int time = 0;

int distance[4][5];

void setup()
{
	Serial.begin(9600);
	pinMode(trigger[0], OUTPUT);
	pinMode(trigger[1], OUTPUT);
	pinMode(trigger[2], OUTPUT);
	pinMode(trigger[3], OUTPUT);
	pinMode(echo[0], INPUT);
	pinMode(echo[1], INPUT);
	pinMode(echo[2], INPUT);
	pinMode(echo[3], INPUT);
}
void loop() {
	/* Vorne links */
	// Senden und Empfangen des Signals
	for (int j = 0; j <= 4; j++) {
		for (int i = 0; i <= 3; i++) {
			int value = 0;
			digitalWrite(trigger[i], LOW); // Setze Spannung an Trigger auf 0 zur Rauschunterdrückung
			delay(5);
			digitalWrite(trigger[i], HIGH); // Aktor starten, Ton für 10 ms
			delay(10);
			digitalWrite(trigger[i], LOW);
			time = pulseIn(echo[i], HIGH);
			value = (time / 2) * 0.03432;
			if (value >= 500) { value = 0; }  // Abfangen von Messfehlern

			distance[i][j] = value;
			delay(200);
		}
	}
	Serial.println("Abstand in cm:");

	for (int j = 0; j <= 4; j++) {
		for (int i = 0; i <= 3; i++) {
			if (i != 3) {
				Serial.print(distance[i][j]);
				Serial.print(", ");
			}
			else {
				Serial.println(distance[i][j]);
			}
		}
	}

	delay(1000); // Messintervall
}

#include <Arduino.h>
#include <WiFi.h>


// WIFI CREDENTIALS
const char* ssid = "interwebs";
const char* password = "trust_the_rob0ts";

int index = 0;

void scan_wifi() {	
	Serial.println("WiFi scan starting...");
	int n = WiFi.scanNetworks();
	Serial.println("Scan complete!");
	if (n==0) {
		Serial.println("No networks found :(");
	} else {
		Serial.print("Networks found: ");
		Serial.println(n);
		
		for (int i=0; i<n; i++) {
			Serial.print(i+1);
			Serial.print(": ");
			Serial.print(WiFi.SSID(i));
			Serial.print(" (");
			//Serial.print(WiFi.RSSI);
			Serial.print(")");
			Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN)?" ":"+");
			delay(10);
		}
	}

	Serial.println();
}


void connect_to_wifi() {

	Serial.print("Connecting to WiFi...");
	WiFi.begin(ssid, password);
	while (WiFi.status() != WL_CONNECTED) {
		Serial.print('.');
		delay(500);
	}
}


void report_wifi_status() {
	
	Serial.print(WiFi.status());
	Serial.print("\tRSSI: ");
	Serial.print(WiFi.RSSI());
	Serial.print("\tIP: ");
	Serial.print(WiFi.localIP());

	Serial.println();
}


void set_static_IP() {
	IPAddress local_IP(10,0,0,123);
	IPAddress gateway(10,0,0,1);
	IPAddress subnet(255,255,255,0);
	IPAddress primaryDNS(75,75,75,75);
	IPAddress secondaryDNS(75,75,76,76);

	if (!WiFi.config(local_IP, gateway, subnet, primaryDNS, secondaryDNS)) {
		Serial.println("STA failed to configure!");
	}
}


void setup() {
	Serial.begin(115200);
	WiFi.mode(WIFI_STA);
	WiFi.disconnect();
	delay(100);

	//delay(10000);
	connect_to_wifi();

	delay(1000);

	set_static_IP();
}

void loop() {
	//scan_wifi();
	delay(1000);

	Serial.print(index);
	Serial.print("\t");
	Serial.print(millis());
	Serial.print("     ");
	report_wifi_status();

}

#include <SPI.h>
#include <WiFi.h>

char ssid[] = "YourSSID";      //  your network SSID (name)
char pass[] = "password";   // your network password
int keyIndex = 0;            // your network key Index number (needed only for WEP)

int status = WL_IDLE_STATUS;

// Initialize the Wifi client library
WiFiClient client;

// server address:
char server[] = "test.com";
//IPAddress server(0, 0, 0, 0); // Please write the IP address if you need

unsigned long lastConnectionTime = 0;            // last time you connected to the server, in milliseconds
const unsigned long postingInterval = 2L * 1000L; // delay between updates, in milliseconds

void setup() {
    //Initialize serial and wait for port to open:
    Serial.begin(9600);

    // check for the presence of the shield:
    if (WiFi.status() == WL_NO_SHIELD) {
        Serial.println("WiFi shield not present");
        // don't continue:
        while (true);
    }

    String fv = WiFi.firmwareVersion();
    if ( fv != "1.1.0" )
        Serial.println("Please upgrade the firmware");

        // attempt to connect to Wifi network:
        while ( status != WL_CONNECTED) {
        Serial.print("Attempting to connect to SSID: ");
        Serial.println(ssid);
        // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
        status = WiFi.begin(ssid, pass);

        // wait 10 seconds for connection:
        delay(10000);
    }
    // you're connected now, so print out the status:
    printWifiStatus();
}

void loop() {
    // if ten seconds have passed since your last connection,
    // then connect again and send data:
    if (millis() - lastConnectionTime > postingInterval) {
        httpRequest();
    }
}

// this method makes a HTTP connection to the server:
void httpRequest() {
    // close any connection before send a new request.
    // This will free the socket on the WiFi shield
    client.stop();

    // if there's a successful connection:
    if (client.connect(server, 3000)) {
        //brightness = brightness/cnt;
        // send the HTTP PUT request:

        client.print("GET /iDB/web/process/get_data.php?");
        client.print("id=id"); // the id you registered
        client.print("&c=");
        client.print("c"); // category
        client.print("&val=");
        client.print(100); // the value you want
        client.println(" HTTP/1.1");
        client.println("Host: test.com");
        client.println("User-Agent: ArduinoWiFi/1.1");
        client.println("Connection: close");
        client.println();

        // note the time that the connection was made:
        lastConnectionTime = millis();
    }
    else {
        // if you couldn't make a connection:
        Serial.println("connection failed");
    }
}


void printWifiStatus() {
    // print the SSID of the network you're attached to:
    Serial.print("SSID: ");
    Serial.println(WiFi.SSID());

    // print your WiFi shield's IP address:
    IPAddress ip = WiFi.localIP();
    Serial.print("IP Address: ");
    Serial.println(ip);

    // print the received signal strength:
    long rssi = WiFi.RSSI();
    Serial.print("signal strength (RSSI):");
    Serial.print(rssi);
    Serial.println(" dBm");
}

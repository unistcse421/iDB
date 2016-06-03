#include <SPI.h>
#include <WiFi.h>

#include <DHT.h>
#define DHTPIN 3     // what pin we're connected to
#define DHTTYPE DHT11   // DHT 11

char ssid[] = "ESD-3";      //  your network SSID (name)
char pass[] = "goddamnnxt";   // your network password
int keyIndex = 0;            // your network key Index number (needed only for WEP)

int status = WL_IDLE_STATUS;

// Initialize the Wifi client library
WiFiClient client;
DHT dht(DHTPIN, DHTTYPE);
float h, t;

// server address:
//char server[] = "www.arduino.cc";
IPAddress server(10, 16, 27, 158);

unsigned long lastConnectionTime = 0;            // last time you connected to the server, in milliseconds
const unsigned long postingInterval = 2L * 1000L; // delay between updates, in milliseconds

bool flag = false;

void setup() {
  dht.begin();
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

    if (flag) {
      t = dht.readTemperature();
      client.print("GET /iDB/web/process/get_data.php?");
      client.print("id=a1");
      client.print("&c=");
      client.print("t");
      client.print("&val=");
      client.print(t);
      client.println(" HTTP/1.1");
      client.println("Host: 192.168.0.43");
      client.println("User-Agent: ArduinoWiFi/1.1");
      client.println("Connection: close");
      client.println();
      Serial.print("temperature=");
      Serial.println(t);
    }
    else {
      h = dht.readHumidity();
      client.print("GET /iDB/web/process/get_data.php?");
      client.print("id=a2");
      client.print("&c=");
      client.print("h");
      client.print("&val=");
      client.print(h);
      client.println(" HTTP/1.1");
      client.println("Host: 192.168.0.43");
      client.println("User-Agent: ArduinoWiFi/1.1");
      client.println("Connection: close");
      client.println();
      Serial.print("humidity=");
      Serial.print(h);
    }
    
    // note the time that the connection was made:
    lastConnectionTime = millis();
    flag = !flag;
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



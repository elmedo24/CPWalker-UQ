#include "wifi.h"

#ifndef HAVE_HWSERIAL1
#include "SoftwareSerial.h"
  SoftwareSerial Serial1(14, 15);
#endif


void wifi::wifi_setup(){

    int status = WL_IDLE_STATUS;
    char ssid[] = "JuanCP";      
    char pass[] = "wifijc12"; 

    Serial.begin(115200);
    Serial1.begin(9600);
    WiFi.init(&Serial1);

    server = new WiFiEspServer(80);  
    buf = new RingBuffer(8);

    if (WiFi.status() == WL_NO_SHIELD) {
      Serial.println("WiFi shield not present");
      // don't continue
      while (true);
    }

    while (status != WL_CONNECTED) {
      Serial.print("Attempting to connect to WPA SSID: ");
      Serial.println(ssid);

      status = WiFi.begin(ssid, pass);
    }

    Serial.println("You're connected to the network");
    printWifiStatus();

    server->begin();
    dataAvailable = false;
}

void wifi::wifi_recepcion(Servo* servo){
  
   WiFiEspClient client = server->available();

    if (client) {
      datos = "";
      boolean data = false;
      Serial.println("New client");
      buf->init();
      while (client.connected()) {
        if (client.available()) {
          // ----- disconect ----- //
          
          //Right Knee
          servo[2].detach();
          //Left Knee
          servo[3].detach();
          //Right hip
          servo[0].detach();
          //Left Hip
          servo[1].detach();
          /**/
          /*
          //Right Knee
          servo[2].write(80);
          //Left Knee
          servo[3].write(70);
          //Right hip
          servo[0].write(72);
          //Left Hip
          servo[1].write(70);
          /**/
          /*
          //Right Hip
          pinMode(11,INPUT);
          
          //Left Hip
          pinMode(6,INPUT);
          
          //Right Knee
          pinMode(10,INPUT);
          
          //Left Knee
          pinMode(9,INPUT);
          /**/
          // -------- //
          //delay(500);
          
          char c = client.read();
          buf->push(c);

          if( !data ) {

            if (buf->endsWith("\r\n\r\n")) {
              sendHttpResponse(client);
              dataAvailable = true;
              break;
            }

            if (buf->endsWith("GET /")) {
              data = true;
            }
          } else  {
            datos += c;
            if( c == 'T' )
              data = false;
          }
        }
      }

      client.stop();

          Serial.println(datos);
          Serial.println("Client disconnected");
    }

}

boolean wifi::disponible()
{
  return dataAvailable;
}

void wifi::readData(int *cadena)
{
    byte  med=datos.length();
    for (int i=0;i<med;i++)
    {
           
      datos[i]=datos[i]-48;
      cadena[i]=(int) datos[i];
      Serial.println(cadena[i]);
    }

    dataAvailable = false;
}

void wifi::sendHttpResponse(WiFiEspClient client)
{

  client.println("HTTP/1.1 200 OK");
  client.println("Content-type:text/html");
  client.println();
  client.println();
}

void wifi::printWifiStatus()
{
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  Serial.println();
  Serial.print("To see this page in action, open a browser to http://");
  Serial.println(ip);
  Serial.println();
}

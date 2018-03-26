#ifndef wifi_h
#define wifi_h
#include "WiFiEsp.h"
#include <Servo.h>

class wifi {

  public:
    void wifi_setup(void);
    void wifi_recepcion(Servo* servo);
    void printWifiStatus(void);
    void sendHttpResponse(WiFiEspClient client);
    boolean disponible();
    void readData(int *cadena);

  private:
    boolean dataAvailable;
    String datos;
    WiFiEspServer* server;
    RingBuffer* buf;
  };
#endif

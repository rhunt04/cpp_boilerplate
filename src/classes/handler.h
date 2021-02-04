#pragma once

#include <cstring>

// Forward declare to avoid dependency issue.
class Client;

class Handler {

  private:

    int m_numClients = 0;
    Client **m_clients = NULL;

  public:

    Handler();
    ~Handler();
    void addClient(Client *newClient);
    bool remClient(const char *name);
    void whisper(const char *message);
    void handler();

};

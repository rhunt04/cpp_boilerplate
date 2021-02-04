#include "client.h"
#include "handler.h"

Handler::Handler() {
  m_clients = new Client*[m_numClients];
}

Handler::~Handler() {
  delete[] m_clients;
}

void Handler::addClient(Client *newClient) {

  Client **tmp = new Client*[m_numClients + 1];

  for (int i = 0; i < m_numClients; i++) {
    tmp[i] = m_clients[i];
  }

  delete[] m_clients;
  m_clients = tmp;
  m_clients[m_numClients++] = newClient;
  newClient->addHandler(this);

}

bool Handler::remClient(const char *name) {

  for (int i = 0; i < m_numClients; i++) {

    if (strcmp(name, m_clients[i]->getName()) == 0) {
      // Found it, remove it.
      m_numClients--;
      Client **tmp = new Client*[m_numClients];
      int index = 0;
      for (int j = 0; j < (m_numClients + 1); j++) {
        if ( j != i ) {
          tmp[index++] = m_clients[j];
        }
      }

      delete[] m_clients;
      m_clients = tmp;
      return true;
    }
  }

  return false;

}

void Handler::whisper(const char *message) {
  // Client whispered something to me.
  // Tell EVERYONE.
  for (int i = 0; i < m_numClients; i++) {
    m_clients[i]->listenMessage(message);
  }
}

void Handler::handler() {
  for (int i = 0; i < m_numClients; i++) {
    m_clients[i]->handler();
  }
}


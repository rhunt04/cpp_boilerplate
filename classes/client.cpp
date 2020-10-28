#include "client.h"
#include "handler.h"

Client::Client() {}

Client::Client(const char *name) {
  setName(name);
}

// Public as user may control some..?
void Client::setName(const char *name) {
  m_name = name;
}

const char *Client::getName() {
  return m_name;
}

void Client::addHandler(Handler *handler) {
  m_handler = handler;
}

void Client::tellHandler(const char *message) {
  if (m_handler) { m_handler->whisper(message); };
}

void Client::detestWord(const char *word) {
  m_detest = word;
}

void Client::listenMessage(const char *message) {
  if ( m_detest ) {
    if ( strstr(message, m_detest) != NULL ) {
      printf("My name is %s, and I detest /that/ word! I will not speak it!\n",
        m_name);
      return;
    }
  }
  printf("My name is %s, and I just got told: %s.\n",
    m_name, message);
}

void Client::handler() {
  printf("I'm %s and I'm being handled :).\n", m_name);
}


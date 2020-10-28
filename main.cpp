#include "classes/client.h"
#include "classes/handler.h"

Handler *bigBossMan = new Handler;

// Declare clients for testing.
// Normally, handler would spawn these for itself, after reading a config.
Client *client1 = new Client("Client 1");
Client *client2 = new Client("Client 2");

int main(void) {


  bigBossMan->addClient(client1);
  bigBossMan->addClient(client2);

  // Client 1 doesn't like it when you swear. It will not repeat what you tell
  // it, if what you tell it matches this word.
  client1->detestWord("Bloody");

  // Say something dumb.
  // This goes to handler, then goes out to everyone else.
  client1->tellHandler("Turn off that Bloody tap!");

  bigBossMan->handler();

  // Tidy.
  delete bigBossMan;
  delete client1;
  delete client2;

  return 0;

}

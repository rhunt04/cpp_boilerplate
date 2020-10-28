#pragma once

#include <stdio.h>

// Forward declare to avoid dependency issue.
class Handler;

class Client {

  private:

    const char *m_name = "unnamed";
    const char *m_detest = NULL;
    Handler *m_handler = NULL;

  public:

    Client();
    Client(const char *name);

    // Public as user may control some..?
    void setName(const char *name);
    const char *getName();

    void addHandler(Handler *handler);
    void detestWord(const char *word);
    // bool with succes crit?
    void tellHandler(const char *message);
    void listenMessage(const char *message);
    void handler();

};

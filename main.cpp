#include <iostream>
#include <sstream>
#include <bitset>
#include <algorithm>

#include <iterator>
#include <iostream>
#include <sstream>


#include <map>
#include <vector>
#include <set>
#include <queue>
#include <deque>
#include <list>

#include <thread>
#include <mutex>


using namespace std;

#include "helloworld.h"

#define GETTEXT_PACKAGE "rc"
//#define PROGRAMNAME_LOCALEDIR "/usr/share/locale/"
//#define PROGRAMNAME_LOCALEDIR "~/locale"
#define PROGRAMNAME_LOCALEDIR "locale"

int main (int argc, char *argv[])
{

  //cerr << "LC_ALL " << setlocale (LC_ALL, NULL) /*getenv("LC_ALL")*/  << ", LANG " << getenv("LANG") << ", GDM_LANG " << getenv("GDM_LANG") << ", LANGUAGE " << getenv("LANGUAGE") << endl;

  auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

  setlocale (LC_ALL, "");
  setenv("LC_ALL", "C", 1);

  bindtextdomain(GETTEXT_PACKAGE, PROGRAMNAME_LOCALEDIR);
  bind_textdomain_codeset(GETTEXT_PACKAGE, "UTF-8");
  textdomain(GETTEXT_PACKAGE);

  HelloWorld helloworld("Hello World");

  //Shows the window and returns when it is closed.
  return app->run(helloworld);
}

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

//#include <math.h>


using namespace std;


int _main()
{

  cout << "Hello Gnome";
  cout << endl;
  return 0;

}

#include "helloworld.h"
//#include <gtkmm/application.h>
//#include <libintl.h>

#if 0
#define GETTEXT_PACKAGE "mc"
//#define PROGRAMNAME_LOCALEDIR "~/locale"
//#define PROGRAMNAME_LOCALEDIR "./locale"
//#define PROGRAMNAME_LOCALEDIR "locale"
//#define PROGRAMNAME_LOCALEDIR "/home/romek/mygnome/hello/locale/pl/LC_MESSAGES/"
//#define PROGRAMNAME_LOCALEDIR "/home/romek/mygnome/hello/locale/"
//#define PROGRAMNAME_LOCALEDIR "/usr/share/locale/"
#else
#define GETTEXT_PACKAGE "rc"
//#define PROGRAMNAME_LOCALEDIR "~/locale"
//#define PROGRAMNAME_LOCALEDIR "./locale"
#define PROGRAMNAME_LOCALEDIR "locale"
#endif

int main (int argc, char *argv[])
{

  //setenv("LANGUAGE", "de_DE", 1);
  cerr << "LC_ALL " << setlocale (LC_ALL, NULL) /*getenv("LC_ALL")*/  << ", LANG " << getenv("LANG") << ", GDM_LANG " << getenv("GDM_LANG") << ", LANGUAGE " << getenv("LANGUAGE") << endl;


  //cerr << textdomain(NULL) << endl;
  //cerr << "??? " << bindtextdomain(GETTEXT_PACKAGE, "/usr/share/locale") << endl;
  //cerr << "??? " << bindtextdomain(NULL, "/usr/share/locale/") << endl;
  //cerr << _("Account:") << endl;

  auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

  setlocale (LC_ALL, "");
  setenv("LC_ALL", "C", 1);

  //bindtextdomain(GETTEXT_PACKAGE, PROGRAMNAME_LOCALEDIR);
  bind_textdomain_codeset(GETTEXT_PACKAGE, "UTF-8");
  textdomain(GETTEXT_PACKAGE);

  cerr << _("Hello World") << " " << _("Account:") << endl;

  //HelloWorld helloworld(_("Account:"));
  HelloWorld helloworld("Account:");

  //Shows the window and returns when it is closed.
  return app->run(helloworld);
}

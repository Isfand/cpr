#include <sstream>
#include <stdexcept>

#include <cpr/cprver.h>
#include <cpr/cpr.h>

#undef NDEBUG
#include <cassert>

int main ()
{
    using namespace std;
    using namespace cpr;

    // Basics.
    cpr::Response r = cpr::Get(cpr::Url{"https://api.github.com/repos/whoshuu/cpr/contributors"},
                          cpr::Authentication{"user", "pass", cpr::AuthMode::BASIC},
                          cpr::Parameters{{"anon", "true"}, {"key", "value"}});
    r.status_code;                  // 200
    r.header["content-type"];       // application/json; charset=utf-8
    r.text;                         // JSON text string
    return 0;

  //
  // {
  //   ostringstream o;
  //   say_hello (o, "World");
  //   assert (o.str () == "Hello, World!\n");
  // }

  // // Empty name.
  // //
  // try
  // {
  //   ostringstream o;
  //   say_hello (o, "");
  //   assert (false);
  // }
  // catch (const invalid_argument& e)
  // {
  //   assert (e.what () == string ("empty name"));
  // }
}

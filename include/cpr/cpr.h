#ifndef CPR_CPR_H
#define CPR_CPR_H

#include <libca-certificates-curl/path.h>

#include "cpr/api.h"
#include "cpr/auth.h"
#include "cpr/bearer.h"
#include "cpr/callback.h"
#include "cpr/cert_info.h"
#include "cpr/connect_timeout.h"
#include "cpr/cookies.h"
#include "cpr/cprtypes.h"
#include "cpr/cprver.h"
#include "cpr/curl_container.h"
#include "cpr/curlholder.h"
#include "cpr/error.h"
#include "cpr/http_version.h"
#include "cpr/interceptor.h"
#include "cpr/interface.h"
#include "cpr/limit_rate.h"
#include "cpr/local_port.h"
#include "cpr/local_port_range.h"
#include "cpr/low_speed.h"
#include "cpr/multipart.h"
#include "cpr/multiperform.h"
#include "cpr/parameters.h"
#include "cpr/payload.h"
#include "cpr/proxies.h"
#include "cpr/proxyauth.h"
#include "cpr/range.h"
#include "cpr/redirect.h"
#include "cpr/reserve_size.h"
#include "cpr/resolve.h"
#include "cpr/response.h"
#include "cpr/session.h"
#include "cpr/ssl_ctx.h"
#include "cpr/ssl_options.h"
#include "cpr/status_codes.h"
#include "cpr/timeout.h"
#include "cpr/unix_socket.h"
#include "cpr/user_agent.h"
#include "cpr/util.h"
#include "cpr/verbose.h"

#define CPR_LIBCURL_VERSION_NUM LIBCURL_VERSION_NUM

inline void add_ca_certificates()
{
    char* env = curl_getenv ("SSL_CERT_FILE");

    if (env == NULL)
    {
        int r{};

#ifndef _WIN32
        r = setenv ("SSL_CERT_FILE", ca_certificates_file (), 0 /* overwrite */);
#else
        char* v = curl_maprintf ("SSL_CERT_FILE=%s", ca_certificates_file ());

        if (v != NULL)
        {
          r = _putenv (v);
          free (v);
        }
        else
            r = -1;
#endif
    }
}

struct AutoCert
{
    AutoCert()
    {
        static bool run = []
        {
            add_ca_certificates();
            return true;
        }();
    }
};

static AutoCert autoCertInst;

#endif

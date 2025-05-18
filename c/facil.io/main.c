#include <fio.h>
#include <http.h>

static void on_http_request(http_s *h)
{
    http_send_body(h, "Hello World!", 12);
}

int main(int argc, char const *argv[])
{
    if (http_listen("3000", NULL, .on_request = on_http_request) == -1)
    {
        exit(1);
    }
    fio_start(.threads = 1, .workers = 1);
    return 0;
}

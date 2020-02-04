#include <stdio.h>
#include <curl/curl.h>

struct curl_slist *headers=NULL;

int main(void)
{
  CURL *curl;
  CURLcode res;
  headers = curl_slist_append(headers, "Content-Type: application/x-www-form-urlencoded");

  curl = curl_easy_init();
  if(curl) {
    const char *data = "some_metric 3.14\n";
    curl_easy_setopt(curl, CURLOPT_URL, "http://192.168.1.74:9091/metrics/job/some_job");
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, 17L);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

    res = curl_easy_perform(curl);
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));

    curl_easy_cleanup(curl);
  }
  curl_global_cleanup();
  return 0;
}

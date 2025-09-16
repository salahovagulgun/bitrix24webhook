#include <iostream>
#include <curl/curl.h>
int main(){
  CURL *curl;
CURLcode res;
std::string url="https://b24-9pajnk.bitrix24.com/rest/1/58vy1rqrwufzhodm/crm.lead.add";
std::string jsondata = R"({
   "fields":{
   
 "TITLE": "Test Lead",
"NAME":  "GULGUN",
"LAST_NAME": "SALAHOVA",
"STATUS_ID": "NEW",
"PHONE": [{"VALUE":
"+994888888", "VALUE_TYPE": "WORK"}],
"EMAIL":[{"VALUE": 
"test@example.com", "VALUE_TYPE":
"WORK"}]
}
});
curl=curl_easy_init();
if(curl){
struct curl_stlist  *headers = NULL;
headers=
curl_slist_append(headers, "Content-Type: application/json"):
curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
curl_easy_setopt(curl, CURLOPT_POSTFIELDS, jsonData.c_str());

res = curl_easy_perform(curl);
if( res !=CURLE_OK)
std::cerr<<
"curl_easy_perform()failed:"<<
curl_easy_strerror(res)<< std::endl;
curl_easy_cleanup(curl);
}
return 0;
}


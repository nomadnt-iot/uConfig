#include <uConfig.h>

using namespace nomadnt;

// declaring config_t configuration
//config_t cfg;
const config_t cfg_default = { 0x6C61706F, 0, {"", ""} };

uConfig config(cfg_default);

void setup(){
  Serial.begin(115200);

  delay(5000L);

  //config.drop(true);
  config.init();

  Serial.println("is configured: " + String(config.data().isConfigured));
  if(config.data().isConfigured == 0){
    config.data().isConfigured = 1;
    Serial.println("setting new values to: " + String(config.data().isConfigured));
    config.save();
  }
}

void loop(){

}

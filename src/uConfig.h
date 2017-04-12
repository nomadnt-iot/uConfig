#ifndef _uCONFIG_H_
#define _uCONFIG_H_

#include <Arduino.h>
#include <EEPROM.h>

/**
 *  configuration structure
 **/
struct config_t{
  uint32_t magic;
  uint8_t isConfigured:1;

  struct config_wifi_t{
    char ssid[34];
    char key[34];
  } wifi;

} __attribute__((packed));

class uConfig{
  public:
    uConfig(config_t &cfg, const config_t &cfg_default, unsigned int addr = 0);

    bool load();

    bool save();

    bool init();

    bool drop(bool erase = false);

  private:

    unsigned int _addr;

    config_t &_cfg;

    const config_t _cfg_default;
};

#endif

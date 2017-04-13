#ifndef _uCONFIG_H_
#define _uCONFIG_H_

#include <Arduino.h>
#include <EEPROM.h>

#include "config.h"

namespace nomadnt{

  class uConfig{
    public:
      /**
       *  constructor
       *  @param config_t &cfg
       *  @param config_t &cfg_default
       *  @param unsigned int address
       **/
      //uConfig(config_t &cfg, const config_t &cfg_default, unsigned int addr = 0);
      uConfig(const config_t &cfg_default, unsigned int addr = 0);

      /**
       *  load configuration from EEPROM and apply default config if first time
       *  @return boolean
       **/
      bool load();

      /**
       *  store configuration to EEPROM
       *  @return boolean
       **/
      bool save();

      /**
       *  init configuration and load from EEPROM
       *  @return boolean
       **/
      bool init();

      /**
       *  drop configuration and erase EEPROM
       *  @param boolean erase
       *  @return boolean
       **/
      bool drop(bool erase = false);

      /**
       *  get configuration struct to use inside other functions
       *  @return boolean
       **/
      config_t &data();

    private:

      config_t _cfg;
      //config_t &_cfg;

      unsigned int _addr;

      const config_t _cfg_default;
  };
}

#endif

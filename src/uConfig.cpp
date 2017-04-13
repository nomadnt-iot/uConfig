#include "uConfig.h"

namespace nomadnt{

  /*uConfig::uConfig(config_t &cfg, const config_t &cfg_default, unsigned int addr) : _cfg(cfg), _cfg_default(cfg_default){
    _addr = addr;
  }*/

  uConfig::uConfig(const config_t &cfg_default, unsigned int addr) : _cfg_default(cfg_default){
    _addr = addr;
  }

  bool uConfig::load(){
    EEPROM.get(_addr, _cfg);
    if(_cfg.magic != _cfg_default.magic){
      _cfg = _cfg_default;
      EEPROM.put(_addr, _cfg);
    }

    return true;
  }

  bool uConfig::save(){
    EEPROM.put(_addr, _cfg);
#ifdef ESP8266
    EEPROM.commit();
#endif
    return true;
  }

  bool uConfig::init(){
#ifdef ESP8266
    EEPROM.begin(sizeof(_cfg));
#endif
    return load();
  }

  bool uConfig::drop(bool erase){
    if(erase){
      for(unsigned int addr = 0; addr < sizeof(_cfg); addr++)
        EEPROM.write(addr, 0);
    }

    _cfg = _cfg_default;
    return save();
  }

  config_t &uConfig::data(){
    return _cfg;
  }

}

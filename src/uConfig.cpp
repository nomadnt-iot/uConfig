#include "uConfig.h"

uConfig::uConfig(config_t &cfg, const config_t &cfg_default, unsigned int addr) : _cfg(cfg), _cfg_default(cfg_default){
  _addr = addr;
}

bool uConfig::load(){
  EEPROM.get(_addr, _cfg);
  if(_cfg.magic != _cfg_default.magic){
    Serial.println("loading default values");
    _cfg = _cfg_default;
    EEPROM.put(_addr, _cfg);
  }

  return true;
}

bool uConfig::save(){
  EEPROM.put(_addr, _cfg);
  // you need to call this on esp8266 board to store into eeprom
  //EEPROM.commit();
  return true;
}

bool uConfig::init(){
  // you need to call this on esp8266 board before using eeprom
  //EEPROM.begin(sizeof(_cfg));
  return load();
}

bool uConfig::drop(bool erase){
  // this is compatible with all boards
  for(unsigned int addr = 0; addr < sizeof(_cfg); addr++) EEPROM.write(addr, 0);
  _cfg = _cfg_default;
  return save();
}


namespace nomadnt{

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

}

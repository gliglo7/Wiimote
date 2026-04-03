#ifndef _WIIMOTE_H_
#define _WIIMOTE_H_

#include <cstdint>
#include <stddef.h>

/*
    bool wiimote_button_down = (data[2] & 0x01) != 0;
    bool wiimote_button_up = (data[2] & 0x02) != 0;
    bool wiimote_button_right = (data[2] & 0x04) != 0;
    bool wiimote_button_left = (data[2] & 0x08) != 0;
    bool wiimote_button_plus = (data[2] & 0x10) != 0;
    bool wiimote_button_2 = (data[3] & 0x01) != 0;
    bool wiimote_button_1 = (data[3] & 0x02) != 0;
    bool wiimote_button_B = (data[3] & 0x04) != 0;
    bool wiimote_button_A = (data[3] & 0x08) != 0;
    bool wiimote_button_minus = (data[3] & 0x10) != 0;
    bool wiimote_button_home = (data[3] & 0x80) != 0;
    */
// #define WIIMOTE_BUTTON_UP 0x0100
// #define WIIMOTE_BUTTON_DOWN 0x0200
// #define WIIMOTE_BUTTON_RIGHT 0x0400
// #define WIIMOTE_BUTTON_LEFT 0x0800
// #define WIIMOTE_BUTTON_PLUS 0x1000
// #define WIIMOTE_BUTTON_2 0x0001
// #define WIIMOTE_BUTTON_1 0x0002
// #define WIIMOTE_BUTTON_B 0x0004
// #define WIIMOTE_BUTTON_A 0x0008
// #define WIIMOTE_BUTTON_MINUS 0x0010
// #define WIIMOTE_BUTTON_HOME 0x0080


enum wiimote_event_type_t {
  WIIMOTE_EVENT_INITIALIZE,
  WIIMOTE_EVENT_SCAN_START,
  WIIMOTE_EVENT_SCAN_STOP,
  WIIMOTE_EVENT_NEW,
  WIIMOTE_EVENT_CONNECT,
  WIIMOTE_EVENT_DISCONNECT,
  WIIMOTE_EVENT_DATA
};

enum balance_position_type_t {
  BALANCE_POSITION_TOP_RIGHT,
  BALANCE_POSITION_BOTTOM_RIGHT,
  BALANCE_POSITION_TOP_LEFT,
  BALANCE_POSITION_BOTTOM_LEFT,
};

typedef void (* wiimote_callback_t)(wiimote_event_type_t event_type, uint16_t handle, uint8_t *data, size_t len);


class Wiimote {
  public:
    void init(wiimote_callback_t cb);
    void handle();
    void scan(bool enable);
    void _callback(wiimote_event_type_t event_type, uint16_t handle, uint8_t *data, size_t len);
    void set_led(uint16_t handle, uint8_t leds);
    void set_rumble(uint16_t handle, bool rumble);
    void get_balance_weight(uint8_t *data, float *weight);
    void initiate_auth(uint16_t handle);
    void disconnect(uint16_t handle);
    void set_reporting_mode(uint16_t handle, uint8_t mode, bool continuous);
  private:
    wiimote_callback_t _wiimote_callback;
};

#endif

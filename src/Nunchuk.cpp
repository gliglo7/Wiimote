// #ifndef _NUNCHUK_H_
// #define _NUNCHUK_H_

// #include <cstdint>
// #include <cstring>

// // Use integer constants for bitmasking
// #define NUNCHUK_BTN_Z 0x01
// #define NUNCHUK_BTN_C 0x02

// struct NunchukState {
//   uint8_t joyX, joyY;
//   uint16_t accelX, accelY, accelZ;
//   bool btnC, btnZ;
// };

// class Nunchuk {
//   public:
//     void init();
//     // This is where you pass the raw 6-byte extension data from the Wiimote
//     void handle(uint8_t *data, size_t len);

//     // Getters to access the data from your main sketch
//     NunchukState getState() { return _state; }

//   private:
//     NunchukState _state;
//     NunchukState _prevState; 
    
//     void parse(uint8_t* ext);
// };

// #endif
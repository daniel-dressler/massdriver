#include "images.h"

// Filename: Ship.png
// Pixel Width: 16px
// Pixel Height: 16px

const int Ship_tile_count = 0x04;
const unsigned char Ship_tile_data[] ={
  0x01,0x00,0x01,0x00,0x02,0x01,0x02,0x01,0x02,0x01,0x02,0x01,0x04,0x03,0x05,0x02,
  0x79,0x06,0x41,0x3E,0x41,0x3E,0x7B,0x04,0x66,0x00,0x60,0x00,0x00,0x00,0x00,0x00,
  0x80,0x00,0x80,0x00,0x40,0x80,0x40,0x80,0x40,0x80,0x40,0x80,0x20,0xC0,0xA0,0x40,
  0x9E,0x60,0x82,0x7C,0x82,0x7C,0xDE,0x20,0x66,0x00,0x06,0x00,0x00,0x00,0x00,0x00
};

// Filename: bullet.png
// Pixel Width: 8px
// Pixel Height: 8px

const int Bullet_tile_count = 0x02;
const unsigned char Bullet_tile_data[] ={
  0x00,0x00,0x00,0x00,0x18,0x18,0x3C,0x24,0x3C,0x24,0x18,0x18,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

// Filename: enemy.png
// Pixel Width: 8px
// Pixel Height: 16px

const int Enemy_tile_count = 0x02;
const unsigned char Enemy_tile_data[] ={
  0x24,0x24,0x24,0x24,0x5A,0x7E,0x5A,0x7E,0x81,0xFF,0xBD,0xC3,0xFF,0xBD,0xBD,0xC3,
  0x5A,0x7E,0x5A,0x7E,0x24,0x24,0x24,0x24,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

// Filename: Enemy2.png
// Pixel Width: 8px
// Pixel Height: 16px

const int Enemy2_tile_count = 0x02;
const unsigned char Enemy2_tile_data[] ={
  0x00,0x00,0x00,0x00,0x3C,0x3C,0x42,0x7E,0x7E,0x5A,0x7E,0x5A,0xDB,0xA5,0xBD,0xC3,
  0xDB,0xBD,0xC3,0xBD,0xDB,0xBD,0xC3,0xA5,0xC3,0xA5,0xA5,0xC3,0x66,0x66,0x00,0x00};

// Filename: EnemyMed.png
// Pixel Width: 24px
// Pixel Height: 16px

const int EnemyMed_tile_count = 0x06;
const unsigned char EnemyMed_tile_data[] ={
  0x00,0x00,0x00,0x00,0x04,0x00,0x0C,0x0C,0x10,0x1C,0x0A,0x15,0x2A,0x37,0x3C,0x67,
  0x7F,0xE4,0x3F,0xE4,0xEE,0x3F,0x59,0xB7,0x21,0x53,0x03,0x30,0x00,0x10,0x00,0x00,
  0x00,0x00,0x00,0x00,0x38,0x00,0x3C,0x00,0xFC,0x7E,0xE7,0xFF,0x08,0xFF,0x1C,0xE7,
  0x39,0xC6,0x3D,0xE6,0x81,0x7E,0xFF,0x00,0x7F,0x81,0xA6,0xFF,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x20,0x00,0x70,0x30,0x40,0x38,0x58,0xA8,0x90,0xEC,0x14,0xEE,
  0xD7,0x2F,0xF7,0x2D,0x62,0xFD,0xFE,0x89,0x14,0xCA,0xC8,0x14,0x00,0x08,0x00,0x00
};

// Filename: Boss.png
// Pixel Width: 48px
// Pixel Height: 48px

const int Boss_tile_count = 0x24;
const unsigned char Boss_tile_data[] ={
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x01,0x03,0x03,0x03,0x03,0x02,0x03,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x50,0x00,0x50,0x00,0x88,
  0x00,0x88,0x70,0x70,0xF8,0xF8,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x00,0x88,0x00,0x88,0x70,0x70,
  0x78,0x78,0x7E,0x7E,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0E,0x00,0x11,0x00,0x11,0x0E,0x0E,
  0x1E,0x1E,0x7E,0x7E,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x00,0x0A,0x00,0x0A,0x00,0x11,
  0x00,0x11,0x0E,0x0E,0x1F,0x1F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x80,0x80,0xC0,0xC0,0xC0,0xC0,0x40,0xC0,
  0x0F,0x0F,0x1E,0x1F,0x1E,0x1F,0x3B,0x3F,0x7B,0x7F,0x7D,0x7F,0x7F,0x7F,0x7F,0x7F,
  0x4F,0x7F,0x4F,0x7F,0x6F,0x7F,0x37,0x3F,0x1F,0x1F,0x0B,0x0F,0x09,0x0F,0x0F,0x0F,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFB,0xFF,0xFB,0xFF,0xFF,0xFF,0xFB,0xFF,0xBD,0xFF,
  0xDE,0xFE,0x7F,0xFF,0xBF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF8,0xFF,0xFC,0xFC,0xFE,0xFE,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFB,0xFF,0xFE,0xFF,0xBF,0xFF,0xDF,0xFF,0xF6,0xFF,
  0xF2,0xF7,0xFD,0xFF,0xE8,0xFD,0x9C,0xDC,0x3E,0xFE,0x7F,0xFF,0xF9,0xFF,0xB4,0xFD,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xDF,0xFF,0x7F,0xFF,0xFD,0xFF,0xFB,0xFF,0x6F,0xFF,
  0x4F,0xEF,0xBF,0xFF,0x17,0xBF,0x39,0x3B,0x7C,0x7F,0xFE,0xFF,0x9F,0xFF,0x2D,0xBF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xDF,0xFF,0xDF,0xFF,0xFF,0xFF,0xDF,0xFF,0xBD,0xFF,
  0x7B,0x7F,0xFE,0xFF,0xFD,0xFF,0xFF,0xFF,0xFF,0xFF,0x1F,0xFF,0x3F,0x3F,0x7F,0x7F,
  0xF0,0xF0,0x78,0xF8,0x78,0xF8,0xDC,0xFC,0xDE,0xFE,0xBE,0xFE,0xFE,0xFE,0xFE,0xFE,
  0xF2,0xFE,0xF2,0xFE,0xF6,0xFE,0xEC,0xFC,0xF8,0xF8,0xD0,0xF0,0x90,0xF0,0xF0,0xF0,
  0x0F,0x0F,0x0F,0x0F,0x0C,0x0D,0x04,0x05,0x06,0x06,0x03,0x03,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0xFF,0xFF,0xFF,0xFF,0xFB,0xFF,0xED,0xFF,0xBD,0xBD,0x1F,0x1F,0x19,0x1F,0x19,0x1B,
  0x0D,0x0D,0x0F,0x0F,0x06,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0xD6,0xFE,0xEB,0xFF,0xA7,0xAF,0xB2,0xB2,0x9E,0x9E,0x80,0x80,0x80,0x80,0x80,0x80,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x6B,0x7F,0xD7,0xFF,0xE5,0xF5,0x4D,0x4D,0x79,0x79,0x01,0x01,0x01,0x01,0x01,0x01,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0xFF,0xFF,0xFF,0xFF,0xDF,0xFF,0xB7,0xFF,0xBD,0xBD,0xF8,0xF8,0x98,0xF8,0x98,0xD8,
  0xB0,0xB0,0xF0,0xF0,0x60,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0xF0,0xF0,0xF0,0xF0,0x30,0xB0,0x20,0xA0,0x60,0x60,0xC0,0xC0,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

// Filename: Stars.jpg
// Pixel Width: 128px
// Pixel Height: 128px

const int Stars_tile_map_size = 0x0100;
const int Stars_tile_map_width = 0x10;
const int Stars_tile_map_height = 0x10;

const int Stars_tile_data_size = 0x02A0;
const int Stars_tile_count = 0x0100;

const unsigned char Stars_map_data[] ={
  0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,
  0x03,0x00,0x00,0x04,0x00,0x00,0x05,0x00,0x00,0x00,0x06,0x07,0x00,0x00,0x06,0x08,
  0x00,0x00,0x00,0x09,0x00,0x00,0x00,0x00,0x00,0x00,0x0A,0x0B,0x0C,0x00,0x00,0x0D,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x00,0x0E,0x0F,0x00,
  0x00,0x10,0x11,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x12,0x00,0x00,
  0x00,0x00,0x00,0x13,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x14,0x15,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x16,0x00,0x0F,0x17,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x00,0x00,0x19,0x00,0x00,0x00,0x00,
  0x00,0x00,0x1A,0x00,0x00,0x00,0x00,0x00,0x1B,0x00,0x00,0x00,0x00,0x00,0x01,0x0E,
  0x00,0x00,0x00,0x00,0x1C,0x1D,0x1E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x1F,0x00,0x00,0x00,0x00,0x00,0x20,0x03,0x00,0x00,0x00,0x21,0x09,
  0x00,0x00,0x00,0x22,0x23,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x1C,0x24,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x25,0x00,0x26,0x00,0x00,0x00,0x11,0x00,0x00,0x00,0x00,0x00,0x00,0x27,
  0x00,0x00,0x00,0x0F,0x00,0x28,0x00,0x00,0x29,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

const unsigned char Stars_tile_data[] ={
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x00,0x20,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x00,0xC0,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,
  0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,
  0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x04,0x03,0x01,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,
  0x00,0x00,0x02,0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x06,0x04,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x08,0x10,0x0C,0x08,0x00,0x00,0x00,
  0x00,0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x20,0xC0,0x00,0xE0,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x01,
  0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x0C,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x04,0x03,0x00,0x03,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x01,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0x00,
  0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

// Filename: Title.jpg
// Pixel Width: 128px
// Pixel Height: 128px

// ///////////////////////
// //                   //
// //  File Attributes  //
// //                   //
// ///////////////////////

// Filename: Title.jpg
// Pixel Width: 128px
// Pixel Height: 128px

const int Title_tile_map_size = 0x0100;
const int Title_tile_map_width = 0x10;
const int Title_tile_map_height = 0x10;

const int Title_tile_data_size = 0x05B0;
const int Title_tile_count = 0x0100;

const unsigned char Title_map_data[] ={
  0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,
  0x03,0x00,0x00,0x04,0x00,0x00,0x05,0x00,0x00,0x00,0x06,0x07,0x00,0x00,0x06,0x08,
  0x00,0x00,0x00,0x09,0x00,0x00,0x00,0x00,0x00,0x00,0x0A,0x0B,0x0C,0x00,0x00,0x0D,
  0x00,0x00,0x00,0x00,0x00,0x0E,0x0F,0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x00,
  0x00,0x18,0x19,0x00,0x00,0x1A,0x1B,0x1C,0x1D,0x1E,0x1F,0x20,0x00,0x21,0x00,0x22,
  0x00,0x00,0x00,0x23,0x00,0x24,0x25,0x26,0x27,0x28,0x29,0x2A,0x2B,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x2C,0x2D,0x2E,0x2F,0x30,0x31,0x32,0x33,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x34,0x35,0x36,0x37,0x38,0x39,0x3A,0x3B,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x3C,0x3D,0x3E,0x3F,0x40,0x41,0x42,0x43,0x00,0x00,0x00,0x00,
  0x00,0x00,0x44,0x00,0x00,0x00,0x00,0x00,0x45,0x00,0x00,0x00,0x00,0x00,0x01,0x16,
  0x00,0x00,0x00,0x00,0x46,0x47,0x48,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x49,0x00,0x00,0x4A,0x4B,0x4C,0x4D,0x03,0x00,0x00,0x00,0x4E,0x09,
  0x00,0x00,0x00,0x4F,0x50,0x00,0x51,0x52,0x53,0x54,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x46,0x55,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x56,0x00,0x57,0x00,0x00,0x00,0x19,0x00,0x00,0x00,0x00,0x00,0x00,0x58,
  0x00,0x00,0x00,0x17,0x00,0x59,0x00,0x00,0x5A,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

const unsigned char Title_tile_data[] ={
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x00,0x20,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x00,0xC0,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,
  0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x7C,0x7C,0xFC,0x7C,0x7C,0xFC,0xF8,0xFD,0xFD,0xF9,
  0x00,0x00,0x00,0x00,0x00,0x00,0x7C,0x7C,0x78,0xFC,0xFD,0xF8,0xF9,0xF9,0xF3,0xF9,
  0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0x7C,0xFC,0xFC,0xFC,0xFC,0xD8,0xFC,0xFC,0xD8,
  0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x07,0x1F,0x1F,0x3F,0x3F,0x7D,0x39,0x7B,0x79,
  0x00,0x00,0x00,0x00,0x00,0x00,0x81,0xC0,0xE3,0xE3,0xE3,0xE7,0xEF,0xE7,0xE7,0xCF,
  0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0xF8,0xFC,0xFC,0xFC,0xFC,0x3C,0xBC,0x38,0x3C,
  0x00,0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,
  0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x01,0x01,0x01,0x03,0x01,0x01,0x03,0x03,0x03,0x07,0x03,0x03,0x07,0x07,0x07,
  0xFD,0xFB,0xFF,0xFB,0xDA,0xFF,0xFC,0xDF,0xFF,0xDD,0xFD,0x9D,0xBF,0xB9,0xBB,0xBB,
  0xFB,0xF3,0xF7,0xF3,0xE7,0xF7,0xFF,0xE7,0xEF,0xEE,0xDE,0xEE,0xFF,0xDF,0xFF,0xDF,
  0xDC,0xB8,0xB8,0xB8,0x38,0x38,0x78,0x38,0x70,0x38,0x38,0x70,0xF1,0xF1,0xF3,0xF1,
  0x7C,0x78,0x7E,0x7C,0x7F,0x7E,0x3F,0x3F,0x3F,0x1F,0x1F,0x0F,0xC7,0xEF,0xEF,0xCF,
  0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x07,0x07,0x03,0x83,0x01,0x81,0xBC,0x3D,0x3C,0x39,
  0x00,0x80,0x80,0xC0,0xC0,0xE0,0xF0,0xE0,0xF0,0xF0,0xE0,0xF0,0xE0,0xF0,0xF0,0xE0,
  0x04,0x03,0x01,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x0F,0x07,0x07,0x0F,0x0E,0x0F,0x1E,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0xFB,0x33,0x37,0x73,0x63,0x77,0x77,0x67,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0xBF,0xFF,0xB8,0xF8,0xF8,0xF8,0xF1,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0xF1,0xF3,0x61,0xF3,0xE1,0xF3,0xF1,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0xCF,0xCF,0xFE,0xFE,0xFE,0xFC,0xF8,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x79,0x39,0x7F,0x3F,0x7F,0x3F,0x3E,0x1F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0xE0,0xE0,0xE0,0xC0,0x80,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x00,
  0x00,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x07,0x03,0x03,0x07,0x07,0x07,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0xF8,0xFE,0xFC,0xFE,0xFC,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0x3F,0x7F,0x7F,0x7F,0x7F,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x87,0xCF,0xC7,0xC7,0xCF,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0xF8,0xFC,0xF9,0xF9,0xF9,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF1,0xF3,0xE3,0xF3,0xE7,0xE3,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF9,0xF9,0xF9,0xF9,0xFB,0xF1,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0xFE,0xFF,0xFE,0xFE,0xFF,
  0x07,0x07,0x07,0x0F,0x0F,0x0F,0x1F,0x0F,0x0F,0x1E,0x1E,0x1E,0x3E,0x1E,0x1E,0x3C,
  0xBE,0xBC,0xBC,0x3C,0x78,0x3C,0x7D,0x78,0x79,0x79,0xF1,0x79,0xFB,0xF1,0xF3,0xF3,
  0xF3,0x7B,0xF3,0xF3,0xF3,0xF7,0xFF,0xFF,0xFC,0xFE,0xFF,0xFE,0xCF,0xEE,0xDF,0xCE,
  0xCF,0xCF,0xDF,0x8F,0x8F,0x9E,0x9E,0x1E,0x3E,0x1E,0x1E,0x3C,0x3D,0x3C,0x7C,0x3D,
  0x7B,0xF9,0xFB,0x73,0x7F,0xF3,0xF7,0xF7,0xF7,0xF7,0xF7,0xEF,0xFF,0xEF,0xEF,0xFE,
  0xC3,0xE7,0xC7,0xC7,0x8F,0xC7,0x87,0x8F,0x0F,0x8F,0x1F,0x0F,0x0F,0x1F,0x1E,0x1E,
  0xC3,0x83,0x83,0x83,0xA7,0x83,0x87,0x07,0xC7,0xE7,0xEF,0xC7,0xCF,0xCF,0x0F,0x0F,
  0xFF,0xCE,0xCE,0xDE,0x9E,0xFE,0xFC,0xFC,0xF8,0xF0,0xF8,0xF8,0xF8,0x38,0x38,0x78,
  0x3D,0x3C,0x79,0x3D,0x3F,0x79,0x7F,0x7F,0xFF,0x7F,0x7F,0xFF,0x00,0x00,0x00,0x00,
  0xE3,0xF3,0xF7,0xE3,0xE7,0xE7,0xE7,0xC7,0xCF,0xC7,0x8F,0x0F,0x00,0x00,0x00,0x00,
  0xCE,0xDE,0xDE,0x9E,0xBE,0x9C,0x9C,0xBC,0xB8,0x3C,0x7D,0x38,0x00,0x00,0x00,0x00,
  0x3D,0x79,0x79,0x79,0xF1,0x79,0x7B,0xF1,0xF3,0xF1,0xE1,0xF3,0x00,0x00,0x00,0x00,
  0xFE,0xFE,0xFC,0xFE,0xFC,0xFC,0xFC,0xF8,0xF8,0xF8,0xF8,0xF0,0x00,0x00,0x00,0x00,
  0x3C,0x1E,0x1E,0x3C,0x3C,0x3C,0x7F,0x3F,0x3F,0x7F,0x7F,0x7F,0x00,0x00,0x00,0x00,
  0x1E,0x0F,0x1E,0x1E,0x1E,0x1E,0xBE,0x9C,0xBD,0x3C,0x3C,0x3D,0x00,0x00,0x00,0x00,
  0x78,0x78,0xF8,0x70,0x70,0xF0,0xF0,0xF0,0xF4,0xE8,0xF0,0xEC,0x08,0x00,0x00,0x00,
  0x00,0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x20,0xC0,0x00,0xE0,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x01,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x1D,0x0B,0x19,0x19,0x0B,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0xC0,0x2C,0x6C,0x2C,0x7E,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0xE7,
  0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x18,0x0C,0xC8,0x6C,0xF8,0xEC,
  0x00,0x0C,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x04,0x03,0x00,0x03,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x1B,0x09,0x19,0x09,0x18,0x08,0x1B,0x09,0x1B,0x09,0x08,0x1D,0x00,0x00,0x00,0x00,
  0xCC,0x8D,0xEC,0xED,0x6C,0x6C,0x3C,0x6D,0x2C,0x6D,0xE5,0xCE,0x00,0x00,0x00,0x00,
  0xBF,0xB7,0xBE,0xB6,0xFE,0x74,0xFE,0xB4,0xBC,0xB6,0xBC,0xF6,0x00,0x00,0x00,0x00,
  0xE8,0x4C,0xE8,0x4C,0xE8,0x4C,0xE8,0x4C,0xE8,0x4C,0x78,0x7C,0x00,0x00,0x00,0x00,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x01,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0x00,
  0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

// Filename: GameOver.jpg
// Pixel Width: 128px
// Pixel Height: 128px

const int GameOver_tile_map_size = 0x0100;
const int GameOver_tile_map_width = 0x10;
const int GameOver_tile_map_height = 0x10;

const int GameOver_tile_data_size = 0x0450;
const int GameOver_tile_count = 0x0100;

const unsigned char GameOver_map_data[] ={
  0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,
  0x03,0x00,0x00,0x04,0x00,0x00,0x05,0x00,0x00,0x00,0x06,0x07,0x00,0x00,0x06,0x08,
  0x00,0x00,0x00,0x09,0x00,0x00,0x00,0x00,0x00,0x00,0x0A,0x0B,0x0C,0x00,0x00,0x0D,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x0E,0x0F,0x10,0x00,
  0x00,0x11,0x12,0x00,0x00,0x0F,0x13,0x14,0x15,0x16,0x17,0x00,0x00,0x18,0x00,0x19,
  0x00,0x00,0x00,0x1A,0x00,0x1B,0x1C,0x1D,0x1E,0x1F,0x20,0x21,0x22,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x23,0x24,0x25,0x26,0x27,0x28,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x29,0x2A,0x2B,0x2C,0x2D,0x2E,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x2F,0x30,0x31,0x32,0x33,0x34,0x00,0x00,0x00,0x00,
  0x00,0x00,0x35,0x00,0x00,0x00,0x00,0x00,0x36,0x00,0x00,0x00,0x00,0x00,0x01,0x0F,
  0x00,0x00,0x00,0x00,0x37,0x38,0x39,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x3A,0x00,0x00,0x00,0x00,0x00,0x3B,0x03,0x00,0x00,0x00,0x3C,0x09,
  0x00,0x00,0x00,0x3D,0x3E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x37,0x3F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x40,0x00,0x41,0x00,0x00,0x00,0x12,0x00,0x00,0x00,0x00,0x00,0x00,0x42,
  0x00,0x00,0x00,0x10,0x00,0x43,0x00,0x00,0x44,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

const unsigned char GameOver_tile_data[] ={
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x00,0x20,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x00,0xC0,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,
  0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,
  0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x78,0xF0,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0x7C,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3E,0x3C,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x79,0x7D,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0xF8,
  0x04,0x03,0x01,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x03,0x01,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,
  0xF8,0xFC,0x9E,0xDC,0xDE,0x9C,0xDC,0x9E,0xDC,0x9E,0x81,0xC0,0xDD,0xBE,0xFC,0x9F,
  0x7C,0xFC,0x7C,0xFC,0xEC,0xFC,0xFE,0xEC,0xCE,0xEC,0xEC,0xCE,0xEE,0xCE,0xCE,0xCE,
  0x7E,0x3C,0x3C,0x3E,0x3E,0x3E,0x3E,0x3E,0x3B,0x3E,0x3A,0x3F,0x3B,0x3F,0x3F,0x3B,
  0xFD,0x79,0xFD,0x79,0x79,0xFD,0xFD,0xF9,0xFD,0xF9,0xB9,0xFD,0xBD,0xF9,0xFD,0xB9,
  0xFC,0xF8,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xF8,0xF8,0xF8,0xF8,0xE0,0xE0,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x00,
  0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x01,0x01,0x00,0x00,0x00,0x00,0x00,
  0xDD,0x9F,0xDF,0x9F,0x9F,0xDF,0x9F,0xDF,0xFF,0xFF,0xFF,0xEF,0x00,0x00,0x00,0x00,
  0xC6,0xCE,0xFF,0xFE,0xFF,0xFE,0x8E,0xC7,0xCF,0xC7,0xCF,0xC7,0x00,0x00,0x00,0x00,
  0x3B,0x3B,0x3B,0x3B,0x39,0x3B,0x39,0x3B,0x39,0x3B,0x3B,0x39,0x00,0x00,0x00,0x00,
  0xBD,0xB9,0xBD,0xB9,0xB9,0xBD,0xBD,0xB9,0x9D,0xB9,0x19,0xBD,0x00,0x00,0x00,0x00,
  0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xFC,0xF8,0xF8,0xFC,0x00,0x00,0x00,0x00,
  0x1E,0x3C,0xFE,0x7F,0xE7,0xF7,0xF7,0xE7,0xF7,0xE7,0xE7,0xF7,0xF7,0xE7,0xF7,0xE7,
  0x73,0xF3,0x73,0xF3,0xFB,0xF3,0xFB,0xF3,0xFB,0xF3,0x73,0xFB,0x37,0xFB,0xB7,0x7B,
  0xCF,0xCF,0xCF,0xCF,0x8E,0xCF,0x8E,0xCF,0xCE,0x8F,0xCE,0x8F,0x8F,0x8F,0x8F,0x8F,
  0xDF,0xCF,0xDF,0xCF,0x1F,0x0E,0x1F,0x0E,0x1F,0x0E,0x1F,0x0E,0xDF,0xCF,0xDF,0xCF,
  0xE0,0xC0,0xF0,0xE0,0xF0,0x70,0xF0,0x70,0xF0,0x70,0xF0,0x70,0xF0,0xE0,0xC0,0xE0,
  0x00,0x00,0x02,0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0xF7,0xE7,0xF7,0xE7,0xE7,0xF7,0xF7,0xE7,0xE7,0xF7,0xFE,0x7F,0x1E,0x3C,0x00,0x00,
  0xFF,0x3B,0xBB,0x3F,0x3F,0xBF,0xBF,0x3F,0x9F,0x3F,0x1F,0x3F,0x3F,0x1F,0x00,0x00,
  0x8E,0x8F,0x0E,0x8F,0x8E,0x0F,0x8E,0x0F,0x0E,0x0F,0x0F,0x0F,0x0F,0x0F,0x00,0x00,
  0x1F,0x0E,0x1F,0x0E,0x1F,0x0E,0x1F,0x0E,0x1F,0x0E,0xFF,0xCE,0xFF,0xCE,0x00,0x00,
  0xF0,0x70,0xF0,0x70,0xF0,0x70,0xF0,0x70,0xF0,0x70,0xF0,0x70,0xF0,0x70,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x08,0x10,0x0C,0x08,0x00,0x00,0x00,
  0x00,0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x20,0xC0,0x00,0xE0,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x01,
  0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x0C,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x04,0x03,0x00,0x03,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x01,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0x00,
  0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};



// Numbers for score printing, 8x8
const int Number_tile_sizes = 0x20; //per number tile size
const int Number_tile_count = 0x02; //per number tile count

const unsigned char Number_tile_data[] ={
	// 0
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 
	0x00,0x00,0x7E,0x7E,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x7E,0x7E,
	// 1
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x38,0x38,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x7E,0x7E,
	// 2
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 
	0x00,0x00,0x7E,0x7E,0x02,0x02,0x02,0x02,0x7E,0x7E,0x40,0x40,0x40,0x40,0x7E,0x7E,
	// 3
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 
	0x00,0x00,0x7E,0x7E,0x02,0x02,0x02,0x02,0x1E,0x1E,0x02,0x02,0x02,0x02,0x7E,0x7E,
	// 4
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 
	0x00,0x00,0x42,0x42,0x42,0x42,0x42,0x42,0x7E,0x7E,0x02,0x02,0x02,0x02,0x02,0x02,
	// 5
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 
	0x00,0x00,0x7E,0x7E,0x40,0x40,0x40,0x40,0x7E,0x7E,0x02,0x02,0x02,0x02,0x7E,0x7E,
	// 6
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 
	0x00,0x00,0x7E,0x7E,0x40,0x40,0x40,0x40,0x7E,0x7E,0x42,0x42,0x42,0x42,0x7E,0x7E,
	// 7
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 
	0x00,0x00,0x7E,0x7E,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,
	// 8
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 
	0x00,0x00,0x7E,0x7E,0x42,0x42,0x42,0x42,0x7E,0x7E,0x42,0x42,0x42,0x42,0x7E,0x7E,
	// 9
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 
	0x00,0x00,0x7E,0x7E,0x42,0x42,0x42,0x42,0x7E,0x7E,0x02,0x02,0x02,0x02,0x02,0x02
};

// Filename: Explode.png
// Pixel Width: 24px
// Pixel Height: 16px

const int Explode_tile_count = 0x06;

const unsigned char Explode_tile_data[] ={
  0x00,0x00,0x00,0x00,0x38,0x38,0x44,0x5C,0x44,0x6C,0x28,0x7C,0x44,0x6C,0x44,0x74,
  0x38,0x7C,0x00,0x28,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x43,0x43,0x81,0xC3,0x9C,0xDC,0x4A,0x7E,0x46,0x7E,0x2A,0x7E,0x12,0x1E,
  0x4C,0x4C,0x41,0x63,0x23,0x27,0x04,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x43,0x43,0x80,0xC2,0x10,0x10,0x22,0x32,0x22,0x36,0x02,0x06,0x41,0x63,0x40,0x60,
  0x22,0x26,0x02,0x0E,0x0C,0x0C,0x40,0x60,0x21,0x23,0x02,0x02,0x00,0x00,0x00,0x00
};
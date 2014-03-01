#include "images.h"

// ///////////////////////
// //                   //
// //  File Attributes  //
// //                   //
// ///////////////////////

// Filename: Test.png
// Pixel Width: 32px
// Pixel Height: 32px

// /////////////////
// //             //
// //  Constants  //
// //             //
// /////////////////

int Test_tile_map_size = 0x10;
int Test_tile_map_width = 0x04;
int Test_tile_map_height = 0x04;

int Test_tile_data_size = 0xD0;
int Test_tile_count = 0x10;

// ////////////////
// //            //
// //  Map Data  //
// //            //
// ////////////////

unsigned char Test_map_data[] ={
  0x00,0x01,0x02,0x03,0x04,0x02,0x05,0x06,0x07,0x08,0x09,0x0A,0x08,0x09,0x0B,0x0C
};

// /////////////////
// //             //
// //  Tile Data  //
// //             //
// /////////////////

unsigned char Test_tile_data[] ={
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFE,0xFF,0xFC,0xFF,0xF8,0xFF,0xF0,0xFF,
  0xE0,0xFF,0xC0,0xFF,0x80,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,
  0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x01,0xFE,0x03,0xFC,0x07,0xF8,0x0F,0xF0,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFE,0xFF,0xFC,0xFF,0xF8,0xFF,0xF0,0xFF,0xE0,0xFF,
  0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x01,0xFE,0x03,0xFC,0x0F,0xF0,0x1F,0xE0,
  0x1F,0xE0,0x3F,0xC0,0x7F,0x80,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,
  0xC0,0xFF,0x80,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,
  0x00,0xFF,0x00,0xFF,0x00,0xFF,0x01,0xFE,0x03,0xFC,0x07,0xF8,0x0F,0xF0,0x1F,0xE0,
  0x3F,0xC0,0x7F,0x80,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,
  0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFE,0x00,0xFC,0x00,0xF8,0x00,0xF0,0x00,
  0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFE,0x00,0xFC,0x00,0xF8,0x00,0xF0,0x00,0xE0,0x00,
  0xC0,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

// ///////////////////////
// //                   //
// //  File Attributes  //
// //                   //
// ///////////////////////

// Filename: Test2.png
// Pixel Width: 16px
// Pixel Height: 16px

// /////////////////
// //             //
// //  Constants  //
// //             //
// /////////////////

int Test2_tile_map_size = 0x04;
int Test2_tile_map_width = 0x02;
int Test2_tile_map_height = 0x02;

int Test2_tile_data_size = 0x40;
int Test2_tile_count = 0x04;

// ////////////////
// //            //
// //  Map Data  //
// //            //
// ////////////////

unsigned char Test2_map_data[] ={
  0x00,0x01,0x02,0x03
};

// /////////////////
// //             //
// //  Tile Data  //
// //             //
// /////////////////

unsigned char Test2_tile_data[] ={
  0x07,0x0F,0x3F,0x1F,0x7C,0x38,0x60,0x70,0x60,0xE0,0xC0,0xC0,0xC0,0xC0,0x80,0xC0,
  0x80,0xC0,0xC0,0xC0,0xC0,0xC0,0x40,0xE0,0x70,0x60,0x38,0x70,0x1D,0x3E,0x1F,0x0F,
  0xE0,0xF0,0xFC,0xF8,0x0E,0x1C,0x0E,0x06,0x02,0x07,0x03,0x03,0x01,0x03,0x03,0x01,
  0x03,0x01,0x01,0x03,0x03,0x03,0x07,0x03,0x07,0x06,0x1C,0x0E,0xB8,0x7C,0xF8,0xF0
};

// ///////////////////////
// //                   //
// //  File Attributes  //
// //                   //
// ///////////////////////

// Filename: bullet.png
// Pixel Width: 8px
// Pixel Height: 8px

// /////////////////
// //             //
// //  Constants  //
// //             //
// /////////////////

int bullet_tile_map_size = 0x02;
int bullet_tile_map_width = 0x01;
int bullet_tile_map_height = 0x02;

int bullet_tile_data_size = 0x20;
int bullet_tile_count = 0x02;

// ////////////////
// //            //
// //  Map Data  //
// //            //
// ////////////////

unsigned char bullet_map_data[] ={
  0x00,0x01
};

// /////////////////
// //             //
// //  Tile Data  //
// //             //
// /////////////////

unsigned char bullet_tile_data[] ={
  0x00,0x00,0x00,0x00,0x18,0x18,0x3C,0x24,0x3C,0x24,0x18,0x18,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

// ///////////////////////
// //                   //
// //  File Attributes  //
// //                   //
// ///////////////////////

// Filename: enemy.png
// Pixel Width: 8px
// Pixel Height: 16px

// /////////////////
// //             //
// //  Constants  //
// //             //
// /////////////////

int enemy_tile_map_size = 0x02;
int enemy_tile_map_width = 0x01;
int enemy_tile_map_height = 0x02;

int enemy_tile_data_size = 0x20;
int enemy_tile_count = 0x02;

// ////////////////
// //            //
// //  Map Data  //
// //            //
// ////////////////

unsigned char enemy_map_data[] ={
  0x00,0x01
};

// /////////////////
// //             //
// //  Tile Data  //
// //             //
// /////////////////

unsigned char enemy_tile_data[] ={
  0x24,0x24,0x24,0x24,0x5A,0x7E,0x5A,0x7E,0x81,0xFF,0xBD,0xC3,0xFF,0xBD,0xBD,0xC3,
  0x5A,0x7E,0x5A,0x7E,0x24,0x24,0x24,0x24,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

#pragma once

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb_image_write.h>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <memory>
#include <immintrin.h>


class Image {
public:
    Image(const std::string& filename) {
        unsigned char* data = stb_load(filename.c_str(), )
    }
private:
    


};

// struct Image{

//     Image(Image&& img) = delete;

//     Image() = default;
//     Image(const char* fileName) {
        
//         n_data = stbi_load(fileName, &n_width, &n_height, &n_channels, 0);
//         if (n_data == nullptr) {
//             std::cout << "Error: Image was not loading!!" << std::endl;
//             throw "Error: Image was not loading!!";
//         }

//     }
//     Image(const Image& img) 
//         : n_data(img.n_data), n_width(img.n_width), n_height(n_height), n_channels(img.n_channels) {}

//     ~Image() { stbi_image_free(n_data); }
    
//     unsigned char* n_data;
        
//     int n_width;
//     int n_height;
//     int n_channels;
// };

// enum class FileType {
//     JPG = 0, 
//     PNG = 1,
// };

// void Save(FileType type, Image& img, const char* fileName) {
//     if (img.n_data == nullptr) { 
//         std::cout << "Error: There is not image !\n";    
//         return; 
//     }

//     switch (type)
//     {
//     case FileType::JPG:
//         stbi_write_jpg(fileName, img.n_width, img.n_height, img.n_channels, img.n_data, img.n_width * img.n_channels);
//         break;
    
//     case FileType::PNG:
//         stbi_write_png(fileName, img.n_width, img.n_height, img.n_channels, img.n_data, img.n_width * img.n_channels);
//         break;
//     default: // Write later
//         break;
//     }

// }


// void Color2Gray(Image& new_img, const Image& old_img) {

//     int r, g, b;
//     unsigned char* tmp = new unsigned char[old_img.n_width * old_img.n_height];
//     new_img.n_width = old_img.n_width;
//     new_img.n_height = old_img.n_height;
//     new_img.n_channels = 1;
//     for (int i = 0; i < old_img.n_width * old_img.n_height; i++) {
//         r = old_img.n_data[i * 3];
//         g = old_img.n_data[i * 3 + 1];
//         b = old_img.n_data[i * 3 + 2];
//         tmp[i] = static_cast<unsigned char>(0.299 * r + 0.587 * g + 0.114 * b);
//     }
//     new_img.n_data = tmp;
// }

// void Color2Gray(unsigned char* output, unsigned char* img, const int& width, const int& height) {

//     int r, g, b;
//     for (int i = 0; i < width * height; i++) {
//         r = img[i * 3];
//         g = img[i * 3 + 1];
//         b = img[i * 3 + 2];
//         output[i] = static_cast<unsigned char>(0.299 * r + 0.587 * g + 0.114 * b);
//     }
// }

// enum class PPMType {
//     Gray = 0,
//     Color = 1,
// };

// void StorePPM(unsigned char* img, const char* name, const int& width, const int& height, PPMType type) {
    
//     std::ofstream file(name, std::ios::binary);
//     switch (type)
//     {
//     case PPMType::Gray:
//         file << "P5\n" << width << " " << height << "\n255\n";
//         file.write(reinterpret_cast<char*>(img), width * height);
//         break;
//     case PPMType::Color:
//         file << "P6\n" << width << " " << height << "\n255\n";
//         file.write(reinterpret_cast<char*>(img), width * height * 3);
//         break;
//     }
//     file.close();
// }

// void BrightDelta(unsigned char* output_img, unsigned char* img, const int& width, const int& height, const int& channels, int delta) {

//     for (int i = 0; i < width * height * channels; ++i) {
//         output_img[i] = img[i];
//     }
//     int value;
//     for (int i = 0; i < width * height * channels; ++i) {
//         value = output_img[i] + delta;
//         output_img[i] = static_cast<unsigned char>(std::clamp(value, 0, 255));
//     }

// }

// struct Color {
//     unsigned char r;
//     unsigned char g;
//     unsigned char b;
// };

// void SimpleConvolution(Image& new_img, const Image& old_img) {

//     new_img.n_channels = old_img.n_channels;
//     new_img.n_height = old_img.n_height;
//     new_img.n_width = old_img.n_width;
//     new_img.n_data = new unsigned char[old_img.n_width * old_img.n_height * old_img.n_channels];
    
//     int idx;
//     for (int x = 1; x < old_img.n_width - 1; x++) {
//         for (int y = 1; y < old_img.n_height - 1; y++) {
//             Color sum = {0,0,0};
//             for (int ky = -1; ky <= 1; ky++) {
//                 for (int kx = -1; kx <= 1; kx++) {
//                     idx = ((y + ky) * old_img.n_width + (x + kx)) * 3;
//                     sum.r += old_img.n_data[idx];
//                     sum.g += old_img.n_data[idx + 1];
//                     sum.b += old_img.n_data[idx + 2];
//                 }
//             } 
//             idx = (y * old_img.n_width + x) * 3;
//             new_img.n_data[idx] = sum.r / 9;
//             new_img.n_data[idx + 1] = sum.g / 9;
//             new_img.n_data[idx + 2] = sum.b / 9;
//         }
//     }
// }

// constexpr float M_PI = 3.1415926;

// void SobelEdgeDetection(Image& new_img, const Image& old_img, unsigned char* direction) {

//     Image tmp;
//     Color2Gray(tmp, old_img);
//     unsigned char* tmp_data = new unsigned char[tmp.n_width * tmp.n_height];
//     new_img.n_channels = tmp.n_channels;
//     new_img.n_width = tmp.n_width;
//     new_img.n_height = tmp.n_height;

//     int gx, gy;
//     int gradient;
//     float theta;
//     for (int x = 1; x < tmp.n_width - 1; x++) {
//     for (int y = 1; y < tmp.n_height - 1; y++) {
//             gx = (-1 * tmp.n_data[(y - 1) * tmp.n_width + (x - 1)]) + (1 * tmp.n_data[(y - 1) * tmp.n_width + (x + 1)]) +
//                  (-2 * tmp.n_data[(  y  ) * tmp.n_width + (x - 1)]) + (2 * tmp.n_data[(  y  ) * tmp.n_width + (x + 1)]) +
//                  (-1 * tmp.n_data[(y + 1) * tmp.n_width + (x - 1)]) + (1 * tmp.n_data[(y + 1) * tmp.n_width + (x + 1)]);

//             gy = (-1 * tmp.n_data[(y - 1) * tmp.n_width + (x - 1)]) + (-2 * tmp.n_data[(y - 1) * tmp.n_width + (x)]) + (-1 * tmp.n_data[(y - 1) * tmp.n_width + (x + 1)]) + 
//                  (1 * tmp.n_data[(y + 1) * tmp.n_width + (x - 1)]) + (2 * tmp.n_data[(y + 1) * tmp.n_width + (x)]) + (1 * tmp.n_data[(y + 1) * tmp.n_width + (x + 1)]);    
//             gradient = std::min(static_cast<int>(std::abs(gx) + std::abs(gy)), 255);
//             tmp_data[y * tmp.n_width + x] = gradient;
//             theta = std::atan2(gy, gx) * 180 / M_PI;
//             direction[y * tmp.n_width + x] = static_cast<unsigned char>((theta + 180) / 360 * 255);
//         }
//     }
//     new_img.n_data = tmp_data;

// }

// void gaussianBlur(Image& new_img, const Image& old_img) {
    
//     unsigned char* tmp = new unsigned char[old_img.n_width * old_img.n_height];
//     new_img.n_channels = old_img.n_channels;
//     new_img.n_height = old_img.n_height;
//     new_img.n_width = old_img.n_width;

//     int kernel[5][5] = {
//         {1,  4,  6,  4, 1},
//         {4, 16, 24, 16, 4},
//         {6, 24, 36, 24, 6},
//         {4, 16, 24, 16, 4},
//         {1,  4,  6,  4, 1},
//     };
//     int sum;
//     for (int y = 2; y < old_img.n_height - 2; y++) {
//         for (int x = 2; x < old_img.n_width - 2; x++) {
//             sum = 0;
//             for (int ky = -2; ky <= 2; ky++) {
//                 for (int kx = -2; kx <= 2; kx++) {
//                     sum += old_img.n_data[(y + ky) * old_img.n_width + (x + kx)] * kernel[(ky + 2)][(kx + 2)];
//                 }
//             }
//             tmp[y * old_img.n_width + x] = sum / 256;
//         }
//     }
//     new_img.n_data = tmp;
// }

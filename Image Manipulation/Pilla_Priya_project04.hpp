//Priya Pilla

#ifndef Pilla_Priya_project04_h
#define Pilla_Priya_project04_h

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

class ImageManipulation
{
public:
    string inputFileName;
    string outputFileName;
    string magicIdentifier;
    int width = 0;
    int height = 0;
    int maxValue;
    int thresholdValue;
    string rotation90degrees = "no";
    string rotation180degrees = "no";
    string rotation270degrees = "no";
    
    int** imagePixels = new int *[height]();
    int** newImagePixels = new int *[width]();
    
    void allocateImagePixelsArray();
    void allocateNewImagePixelsArray();
    void deallocateImagePixelsArray();
    void deallocateNewImagePixelsArray();
    int rotateImage90Degrees();
    int rotateImage180Degrees();
    void rotateImage270Degrees();
    void flipVertical();
    void flipHorizontal();
    int loadImage();
    void rotateImage();
    void flipImage();
    void convertToBlackAndWhite();
    int saveToOutput();
    void quit();
};

#endif /* Pilla_Priya_project04_h */

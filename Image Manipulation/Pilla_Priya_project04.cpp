// Priya Pilla

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Pilla_Priya_project04.hpp"

using namespace std;

void ImageManipulation::allocateImagePixelsArray(){
    for (int i = 0; i < height; i++) {     // Function to Allocate Image Pixels array
        imagePixels[i] = new int [width];
    }
};

void ImageManipulation::allocateNewImagePixelsArray(){
    for (int i = 0; i < width; i++) {     // Function to Allocate New Image Pixels array
        newImagePixels[i] = new int [height];
    }
};

void ImageManipulation::deallocateImagePixelsArray(){
    for (int i = 0; i < height; i++) {           //Function to Deallocate ImagesPixels Array
        delete [] imagePixels[i];
    }
    delete [] imagePixels;
};

void ImageManipulation::deallocateNewImagePixelsArray(){
    for (int i = 0; i < width; i++) {           //Function to Deallocate NewImagePixels Array
        delete [] newImagePixels[i];
    }
    delete [] newImagePixels;
};

int ImageManipulation::rotateImage90Degrees(){
    
    for(int i=0; i<width; i++) {
        for(int j=0; j<height; j++) {                           //rotate 90 degrees (from original)
            newImagePixels[i][j] = imagePixels[height-1-j][i];
        }
    }
    rotation90degrees = "yes"; // Condition to use in later functions to specify a different array
    return 0;
};

int ImageManipulation::rotateImage180Degrees(){
    
    for(int i=0;i<height;i++) {
        for(int j=0,k=width-1;j<k;j++,k--) {
            swap(imagePixels[i][j],imagePixels[i][k]);           //rotate 180 degrees (from original)
        }
    }
    
    for(int j=0;j<width;j++) {
        for(int i=0, k=height-1; i<k; i++, k--) {
            swap(imagePixels[i][j],imagePixels[k][j]);
        }
    }
    rotation180degrees = "yes";
    
    return 0;
};

void ImageManipulation::rotateImage270Degrees(){
    
    allocateNewImagePixelsArray();
    
    for(int i = 0; i < width; i++) {
        for(int j = 0; j < height; j++) {                           //rotate 90 degrees (from original)
            newImagePixels[i][j] = imagePixels[height-1-j][i];
        }
    }
                                                                                     // Combined rotation 270 degrees
    for(int i = 0;i < width;i++) {
        for(int j = 0,k = height-1; j < k; j++, k--) {
            swap(newImagePixels[i][j],newImagePixels[i][k]);           //rotate 180 degrees (from 90 degrees)
        }
    }
    
    for(int j = 0; j < height; j++) {
        for(int i = 0, k = width-1; i < k; i++, k--) {
            swap(newImagePixels[i][j],newImagePixels[k][j]);
        }
    }
    
    rotation270degrees = "yes";
};

void ImageManipulation::flipVertical(){
                                                                                                //Flip vertical
    if (rotation90degrees == "yes" || rotation270degrees == "yes") {
        for(int i=0;i<width;i++) {
            for(int j=0,k=height-1;j<k;j++,k--) {
                swap(newImagePixels[i][j],newImagePixels[i][k]);
            }
        }
        
        for(int j=0;j<height;j++) {
            for(int i=0, k=width-1; i<k; i++, k--) {
                swap(newImagePixels[i][j],newImagePixels[k][j]);
            }
        }
    }else{
        
        for(int i=0;i<height;i++) {
            for(int j=0,k=width-1;j<k;j++,k--) {
                swap(imagePixels[i][j],imagePixels[i][k]);
            }
        }
        
        for(int j=0;j<width;j++) {
            for(int i=0, k=height-1; i<k; i++, k--) {
                swap(imagePixels[i][j],imagePixels[k][j]);
            }
        }
    }
    
};

void ImageManipulation::flipHorizontal(){
                                                                                            //Flip horizontal
    int temp;
    if (rotation90degrees == "yes" || rotation270degrees == "yes") {
        for(int i = 0; i < width  ; i++) {
            for (int j = 0; j < height/2 ; j++) {
                temp = newImagePixels[i][j];
                newImagePixels[i][j] = newImagePixels[i][height - 1 - j];
                newImagePixels[i][height - 1 - j] = temp;
            }
        }
    }else{
        for(int i = 0; i < height  ; i++) {
            for (int j = 0; j < width/2 ; j++) {
                temp = imagePixels[i][j];
                imagePixels[i][j] = imagePixels[i][width - 1 - j];
                imagePixels[i][width - 1 - j] = temp;
            }
        }
    }
    
};

int ImageManipulation::loadImage(){
    
    ifstream inFS;
    
    inFS.open(inputFileName.c_str());                               //opening input file
    if (!inFS.is_open()){
        cout << "Could not open file " << inputFileName << endl;
        return 1;
    }
    
    inFS >> magicIdentifier >> width >> height >> maxValue;
    
    allocateImagePixelsArray();                           // call to allocate image pixels array
    allocateNewImagePixelsArray();                       //Call to allocate new image pixels array
    
    for (int i = 0; i < height; i++) {                    //fill the array
        for (int j = 0; j < width; j++) {
            inFS >> imagePixels[i][j];
        }
    }
    
    cout << "Image data successfully loaded!" << endl;
    
    inFS.close();                                                // Closing Input File
    
    return 0;
};

void ImageManipulation::rotateImage(){
    int choice;
    cout << "-|ROTATE IMAGE|-" << endl;                   //Menu and Selection for rotating image
    cout << "1. Rotate 90 degrees " << endl
    << "2. Rotate 180 degrees " << endl
    << "3. Rotate 270 degrees " << endl
    << "Select an option: " << endl;
    cin >> choice;
    while (choice > 3 || choice < 0) {
        cout << "Invalid choice. Please choose 1 to 3 only." << endl;
        cout << "Select an option: ";
        cin >> choice;
    }
    
    switch (choice) {
        case 1:
            rotateImage90Degrees();
            break;
        case 2:
            rotateImage180Degrees();
            break;
        case 3:
            rotateImage270Degrees();
            break;
    }
};

void ImageManipulation::flipImage(){
    int choice;
    cout << "-|FLIP IMAGE|-" << endl;
    cout << "1. Flip Vertical " << endl                             // Menu and selection for flipping image
    << "2. Flip Horizontal " << endl
    << "Select an option: " << endl;
    cin >> choice;
    while (choice > 2 || choice < 0) {
        cout << "Invalid choice. Please choose 1 to 2 only." << endl;
        cout << "Select an option: ";
        cin >> choice;
    }
    
    switch (choice) {
        case 1:
            flipVertical();
            break;
        case 2:
            flipHorizontal();
            break;
    }
};

void ImageManipulation::convertToBlackAndWhite(){                                              // Convert image to black and white
    cout << "Enter the threshold value: " << endl;
    cin >> thresholdValue;
    
    if (rotation90degrees == "yes" || rotation270degrees == "yes") {
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                if (newImagePixels[i][j] <= thresholdValue) {
                    newImagePixels[i][j] = 0;
                }else if(newImagePixels[i][j] > thresholdValue){
                    newImagePixels[i][j] = maxValue;
                }
            };
        }
    }else{
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (imagePixels[i][j] <= thresholdValue) {
                    imagePixels[i][j] = 0;
                }else if(imagePixels[i][j] > thresholdValue){
                    imagePixels[i][j] = maxValue;
                }
            };
        }
    }
    cout << "Image converted to Black and White." << endl;
};

int ImageManipulation::saveToOutput(){
    
    ofstream outFS;
    
    outFS.open(outputFileName.c_str());                                   //opening output file
    if (!outFS.is_open()){
        cout << "Could not open file " << outputFileName << endl;
        return 1;
    }
    
    outFS << magicIdentifier << endl << width << " " << height << endl << maxValue << endl;
    if (rotation90degrees == "yes" || rotation270degrees == "yes") {
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {                              //Outputting data into output file
                if (j == 0) {
                    outFS << newImagePixels[i][j];
                }else{
                    outFS << setw(3) << newImagePixels[i][j];
                }
            }
            outFS << endl;
        }
        outFS << endl;
    }else{
        
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (j == 0) {
                    outFS << imagePixels[i][j];
                }else{
                    outFS << setw(3) << imagePixels[i][j];
                }
            }
            outFS << endl;
        }
        outFS << endl;
    }
    cout << "Output successfully saved!" << endl;
    
    outFS.close();                                          // Closing output file
    
    
    
    return 0;
};

void ImageManipulation::quit(){
    deallocateImagePixelsArray();
    deallocateNewImagePixelsArray();                   // Calls to Deallocating arrays
};

// -------------------------------------------------MAIN-----------------------------------------------------
int main()
{
    ImageManipulation imageManipulation;
    int count = 0;
    cout << "Enter the input file name (no greater than 31 characters): " << endl; // User enters input file name
    do {
        count = 0;
        cin >> imageManipulation.inputFileName;
        for (int i = 0; imageManipulation.inputFileName[i] ; i++) { //counts no of chars to make sure they are less than 31
            count++;
        }
        if (count > 31) {
            cout << "Please only enter input file name with no greater than 31 characters: " << endl;
        }
    } while (count > 31);
    
   imageManipulation.loadImage(); // Loading image right after user enters file name
    
    cout << "Enter the output file name (no greater than 31 characters): " << endl; // User enters output file name
    do {
        count = 0;
        cin >> imageManipulation.outputFileName;
        for (int i = 0; imageManipulation.outputFileName[i] ; i++) {
            count++;
        }
        if (count > 31) {
            cout << "Please only enter output file name with no greater than 31 characters: " << endl;
        }
    } while (count > 31);
    
    
    int choice;
    
    do {
        cout << "-|USER INTERFACE|-" << endl                                 // User Interface and selection
        << "1. Load an Image" << endl
        << "2. Rotate image" << endl
        << "3. Flip Image" << endl
        << "4. Convert to Black and White" << endl
        << "5. Save to Output file" << endl
        << "6. Quit" << endl;
        cout << "Input your choice: ";
        cin >> choice;
    while (choice > 6 || choice < 0) {
        cout << "Invalid choice. Input 1 to 6 only!" << endl;
        cout << "Input your choice: ";
        cin >> choice;
    }
        
    switch (choice) {
        case 1:
            imageManipulation.loadImage();
            break;
        case 2:
            imageManipulation.rotateImage();
            break;
        case 3:
            imageManipulation.flipImage();
            break;
        case 4:
            imageManipulation.convertToBlackAndWhite();
            break;
        case 5:
            imageManipulation.saveToOutput();
            break;
        case 6:
            imageManipulation.quit();                        // deallocates arrays
            cout << "Thank you for using :)" << endl;
        }
    } while (choice != 6);
    
    return 0;
}

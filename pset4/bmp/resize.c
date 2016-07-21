/**
 * copy.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./copy infile outfile\n");
        return 1;
    }
    int resize = atoi(argv[1]);
    if(resize < 1 || resize > 100){
        return 0;
    }
    // remember filenames
    char* infile = argv[2];
    char* outfile = argv[3];

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);
    
    
    //bi_re.biSize = bi.biSize * resize;
    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    
    BITMAPINFOHEADER bi_re = bi;
    BITMAPFILEHEADER bf_re = bf;
    bi_re.biWidth = bi_re.biWidth *resize;
    bi_re.biHeight = bi_re.biHeight *resize;
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int rePadding =  (4 - (bi_re.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
   
    bi_re.biSizeImage = (bi_re.biWidth * sizeof(RGBTRIPLE) + rePadding) * abs(bi_re.biHeight);
    bf_re.bfSize = bf.bfSize - bi.biSizeImage + bi_re.biSizeImage;
    // write outfile's BITMAPFILEHEADER
    fwrite(&bf_re, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi_re, sizeof(BITMAPINFOHEADER), 1, outptr);

    // determine padding for scanlines
    int lineSize = bi.biWidth * sizeof(RGBTRIPLE) + padding;
    //int re_padding = padding * resize;
    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++){
        for(int re_H = 0; re_H < resize; re_H++){
            // iterate over pixels in scanline
            for (int j = 0; j < bi.biWidth; j++){
                // temporary storage
                RGBTRIPLE triple;
                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
                
                for(int size_Pix = 0; size_Pix < resize; size_Pix++){
                    // write RGB triple to outfile
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            }
        // skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);

        // then add it back (to demonstrate how)
        for (int k = 0; k < rePadding; k++)
        {
            fputc(0x00, outptr);
        }
        fseek(inptr, -lineSize, SEEK_CUR);
        }
    fseek(inptr, lineSize, SEEK_CUR);
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}

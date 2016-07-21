/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */
 #include <stdio.h>
 #include <stdlib.h>

int main(int argc, char* argv[])
{
    // TODO
    if(argc > 1){
        return 2;
    }
    int jpegNUM = 0;
    FILE* main_Recover = fopen("card.raw", "rb");
    FILE* output_File = NULL;
    unsigned char startSearch [512] = {0};
    char file_Name[200] = {0};
    while(fread(startSearch, 512,1,main_Recover)==1){
        if (startSearch[0] == 0xff && startSearch[1] == 0xd8 && startSearch[2] == 0xff)
        {
            if(output_File!= NULL){
                fclose(output_File);
            }
            sprintf(file_Name, "%03d.jpg", jpegNUM);
            //compiler doesnt like unused ints
            jpegNUM ++;
            output_File = fopen(file_Name, "w");
            fwrite(startSearch, 1, 512, output_File);
        }
        else if(output_File!=NULL){
            fwrite(startSearch, 1, 512, output_File);
        }
        
    }
    fclose(main_Recover);
    fclose(output_File);
}

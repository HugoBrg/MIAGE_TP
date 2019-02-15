#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include <math.h>
#include <string.h>
#include "wav.h"


int quantification4bits( int32_t frameCount, int16_t *buffer_p){
    int32_t k;
    int ret = 0;
    int bits = 16;
    int step = pow(2,bits)/bits;
    for(k = 0; k < frameCount; k++){
        for(int i =0;i<bits;i++){
            if(step*i < buffer_p[k] && buffer_p[k] < step*(i+1)){
                buffer_p[k]=step*(i+1)-step/2;
            }else if(-step*i > buffer_p[k] && buffer_p[k] > -step*(i+1)){
                buffer_p[k]=-(step*(i+1)-step/2);
            }
        }
    }
    return ret;
}

/*Generate one pure tone: a sinusoidal waveform at a frequency and a amplitudes*/
int generate_sinusoid ( double frequency,
                       double amplitude,
                       int32_t SampleRate,
                       int32_t FrameCount,
                       int16_t  *buffer_p)
{
    int ret = 0;
    double SampleRate_d = (double)SampleRate;
    
    int32_t k;
    int16_t wave;
    /*Check for the violation of the Nyquist limit*/
 /*   if (frequency*2 >= SampleRate_d)
    {
        ret = -1;
        goto error0;
    }*/
    
    for(k = 0;
        k < FrameCount;
        k++)
    {
        wave = (int16_t) (amplitude * sin(k*frequency*2.0*M_PI/SampleRate_d));
        buffer_p[k] = wave;
        
    }
    return ret;
/*
error0:
    return ret;*/
}

int generate_melody (double amplitude, int32_t sampleRate, int32_t frameCount, int16_t *buffer_p){
    int melody[] = {264,297,330,352,396,440,495,528,594,660,704,792,880,990,1056}; //fréquences des sons
    int nombreNotes = 15;                                                          //nombre de notes
    int tempsNote = frameCount / nombreNotes;                                      //temps d'une note (temps total/nombre de notes)
    int ret = 0;
    double sampleRate_d = (double)sampleRate;                                      //taux d'échantillonage
    int32_t k;
    int16_t wave;
    int i;
    int j;

    for(k = 0; k < frameCount; k++){
        wave = (int16_t) (amplitude * sin(k*melody[i]*2.0*M_PI/sampleRate_d));
        buffer_p[k] = wave;
        if(j >= tempsNote){
            j=0;
            i++;
        }
        j++;
    }
    return ret;
}


// Write audio samples in a CSV file
size_t write_CSV_file(char* filename, int32_t FrameCount,
                      int16_t  *buffer_p)
{
    size_t ret = 0;
    FILE *csvfile;
    csvfile = fopen(strcat(filename, "_samples.csv"), "w");
    for (int32_t n=0 ; n<FrameCount ; n++){
        ret += fprintf(csvfile, "%d\n", buffer_p[n]);
    }
    fclose(csvfile);
    return ret;
}

int main(int argc, char *argv[])
{
    int ret;
    FILE* file_p;
    char *filename;
    
    double frequency = 440; /*LA_3*/
    
    /* 16 bits / sample */
    double amplitude = 1.0 * (double)SHRT_MAX; // (16 bits)
 
    double duration = 8; /*seconds*/
    int32_t FrameCount = duration * SAMPLE_RATE;
    
    int16_t *buffer_p = NULL;
    size_t written;
    
    /* Verification de l'appel du programme ----*/
    if (argc != 2){ /* usage -- print usage message and exit */
        fprintf(stderr, "Usage: %s filename \n", argv[0]);
        exit(1);
    }
    else
        filename = argv[1];
    
    char filename_cp[20];
    strcpy(filename_cp, filename);
    /*Open the wav file*/
    file_p = fopen(strcat(filename_cp,".wav"), "w");
    if(NULL == file_p)
    {
        perror("fopen failed in main");
        ret = -1;
        goto error0;
    }
    
    /*Allocate the data buffer*/
    buffer_p = allocate_PCM16_buffer(FrameCount);
    if(NULL == buffer_p)
    {
        perror("allocate_PCM16_buffer failed in main");
        ret = -1;
        goto error1;
    }
    
    /*Fill the buffer*/
    ret = generate_melody (amplitude,
                           SAMPLE_RATE,
                           FrameCount,
                           buffer_p);
    ret = quantification4bits(FrameCount,buffer_p);
    if(ret < 0)
    {
        fprintf(stderr, "generate_sinusoid failed in main\n");
        ret = -1;
        goto error2;
    }
    
    // Print the sample values in the buffer to a CSV file
    ret = write_CSV_file(filename, FrameCount, buffer_p);
    if(ret < 0)
    {
        perror("write_CSV_file failed in main");
        ret = -1;
        goto error2;
    }
    
    
    /*Write the wav file header*/
    ret = write_PCM16_header(file_p,
                             SAMPLE_RATE,
                             FrameCount);
    if(ret < 0)
    {
        perror("write_PCM16_header failed in main");
        ret = -1;
        goto error2;
    }
    
    /*Write the data out to file*/
    written = write_PCM16wav_data(  file_p,
                                  FrameCount,
                                  buffer_p);

    if(written < FrameCount)
    {
        perror("write_PCM16wav_data failed in main");
        ret = -1;
        goto error2;
    }
    
    /*Free and close everything*/
error2:
    free(buffer_p);
error1:
    fclose(file_p);
error0:
    return ret;
}
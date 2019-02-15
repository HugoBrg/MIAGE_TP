#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include <math.h>
#include <string.h>
/*The header of a wav file is based on:  https://fr.wikipedia.org/wiki/Waveform_Audio_File_Format */
typedef struct wavfile_header_s
{
    char    ChunkID[4];     /*  4   */
    int32_t ChunkSize;      /*  4   */
    char    Format[4];      /*  4   */

    char    Subchunk1ID[4]; /*  4   */
    int32_t Subchunk1Size;  /*  4   */
    int16_t AudioFormat;    /*  2   */
    int16_t NumChannels;    /*  1   */
    int32_t SampleRate;     /*  4   */
    int32_t ByteRate;       /*  4   */
    int16_t BlockAlign;     /*  2   */
    int16_t BitsPerSample;  /*  2   */

    char    Subchunk2ID[4];
    int32_t Subchunk2Size;
} wavfile_header_t;

/*Standard values for CD-quality audio*/
#define SUBCHUNK1SIZE   (16)
#define AUDIO_FORMAT    (1) /*For PCM*/
#define NUM_CHANNELS    (1) /*For mono-channel sound*/
#define SAMPLE_RATE     (44100)


#define BITS_PER_SAMPLE (4)

#define BYTE_RATE       (SAMPLE_RATE * NUM_CHANNELS * BITS_PER_SAMPLE/8)
#define BLOCK_ALIGN     (NUM_CHANNELS * BITS_PER_SAMPLE/8)

//----- Function prototypes ----------------------------------------------------

/*Return 0 on success and -1 on failure*/
int write_PCM16_header(FILE* file_p, int32_t SampleRate, int32_t FrameCount);

// Allocate the data buffer of 16-bit samples
int16_t *allocate_PCM16_buffer(int32_t FrameCount);


/*Return the number of audio frames sucessfully written*/
size_t  write_PCM16wav_data(FILE*           file_p,
                            int32_t         FrameCount,
                            int16_t  *buffer_p);